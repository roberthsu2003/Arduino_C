#include <MatrixMini.h>


void setup() {
  Mini.begin();  // create with the default frequency 1.6KHz
  Serial.begin(9600);           // set up Serial library at 9600 bps

  
  Serial.println("\n Matrix Mini DC Motor Test \n");
  int i=70;
  
  Mini.M1.set(i);  
  Mini.M2.set(i);
  delay(3000);
  Mini.M1.set(0);
  Mini.M2.set(0);
}


void loop() { 
  
}
