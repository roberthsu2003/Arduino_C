#include <MatrixMini.h>
//將光敏電阻插入至A1
#define LIGHT_SENSOR A1
#define LIGHT_DIGITOR A0

MatrixMini Mini;
int lightAvg;

void setup() {
  Mini.begin();
  Serial.begin(9600);
  long lightTotal = 0;
  for(int i=0; i<10; i++){
    lightTotal += analogRead(LIGHT_SENSOR);
  }
  
  lightAvg=lightTotal/10;
  Serial.print("目前光線平均強度");
  Serial.println(lightAvg);
}

void loop() {
  // put your main code here, to run repeatedly:

}
