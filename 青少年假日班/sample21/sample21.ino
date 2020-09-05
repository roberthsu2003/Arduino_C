//============================================================================
// Name        : withoutDelay.ino
//不使用delay()方法,計算時間,讓2個LED每格1秒亮燈,顏色要使用亂數
//請使用function millis()

#include <MatrixMini.h>

MatrixMini Mini;
bool ledState = LOW;
unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
  Serial.begin(9600);
  Mini.begin();
  randomSeed(analogRead(A0) + millis()/2);
}

void loop() {
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval){
    Serial.println("過了1秒");
    previousMillis = currentMillis;

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

    if(ledState == LOW){
      ledState = HIGH;
      Mini.LED1.setRGB(r,g,b);
      Mini.LED2.setRGB(r, g, b);
    }else{
      ledState = LOW;
      Mini.LED1.setRGB(0,0,0);
      Mini.LED2.setRGB(0,0,0);
    }
  }

}
