#include "WiFi.h"
#include "SPIFFS.h"

String IpToString(const IPAddress &ipAddress)
{
  return String(ipAddress[0]) + String(".") +
         String(ipAddress[1]) + String(".") +
         String(ipAddress[2]) + String(".") +
         String(ipAddress[3]);
}

//This function sets up the SPIFFS filesystem for storage of temperature and humidity data
void SetupFilesystem()
{
  if (!SPIFFS.begin(true))
  {
    DisplayString("ERROR: Can't mount SPIFFS!");
    return;
  }

}
