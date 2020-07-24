#include <MatrixMini.h>

MatrixMini Mini;

void setup() {
  Mini.begin();
}

void loop() {
  Mini.LED1.setRGB(255, 0, 0);
  Mini.LED2.setRGB(0, 255, 0);
  delay(500);
  
  Mini.LED1.setRGB(0, 0, 0);
  Mini.LED2.setRGB(0, 0, 0);
  delay(500);
}
