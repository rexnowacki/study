// Christopher Nowacki
// CIS 278
// Polynomial
#include <iostream>
#include <vector>

using namespace std;

class Polynomial {
private:
    vector<int> coeffs; // Vector to hold coefficients

public:
    // Constructor
    Polynomial() = default;
    explicit Polynomial(const vector<int>& coefficients) : coeffs(coefficients) {
        // Remove trailing zeros
        while (!coeffs.empty() && coeffs.back() == 0) {
            coeffs.pop_back();
        }
    }

    // Copy constructor
    Polynomial(const Polynomial& other) : coeffs(other.coeffs) {}

    // Destructor
    ~Polynomial() = default;

    // Assignment operator
    Polynomial& operator=(const Polynomial& poly) {
        if (this != &poly) { 
            coeffs = poly.coeffs;
        }
        return *this;
    }

    // Addition operator
    Polynomial operator+(const Polynomial& poly) const {
        vector<int> result_coeffs(max(coeffs.size(), poly.coeffs.size()), 0);

        for (size_t i = 0; i < result_coeffs.size(); ++i) {
            int a = (i < coeffs.size()) ? coeffs[i] : 0;
            int b = (i < poly.coeffs.size()) ? poly.coeffs[i] : 0;
            result_coeffs[i] = a + b;
        }

        return Polynomial(result_coeffs);
    }

    // Subtraction operator
    Polynomial operator-(const Polynomial& poly) const {
        size_t max_size = max(coeffs.size(), poly.coeffs.size());
        vector<int> result_coeffs(max_size, 0);

        for (size_t i = 0; i < max_size; ++i) {
            int a = (i < coeffs.size()) ? coeffs[i] : 0;
            int b = (i < poly.coeffs.size()) ? poly.coeffs[i] : 0;
            result_coeffs[i] = a - b;
        }

        return Polynomial(result_coeffs);
    }

    // Multiplication operator
    Polynomial operator*(const Polynomial& poly) const {
        vector<int> result_coeffs(coeffs.size() + poly.coeffs.size() - 1, 0);

        for (size_t i = 0; i < coeffs.size(); ++i) {
            for (size_t j = 0; j < poly.coeffs.size(); ++j) {
                result_coeffs[i + j] += coeffs[i] * poly.coeffs[j];
            }
        }

        return Polynomial(result_coeffs);
    }

    // Addition assignment operator
    Polynomial& operator+=(const Polynomial& poly) {
        *this = *this + poly;
        return *this;
    }

    // Subtraction assignment operator
    Polynomial& operator-=(const Polynomial& poly) {
        *this = *this - poly;
        return *this;
    }

    // Multiplication assignment operator
    Polynomial& operator*=(const Polynomial& poly) {
        *this = *this * poly;
        return *this;
    }

    // Method to print polynomial
    void print() const {
        // Loop through coeffs from high to low (Degree)
        for (int i = coeffs.size() - 1; i >= 0; --i) {
            if (coeffs[i] != 0) { // Print only non-zero coefficients
                // Add plus sign before positive coeffs except for first term
                cout << (coeffs[i] > 0 && i != coeffs.size() - 1 ? "+" : "") << coeffs[i];
                if (i != 0) {
                    cout << "x^" << i << " ";
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Polynomial p1({1, 5, 4}); // Represents 4x^2 + 5x + 1
    Polynomial p2({0, 1, 2}); // Represents 2x^2 + x

    Polynomial p3 = p1 + p2; // Add two polynomials
    Polynomial p4 = p1 - p2; // Subtract two polynomials
    Polynomial p5 = p1 * p2; // Multiply two polynomials

    cout << "Polynomial A: ";
    p1.print();
    cout << "Polynomial B: ";
    p2.print();
    cout << "A + B: ";
    p3.print();
    cout << "A - B: ";
    p4.print();
    cout << "A * B: ";
    p5.print();

    return 0;
}
