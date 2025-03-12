#ifndef FIGHTER_H
#define FIGHTER_H

#include "Aircraft.h"

/**
 * @class Fighter
 * @brief Represents a fighter aircraft in the combat simulation
 * @inherits Aircraft
 */
class Fighter : public Aircraft {
public:
    /**
     * @brief Constructor for Fighter
     * @param name The name of the fighter aircraft
     * @param health The initial health points of the fighter
     * @param speed The speed of the fighter
     */
    Fighter(std::string name, int health, int speed);

    /**
     * @brief Overridden attack method for Fighter
     * @return The attack damage (random value between 20 and 80)
     */
    int attack() const override;

    /**
     * @brief Get the type of the aircraft
     * @return The string "Fighter"
     */
    std::string getType() const override { return "Fighter"; }
};

#endif // FIGHTER_H