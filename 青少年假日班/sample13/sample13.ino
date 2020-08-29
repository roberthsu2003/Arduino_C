//輸入顧客購買金額，若金額在100000元打8折，50000打85折，30000打9折，10000打95折

long money;
long payMoney;

void setup() {
  Serial.begin(9600);
  Serial.println("請輸入購買金額:");
}

void loop() {
  if(Serial.available()){
    money = Serial.parseInt();
    Serial.println("您購買的金額:" + String(money));

    if(money >= 100000){
      payMoney = money * 0.8;
    }else if(money >= 50000){
      payMoney = money * 0.85;
    }else if(money >= 30000){
      payMoney = money * 0.9;
    }else if(money >= 10000){
      payMoney = money * 0.95;
    }else{
      payMoney = money;
    }

    Serial.println("實付金額是:" + String(payMoney) + "元");
    Serial.println("=====================================");
  }
}
