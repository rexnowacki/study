// Christopher Nowacki
// CIS 265
// 5x5 Array 
//
#include <stdio.h>

int main() {
  int matrix[5][5]; // Multi-dimensional array to store integers
  int row_total[5] = {0}; // Array for row total, 5 elements
  int col_total[5] = {0}; // Array for column total, 5 elements
  int i, j; // i for rows, j for columns

  // Input the matrix values from user
  for (i = 0; i<5; i++) {
    printf("Enter 5 numbers for row %d separated by spaces: ", i + 1);
    for (j = 0; j < 5; j++) {
      scanf("%d", &matrix[i][j]); // Stores in "matrix" at current row/column
    }
  }

  // Calculate the sum for each row
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      row_total[i] = row_total[i] + matrix[i][j];
    }
  }
  // Calculate the sum for each column
  for (j = 0; j < 5; j++) {
    for (i = 0; i < 5; i++) {
      col_total[j] = col_total[j] + matrix[i][j];
    }
  }
  // Dispplay row totals
  printf("\nRow totals: ");
  for (i = 0; i < 5; i++) {
    printf("%d ", row_total[i]);
  }
  // Display column totals
  printf("\nColumn totals: ");
    for (j = 0; j < 5; j++) {
    printf("%d ", col_total[j]);
  }
  printf("\n");
  return 0;
}
