int nums = 100;
void setup() {
  Serial.begin(9600);
  int array[nums];
  
  for(int i=0; i<nums; i++){
    array[i] = random(10,51);
  }

  for(int i=0; i<nums; i++){
    Serial.println(array[i]);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
