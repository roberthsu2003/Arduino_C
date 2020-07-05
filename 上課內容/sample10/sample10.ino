#include <MatrixMini.h>
#define buzzer 3

MatrixMini Mini;

void setup() {
  Mini.begin();
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  digitalWrite(buzzer, HIGH);

}

void loop() {
  if(Mini.BTN1.get() && Mini.BTN2.get()){
    Serial.println("同時按下");
    digitalWrite(buzzer, LOW);
  }else{
    Serial.println("沒有同時按下");
    digitalWrite(buzzer, HIGH);
  }

}
