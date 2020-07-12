//============================================================================
// Name        : for1.ino
//計算2 - 10所有偶數的總和
//================================================================
void setup() {
  Serial.begin(9600);
  int sum = 0;
  for(int i=2;i<=10; i+=2){
    sum += i;
    Serial.print("第");
    Serial.print(i/2);
    Serial.print("次迴圈的i=");
    Serial.print(i);
    Serial.print(",總和為");
    Serial.println(sum);
  }
}

void loop() {  

}
