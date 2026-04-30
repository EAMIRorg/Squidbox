#include "DrumScene.h"
#include "Squidbox.h"
#include "gui/menu-item/random-velocity/RandomVelocityMenuItem.h"

DrumScene::DrumScene(Squidbox *squidbox) : Scene(squidbox, nullptr) {
  // Create menu items
  octaveMenuItem = new OctaveMenuItem();
  randomVelocityMenuItem = new RandomVelocityMenuItem(squidbox);

  // Create an array of menu items
  MenuItem **menuItems = new MenuItem *[2];
  menuItems[0] = octaveMenuItem;
  menuItems[1] = randomVelocityMenuItem;

  // Create a new menu with the menu items
  menu = new Menu("Drums", 2, menuItems, MAIN_SCENE);
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
    squidbox->getMidiController()->sendNoteOn(
        note, squidbox->getNoteOnVelocity(), 0);
  } else {
    squidbox->getMidiController()->sendNoteOff(note, 127, 0);
  }
}