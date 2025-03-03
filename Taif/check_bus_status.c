#include <stdio.h>

void check_bus_status();
void busnumbers();
int main()
{
    busnumbers();
    check_bus_status();
    return 0;
}

void check_bus_status()
{
    int fare[5] = {100, 150, 180, 200, 250};
    int buses[5][2] = {{101, 60}, {102, 70}, {103, 80}, {104, 90}, {105, 100}};
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
            printf("\n Total Seats      :       %d", buses[match][1]);
            printf("\n Available Seats  :       %d", buses[match][1] - (match + 1)); // test
            printf("\n Fare             :       %d", fare[match]);
            break;
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