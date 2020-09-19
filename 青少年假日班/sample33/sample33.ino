//小車循跡S區線，終點使用障礙物，讓小車轉一圈後循跡S區線，回到起點
//D1插孔 - 紅外線左模組
//D2插孔- 紅外線右模組
//白色-0
//黑色-1

#include <Thread.h>
#include <MatrixMini.h>

#define irLeft 2
#define irRight 3

Thread myThread = Thread();
MatrixMini Mini;

void setup() {
  Serial.begin(9600);
  Mini.begin();
  pinMode(irLeft,INPUT);
  pinMode(irRight,INPUT);
  myThread.onRun(runS);
  myThread.setInterval(50);
  delay(1000);
}

void loop() {
  if(myThread.shouldRun()){
    myThread.run();
  }

}

int speed = 70;
int g=40;

void runS(){
  Serial.println("0.05Run");
  int leftValue = digitalRead(irLeft);
  int rightValue = digitalRead(irRight);
  //Serial.println("leftValue=" + String(leftValue));
  //Serial.println("rightValue=" + String(rightValue));
  if (leftValue == 0 && rightValue == 0){
    //直走
    running(speed, speed);
  }else if(leftValue == 0 && rightValue == 1){
    //右轉
    running(speed, speed-g);  
  }else if(leftValue == 1 && rightValue == 0){
    //左轉
    running(speed-g, speed);
  }else{
    running(0,0);
  }
}

void running(int leftMotor,int rightMotor){
  Mini.M1.set(leftMotor);
  Mini.M2.set(rightMotor);
}
