#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <string>
#include <vector>
#include "Weapon.h"

/**
 * @class Aircraft
 * @brief Base class for all aircraft types in the combat simulation
 */
class Aircraft {
public:
    /**
     * @brief Constructor for Aircraft
     * @param name The name of the aircraft
     * @param health The initial health points of the aircraft
     * @param speed The speed of the aircraft
     */
    Aircraft(std::string name, int health, int speed);

    /**
     * @brief Virtual destructor for proper cleanup of derived classes
     */
    virtual ~Aircraft() = default;

    /**
     * @brief Add a weapon to the aircraft's arsenal
     * @param weapon The weapon to be added
     */
    void addWeapon(const Weapon& weapon);

    /**
     * @brief Check if the aircraft is still alive
     * @return true if health is greater than 0, false otherwise
     */
    bool isAlive() const;

    /**
     * @brief Get the name of the aircraft
     * @return The name of the aircraft
     */
    std::string getName() const;

    /**
     * @brief Get the current health of the aircraft
     * @return The current health points
     */
    int getHealth() const;

    /**
     * @brief Get the speed of the aircraft
     * @return The speed of the aircraft
     */
    int getSpeed() const;

    /**
     * @brief Apply damage to the aircraft
     * @param damage The amount of damage to be applied
     */
    virtual void takeDamage(int damage);

    /**
     * @brief Virtual attack method to be overridden by derived classes
     * @return The attack damage
     */
    virtual int attack() const;

    /**
     * @brief Pure virtual method to get the type of the aircraft
     * @return The type of the aircraft as a string
     */
    virtual std::string getType() const = 0;

protected:
    std::string name;   ///< The name of the aircraft
    int health;         ///< The current health points of the aircraft
    int speed;          ///< The speed of the aircraft
    std::vector<Weapon> weapons;  ///< The weapons equipped on the aircraft
};

#endif // AIRCRAFT_H