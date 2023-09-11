#include <stdio.h>

int main(void)
{
   float amount, total;
   #define TAX 0.05
   printf("Enter an amount: \n");
   scanf("%f", &amount);
   total = amount * (1 + TAX);
   printf("With tax added: %.2f\n", total);

   return 0;
}
