#include <MatrixMini.h>
#define TRIGGER_PIN  A0
#define ECHO_PIN A1
#define US 58.1
#define buzzer 3

void setup() {
  Mini.begin();
  pinMode(TRIGGER_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);
  Serial.begin(9600);
  
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, HIGH);
  
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
      alermSystem();  
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
      removeAlerm();    
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

void alermSystem(){
   bee(buzzer,500);
   Serial.println("開啟防盜");
   int distances[10];
   for(int i=0; i<10; i++){
      distances[i] = ping();
      Serial.print(distances[i]);
      Serial.print(" ");
   }
}

void removeAlerm(){
  bee(buzzer,500);
  Serial.println("解除防盜");
}

void bee(int pin,int delayTime){
  digitalWrite(pin, LOW);
  delay(delayTime);
  digitalWrite(pin, HIGH);
}


