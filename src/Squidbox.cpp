#include "Squidbox.h"

Squidbox::Squidbox() {
#ifdef SIMULATION
  midiController = new SimulatedMidiController();
#else
  // Start the BLE MIDI server with the name of the device
  midiController = new BLEMidiController(getName());
#endif
  midiController->begin();

  // Initialize the screen, joystick, knob, and buttons with their respective
  // pins
  screen = new Screen();
  joystick = new Joystick(PIN_JOYSTICK_X, PIN_JOYSTICK_Y, PIN_JOYSTICK_BUTTON);
  knob = new Knob(PIN_KNOB_A, PIN_KNOB_B, PIN_KNOB_BUTTON);
  backButton = new Button(PIN_BACK_BUTTON);
  okButton = new Button(PIN_OK_BUTTON);
  buttons[0] = new Button(PIN_BUTTON_0);
  buttons[1] = new Button(PIN_BUTTON_1);
  buttons[2] = new Button(PIN_BUTTON_2);
  buttons[3] = new Button(PIN_BUTTON_3);
  buttons[4] = new Button(PIN_BUTTON_4);
  buttons[5] = new Button(PIN_BUTTON_5);
  buttons[6] = new Button(PIN_BUTTON_6);
  buttons[7] = new Button(PIN_BUTTON_7);

  // Enable wakeup from deep sleep when button 0 is pressed
  esp_sleep_enable_ext0_wakeup(static_cast<gpio_num_t>(PIN_BACK_BUTTON), 0);
}

void Squidbox::init() {
  // Initialize the scenes with this Squidbox instance
  scenes[MAIN_SCENE] = new MainScene(this);
  scenes[CHORD_SCENE] = new ChordScene(this);
  scenes[NOTE_SCENE] = new NoteScene(this);
  scenes[DRUM_SCENE] = new DrumScene(this);
  scenes[CUSTOM_SCENE] = new CustomScene(this);
  scenes[JOYSTICK_CALIBRATOR_SCENE] = new JoystickCalibratorScene(this);
  scenes[KNOB_SCENE] = new KnobScene(this);
  scenes[BUTTON_SCENE] = new ButtonScene(this);
}

void Squidbox::update() {
  // If the current scene has not been initialized, initialize it
  if (!currentSceneInitialized) {
    scenes[currentScene]->init();
    currentSceneInitialized = true;
  }

  // Update the current scene
  scenes[currentScene]->update();
}

void Squidbox::switchTo(SceneType scene) {
  // If the scene has changed, set the new scene and mark it as not initialized
  if (scene != currentScene) {
    currentScene = scene;
    currentSceneInitialized = false;
  }
}

void Squidbox::sleep() {
  // Clear the screen and update it before going to deep sleep
  screen->clear();
  screen->update();
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  esp_deep_sleep_start();
}

Screen *Squidbox::getScreen() { return screen; }

Joystick *Squidbox::getJoystick() { return joystick; }

Knob *Squidbox::getKnob() { return knob; }

Button *Squidbox::getBackButton() { return backButton; }

Button *Squidbox::getOkButton() { return okButton; }

Button **Squidbox::getButtons() { return buttons; }

Button *Squidbox::getButton(int index) {
  // Check if the index is out of bounds
  if (index < 0 || index > NUM_BUTTONS - 1) {
    Serial.printf("Error: Button not found with index %d\n", index);
  }
  // Return the button at the given index
  return buttons[index];
}

MidiController *Squidbox::getMidiController() { return midiController; }

const char *Squidbox::getDeviceId() {
  // Get the default MAC address and format it as a string
  static char deviceId[18];
  uint8_t baseMac[6];
  esp_efuse_mac_get_default(baseMac);
  sprintf(deviceId, "%02X:%02X:%02X", baseMac[3], baseMac[4], baseMac[5]);
  return deviceId;
}

const char *Squidbox::getName() {
  // Format the name of the device as "Squidbox " followed by the device ID
  static char name[26];
  const char *deviceId = getDeviceId();
  sprintf(name, "Squidbox %s", deviceId);
  return name;
}
