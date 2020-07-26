
void setup() {
  Serial.begin(9600);
  int ary[] = {212, 328, 765, 986};
  int count = sizeof(ary) / sizeof(ary[0]);
  Serial.println("呼叫showArray");
  showArray(ary, count);
  sub2(ary, count);
  showArray(ary, count);
}

void showArray(int tempary[], int count){
  for(int i=0; i<count; i++){
    Serial.print("ary[" + (String)i + "]=" + (String)tempary[i] + "\t");
  }

  Serial.print("\n\n");
}

void sub2(int tempary[], int count){
  for(int i=0; i<count; i++){
    tempary[i] *= 2;
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
