//使用光敏電阻,檢查目前的亮度
//插入至Ａ1孔
//小於等於100 很亮
//小於等於200,大於100 亮
//小於等於400,大於200有點亮
//小於等於600,大於400有點暗
//小於等於800,大於600暗
//小於等於1023,大於800 很暗
//當狀態改變時，請閃爍一下LED2

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
  int analogValue = analogRead(A1);
  
  if(analogValue<100){
    state = "很亮";
  }else if (analogValue<200){
    state = "亮";
  }else if (analogValue<400){
    state = "有點亮";
  }else if(analogValue<600){
    state = "有點暗";
  }else if(analogValue<800){
    state = "暗";
  }else{
    state = "很暗";
  }

  if (state != preState){
    Serial.println("狀態改變");
    Mini.LED2.setRGB(255,0, 0);
    delay(500);
    Mini.LED2.setRGB(0,0, 0);
    preState = state;
  }
  
  Serial.println(state);
  delay(500);
}
