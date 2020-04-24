# MR200操控台控制台
![arduino編輯器安裝說明文件](ArduinoInstallation.pdf) 
 
![MINI控制器外觀說明](Matrix_Mini.pdf) 

![MINI控制器腳位定義文件](Mini_Pin_Definition.pdf) 

![MINI Car 安裝說明文件](Mini_Car_Assembly.pdf)

![超音波_紅外線安裝說明文件](Sensor_Servo_Assembly.pdf)


[![MR200-MINI-小車-組裝影片](../MR200.jgp)](https://www.youtube.com/playlist?list=PLLVBR5MLJ8AW4XOThhsSQz_84RyxFMdV0)
### 按鈕測試

```c
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

### RGBLED測試

```c
#include <MatrixMini.h>

MatrixMini Mini;

void setup() {
  Mini.begin(); 
  Serial.begin(9600);

  Serial.println("\n Matrix Mini Button LED Test \n");
}

void loop() {
  if(Mini.BTN1.get()) 
    Mini.LED1.setRGB(255,0, 0);
  else
    Mini.LED1.setRGB(0,0, 0);


  if(Mini.BTN2.get()) 
    Mini.LED2.setRGB(0,255, 0);
  else
    Mini.LED2.setRGB(0,0, 0);
  
  delay(50);
}
```


