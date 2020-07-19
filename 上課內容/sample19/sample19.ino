//============================================================================
// Name        : withoutDelay.ino
//不使用delay()方法,計算時間,讓2個LED每格1秒亮燈,顏色要使用亂數
//請在資源庫安裝Arduino Thread

#include <Thread.h>
#include <MatrixMini.h>

MatrixMini mini;

Thread myThread = Thread();
Thread myThread3 = Thread();
Thread myThread5 = Thread();

void setup() {
  Serial.begin(9600);
  mini.begin();
  myThread.onRun(callBack1);
  myThread.setInterval(1000);
  myThread3.onRun(callBack2);
  myThread3.setInterval(3000);
  myThread5.onRun(callBack3);
  myThread5.setInterval(5000);
}

void callBack1() {
  Serial.println("1秒Run");
}


void callBack2() {
  Serial.println("3秒Run");
}

void callBack3() {
  Serial.println("5秒Run");
}

void loop() {
  threadRun();

}

void threadRun() {
  if (myThread.shouldRun()) {
    myThread.run();
  }

  if (myThread3.shouldRun()) {
    myThread3.run();
  }

  if (myThread5.shouldRun()) {
    myThread5.run();
  }
}
