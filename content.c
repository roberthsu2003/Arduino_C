#include <MatrixMini.h>

void setup() {
  Mini.begin();
  Mini.M1.set(-50);
  Mini.M2.set(50);
  delay(5000);
  Mini.M1.set(0);
  Mini.M2.set(0);
}

void loop() {
  // put your main code here, to run repeatedly:

}
