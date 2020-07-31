#include <sound.h>

#define BUZZER 3 //接線至D1插孔

Sound s(BUZZER);

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
  int min = 1;
  int max = 99;
  int guess;
  //建立亂數
  randomSeed(analogRead(0));
  guess = random(min, max+1);
  Serial.println("現在的亂數是" + (String)guess);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
