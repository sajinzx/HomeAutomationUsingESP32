/*************************************************************
  Blynk is a platform with iOS and Android apps to control
  ESP32, Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build mobile and web interfaces for any
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: https://www.blynk.io
    Sketch generator:           https://examples.blynk.cc
    Blynk community:            https://community.blynk.cc
    Follow us:                  https://www.fb.com/blynkapp
                                https://twitter.com/blynk_app

  Blynk library is licensed under MIT license
 *************************************************************
  Blynk.Edgent implements:
  - Blynk.Inject - Dynamic WiFi credentials provisioning
  - Blynk.Air    - Over The Air firmware updates
  - Device state indication using a physical LED
  - Credentials reset using a physical Button
 *************************************************************/

/* Fill in information from your Blynk Template here */
/* Read more: https://bit.ly/BlynkInject */
#define BLYNK_TEMPLATE_ID "TMPL3zuGf9oHi"
#define BLYNK_TEMPLATE_NAME "Home Automation"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_ESP32_DEV_MODULE
//#define USE_ESP32C3_DEV_MODULE
//#define USE_ESP32S2_DEV_KIT
//#define USE_WROVER_BOARD
//#define USE_TTGO_T7
//#define USE_TTGO_T_OI

#include "BlynkEdgent.h"

void setup()
{
  Serial.begin(115200);
  delay(100);
  BlynkEdgent.begin();
  pinMode(15, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

BLYNK_WRITE(V0){
  int s1 = param.asInt();
  if(s1 == 1){
    digitalWrite(15, HIGH);
  }
  else{
    digitalWrite(15, LOW);
  }
}

BLYNK_WRITE(V1){
  int s1 = param.asInt();
  if(s1 == 1){
    digitalWrite(2, HIGH);
  }
  else{
    digitalWrite(2, LOW);
  }
}

BLYNK_WRITE(V2){
  int s1 = param.asInt();
  if(s1 == 1){
    digitalWrite(4, HIGH);
  }
  else{
    digitalWrite(4, LOW);
  }
}

BLYNK_WRITE(V3){
  int s1 = param.asInt();
  if(s1 == 1){
    digitalWrite(5, HIGH);
  }
  else{
    digitalWrite(5, LOW);
  }
}

void loop() {
  BlynkEdgent.run();
}

