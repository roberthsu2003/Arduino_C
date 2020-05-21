# 10避障車
### 取得360度測試的距離
```c++
//藍線A0 - Echo
//白線A1 - Trig
//安裝NewPing Library

#include <NewPing.h>
#include <MatrixMini.h>
#define TRIGGER_PIN  A1
#define ECHO_PIN     A0
#define MAX_DISTANCE 200
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
MatrixMini Mini;
unsigned long startTime;
void setup() {
  Mini.begin(); 
  Serial.begin(9600);
  detect();
}
 
void loop() {
  
}



void detect(){
  //要先手動測試interval的時間是否剛好轉一圈
  //要使用電池在地上測試  
  int interval = 6500;
  int speed = 20;
  int n=0;
  Mini.M1.set(speed);  
  Mini.M2.set(-speed);
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
      n++; //小車旋轉1圈,超音波偵測的次數      
      startTime1 = currentTime;
    }
    
   
    //小車旋轉interval的時間
    if(millis() - startTime >= interval){
       Mini.M1.set(0);  
       Mini.M2.set(0);       
      break;
    }
  }
  //輸出測試距離和時間
  for(int i=0; i<n ; i++){
    Serial.println(times[i]);
    Serial.println(distances[i]);
  }
}

void recordTimeAndDisctance(unsigned long ts[], int ds[], int n){
  //n會0-19
  ts[n] = millis();  
  int uS = sonar.ping();
  int distance = uS / US_ROUNDTRIP_CM;
  //如果距離為0代表超過測試距離就使用最大測試距離
  ds[n] = distance == 0 ? MAX_DISTANCE : distance;
}

```

### 分析那一個時間的距離最遠
```c++
//藍線A0 - Echo
//白線A1 - Trig
//安裝NewPing Library

#include <NewPing.h>
#include <MatrixMini.h>
#define TRIGGER_PIN  A1
#define ECHO_PIN     A0
#define MAX_DISTANCE 200
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
MatrixMini Mini;
unsigned long startTime;
void setup() {
  Mini.begin(); 
  Serial.begin(9600);
  detect();
}
 
void loop() {
  
}



void detect(){
  //要先手動測試interval的時間是否剛好轉一圈  
  int interval = 7200;
  int speed = 20;
  int n=0;
  Mini.M1.set(speed);  
  Mini.M2.set(-speed);
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
      n++; //小車旋轉1圈,超音波偵測的次數      
      startTime1 = currentTime;
    }
    
   
    //小車旋轉interval的時間
    if(millis() - startTime >= interval){
       Mini.M1.set(0);  
       Mini.M2.set(0);       
      break;
    }
  }
  for(int i=0; i<n ; i++){
    Serial.println(times[i]);
    Serial.println(distances[i]);
  }

  //開始分析
  turnRightDirection(times,distances, startTime, interval);
}

void recordTimeAndDisctance(unsigned long ts[], int ds[], int n){
  //n會0-19
  ts[n] = millis();
  
  int uS = sonar.ping();
  int distance = uS / US_ROUNDTRIP_CM;
  //如果距離為0代表超過測試距離就使用最大測試距離
  ds[n] = distance == 0 ? MAX_DISTANCE : distance;
}

void turnRightDirection(unsigned long ts[], int ds[],unsigned long beginTime,int interval){
  
  //取得最大值
  int maxValue = 0;
  Serial.println("==========================");
  for(int i=0; i<20; i++){
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
      maxValueTimes[n] == ts[i];
      n++;
    }
  }
  
Serial.println("==========================");
 for(int i=0; i<count; i++){  
  Serial.print("maxValueTime");
  Serial.println(maxValueTimes[i]);
 }
  
}


```