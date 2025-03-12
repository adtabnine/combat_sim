#include "Fighter.h"
#include <cstdlib>

Fighter::Fighter(std::string name, int health, int speed)
    : Aircraft(name, health, speed) {}

int Fighter::attack() const {
    return rand() % 61 + 20;  // Random damage between 20 and 80
}