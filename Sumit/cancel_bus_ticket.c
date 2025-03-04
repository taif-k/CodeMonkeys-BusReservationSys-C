#include <stdio.h> //Headerfile

void cancel_bus_ticket();

int main() // Function
{
    cancel_bus_ticket(); // Main function
}

void cancel_bus_ticket() // Function
{
    int number;
    int cancel = 0;
    int total = 50;
    while (1) // While Loop
    {
        printf("\nEnter Your Bus Number ");

        if (scanf("%d", &number) != 1) //
        {
            while (getchar() != '\n') 
                ; // clear input (input buffer)
            continue;
        }

        while (1)//While Loop
        {
            printf("\nEnter Seats you want to Cancel ");
            if (scanf("%d", &cancel) != 1)
            {
                while (getchar() != '\n') // clear input 
                    ;
                continue;
            }
            if (number == 101) //if condition
            {
                printf("\nYour Bus Number:%d ", number);
                printf("\nYou Canceled Tickets:%d ", cancel);
                printf("\nTotal Number Of Seats Remaining %d ", total - cancel);
                break;
            }
            else if (number == 102) // esle if condition 
            {
                printf("\nYour Bus Number:%d ", number);
                printf("\nYou Canceled Tickets:%d ", cancel);
                printf("\nTotal Number Of Seats Remaining %d ", total - cancel);
                break;
            }
            else if (number == 103) // else if condition
            {
                printf("\nYour Bus Number:%d ", number);
                printf("\nYou Canceled Tickets:%d ", cancel);
                printf("\nTotal Number Of Seats Remaining %d ", total - cancel);
                break;
            }
            else // else condition
            {
                printf("\nEnter valid bus number ");
            } 
        }
        break;
    }
}