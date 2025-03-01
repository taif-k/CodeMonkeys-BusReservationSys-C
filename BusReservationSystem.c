#include <stdio.h>

void brs();

int main()
{
    printf("\n------------------------Bus Reservation System------------------------");
    brs(); // bus rservation system

    return 0;
}

void brs()
{
    int option = 0;
    int count = 0;
    char userinfo[2][10] = {"cm123", "cm@123"}; // { {"cm123"}, {"cm@123"} }  row = username col = password, 10 is length
    char username[10];
    char password[10];
    int busnumber = 0;
    int seatbook = 0;
    int seatcancel = 0;
    int buses[5][2] = {{101, 50}, {102, 50}, {103, 50}, {104, 50}, {105, 50}};

    while (1)
    {
        printf("\n1-Login");
        printf("\n2-Exit");
        do // option 1
        {
            printf("\nEnter task number: ");
            if (scanf("%d", &option) != 1)
            {
                while (getchar() != '\n')
                    ;
                continue;
            }

            if (option == 1)
            {
                while (1)
                {
                    printf("\nEnter username: ");
                    scanf("%s", &username);
                    printf("Enter password: ");
                    scanf("%s", &password);

                    int usermatch = 0;
                    for (int i = 0; username[i] != '\0' || userinfo[0][i] != '\0'; i++) // cm123  //abc12
                    {
                        if (username[i] != userinfo[0][i])
                        {
                            usermatch = 1;
                            break;
                        }
                    }

                    int passwordmatch = 0;
                    for (int i = 0; password[i] != '\0' || userinfo[1][i] != '\0'; i++) // cm@123  //ab@123
                    {
                        if (password[i] != userinfo[1][i])
                        {
                            passwordmatch = 1;
                            break;
                        }
                    }

                    if (usermatch == 0 && passwordmatch == 0)
                    {
                        printf("\nWelcome, Team Code Monkeys");
                        break;
                    }
                    else
                    {
                        printf("\nEither Username or passwor is Incorrect..Try again");
                    }
                }
            }
            else if (option == 2)
            {
                return;
            }
            else
            {
                printf("\nLogin to proceed further");
            }

        } while (option != 1);

        do // do-while to handle tasks after login
        {
            printf("\n\n---User Menu---");
            printf("\n1-Book a ticket");
            printf("\n2-Cancel a ticket");
            printf("\n3-Check Bus status");
            printf("\n4-Logout");

            printf("\nEnter User menu task no: ");
            if (scanf("%d", &option) != 1 || option < 1 || option > 4)
            {
                while (getchar() != '\n')
                    ;
                continue;
            }

            if (option == 1)
            {
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
                                printf("\nCongratulations! Seat Booked: %d", seatbook);
                                printf("\nSeat left %d", buses[match][1]);
                                break;
                            }
                            else
                            {
                                printf("\nBooking seats greater than total seats %d", buses[match][1]);
                            }
                        }
                    }
                    else
                    {
                        printf("Enter valid bus Number \n");
                    }
                }
            }
            else if (option == 2)
            {
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
                            printf("\nEnter number of seats to cancel: ");
                            scanf("%d", &seatcancel); // 2

                            if (seatbook <= buses[match][1]) // 50
                            {
                                buses[match][1] = buses[match][1] + seatcancel;
                                printf("\nSeats Cancelled: %d", seatcancel);
                                printf("\nSeats Available: %d", buses[match][1]);
                                break;
                            }
                        }
                    }
                    else
                    {
                        printf("\nEnter valid Bus Number ");
                    }
                }
            }
            else if (option == 3)
            {
                while (1)
                {
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
                    break;
                }
            }
            else if (option == 4)
            {
                count = 1;
            }

        } while (count == 0);
    }
}