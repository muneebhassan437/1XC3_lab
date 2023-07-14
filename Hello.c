#include <stdio.h>
int main() {
int number;
    printf("Enter a number: ");
    // Loop until a valid number is entered
    while (scanf("%d", &number) != 1) {
        // Clear the input buffer
        while (getchar() != '\n');
        printf("Invalid input. Enter a number: ");
    }
    printf("You entered: %d\n", number);
    return 0;
}