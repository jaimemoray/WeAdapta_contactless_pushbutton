
// ESP32 WROOM Dev

/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.13 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.15.01 or later version;
     - for iOS 1.12.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// you can enable debug logging to Serial at 115200
//#define REMOTEXY__DEBUGLOG    

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP32CORE_BLE

#include <BLEDevice.h>

// RemoteXY connection settings 
#define REMOTEXY_BLUETOOTH_NAME "RemoteXY"


#include <RemoteXY.h>

// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 32 bytes
  { 255,0,0,1,0,25,0,19,0,0,0,108,101,100,0,31,1,106,200,1,
  1,1,0,70,41,48,18,18,16,26,37,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // output variables
  uint8_t led; // from 0 to 1

    // other variable
  uint8_t connect_flag = 0;  // =1 if wire connected, else =0

} RemoteXY;   
#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#include <driver/touch_pad.h>

const int touchPin=4;
const int calibratedPin=22;

void setup() {
  RemoteXY_Init (); 
// put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(calibratedPin,INPUT);  

}

void loop() {
  RemoteXY_Handler ();
  Serial.println(touchRead(touchPin));
  Serial.println("Init");

  if(digitalRead(calibratedPin)==LOW){
    Serial.println("Save Value");
    delay(200);
  }
  delay(1000);

}
