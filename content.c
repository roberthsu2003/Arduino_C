#include <MatrixMini.h>

void setup() {
  // put your setup code here, to run once:
  Mini.begin();
  Serial.begin(9600);
  Serial.println("小車按鈕測試");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("按鈕1: ");
  Serial.print(Mini.BTN1.get());
  Serial.print("按鈕2: ");
  Serial.print(Mini.BTN2.get());
  Serial.println();
  delay(50);
}
