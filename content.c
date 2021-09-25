#include <MatrixMini.h>
#define TRIGGER_PIN  A0
#define ECHO_PIN     A1
#define MAX_DISTANCE 200
#define US 58.1

void setup() {
  Mini.begin();  // create with the default frequency 1.6KHz
  Serial.begin(9600); // set up Serial library at 9600 bps  
  Serial.println("\n Matrix Mini DC Motor Test \n");
  pinMode(TRIGGER_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);
  
}

void loop() { 
  delay(100);
  fireButton();
  stopButton();
  int distance = ping();
  Serial.println(distance);
  if(distance <= 10){
    stopCar();
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
      fireCar(50);
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

int ping(){
  digitalWrite(TRIGGER_PIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN,LOW);
  unsigned long pulseTime = pulseIn(ECHO_PIN,HIGH);
  return pulseTime / US;
}

void fireCar(int i){  
  Mini.M1.set(i);  
  Mini.M2.set(i);  
}

void stopCar(){
   Mini.M1.set(0);  
   Mini.M2.set(0);  
}
