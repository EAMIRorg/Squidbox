#pragma once

/**
 * @enum SceneType
 * @brief An enumeration of different types of scenes.
 * @details This enumeration is used to distinguish between different types of
 * scenes in the Squidbox device.
 */
enum SceneType {
  MAIN_SCENE,                ///< The main scene.
  CHORD_SCENE,               ///< The chord scene.
  NOTE_SCENE,                ///< The note scene.
  DRUM_SCENE,                ///< The drum scene.
  CUSTOM_SCENE,              ///< The custom scene.
  JOYSTICK_CALIBRATOR_SCENE, ///< The joystick calibrator scene.
  KNOB_SCENE,                ///< The knob scene.
  BUTTON_SCENE,              ///< The button scene.
  NULL_SCENE ///< The null scene. This is a special scene type that does not
             ///< correspond to an actual scene. It is used as a placeholder or
             ///< default value in certain situations, such as when a scene has
             ///< not yet been assigned or when an invalid or non-existent scene
             ///< is referenced.
};

/**
 * @brief The total number of scenes.
 */
const int NUM_SCENES = 8;