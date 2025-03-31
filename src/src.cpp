#include "Squidbox.h"

Squidbox *squidbox;

void setup() {
  // Start serial communication at a baud rate of 115200
  // This allows for debugging information to be sent over the serial port
  Serial.begin(115200);

  // Create a new instance of the Squidbox class
  // This represents the main application object
  squidbox = new Squidbox();

  // Initialize the Squidbox instance
  // This sets up the initial state of the application
  squidbox->init();
}

void loop() {
  // https://docs.wokwi.com/faq#the-simulation-is-slow-how-can-i-make-it-faster
#ifdef SIMULATION
  delay(10);
#endif
  // Continuously update the Squidbox instance
  // This function is called repeatedly by the Arduino framework and drives the
  // application
  squidbox->update();
}