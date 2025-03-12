#ifndef BOMBER_H
#define BOMBER_H

#include "Aircraft.h"

/**
 * @class Bomber
 * @brief Represents a bomber aircraft in the combat simulation
 * @inherits Aircraft
 */
class Bomber : public Aircraft {
public:
    /**
     * @brief Constructor for Bomber
     * @param name The name of the bomber aircraft
     * @param health The initial health points of the bomber
     * @param speed The speed of the bomber
     * @param bombLoad The initial number of bombs the bomber carries
     */
    Bomber(std::string name, int health, int speed, int bombLoad);

    /**
     * @brief Overridden attack method for Bomber
     * @return The attack damage (100 if bombs are available, 0 otherwise)
     */
    int attack() const override;

    /**
     * @brief Get the type of the aircraft
     * @return The string "Bomber"
     */
    std::string getType() const override { return "Bomber"; }

    /**
     * @brief Check if the bomber has any bombs left
     * @return true if bombLoad is greater than 0, false otherwise
     */
    bool hasBombs() const;

private:
    mutable int bombLoad;  ///< The number of bombs remaining, mutable to allow modification in const functions
};

#endif // BOMBER_H