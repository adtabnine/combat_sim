#include "Stealth.h"
#include <cstdlib>

Stealth::Stealth(std::string name, int health, int speed)
    : Aircraft(name, health, speed) {}

int Stealth::attack() const {
    return rand() % 41 + 40;  // Random damage between 40 and 80
}
void Stealth::takeDamage(int damage) {
    // 50% chance to avoid damage
    if (rand() % 2 == 0) {
        Aircraft::takeDamage(damage);
    }
}