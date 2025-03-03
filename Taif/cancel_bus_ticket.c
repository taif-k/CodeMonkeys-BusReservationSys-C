#include <stdio.h> //Header file

void cancel_bus_ticket(); // Declaration
void busnumbers();  // bus chart

int main() // system defined fucntion
{
    cancel_bus_ticket(); // calling
    return 0;
}

void cancel_bus_ticket() // defination
{
    int busnumber = 0;
    int seatcancel = 0;
    int buses[5][2] = {{101, 60}, {102, 70}, {103, 80}, {104, 90}, {105, 100}};
    busnumbers();  // calling bus chart
    while (1)
    {
        printf("\nEnter Bus number: ");
        if (scanf("%d", &busnumber) != 1)
        {
            while (getchar() != '\n');
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
                while (1)
                {
                    printf("\nEnter number of seats to cancel: ");
                    if(scanf("%d", &seatcancel) != 1)
                    {
                        while(getchar() != '\n');  //   abcde
                        continue;
                    } // 2

                    if (seatcancel <= buses[match][1]) // ex: 2 <= 60
                    {
                        printf("\nTotal seats %d", buses[match][1]);
                        printf("\nSeats cancelled %d", seatcancel);
                        buses[match][1] = buses[match][1] - seatcancel;
                        printf("\nSeatleft %d", buses[match][1]);
                        break;
                    }
                    else
                    {
                        printf("\nCanceling seats greater than total seats %d", buses[match][1]);
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
    printf("Bus Numbers: 101 ");
    printf(" 102 ");
    printf(" 103 ");
    printf(" 104 ");
    printf(" 105 ");
}
