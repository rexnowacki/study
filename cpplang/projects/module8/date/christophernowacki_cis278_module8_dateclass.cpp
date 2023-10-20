// Christopher Nowacki
// CIS 278
// Date Class
#include "date.h"

using namespace std;

// Test program
int main() {
    Date date1(5, 10, 2023);    // valid date
    Date date2(15, 10, 2023);   // invalid month

    cout << "Date 1: ";
    date1.displayDate();

    cout << "Date 2: ";
    date2.displayDate();

    // Test setters and getters
    date1.setMonth(8);
    date1.setDay(24);
    date1.setYear(2022);

    cout << "Updated Date 1: ";
    date1.displayDate();

    cout << "Date 1 month using getter: " << date1.getMonth() << endl;
    cout << "Date 1 day using getter: " << date1.getDay() << endl;
    cout << "Date 1 year using getter: " << date1.getYear() << endl;

    return 0;
}
