#pragma once

#include "gui/keyboard/Keyboard.h"
#include "scene/Scene.h"
#include "util/ChordType.h"
#include "util/note/Note.h"
#include "util/scale/Scale.h"
#include <gui/menu-item/preset/PresetMenuItem.h>
#include "gui/menu-item/random-velocity/RandomVelocityMenuItem.h" //includes new random velocity for notes

/**
 * @class CustomScene
 * @brief A class that represents a scene for playing chords.
 * @details This class is a subclass of Scene and adds functionality for playing
 * chords. It includes a keyboard for playing chords, and menu items for
 * selecting the root note, scale, and chord type.
 */
class CustomScene : public Scene {
private:
  PresetMenuItem
      *presetMenuItem;    ///< The menu item for selecting the preset.
  Keyboard *keyboard;     ///< The keyboard for playing chords.
  RandomVelocityMenuItem *randomVelocityMenuItem; ///< The menu item for toggling random velocity.
  static const Note MIN_NOTE =
      NOTE_C1; ///< The minimum note that can be played.
  static const Note MAX_NOTE =
      NOTE_C7; ///< The maximum note that can be played.
  Note lastRootNote = NOTE_C4; ///< The last root note played.

public:
  /**
   * @brief Construct a new CustomScene object.
   * @param squidbox The Squidbox object.
   */
  CustomScene(Squidbox *squidbox);

  /**
   * @brief Update the custom scene.
   */
  void update() override;

  /**
   * @brief Play a chord.
   * @param index The index of the chord to play.
   * @param on Whether the chord should be played or stopped.
   */
  void playChord(int index, bool on);
};