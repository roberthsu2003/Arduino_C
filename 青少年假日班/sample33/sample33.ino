//小車循跡S區線，終點使用障礙物，讓小車轉一圈後循跡S區線，回到起點
//D1插孔 - 紅外線左模組
//D2插孔- 紅外線右模組
//白色-0
//黑色-1

#include <Thread.h>
#include <MatrixMini.h>
#include <NewPing.h>

#define irLeft 2
#define irRight 3
#define TRIGGER_PIN A0
#define ECHO_PIN A1
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
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
  if(goOrStop()){
    if(myThread.shouldRun()){
      myThread.run();
    }
  }else{
    //停車轉180度
    Mini.M1.set(0);
    Mini.M2.set(0);
    delay(1000);
    int interval = 500;
    int speed = 80;
    Mini.M1.set(speed);
    Mini.M2.set(-speed);
    delay(interval);
    Mini.M1.set(0);
    Mini.M2.set(0);
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

bool goOrStop(){
  int uS = sonar.ping();
  int distance = uS / US_ROUNDTRIP_CM;
  if(distance == 0){
    return true;
  }

  return (distance >= 10) ? true: false;
}
