#pragma once

#include "gui/keyboard/Keyboard.h"
#include "gui/menu-item/chord-type/ChordTypeMenuItem.h"
#include "gui/menu-item/root-note/RootNoteMenuItem.h"
#include "gui/menu-item/scale/ScaleMenuItem.h"
#include "scene/Scene.h"
#include "util/ChordType.h"
#include "util/note/Note.h"
#include "util/scale/Scale.h"

/**
 * @class CustomScene
 * @brief A class that represents a scene for playing chords.
 * @details This class is a subclass of Scene and adds functionality for playing
 * chords. It includes a keyboard for playing chords, and menu items for
 * selecting the root note, scale, and chord type.
 */
class CustomScene : public Scene {
private:
  RootNoteMenuItem
      *rootMenuItem;            ///< The menu item for selecting the root note.
  ScaleMenuItem *scaleMenuItem; ///< The menu item for selecting the scale.
  ChordTypeMenuItem
      *chordTypeMenuItem; ///< The menu item for selecting the chord type.
  Keyboard *keyboard;     ///< The keyboard for playing chords.
  static const Note MIN_NOTE =
      NOTE_C1; ///< The minimum note that can be played.
  static const Note MAX_NOTE =
      NOTE_C7; ///< The maximum note that can be played.

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