#include "ChordScene.h"
#include "Squidbox.h"
#include "gui/menu-item/random-velocity/RandomVelocityMenuItem.h"

ChordScene::ChordScene(Squidbox *squidbox) : Scene(squidbox, nullptr) {
  // Create menu items for root note, scale, chord type, and random velocity
  rootMenuItem = new RootNoteMenuItem();
  scaleMenuItem = new ScaleMenuItem();
  chordTypeMenuItem = new ChordTypeMenuItem();
  randomVelocityMenuItem = new RandomVelocityMenuItem(squidbox);

  // Create an array of menu items
  MenuItem **menuItems = new MenuItem *[4];
  menuItems[0] = rootMenuItem;
  menuItems[1] = scaleMenuItem;
  menuItems[2] = chordTypeMenuItem;
  menuItems[3] = randomVelocityMenuItem;

  // Create a new menu with the menu items
  menu = new Menu("Chords", 4, menuItems, MAIN_SCENE);

  // Create a new keyboard
  keyboard = new Keyboard(squidbox);
}

void ChordScene::update() {
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

  // Update the keyboard with the current root note
  keyboard->update(rootMenuItem->getRootNote());
}

void ChordScene::playChord(int index, bool on) {
  // Get the current scale, root note, and chord type from the menu items
  Scale *scale = scaleMenuItem->getScale();
  Note root = rootMenuItem->getRootNote();
  ChordType *chordType = chordTypeMenuItem->getChordType();

  // Get the notes in the chord
  int *notes = scale->getNotesFromChord(root, index, chordType);

  // Play or stop playing the notes
  for (int i = 0; i < chordType->numNotes; i++) {
    keyboard->setKeyDown(notes[i], on);
    if (on) { // If the chord should be played, play the note
      squidbox->getMidiController()->sendNoteOn(notes[i], squidbox->getNoteOnVelocity(), 0); //changed to have a randomized velocity if enabled
    } else { // If the chord should be stopped, stop playing the note
      squidbox->getMidiController()->sendNoteOff(notes[i], 127, 0);
    }
  }
}