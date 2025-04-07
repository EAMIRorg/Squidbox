#pragma once

#include "components/button/Button.h"
#include "components/joystick/Joystick.h"
#include "components/knob/Knob.h"
#include "components/midi-controller/MidiController.h"
#include "components/screen/Screen.h"
#include "config/pins.h"
#include "scene/Scene.h"
#include "scene/button/ButtonScene.h"
#include "scene/chord/ChordScene.h"
#include "scene/drum/DrumScene.h"
#include "scene/custom/CustomScene.h"
#include "scene/joystick-calibrator/JoystickCalibratorScene.h"
#include "scene/knob/KnobScene.h"
#include "scene/main/MainScene.h"
#include "scene/note/NoteScene.h"
#include "upload/Upload.h"
#include <Arduino.h>
#include <esp_efuse.h>

#ifdef SIMULATION
#include "components/midi-controller/simulated-midi-controller/SimulatedMidiController.h"
#else
#include "components/midi-controller/ble-midi-controller/BLEMidiController.h"
#endif

#define MIN_VOLTAGE 3.2 // Considered 0% (deep discharge)
#define MAX_VOLTAGE 4.2 // Fully charged (100%)

/**
 * @class Squidbox
 * @brief This class represents the Squidbox device.
 *
 * The Squidbox is a MIDI controller with a screen, a joystick, a knob, and
 * multiple buttons. It can switch between different scenes, each providing a
 * different functionality. For example, one scene might allow the user to play
 * notes, while another might allow the user to play chords.
 *
 * The Squidbox class manages the state of the device, including the current
 * scene, the state of the screen, joystick, knob, and buttons. It also manages
 * the initialization of the device and the transition between scenes.
 *
 * The class provides methods to initialize the device, update its state, switch
 * to a specific scene, and access its components (screen, joystick, knob, and
 * buttons).
 */
class Squidbox {
public:
  static const int NUM_BUTTONS = 8; ///< The number of buttons in the Squidbox

  /**
   * @brief Construct a new Squidbox object
   */
  Squidbox();

  /**
   * @brief Initialize the Squidbox
   */
  void init();

  /**
   * @brief Update the Squidbox
   */
  void update();

  /**
   * @brief Switch to a specific scene
   * @param scene The scene to switch to
   */
  void switchTo(SceneType scene);

  /**
   * @brief Put the Squidbox to sleep
   */
  void sleep();

  /**
   * @brief Get a pointer to the screen
   * @return A pointer to the screen
   */
  Screen *getScreen();

  /**
   * @brief Get a pointer to the joystick
   * @return A pointer to the joystick
   */
  Joystick *getJoystick();

  /**
   * @brief Get a pointer to the knob
   * @return A pointer to the knob
   */
  Knob *getKnob();

  /**
   * @brief Get a pointer to the back button
   * @return A pointer to the back button
   */
  Button *getBackButton();

  /**
   * @brief Get a pointer to the OK button
   * @return A pointer to the OK button
   */
  Button *getOkButton();

  /**
   * @brief Get an array of pointers to the buttons
   * @return An array of pointers to the buttons
   */
  Button **getButtons();

  /**
   * @brief Get a pointer to a specific button
   * @param index The index of the button
   * @return A pointer to the button
   */
  Button *getButton(int index);

  /**
   * @brief Get a pointer to the MIDI controller
   * @return A pointer to the MIDI controller
   */
  MidiController *getMidiController();

  /**
   * @brief Get the device ID
   * @return The device ID
   */
  const char *getDeviceId();

  /**
   * @brief Get the name of the Squidbox
   * @return The name of the Squidbox
   */
  const char *getName();

  /**
   * @brief Get the percentage of battery remaining
   * @return The battery percentage remaining
   */
  const int getBatteryPercent();

private:
  Scene *scenes[NUM_SCENES];     ///< An array of pointers to the scenes in the
                                 ///< Squidbox
  int currentScene = MAIN_SCENE; ///< The index of the current scene
  Screen *screen;                ///< A pointer to the screen of the Squidbox
  Joystick *joystick;            ///< A pointer to the joystick of the Squidbox
  Knob *knob;                    ///< A pointer to the knob of the Squidbox
  Button *backButton; ///< A pointer to the back button of the Squidbox
  Button *okButton;   ///< A pointer to the OK button of the Squidbox
  Button *buttons[NUM_BUTTONS]; ///< An array of pointers to the buttons of the
                                ///< Squidbox
  MidiController
      *midiController; ///< A pointer to the MIDI controller of the Squidbox
  bool currentSceneInitialized = false; ///< A flag indicating whether the
                                        ///< current scene has been initialized
};