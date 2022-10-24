/*
* 
* Arduino 7 Segment Display Clock: With and Without RTC
* Clock code only
*/
#include "SevSeg.h"
#include <DS3231.h>
#include <EEPROM.h>
#include <Wire.h>

DS3231  rtc(SDA, SCL);                          //  Create object rtc SDA->A4 / SCL->A5 /DS3231 Lib
Time  t;                                        // 
SevSeg Display;                                 //  Create objet Display /SevSeg Lib

unsigned int number = 0;                        //  Time variable to show 

void setup(){

  rtc.begin();                                  //  Inicialize objet RTC    

  byte numDigits = 4;                           //  Digits to use
  byte digitPins[] = {9,10,11,12};              //  Pin digits  as array  [] = {Digit1, Digit2, Digit3, Digit4}
//  byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8}; //  Pins segments -> UNO as array [] = {A, B, C, D, E, F, G, dp}
  byte segmentPins[] = {4, 2, 6, 7, 8, 3, 5,13}; // Pins segments -> Pro Mini
  bool resistorsOnSegments = false;              // If Led resistances are on segments pins -> true / If Led resistances are on digit pins -> false
  bool updateWithDelays = false;                   
  byte hardwareConfig = COMMON_CATHODE;          // COMMON_CATHODE or COMMON_ANODE 
  bool leadingZeros = true;                      // Show leading zeros on hors -> true (example: 09:30) / No show -> false (Example 9:30)
  bool disableDecPoint = false;                  // Use Decimal Point segment
  Display.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros, disableDecPoint);
  Display.setBrightness(0);                      // Set brightness Min. 0 Max 100

  Serial.begin(9600);
  Serial.println(__FILE__);                      // Print file name & file path on serial monitor
  Serial.println("V.01");
  Serial.println(rtc.getTimeStr());              // Pinr time stored (actual) on DS3231 RTC
  Serial.println(rtc.getDateStr());              // Print date stored on DS3231  RTC 
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

