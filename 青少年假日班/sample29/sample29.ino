void setup() {
  Serial.begin(9600);
  int scores[3] = {70, 80, 90}; //同時給值的動作,只有在建立陣列時可以使用,不可以後面才一次給值

  Serial.println("scores[0]=" + String(scores[0]));
  Serial.println("scores[1]=" + String(scores[1]));
  Serial.println("scores[2]=" + String(scores[2]));
}

void loop() {
  // put your main code here, to run repeatedly:

}
