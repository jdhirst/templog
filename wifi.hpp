#include "WiFi.h"
#include "WiFiUdp.h"
#include "WifiConfig.hpp"
#include "heltec.h"

void ConnectToWiFi()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);
  Heltec.display->drawString(0,0,"Connecting...");
 
  uint8_t i = 0;
  while (WiFi.status() != WL_CONNECTED)
  {
    Heltec.display->drawString(0,0,".");
    delay(500);
 
    if ((++i % 16) == 0)
    {
      Heltec.display->clear();
      Heltec.display->drawStringMaxWidth(0, 0, 128," still trying to connect");
      Heltec.display->display();
    }
  }
  Heltec.display->clear();
  Heltec.display->drawStringMaxWidth(0, 0, 128, "Connected. My IP address is: ");
  Heltec.display->drawStringMaxWidth(0, 20, 128, IpToString(WiFi.localIP()));
  Heltec.display->display();
}