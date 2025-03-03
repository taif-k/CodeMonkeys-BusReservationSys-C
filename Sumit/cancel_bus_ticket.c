#include <stdio.h>

void cancel_bus_ticket();

int main()
{
    cancel_bus_ticket();
}

void cancel_bus_ticket()
{
    int number;
    int cancel = 0;
    int total = 50;
    while (1)
    {
        printf("\nEnter Your Bus Number ");

        if (scanf("%d", &number) != 1) //
        {
            while (getchar() != '\n')
                ; // clear input (input buffer)
            continue;
        }

        while (1)
        {
            printf("\nEnter Numbers Seats Want You Cancel ");
            if (scanf("%d", &cancel) != 1)
            {
                while (getchar() != '\n')
                    continue;
                if (number == 101)
                {
                    printf("\nYour Bus Number:%d ", number);
                    printf("\nYou Canceled Tickets:%d ", cancel);
                    printf("\nTotal Number Of Seats Remaining %d ", total - cancel);
                    break;
                }
                else
                {
                    printf("\nEnter 101 bus number ");
                }
            }
        }
    }
}