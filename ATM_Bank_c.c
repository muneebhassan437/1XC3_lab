#include <stdio.h>
#include <math.h>

int main()
{
    float interest;
    int choice;
    int i;
    int accounts;

    printf("Enter your interest rate between 0 and 1: ");
    // Loop until a valid number is entered
    while ((scanf("%f", &interest) != 1) || (interest < 0) || (interest > 1))
    {
        // Clear the input buffer
        while (getchar() != '\n')
            ;
        printf("Invalid input. Enter your interest rate between 0 and 1: ");
    }

    printf("\nEnter the number of accounts ");
    // Loop until a valid number is entered
    while ((scanf("%d", &accounts) != 1) || (accounts < 0))
    {
        // Clear the input buffer
        while (getchar() != '\n')
            ;
        printf("Invalid input. Enter the number of accounts: ");
    }

    // initialises the array with number of arrays equal to accounts
    float Balances[(accounts)];
    printf("\n");

    for (int i = 0; i < accounts; i++)
    {
        printf("Please enter balance for account number %d: ", i + 1);
        // Loop until a valid number is entered
        while ((scanf("%f", &Balances[i]) != 1) || (Balances[i] < 0))
        {
            while (getchar() != '\n')
                ;
            printf("Invalid input. Enter balance for account number %d: ", i + 1);
        }
    }
    printf("\n");

    printf("Please enter account number: ");
    // Loop until a valid number is entered
    while ((scanf("%d", &i) != 1) || (i > accounts) || (i < 1))
    {
        while (getchar() != '\n')
            ;
        printf("Invalid input. Enter account number: ");
    }
    printf("\n");

    do
    {
        printf("\nCurrent Account: %d \n", i);
        printf("\n");
        printf("Select an operation: \n");
        printf("1. Deposit \n");
        printf("2. Withdraw \n");
        printf("3. Check Balance \n");
        printf("4. Future Balance Using Interest Rate \n");
        printf("5. Switch Account \n");
        printf("6. Display All Balances \n");
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
            Balances[i - 1] += deposit;
            printf("\n");
            printf("Your new balance for account number %d: %.2f", i, Balances[i - 1]);
            printf("\n");
            break;

        case 2:
            float withdraw;
            printf("\n");
            printf("Please enter amount to withdraw: ");
            while ((scanf("%f", &withdraw) != 1) || (withdraw < 0) || ((Balances[i - 1] - withdraw) < 0))
            {
                // Clear the input buffer
                while (getchar() != '\n')
                    ;
                printf("Invalid input. Enter amount to withdraw: ");
            }
            Balances[i - 1] -= withdraw;
            printf("\n");
            printf("Your new balance for account number %d: %.2f", i, Balances[i - 1]);
            printf("\n");
            break;

        case 3:
            printf("\nYour total balance for account number %d: %.2f \n",i, Balances[i - 1]);
            printf("\n");
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
            result = Balances[i - 1] * pow((1 + interest), years);
            printf("\nYour balance for account number %d will be: %.2f", i, result);
            printf("\n");
            break;

        case 5:
            printf("\nPlease enter account number: ");
            scanf("%d", &i);
            break;

        case 6:
            printf("\n");
            for (int k = 0; k < accounts; k++)
            {
                printf("Your balance for account number %d: %.2f \n", k + 1, Balances[k]);
            }
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
