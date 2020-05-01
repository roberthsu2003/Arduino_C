//arduinoC
/*
請使用三元運算子? : 製作一個判斷奇偶數的程式，程式的執行結果,偶數蜂鳴器叫2次,奇數蜂鳴器叫1次
顯示=============
請輸入數字:15
您輸入的15是奇數
 */
 
#define buzzer 3

void setup(){
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, HIGH);
  
  Serial.begin(9600);  
  Serial.println("請輸入數字:");  
}

void loop() {
  int inputNumber;
  String message;
  if(Serial.available()){
    inputNumber = Serial.parseInt();
    
    message = (inputNumber % 2 == 0) ? "偶數" : "奇數";

    switch(inputNumber % 2){
      case 0:
        
        digitalWrite(buzzer, LOW);
        delay(200);
        digitalWrite(buzzer, HIGH);
        delay(200);
        digitalWrite(buzzer, LOW);
        delay(200);
        digitalWrite(buzzer, HIGH);
        delay(200);
        break;
      case 1:
        
        digitalWrite(buzzer, LOW);
        delay(200);
        digitalWrite(buzzer, HIGH);
        delay(200);
        break;
      }
      
    Serial.print("您輸入的");
    Serial.print(inputNumber);
    Serial.print("是");
    Serial.println(message);
  }
  
}
