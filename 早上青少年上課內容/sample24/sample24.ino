//循跡車
//人面對背面方向
//D1插孔 - 紅外線左模組
//D2插孔- 紅外線右模組

//白色-0
//黑色-1

#include <MatrixMini.h>
#include <Thread.h>

MatrixMini Mini;
Thread myThread = Thread();

#define irLeft 2
#define irRight 3

void setup() {
  Mini.begin();
  myThread.onRun(detect);
  myThread.setInterval(10);
  pinMode(irLeft, INPUT);
  pinMode(irRight, INPUT);
}

void loop() {
  if(myThread.shouldRun()){
    myThread.run();
  }
  delay(1);
}

void detect(){
  int leftValue = digitalRead(irLeft);
  int rightValue = digitalRead(irRight);
  int speed = 75;
  int slow = 75;
  if(leftValue == 0 && rightValue == 0){
    //直走
    running(speed, speed);
  }else if(leftValue == 0 && rightValue == 1){
    //右轉
    running(speed, speed-slow);
  }else if(leftValue == 1 && rightValue ==0){
    //左轉
    running(speed-slow, speed);
  }else{
    running(0, 0);
  }
}

void running(int leftMotor, int rightMotor){
  //M1 = 左輪
  //M2 = 右輪
  Mini.M1.set(leftMotor);
  Mini.M2.set(rightMotor);
}
