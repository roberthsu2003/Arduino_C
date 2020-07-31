//不使用delay()方法,計算時間,讓2個LED每格1秒亮燈,顏色要使用亂數
#include <MatrixMini.h>
#include <Thread.h>

//建立小車
MatrixMini Mini;
//建立時間管理
Thread timeThread = Thread();

void setup() {
  //啟動序列埠
  Serial.begin(9600);
  //啟動小車
  Mini.begin();
  //建立亂數種子
  randomSeed(analogRead(0));

  //啟動時間管理
  timeThread.onRun(callBack);
  timeThread.setInterval(1000);
}

void callBack(){
  Serial.println("每隔1秒輸出一次");
}

void loop() {
  //執行時間管理
  if(timeThread.shouldRun()){
    timeThread.run();
  }

}
