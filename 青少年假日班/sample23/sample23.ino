#include <Thread.h>
Thread timeThread1000 = Thread();
Thread timeThread1300 = Thread();
Thread timeThread500 = Thread();


void setup() {
  Serial.begin(9600);
  timeThread1000.onRun(callBack1000);
  timeThread1000.setInterval(1000);
  timeThread500.onRun(callBack500);
  timeThread500.setInterval(500);
  timeThread1300.onRun(callBack1300);
  timeThread1300.setInterval(1300);
}

void callBack1000(){
  Serial.println("已經過了1秒");
}

void callBack1300(){
  Serial.println("已經過了1.3秒");
}

void callBack500(){
  Serial.println("已經過了0.5秒");
}

void loop() {
 
  if(timeThread1000.shouldRun()){
    timeThread1000.run();
  }

  if(timeThread500.shouldRun()){
    timeThread500.run();
  }

  if(timeThread1300.shouldRun()){
    timeThread1300.run();
  }

}
