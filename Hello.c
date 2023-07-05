#include <stdio.h>
int main()
{
    int x = 7;
    printf(" Original value : %d\n", x);
    printf(" After x ++: %d\n", x++);    // Postfix increment
    printf(" After ++x: %d\n", ++x);     // Prefix increment
    printf(" After x - -: %d\n", x--); // Postfix decrement
    printf(" After --x: %d\n", --x);     // Prefix decrement
}

