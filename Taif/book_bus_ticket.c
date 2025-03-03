#include <stdio.h>

void book_ticket();
void busnumbers();

int main()
{
    busnumbers();
    book_ticket();
    return 0;
}

void book_ticket()
{
    int busnumber = 0;
    int seatbook = 0;
    int buses[5][2] = {{101, 50}, {102, 60}, {103, 70}, {104, 80}, {105, 90}};   // {bus number, total seats}

    while (1)
    {
        printf("\nEnter Bus number: ");
        if (scanf("%d", &busnumber) != 1)
        {
            while (getchar() != '\n');  // input buffer is cleared if anything other than integer is given as inout
            continue;
        }

        if (busnumber == 101 || busnumber == 102 || busnumber == 103 || busnumber == 104 || busnumber == 105)
        {
            int match = 0;
            for (int i = 0; i < 5; i++)  //  loop over buses[][] to get bus number
            {

                if (busnumber == buses[i][0])  // buses[i][0] bus number is accessed through indexes
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

                    if (seatbook <= buses[match][1]) // 50
                    {
                        printf("\nTotal Seats %d",buses[match][1]);
                        buses[match][1] = buses[match][1] - seatbook;
                        printf("\nSeats Booked %d", seatbook);
                        printf("\nSeatleft %d", buses[match][1]);
                        break;
                    }
                    else
                    {
                        printf("\nBooking seats greater than total seats %d", buses[match][1]);
                    }
                }
                break;
            }
        }
    }
}

void busnumbers()
{
    printf("Bus Numbers: 101 ");
    printf(" 102 ");
    printf(" 103 ");
    printf(" 104 ");
    printf(" 105 ");
}
