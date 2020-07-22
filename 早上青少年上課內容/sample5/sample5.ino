int area;
int radius = 10;
float PI = 3.14159;

void setup() {
  Serial.begin(9600);
  area = PI * radius * radius;
  Serial.print("圓面積=");
  Serial.println(area);

}

void loop() {
  // put your main code here, to run repeatedly:

}
