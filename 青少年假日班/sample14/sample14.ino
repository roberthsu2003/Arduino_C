#define BUZZER 3

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

}
