#define BUZZER 3

void setup() {
  //啟動BUZZER
  pinMode(BUZZER,OUTPUT);
  digitalWrite(BUZZER,HIGH);
  Serial.begin(9600);

  int n = 0;
  int sum = 0;
  for(int i=1; i<=7; i++){
    if(i==7){
      Serial.print("請輸入星期日的支出:");      
    }else{
      Serial.print("請輸入星期"+(String)i+"的支出:");
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

  Serial.print("本星期的支出為:" + (String)sum + "元");
 

}

void loop() {
  // put your main code here, to run repeatedly:

}
