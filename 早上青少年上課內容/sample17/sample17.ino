#include <sound.h>

#define BUZZER 3 //接線至D1插孔

Sound s(BUZZER);

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
  int min = 1;
  int max = 99;
  int guess; // 隨機的數值
  int keyin; //使用者輸入的值
  int count = 0;
  //建立亂數
  randomSeed(analogRead(0));
  guess = random(min, max+1);
  //Serial.println("現在的亂數是" + (String)guess);
  Serial.println("===============猜數字遊戲=================:\n");
  do{
    //顯示猜數字的範圍
    Serial.print("猜數字範圍" + (String)min + "~" + (String)max + ":");

    //等待和接收使用者輸入,並且顯示輸入的數值
    while(true){
      if(Serial.available()){
        keyin = Serial.parseInt();
        count++;
        s.beep(200);
        Serial.println(keyin);
        break;
      }
    }

    if(keyin >= min && keyin <=max){
      if(keyin == guess){
        Serial.println("賓果!猜對了,答案是" + (String)guess);
        Serial.println("您猜了" + (String)count + "次\n");
        s.melodySound();
        break;
      }else if(keyin > guess){
        max = keyin;
        Serial.println("再小一點");
      }else if(keyin < guess){
        min = keyin;
        Serial.println("再大一點");
      }

      Serial.println("您猜了" + String(count) + "次\n");
    }else{
      Serial.println("請輸入提示範圍內的數字!\n");
    }
  }while(true);
  Serial.println("Game Over!!!");
}

void loop() {
  // put your main code here, to run repeatedly:

}
