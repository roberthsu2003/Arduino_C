#include <MatrixMini.h>
void setup() {
  Mini.begin();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  leftButton();
  rightButton();
}

void leftButton(){
  static bool previousState = false;
   static int counter = 0;
   bool currentState = Mini.BTN1.get();
  if(currentState != previousState){    
    counter += 1;
    if(counter % 2 == 0){
      Serial.println("左按鈕被按了一下");     
    }
    previousState = currentState;
  }
}

void rightButton(){
  static bool previousState = false;
   static int counter = 0;
   bool currentState = Mini.BTN2.get();
  if(currentState != previousState){    
    counter += 1;
    if(counter % 2 == 0){
      Serial.println("右按鈕被按了一下");     
    }
    previousState = currentState;
  }
}

