#include <stdio.h>

int main(){
  int first, second, third, fourth;
  int first_sum, sec_sum, total, check_digit;
  int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5;
  printf("Enter first (single) digit: ");
  scanf("%1d", &d);
  printf("Enter first group of five digits: ");
  scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);
  printf("Enter second group of five digits: ");
  scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);
  
  // Determine check digit
  first_sum = d + i2 + i4 +j1 +j3 +j5;
  sec_sum = i1 + i3 + i5 + j2 +j4;
  total = ((3 * first_sum) + sec_sum - 1) % 10;
  check_digit = 9 - total;
  printf("The check digit is: %d\n", check_digit);
}
