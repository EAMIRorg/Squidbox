#pragma once

#include "gui/menu-item/octave/OctaveMenuItem.h"
#include "scene/Scene.h"
#include "util/note/Note.h"
#include "gui/menu-item/random-velocity/RandomVelocityMenuItem.h"


/**
 * @class DrumScene
 * @brief A class that represents a scene for playing drums.
 * @details This class is a subclass of Scene and adds functionality for playing
 * drums. It includes a menu item for selecting the octave, as most MIDI drum
 * kits start on a C note. This scene is similar to the NoteScene, the main
 * difference being that the note is selected by choosing an octave.
 */
class DrumScene : public Scene {
private:
  OctaveMenuItem *octaveMenuItem; ///< The menu item for selecting the octave.
  RandomVelocityMenuItem *randomVelocityMenuItem; ///< The menu item for toggling random velocity.
public:
  /**
   * @brief Construct a new DrumScene object.
   * @param squidbox The Squidbox object.
   */
  DrumScene(Squidbox *squidbox);

  /**
   * @brief Update the drum scene.
   */
  void update() override;

  /**
   * @brief Play a drum.
   * @param index The index of the drum to play.
   * @param on Whether the drum should be played or stopped.
   */
  void playDrum(int index, bool on);
};