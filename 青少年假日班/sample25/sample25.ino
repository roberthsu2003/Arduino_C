//建立一個包含五個元素的整數陣列，讓使用者輸入五位學生的成績，然後計算班級總成績及平均成績
//============================================================

const int nums = 5;
int scores[nums];
int sum = 0;
double ave;

void setup() {
  Serial.begin(9600);
  for(int i=0; i<nums; i++){    
    Serial.print("請入第"+String(i+1)+"位學生的成績:");
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
    Serial.print("全班總成績為:");
    Serial.print(sum);
    Serial.print("分,平均為");
    Serial.print(ave);
    Serial.println("分");

}

void loop() {
  // put your main code here, to run repeatedly:

}
