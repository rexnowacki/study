// Christopher Nowacki
// CIS 280
// Tortoise and Hare SIMULATION Module 6 PRoject
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
const int MAX_SQUARES = 70;

void move_tortoise(int &position) {
    int chance = rand() % 10 + 1;
    if (chance <= 5) { // 50% fast plod
        position += 3;
    } else if (chance <= 7) { // 20% slip
        position -= 6;
        if (position < 0) position = 0; 
    } else { // 30% slow plod
        position += 1;
    }
}

void move_hare(int &position) {
    int chance = rand() % 10 + 1;
    if (chance <= 2) { // 20% chance: sleep (do nothing)
    } else if (chance <= 4) { // 20% big hop
        position += 9;
    } else if (chance == 5) { // 10% big slip
        position -= 12;
        if (position < 0) position = 0;
    } else if (chance <= 8) { // 30% small hop
        position += 1;
    } else { // 20% small slip
        position -= 2;
        if (position < 0) position = 0;
    }
}

// Display positions on "board"
void print_race(int t_position, int h_position) {
    for (int i = 0; i < MAX_SQUARES; i++) {
        if (i == t_position && i == h_position) { // collision detection
            cout << "OUCH!!!";
        } else if (i == t_position) {
            cout << "T";
        } else if (i == h_position) {
            cout << "H";
        } else {
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    srand(time(0));  // Initialize random seed

    // Starting message for race
    cout << "BANG !!!!!" << endl;
    cout << "AND THEY'RE OFF !!!!!" << endl;
   
    // Initialize positions for tortoise and hare
    int t_position = 0;
    int h_position = 0;

    // Continue race while position is less than max squares (70)
    while (t_position < MAX_SQUARES && h_position < MAX_SQUARES) {
        move_tortoise(t_position);
        move_hare(h_position);
        print_race(t_position, h_position);
    }

    // Determine and announce winner
    if (t_position >= MAX_SQUARES && h_position < MAX_SQUARES) {
        cout << "TORTOISE WINS!!! YAY!!!" << endl;
    } else if (h_position >= MAX_SQUARES && t_position < MAX_SQUARES) {
        cout << "Hare wins. Yuch." << endl;
    } else if (t_position >= MAX_SQUARES && h_position >= MAX_SQUARES) {
        cout << "It's a tie." << endl;
    }

    return 0;
}
