#include <stdio.h>

void checkstatus();

int main()
{

    checkstatus();
    return 0;
}

void checkstatus()
{
    int busnumber = 0;
    int seatbook = 0;
    int buses[5][2] = {{101, 50}, {102, 50}, {103, 50}, {104, 50}, {105, 50}};
    int fare[5] = {100, 200, 300, 400, 500};
    char sourcecity[5][10] = {
        "Delhi",
        "Noida",
        "Gurugram",
        "Punjab",
    };
    char destinationcity[5][10] = {
        "Noida",
        "Delhi",
        "Gurugram",
        "Punjab",
    };

    printf("\nEnter Bus Number: ");
    scanf("%d", &busnumber);
    While(1)
     {
    if (busnumber == 101)
    {
        printf("\n Bus Number       :       %d", busnumber);
        printf("\n Source citty     :       %s", sourcecity[0]);
        printf("\n Destination city :       %s", destinationcity[2]);
        printf("\n Total Seats      :       %d", buses[0][1]);
        printf("\n Fare             :       %d", fare[0]);
    }
    else if (busnumber == 102)
    {
        printf("\n Bus Number       :       %d", busnumber);
        printf("\n Source City      :       %s", sourcecity[1]);
        printf("\n Destination City :       %s", destinationcity[1]);
        printf("\n Total Seats      :       %d", buses[1][1]);
        printf("\n Fare             :       %d\n", fare[1]);
    }
    else if (busnumber == 103)
    {
        printf("\n Bus Number       :       %d", busnumber);
        printf("\n Source City      :       %s", sourcecity[2]);
        printf("\n Destination City :       %s", destinationcity[2]);
        printf("\n Total Seats      :       %d", buses[2][1]);
        printf("\n Fare             :       %d\n", fare[2]);
    }
    else if (busnumber == 104)
    {
        printf("\n Bus Number       :       %d", busnumber);
        printf("\n Source City      :       %s", sourcecity[3]);
        printf("\n Destination City :       %s", destinationcity[3]);
        printf("\n Total Seats      :       %d", buses[3][1]);
        printf("\n Fare             :       %d\n", fare[3]);
    }
    else if (busnumber == 105)
    {
        printf("\n Bus Number       :       %d", busnumber);
        printf("\n Source City      :       %s", sourcecity[4]);
        printf("\n Destination City :       %s", destinationcity[4]);
        printf("\n Total Seats      :       %d", buses[4][1]);
        printf("\n Fare             :       %d\n", fare[4]);
    }
    else
    }
    {
        printf("\nInvalid Bus Number! Please enter a valid bus number (101-105).\n");
    }
}
}
