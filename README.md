# Squidbox

The EAMIR Squidbox is a low-cost Bluetooth MIDI controller. It provides an intuitive and interactive way to learn about scales and chords while having fun making music. It runs on an ESP32 and features a 2-axis joystick, a small OLED screen, a knob, and multiple buttons. 

## Python + PlatformIO setup (macOS)

In Terminal on MacOS: 
- Verify Python 3 is available by running: `python3 --version`
  - If not installed, install from `https://www.python.org/downloads/` (or through Homebrew: `brew install python`)
- Install PlatformIO via pip (preferred): `python3 -m pip install --user platformio` (or `pip3 install --user platformio`) (or through Homebrew: `brew install platformio`)
- Confirm install: `python3 -m platformio --version`
- If `platformio`/`pio` is not found, add your Python user bin to PATH:
  - Find the user base: `python3 -m site --user-base` (expect something like `/Users/<you>/Library/Python/3.xx`)
  - Add run: `echo 'export PATH="/Users/<you>/Library/Python/3.xx/bin:$PATH"' >> ~/.zshrc && source ~/.zshrc`

In VSCode:
- Restart VSCode
- Open the Terminal and test by running: `platformio --version` (or `pio --version`),`which platformio` (or `which pio`)
- If it still cannot find `pio`, set the same PATH in VS Code settings (`terminal.integrated.env.osx`) or select the `python3` interpreter in the Command Palette by Opening VS Code settings (Command Palette → “Preferences: Open User Settings (JSON)”). Add or update this: "terminal.integrated.env.osx": {
  "PATH": "/Users/<you>/Library/Python/3.xx/bin:${env:PATH}"
}
 (replace with your actual user bin path from python3 -m site --user-base):


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


## Related

- The Squidbox Configuration Editor is available at https://eamirorg.github.io/Squidbox-web-editor/

- The Squidbox Configuration Editor source is available at https://github.com/EAMIRorg/Squidbox-web-editor 



## Contributing

Navigate to the [CONTRIBUTING.md](./CONTRIBUTING.md) file for guidelines on how to contribute to the project.
