/*--------------------------------
 *使用者,可以在arudino編輯器的序列埠管理員
 *輸入3個數值,格式如下: 255,255,0
 *rgb參數必需傳入3個int元素的陣列
 *
----------------------------- */
void inputMultipleValue(int* rgb){
  if(Serial.available() > 0){
    String stringBuffer = Serial.readString();    
    int stringLength = stringBuffer.length();
    String rString = "";     
    int j = 0;
     
    for(int i=0; i<stringLength; i++){
      
      if(stringBuffer[i] != ',' ){ 
        rString += stringBuffer[i];       
      }else{
        rgb[j] = rString.toInt();
        j++;
        rString = "";
      }

      if(i == stringLength-1){
        rgb[j] = rString.toInt();
        j++;
         rString = "";
      } 
      
      
    }

    
    
  }
}








#include "inputThreeValue.h"
int rgb[3] = {0, 0, 0};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  inputMultipleValue(rgb);
  Serial.print('R=');
  Serial.println(rgb[0]);
  Serial.print('G=');
  Serial.println(rgb[1]);
  Serial.print('B=');
  Serial.println(rgb[2]);
  Serial.println("========================");
  delay(3000);

}
