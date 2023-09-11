
#include <iostream>
#include <cmath> // for M_PI

// Function to find the smallest positive coterminal angle in degrees
int positive_angle_degrees(int angle) {
    while(angle >= 360) {
        angle -= 360;
    }
    while(angle < 0) {
        angle += 360;
    }
    return angle;
}

// Function to find the smallest positive coterminal angle in radians
double positive_angle_radians(double angle) {
    while(angle >= 2*M_PI) {
        angle -= 2*M_PI;
    }
    while(angle < 0) {
        angle += 2*M_PI;
    }
    return angle;
}

int main() {
    int choice;

    std::cout << "Choose the unit: 1 for degrees, 2 for radians: ";
    std::cin >> choice;

    if (choice == 1) {
        int angle_deg;
        std::cout << "Please enter an angle in degrees: ";
        std::cin >> angle_deg;

        angle_deg = positive_angle_degrees(angle_deg);

        if(angle_deg == 0) {
            std::cout << "The smallest positive coterminal angle is: 0 or 360 degrees" << std::endl;
        } else {
            std::cout << "The smallest positive coterminal angle is: " << angle_deg << " degrees" << std::endl;
        }
    } else if (choice == 2) {
        double angle_rad;
        std::cout << "Please enter an angle in radians: ";
        std::cin >> angle_rad;

        angle_rad = positive_angle_radians(angle_rad);

        if(angle_rad == 0) {
            std::cout << "The smallest positive coterminal angle is: 0 or 2π radians" << std::endl;
        } else {
            std::cout << "The smallest positive coterminal angle is: " << angle_rad << " radians" << std::endl;
        }
    } else {
        std::cout << "Invalid choice. Exiting program." << std::endl;
    }

    return 0;
}
