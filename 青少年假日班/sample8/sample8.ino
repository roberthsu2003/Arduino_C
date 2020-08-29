#include <MatrixMini.h>

MatrixMini Mini;
byte value;

void setup() {
  Mini.begin();
  Serial.begin(9600);

}

void loop() {
  while(true){
    if(Serial.available()){
      value = Serial.parseInt();
      Serial.println(value);
      Mini.LED1.setRGB(0, 0, value);
      delay(5000);
      Mini.LED1.setRGB(0,0,0);
      break;
    }
  }

}
