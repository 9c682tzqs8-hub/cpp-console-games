# cpp-console-games
A collection of interactive, terminal-based games (Pokémon, Snake &amp; Ladder, Tic-Tac-Toe) built in C++ to demonstrate core logic, control flow, and Object-Oriented Programming
# C++ Console Games Suite 🎮

A collection of interactive, terminal-based games written entirely in C++. This repository serves as a showcase of core programming concepts, including Object-Oriented Programming (OOP), state management, random number generation, and game loop mechanics.

## 🕹️ Projects Included

### 1. Pokémon Arena (`pokemon.cpp`)
A turn-based battle simulator inspired by classic Pokémon games.
* **Features:** * Playable starter selection (Pikachu, Charmander, Squirtle).
  * Unique move sets and power scaling.
  * Health point (HP) tracking and randomized enemy AI moves.
  * Implemented using C++ Structs and Classes for organized entity management.

### 2. Snake and Ladder (`snakeandladder.cpp`)
A digital recreation of the classic board game for two players.
* **Features:**
  * Dice roll mechanics using `rand()`.
  * Grid navigation mapped via `std::map` for efficient ladder climbs and snake bites.
  * Exact-roll win conditions to reach square 100.

### 3. Tic-Tac-Toe (`tictactoegame.cpp`)
The timeless 3x3 grid game, completely playable in the terminal.
* **Features:**
  * Two-player turn-based system.
  * Real-time board rendering and input validation (prevents overwriting occupied cells).
  * Automated win-state and draw-state detection algorithms.


Concepts Demonstrated
Control Structures: Complex while loops and conditional logic for game states.
Data Structures: Utilization of arrays, pointers, and the C++ Standard Template Library (std::map).
Object-Oriented Design: Encapsulation of data and behavior within C++ classes.
Memory & Input: Handling standard input/output streams and basic terminal clearing techniques.


## 🚀 Getting Started

### Prerequisites
To compile and run these games, you will need a C++ compiler installed on your system (such as GCC/G++ or Clang).

### Compilation & Execution

Open your terminal, navigate to the repository folder, and compile the game you want to play using `g++`:

**For Pokémon Arena:**
```bash
g++ pokemon.cpp -o pokemon
./pokemon
```

**For Snake and Ladder:**
```bash
g++ snakeandladder.cpp -o snake
./snake
```

**For Tic-Tac-Toe:**
```bash
g++ tictactoegame.cpp -o tictactoe
./tictactoe
```
