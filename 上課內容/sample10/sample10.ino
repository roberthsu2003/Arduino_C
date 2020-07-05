#include <MatrixMini.h>

MatrixMini Mini;

void setup() {
  Mini.begin();
  Serial.begin(9600);

}

void loop() {
  if(Mini.BTN1.get() && Mini.BTN2.get()){
    Serial.println("同時按下");
  }else{
    Serial.println("沒有同時按下");
  }

}
