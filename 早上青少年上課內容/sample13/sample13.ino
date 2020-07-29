//計算2 - 10所有偶數的總和
#define BUZZER 3

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, HIGH); //一開始不要有聲音
  
  int sum = 0;
  for(int i=2;i<=10;i+=2){
    sum += i;
    Serial.print("第");
    Serial.print(i/2);
    Serial.print("次迴圈的i=");
    Serial.print(i);
    Serial.print(",總和為");
    Serial.println(sum);
    digitalWrite(BUZZER, LOW);
    delay(100);
    digitalWrite(BUZZER, HIGH);
    delay(1000);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
