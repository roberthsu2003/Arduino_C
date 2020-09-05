void setup() {  
  Serial.begin(9600);
  randomSeed(analogRead(0));
 }

void loop() {
  // 列印出0~299的亂數
  int randomNum = random(0, 300);
  Serial.println(randomNum);
  delay(1000);

  // 列印出10~19的亂數
  randomNum = random(10,20);
  Serial.println(randomNum);
  delay(1000);
}
