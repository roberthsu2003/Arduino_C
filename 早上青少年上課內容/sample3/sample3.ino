//arduinoC
//arduinoC的輸入輸出

void setup() {
  Serial.begin(9600);
  int englishScore = 60;
  Serial.println("請輸入您的英文分數:");
  
  while(true){
    if(Serial.available()){
      englishScore = Serial.parseInt();
      break;
    }
  }

  Serial.print("Hello! 您的英文分數是:");
  Serial.println(englishScore);
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
