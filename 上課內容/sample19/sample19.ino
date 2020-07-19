//============================================================================
// Name        : withoutDelay.ino
//不使用delay()方法,計算時間,讓2個LED每格1秒亮燈,顏色要使用亂數
//請在資源庫安裝Arduino Thread

#include <Thread.h>
#include <MatrixMini.h>

MatrixMini mini;

Thread myThread = Thread();

void setup() {
  Serial.begin(9600); 
  mini.begin();
  myThread.onRun(callBack1);
  myThread.setInterval(1000);
}

void callBack1(){
  Serial.println("1秒Run");
}

void loop() {
  if(myThread.shouldRun()){
    myThread.run();
  }

}
