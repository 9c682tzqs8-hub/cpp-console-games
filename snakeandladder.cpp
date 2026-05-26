#include <iostream>
#include <map>
#include <cstdlib>
#include <ctime>
using namespace std;

int rollDice() {
return (rand() % 6) + 1;

}

int main() {
srand(static_cast<unsigned int>(time(0)));


map<int, int> snakesLadders = {

    // Ladders

    {3, 22}, {5, 8}, {11, 26}, {20, 29},

    {27, 56}, {36, 44}, {51, 67}, {71, 92}, {80, 99},

    // Snakes

    {17, 4}, {19, 7}, {21, 9}, {43, 34},

    {54, 31}, {62, 18}, {64, 60}, {87, 24},

    {93, 73}, {95, 75}, {98, 79}

};


int player1 = 0, player2 = 0;

int currentPlayer = 1;

char choice;


cout << "===== Snake and Ladder Game =====\n";

cout << "Two players: Player 1 and Player 2\n";

cout << "Reach exactly 100 to win.\n\n";


while (true) {

    cout << "Player " << currentPlayer << ", press 'r' to roll dice: ";

    cin >> choice;


    if (choice != 'r' && choice != 'R') {

        cout << "Invalid input! Press only 'r' to roll.\n";

        continue;

    }


    int dice = rollDice();

    cout << "Player " << currentPlayer << " rolled: " << dice << "\n";


    int &position = (currentPlayer == 1) ? player1 : player2;


    if (position + dice <= 100) {

        position += dice;

        cout << "Player " << currentPlayer << " moved to: " << position << "\n";


        if (snakesLadders.find(position) != snakesLadders.end()) {

            int oldPos = position;

            position = snakesLadders[position];

            if (position > oldPos)

                cout << "Wow! Ladder! Climb up to: " << position << "\n";

            else

                cout << "Oops! Snake! Slide down to: " << position << "\n";

        }

    } else {

        cout << "Need exact number to reach 100. Stay at: " << position << "\n";

    }


    cout << "Positions -> Player 1: " << player1 << " | Player 2: " << player2 << "\n\n";


    if (position == 100) {

        cout << "🎉 Player " << currentPlayer << " wins the game!\n";

        break;

    }


    currentPlayer = (currentPlayer == 1) ? 2 : 1;

}


return 0;

}