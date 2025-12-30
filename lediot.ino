#define BLYNK_AUTH_TOKEN "your auth token"
#define BLYNK_TEMPLATE_ID "your template id"
#define BLYNK_TEMPLATE_NAME "Quickstart Device"

#define BLYNK_PRINT Serial



#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include <WiFiGeneric.h>
#include <WiFiMulti.h>
#include <WiFiSTA.h>
#include <WiFiScan.h>
#include <WiFiServer.h>
#include <WiFiType.h>
#include <WiFiUdp.h>

#include <BlynkSimpleEsp32.h>

#define WiFi_SSID "your ssid"
#define WiFi_PASS "your pass"


const int lpin = 25;

BLYNK_WRITE(V0)
{
  int lstate = param.asInt();
  Serial.println(lstate);
  digitalWrite(lpin, lstate);
}
void setup() {
  // put your setup code here, to run once:
  pinMode(lpin, OUTPUT);
  WiFi.begin(WiFi_SSID, WiFi_PASS);
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, WiFi_SSID, WiFi_PASS);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
}
