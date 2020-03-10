#include <SPI.h>
#include <SD.h>
#include <stdio.h>
#include <Time.h> 
#define Sensor 2
Sd2Card card;
SdVolume volume;
SdFile root;

unsigned long timestamp;
const int chipSelect = 10;
const int butPin = 7;
bool butState;

void setup() 
{
  pinMode(butPin,INPUT_PULLUP);
  Serial.begin(9600);
  while (!Serial)
  {
    ;
  }

  Serial.print("Initializing SD card...");
 
  if (!SD.begin(chipSelect)) 
  {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
}

void loop() {

bool Detection = digitalRead(Sensor);

//Serial.println("Motion detected :");
//Serial.println(Detection);
delay(10);
if(Detection == HIGH){
Serial.println("Motion detected !!");
timestamp = millis();
//myFile.println(timestamp, "detected");
//myFile.close();
File dataFile = SD.open("datalog.txt", FILE_WRITE);
   if (dataFile)
   {
    dataFile.println(timestamp);
    dataFile.close();
    Serial.println(timestamp);
   }
   else 
   {
    Serial.println("error opening datalog.txt");
   }
  }
delay(5000); 
}
// if(Detection == LOW)
// Serial.println();
