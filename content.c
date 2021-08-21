#include <MatrixMini.h>

void setup() {
  Mini.begin();
  turnCar(50);
  delay(3000);
  turnCar(-50);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void turnCar(int i){
   Mini.M1.set(-i);
   Mini.M2.set(i);
   delay(5000);
   Mini.M1.set(0);
   Mini.M2.set(0);
}
