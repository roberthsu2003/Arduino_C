#include <MatrixMini.h>
#define buzzer 3

void setup() {
  // put your setup code here, to run once:
  Mini.begin();
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  leftButton();
}



void leftButton(){
   static bool previousState = false;
   static int counter = 0;
   bool currentState = Mini.BTN1.get();
  if(currentState != previousState){    
    counter += 1;
    if(counter % 2 == 0){
      //Serial.println("左按鈕被按了一下");
      bee(buzzer,500);
      playGame();  
    }
    previousState = currentState;
  }
}

void bee(int pin,int delayTime){
  digitalWrite(pin, LOW);
  delay(delayTime);
  digitalWrite(pin, HIGH);
}

void playGame(){
  int min = 1;
  int max = 99;
  int keyin;
  int count = 0;
  int guess = random(1,100);
  Serial.print("=================猜數字遊戲================\n\n");
}
