float PI1=3.14159;
int radius = 345;
//int area;
float area;

void setup() {
Serial.begin(9600);
Serial.print("area=");
area = PI1 * radius * radius;
Serial.println(area);

Serial.println(3/5.0);
//強制轉換
Serial.println((float)3/5);

}

void loop() {
  // put your main code here, to run repeatedly:

}
