// Christopher Nowacki
// CIS 278
// Project Name

#include <iostream>
#include <iomanip>
using namespace std;

// Function to get the price of a product based on its number
double get_price(int product_num) {
  switch(product_num) {
    case 1: return 2.98;
    case 2: return 4.50;
    case 3: return 9.98;
    case 4: return 4.49;
    case 5: return 6.87;
    default: {
      cout << "Invalid product number." << endl;
      return 0.0; // return 0 if product number is invalid
    }
  }
}

int main() {
  int product_num;
  int quantity_sold;
  double total_sales = 0;

  while(true) {
    // Get user input
    cout << "Enter the product number (or -1 to quit): ";
    cin >> product_num;

    // Check for sentinel value -1
    if(product_num == -1) {
      break;
    }

    while(product_num > 0 && product_num < 5) {
    cout << "Enter the quantity sold: ";
    cin >> quantity_sold;
    break;
    }
    // Calculate the sales for this product and add to the total
    total_sales += get_price(product_num) * quantity_sold;
  }

  // Display the final results
  cout << fixed << setprecision(2); // Sets the precision to display dollars and cents
  cout << "The total retail value of all products sold: $" << total_sales << endl;

  return 0;
}
