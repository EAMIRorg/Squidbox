#include "SimulatedMidiController.h"

SimulatedMidiController::SimulatedMidiController() {}

const char *SimulatedMidiController::getName() { return "SIM"; }

bool SimulatedMidiController::isConnected() { return true; }

void SimulatedMidiController::begin() {}

void SimulatedMidiController::sendNoteOn(uint8_t note, uint8_t velocity,
                                         uint8_t channel) {
  Serial.printf("Note On: %d, Velocity: %d, Channel: %d\n", note, velocity,
                channel);
};

void SimulatedMidiController::sendNoteOff(uint8_t note, uint8_t velocity,
                                          uint8_t channel) {
  Serial.printf("Note Off: %d, Velocity: %d, Channel: %d\n", note, velocity,
                channel);
};

SimulatedMidiController::~SimulatedMidiController() {}
