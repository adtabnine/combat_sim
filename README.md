# Combat Simulation Project

## Overview
This project simulates aerial combat between different types of aircraft. It's implemented in C++ and demonstrates object-oriented programming concepts such as inheritance and polymorphism.

## Project Structure
The project consists of the following main components:

- `Aircraft`: Base class for all aircraft types
- `Fighter`: Derived class representing fighter aircraft
- `Bomber`: Derived class representing bomber aircraft
- `Stealth`: Derived class representing stealth aircraft
- `CombatSimulation`: Class that manages the combat simulation

## Class Descriptions

### Aircraft
Base class for all aircraft types. It contains common properties like name, health, and speed.

### Fighter
Represents a fighter aircraft. It has a random attack damage between 20 and 80.

### Bomber
Represents a bomber aircraft. It has a fixed attack damage of 100 but limited bomb load.

### Stealth
Represents a stealth aircraft. It has a random attack damage between 40 and 60.

### CombatSimulation
Manages the combat simulation, including adding aircraft, running rounds, and determining the winner.

## How to Compile and Run

1. Ensure you have a C++ compiler installed (e.g., g++)
2. Navigate to the project directory in the terminal
3. Compile the project using the following command:
4. Run the simulation:

## Sample Output
Starting combat simulation...
===== Round 1 =====
F-16 (Fighter) attacks B-52 (Bomber) for 78 damage.
B-52 health: 122
MiG-29 (Fighter) attacks F-16 (Fighter) for 67 damage.
F-16 health: 33
B-52 (Bomber) attacks MiG-29 (Fighter) for 100 damage.
MiG-29 health: 20
F-22 (Stealth) attacks MiG-29 (Fighter) for 55 damage.
MiG-29 health: 0
MiG-29 has been destroyed!
===== Round 2 =====
F-16 (Fighter) attacks F-22 (Stealth) for 36 damage.
F-22 health: 90
B-52 (Bomber) attacks F-16 (Fighter) for 100 damage.
F-16 health: 0
F-16 has been destroyed!
F-22 (Stealth) attacks B-52 (Bomber) for 44 damage.
B-52 health: 78
===== Round 3 =====
B-52 (Bomber) attacks F-22 (Stealth) for 100 damage.
F-22 health: 0
F-22 has been destroyed!
Winner: B-52 (Bomber)


## Future Improvements
- Add more aircraft types
- Implement different weapons for each aircraft type
- Add environmental factors affecting combat
- Create a user interface for easier simulation setup
- Implement more complex combat mechanics (dodging, critical hits)

## Contributing
Feel free to fork this project and submit pull requests with improvements or new features.

## License
[Insert your chosen license here]