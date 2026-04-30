#pragma once

#include "gui/keyboard/Keyboard.h"
#include "gui/menu-item/root-note/RootNoteMenuItem.h"
#include "gui/menu-item/scale/ScaleMenuItem.h"
#include "scene/Scene.h"
#include "util/ChordType.h"
#include "util/note/Note.h"
#include "util/scale/Scale.h"
#include "gui/menu-item/random-velocity/RandomVelocityMenuItem.h" //includes new random velocity for notes

/**
 * @class NoteScene
 * @brief A class that represents a scene for playing notes.
 * @details This class is a subclass of Scene and adds functionality for playing
 * notes. It includes a keyboard for playing notes, and menu items for selecting
 * the root note and scale.
 */
class NoteScene : public Scene {
private:
  RootNoteMenuItem
      *rootMenuItem;            ///< The menu item for selecting the root note.
  ScaleMenuItem *scaleMenuItem; ///< The menu item for selecting the scale.
  RandomVelocityMenuItem *randomVelocityMenuItem; ///< The menu item for toggling random velocity.
  Keyboard *keyboard;           ///< The keyboard for playing notes.
  static const Note MIN_NOTE =
      NOTE_C1; ///< The minimum note that can be played.
  static const Note MAX_NOTE =
      NOTE_C7; ///< The maximum note that can be played.

public:
  /**
   * @brief Construct a new NoteScene object.
   * @param squidbox The Squidbox object.
   */
  NoteScene(Squidbox *squidbox);

  /**
   * @brief Update the scene.
   */
  void update() override;

  /**
   * @brief Play a note.
   * @param index The index of the note to play.
   * @param on Whether the note should be played or stopped.
   */
  void playNote(int index, bool on);
};