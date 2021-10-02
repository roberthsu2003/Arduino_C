#include <MatrixMini.h>

void setup() {
  // put your setup code here, to run once:
  Mini.begin();  // create with the default frequency 1.6KHz
  Serial.begin(9600);
}

void loop() {
  fireButton();
  stopButton();
}

void fireButton(){
   static bool previousState = false;
   static int counter = 0;
   bool currentState = Mini.BTN1.get();
  if(currentState != previousState){    
    counter += 1;
    if(counter % 2 == 0){
      Serial.println("防盜器啟動");      
    }
    previousState = currentState;
  }
}

void stopButton(){
  static bool previousState = false;
  static int counter = 0;
  bool currentState = Mini.BTN2.get();
  if(currentState != previousState){    
    counter += 1;    
    if(counter % 2 == 0){
      Serial.println("防盜器關閉");     
    }
    previousState = currentState;
  }
}
