//============================================================================
// Name        : for1.ino
//計算2 - 10所有偶數的總和
//================================================================
//第 1 次迴圈的 i = 2,總和為:2
//第 2 次迴圈的 i = 4,總和為:6
//第 3 次迴圈的 i = 6,總和為:12
//第 4 次迴圈的 i = 8,總和為:20
//第 5 次迴圈的 i = 10,總和為:30
//=================================================================
//BUZZER要插在D1腳

#define BUZZER 3

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, HIGH);

  int sum = 0;
  for(int i=2; i<=10; i+=2){
    sum += i;
    Serial.println("第"+String(i/2) +"次迴圈的i=" + String(i) + "總和為" + String(sum));
    digitalWrite(BUZZER, LOW);
    delay(100);
    digitalWrite(BUZZER, HIGH);
    delay(100);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
