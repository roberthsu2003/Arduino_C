#define LIGHT_DIGITOR A0


void setup() {
  Serial.begin(9600);
  pinMode(LIGHT_DIGITOR, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("=====光敏電阻數位訊號===========");
  bool digitalValue = digitalRead(LIGHT_DIGITOR);
  Serial.println("數位訊號是:"+String(digitalValue));  
  delay(1000);
}
