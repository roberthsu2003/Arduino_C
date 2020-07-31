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
  timeThread.setInterval(500);
}

void callBack(){
  static bool ledStatus = false;
  ledStatus = !ledStatus;
   int randomValue = random(1000);
  int r = 0;
  int g = 0;
  int b = 0;
  switch(randomValue%3){
    case 0:
      r = 255;
      break;
    case 1:
      g = 255;
      break;
    case 2:
      b = 255;
      break;
  }

  if(ledStatus == LOW){
    Mini.LED1.setRGB(r, g, b);
    Mini.LED2.setRGB(r, g, b);
  }else{
    Mini.LED1.setRGB(0, 0, 0);
    Mini.LED2.setRGB(0, 0, 0);
  }

  Serial.print("Cool!現在的時間是:");
  Serial.println(millis());
  
}

void loop() {
  //執行時間管理
  if(timeThread.shouldRun()){
    timeThread.run();
  }

 

}
