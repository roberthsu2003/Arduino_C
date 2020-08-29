unsigned short chinese =0, english=0, math=0;
void setup() {
  Serial.begin(9600);
  Serial.print("請輸入國文成績:(0-100):");
  while(true){
    if(Serial.available()){
      chinese = Serial.parseInt();
      Serial.println(chinese);
      break;
    }
  }

  Serial.print("請輸入英文成績:(0-100):");
  while(true){
    if(Serial.available()){
      english = Serial.parseInt();
      Serial.println(english);
      break;
    }
  }

  Serial.print("請輸入數學成績:(0-100):");
  while(true){
    if(Serial.available()){
      math = Serial.parseInt();
      Serial.println(math);
      break;
    }
  }

  int sum = chinese + english + math;
  float average = sum / 3.0;
  Serial.println("您的總分是:" + (String)sum);

  Serial.println("您的平均是:" + (String)average);

}

void loop() {
  // put your main code here, to run repeatedly:

}
