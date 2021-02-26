#include <WiFi.h>
#include <time.h>
#include <WiFiUdp.h>

// Replace with your network credentials
const char *ssid = "REPLACE_WITH_YOUR_SSID";
const char *password = "REPLACE_WITH_YOUR_PASSWORD";

void SetupNtp() {
    const char* ntpServer = "pool.ntp.org";
    const long  gmtOffset_sec = 3600;
    const int   daylightOffset_sec = 3600;
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

String getTimestamp()
{
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return "ERR";
  }
  char timeStringBuff[50]; //50 chars should be enough
  strftime(timeStringBuff, sizeof(timeStringBuff), "%Y %b %d %H:%M:%S", &timeinfo);
  
  return timeStringBuff;
}