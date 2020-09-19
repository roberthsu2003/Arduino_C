void setup() {
  Serial.begin(9600);
  int scores[3];
  scores[0] = 70;
  scores[1] = 80;
  scores[2] = 90;

  Serial.println("scores[0]=" + String(scores[0]));
  Serial.println("scores[1]=" + String(scores[1]));
  Serial.println("scores[2]=" + String(scores[2]));
}

void loop() {
  // put your main code here, to run repeatedly:

}
