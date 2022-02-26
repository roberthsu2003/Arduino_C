#define btnPin 7

bool btnState;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(btnPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  btnState = digitalRead(btnPin);
  Serial.println(btnState);
  delay(100);
}
