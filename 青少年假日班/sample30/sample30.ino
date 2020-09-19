
// Name        : score1.ino
//建立一個包含五個元素的整數陣列，讓使用者輸入五位學生的成績，然後計算班級總成績及平均成績

/*============================================================
請輸入第1位學的成績78
請輸入第2位學的成績89
請輸入第3位學的成績67
請輸入第4位學的成績90
請輸入第5位學的成績89
全班總成績為:413分,平均為82.6分
============================================================
*/
const int nums = 5;
int scores[nums];

void setup() {
  Serial.begin(9600);
  for(int i=0;i<nums; i++){
    Serial.print("請輸入第" + String(i+1) + "位學生的成績:");
    while(true){
      if(Serial.available()){
        scores[i] = Serial.parseInt();
        Serial.println(scores[i]);
        break;
      }
    }    
  }

  for(int i=0; i<nums; i++){
    Serial.println("scores[" + String(i) + "]=" + String(scores[i]) );
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
