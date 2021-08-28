#include <NewPing.h>
#define TRIGGER_PIN A0
#define ECHO_PIN A1
#define MAX_DISTANCE 200


NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int uS = sonar.ping();
  int distance = uS / US_ROUNDTRIP_CM;
  Serial.print("前放物件的距離:");
  Serial.println(String(distance) + "公分");
  delay(500);
}
