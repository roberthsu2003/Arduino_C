#include <MatrixMini.h>

MatrixMini Mini;


void setup() {
  Mini.begin();  // create with the default frequency 1.6KHz
  Serial.begin(9600);           // set up Serial library at 9600 bps

  
  Serial.println("\n Matrix Mini DC Motor Test \n");

  Mini.M1.set(0);
  Mini.M2.set(0);
}


void loop() {
  int i;
  
  Serial.println("One way");
  for (i=-100; i<100; i++) {
    Mini.M1.set(i);  
    Mini.M2.set(i);
    delay(15);
  }
  
  Serial.println("Or another");
  for (i=100; i>-100; i--) {
    Mini.M1.set(i);  
    Mini.M2.set(i);
    delay(15);
  }
  
}
