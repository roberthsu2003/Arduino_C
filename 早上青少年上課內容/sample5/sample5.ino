int area;
int radius;
//float PI = 3.14159;

void setup() {
  Serial.begin(9600);
  Serial.println("請輸入半徑:");
  //等待使用者輸入半徑
  while(true){
    if(Serial.available()){
      radius = Serial.parseInt();
      break;
    }
  }
  
  area = PI * radius * radius;
  Serial.print("圓面積=");
  Serial.println(area);

}

void loop() {
  // put your main code here, to run repeatedly:

}
