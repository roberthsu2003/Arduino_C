long randomNumber;

void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
randomSeed(analogRead(A0));
}

void loop() {

  // 列印出0~299的亂數
  
  randomNumber = random(300);
  Serial.println(randomNumber);
  delay(1000);

  // 列印出10~19的亂數
  randomNumber = random(10, 20);
  Serial.println(randomNumber);
  delay(1000);
 
}
