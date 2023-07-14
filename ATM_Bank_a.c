#include <stdio.h>

int main()
{
    int choice;    // this variable stores the user's choice input (1,2,3,0).
    float balance; // this variable stores the balance of user's account

    printf("Enter your balance: ");
    // Loop until a valid number is entered
    while ((scanf("%f", &balance) != 1) || (balance < 0))
    {
        // Clear the input buffer
        while (getchar() != '\n')
            ;
        printf("Invalid input. Enter your balance: ");
    }

    // The do..while loop will ask the user to select its choice of operation untill the choice entered is 0
    do
    {
        printf("\n"); // skipped an extra line for more readability
        printf("Select an operation: \n");
        printf("1. Deposit \n");
        printf("2. Withdraw \n");
        printf("3. Check Balance \n");
        printf("0. Exit \n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        // The switch cases performs the operations based on user's inputs.
        switch (choice)
        {
        case 1:
            float deposit;
            printf("\n");
            printf("Please enter amount to deposit: ");
            while ((scanf("%f", &deposit) != 1) || (deposit < 0))
            {
                // Clear the input buffer
                while (getchar() != '\n')
                    ;
                printf("Invalid input. Enter amount to deposit: ");
            }
            balance += deposit;
            printf("\n");
            printf("Your new balance is: %.2f", balance);
            printf("\n");
            break;

        case 2:
            float withdraw;
            printf("\n");
            printf("Please enter amount to withdraw: ");
            while ((scanf("%f", &withdraw) != 1) || (withdraw < 0) || ((balance - withdraw) < 0))
            {
                // Clear the input buffer
                while (getchar() != '\n')
                    ;
                printf("Invalid input. Enter amount to withdraw: ");
            }
            balance -= withdraw;
            printf("\n");
            printf("Your new balance is: %.2f", balance);
            printf("\n");
            break;

        case 3:
            printf("\n");
            printf("Your total balance is: %.2f \n", balance);
            break;

        case 0:
            printf("\nThankyou for using 'DoesNotexist' Bank. take care! \n");
            break;

        default:
            printf("\nWrong input. Please try again! \n");
            break;
        }

    } while (choice != 0);

    return 0;
}
