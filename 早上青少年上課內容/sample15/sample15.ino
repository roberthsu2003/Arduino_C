#include <MatrixMini.h>
#include <sound.h>

#define BUZZER 3
Sound s(BUZZER);

void setup() {
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER,HIGH);  
  //s.bee();  
  //s.beep(2000);
  //s.phone();
  s.melodySound();
}

void loop() {
  // put your main code here, to run repeatedly:

}
