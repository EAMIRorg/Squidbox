#pragma once

#include <Arduino.h>

/**
 * @class MidiController
 * @brief Represents a MIDI controller.
 * @details This class provides an interface for MIDI controllers. It defines
 * a common interface for how Squidbox can interact with different types of MIDI
 * controllers, such as BLE or USB MIDI controllers.
 */
class MidiController {
public:
  virtual const char *getName() = 0;
  virtual void begin() = 0;
  virtual bool isConnected() = 0;
  virtual void sendNoteOn(uint8_t note, uint8_t velocity, uint8_t channel) = 0;
  virtual void sendNoteOff(uint8_t note, uint8_t velocity, uint8_t channel) = 0;
  virtual ~MidiController() {}
};