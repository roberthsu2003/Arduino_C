//只要距離為超過100就停止
#include <MatrixMini.h>
#include <NewPing.h>
#define TRIGGER_PIN A0
#define ECHO_PIN A1
#define MAX_DISTANCE 100

MatrixMini Mini;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

const int count=20;


void setup() {
  Mini.begin();
  Serial.begin(9600);
  delay(2000);
  for(int i=0; i<count; i++){
    Mini.M1.set(50);
    Mini.M2.set(-50);
    int uS = sonar.ping();
    if(uS == 0){
      break;
    }
    
    delay(100);
  }
  Mini.M1.set(0);
  Mini.M2.set(0);

 

}

void loop() {
  // put your main code here, to run repeatedly:

}
