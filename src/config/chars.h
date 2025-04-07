#pragma once

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h> // or your specific display library

const unsigned char CHECKMARK_BITMAP[] PROGMEM = {
  0b00000000,
  0b00000001,
  0b00000010,
  0b00000100,
  0b10001000,
  0b01010000,
  0b00100000,
  0b00000000
};

const unsigned char X_BITMAP[] PROGMEM = {
    0b10000001,
    0b01000010,
    0b00100100,
    0b00011000,
    0b00011000,
    0b00100100,
    0b01000010,
    0b10000001
};