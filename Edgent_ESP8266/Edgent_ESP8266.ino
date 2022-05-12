#define BLYNK_TEMPLATE_ID "TMPLqYTsgAhK"
#define BLYNK_DEVICE_NAME "Codebots"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"
BLYNK_WRITE(V0){
  int pinvalue1 = param.asInt();
  digitalWrite(D0,pinvalue1);
}

BLYNK_WRITE(V1){
  int pinvalue2 = param.asInt();
  digitalWrite(D1,pinvalue2);
}

BLYNK_WRITE(V2){
  int pinvalue3 = param.asInt();
  digitalWrite(D2,pinvalue3);
}

void setup()
{
  Serial.begin(115200);
  delay(100);
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  BlynkEdgent.begin();
}
void loop() {
  BlynkEdgent.run();
}
