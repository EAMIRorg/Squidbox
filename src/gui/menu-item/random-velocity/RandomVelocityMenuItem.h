#pragma once

#include "gui/menu-item/MenuItem.h"

class Squidbox;

/**
 * @class RandomVelocityMenuItem
 * @brief Toggle between fixed and random velocity
 */
class RandomVelocityMenuItem : public MenuItem {
private:
  Squidbox *squidbox;

  /**
   * @brief Handle knob left
   */
  static void onKnobLeft(void *arg);

  /**
   * @brief Handle knob right
   */
  static void onKnobRight(void *arg);

  /**
   * @brief Update label based on current state
   */
  void updateName();

public:
  /**
   * @brief Construct a new RandomVelocityMenuItem
   */
  RandomVelocityMenuItem(Squidbox *squidbox);
};