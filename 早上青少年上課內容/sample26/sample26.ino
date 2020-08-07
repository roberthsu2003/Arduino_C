#include <MatrixMini.h>
#include <NewPing.h>
#define TRIGGER_PIN A0
#define ECHO_PIN A1
#define MAX_DISTANCE 200

MatrixMini Mini;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
  Mini.begin();
  //oneTurn();  
}

void loop() {
  // put your main code here, to run repeatedly:
  detect_distance();
  
}

void detect_distance(){
  //測到距離10cm以內,讓小車前進後退
  delay(200);
  
  int uS = sonar.ping();
  int distance = uS / US_ROUNDTRIP_CM;
  Serial.print("距離:");
  Serial.print(distance);
  Serial.println("cm");
  int interval = 1000;
  int speed = 50;
  
  if(distance <= 10 && distance != 0){
    Mini.M1.set(-speed);
    Mini.M2.set(-speed);
    delay(interval);
    Mini.M1.set(speed);
    Mini.M2.set(speed);
    delay(interval);
    Mini.M1.set(0);
    Mini.M2.set(0);
  }
  
}

void oneTurn(){
  //轉360
  int interval = 1000;
  int speed = 80;
  Mini.M1.set(speed);
  Mini.M2.set(-speed);
  delay(interval);
  Mini.M1.set(0);
  Mini.M2.set(0);
}
