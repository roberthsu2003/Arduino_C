void setup() {
  Serial.begin(9600);
  char characterA;
  characterA = 'A';
  Serial.print("characterA=");
  Serial.print('\'');
  Serial.print(characterA);
  Serial.print('\'');
  Serial.print("\n");
  //字串相加
  Serial.print("characterA=\'"+ (String)characterA + "\'");

}

void loop() {
  // put your main code here, to run repeatedly:

}
