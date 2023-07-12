#include <stdio.h>
#include <math.h>
int main()
{
    int choice;
    float balance;

    printf("Please enter your initial balance: ");
    scanf("%f", &balance);

    do
    {
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
            printf("Please enter amount to deposit: ");
            scanf("%f", &deposit);
            if (deposit < 0)
            {
                printf("Please enter a positive number. \n");
            }
            else
            {
                balance += deposit;
                printf("Your total Balance is: %.2f \n", balance);
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
            else if ((balance - withdraw) < 0)
            {
                printf("You cannot withdraw that amount. try again \n");
            }
            else
            {
                balance -= withdraw;
                printf("Your total Balance is: %.2f \n", balance);
            }
            break;

        case 3:
            printf("Your total balance is: %.2f \n", balance);
            break;

        case 4:
            int years;
            float result;
            const float interest;
            printf("Please enter your desired interest rate");
            scanf("%f",&interest);
            printf("Please enter the number of years: ");
            scanf("%d",&years);
            result = balance * pow((1 + interest), years);
            printf("Your balance will be %.2f", result);
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