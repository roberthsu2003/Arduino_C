#include <IRremote.h>
#define IRPin 7

IRrecv irrecv(IRPin);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if(irrecv.decode(&results)){
    Serial.print("irCode:");
    Serial.print(results.value, Hex);
    Serial.print(",bits:");
    Serial.println(results.bits);
    irrecv.resume();
  }

  delay(600);
}
