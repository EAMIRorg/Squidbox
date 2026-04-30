#pragma once

#include "gui/menu-item/random-velocity/RandomVelocityMenuItem.h"
#include "gui/keyboard/Keyboard.h"
#include "gui/menu-item/chord-type/ChordTypeMenuItem.h"
#include "gui/menu-item/root-note/RootNoteMenuItem.h"
#include "gui/menu-item/scale/ScaleMenuItem.h"
#include "scene/Scene.h"
#include "util/ChordType.h"
#include "util/note/Note.h"
#include "util/scale/Scale.h"

/**
 * @class ChordScene
 * @brief A class that represents a scene for playing chords.
 * @details This class is a subclass of Scene and adds functionality for playing
 * chords. It includes a keyboard for playing chords, and menu items for
 * selecting the root note, scale, and chord type.
 */
class ChordScene : public Scene {
private:
  RootNoteMenuItem
      *rootMenuItem;            ///< The menu item for selecting the root note.
  ScaleMenuItem *scaleMenuItem; ///< The menu item for selecting the scale.
  RandomVelocityMenuItem *randomVelocityMenuItem; ///< The menu item for toggling random velocity.
  ChordTypeMenuItem
      *chordTypeMenuItem; ///< The menu item for selecting the chord type.
  Keyboard *keyboard;     ///< The keyboard for playing chords.
  static const Note MIN_NOTE =
      NOTE_C1; ///< The minimum note that can be played.
  static const Note MAX_NOTE =
      NOTE_C7; ///< The maximum note that can be played.

public:
  /**
   * @brief Construct a new ChordScene object.
   * @param squidbox The Squidbox object.
   */
  ChordScene(Squidbox *squidbox);

  /**
   * @brief Update the chord scene.
   */
  void update() override;

  /**
   * @brief Play a chord.
   * @param index The index of the chord to play.
   * @param on Whether the chord should be played or stopped.
   */
  void playChord(int index, bool on);
};