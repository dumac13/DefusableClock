/*
* 
* Arduino 7 Segment Display Clock: With and Without RTC
* Clock code only
*/

#include "SevSeg.h"
#include <DS3231.h>
#include <EEPROM.h>
#include <Wire.h>

DS3231  rtc(SDA, SCL);                        //Inicia objeto rtc SDA->A4 / SCL->A5
Time  t;                                      //
SevSeg Display;                               //Inicia objeto Display

unsigned int number = 0;                      //Valor a mostrar
const long interval = 500;                    //Variable para segundero
unsigned long startMillis;
unsigned long currentMillis;
unsigned long previousMillis = 0;
unsigned int Hour = 0;
unsigned int hrs_var = 0;
unsigned int min_var = 0;


void setup(){

  rtc.begin();                                //Inicia objeto RTC    

  byte numDigits = 4;                         //Numero de digitos a utilizar
  byte digitPins[] = {9,10,11,12};            // Pines anodo/digitos
//  byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8}; //Pines segmentos -> UNO
  byte segmentPins[] = {4, 2, 6, 7, 8, 3, 5,13}; //Pines segmentos -> Pro Mini
  bool resistorsOnSegments = false;  
  bool updateWithDelays = true;
  byte hardwareConfig = COMMON_CATHODE;
  bool leadingZeros = true;
  bool disableDecPoint = false;
  Display.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros, disableDecPoint);
  Display.setBrightness(0);                   //Brillo inicial

  Serial.begin(9600);
  Serial.println(__FILE__);
  Serial.println("V.01");

/////////////////////////////////////////////////////////////////

// Uncomment on first run
// Define values for actual time or date or both
//  rtc.setTime(12, 0, 0);     // Set the time to 12:00:00 (24hr format) Hrs, Min, Seg
//  rtc.setDate(1, 1, 2022);   // Set the date to January 1st, 2022
//comment after first run
}

void loop() {


  
////////////////////////////////////////////////
  t = rtc.getTime();

  number = t.hour * 100 + t.min;
  Display.setNumber(number, 2);
  Display.refreshDisplay();


} // End Loop

