#include "CombatSimulation.h"
#include <iostream>
#include <algorithm>

void CombatSimulation::addAircraft(std::shared_ptr<Aircraft> aircraft) {
    aircraft_list.push_back(aircraft);
}

void CombatSimulation::runSimulation(int maxRounds) {
    std::cout << "Starting combat simulation...\n";
    int roundNumber = 1;
    while (!isSimulationOver() && roundNumber <= maxRounds) {
        std::cout << "\n===== Round " << roundNumber << " =====\n";
        performRound(roundNumber);
        roundNumber++;
    }

    if (roundNumber > maxRounds) {
        std::cout << "\nSimulation reached maximum number of rounds.\n";
    }
    if (aircraft_list.size() == 1) {
        std::cout << "\nWinner: " << aircraft_list[0]->getName() << " (" << aircraft_list[0]->getType() << ")\n";
    } else if (aircraft_list.empty()) {
        std::cout << "\nAll aircraft destroyed. No winner.\n";
    } else {
        std::cout << "\nMultiple aircraft survived. It's a draw.\n";
    }
}

void CombatSimulation::performRound(int roundNumber) {
    for (size_t i = 0; i < aircraft_list.size(); ++i) {
        if (!aircraft_list[i]->isAlive()) continue;

        // Find a random target that is not the current aircraft and is alive

        std::vector<size_t> possibleTargets;
        for (size_t j = 0; j < aircraft_list.size(); ++j) {
            if (i != j && aircraft_list[j]->isAlive()) {
                possibleTargets.push_back(j);
            }
        }

        if (!possibleTargets.empty()) {
            size_t targetIndex = possibleTargets[rand() % possibleTargets.size()];
            int damage = aircraft_list[i]->attack();
            aircraft_list[targetIndex]->takeDamage(damage);

            std::cout << aircraft_list[i]->getName() << " (" << aircraft_list[i]->getType() << ") attacks "
                      << aircraft_list[targetIndex]->getName() << " (" << aircraft_list[targetIndex]->getType() << ") for "
                      << damage << " damage.\n";
            std::cout << aircraft_list[targetIndex]->getName() << " health: " << aircraft_list[targetIndex]->getHealth() << "\n";

            if (!aircraft_list[targetIndex]->isAlive()) {
                std::cout << aircraft_list[targetIndex]->getName() << " has been destroyed!\n";
            }
        }
    }

    // Remove destroyed aircraft
    aircraft_list.erase(
        std::remove_if(aircraft_list.begin(), aircraft_list.end(),
            [](const std::shared_ptr<Aircraft>& a) { return !a->isAlive(); }),
        aircraft_list.end()
    );
}

bool CombatSimulation::isSimulationOver() const {
    return aircraft_list.size() <= 1;
}