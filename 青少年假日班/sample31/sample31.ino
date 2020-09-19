#include <MatrixMini.h>
#include <NewPing.h>
#define TRIGGER_PIN A0
#define ECHO_PIN A1
#define MAX_DISTANCE 200

MatrixMini Mini;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

const int count=20;
int distances[20];

void setup() {
  Mini.begin();
  Serial.begin(9600);
  delay(2000);
  for(int i=0; i<count; i++){
    Mini.M1.set(50);
    Mini.M2.set(-50);
    int uS = sonar.ping();
    distances[i] = uS / US_ROUNDTRIP_CM;
    delay(100);
  }
  Mini.M1.set(0);
  Mini.M2.set(0);

  for(int i=0; i<count; i++){
    if(distances[i] == 0){
      Serial.println(i);
      Mini.M1.set(50);
      Mini.M2.set(-50);
      delay(100*(i));
      break;
    }
  }
  Mini.M1.set(0);
  Mini.M2.set(0);

}

void loop() {
  // put your main code here, to run repeatedly:

}
