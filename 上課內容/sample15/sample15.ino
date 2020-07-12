//============================================================================
// Name        : dowhile2.cpp
//預設的密碼為5678，使用者若輸入的密碼錯誤，將不斷出現輸入密碼訊息，直到輸入的密碼正確才顯示正確訊息
//密碼錯誤,發出單一聲音,燈光顯示紅燈
//密碼正確,發出不同聲音,燈光顯示綠燈
//

#include <MatrixMini.h>
#include <sound.h>

MatrixMini mini;
Sound s(3);
String password;

void setup() {
  Serial.begin(9600);
  mini.begin();
  do{
    Serial.print("請輸入密碼:");
    
    while(true){
      if(Serial.available()){
        password = Serial.readString();
        Serial.println(password);
        break;
      }
    }
    s.beep(200);
    mini.LED1.setRGB(255,0,0);
    delay(200);
    mini.LED1.setRGB(0, 0, 0);
  }while(password != "5678");

  Serial.println("恭喜!你的密碼正確了!請進");
  mini.LED1.setRGB(0,255,0);
  delay(200);
  mini.LED1.setRGB(0, 0, 0);
  s.bee();
}

void loop() {
  // put your main code here, to run repeatedly:

}
