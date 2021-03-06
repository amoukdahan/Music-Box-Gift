/*
*Music Box with mini LCD screen, using Arduino Nano and DFPlayer Mini Module
*This project is for my girlfriend's early birthday with her favorite songs
*/
#include <DFRobotDFPlayerMini.h>
#include "Arduino.h"
#include <SoftwareSerial.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)

#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

SoftwareSerial mySoftwareSerial(2,3); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

long int songs;

void setup() {
  mySoftwareSerial.begin(9600);
  Serial.begin(9600);
  randomSeed(analogRead(0));
  songs = (1,42);
  
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));
  myDFPlayer.setTimeOut(500); //Set serial communictaion time out 500ms
  myDFPlayer.volume(10); 
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
  
   if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();
  
     display.setTextSize(2); // Draw 2X-scale text
     display.setTextColor(SSD1306_WHITE);
     display.setCursor(0,2);
     display.print("I LOVE YOU  ASHLEY");

     display.display();      // Show initial text
     delay(4000);
 
     display.clearDisplay();
}

void loop() {
 
    
   
     myDFPlayer.play(random(songs));
     
     display.setTextSize(2); // Draw 2X-scale text
     display.setTextColor(SSD1306_WHITE); 
     display.setCursor(0,1);
     display.println(F("ANIKA +      ASHLEY"));
     display.display();      // Show initial text
     
     display.startscrollleft(0x00, 0x0F);
     delay(800000);
     
    
     
    
  
    
int A;
 do {A == 0;} while (A = 1);  //Infinite wait; only plays once per lid lift
}
