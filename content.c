#include <MatrixMini.h>
#define LIGHT_DIGITOR A0

void setup() {
  Serial.begin(9600);
  pinMode(LIGHT_DIGITOR, INPUT);
  Mini.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("=====光敏電阻數位訊號===========");
  bool digitalValue = digitalRead(LIGHT_DIGITOR);
  Serial.println("數位訊號是:"+String(digitalValue));  
  if (digitalValue == 1){
    Serial.println("向右旋轉");
    turn(30);
  }
  delay(300);
}

void turn(int s){
  Mini.M1.set(s);
  Mini.M2.set(-s);
  delay(3000);
  Mini.M1.set(0);
  Mini.M2.set(0);
}
