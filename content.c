//藍線A0 - Trig
//白線A1 - Echo


#include "NewPing.h"
#define TRIGGER_PIN A0
#define ECHO_PIN A1
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  delay(50);
  int uS = sonar.ping();
  Serial.print("Ping:");
  Serial.print(uS / US_ROUNDTRIP_CM);
  Serial.println("cm");
}
