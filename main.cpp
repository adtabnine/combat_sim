#include "CombatSimulation.h"
#include "Fighter.h"
#include "Bomber.h"
#include "Stealth.h"
#include <memory>
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(0));  // Seed for random number generation

    CombatSimulation sim;

    sim.addAircraft(std::make_shared<Fighter>("F-16", 100, 1500));
    sim.addAircraft(std::make_shared<Fighter>("MiG-29", 120, 1700));
    sim.addAircraft(std::make_shared<Bomber>("B-52", 200, 1000, 10));  // Added bombLoad parameter
    sim.addAircraft(std::make_shared<Stealth>("F-22", 90, 1600));

    sim.runSimulation(20);  // Run for a maximum of 20 rounds

    return 0;
}