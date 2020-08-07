#include <MatrixMini.h>

MatrixMini Mini;

void setup() {
  Mini.begin();
  oneTurn();
}

void loop() {
  // put your main code here, to run repeatedly:

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
