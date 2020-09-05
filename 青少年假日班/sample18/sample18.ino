#include "sound.h"
#define BUZZER 3
String password;
//建立Sound
Sound buzzer(BUZZER);

void setup() {
  Serial.begin(9600);
  do{
    Serial.print("請輸入密碼:");
    while(true){
      if(Serial.available()){
        password = Serial.readString();
        Serial.println(password);
        break;
      }
    }
    buzzer.beep(200);
  }while(password != "5678");
  Serial.println("恭喜!你的密碼正確了!請進");
  buzzer.bee();
}

void loop() {
  // put your main code here, to run repeatedly:

}
