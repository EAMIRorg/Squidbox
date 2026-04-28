#include "CustomScene.h"
#include "Squidbox.h"
#include "gui/menu-item/random-velocity/RandomVelocityMenuItem.h"

CustomScene::CustomScene(Squidbox *squidbox) : Scene(squidbox, nullptr) {
  presetMenuItem = new PresetMenuItem();
  randomVelocityMenuItem = new RandomVelocityMenuItem(squidbox);

  // Create an array of menu items
  MenuItem **menuItems = new MenuItem *[2];
  menuItems[0] = presetMenuItem;
  menuItems[1] = randomVelocityMenuItem;

  // Create a new menu with the menu items
  menu = new Menu("Custom", 2, menuItems, MAIN_SCENE);

  // Create a new keyboard
  keyboard = new Keyboard(squidbox);
}

void CustomScene::update() {
  // Call the update function of the parent class
  Scene::update();

  // Check if any of the buttons are pressed
  for (int i = 0; i < Squidbox::NUM_BUTTONS; i++) {
    Button *button = squidbox->getButton(i);
    if (button->isPressed()) {
      // If the button is pressed, play the chord
      playChord(i, true);
    }
    if (button->isReleased()) {
      // If the button is released, stop playing the chord
      playChord(i, false);
    }
  }

  // Draw keyboard with root note as last root note played
  keyboard->update(lastRootNote);
}

void CustomScene::playChord(int index, bool on) {
  const std::vector<int> notes = presetMenuItem->getPreset()->notes[index];

  // Play or stop playing the notes
  for (int i = 0; i < notes.size(); i++) {
    keyboard->setKeyDown(notes[i], on);
    if (on) {
      // If the chord should be played, send a note on message
      squidbox->getMidiController()->sendNoteOn(
          notes[i], squidbox->getNoteOnVelocity(), 0);
    } else {
      // If the chord should be stopped, send a note off message
      squidbox->getMidiController()->sendNoteOff(notes[i], 127, 0);
    }
  }

  // Update the keyboard with the root note of the chord
  lastRootNote = Note(notes[0]);
}