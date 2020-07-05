void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  char characterA;
  characterA = 'A';
  Serial.print("characterA=");
  Serial.println(characterA);

  characterA = 97;
  Serial.print("characterA=");
  Serial.println(characterA);
}

void loop() {
  // put your main code here, to run repeatedly:

}
