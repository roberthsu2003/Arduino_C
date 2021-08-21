#include <MatrixMini.h>

void setup() {
  Mini.begin();
  int i = 30;
  Mini.M1.set(i);
  Mini.M2.set(i);
  delay(1000);
  Mini.M1.set(0);
  Mini.M2.set(0);
}

void loop() {
  // put your main code here, to run repeatedly:

}
