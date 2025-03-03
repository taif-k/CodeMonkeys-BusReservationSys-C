#include <stdio.h> //Header file

void cancel_bus_ticket(); // Declaration
void busnumbers();        // bus chart

int main() // system defined fucntion
{
    cancel_bus_ticket(); // calling
    return 0;
}

void cancel_bus_ticket() // defination
{
    int busnumber = 0;
    int seatcancel = 0;
    int buses[5][2] = {{101, 50}, {102, 60}, {103, 70}, {104, 80}, {105, 90}};
    busnumbers(); // calling bus chart
    while (1)
    {
        printf("\n\nEnter Bus number: ");
        if (scanf("%d", &busnumber) != 1) // checks input from user
        {
            while (getchar() != '\n');
            continue;
        }

        if (busnumber == 101 || busnumber == 102 || busnumber == 103 || busnumber == 104 || busnumber == 105)
        {
            int match = 0;
            for (int i = 0; i < 5; i++)
            {

                if (busnumber == buses[i][0]) // if input bus number matches from array bus number
                {
                    match = i;  // match is updated as the i changes
                    break;
                }
            }

            if (match >= 0)  // 0  1  2  3  4 (5 buses)
            {
                while (1)
                {
                    printf("\nEnter number of seats to cancel: ");
                    if (scanf("%d", &seatcancel) != 1)
                    {
                        while (getchar() != '\n'); //   abcde
                        continue;
                    } // 2

                    if (seatcancel < 0)
                    {
                        printf("\nSeats cannot be negative ");
                        continue;
                    }

                    if (seatcancel <= buses[match][1]) // ex: 2 <= 60
                    {
                        printf("\nBooked seats %d", buses[match][1]);
                        printf("\nSeats cancelled %d", seatcancel);
                        buses[match][1] = buses[match][1] - seatcancel;
                        printf("\nSeat Available %d", seatcancel);
                        break;
                    }
                    else
                    {
                        printf("\nCanceling seats greater than Booked seats %d", buses[match][1]);
                    }
                }
                break;
            }
        }
        else
        {
            printf("Please enter valid bus numbers");
        }
    }
}

void busnumbers()
{
    int buses[5][2] = {{101, 50}, {102, 60}, {103, 70}, {104, 80}, {105, 90}}; // {bus number, total seats}
    for (int i = 0; i < 5; i++)
    {
        printf("\nBus Number %d : seats Booked %d", buses[i][0], buses[i][1]);
    }
}
