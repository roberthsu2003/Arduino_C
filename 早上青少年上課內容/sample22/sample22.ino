#include <MatrixMini.h>

#define LIGHT_SENSOR A1
#define LIGHT_DIGITOR A0
#define SPEED 100

//一開始要取得目前光線的平均值
//光線變暗時,向左或向右旋轉3秒
MatrixMini Mini;
int lightAvg;

void setup() {
  Mini.begin();
  Serial.begin(9600);
  int lightTotal = 0;
  for (int i = 0; i < 10; i++) {
    lightTotal += analogRead(LIGHT_SENSOR);
    delay(100);
  }
  lightAvg = lightTotal / 10;
  Serial.print("目前光線平均強度");
  Serial.println(lightAvg);

}

void loop() {
  int currentLight = analogRead(LIGHT_SENSOR);
  int diffentValue = currentLight - lightAvg;
  if (diffentValue > 100) {
    switch (diffentValue % 2) {
      case 0:
        Serial.println("正轉");
        //turn(SPEED);
        turn1(SPEED);
        break;
      case 1:
        Serial.println("反轉");
        //turn(-SPEED);
        turn1(-SPEED);
        break;
    }
  }
}

void turn(int speed) {
  Mini.M1.set(speed);
  Mini.M2.set(-speed);
  delay(3000);
  Mini.M1.set(0);
  Mini.M2.set(0);
}

void turn1(int speed) {
  for (int i = 0; i <= 3; i++){
    Mini.M1.set(speed);
    Mini.M2.set(-speed);
    delay(1000);
    Mini.M1.set(speed);
    Mini.M2.set(speed);
    delay(500);
    Mini.M1.set(-speed+50);
    Mini.M2.set(-speed+50);
    delay(500);
  }
  Mini.M1.set(0);
  Mini.M2.set(0);
}
