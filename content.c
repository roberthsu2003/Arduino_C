#define analogSensor A2
#define digitalSensor A3

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  int analogValue = analogRead(analogSensor);
  int digitalValue = digitalRead(digitalSensor);

  Serial.println("暗亮訊號值");
  Serial.print("類比訊號:");
  Serial.println(analogValue);
  Serial.print("數位訊號:");
  Serial.println(digitalValue);
  delay(500);
}
