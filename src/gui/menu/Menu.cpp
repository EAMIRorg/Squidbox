#include "Menu.h"
#include "Squidbox.h"

Menu::Menu(const char *name, int numMenuItems, MenuItem **menuItems,
           SceneType parentScene)
    : name(name), numMenuItems(numMenuItems), menuItems(menuItems),
      parentScene(parentScene), selectedIndex(0) {}

Menu::Menu(const char *name, int numMenuItems, MenuItem **menuItems)
    : Menu(name, numMenuItems, menuItems, NULL_SCENE) {}

Menu::Menu(const char *name, SceneType parentScene)
    : Menu(name, 0, nullptr, parentScene) {}

void Menu::drawMenu(Squidbox *squidbox) {
  // Get joystick input
  Joystick *joystick = squidbox->getJoystick();

  // Update selected index based on joystick input
  if (joystick->wasUpJustInputted()) {
    selectedIndex = getPreviousIndex();
  } else if (joystick->wasDownJustInputted()) {
    selectedIndex = getNextIndex();
  } else if (joystick->wasLeftJustInputted()) {
    // Trigger onKnobLeft event for selected menu item
    menuItems[selectedIndex]->onKnobLeft();
  } else if (joystick->wasRightJustInputted()) {
    // Trigger onKnobRight event for selected menu item
    menuItems[selectedIndex]->onKnobRight();
  }

  // If OK button is pressed, trigger onSelect event for selected menu item
  if (hasMenuItems()) {
    Button *okButton = squidbox->getOkButton();
    if (okButton->isPressed()) {
      menuItems[selectedIndex]->onSelect();
    }
  }

  // If back button is pressed, switch to parent scene
  if (hasParentScene()) {
    Button *backButton = squidbox->getBackButton();
    if (backButton->isPressed()) {
      squidbox->switchTo(parentScene);
    }
  }

  // Get screen and clear portion of the screen that contains text
  Screen *screen = squidbox->getScreen();
  int clearHeight = (numMenuItems + 2) * 8; // 8 pixels per line
  screen->getDisplay()->fillRect(0, 0, Screen::WIDTH, clearHeight, BLACK);

  // Set text size, color, and cursor position
  screen->getDisplay()->setTextSize(1);
  screen->getDisplay()->setTextColor(WHITE);
  screen->getDisplay()->setCursor(0, 0);

  // Print header bar
  screen->getDisplay()->printf(squidbox->getDeviceId());
  ;
  screen->getDisplay()->setCursor(Screen::WIDTH - 28, 0);
  screen->getDisplay()->printf("%s:", squidbox->getMidiController()->getName());
  const unsigned char *connectedIcon =
      squidbox->getMidiController()->isConnected() ? CHECKMARK_BITMAP
                                                   : X_BITMAP;
  screen->getDisplay()->drawBitmap(Screen::WIDTH - 8, 0, connectedIcon, 8, 8,
                                   WHITE);

  screen->getDisplay()->setCursor(0, 8);

  // Print menu name
  if (hasParentScene()) {
    screen->getDisplay()->write(ASCII_LEFT_ARROW);
  }
  screen->getDisplay()->printf("%s\n", name);

  // Print menu items
  for (int i = 0; i < numMenuItems; i++) {
    MenuItem *menuItem = menuItems[i];
    int prefix = i == selectedIndex ? menuItem->getPrefix() : ASCII_NULL;
    screen->getDisplay()->write(prefix);
    screen->getDisplay()->printf("%s\n", menuItem->getName());
  }

  // Update screen
  screen->update();
}

void Menu::setName(const char *name) { this->name = name; }

bool Menu::hasMenuItems() {
  // Check if the number of menu items is greater than 0
  return numMenuItems > 0;
}

bool Menu::hasParentScene() {
  // Check if the parent scene is not equal to NULL_SCENE
  return parentScene != NULL_SCENE;
}

int Menu::getNextIndex() {
  // Calculate the next index, ensuring it doesn't exceed the number of menu
  // items
  return min(selectedIndex + 1, numMenuItems - 1);
}

int Menu::getPreviousIndex() {
  // Calculate the previous index, ensuring it doesn't go below 0
  return max(selectedIndex - 1, 0);
}

void Menu::onKnobLeft(int count, void *usr_data) {
  Menu *self = static_cast<Menu *>(usr_data);

  // Knob triggers twice per click, so we only want to trigger the event every
  // other click
  if (count % 2 == 0) {
    self->menuItems[self->selectedIndex]->onKnobLeft();
  }
}

void Menu::onKnobRight(int count, void *usr_data) {
  Menu *self = static_cast<Menu *>(usr_data);

  // Knob triggers twice per click, so we only want to trigger the event every
  // other click
  if (count % 2 == 0) {
    self->menuItems[self->selectedIndex]->onKnobRight();
  }
}