#include <stdio.h>

void checkstatus();
void busnumbers();
int main()
{

    busnumbers();
    checkstatus();
    return 0;
}

void checkstatus()
{

    while (1)
    {
        int busnumber = 0; // 101
        int seatbook = 0;
        int buses[5][2] = {{101, 50}, {102, 50}, {103, 50}, {104, 50}, {105, 50}};
        int fare[5] = {100, 150, 180, 200, 250};
        char sourcecity[5][10] = {"Delhi", "Noida", "Gurugram", "Haryana", "Faridabad"};
        char destinationcity[5][10] = {"Noida", "Gurugram", "Haryana", "Faridabad", "Agra"};

        printf("\nEnter Bus Number: ");
        if (scanf("%d", &busnumber) != 1) //  101  102..
        {
            while (getchar() != '\n')
                ;
            continue;
        }

        int count = 0;
        for (int i = 0; i < 5; i++)
        {
            if (buses[i][0] == busnumber) 
            {
                printf("\n Bus Number       :       %d", buses[i][0]);
                printf("\n Source           :       %s", sourcecity[i]);
                printf("\n Destination      :       %s", destinationcity[i]);
                printf("\n Total Seats      :       %d", buses[i][1]);
                printf("\n Fare             :       %d", fare[i]);
                count = 1;
                break;
            }
        }
    }
}

void busnumbers()
{
    printf(" Bus Numbers\n");
    printf(" 101");
    printf(" 102");
    printf(" 103");
    printf(" 104");
    printf(" 105");
}