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
  if(Serial.available()){
    char op = Serial.read();
    switch(op){
      case '+':
        Serial.print("num1+num2=");
        Serial.println(num1+num2);
        break;

      case '-':
        Serial.print("num1-num2=");
        Serial.println(num1-num2);
        break;

      case '*':
        Serial.print("num1*num2=");
        Serial.println(num1*num2);
        break;
        
      case '/':
        Serial.print("num1/num2=");
        Serial.println(num1/num2);
        break;
        
      default:
        Serial.println("您輸入的運算字元不合法");
    }
  }

}
