// Name        : car.ino
//以4種速度前進或後退3秒

#include <MatrixMini.h>

MatrixMini mini;

void setup() {
  mini.begin();
  Serial.begin(9600);
  Serial.println("\nMatrix Mini DC Motor 測試\n");
  int speed = 30;
  mini.M1.set(speed);
  mini.M2.set(speed);
  delay(3000);
  mini.M1.set(0);
  mini.M2.set(0);
}

void loop() {
  // put your main code here, to run repeatedly:

}
