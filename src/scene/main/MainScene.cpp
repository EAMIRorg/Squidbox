#include "MainScene.h"
#include "Squidbox.h"

MainScene::MainScene(Squidbox *squidbox) : Scene(squidbox, nullptr) {
  // Create new menu items for each scene
  MenuItem *chordMenuItem = new SwitchSceneMenuItem("Chords", squidbox, CHORD_SCENE);
  MenuItem *noteMenuItem = new SwitchSceneMenuItem("Notes", squidbox, NOTE_SCENE);
  MenuItem *drumMenuItem = new SwitchSceneMenuItem("Drums", squidbox, DRUM_SCENE);
  MenuItem *customMenuItem = new SwitchSceneMenuItem("Custom", squidbox, CUSTOM_SCENE);
  MenuItem *quitMenuItem = new QuitMenuItem(squidbox);

  // Create an array of menu items
  int NUM_MENU_ITEMS = 5;

  MenuItem **menuItems = new MenuItem *[NUM_MENU_ITEMS];
  menuItems[0] = chordMenuItem;
  menuItems[1] = noteMenuItem;
  menuItems[2] = drumMenuItem;
  menuItems[3] = customMenuItem;
  menuItems[4] = quitMenuItem;

  // Create a new menu with the menu items
  menu = new Menu("Menu", NUM_MENU_ITEMS, menuItems);
}