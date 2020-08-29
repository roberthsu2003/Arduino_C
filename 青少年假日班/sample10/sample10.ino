String password;
void setup() {
  Serial.begin(9600);
  Serial.println("請輸入密碼:");
  
  while(true){
    if(Serial.available()){
      password =Serial.readString();
      if(password == "1234"){
        Serial.println("密碼正確!歡迎光臨!");
      }else{
        Serial.println("密碼錯誤!請重新輸入!");      
      }
      break;
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
