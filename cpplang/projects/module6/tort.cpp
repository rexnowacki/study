
#include <iostream>
#include <ctime>
#include <cstdlib>

const int MAX_SQUARES = 70;

void move_tortoise(int &position) {
    int chance = rand() % 10;
    if (chance < 5) {
        position += 3;
    } else if (chance < 7) {
        position -= 6;
        if (position < 0) position = 0;
    } else {
        position += 1;
    }
}

void move_hare(int &position) {
    int chance = rand() % 10;
    if (chance < 2) {
        // Sleep
    } else if (chance < 4) {
        position += 9;
    } else if (chance == 4) {
        position -= 12;
        if (position < 0) position = 0;
    } else if (chance < 8) {
        position += 1;
    } else {
        position -= 2;
        if (position < 0) position = 0;
    }
}

void print_race(int t_position, int h_position) {
    for (int i = 0; i < MAX_SQUARES; i++) {
        if (i == t_position && i == h_position) {
            std::cout << "OUCH!!!";
        } else if (i == t_position) {
            std::cout << "T";
        } else if (i == h_position) {
            std::cout << "H";
        } else {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    srand(time(0));  // Initialize random seed

    std::cout << "BANG !!!!!" << std::endl;
    std::cout << "AND THEY'RE OFF !!!!!" << std::endl;
    
    int t_position = 0;
    int h_position = 0;

    while (t_position < MAX_SQUARES && h_position < MAX_SQUARES) {
        move_tortoise(t_position);
        move_hare(h_position);
        print_race(t_position, h_position);
    }

    if (t_position >= MAX_SQUARES && h_position < MAX_SQUARES) {
        std::cout << "TORTOISE WINS!!! YAY!!!" << std::endl;
    } else if (h_position >= MAX_SQUARES && t_position < MAX_SQUARES) {
        std::cout << "Hare wins. Yuch." << std::endl;
    } else if (t_position >= MAX_SQUARES && h_position >= MAX_SQUARES) {
        std::cout << "It's a tie." << std::endl;
    }

    return 0;
}
