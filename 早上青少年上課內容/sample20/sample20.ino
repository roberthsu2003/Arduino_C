#include <MatrixMini.h>

MatrixMini Mini;
void setup() {
  Mini.begin();
  Serial.begin(9600);
  Serial.println("\n Matrix Mini 直流馬達測試 \n");
  Mini.M1.set(50);
  Mini.M2.set(50);
  delay(3000);
  Mini.M1.set(0);
  Mini.M2.set(0);
}

void loop() {
  // put your main code here, to run repeatedly:

}
