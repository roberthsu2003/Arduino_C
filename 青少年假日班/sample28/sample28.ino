//人面對背面方向
//D1插孔 - 紅外線左模組
//D2插孔- 紅外線右模組

//白色-0
//黑色-1

#define irLeft 2
#define irRight 3

void setup() {
  Serial.begin(9600);
  pinMode(irLeft, INPUT);
  pinMode(irRight, INPUT);

}

void loop() {
  int leftValue = digitalRead(irLeft);
  int rightValue = digitalRead(irRight);
  Serial.println("left:"+String(leftValue));
  Serial.println("right:" +String(rightValue));
  delay(500);

}
