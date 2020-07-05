#include <MatrixMini.h>
#define LIGHT_SENSOR A1
#define LIGHT_DIGITOR A0

MatrixMini Mini;
void setup() {
  Mini.begin();
  Serial.begin(9600);
  pinMode(LIGHT_DIGITOR, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Digitor:");
  Serial.println(digitalRead(LIGHT_DIGITOR));
  Serial.print("Analog:");
  Serial.println(analogRead(LIGHT_SENSOR));
  delay(500);
}
