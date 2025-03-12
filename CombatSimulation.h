#ifndef COMBAT_SIMULATION_H
#define COMBAT_SIMULATION_H

#include <vector>
#include <memory>
#include "Aircraft.h"

class CombatSimulation {
public:
    void addAircraft(std::shared_ptr<Aircraft> aircraft);
    void runSimulation(int maxRounds = 100);

private:
    std::vector<std::shared_ptr<Aircraft>> aircraft_list;
    void performRound(int roundNumber);
    bool isSimulationOver() const;
};

#endif // COMBAT_SIMULATION_H