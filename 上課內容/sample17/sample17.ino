//============================================================================
// Name        : guess.ino
//猜數字遊戲
//猜對後請發出美樂迪音樂


void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(A0));
  int guess = random(1, 100);
  int keyin;
  Serial.println("===============猜數字遊戲=================:\n\n");
  do {

    Serial.print("猜數字範圍1~99:");
    while (true) {
      if (Serial.available()) {
        keyin = Serial.parseInt();
        Serial.println(keyin);
        break;
      }
    }

    if (keyin == guess) {
      Serial.print("賓果!猜對了,答案是");
      Serial.println(guess);
    } else {
      Serial.println("沒有猜中");
    }


  } while (true);


}

void loop() {
  // put your main code here, to run repeatedly:

}
