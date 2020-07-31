//arduino C
//使用randomSeed()
//使用random()

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  int randomNum = random(1,100);
  Serial.println(randomNum);
  delay(1000);
}
