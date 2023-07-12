#include <stdio.h>
#include <math.h>

int main()
{
    int choice;
    int accounts;
    int i;

    printf("Please enter the number of accounts: ");
    scanf("%d", &accounts);
    float Balances[accounts];
    printf("\n");

    for (int i = 0; i < accounts; i++)
    {
        do
        {
            printf("Please enter balance for account number %d: ", i + 1);
            scanf("%f", &Balances[i]);
            if (Balances[i] < 0)
            {
                printf("\n");
                printf("Balance cannot be a negative number. Try again.");
                printf("\n");
            }
        } while (Balances[i] <= 0);
    }
    printf("\n");

    do
    {
        printf("Please enter account number: ");
        scanf("%d", &i);
        if (i < 0 || i > accounts)
        {
            printf("\n");
            printf("Account doesnot exist. Try again: \n");
        }

    } while (i < 0 || i > accounts);

    printf("\n");

    do
    {
        printf("Current Account: %d \n", i);
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
            scanf("%f", &deposit);
            if (deposit < 0)
            {
                printf("\n");
                printf("Please enter a positive number. \n");
            }
            else
            {
                Balances[i - 1] += deposit;
                printf("\n");
                printf("Your total Balance is: %.2f \n", Balances[i - 1]);
            }
            break;

        case 2:
            float withdraw;
            printf("Please enter amount to withdraw: ");
            scanf("%f", &withdraw);
            if (withdraw < 0)
            {
                printf("Please enter a positive number. \n");
            }
            else if ((Balances[i - 1] - withdraw) < 0)
            {
                printf("You cannot withdraw that amount. try again \n");
            }
            else
            {
                Balances[i - 1] -= withdraw;
                printf("Your total Balance is: %.2f \n", Balances[i - 1]);
            }
            break;

        case 3:
            printf("Your total balance is: %.2f \n", Balances[i - 1]);
            break;

        case 4:
            int years;
            float result;
            float interest;
            printf("Please enter your desired interest rate");
            scanf("%f", &interest);
            printf("Please enter the number of years: ");
            scanf("%d", &years);
            result = Balances[i - 1] * pow((1 + interest), years);
            printf("Your balance will be %.2f", result);
            break;

        case 5:
            printf("Please enter account number: \n");
            scanf("%d", &i);
            break;

        case 6:
            for (int k = 0; k < accounts; k++)
            {
                printf("Your balance for account number %d: %f \n", k + 1, Balances[k]);
            }
            break;

        case 0:
            printf("Thankyou for using 'DoesNotexist' Bank. take care! \n");
            break;

        default:
            printf("Wrong input. Please try again! \n");
        }

    } while (choice != 0);

    return 0;
}
