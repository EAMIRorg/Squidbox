#pragma once

#include "components/midi-controller/MidiController.h"
#include <BLEMidi.h>

/**
 * @class BLEMidiController
 * @brief Represents a Bluetooth Low Energy (BLE) MIDI controller.
 */
class BLEMidiController : public MidiController {
private:
  const char *deviceName; ///< The name of the BLE device.

public:
  /**
   * @brief Constructs a new BLEMidiController object.
   * @param deviceName The name of the BLE device.
   */
  BLEMidiController(const char *deviceName);
  const char *getName() override;
  bool isConnected() override;
  void begin() override;
  void sendNoteOn(uint8_t note, uint8_t velocity, uint8_t channel) override;
  void sendNoteOff(uint8_t note, uint8_t velocity, uint8_t channel) override;
  ~BLEMidiController() override;
};