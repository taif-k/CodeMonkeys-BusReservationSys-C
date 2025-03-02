#include <stdio.h>
#include <string.h>

void brs();
void signup(char uname[10], char password[10]);
void menu();
void loginaccount(char username[10], char password[10]);

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

    signup(username, password);
    while (1)
    {

        loginaccount(username, password);

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

void signup(char uname[10], char pword[10])
{
    while (1)
    {
        printf("\nEnter username to Register: ");
        scanf("%s", &uname[0]); // Use &uname[0] to pass the address of the first element
        int length = strlen(uname);
        int match = 0;
        int numcount = 0;

        for (int i = 0; uname[i] != '\0'; i++)
        {
            if ((uname[i] < '0' || uname[i] > '9') && (uname[i] != '@') && (uname[i] < 'a' || uname[i] > 'z'))
            {
                match = 1;
                break;
            }

            if (uname[i] >= '0' && uname[i] <= '9')
            {
                numcount++;
            }
        }

        if (numcount > 4)
        {
            match = 1;
            printf("\nMore than 4 digits present.\n");
        }

        if (match == 0)
        {
            if (length >= 5)
            {
                printf("Username is: %s\n", uname);
                break;
            }
            else
            {
                printf("\nUsername should be at least 5 characters long.\n");
            }
        }
    }

    while (1)
    {
        printf("\nEnter password: ");
        scanf("%s", &pword[0]); // Use &pword[0] to pass the address of the first element
        int length = strlen(pword);

        if (length >= 6)
        {
            printf("Password is : %s\n", pword);
            break;
        }
        else
        {
            printf("\nPassword should be at least 6 characters long");
        }
    }

    while (1)
    {
        char city[10];
        printf("\nEnter city: ");
        scanf("%s", &city[0]); // Use &city[0] to pass the address of the first element
        int length = strlen(city);
        int match = 0;

        for (int i = 0; city[i] != '\0'; i++)
        {
            if (city[i] < 'a' || city[i] > 'z')
            {
                match = 1;
                break;
            }
        }

        if (match == 0)
        {
            if (length >= 5)
            {
                printf("City is : %s", city);
                break;
            }
            else
            {
                printf("\nCity should be at least 5 characters long");
            }
        }
    }
}

void loginaccount(char username[10], char password[10])
{
    int option;
    char inputUsername[10];
    char inputPassword[10];

    do
    {
        menu();
        printf("\nEnter task no: ");
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
                scanf("%s", &inputUsername[0]); // Use &inputUsername[0] to pass the address of the first element
                printf("Enter password: ");
                scanf("%s", &inputPassword[0]); // Use &inputPassword[0] to pass the address of the first element

                int usermatch = 0;
                for (int i = 0; inputUsername[i] != '\0' || username[i] != '\0'; i++) // Compare each character
                {
                    if (inputUsername[i] != username[i])
                    {
                        usermatch = 1; // Username mismatch
                        break;
                    }
                }

                int passwordmatch = 0;
                for (int i = 0; inputPassword[i] != '\0' || password[i] != '\0'; i++) // Compare each character
                {
                    if (inputPassword[i] != password[i])
                    {
                        passwordmatch = 1; // Password mismatch
                        break;
                    }
                }

                if (usermatch == 0 && passwordmatch == 0)
                {
                    printf("\nWelcome, Team Code Monkeys\n");
                    break;
                }
                else
                {
                    printf("\nEither Username or Password is Incorrect.. Try again\n");
                }
            }
        }
        else if (option == 2)
        {
            break;
        }

    } while (option != 1);
}

void menu()
{
    printf("\n1- Login");
    printf("\n2- Exit");
}
