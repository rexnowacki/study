// Christopher Nowacki
// CIS 265
// Project Name

// Exercise #9: pp 274
// Write the following function:
// double inner_product(const double *a, const double *b, int n);
// a and b both point to arrays of length n. The function should return a 
// a[0] * b[0] + a[1] + b[1] + ... + a[n-1] * b[n-1]. Use pointer arithmetic,
// not subscripting to visit array elements.

#include <stdio.h>
double inner_product(const double *a, const double *b, int n) {

  double sum = 0.0;
  for (int i = 0; i < n; i++) {
    sum += *(a + i) * *(b + i);
  }
  return sum;
}

int main() {
  double arr1[] = {1.0, 2.0, 3.0, 4.0, 5.0};
  double arr2[] = {5.0, 4.0, 3.0, 2.0, 1.0};
  int length = sizeof(arr1) / sizeof(arr1[0]); // 40 / 8 = 5
  double result = inner_product(arr1, arr2, length);
  // Product should equal 35: 
  // (1.00*5.00) + (2.00*4.00) + (3.00*3.00) + (4.00*2.00) + (5.00*1.00)
  // == 5.00 + 8.00 + 9.00 + 8.00 + 5.00 == 35.00
  printf("Inner product: %f\n", result);

  return 0;
}
