# Arduino 自駕車導航系統設計

```
1 ( A )在Arduino的程式中，若想加入註解，應以何符號標示?

(A) /*...*/
(B) \\
(C) "
(D) '
```

```
2 ( A )在C語言中，若變數宣告int x=27; int y=5; 試問 x % y的運算結果為何?

(A) 2
(B) 3
(C) 4
(D) 5
```

```
3 ( B )執行下列程式後，變數k = ? 

		int k=0;
		for(byte a=5; a<=10; a++)
			k+=a;

(A) 55
(B) 45
(C) 40
(D) 35		
```

```
4 ( D )下列關於Arduino的Serial.print()方法特殊字元說明，何者錯誤?

(A) \t 代表跳位鍵字元
(B) \n 代表換行字元
(C) \r 代表歸位字元
(D) \c 代表清除字元
```

```
5 ( C )digitalWrite(3, LOW)指令的作用是指定Arduino進行何動作?

(A) 第3腳輸出 0V
(B) 第3腳輸出 5V
(C) D3腳輸出 0V
(D) D3腳輸出 5V
```

```
6 ( B )Arduino 程式中digitalWrite(7, HIGH)指令的作用為何?

(A) 指定輸出的高準位為7V
(B) 指定D7腳輸出高準位
(C) 指定第7腳輸出高準位
(D) 指定輸出高準位並持續7毫秒(ms)
```

```
7 ( C ) Arduino程式中analogWrite(10, 64)指令會在指定的I/O腳輸出多少工作週期的PWM

(A) 4%
(B) 10%
(C) 25%
(D) 50%
```

```
8 ( A ) Arduino UNO 控制板中，下列那一個pin腳無法輸出PWM?

(A) 4
(B) 5
(C) 9
(D) 10
```

```
9 ( B ) 若想指定Arduino的D3腳輸出控制一顆馬達，應使用哪一個指定設定 I/O 腳的電氣模式?

(A) pinMode(3, INPUT)
(B) pinMode(3, OUTPUT)
(C) setMode(3, INPUT)
(D) setMode(3, OUTPUT)
```

```
10 ( D ) delay(200)指令的意義為何? 

(A) 產生200V電壓
(B) 時間延遲200秒
(C) 時間延遲200微秒
(D) 時間延遲200毫秒
```

```
11 ( A ) Arduon I/O 板 Reset後，會先執行哪一個函式?

(A) setup()
(B) loop()
(C) main()
(D) startup()
```

```
12 ( D ) Arduino 的數位 I/O 腳無法使用在哪個應用?

(A) LED 亮滅控制
(B) 脈波寬度量測
(C) 馬達速度控制
(D) 亮度測量
```

```
13 ( C ) 執行下列 Arduino 的C程式後，試問會在指定pin腳上輸出多少工作週期的脈波?

	void loop(){
		digitalWrite(10,HIGH);
		delay(75);
		digitalWrite(10,LOW);
		delay(25);
	}
	
(A) 40%
(B) 60%
(C) 75%
(D) 80%
```

```
14 ( A ) 同上題，試問在指定pin腳可測量到的輸出脈波頻率為多少?

(A) 10Hz
(B) 25Hz
(C) 75Hz
(D) 10kHz
```

```
15 ( C )if ... else ... 指令功能為何?

(A) 輸入輸出控制
(B) 迴圈控制
(C) 條件判斷
(D) 算術運算處理
```