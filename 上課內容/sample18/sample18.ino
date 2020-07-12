//============================================================================
// Name        : withoutDelay.ino
//不使用delay()方法,計算時間,讓2個LED每格1秒亮燈,顏色要使用亂數
//請使用function millis()

unsigned long previousMillis = 0;

//建立常數
const long interval = 1000;
unsigned long second=0;

void setup() {
  Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval){
    //過了1秒
    second++;
    previousMillis = currentMillis;
    Serial.print("過了");
    Serial.print(second);
    Serial.println("秒");
  }
  
}
