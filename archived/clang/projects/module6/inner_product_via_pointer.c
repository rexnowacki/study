// Christopher Nowacki
// CIS 265
// Inner Product via Pointer

// Exercise #9: pp 274
// Write the following function:
// double inner_product(const double *a, const double *b, int n);
// a and b both point to arrays of length n. The function should return a 
// a[0] * b[0] + a[1] + b[1] + ... + a[n-1] * b[n-1]. Use pointer arithmetic,
// not subscripting to visit array elements.

#include <stdio.h>
double inner_product(const double *a, const double *b, int n) {

  double sum = 0.0;
  
  // Use pointer arithmetic to calculate product of elements 1a and 1b, etc
  for (int i = 0; i < n; i++) {
    sum += *(a + i) * *(b + i);
  }
  return sum;
}

int main() {
  int elements; // Number of elements each array will hold

  printf("Enter the number of elements for the lists: ");
  scanf("%d", &elements);
  
  double array_a[elements];
  double array_b[elements];

  // Input user for all elements of ARRAY A
  for (int i = 0; i < elements; ++i) {
    printf("Enter value %d for ARRAY A: ", i+1);
    scanf("%lf", &array_a[i]);
  }

  // Input user for all elemnts of ARRAY B
  for (int i = 0; i < elements; ++i) {
    printf("Enter value %d for ARRAY B: ", i+1);
    scanf("%lf", &array_b[i]);
  }

  double result = inner_product(array_a, array_b, elements);
  
  printf("Inner product: %f\n", result);

  return 0;
}
