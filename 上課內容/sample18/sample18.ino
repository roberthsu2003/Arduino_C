//============================================================================
// Name        : withoutDelay.ino
//不使用delay()方法,計算時間,讓2個LED每格1秒亮燈,顏色要使用亂數
//請使用function millis()

#include <MatrixMini.h>
MatrixMini mini;

unsigned long previousMillis = 0;
unsigned long previousMillis1 = 0;

//建立常數
const long interval = 1000;
unsigned long second=0;

void setup() {
  Serial.begin(9600); 
  mini.begin(); 
  randomSeed(analogRead(A0));
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval){
    //過了1秒
    second++;
    previousMillis = currentMillis;
    Serial.print("過了");
    Serial.print(second);
    Serial.println("秒");

    int randomValue = random(1000);
    int r = 0;
    int g = 0;
    int b = 0;

    switch(randomValue % 3){
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

    mini.LED1.setRGB(r,g,b);
    
  }


  unsigned long currentMillis1 = millis();
  if(currentMillis1 - previousMillis1 >= 2000){
    //過了1秒
    second++;
    previousMillis1 = currentMillis1;
    Serial.print("過了");
    Serial.print(second);
    Serial.println("秒");

    int randomValue = random(1000);
    int r = 0;
    int g = 0;
    int b = 0;

    switch(randomValue % 3){
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

    mini.LED2.setRGB(r,g,b);
    
  }
  
}
