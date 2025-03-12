#ifndef STEALTH_H
#define STEALTH_H

#include "Aircraft.h"

class Stealth : public Aircraft {
public:
    Stealth(std::string name, int health, int speed);
    int attack() const override;
    std::string getType() const override { return "Stealth"; }
    void takeDamage(int damage) override;
};

#endif // STEALTH_H