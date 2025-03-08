#include <stdio.h>

void book_bus_ticket(); // Decalartion
void busdetails();

int main()
{
    busdetails(); // calling
    book_bus_ticket();
    return 0;
}

void book_bus_ticket() // user-defined function
{
    int busnumber = 0;
    int seatbook = 0;
    int buses[5][2] = {{101, 50}, {102, 60}, {103, 70}, {104, 80}, {105, 90}}; // {bus number, total seats}

    while (1)
    {
        printf("\n\nEnter valid Bus number: ");
        if (scanf("%d", &busnumber) != 1 || busnumber == '\n')
        {
            while (getchar() != '\n')
                ; // input buffer is cleared if anything other than integer is given as input
            continue;
        }

        int match = -1;

        for (int i = 0; i < 5; i++)
        {

            if (busnumber == buses[i][0])
            {
                match = i;
                break;
            }
        }

        if (match >= 0)
        {
            while (1)
            {
                printf("\nEnter number of seats to book: ");
                if (scanf("%d", &seatbook) != 1) // 2
                {
                    while (getchar() != '\n')
                        ;
                    continue;
                }

                if (seatbook <= 0) // If seat number is entered in negative, rest if-else are skipped and while loop keeps on running
                {
                    printf("Seats cannot be Negative or zero");
                    continue;
                }

                if (seatbook <= buses[match][1]) // 50
                {
                    printf("\nTotal Seats %d", buses[match][1]);
                    buses[match][1] = buses[match][1] - seatbook;
                    printf("\nSeats Booked %d", seatbook);
                    printf("\nSeats left %d", buses[match][1]);
                    break;
                }
                else
                {
                    printf("\nBooking seats greater than total seats %d", buses[match][1]);
                }
            }
            break;
        }
        else
        {
            printf("\n Invalid Bus Number ");
        }
    }
}

void busdetails()
{
    int buses[5][2] = {{101, 50}, {102, 60}, {103, 70}, {104, 80}, {105, 90}}; // {bus number, total seats}
    for (int i = 0; i < 5; i++)
    {
        printf("\nBus Number %d : seats %d", buses[i][0], buses[i][1]);
    }
}
