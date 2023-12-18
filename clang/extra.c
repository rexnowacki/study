
#include <stdio.h>

int main() {
    unsigned short i, j, k;

    // Fragment (a)
    i = 8; j = 9;
    printf("Result of fragment (a): %d\n", i >> 1 + j >> 1);

    // Fragment (b)
    i = 1;
    printf("Result of fragment (b): %d\n", i & ~i);

    // Fragment (c)
    i = 2; j = 1; k = 0;
    printf("Result of fragment (c): %d\n", ~i & j ^ k);

    // Fragment (d)
    i = 7; j = 8; k = 9;
    printf("Result of fragment (d): %d\n", i ^ j & k);

    return 0;
}
