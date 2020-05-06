# 亂數和時間操控

```c
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
