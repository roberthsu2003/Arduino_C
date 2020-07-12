//============================================================================
// Name        : for2.ino
//計算固定中的支出，媽媽每天會將家裡的花費記錄下來，並且計算本週的花費總和
//================================================================

void setup() {
  Serial.begin(9600);
  int sum = 0, n;
  for(int i=1;i<=7;i++){
    if(i == 7){
      Serial.print("請輸入星期日的支出:");
    }else{
      Serial.print("請輸入星期");
      Serial.print(i);
      Serial.print("的支出:");
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
  Serial.print("本星期的支出為:");
  Serial.print(sum);
  Serial.println("元");
}

void loop() {
  // put your main code here, to run repeatedly:

}
