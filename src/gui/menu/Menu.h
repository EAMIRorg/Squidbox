#pragma once

#include "gui/menu-item/MenuItem.h"
#include "scene/SceneType.h"
#include "config/chars.h"

class Squidbox;

/**
 * @class Menu
 * @brief A class that represents an interactable GUI within a Scene.
 * @details The Menu class is a key component of the user interface, providing a
 * structured and interactive way for users to navigate through different
 * functionalities within a Scene. It achieves this by aggregating a number of
 * MenuItem objects, each representing a selectable option or action. The Menu
 * class manages these MenuItems, handling user input to navigate between them
 * and triggering their associated actions when selected.
 */
class Menu {
private:
  const char *name;      ///< The name of the menu.
  int numMenuItems;      ///< The number of menu items.
  int selectedIndex;     ///< The index of the selected item.
  SceneType parentScene; ///< The parent scene of the menu.
  MenuItem **menuItems;  ///< The menu items.

  /**
   * @brief Get the next index.
   * @return The next index.
   */
  int getNextIndex();

  /**
   * @brief Get the previous index.
   * @return The previous index.
   */
  int getPreviousIndex();

public:
  /**
   * @brief Construct a new Menu object.
   * @param name The name of the menu.
   * @param numMenuItems The number of menu items.
   * @param menuItems The menu items.
   * @param parentScene The parent scene of the menu.
   */
  Menu(const char *name, int numMenuItems, MenuItem **menuItems,
       SceneType parentScene);

  /**
   * @brief Construct a new Menu object.
   * @param name The name of the menu.
   * @param numMenuItems The number of menu items.
   * @param menuItems The menu items.
   */
  Menu(const char *name, int numMenuItems, MenuItem **menuItems);

  /**
   * @brief Construct a new Menu object.
   * @param name The name of the menu.
   * @param parentScene The parent scene of the menu.
   */
  Menu(const char *name, SceneType parentScene);

  /**
   * @brief Draw the menu.
   * @param squidbox The Squidbox object.
   */
  void drawMenu(Squidbox *squidbox);

  /**
   * @brief Check if the menu has items.
   * @return true if the menu has items, false otherwise.
   */
  bool hasMenuItems();

  /**
   * @brief Check if the menu has a parent scene.
   * @return true if the menu has a parent scene, false otherwise.
   */
  bool hasParentScene();

  /**
   * @brief Set the name of the menu.
   * @param name The new name of the menu.
   */
  void setName(const char *name);

  /**
   * @brief Handle the left knob event.
   * @param count The count of the event.
   * @param usr_data The user data.
   */
  static void onKnobLeft(int count, void *usr_data);

  /**
   * @brief Handle the right knob event.
   * @param count The count of the event.
   * @param usr_data The user data.
   */
  static void onKnobRight(int count, void *usr_data);
};