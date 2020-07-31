//建立切換按鈕，按一次為LED開, 再按一次LED關
//請在資源庫安裝Arduino Thread

#include <MatrixMini.h>
#include <Thread.h>

MatrixMini Mini;
Thread myThread = Thread();

bool buttonState;
int pressCount=0;

void setup() {
  Mini.begin();
  Serial.begin(9600);
  buttonState = Mini.BTN1.get();
  myThread.onRun(callBack);
  myThread.setInterval(500);   
}

void loop() {
  if(myThread.shouldRun()){
    myThread.run();
  }
  if(buttonState != Mini.BTN1.get()){
    delay(50);
    if(buttonState != Mini.BTN1.get()){
      pressCount++;
      buttonState = !buttonState;
      Serial.println(pressCount);
    }    
  } 

}

void callBack(){
  switch(pressCount % 4){
    case 2:
      Serial.println("按鈕開");
      Mini.LED1.setRGB(255, 0, 0);
      break;
    case 0:
      Serial.println("按鈕關");
      Mini.LED1.setRGB(0, 0, 0);
      break;
  }
}
