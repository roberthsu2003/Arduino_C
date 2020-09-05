#define BUZZER 3

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, HIGH);

  int sum = 0;
  for(int i=2; i<=10; i+=2){
    sum += i;
    Serial.println("第"+String(i/2) +"次迴圈的i=" + String(i) + "總和為" + String(sum));
    digitalWrite(BUZZER, LOW);
    delay(100);
    digitalWrite(BUZZER, HIGH);
    delay(100);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
