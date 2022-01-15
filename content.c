#include <arduino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int englishScore = 60;
  Serial.print("目前英文分數是");
  Serial.println(englishScore);
  Serial.println("請輸入您的英文分數:");
  while(true){
    //等待使用者輸入
    char letters[2];
    if(Serial.available() > 0){      
        englishScore = Serial.parseInt();
        break;
    }
    
  }

  Serial.print("新的英文分數是:");
  Serial.println(englishScore);

}

void loop() {
  // put your main code here, to run repeatedly:

}
