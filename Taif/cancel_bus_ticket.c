#include <stdio.h> 

void cancel_bus_ticket(); 
void busnumbers();       

int main() 
{
    int alreadybooked[5] = {0, 0, 0, 0, 0};

    cancel_bus_ticket(alreadybooked); 
    return 0;
}

void cancel_bus_ticket(int booked[5]) 
{
    int busnumber = 0;
    int seatcancel = 0;
    int buses[5][2] = {{101, 50}, {102, 60}, {103, 70}, {104, 80}, {105, 90}};

    busnumbers(); // calling bus chart
    while (1)
    {
        printf("\n\nEnter valid Bus number: ");
        if (scanf("%d", &busnumber) != 1) // checks input from user
        {
            while (getchar() != '\n')
                ;
            continue;
        }

        int match = -1;
        for (int i = 0; i < 5; i++)
        {

            if (busnumber == buses[i][0]) // if input bus number matches from array bus number
            {
                match = i; // match is updated as the i changes
                break;
            }
        }

        if (match >= 0) // 0  1  2  3  4 (5 buses)
        {
            while (1)
            {
                printf("\n\nEnter number of seats to cancel: ");
                if (scanf("%d", &seatcancel) != 1)
                {
                    while (getchar() != '\n')
                        ; //   abcde
                    continue;
                } // 2

                if (seatcancel < 0)
                {
                    printf("\nSeats cannot be negative ");
                    continue;
                }

                if (seatcancel <= booked[match]) 
                {
                    booked[match] = booked[match] - seatcancel;
                    buses[match][1] = buses[match][1] + seatcancel;
                    printf("\nSeats Cancelled: %d", seatcancel);
                    printf("\nSeats Available: %d", buses[match][1]);
                    break;
                }
                else
                {
                    printf("\nEnter 0 seats to cancel, Total seats %d", buses[match][1]);
                }
            }
            break;
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
        printf("\nBus Number %d : Total Seats %d", buses[i][0], buses[i][1]);
    }
    printf("\n\nPlease enter 0 seats to cancel because nothing is booked yet");
}
