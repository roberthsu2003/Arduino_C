#include <MatrixMini.h>

MatrixMini Mini;

void setup() {
  Mini.begin();
  Serial.begin(9600);
  delay(2000);
  for(int i=0; i<20; i++){
    Mini.M1.set(50);
    Mini.M2.set(-50);
    delay(100);
  }
  Mini.M1.set(0);
  Mini.M2.set(0);

}

void loop() {
  // put your main code here, to run repeatedly:

}
