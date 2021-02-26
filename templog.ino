#include "Arduino.h"
#include "heltec.h"
#include "display.hpp"
#include "utils.hpp"
#include "wifi.hpp"
#include "ntp.hpp"
#include "dht.hpp"
#include "AsyncTCP.h"
#include "ESPAsyncWebServer.h"

//Instantiate a new web server on port 80
AsyncWebServer server(80);

void setup() {
  //Setup display
  SetupDisplay();

  //Initialize temperature sensor
  initTemp();

  //Connect to wifi network
  ConnectToWiFi();

  //Setup filesystem
  SetupFilesystem();

  //Setup NTP Client
  SetupNtp();

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/tlog.txt", "text/plain");
  });

  // Signal end of setup() to tasks and begin server process
  server.begin();
  tasksEnabled = true;
}

void loop() {
  if (!tasksEnabled) {
    DisplayString("DHT TempLog");
    // Wait 2 seconds to let system settle down
    delay(2000);
    // Enable task that will read values from the DHT sensor
    tasksEnabled = true;
    if (tempTaskHandle != NULL) {
			vTaskResume(tempTaskHandle);
		}
  }
  yield();
}