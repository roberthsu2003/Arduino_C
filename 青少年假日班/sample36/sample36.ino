//藍線A0 - Trig
//白線A1 - Echo

#include <MatrixMini.h>
#include <NewPing.h>
#define TRIGGER_PIN A0
#define ECHO_PIN A1
#define MAX_DISTANCE 200

MatrixMini Mini;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int speed = 80;

void setup() {
  
  Serial.begin(9600);
  Mini.begin();
  randomSeed(analogRead(A2));
  delay(1000);
}

void loop() {
  int uS = sonar.ping();
  int distance = uS / US_ROUNDTRIP_CM;

  if(distance <= 10 && distance != 0){
    Mini.M1.set(-speed);
    Mini.M2.set(-speed);
    delay(1000);
    Mini.M1.set(speed);
    Mini.M2.set(-speed);
    delay(random(500,1500));
  }

  Mini.M1.set(speed);
  Mini.M2.set(speed);

}
