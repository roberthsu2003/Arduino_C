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
  //多向選擇
  if(distance <= 10 && distance != 0){
    Serial.println("障礙物很接近");
  }else if(distance <= 20 && distance != 0){
    Serial.println("障礙物在11~20分分之間");
  }else{
    Serial.println("障礙物21公分以上");
  }
  delay(300);
}
