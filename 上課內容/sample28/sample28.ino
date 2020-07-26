//使用超音波測計算每收集10個的平均距離

//藍線A0 - Echo
//白線A1 - Trig

#include <NewPing.h>
#include <Thread.h> 
#define TRIGGER_PIN  A1
#define ECHO_PIN     A0
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
Thread myThread = Thread();
byte distances[10];
void setup() {
  Serial.begin(9600);
  myThread.onRun(callBack);
  myThread.setInterval(50);
}

void callBack(){
  
  static byte count = 0;
  static int sumDis = 0;

  if(count == 10){
    for(int i=0; i<=9; i++){
      sumDis += distances[i];
    }    
    Serial.print(sumDis/10);
    Serial.println("cm");
    count = 0;
    sumDis = 0;
  }
  int uS = sonar.ping();  
  distances[count] = uS / US_ROUNDTRIP_CM;
  count++;

  
}

void loop() {
  if(myThread.shouldRun()){
    myThread.run();
  }
}
