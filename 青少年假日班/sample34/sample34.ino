//藍線A0 - Trig
//白線A1 - Echo
//安裝NewPing Library

#include <NewPing.h>
#include <MatrixMini.h>
#define TRIGGER_PIN  A0
#define ECHO_PIN     A1
#define MAX_DISTANCE 200
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
MatrixMini Mini;
unsigned long startTime;
int detectSpeed = 20; //設定偵測的速度
int runSpeed = 50;
void setup() {
  Mini.begin(); 
  Serial.begin(9600);
  detect();
}
 
void loop() {
  int uS = sonar.ping();
  int distance = uS / US_ROUNDTRIP_CM;
  if(distance < 15 && distance >0){
    Mini.M1.set(-35);  
    Mini.M2.set(-35);
    delay(1000);
    detect();
  }else{
    Mini.M1.set(runSpeed);  
    Mini.M2.set(runSpeed);
  }
  delay(10);
}



void detect(){
  //要先手動測試interval的時間是否剛好轉一圈  
  int interval = 7200;
  
  int n=0;
  Mini.M1.set(detectSpeed);  
  Mini.M2.set(-detectSpeed);
  startTime = millis();
  unsigned long startTime1 = millis();
  unsigned long times[20]; //儲存時間陣列
  //儲存距離陣列
  int distances[20]= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  while(true){
    //轉一圈的時間,要取得20個值
    unsigned long currentTime = millis();  
    if(currentTime - startTime1 >= interval/20){      
      recordTimeAndDisctance(times, distances, n); 
      if(n==19){         
        break;    
      }
      n++; //小車旋轉1圈,超音波偵測的次數   
         
      startTime1 = currentTime;
    }
    
   
    //小車旋轉interval的時間
    /*
    if(millis() - startTime >= interval){
       Mini.M1.set(0);  
       Mini.M2.set(0);       
      break;
    }
    */
  }
  for(int i=0; i<n ; i++){
    Serial.println(times[i]);
    Serial.println(distances[i]);
  }

  //開始分析
  Serial.print("startTime:");
  Serial.println(startTime);
  rightDirection(times,distances, startTime, interval);
  
}

void recordTimeAndDisctance(unsigned long ts[], int ds[], int n){
  //n會0-19
  ts[n] = millis();
  
  int uS = sonar.ping();
  int distance = uS / US_ROUNDTRIP_CM;
  //如果距離為0代表超過測試距離就使用最大測試距離
  ds[n] = distance == 0 ? MAX_DISTANCE : distance;
}

//取出最遠距離的時間(陣列)
void rightDirection(unsigned long ts[], int ds[],unsigned long beginTime,int interval){
  
  //取得最大值
  int maxValue = 0;
  Serial.println("==========================");
  for(int i=0; i<20; i++){
    //8-12是正後方,不處理
    
    switch(i){
      case 8:
      case 9:
      case 10:
      case 11:
      case 12:
      continue;
    }
    
    maxValue = max(ds[i], maxValue);
    Serial.println(maxValue);
  }

  Serial.println("==========================");
  Serial.println(maxValue);


  //計算maxValue的數量
  int count=0;
  for(int i=0; i<20; i++){
    if(maxValue == ds[i]){
      count++;
    }
  }
 Serial.println("==========================");
 Serial.print("maxValue");
 Serial.println(count);
 //建立出maxValue的時間陣列
 unsigned long maxValueTimes[count];
 int n=0;
 for(int i=0; i<20; i++){
    if(maxValue == ds[i]){
      maxValueTimes[n] = ts[i];      
      n++;
    }
  }
  
Serial.println("==========================");
//列印出距離最遠的時間
 for(int i=0; i<count; i++){  
  Serial.print("maxValueTime");
  Serial.println(maxValueTimes[i]);
 }

 //取最大時間陣列的第一個數值
 //並計算起始時間和第一個數值的時間差

 unsigned long moveDistance = maxValueTimes[count/2] - beginTime;
 Serial.print("beginTime:");
 Serial.println(beginTime);
 Serial.print("maxValueTimes[0]:");
 Serial.println(maxValueTimes[0]);
 Serial.println("=================");
 Serial.print("moveDistance:");
 Serial.println(moveDistance);
 if(moveDistance < interval/2){
  //距離順時鐘較近
  unsigned long currentTime = millis();
  Mini.M1.set(detectSpeed);  
  Mini.M2.set(-detectSpeed);
  while(true){    
    if(millis()-currentTime >= moveDistance ){
        Mini.M1.set(0);  
        Mini.M2.set(0);
        break; 
    }
  }
  
 }else{
  //距離反時鐘較近
  unsigned long currentTime = millis();
  Mini.M1.set(-detectSpeed);  
  Mini.M2.set(detectSpeed);
  
  while(true){    
    if(millis()-currentTime >= (interval - moveDistance) ){
        Mini.M1.set(0);  
        Mini.M2.set(0);
        break;   
    }
  }
 }
 
}
