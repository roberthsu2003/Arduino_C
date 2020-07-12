void setup() {
  Serial.begin(9600);
  for(int i=1; i<=9; i++){
    for(int j=1; j<=9; j++){
      Serial.print(i);
      Serial.print("*");
      Serial.print(j);
      Serial.print("=");
      Serial.print(i*j);
      Serial.print("\t");
    }
    Serial.print("\n");
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
