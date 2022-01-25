#define R 3
#define G 5
#define B 6

String stringBuffer;

void setup() {
  Serial.begin(9600);

}

void loop() {
  if(Serial.available() > 0){
    stringBuffer = Serial.readString();    
    int stringLength = stringBuffer.length();
    String rString = ""; 
    int rgbArray[3];
    int j = 0;
     
    for(int i=0; i<stringLength; i++){
      
      if(stringBuffer[i] != ',' ){ 
        rString += stringBuffer[i];       
      }else{
        rgbArray[j] = rString.toInt();
        j++;
        rString = "";
      }

      if(i == stringLength-1){
        rgbArray[j] = rString.toInt();
        j++;
         rString = "";
      } 
      
      
    }

    Serial.println(rgbArray[0]);
    Serial.println(rgbArray[1]);
    Serial.println(rgbArray[2]);
    
  }

}
