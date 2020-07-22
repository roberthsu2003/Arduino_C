//RGBLED燈
//讀取整數
//Serial.parseInt()

#include <MatrixMini.h>

MatrixMini Mini;

void setup() {
  Mini.begin();
  // initialize the serial communication:
  Serial.begin(9600);
  // initialize the ledPin as an output:
  
}

void loop() {
  //因為使用byte只能讀取0-255
  byte value;
  // check if data has been sent from the computer:
  if (Serial.available()) {
    // 只能解析0~255的數字
    value = Serial.parseInt();
    // set the brightness of the LED:
    Serial.println(value,DEC);
    Mini.LED1.setRGB(value, 0, 0);
    delay(2000);
    Mini.LED1.setRGB(0, 0, 0);
  }
}
