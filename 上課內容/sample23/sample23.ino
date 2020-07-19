//紅外線校對
//循跡車
//人面對背面方向
//D1插孔 - 紅外線左模組
//D2插孔- 紅外線右模組

//白色-0
//黑色-1
#include <MatrixMini.h>
#include <Thread.h>

#define irLeft 2
#define irRight 3
#define speed 50

MatrixMini Mini;
Thread myThread = Thread();

void setup() {
  Mini.begin();
  myThread.onRun(detect);
  myThread.setInterval(50);
  Serial.begin(9600);
}

void detect(){
  int leftValue = digitalRead(irLeft);
  int rightValue = digitalRead(irRight);
  Serial.print("leftValue:");
  Serial.println(leftValue);
  Serial.print("rightValue:");
  Serial.println(rightValue);
  if(leftValue == 0 && rightValue == 0){
    //直線
    running(speed, speed);
  }else if(leftValue == 0 && rightValue == 1){
    //右轉
    running(speed, speed-20);
  }else if(leftValue == 1 && rightValue == 0){
    //左轉
    running(speed-20, speed);
  }else{
    //停止
    running(0, 0);
  }
  
  
}

void running(int leftMotor, int rightMotor){
  //M1=左輪
  //M2=右輪
  Mini.M1.set(leftMotor);
  Mini.M2.set(rightMotor);
}

void loop() {
  if(myThread.shouldRun()){
    myThread.run();
  }
  delay(1);
}
