/*========================================================

  num1=20,num2=4
  請輸入要執行的運算(+ - * /):+
  num1+num2=24

========================================================*/


// Name        : calculate.ino
//讓使用者輸入加、減、乘、除運算子, 就會顯示運算結果

byte num1 = 20;
byte num2 = 4; 

void setup() {
  Serial.begin(9600);
  Serial.println("num1=20, num2=4");
  Serial.println("請輸入要執行的運算(+, -, *, /):");
}

void loop() {
  // put your main code here, to run repeatedly:

}
