#include "DrumScene.h"
#include "Squidbox.h"

DrumScene::DrumScene(Squidbox *squidbox) : Scene(squidbox, nullptr) {
  // Create a new menu item for the octave
  octaveMenuItem = new OctaveMenuItem();

  // Create an array of menu items
  MenuItem **menuItems = new MenuItem *[1];
  menuItems[0] = octaveMenuItem;

  // Create a new menu with the menu items
  menu = new Menu("Drums", 1, menuItems, MAIN_SCENE);
}

void DrumScene::update() {
  // Call the update function of the parent class
  Scene::update();

  // Loop through all the buttons
  for (int i = 0; i < Squidbox::NUM_BUTTONS; i++) {
    // Check if the button is pressed
    if (squidbox->getButton(i)->isPressed()) {
      // If the button is pressed, play the drum
      playDrum(i, true);
    }
    if (squidbox->getButton(i)->isReleased()) {
      // If the button is released, stop playing the drum
      playDrum(i, false);
    }
  }
}

void DrumScene::playDrum(int index, bool on) {
  // Get the current octave from the menu item
  Note octave = octaveMenuItem->getNote();

  // Calculate the note to play based on the octave and index
  int note = octave + index;

  // Play or stop playing the note
  if (on) {
    squidbox->getMidiController()->sendNoteOn(note, 127, 0);
  } else {
    squidbox->getMidiController()->sendNoteOff(note, 127, 0);
  }
}