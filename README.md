# Squidbox

The EAMIR Squidbox is a low-cost Bluetooth MIDI controller. It provides an intuitive and interactive way to learn about scales and chords while having fun making music. It runs on an ESP32 and features a 2-axis joystick, a small OLED screen, a knob, and multiple buttons.

## Flashing Quickstart (PlatformIO CLI)

Assumes you have the board connected (USB) and PlatformIO CLI installed (`pip install platformio` and make sure `pio` is on your PATH).

Replace `/dev/cu.usbserial-XXXX` with your serial port (check with `pio device list`).

Copying and entering this two-line command below should get the firmware built and pushed to the Squidbox:

# Build + upload main firmware
pio run -e adafruit_feather_esp32_v2 -t upload --upload-port /dev/cu.usbserial-59690893931

# Upload the LittleFS data (presets in data/config.json)
pio run -e adafruit_feather_esp32_v2 -t uploadfs --upload-port /dev/cu.usbserial-59690893931


Here are the general commands we use:

- Build + upload Squidbox firmware (Feather ESP32 V2 target):  
  `pio run -e adafruit_feather_esp32_v2 -t upload --upload-port /dev/cu.usbserial-XXXX`
- Upload LittleFS data (presets in `data/`):  
  `pio run -e adafruit_feather_esp32_v2 -t uploadfs --upload-port /dev/cu.usbserial-XXXX`
- Serial monitor at project baud:  
  `pio device monitor -b 115200 --port /dev/cu.usbserial-XXXX --echo`
- If you are using the DevKit simulation target instead:  
  `pio run -e esp32dev -t buildfs -t upload --upload-port /dev/cu.usbserial-XXXX`

If upload hangs on “Connecting…”, hold BOOT during that phase and release after the dots start. Press EN/reset to reboot after flashing.


## Contributing

Navigate to the [CONTRIBUTING.md](./CONTRIBUTING.md) file for guidelines on how to contribute to the project.