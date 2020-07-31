#include <sound.h>

#define BUZZER 3 //接線至D1插孔

Sound s(BUZZER);

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
  
  digitalWrite(BUZZER,LOW);
  delay(1000);
  digitalWrite(BUZZER,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:

}
