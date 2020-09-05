//============================================================================
// Name        : guess.ino
//猜數字遊戲
//猜對後請發出美樂迪音樂
#include <sound.h>
#define BUZZER 3

Sound buzzer(BUZZER);
int guess;
int min = 1;
int max = 99;
  
void setup() {
  Serial.begin(9600);
  Serial.println("===============猜數字遊戲=================:\n");
  Serial.print("請輸入一個幸運號碼(1000~62000):");
  while(true){
    if(Serial.available()){
      int inputNum = Serial.parseInt();
      Serial.println(inputNum);
      randomSeed(inputNum);
      break;
    }
  }
  pinMode(BUZZER, OUTPUT);  
  
}

void loop() {
  randomSeed(millis());
  guess = random(min, max+1);
  Serial.println(guess);
  while(true);

}
