#include <stdio.h>
#include <ctype.h>

int main()
{
  char lower;
  char upper;

  printf("Lowercase: ");
  scanf("%c", &lower);
  upper = toupper(lower);
  printf("Uppercase: %c\n", upper);

  return 0;
}
