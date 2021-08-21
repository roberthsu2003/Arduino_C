#include <MatrixMini.h>

void setup() {
  Mini.begin();
  int i = 30;
  //前進
  Mini.M1.set(i);
  Mini.M2.set(i);
  delay(2000);
  //停
  Mini.M1.set(0);
  Mini.M2.set(0);
  delay(2000);
  //後退
  Mini.M1.set(-i);
  Mini.M2.set(-i);
  delay(2000);
  //停
  Mini.M1.set(0);
  Mini.M2.set(0);
}

void loop() {
  // put your main code here, to run repeatedly:

}
