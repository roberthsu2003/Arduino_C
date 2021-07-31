
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(analogRead(A1));
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(random(1,101));
  
  delay(1000);
}
