#include <arduino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int englishScore = 60;
  Serial.println("目前英文分數是");
  Serial.println(englishScore);
  Serial.println("請輸入您的英文分數:");

}

void loop() {
  // put your main code here, to run repeatedly:

}
