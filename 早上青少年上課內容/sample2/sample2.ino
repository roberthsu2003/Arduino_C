void setup() {
  Serial.begin(9600);
  Serial.println("您好,這裏是setup");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("您好,這裏是loop");
  delay(1000);
}
