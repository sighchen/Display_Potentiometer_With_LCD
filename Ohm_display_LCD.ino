/* Lab9 - 在 2x16 LCD 上顯示 "Hello World" 訊息  
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * 10K Potentiometer:
 * ends to +5V and ground
 * wiper to LCD Vo pin (pin 3)
 
 This example code is in the public domain.
 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// 引用 LiquidCrystal Library
#include <LiquidCrystal.h>

// 建立 LiquidCrystal 的變數 lcd
//                 LCD 接腳:  rs, enable, d4, d5, d6, d7  
//      對應到 Arduino 接腳:  12,     11,  5,  4,  3,  2
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
String real = "";
//char* comdata = "0";
String comdata="";
void setup() {
  int loop_x = 1;
   Serial.begin(9600);
  // 設定 LCD 的行列數目 (2 x 16)
  lcd.begin(16, 2);
  Serial.println("Define the Maximum value of Potentiometer :");
  real = Maximum_Set_up(loop_x , comdata); 
  lcd.print("Potentiometer");
}
void loop() {
  /*int GG = 0;
  // 將游標設到 column 0, line 1
  // (注意: line 1 是第二行(row)，因為是從 0 開始數起):
  char* test_real[real.length()];
  real.toCharArray(test_real,real.length());*/
  long GG =real.toInt();
  Serial.print(GG);
  float sensorValue = analogRead(A0);
  float Display_ohm;
  long Resistance = GG;
  lcd.setCursor(0, 1);
  Display_ohm = Get_ohm(sensorValue,Resistance);
  lcd.print(Display_ohm);
  lcd.print("ohm");
  delay(100);
}

  String Maximum_Set_up(int z ,String Data){
  while(z == 1){ 
  if (Serial.available() > 0){
        Data += char(Serial.read());
        delay(2);
   }
    else if (Data.length() > 0){
        Serial.println(Data);
        return Data;
        Data = "";
        z--;
   }
  }
}
   float Get_ohm(float x,float y){
   float voltage,Ohm;
   voltage = x / 1023.0 *5.0;
   Ohm = y / (5/voltage) ;
   return Ohm;
}
  
