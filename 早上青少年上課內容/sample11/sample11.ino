
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
#define LIGHT_DIGHTOR A0

MatrixMini Mini;

void setup() {
  Mini.begin();
  Serial.begin(9600);
  Serial.println("==========光敏電阻測試==============");
  pinMode(LIGHT_DIGHTOR, INPUT);
}

void loop() {
  Serial.println("==========光敏電阻數位訊號輸出==============");
  bool digitalValue = digitalRead(LIGHT_DIGHTOR);
  Serial.print("數位訊號是:");
  Serial.println(digitalValue);
  Serial.println("\n\n");
  Serial.println("==========光敏電阻類比訊號輸出==============");
  int analogValue = analogRead(LIGHT_SENSOR);
  Serial.print("類比訊號是:");
  Serial.println(analogValue);
  delay(1000);
}
