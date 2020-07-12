//============================================================================
// Name        : forNest1.cpp
//利用2層迴圈列印「井」字，將其排列成直角三角形
//每輸出一個「井」字，就LED2就閃爍一次，每輸出2個「井」字，就BTN2就閃爍2次....
//=======================================================
//#
//##
//###
//####
//####
//====================================================


#include <MatrixMini.h>
#include <sound.h>

MatrixMini Mini;
Sound s(3);

void setup() {
  Serial.begin(9600);
  Mini.begin();
  for(int i=1; i<=5; i++){
    for(int j=1; j<=i; j++){
      Serial.print("#");
      Mini.LED2.setRGB(255,0,0);
      delay(100);
      Mini.LED2.setRGB(0,0,0);
      delay(100);
      s.beep(200);
    }
    Serial.println();
    delay(1000);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
