// 引用 LiquidCrystal Library
#include <LiquidCrystal.h>

// 建立 LiquidCrystal 的變數 lcd
//                 LCD 接腳:  rs, enable, d4, d5, d6, d7  
//      對應到 Arduino 接腳:  12,     11,  5,  4,  3,  2
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
String MAX = "";
String comdata="";
void setup() {
  int loop_x = 1;
   Serial.begin(9600);
  // 設定 LCD 的行列數目 (2 x 16)
  lcd.begin(16, 2);
  Serial.println("Define the Maximum value of Potentiometer :");
  MAX = Maximum_Set_up(loop_x , comdata); //執行副程式，設定可變電阻最大值
  lcd.print("Potentiometer");
}
void loop() {
  long M2R =MAX.toInt();
  float sensorValue = analogRead(A0); //取得可變電阻(0~1023)
  float Display_ohm;
  long Resistance = M2R;
  lcd.setCursor(0, 1);
  Display_ohm = Get_ohm(sensorValue,Resistance);//執行副程式，獲得電阻值
  lcd.print(Display_ohm);
  lcd.print("ohm");
  delay(100);
}

  String Maximum_Set_up(int z ,String Data){
  while(z == 1){ //Enable infinite loop 
  if (Serial.available() > 0){
        Data += char(Serial.read()); 
        delay(2);
   }
    else if (Data.length() > 0){//若有文字輸入
        Serial.println(Data);
        return Data;//回傳Data植
        Data = "";//Clear Data
        z--;//Disable infinite loop
   }
  }
}
   float Get_ohm(float x,float y){
   float voltage,Ohm;
   voltage = x / 1023.0 *5.0;
   Ohm = y / (5/voltage) ;//利用比值求出電阻值
   return Ohm;
}
  
