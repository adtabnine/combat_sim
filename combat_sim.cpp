#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

class Weapon {
public:
    Weapon(std::string name, int damage) : name(name), damage(damage) {}
    std::string getName() const { return name; }
    int getDamage() const { return damage; }

private:
    std::string name;
    int damage;
};

class Aircraft {
public:
    Aircraft(std::string name, int health, int speed) 
        : name(name), health(health), speed(speed) {}

    void addWeapon(const Weapon& weapon) {
        weapons.push_back(weapon);
    }

    bool isAlive() const { return health > 0; }
    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getSpeed() const { return speed; }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
    }

    int attack() const {
        if (weapons.empty()) return 0;
        int weaponIndex = rand() % weapons.size();
        return weapons[weaponIndex].getDamage();
    }
private:
    std::string name;
    int health;
    int speed;
    std::vector<Weapon> weapons;
};

class CombatSimulation {
public:
    void addAircraft(const Aircraft& aircraft) {
        aircraft_list.push_back(aircraft);
    }

    void runSimulation() {
        std::cout << "Starting combat simulation...\n";
        while (aircraft_list.size() > 1) {
            performRound();
        }
        if (aircraft_list.size() == 1) {
            std::cout << "Winner: " << aircraft_list[0].getName() << "\n";
        } else {
            std::cout << "All aircraft destroyed. No winner.\n";
        }
    }

private:
    std::vector<Aircraft> aircraft_list;

    void performRound() {
        for (size_t i = 0; i < aircraft_list.size(); ++i) {
            if (!aircraft_list[i].isAlive()) continue;

            size_t target = rand() % aircraft_list.size();
            while (target == i || !aircraft_list[target].isAlive()) {
                target = rand() % aircraft_list.size();
            }

            int damage = aircraft_list[i].attack();
            aircraft_list[target].takeDamage(damage);

            std::cout << aircraft_list[i].getName() << " attacks " << aircraft_list[target].getName()
                      << " for " << damage << " damage.\n";
            std::cout << aircraft_list[target].getName() << " health: " << aircraft_list[target].getHealth() << "\n";

            if (!aircraft_list[target].isAlive()) {
                std::cout << aircraft_list[target].getName() << " has been destroyed!\n";
                aircraft_list.erase(aircraft_list.begin() + target);
            }
        }
        std::cout << "------- End of round -------\n";
    }
};

int main() {
    srand(time(0));  // Seed for random number generation
    Weapon missile("Missile", 50);
    Weapon machineGun("Machine Gun", 30);

    Aircraft f16("F-16", 100, 1500);
    f16.addWeapon(missile);
    f16.addWeapon(machineGun);

    Aircraft mig29("MiG-29", 120, 1700);
    mig29.addWeapon(missile);
    mig29.addWeapon(machineGun);

    Aircraft su35("Su-35", 140, 1600);
    su35.addWeapon(missile);
    su35.addWeapon(machineGun);
    CombatSimulation sim;
    sim.addAircraft(f16);
    sim.addAircraft(mig29);
    sim.addAircraft(su35);

    sim.runSimulation();

    return 0;
}