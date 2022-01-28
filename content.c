#define VA A0

void setup() {
 Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(VA);
  Serial.println(value);
}
