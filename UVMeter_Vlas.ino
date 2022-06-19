/*******************************************************
Project: UV Meter with OLED 128x64
Author: VlasElectronics
Based on: AlphaMods (youtube) -> http://www.educ8s.tv
*******************************************************/

#include <GyverOLED.h>

#define textScale 4
#define debug false

GyverOLED<SSD1306_128x64, OLED_BUFFER> oled;

extern unsigned char BigNumbers[];
extern uint8_t splash[];
extern uint8_t splash2[];
extern uint8_t splash3[];
extern uint8_t ui[];

String uv = "0"; 

void setup() {
  if(debug) Serial.begin(9600);
  
  oled.init();
  oled.clear();
  oled.update();  // needs for OLED_BUFFER mode
  Serial.println("oled init, clear, update: finished");

  // oled.home();            // курсор в 0,0
  oled.setScale(textScale);

  // Test
  /*oled.setCursorXY(52, 18); // курсор в (пиксель X, пиксель Y)
  // oled.invertText(true);    // инвертируй текст!
  oled.print("9");
  oled.update();
  delay(5000);

  oled.setCursorXY(36, 18); // курсор в (пиксель X, пиксель Y)
  // oled.invertText(true);    // инвертируй текст!
  oled.print("10");
  oled.update();
  delay(5000);

  oled.setCursorXY(28, 18); // курсор в (пиксель X, пиксель Y)
  // oled.invertText(true);    // инвертируй текст!
  oled.print("9.9");
  oled.update();
  delay(5000);*/

  // oled.setScale(2);
  // oled.clear();
  // oled.drawBitmap(0, 0, splash, 84, 48);
  // oled.update();  
  // delay(3000);

 
  // oled.setFont(BigNumbers);
  // oled.setScale(2);
  // oled.clear();
  // oled.drawBitmap(0, 0, splash2, 84, 48);
  // oled.update();  
  // delay(2000);

  // oled.init();
  // oled.setScale(2);
  // oled.clear();
  // oled.drawBitmap(0, 0, splash3, 84, 48);
  // oled.update();  
  // delay(3500);
}

void loop() {
 
  uv = readSensor();
  if(debug) Serial.println("uv: " + uv);

  int uvValueLength = uv.length();
  if(debug) Serial.println("uvValueLength: " + (String)uvValueLength);
  
  oled.clear();
  // oled.setCursor(20, 30);
  // oled.drawBitmap(0, 0, ui, 84, 48);
  printUV(uvValueLength);
  oled.update();
  delay(250);
}

void printUV(int length)
{
  switch(length)
  {
    case 1:  {
      oled.setCursorXY(52, 18); 
      oled.print(uv); 
      break;
    }
    case 2: { 
      oled.setCursorXY(36, 18); 
      oled.print(uv); 
      break;
    }
    default: { 
      oled.setCursorXY(28, 18); 
      oled.print(uv); 
      break;
    }
  }
}

String readSensor()
{
  String uvIndex = "0";
  int sensorValue = 0;
  
  sensorValue = analogRead(0);                        //connect UV sensor to Analog 0   
  int voltage = (sensorValue * (5.0 / 1023.0))*1000;  //Voltage in miliVolts
  
  if(voltage<50) {
      uvIndex = "0";
  } else if (voltage>50 && voltage<=100) {
      uvIndex = "0.5";
  } else if (voltage>100 && voltage<=227) {
      uvIndex = "1";
  } else if (voltage>227 && voltage<=260) {
    uvIndex = "1.5";
  } else if (voltage>260 && voltage<=318) {
      uvIndex = "2";
  } else if (voltage>318 && voltage<=360) {
      uvIndex = "2.5";
  } else if (voltage>360 && voltage<=408) {
      uvIndex = "3";
  } else if (voltage>408 && voltage<=450) {
      uvIndex = "3.5";
  } else if (voltage>450 && voltage<=503) {
      uvIndex = "4";
  } else if (voltage>503 && voltage<=550) {
      uvIndex = "4.5";
  } else if (voltage>550 && voltage<=606) {
      uvIndex = "5";
  } else if (voltage>606 && voltage<=650) {
      uvIndex = "5.5";
  } else if (voltage>650 && voltage<=696) {
      uvIndex = "6";
  } else if (voltage>696 && voltage<=700) {
      uvIndex = "6.5";
  } else if (voltage>700 && voltage<=796) {
      uvIndex = "7";
  } else if (voltage>796 && voltage<=830) {
      uvIndex = "7.5";
  } else if (voltage>830 && voltage<=881) {
      uvIndex = "8";
  } else if (voltage>881 && voltage<=925) {
      uvIndex = "8.5";
  } else if (voltage>925 && voltage<=976) {
      uvIndex = "9";
  } else if (voltage>976 && voltage<=1025) {
      uvIndex = "9.5";
  } else if (voltage>1025 && voltage<=1079) {
      uvIndex = "10";
  } else if (voltage>1079 && voltage<=1125) {
      uvIndex = "10.5";
  } else if (voltage>1125 && voltage<=1170) {
      uvIndex = "11";
  } else if (voltage>1170) {
      uvIndex = "11+";
  }
  return uvIndex;
}


