# 亂數和時間操控

```c++
#arduino C
#使用randomSeed()
#使用random()

long randNumber;

void setup() {
  Serial.begin(9600);
  //A0沒有接任何裝置時,會取得環境的訊號(沒有固定值的訊號)
  randomSeed(analogRead(0));
}

void loop() {
  // 列印出0~299的亂數
  randNumber = random(300);
  Serial.println(randNumber);

  // 列印出10~19的亂數
  delay(1000);
  randNumber = random(10, 20);
  Serial.println(randNumber);

  delay(1000);
}
```

```c++

//============================================================================
// Name        : guess.ino
//猜數字遊戲
//猜對後請發出美樂迪音樂

#include "sound.h"

Sound s(6);

void setup() {
  Serial.begin(9600);
  int guess;
  int min = 1;
  int max = 99;
  int keyin;
  int count = 0;
  randomSeed(analogRead(A0));
  //1~99
  guess = random(min,max+1);
  Serial.println("===============猜數字遊戲=================:\n\n");
  do{
    Serial.print("猜數字範圍");
    Serial.print(min);
    Serial.print("~");
    Serial.print(max);
    Serial.print(":");
    
    while(true){
      if(Serial.available()){
        keyin = Serial.parseInt();
        count++;
        s.beep(200);
        Serial.println(keyin);
        break;
      }
    }

    if(keyin >= min && keyin <= max){
      if(keyin == guess){
        Serial.print("賓果!猜對了,答案是");
        Serial.println(guess);
        Serial.print("您猜了");
        Serial.print(count);
        Serial.println("次\n");
        s.melodySound();
        break;
      }else if(keyin > guess){
        max = keyin;
        Serial.println("再小一點\n");        
      }else if(keyin < guess){
        min = keyin;
        Serial.println("再大一點!\n");
      }
      Serial.print("您猜了");
      Serial.print(count);
      Serial.println("次");
    }else{
      Serial.println("請輸入提示範圍內的數字! \n");
    }
  }while(true);
}

void loop() {
  // put your main code here, to run repeatedly:
}
```

```c++
//============================================================================
// Name        : withoutDelay.ino
//不使用delay()方法,計算時間,讓2個LED每格1秒亮燈,顏色要使用亂數
//請使用function millis()

#include <MatrixMini.h>

MatrixMini Mini;

bool ledState = LOW;
//使用 unsigned long可以儲存較多的值
unsigned long previousMillis = 0;  

// constants won't change:
const long interval = 1000;  
         
void setup() {
  // set the digital pin as output:
  Serial.begin(9600);
  Mini.begin();
  randomSeed(analogRead(A0));
}

void loop() {
  
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
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
    if (ledState == LOW) {
      ledState = HIGH;
      Mini.LED1.setRGB(r, g, b);
      Mini.LED2.setRGB(r, g, b);
    } else {
      ledState = LOW;
      Mini.LED1.setRGB(0, 0, 0);
      Mini.LED2.setRGB(0, 0, 0);
    }

  }
}

```

```c++

//============================================================================
// Name        : withoutDelay.ino
//不使用delay()方法,計算時間,讓2個LED每格1秒亮燈,顏色要使用亂數
//請在資源庫安裝Arduino Thread

#include <MatrixMini.h>
#include <Thread.h>

MatrixMini Mini;
Thread myThread = Thread();

         
void setup() {
  // set the digital pin as output:
  Serial.begin(9600);
  Mini.begin();
  randomSeed(analogRead(A0));
  myThread.onRun(callBack);
  myThread.setInterval(500);
}

void loop() {
  if(myThread.shouldRun()){
    myThread.run();
  }
  
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
    
  if (ledStatus == LOW) {      
      Mini.LED1.setRGB(r, g, b);
      Mini.LED2.setRGB(r, g, b);
    } else {      
      Mini.LED1.setRGB(0, 0, 0);
      Mini.LED2.setRGB(0, 0, 0);
    }
  Serial.print("cool!現在的時間是: ");
  Serial.println(millis());
}

```

```c++

//============================================================================
// Name        : switchButton.ino
//建立切換按鈕，按一次為LED開, 再按一次LED關
//請在資源庫安裝Arduino Thread

#include <MatrixMini.h>
#include <Thread.h>

MatrixMini Mini;
Thread myThread = Thread();

bool buttonState;
int pressCount=0;

void setup() {
  Mini.begin();
  Serial.begin(9600);
  buttonState = Mini.BTN1.get();
  myThread.onRun(callBack);
  myThread.setInterval(500);   
}

void loop() {
  if(myThread.shouldRun()){
    myThread.run();
  }
  if(buttonState != Mini.BTN1.get()){
    delay(50);
    if(buttonState != Mini.BTN1.get()){
      pressCount++;
      buttonState = !buttonState;
      Serial.println(pressCount);
    }    
  } 

}

void callBack(){
  switch(pressCount % 4){
    case 2:
      Serial.println("按鈕開");
      Mini.LED1.setRGB(255, 0, 0);
      break;
    case 0:
      Serial.println("按鈕關");
      Mini.LED1.setRGB(0, 0, 0);
      break;
  }
}

