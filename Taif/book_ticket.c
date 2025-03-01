#include <stdio.h>

void bookticket();

int main()
{
    bookticket();
    return 0;
}

void bookticket()
{
    int busnumber = 0;
    int seatbook = 0;
    int buses[5][2] = {{101, 50}, {102, 50}, {103, 50}, {104, 50}, {105, 50}};

    while (1)
    {
        printf("\nEnter Bus number: ");
        if (scanf("%d", &busnumber) != 1)
        {
            while (getchar() != '\n')
                ;
            continue;
        }
        if (busnumber == 101 || busnumber == 102 || busnumber == 103 || busnumber == 104 || busnumber == 105)
        {
            int match = 0;
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
                printf("\nEnter number of seats to book: ");
                scanf("%d", &seatbook); // 2

                if (seatbook <= buses[match][1]) // 50
                {
                    buses[match][1] = buses[match][1] - seatbook;
                    printf("\nSeatleft %d", buses[match][1]);
                    break;
                }
                else
                {
                    printf("\nBooking seats greater than total seats %d", buses[match][1]);
                }
            }
        }
    }
}
