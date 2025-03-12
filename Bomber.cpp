#include "Bomber.h"

Bomber::Bomber(std::string name, int health, int speed, int bombLoad)
    : Aircraft(name, health, speed), bombLoad(bombLoad) {}

int Bomber::attack() const {
    if (hasBombs()) {
        bombLoad -= 1;  // Decrease bombLoad by 1 for each attack
        return 100;  // Assuming each bomb does 100 damage
    }
    return 0;  // No bombs left
}

bool Bomber::hasBombs() const {
    return bombLoad > 0;
}