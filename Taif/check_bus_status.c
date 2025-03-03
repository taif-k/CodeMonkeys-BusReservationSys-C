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
    int fare[5] = {100, 150, 180, 200, 250};
    int buses[5][2] = {{101, 50}, {102, 50}, {103, 50}, {104, 50}, {105, 50}};
    char sourcecity[5][10] = {"Delhi", "Noida", "Gurugram", "Haryana", "Faridabad"};
    char destinationcity[5][10] = {"Noida", "Gurugram", "Haryana", "Faridabad", "Agra"};

    while (1)
    {
        int busnumber = 0;

        printf("\nEnter Bus Number: ");
        if (scanf("%d", &busnumber) != 1) //  101  102..
        {
            while (getchar() != '\n')
                ;
            continue;
        }

        int match = -1;
        for (int i = 0; i < 5; i++)
        {
            if (buses[i][0] == busnumber)
            {
                match = i;
                break;
            }
        }

        if (match >= 0)
        {
            printf("\n Bus Number       :       %d", buses[match][0]);
            printf("\n Source           :       %s", sourcecity[match]);
            printf("\n Destination      :       %s", destinationcity[match]);
            printf("\n Total Seats      :       %d", 50);
            printf("\n Available Seats  :       %d", buses[match][1]);
            printf("\n Fare             :       %d", fare[match]);
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