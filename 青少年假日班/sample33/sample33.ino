//小車循跡S區線，終點使用障礙物，讓小車轉一圈後循跡S區線，回到起點
//D1插孔 - 紅外線左模組
//D2插孔- 紅外線右模組

#include <Thread.h>

#define irLeft 2
#define irRight 3

Thread myThread = Thread();

void setup() {
  Serial.begin(9600);
  pinMode(irLeft,INPUT);
  pinMode(irRight,INPUT);
  myThread.onRun(runS);
  myThread.setInterval(50);
}

void loop() {
  if(myThread.shouldRun()){
    myThread.run();
  }

}

void runS(){
  Serial.println("0.05Run");
}
