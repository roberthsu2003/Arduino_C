#include <MatrixMini.h>
#define TRIGGER_PIN  A0
#define ECHO_PIN     A1
#define MAX_DISTANCE 200
#define US 58.1
 


int cm;

void setup() {
  Mini.begin();  // create with the default frequency 1.6KHz
  Serial.begin(9600); // set up Serial library at 9600 bps  
  Serial.println("\n Matrix Mini DC Motor Test \n");
  pinMode(TRIGGER_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);
  
}

void loop() { 
  delay(100);
  Serial.println(Mini.BTN1.get());  
}

int ping(){
  digitalWrite(TRIGGER_PIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN,LOW);
  unsigned long pulseTime = pulseIn(ECHO_PIN,HIGH);
  return pulseTime / US;
}

void back(int i){  
  Mini.M1.set(i);  
  Mini.M2.set(i);
  delay(1000);
  Mini.M1.set(0);
  Mini.M2.set(0);
  delay(1000);
  Mini.M1.set(-i);  
  Mini.M2.set(-i);
  delay(1000);
  Mini.M1.set(0);
  Mini.M2.set(0);
  
}
