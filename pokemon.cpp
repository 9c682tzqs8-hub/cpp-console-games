#include <iostream> // For input and output operations
#include <string> // For using strings
#include <cstdlib> // For random number generation
#include <ctime> // For seeding random number generation
using namespace std; // Standard namespace 


struct Move {
    string name;
    int power;
};

class Pokemon {
public:
    string name;
    int hp;
    int max_hp;
    Move move1;
    Move move2;

    Pokemon(string n, int h, Move m1, Move m2) 
        : name(n), hp(h), max_hp(h), move1(m1), move2(m2) {}

    bool isFainted() const {
        return hp <= 0;
    }

    void takeDamage(int damage) {
        hp -= damage;
        if (hp < 0) {
            hp = 0;
        }
    }
};

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

void printStatus(const Pokemon& p1, const Pokemon& p2) {
    cout << "================================\n";
    cout << p2.name << " HP: " << p2.hp << " / " << p2.max_hp << "\n\n";
    cout << p1.name << " HP: " << p1.hp << " / " << p1.max_hp << "\n";
    cout << "================================\n";
}

void battle(Pokemon& player, Pokemon& enemy) {
    clearScreen();
    cout << "A wild " << enemy.name << " appeared!\n\n";

    while (!player.isFainted() && !enemy.isFainted()) {
        printStatus(player, enemy);

        cout << "Choose a move:\n";
        cout << "1. " << player.move1.name << " (Power: " << player.move1.power << ")\n";
        cout << "2. " << player.move2.name << " (Power: " << player.move2.power << ")\n";
        cout << "> ";

        int choice;
        cin >> choice;
        clearScreen();

        int pDamage = 0;
        string pMoveName = "";

        if (choice == 1) {
            pDamage = player.move1.power;
            pMoveName = player.move1.name;
        } else {
            pDamage = player.move2.power;
            pMoveName = player.move2.name;
        }

        cout << player.name << " used " << pMoveName << "!\n";
        enemy.takeDamage(pDamage);

        if (enemy.isFainted()) {
            cout << "\n" << enemy.name << " fainted!\n";
            cout << "You won the battle!\n";
            break;
        }

        int eChoice = (rand() % 2) + 1;
        int eDamage = 0;
        string eMoveName = "";

        if (eChoice == 1) {
            eDamage = enemy.move1.power;
            eMoveName = enemy.move1.name;
        } else {
            eDamage = enemy.move2.power;
            eMoveName = enemy.move2.name;
        }

        cout << enemy.name << " used " << eMoveName << "!\n\n";
        player.takeDamage(eDamage);

        if (player.isFainted()) {
            cout << "\n" << player.name << " fainted!\n";
            cout << "You blacked out...\n";
            break;
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    Move tackle{"Tackle", 15};
    Move thunderbolt{"Thunderbolt", 35};
    Move scratch{"Scratch", 15};
    Move ember{"Ember", 30};
    Move waterGun{"Water Gun", 30};
    Move bite{"Bite", 20};

    Pokemon pikachu("Pikachu", 100, tackle, thunderbolt);
    Pokemon charmander("Charmander", 110, scratch, ember);
    Pokemon squirtle("Squirtle", 120, tackle, waterGun);

    clearScreen();
    cout << "Welcome to the C++ Pokemon Arena!\n";
    cout << "Choose your starter:\n";
    cout << "1. Pikachu\n";
    cout << "2. Charmander\n";
    cout << "3. Squirtle\n";
    cout << "> ";

    int starterChoice;
    cin >> starterChoice;

    Pokemon* player = nullptr;
    Pokemon* opponent = nullptr;

    if (starterChoice == 1) {
        player = &pikachu;
        opponent = &squirtle;
    } else if (starterChoice == 2) {
        player = &charmander;
        opponent = &pikachu;
    } else {
        player = &squirtle;
        opponent = &charmander;
    }

    battle(*player, *opponent);

    return 0;
}