#include "Arduino.h"
#include "heltec.h"

void SetupDisplay() {
      //Setup display and bring online
  Heltec.begin(true , false , true );
  Heltec.display->flipScreenVertically();
  Heltec.display->setFont(ArialMT_Plain_10);
}

void DisplayString(String str) {
    Heltec.display->clear();
    Heltec.display->drawStringMaxWidth(0, 0, 128,str);
    Heltec.display->display();
}

void DisplayTemp(String t, String h, String i, String d, String c) {
    Heltec.display->clear();
    Heltec.display->drawString(0,0,"Temp: ");
    Heltec.display->drawString(50,0, t);
    Heltec.display->drawString(0,10,"Humid: ");
    Heltec.display->drawString(50,10, h);
    Heltec.display->drawString(0,20,"Index: ");
    Heltec.display->drawString(50,20, i);
    Heltec.display->drawString(0,30,"Dew: ");
    Heltec.display->drawString(50,30, d);
    Heltec.display->drawString(0,40,"Comfort: ");
    Heltec.display->drawString(50,40, c);
    Heltec.display->display();
}