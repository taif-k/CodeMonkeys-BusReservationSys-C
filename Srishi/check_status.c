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

    if (busnumber == 101)
    {
        printf("\n Bus Number       :       %d", busnumber);
        printf("\n Source citty     :       %s", sourcecity[0]);
        printf("\n Destination city :       %s", destinationcity[2]);
        printf("\n Total Seats      :       %d", buses[0][1]);
        printf("\n Fare             :       %d", fare[0]);
    }
}