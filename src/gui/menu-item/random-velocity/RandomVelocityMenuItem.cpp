#include "RandomVelocityMenuItem.h"
#include "Squidbox.h"

RandomVelocityMenuItem::RandomVelocityMenuItem(Squidbox *squidbox)
    : MenuItem(), squidbox(squidbox) {

  // Set knob callbacks
  setOnKnobLeftCallback(onKnobLeft, this);
  setOnKnobRightCallback(onKnobRight, this);

  // Set initial label
  updateName();
}

void RandomVelocityMenuItem::updateName() {
  if (squidbox->isRandomVelocityEnabled()) {
    setName("Velocity: Random");
  } else {
    setName("Velocity: Fixed");
  }
}

void RandomVelocityMenuItem::onKnobLeft(void *arg) {
  RandomVelocityMenuItem *self =
      static_cast<RandomVelocityMenuItem *>(arg);

  self->squidbox->toggleRandomVelocity();
  self->updateName();
}

void RandomVelocityMenuItem::onKnobRight(void *arg) {
  RandomVelocityMenuItem *self =
      static_cast<RandomVelocityMenuItem *>(arg);

  self->squidbox->toggleRandomVelocity();
  self->updateName();
}