/**
 *
 *****************************************************************
 * IOT Challenges - https://instagram.com/iotchallenges          *
 *****************************************************************
 * Evandro Fruhauf                                               *
 *  GitHub - https://github.com/evandrodp                        *
 *  LinkedIn - http://linkedin.com/in/evandrofruhauf             *
 *****************************************************************
 * This code can contain parts from other open-sources projects, *
 * whenever possible it will be quoted.                          *
 *****************************************************************
 *
 * Relay
 *
 * Challenge: Be able to turn on/off the relay using the Touch sensor
 *
 * Code base: https://programmingelectronics.com/tutorial-19-debouncing-a-button-with-arduino-old-version/
**/
#include <Arduino.h>

// Set TouchSensor pin
#define TOUCH 2
// Set RELAY pin
#define RELAY 8

int relayState = LOW;
int touchState = LOW;
long lastDebounceTime = 0;
long debounceDelay = 1000;

void setup()
{
  // initialise serial debugger
  Serial.begin(9600);
  // initialise TOUCH digital pin as an input.
  pinMode(TOUCH, INPUT_PULLUP);
  // initialise RELAY digital pin as an output.
  pinMode(RELAY, OUTPUT);
}

void loop()
{
  //sample the state of the touch - is it pressed or not?
  touchState = digitalRead(TOUCH);

  //filter out any noise by setting a time buffer
  if ( (millis() - lastDebounceTime) > debounceDelay) {
    //if the button has been pressed, lets toggle the RELAY from "off to on" or "on to off"
    if ( (touchState == HIGH) && (relayState == LOW) ) {
      Serial.println("OFF TO ON");
      digitalWrite(RELAY, HIGH); //turn RELAY on
      relayState = HIGH; //now the RELAY is on, we need to change the state
      lastDebounceTime = millis(); //set the current time
    }
    else if ( (touchState == HIGH) && (relayState == HIGH) ) {
      Serial.println("ON TO OFF");
      digitalWrite(RELAY, LOW); //turn RELAY off
      relayState = LOW; //now the RELAY is off, we need to change the state
      lastDebounceTime = millis(); //set the current time
    }

  }
}