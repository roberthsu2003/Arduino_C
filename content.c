#define LIGHT_DIGITOR A0
#define LIGHT_SENSOR A1

void setup() {
  Serial.begin(9600);
  pinMode(LIGHT_DIGITOR, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("=====光敏電阻數位訊號===========");
  bool digitalValue = digitalRead(LIGHT_DIGITOR);
  Serial.println("數位訊號是:"+String(digitalValue));
  Serial.println("\n\n");
  Serial.println("=====光敏電阻類比訊號===========");
  int analogValue = analogRead(LIGHT_SENSOR);
  Serial.println("類比訊號是:"+String(analogValue));
  delay(1000);
}
