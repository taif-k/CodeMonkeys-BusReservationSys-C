#include <stdio.h>

void cancel_bus_ticket(); // Declaration
void busnumbers();

int main() // system define
{
    busnumbers();
    cancel_bus_ticket(); // calling
}

void cancel_bus_ticket() // user define function
{

    int number;
    int cancel_seat = 0;
    int booked_book = 50;
    while (1)
    {
        printf("\nEnter valid Your Bus Number ");

        if (scanf("%d", &number) != 1)
        {
            while (getchar() != '\n') //  if a character is given as input ,input will be cleared
                ;                     // clear input (input buffer)
            continue;
        }
        if (number == 101 || number == 102 || number == 103)
        {
            while (1)
            {
                printf("\nEnter Seats you want to Cancel ");
                if (scanf("%d", &cancel_seat) != 1)
                {
                    while (getchar() != '\n')
                        ;
                    continue;
                }

                if (cancel_seat < 0 || cancel_seat > booked_book)
                {
                    continue;
                }


                if (number == 101)
                {
                    printf("\nYour Bus Number:%d ", number);
                    printf("\nYou Canceled Tickets:%d ", cancel_seat);
                    printf("\nTotal Number Of Seats Remaining %d ", booked_book - cancel_seat);
                    break;
                }
                else if (number == 102)
                {
                    printf("\nYour Bus Number:%d ", number);
                    printf("\nYou Canceled Tickets:%d ", cancel_seat);
                    printf("\nTotal Number Of Seats Remaining %d ", booked_book - cancel_seat);
                    break;
                }
                else if (number == 103)
                {
                    printf("\nYour Bus Number:%d ", number);
                    printf("\nYou Canceled Tickets:%d ", cancel_seat);
                    printf("\nTotal Number Of Seats Remaining %d ", booked_book - cancel_seat);
                    break;
                }
                else
                {
                    printf("\nEnter valid bus number ");
                }
            }
            break;
        }
    }
}

void busnumbers()
{
    printf(" Bus numbers: 101 ");
    printf(" Bus numbers: 102 ");
    printf(" Bus numbers: 103 ");
}