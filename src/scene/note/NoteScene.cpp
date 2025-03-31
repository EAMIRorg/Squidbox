#include "NoteScene.h"
#include "Squidbox.h"

NoteScene::NoteScene(Squidbox *squidbox) : Scene(squidbox, nullptr) {
  // Create new menu items for root note and scale
  rootMenuItem = new RootNoteMenuItem();
  scaleMenuItem = new ScaleMenuItem();

  // Create an array of menu items
  MenuItem **menuItems = new MenuItem *[2];
  menuItems[0] = rootMenuItem;
  menuItems[1] = scaleMenuItem;

  // Create a new menu with the menu items
  menu = new Menu("Chords", 2, menuItems, MAIN_SCENE);

  // Create a new keyboard
  keyboard = new Keyboard(squidbox);
}

void NoteScene::update() {
  // Call the update function of the parent class
  Scene::update();

  // Check if any of the buttons are pressed
  for (int i = 0; i < Squidbox::NUM_BUTTONS; i++) {
    Button *button = squidbox->getButton(i);
    if (squidbox->getButton(i)->isPressed()) {
      // If the button is pressed, play the note
      playNote(i, true);
    }
    if (squidbox->getButton(i)->isReleased()) {
      // If the button is released, stop playing the note
      playNote(i, false);
    }
  }

  // Update keyboard
  keyboard->update(rootMenuItem->getRootNote());
}

void NoteScene::playNote(int index, bool on) {
  // Get scale, root note, and chord type from menu items
  Scale *scale = scaleMenuItem->getScale();
  Note root = rootMenuItem->getRootNote();

  // Get notes in chord
  int note = scale->getNote(root, index);

  // Play notes
  keyboard->setKeyDown(note, on);
  if (on) {
    squidbox->getMidiController()->sendNoteOn(note, 127, 0);
  } else {
    squidbox->getMidiController()->sendNoteOff(note, 127, 0);
  }
}