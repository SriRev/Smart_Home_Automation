#ifdef ENABLE_DEBUG
  #define DEBUG_ESP_PORT Serial
  #define NODEBUG_WEBSOCKETS
  #define NDEBUG
#endif
#include <Arduino.h>
#ifdef ESP8266 
  #include <ESP8266WiFi.h>
#endif 
#ifdef ESP32   
       #include <WiFi.h>
#endif
#include <SinricPro.h>
#include <SinricProSwitch.h>
int D1 = 5;
int D2 = 4;
int D3 = 0;
#define RELAYPIN_1 D1
#define RELAYPIN_2 D2
struct RelayInfo {
  String deviceId;
  String name;
  int pin;
};
std::vector<RelayInfo> relays = {
    {"66b6285c54041e4ff61a1ff9", "Relay 1", RELAYPIN_1},
    {"66b62784deddece34b78e1be", "Relay 2", RELAYPIN_2}};
#define WIFI_SSID  "SriRev"
#define WIFI_PASS  "iclo4981"
#define APP_KEY    "7a6f514d-077d-4491-a892-860ce2c6cc24"
#define APP_SECRET "20cbc485-28e2-4b13-8383-29a3cb3f1b20-d08d09ee-5bf5-4ce6-a58b-19bfed390c66"
#define BAUD_RATE  9600
bool onPowerState(const String &deviceId, bool &state) {
  for (auto &relay : relays) {
    if (deviceId == relay.deviceId) {
      Serial.printf("Device %s turned %s\r\n", relay.name.c_str(), state ? "on" : "off");
      digitalWrite(relay.pin, !state);
      return true;
    }
  }
  return false;
}
void setupRelayPins() {
  for (auto &relay : relays) {
    pinMode(relay.pin, OUTPUT);
  }
}
void setupWiFi() {
  Serial.printf("\r\n[Wifi]: Connecting");
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.printf(".");
    delay(250);
  }
  Serial.printf("connected!\r\n[WiFi]: IP-Address is %s\r\n", WiFi.localIP().toString().c_str());
}
void setupSinricPro() {
  for (auto &relay : relays) {
    SinricProSwitch &mySwitch = SinricPro[relay.deviceId];
    mySwitch.onPowerState(onPowerState);
  }
  SinricPro.onConnected([]() { Serial.printf("Connected to SinricPro\r\n"); });
  SinricPro.onDisconnected([]() { Serial.printf("Disconnected from SinricPro\r\n"); });
  SinricPro.begin(APP_KEY, APP_SECRET);
}
void setup() {
  Serial.begin(BAUD_RATE);
  setupRelayPins();
  setupWiFi();
  setupSinricPro();
}
void loop() {
  SinricPro.handle();
}
