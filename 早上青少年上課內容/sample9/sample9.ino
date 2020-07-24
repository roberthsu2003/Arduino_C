//輸入顧客購買金額，若金額在10000元打8折，5000打85折，3000打9折，1000打95折
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("請輸入購買金額:");
}

void loop() {
  int money;
  if(Serial.available()){
    money = Serial.parseInt();
    Serial.print("您購買的金額是:");
    Serial.println(money);
  }
}
