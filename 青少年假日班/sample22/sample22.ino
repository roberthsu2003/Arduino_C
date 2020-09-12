#include <MatrixMini.h>
#include <Thread.h>

MatrixMini Mini;
Thread timeThread = Thread();

void setup() {
  Serial.begin(9600);
  Mini.begin();
  randomSeed(analogRead(A0) + millis()/2);

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
}

void loop() {
  if(timeThread.shouldRun()){
    timeThread.run();
  }

}
