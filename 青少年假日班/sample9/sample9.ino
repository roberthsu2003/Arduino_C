#define RATE 1.325

//const float RATE = 1.325;
void setup() {
  Serial.begin(9600);
  float payMoney = 50000 * RATE;
  Serial.println("payMoney:" + String(payMoney));

}

void loop() {
  // put your main code here, to run repeatedly:

}
