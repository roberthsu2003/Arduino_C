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
#include <sound.h>
#define BUZZER 3

Sound buzzer(BUZZER);
int guess;
int min = 1;
int max = 99;
int keyin;
int count = 0;
  
void setup() {
  Serial.begin(9600);
  Serial.println("===============猜數字遊戲=================:\n");
  Serial.print("請輸入一個幸運號碼(1000~62000):");
  while(true){
    if(Serial.available()){
      int inputNum = Serial.parseInt();
      Serial.println(inputNum);
      randomSeed(inputNum+(millis()/2));
      break;
    }
  }
  pinMode(BUZZER, OUTPUT);  
  
}

void loop() {
  randomSeed(millis());
  guess = random(min, max+1);
  do{
    Serial.print("猜數字範圍" + String(min) + "~" + String(max) + ":");
    while(true){
      if(Serial.available()){
        keyin = Serial.parseInt();
        count++;
        buzzer.beep(200);
        Serial.println(keyin);
        break;
      }
    }

    if(keyin >= min && keyin <= max){
      if(keyin == guess){
        Serial.println("賓果!猜對了,答案是" + (String)guess);
        Serial.println("您猜了" + String(count) + "次\n");
        buzzer.melodySound();
        break;
      }else if(keyin > guess){
        Serial.println("再小一點!");
        max = keyin;
      }else if(keyin < guess){
         Serial.println("再大一點!");
         min = keyin;
      }
      Serial.println("您猜了" + String(count) + "次\n");
    }else{
      Serial.println("請輸入提示範圍內的數字!\n");
    }
  }while(true);
  Serial.println("Game Over!!!");
  while(true);
}
```

```c++
//============================================================================
// Name        : withoutDelay.ino
//不使用delay()方法,計算時間,讓2個LED每格1秒亮燈,顏色要使用亂數
//請使用function millis()

#include <MatrixMini.h>



bool ledState = LOW;
//使用 unsigned long可以儲存較多的值
unsigned long previousMillis = 0;  

// constants won't change:
const long interval = 1000;  
         
void setup() {
  // set the digital pin as output:
  Serial.begin(9600);
  Mini.begin();
  randomSeed(analogRead(A0+ millis()/2));
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
      Mini.RGB1.setRGB(r, g, b);
      Mini.RGB2.setRGB(r, g, b);
    } else {
      ledState = LOW;
      Mini.RGB1.setRGB(0, 0, 0);
      Mini.RGB2.setRGB(0, 0, 0);
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

//建立小車

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
    Mini.RGB1.setRGB(r, g, b);
    Mini.RGB2.setRGB(r, g, b);
  }else{
    Mini.RGB1.setRGB(0, 0, 0);
    Mini.RGB2.setRGB(0, 0, 0);
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
```

```c++

//============================================================================
// Name        : switchButton.ino
//建立切換按鈕，按一次為LED開, 再按一次LED關
//請在資源庫安裝Arduino Thread

#include <MatrixMini.h>
#include <Thread.h>


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
      Mini.RGB1.setRGB(255, 0, 0);
      break;
    case 0:
      Serial.println("按鈕關");
      Mini.RGB1.setRGB(0, 0, 0);
      break;
  }
}

```

```c++
//使用ThreadController,來管理多個Thread

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
```