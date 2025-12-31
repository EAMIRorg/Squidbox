# Squidbox

The EAMIR Squidbox is a low-cost Bluetooth MIDI controller. It provides an intuitive and interactive way to learn about scales and chords while having fun making music. It runs on an ESP32 and features a 2-axis joystick, a small OLED screen, a knob, and multiple buttons. 

# General Setup

  - Install [Python](https://www.python.org/downloads/) (or via Homebrew: `brew install python`)

  Once Python is installed, follow one of the setup methods described below. 

## VSCode Setup and Extensions

  - Install [VSCode](https://code.visualstudio.com/download)

In VSCode, install the extensions:
- PlatformIO
- Wokwi (optional) - required only for simulating Squidbox; see [CONTRIBUTING.md](./CONTRIBUTING.md) for more details

In VS Code, set the integrated terminal to use `zsh`

# Automatic Setup for MacOS (Python + PlatformIO)
Open the Terminal utility on MacOS, and copy and run: 

```bash
/bin/bash -c 'set -euo pipefail
trap '"'"'echo "PlatformIO install failed." >&2'"'"' ERR
if ! command -v python3 >/dev/null; then
  echo "Python 3 not found. Install it first (e.g., brew install python)." >&2
  exit 1
fi

TMP_PIO="$(mktemp -t get-platformio.XXXXXX.py)"
trap '"'"'rm -f "$TMP_PIO"'"'"' EXIT
curl -fsSL https://raw.githubusercontent.com/platformio/platformio-core-installer/master/get-platformio.py -o "$TMP_PIO"
python3 "$TMP_PIO"

PIO_BIN_DIR="$HOME/.platformio/penv/bin"
if [ -x "$PIO_BIN_DIR/platformio" ]; then
  "$PIO_BIN_DIR/platformio" --version
else
  echo "PlatformIO binary not found at $PIO_BIN_DIR/platformio" >&2
  exit 1
fi

if ! echo ":$PATH:" | grep -q ":$PIO_BIN_DIR:"; then
  echo "export PATH=\"${PIO_BIN_DIR}:\$PATH\"" >> "$HOME/.zshrc"
  export PATH="${PIO_BIN_DIR}:$PATH"
  echo "Added ${PIO_BIN_DIR} to PATH in ~/.zshrc. Restart shell or run: source ~/.zshrc"
else
  echo "PATH already includes ${PIO_BIN_DIR}"
fi
echo "PlatformIO install complete."
'
```

## Manual Setup for MacOS (Python + PlatformIO)

In Terminal on MacOS: 
- Verify Python 3 is available by running: `python3 --version`
- Install PlatformIO via pip (preferred): `python3 -m pip install --user platformio` (or `pip3 install --user platformio`) (or through Homebrew: `brew install platformio`)
  - If an error indicates that pip is not installed, reinstall python using one of the above methods (or run `sudo apt-get install python3-pip`)
- Confirm install: `python3 -m platformio --version`
- If `platformio`/`pio` is not found, add your Python user bin to PATH:
  - Find the user base: `python3 -m site --user-base` (expect something like `/Users/<you>/Library/Python/3.xx`)
  - Add run: `echo 'export PATH="/Users/<you>/Library/Python/3.xx/bin:$PATH"' >> ~/.zshrc && source ~/.zshrc`


# Automatic Setup for Windows (Python + PlatformIO)

In PowerShell on Windows, copy and run:

```powershell
try {
  python --version  # ensure Python 3 is installed and on PATH

  $tmp = [IO.Path]::GetTempFileName()
  Invoke-WebRequest -UseBasicParsing https://raw.githubusercontent.com/platformio/platformio-core-installer/master/get-platformio.py -OutFile $tmp
  python $tmp
  Remove-Item $tmp -ErrorAction SilentlyContinue

  $PioBin = Join-Path $HOME ".platformio/penv/Scripts/platformio.exe"
  if (Test-Path $PioBin) {
    & $PioBin --version
  } else {
    throw "PlatformIO binary not found at $PioBin"
  }

  $PioDir = Split-Path $PioBin
  if (-not ($env:PATH -split ";" | ? { $_ -eq $PioDir })) {
    [System.Environment]::SetEnvironmentVariable("Path", "$PioDir;$env:Path", "User")
    Write-Host "Added $PioDir to user PATH. Restart terminal."
  } else {
    Write-Host "PATH already includes $PioDir"
  }
  Write-Host "PlatformIO install complete."
}
catch {
  Write-Error "PlatformIO install failed: $_"
  exit 1
}
```



# Finishing VSCode Setup
In VSCode:
- Restart VSCode
- Open a new Terminal window and test by running: `platformio --version` (or `pio --version`),`which platformio` (or `which pio`)
- If `pio` isn’t found in VS Code’s integrated terminal, open the Command Palette (View → Command Palette → “Preferences: Open User Settings (JSON)”) and add:
"terminal.integrated.env.osx": {
  "PATH": "/Users/<you>/Library/Python/3.x/bin:${env:PATH}"
}
Replace `<you>` with your username (from `python3 -m site --user-base`) and make sure the default terminal profile is `zsh`.


# Flashing the Squidbox in VSCode

Assumes you have the board connected (USB) and PlatformIO CLI installed (`pip install platformio` and make sure `pio` is on your PATH).

In VSCode: 
- Run `pio device list` 
- Note the line in the code that reads `/dev/cu.usbserial-XXXX`
- Replace `/dev/cu.usbserial-XXXX` with your serial port in the commands below (check with `pio device list` again if unsure).
- Copy and enter this two-line command below (with your serial port) to build the code and push it to the Squidbox:

pio run -e adafruit_feather_esp32_v2 -t upload --upload-port /dev/cu.usbserial-59690893931
pio run -e adafruit_feather_esp32_v2 -t uploadfs --upload-port /dev/cu.usbserial-59690893931


## General Commands

Here are the general commands we use with Squidbox:

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
