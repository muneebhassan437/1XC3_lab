#include <stdio.h>
#include <math.h>
int main()
{
    int choice;     // this variable stores the user's choice input (1,2,3,0).
    float balance;  // this variable stores the balance of user's account
    float interest; // this variable stores the interest rate provided by user.

    printf("Enter your interest rate between 0 and 1: ");
    // Loop until a valid number is entered
    while ((scanf("%f", &interest) != 1) || (interest < 0) || (interest > 1))
    {
        // Clear the input buffer
        while (getchar() != '\n')
            ;
        printf("Invalid input. Enter your interest rate between 0 and 1: ");
    }

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
        printf("\n");
        printf("Select an operation: \n");
        printf("1. Deposit \n");
        printf("2. Withdraw \n");
        printf("3. Check Balance \n");
        printf("4. Future Balance Using Interest Rate \n");
        printf("0. Exit \n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

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
            printf("\nYour total balance is: %.2f \n", balance);
            break;

        case 4:
            int years;
            float result;
            printf("\n");
            printf("Please enter number of years: ");
            while (scanf("%d", &years) != 1)
            {
                // Clear the input buffer
                while (getchar() != '\n')
                    ;
                printf("Invalid input. Enter number of years: ");
            }
            result = balance * pow((1 + interest), years);
            printf("\nYour balance will be %.2f", result);
            printf("\n");
            break;

        case 0:
            printf("\nThankyou for using 'DoesNotexist' Bank. take care! \n");
            break;

        default:
            printf("\nWrong input. Please try again! \n");
        }

    } while (choice != 0);

    return 0;
}