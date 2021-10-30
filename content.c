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
  while(true){
    Serial.println("猜數字範圍"+String(min)+"~"+String(max)+":");
    while(true){
      if(Serial.available()){
        keyin = Serial.parseInt();
        break;
      }
    }
    count += 1;
    if(keyin >= min && keyin <=max){
      if(keyin == guess){
        Serial.println("賓果!猜對了,答案是"+String(guess));
        Serial.println("您猜了" + String(count) + "次");
        break;
      }else if(keyin > guess){
        max = keyin - 1;
        Serial.println("再小一點");
      }else if(keyin < guess){
        min = keyin + 1;
        Serial.println("再大一點");
      }
      Serial.println("您已經猜了"+String(count)+"次");
      
    }else{
      Serial.println("請輸入提示範圍內的數字!");
    }
  }

  Serial.println("遊戲結束");
  
}
