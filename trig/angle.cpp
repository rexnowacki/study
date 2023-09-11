
#include <iostream>

// Function to find the smallest positive coterminal angle
int positive_angle(int angle) {
    while(angle >= 360) {
        angle -= 360;
    }
    while(angle < 0) {
        angle += 360;
    }
    return angle;
}

int main() {
    int angle;

    std::cout << "Please enter an angle: ";
    std::cin >> angle;

    angle = positive_angle(angle);

    if(angle == 0) {
        std::cout << "The smallest positive coterminal angle is: 0 or 360" << std::endl;
    } else {
        std::cout << "The smallest positive coterminal angle is: " << angle << std::endl;
    }

    return 0;
}

