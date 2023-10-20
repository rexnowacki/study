#include <iostream>

using namespace std;

class Date {
private:
    int month;
    int day;
    int year;

public:
    // Constructor with 3 parameters to initialize data members
    Date(int m, int d, int y) : month(m), day(d), year(y) {
        // Ensure month is in range 1-12; if not, set to 1
        if (month < 1 || month > 12) {
            month = 1;
        }
    }

    // Setter for month
    void setMonth(int m) {
        if (m < 1 || m > 12) {
            month = 1;
        } else {
            month = m;
        }
    }

    // Getter for month
    int getMonth() const {
        return month;
    }

    // Setter for day
    void setDay(int d) {
        day = d;
    }

    // Getter for day
    int getDay() const {
        return day;
    }

    // Setter for year
    void setYear(int y) {
        year = y;
    }

    // Getter for year
    int getYear() const {
        return year;
    }

    // Member function to display the date
    void displayDate() const {
        cout << month << "/" << day << "/" << year << endl;
    }
};
