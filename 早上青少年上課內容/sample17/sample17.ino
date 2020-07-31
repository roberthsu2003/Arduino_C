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
  }while(true);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
