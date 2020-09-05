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
