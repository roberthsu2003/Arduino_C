#include <Thread.h>
#include <ThreadController.h>

Thread timeThread1000 = Thread();
Thread timeThread1300 = Thread();
Thread timeThread500 = Thread();

ThreadController controller = ThreadController();

void setup() {
  Serial.begin(9600);
  timeThread1000.onRun(callBack1000);
  timeThread1000.setInterval(1000);
  timeThread500.onRun(callBack500);
  timeThread500.setInterval(500);
  timeThread1300.onRun(callBack1300);
  timeThread1300.setInterval(1300);
  controller.add(&timeThread1000);
  controller.add(&timeThread500);
  controller.add(&timeThread1300);
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
  controller.run();
}
