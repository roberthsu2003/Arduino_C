const int nums = 5;
int scores[nums];
int sum=0;
double ave=0;

void setup() {
  Serial.begin(9600);
  for(int i=0; i<nums; i++){
    Serial.print("請輸入第" + (String)(i+1) + "位學生的成績:");
    while(true){
      if(Serial.available()){
        scores[i] = Serial.parseInt();
        Serial.println(scores[i]);
        break;
      }
    }
  }

  for(int i=0; i<nums; i++){
    sum += scores[i];
  }

  ave = (double)sum / nums;
  Serial.println("全班總成績為:" + (String)sum + "分,平均為" + (String)ave + "分");
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
