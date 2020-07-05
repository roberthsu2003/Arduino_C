#include <MatrixMini.h>
#define LIGHT_SENSOR A1
#define LIGHT_DIGITOR A0

MatrixMini Mini;

String state;
String preState="";
void setup() {
  Mini.begin();
  Serial.begin(9600);
  pinMode(LIGHT_DIGITOR, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Digitor:");
  Serial.println(digitalRead(LIGHT_DIGITOR));
  Serial.print("Analog:");
  int analogValue = analogRead(LIGHT_SENSOR);
  Serial.println(analogValue);

  if(analogValue <= 100){
    state = "很亮";
  }else if(analogValue <= 200){
    state = "亮";
  }else if(analogValue <= 400){
    state = "有點亮";
  }else if(analogValue <= 600){
    state = "有點暗";
  }else if(analogValue <= 800){
    state = "暗";
  }else{
    state = "很暗";
  }

  Serial.println(state);
  if(state != preState){
    Serial.println("狀態改變");
    Mini.LED2.setRGB(255, 0, 0);
    delay(500);
    Mini.LED2.setRGB(0, 0, 0);
    preState = state;
  }
  
  delay(500);
}
