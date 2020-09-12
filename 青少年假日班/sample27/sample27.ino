#include <MatrixMini.h>

MatrixMini Mini;

void setup() {
  Mini.begin();
  Serial.begin(9600);

  Serial.println("\n Matrix Mine 直流馬達測試 \n");
  int i = 30;
  Mini.M1.set(i);
  Mini.M2.set(i);
  delay(3000);
  Mini.M1.set(0);
  Mini.M2.set(0);

}

void loop() {
  // put your main code here, to run repeatedly:

}
