#pragma once

#include "components/midi-controller/MidiController.h"

/**
 * @class SimulatedMidiController
 * @brief Represents a simulated MIDI controller.
 * @details This class is used for the simulation of Squidbox during development
 * and does not actually send MIDI messages.
 */
class SimulatedMidiController : public MidiController {
public:
  SimulatedMidiController();
  const char *getName() override;
  bool isConnected() override;
  void begin() override;
  void sendNoteOn(uint8_t note, uint8_t velocity, uint8_t channel) override;
  void sendNoteOff(uint8_t note, uint8_t velocity, uint8_t channel) override;
  ~SimulatedMidiController() override;
};