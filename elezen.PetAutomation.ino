/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************
 * This example runs directly on ESP8266 chip.
 *
 * You need to install this for ESP8266 development:
 *   https://github.com/esp8266/Arduino
 *
 * Please be sure to select the right ESP8266 module
 * in the Tools -> Board menu!
 *
 * Change WiFi ssid, pass, and Blynk auth token to run :)
 *
 **************************************************************/

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <Servo.h>


// define ports
#define LED_PORT 4

//servo controller
Servo feedServo;  // create servo object to control a servo

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "671529a44d384cd7acffab66f5c94f73";

SimpleTimer Interrupt;

void InterruptFunction()
{ 
  //initial setup state
  int Hydrate = digitalRead(4);
  int Feed = digitalRead(5);
  Serial.print ("Hydrate: ");
  Serial.println (Hydrate);
  Serial.print ("Feed: ");
  Serial.println (Feed);

  if (digitalRead(5) == 0) {
    feedServo.write(5);
  } else {
    feedServo.write(110);   
  }
 

}


BLYNK_WRITE(V0)
{

/*
  if (digitalRead(5) == 0) {
    feedServo.write(0);
  } else {
    feedServo.write(180);   
  }
*/

}



void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, "aunehzatar", "letmein123");
  Interrupt.setInterval(250, InterruptFunction);
  feedServo.attach(12);  // attaches the servo on pin 12 to the servo object
}

void loop()
{
  Blynk.run();
  Interrupt.run();
}

