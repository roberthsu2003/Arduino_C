//小車循跡S區線，終點使用障礙物，讓小車轉一圈後循跡S區線，回到起點
//藍線A0 - Echo
//白線A1 - Trig
//安裝NewPing Library
//人面對背面方向
//D1插孔 - 紅外線左模組
//D2插孔- 紅外線右模組


#include <NewPing.h>
#include <MatrixMini.h>
#include <Thread.h>

#define TRIGGER_PIN A1
#define ECHO_PIN A0
#define MAX_DISTANCE 200
#define irLeft 2
#define irRight 3

NewPing sonar(TRIGGER_PIN,ECHO_PIN,MAX_DISTANCE);
Thread myThread = Thread();
MatrixMini Mini;

void setup() {
  Serial.begin(9600);
  Mini.begin(); 
  pinMode(irLeft,INPUT);
  pinMode(irRight,INPUT);
  //oneTurn();//測試轉一圈
  myThread.onRun(runS);
  myThread.setInterval(50);
}

void loop() {
  if (goOrStop()){
    if(myThread.shouldRun()){
      myThread.run(); 
    }
  }else{
    //停車
    Mini.M1.set(0);
    Mini.M2.set(0);
    delay(2000);
    oneTurn();
  }
  
  
  /*
  int uS= sonar.ping();
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM);
  Serial.println("cm");

  int leftValue = digitalRead(irLeft);
  int rightValue = digitalRead(irRight);
  Serial.print("left:");
  Serial.println(leftValue);
  Serial.print("right:");
  Serial.println(rightValue);
  delay(500);
  */
}

bool goOrStop(){
  int uS= sonar.ping();
  int distance = uS / US_ROUNDTRIP_CM;
  /*
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM);
  Serial.println("cm");
  */
  return (distance > 10) ?  true : false;  
}

void runS(){
  Serial.println("runS");
  int leftValue = digitalRead(irLeft);
  int rightValue = digitalRead(irRight);
  int speed = 50;
  int g = 20;
  if(leftValue == 0 && rightValue == 0){
    //直線
    running(speed, speed);
    Serial.println("直線");
  }else if(leftValue == 0 && rightValue == 1){
    //右轉
    running(speed, speed-g);
    Serial.println("右轉");
  }else if(leftValue == 1 && rightValue == 0){
    //左轉
    running(speed-g, speed);
    Serial.println("左轉");
  }
}

void running(int leftMotor, int rightMotor){
  //M1 = 左輪
  //M2 = 右輪
  Mini.M1.set(leftMotor);
  Mini.M2.set(rightMotor);
}

void oneTurn(){
  int interval = 3700;
  int speed = 30;
  Mini.M1.set(speed);
  Mini.M2.set(-speed);
  delay(interval);
  Mini.M1.set(0);
  Mini.M2.set(0);
  //while(true);
}
