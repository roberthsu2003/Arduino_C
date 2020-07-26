//藍線A0 - Echo
//白線A1 - Trig
//安裝NewPing Library
//人面對背面方向
//D1插孔 - 紅外線左模組
//D2插孔- 紅外線右模組


#include <NewPing.h>

#define TRIGGER_PIN A1
#define ECHO_PIN A0
#define MAX_DISTANCE 200
#define irLeft 2
#define irRight 3

NewPing sonar(TRIGGER_PIN,ECHO_PIN,MAX_DISTANCE);

void setup() {
  Serial.begin(9600);  
  pinMode(irLeft,INPUT);
  pinMode(irRight,INPUT);
}

void loop() {
  
  int uS= sonar.ping();
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM);
  Serial.println("cm");

  int leftValue = digitalRead(irLeft);
  int rightValue = digitalRead(irRight);
  Serial.print("left:");
  Serial.println(leftValue);
  Serial.print("right:");
  Serial.println(rightValue);
  delay(500);
}
