#include "BLEMidiController.h"

BLEMidiController::BLEMidiController(const char *deviceName)
    : deviceName(deviceName) {}

const char *BLEMidiController::getName() { return "BLE"; }

bool BLEMidiController::isConnected() { return BLEMidiServer.isConnected(); }

void BLEMidiController::begin() { BLEMidiServer.begin(deviceName); }

void BLEMidiController::sendNoteOn(uint8_t note, uint8_t velocity,
                                   uint8_t channel) {
  BLEMidiServer.noteOn(channel, note, velocity);
};

void BLEMidiController::sendNoteOff(uint8_t note, uint8_t velocity,
                                    uint8_t channel) {
  BLEMidiServer.noteOff(channel, note, velocity);
};

BLEMidiController::~BLEMidiController() { BLEMidiServer.end(); }
