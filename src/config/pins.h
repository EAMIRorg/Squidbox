#pragma once

#ifdef ARDUINO_ADAFRUIT_FEATHER_ESP32_V2

#define PIN_JOYSTICK_X 25 // A1
#define PIN_JOYSTICK_Y 34 // A2
#define PIN_JOYSTICK_BUTTON -1
#define PIN_KNOB_A 5 // SCK
#define PIN_KNOB_B 4 // A5
#define PIN_KNOB_BUTTON -1
#define PIN_BACK_BUTTON 26 // A0
#define PIN_OK_BUTTON 13   // 13
#define PIN_BUTTON_0 21    // MI
#define PIN_BUTTON_1 19    // MO
#define PIN_BUTTON_2 12    // 12
#define PIN_BUTTON_3 27    // 27
#define PIN_BUTTON_4 33    // 33
#define PIN_BUTTON_5 15    // 15
#define PIN_BUTTON_6 32    // 32
#define PIN_BUTTON_7 14    // 14

#endif // ARDUINO_ADAFRUIT_FEATHER_ESP32_V2

// Remapping pins to match simulated hardware
#ifdef ARDUINO_ESP32_DEV

// Use pin 2 since the ESP32 dev board does not have a built-in LED
#define LED_BUILTIN 2
#define PIN_JOYSTICK_X 39 // VN, ADC1_3
#define PIN_JOYSTICK_Y 34 // D34, ADC1_6
#define PIN_JOYSTICK_BUTTON -1
#define PIN_KNOB_A 32 // D32
#define PIN_KNOB_B 33 // D33
#define PIN_KNOB_BUTTON -1
#define PIN_BACK_BUTTON 36 // VP, ADC1_0
#define PIN_OK_BUTTON 35   // D35
#define PIN_BUTTON_0 18    // D18
#define PIN_BUTTON_1 19    // D19
#define PIN_BUTTON_2 25    // D25
#define PIN_BUTTON_3 26    // D26
#define PIN_BUTTON_4 27    // D27
#define PIN_BUTTON_5 14    // D14
#define PIN_BUTTON_6 12    // D12
#define PIN_BUTTON_7 13    // D13

#endif // ARDUINO_ESP32_DEV
