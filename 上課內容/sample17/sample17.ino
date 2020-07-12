//============================================================================
// Name        : guess.ino
//猜數字遊戲
//猜對後請發出美樂迪音樂


void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(A0));
  int guess = random(1, 100);
  int keyin;
  int min = 1;
  int max = 99;
  int count = 0;
  Serial.println("===============猜數字遊戲=================:\n\n");
  
  do {
    Serial.print("猜數字範圍");
    Serial.print(min);
    Serial.print("~");
    Serial.print(max);
    Serial.print(":");
    
    while (true) {
      if (Serial.available()) {
        keyin = Serial.parseInt();
        count++;
        Serial.println(keyin);
        break;
      }
    }

    if(keyin >= min && keyin <= max){
       if (keyin == guess) {
        Serial.print("賓果!猜對了,答案是");
        Serial.println(guess);
        Serial.print("您猜了");
        Serial.print(count);
        Serial.println("次\n");
        break;
      } else if(keyin > guess){
        max = keyin;
        Serial.println("再小一點\n");
      }else if(keyin < guess){
        min = keyin;
        Serial.println("再大一點\n");
      }
      Serial.print("您猜了");
      Serial.print(count);
      Serial.println("次\n");
      
      
    }else{
      Serial.println("請輸入提示範圍內的數字! \n");
    }
   
  } while (true);


}

void loop() {
  // put your main code here, to run repeatedly:

}
