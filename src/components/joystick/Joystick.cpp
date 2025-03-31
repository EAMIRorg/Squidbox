#include "Joystick.h"

const char *directionToString(Direction direction) {
  switch (direction) {
  case NONE:
    return "NONE";
  case UP:
    return "UP";
  case RIGHT:
    return "RIGHT";
  case DOWN:
    return "DOWN";
  case LEFT:
    return "LEFT";
  default:
    return "UNKNOWN";
  }
}

Joystick::Joystick(int xPin, int yPin, int buttonPin)
    : xPin(xPin), yPin(yPin), buttonPin(buttonPin), wasLeft(false),
      wasRight(false), wasUp(false), wasDown(false) {
  pinMode(buttonPin, INPUT_PULLUP);
}

float Joystick::map(float x, float inMin, float inMax, float outMin,
                    float outMax) {
  // Calculate the mapped value by subtracting inMin from x, multiplying the
  // result by the ratio of the output range to the input range, and adding
  // outMin.
  return (x - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}

float Joystick::convertRawValue(int raw, int center, int min, int max) {
  // Note that the raw value is inverted because the joystick is rotated 90
  // degrees to the left.
  if (raw > center) {
    // If the raw value is greater than the center value, map it from the range
    // [center, max] to [0, 1].
    return map(raw, center, max, 0, -1);
  } else {
    // If the raw value is less than or equal to the center value, map it from
    // the range [min, center] to [-1, 0].
    return map(raw, min, center, 1, 0);
  }
}

int Joystick::getRawX() { return analogRead(xPin); }

int Joystick::getRawY() { return analogRead(yPin); }

float Joystick::getX() {
  // Convert the raw X value to a value in the range -1 to 1 and return it.
  return convertRawValue(getRawX(), X_CENTER, X_MIN, X_MAX);
}

float Joystick::getY() {
  // Convert the raw Y value to a value in the range -1 to 1 and return it.
  return convertRawValue(getRawY(), Y_CENTER, Y_MIN, Y_MAX);
}

bool Joystick::isPressed() {
  // digitalRead returns 0 when the button is pressed, so return the opposite of
  // the digitalRead value.
  return !digitalRead(buttonPin);
}

Direction Joystick::getDirection() {
  // Calculate the distance from the center of the joystick.
  float x = getX();
  float y = getY();
  float distance = sqrt(x * x + y * y);

  // Determine the direction based on the x and y values and the distance from
  // the center.
  if (distance < JOYSTICK_DEADZONE) {
    return Direction::NONE;
#if SIMULATION
  } else if (y > 0 && y > fabs(x)) {
    return Direction::DOWN;
  } else if (y < 0 && -y > fabs(x)) {
    return Direction::UP;
#else
  } else if (y > 0 && y > fabs(x)) {
    return Direction::UP;
  } else if (y < 0 && -y > fabs(x)) {
    return Direction::DOWN;
#endif
  } else if (x < 0 && -x > fabs(y)) {
    return Direction::LEFT;
  } else if (x > 0 && x > fabs(y)) {
    return Direction::RIGHT;
  } else {
    // If none of the above conditions are met, return NONE.
    return Direction::NONE;
  }
}

bool Joystick::wasLeftJustInputted() {
  // Check if the joystick is currently pointing left.
  bool leftInputted = getDirection() == LEFT;
  // If the joystick is currently pointing left and was not pointing left the
  // last time we checked, then it was just moved to the left.
  bool leftJustInputted = leftInputted && !wasLeft;
  // Update the wasLeft variable for the next time we check.
  wasLeft = leftInputted;
  // Return whether the joystick was just moved to the left.
  return leftJustInputted;
}

bool Joystick::wasRightJustInputted() {
  // Check if the joystick is currently pointing right.
  bool rightInputted = getDirection() == RIGHT;
  // If the joystick is currently pointing right and was not pointing right the
  // last time we checked, then it was just moved to the right.
  bool rightJustInputted = rightInputted && !wasRight;
  // Update the wasRight variable for the next time we check.
  wasRight = rightInputted;
  // Return whether the joystick was just moved to the right.
  return rightJustInputted;
}

bool Joystick::wasUpJustInputted() {
  // Check if the joystick is currently pointing up.
  bool upInputted = getDirection() == UP;
  // If the joystick is currently pointing up and was not pointing up the last
  // time we checked, then it was just moved up.
  bool upJustInputted = upInputted && !wasUp;
  // Update the wasUp variable for the next time we check.
  wasUp = upInputted;
  // Return whether the joystick was just moved up.
  return upJustInputted;
}

bool Joystick::wasDownJustInputted() {
  // Check if the joystick is currently pointing down.
  bool downInputted = getDirection() == DOWN;
  // If the joystick is currently pointing down and was not pointing down the
  // last time we checked, then it was just moved down.
  bool downJustInputted = downInputted && !wasDown;
  // Update the wasDown variable for the next time we check.
  wasDown = downInputted;
  // Return whether the joystick was just moved down.
  return downJustInputted;
}