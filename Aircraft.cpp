#include "Aircraft.h"

/**
 * @brief Constructor for Aircraft class
 * @param name The name of the aircraft
 * @param health The initial health points of the aircraft
 * @param speed The speed of the aircraft
 */
Aircraft::Aircraft(std::string name, int health, int speed) 
    : name(name), health(health), speed(speed) {}

/**
 * @brief Check if the aircraft is still alive
 * @return true if health is greater than 0, false otherwise
 */
bool Aircraft::isAlive() const { return health > 0; }

/**
 * @brief Get the name of the aircraft
 * @return The name of the aircraft
 */
std::string Aircraft::getName() const { return name; }

/**
 * @brief Get the current health of the aircraft
 * @return The current health points
 */
int Aircraft::getHealth() const { return health; }

/**
 * @brief Get the speed of the aircraft
 * @return The speed of the aircraft
 */
int Aircraft::getSpeed() const { return speed; }

/**
 * @brief Apply damage to the aircraft
 * @param damage The amount of damage to be applied
 */
void Aircraft::takeDamage(int damage) {
    health = std::max(0, health - damage);
}

/**
 * @brief Virtual attack method (to be overridden by derived classes)
 * @return The attack damage (0 for base class)
 */
int Aircraft::attack() const {
    // Base implementation (should be overridden)
    return 0;
}