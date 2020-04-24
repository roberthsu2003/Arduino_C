# 亂數和時間操控
```
#arduinoC 控制按鈕
#include <MatrixMini.h>

MatrixMini Mini;

void setup() {
  Mini.begin(); 
  Serial.begin(9600);

  Serial.println("\n Matrix Mini Button Test \n");
}

void loop() {
  Serial.print("  Button 1: "); Serial.print(Mini.BTN1.get());
  Serial.print("\tButton 2: "); Serial.print(Mini.BTN2.get());
  Serial.println();
  delay(50);
}
```



```c
#arduino C
#使用randomSeed()
#使用random()

long randNumber;

void setup() {
  Serial.begin(9600);

  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(0));
}

void loop() {
  // print a random number from 0 to 299
  randNumber = random(300);
  Serial.println(randNumber);

  // print a random number from 10 to 19
  randNumber = random(10, 20);
  Serial.println(randNumber);

  delay(1000);
}
```
