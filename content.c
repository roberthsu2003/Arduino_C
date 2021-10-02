#include <MatrixMini.h>
#define SPEED 50
#define digitalSensor A3


bool carState = false;

void setup() {
  Mini.begin();  // create with the default frequency 1.6KHz
  Serial.begin(9600); // set up Serial library at 9600 bps  
  pinMode(digitalSensor,INPUT);  
}

void loop() { 
  delay(100);  
  fireButton();
  stopButton(); 
  Serial.println("亂數:"+String(random(500,1000))); 
  bool digitalValue = digitalRead(digitalSensor);
  Serial.println(digitalValue);
  if(digitalValue == 0 && carState == true){
    //stopCar();
    turnCar();
  }
   
}

void fireButton(){
   static bool previousState = false;
   static int counter = 0;
   bool currentState = Mini.BTN1.get();
  if(currentState != previousState){    
    counter += 1;
    if(counter % 2 == 0){
      Serial.println("啟動");
      fireCar();
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
      Serial.println("停止");
      stopCar();
    }
    previousState = currentState;
  }
}


void fireCar(){  
  Mini.M1.set(SPEED);  
  Mini.M2.set(SPEED);
  carState = true; 
}

void stopCar(){
   Mini.M1.set(0);  
   Mini.M2.set(0);
   carState = false;  
}

void turnCar(){
  //停一下 0.5秒
  Mini.M1.set(0);
  Mini.M2.set(0);
  delay(500);
  //旋轉0.8
  Mini.M1.set(SPEED);
  Mini.M2.set(-SPEED);
  //建立亂數
  
  delay(random(500,1000));
  fireCar();
}
