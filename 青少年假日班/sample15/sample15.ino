//============================================================================
// Name        : for2.ino
//計算固定中的支出，媽媽每天會將家裡的花費記錄下來，並且計算本週的花費總和
//每輸入一次就響一次
//================================================================
//請輸入星期1 的支出567
//請輸入星期2 的支出456
//請輸入星期3 的支出567
//請輸入星期4 的支出890
//請輸入星期5 的支出345
//請輸入星期6 的支出534
//請輸入星期日 的支出678
//本星期的支出為:4037元
//==================================================================

//BUZZER插入在D1孔
#define BUZZER 3

void setup() {
  //啟動序列埠
  Serial.begin(9600);
  //啟動Buzzer
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, HIGH);

  int n=0;
  int sum = 0;
  for(int i=1; i<=7; i++){
    digitalWrite(BUZZER, LOW);
    delay(100);
    digitalWrite(BUZZER, HIGH);
    if(i==7){
      Serial.print("請輸入星期日的支出:");
    }else{
      Serial.print("請輸入星期"+String(i)+"的支出:");
    }

    while(true){
      if(Serial.available()){
        n = Serial.parseInt();
        Serial.println(n);
        sum += n;
        break;
      }
    }
  }

  Serial.print("本星期的支出為:"+ String(sum) + "元");
}

void loop() {
  // put your main code here, to run repeatedly:

}
