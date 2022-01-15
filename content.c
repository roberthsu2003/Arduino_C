int num=0;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  Serial.println("請輸入13pinLed,閃爍的次數:");  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
      num=Serial.parseInt();
      Serial.print("目前將閃爍");
      Serial.print(num);
      Serial.println("次");      
    }
  blink13(&num);
}

void blink13(int *n){
  for(; *n > 0;*n-=1){
    Serial.println(*n);
    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);
  }
  
}
