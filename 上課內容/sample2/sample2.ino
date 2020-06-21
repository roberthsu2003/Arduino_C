#include <MatrixMini.h>

MatrixMini Mini;

void setup() {
  Mini.begin(); 
  Serial.begin(9600);

  Serial.println("\n Matrix Mini Button LED Test \n");
}

void loop() {
  if(Mini.BTN1.get()) 
    Mini.LED1.setRGB(255,0, 0);
  else
    Mini.LED1.setRGB(0,0, 0);


  if(Mini.BTN2.get()) 
    Mini.LED2.setRGB(0,255, 0);
  else
    Mini.LED2.setRGB(0,0, 0);
  
  delay(50);
}
