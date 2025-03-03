#include <stdio.h>

void check_status(); // yaha pe checkstatus function ko declare kiya gya hai jo bus ki details dikhane ka kaam krega

int main() // program ka starting point hota hai.
{

    check_status(); // ye functipn call ho rha hai jo bus ki details check krega
    return 0;       // eska matlab program execute ho rha hai
}

void check_status() // yha se bus ki details check check karne wala function start ho rha .
{
    int busnumber = 0;                                                         // user jo bus number input krega usko store krega
    int seatbook = 0;                                                          // ye variable abhi use nhi ho raha hai, future me booking ke liye ho skta hai
    int buses[5][2] = {{101, 50}, {102, 50}, {103, 50}, {104, 50}, {105, 50}}; // ek 2d array hia jo 5 buses ki details store karta hai
    int fare[5] = {100, 200, 300, 400, 500};                                   // ye array har bus ka ticket price store karta hai.
    char sourcecity[5][10] = {"Delhi", "Noida", "Gurugram", "Punjab", "bangaluru"};
    char destinationcity[5][10] = {"Noida", "Delhi", "Gurugram", "Punjab", "Haryana"};

    while (1)
    {
<<<<<<< HEAD:Srishi/check_status.c
        printf("\nEnter Bus Number: ");// ek infinite loop hai, jab tak user valid bus number enter nahi karega, jab tak ye loop chalega.
        if(scanf("%d", &busnumber) != 1 ) // a ! = 1
        {
                while(getchar() != '\n'); // abcd
                continue;
        }// user se ek integer input leta hai jo bus number hoga 
        
=======
        printf("\nEnter Bus Number: "); // ek infinite loop hai, jab tak user valid bus number enter nahi karega, jab tak ye loop chalega.
        if (scanf("%d", &busnumber) != 1)
        {
            while (getchar() != '\n')
                ;
            continue;
        } // user se ek integer input leta hai jo bus number hoga
>>>>>>> 54886fdb6edf8b836bcf17790ca01701fbd148d1:Srishti/check_bus_status.c
        if (busnumber == 101)
        {
            printf("\n Bus Number       :       %d", busnumber);
            printf("\n Source city      :       %s", sourcecity[0]);
            printf("\n Destination city :       %s", destinationcity[2]);
            printf("\n Total Seats      :       %d", buses[0][1]);
            printf("\n Fare             :       %d", fare[0]);
            break; // ye esliye likha hai taaki loop yhi ruk jaye.
        }
        else if (busnumber == 102) // 102 0r 105 tak same logic apply hota hai bas indexes change hota hai .
        {
            printf("\n Bus Number       :       %d", busnumber);
            printf("\n Source City      :       %s", sourcecity[1]);
            printf("\n Destination City :       %s", destinationcity[1]);
            printf("\n Total Seats      :       %d", buses[1][1]);
            printf("\n Fare             :       %d\n", fare[1]);
            break;
        }
        else if (busnumber == 103)
        {
            printf("\n Bus Number       :       %d", busnumber);
            printf("\n Source City      :       %s", sourcecity[2]);
            printf("\n Destination City :       %s", destinationcity[2]);
            printf("\n Total Seats      :       %d", buses[2][1]);
            printf("\n Fare             :       %d\n", fare[2]);
            break;
        }
        else if (busnumber == 104)
        {
            printf("\n Bus Number       :       %d", busnumber);
            printf("\n Source City      :       %s", sourcecity[3]);
            printf("\n Destination City :       %s", destinationcity[3]);
            printf("\n Total Seats      :       %d", buses[3][1]);
            printf("\n Fare             :       %d\n", fare[3]);
            break;
        }
        else if (busnumber == 105)
        {
            printf("\n Bus Number       :       %d", busnumber);
            printf("\n Source City      :       %s", sourcecity[4]);
            printf("\n Destination City :       %s", destinationcity[4]);
            printf("\n Total Seats      :       %d", buses[4][1]);
            printf("\n Fare             :       %d\n", fare[4]);
            break;
        }
        else
        {
            printf("\nInvalid Bus Number! Please enter a valid bus number (101-105).\n"); // agar user 101-105 ke alawa koi aur number dalta hai to error print hoga.
        }
    }
}