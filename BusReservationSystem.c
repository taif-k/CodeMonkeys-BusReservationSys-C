#include <stdio.h>
#include <string.h>

void bus_reservation_sys();
void user_menu();
void sign_up(char uname[10], char password[10]);
void menu();
void login_account(char username[10], char password[10]);
void book_ticket(int busnumb, int seatbooked, int bus[5][2]);
void cancel_ticket(int busnumb, int seatcancelled, int bus[5][2]);
void check_bus_status(int busnumb, int bus[5][2]);

int main()
{
    printf("\n------------------------Bus Reservation System------------------------");
    bus_reservation_sys(); // bus rservation system

    return 0;
}

void bus_reservation_sys()
{
    int option = 0;
    int count = 0;
    char username[10];
    char password[10];
    int seatcancel = 0;
    int busnumber = 0;
    int seatbook = 0;
    int buses[5][2] = {{101, 50}, {102, 50}, {103, 50}, {104, 50}, {105, 50}};

    sign_up(username, password);
    login_account(username, password);
    while (1)
    {

        do // do-while to handle tasks after login
        {
            user_menu();
            printf("\nEnter User menu task no: ");
            if (scanf("%d", &option) != 1 || option < 1 || option > 4)
            {
                while (getchar() != '\n')
                    ;
                continue;
            }

            if (option == 1)
            {
                book_ticket(busnumber, seatbook, buses);
            }
            else if (option == 2)
            {
                cancel_ticket(busnumber, seatcancel, buses);
            }
            else if (option == 3)
            {
                check_bus_status(busnumber, buses);
            }
            else if (option == 4)
            {
                count = 1;
            }

        } while (count == 0);
    }
}

void sign_up(char uname[10], char pword[10])
{
    while (1)
    {
        printf("\nEnter username to Register: ");
        scanf("%s", &uname[0]);
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

        if (numcount > 4) // if 4 digits are found in the string, it will update the value of match to 1
        {
            match = 1;
            printf("\nMore than 4 digits present");
        }

        if (match == 0) // if digits are not more than 4 and line 35 is not true match is set to 0;
        {
            if (length >= 5)
            {
                break;
            }
            else
            {
                printf("\nUsername should be at least 5 characters long");
            }
        }
    }

    while (1)
    {
        printf("Enter password: ");
        scanf("%s", &pword[0]);
        int length = strlen(pword);

        if (length >= 6) // re-ask for password if length is not equal or more than 6
        {
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
        printf("Enter city: ");
        scanf("%s", &city[0]);
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
                break;
            }
            else
            {
                printf("\nCity should be at least 5 characters long");
            }
        }
    }
}

void login_account(char username[10], char password[10])
{
    int option;
    char loginusername[10];
    char loginpassword[10];

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
                scanf("%s", &loginusername[0]);
                printf("Enter password: ");
                scanf("%s", &loginpassword[0]);

                int usermatch = 0;
                for (int i = 0; loginusername[i] != '\0' || username[i] != '\0'; i++)
                {
                    if (loginusername[i] != username[i]) // if any char of signup username is not equal to char of login username
                    {
                        usermatch = 1;
                        break;
                    }
                }

                int passwordmatch = 0;
                for (int i = 0; loginpassword[i] != '\0' || password[i] != '\0'; i++)
                {
                    if (loginpassword[i] != password[i]) // if any char of signup password is not equal to char of login password
                    {
                        passwordmatch = 1;
                        break;
                    }
                }

                if (usermatch == 0 && passwordmatch == 0) // if both the string exactly match
                {
                    printf("\nWelcome, Team Code Monkeys");
                    break;
                }
                else
                {
                    printf("\nEither Username or Password is Incorrect.. Try again");
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

void user_menu()
{
    printf("\n\n---User Menu---");
    printf("\n1-Book a ticket");
    printf("\n2-Cancel a ticket");
    printf("\n3-Check Bus status");
    printf("\n4-Logout");
}

void book_ticket(int busnumb, int seatbooked, int bus[5][2])
{
    while (1)
    {
        printf("\nEnter Bus number: ");
        if (scanf("%d", &busnumb) != 1)
        {
            while (getchar() != '\n')
                ;
            continue;
        }
        if (busnumb == 101 || busnumb == 102 || busnumb == 103 || busnumb == 104 || busnumb == 105)
        {
            int match = 0;
            for (int i = 0; i < 5; i++)
            {

                if (busnumb == bus[i][0])
                {
                    match = i;
                    break;
                }
            }

            if (match >= 0)
            {
                printf("\nEnter number of seats to book: ");
                scanf("%d", &seatbooked); // 2

                if (seatbooked <= bus[match][1]) // 50
                {
                    bus[match][1] = bus[match][1] - seatbooked;
                    printf("\nCongratulations! Seat Booked: %d", seatbooked);
                    printf("\nSeat left %d", bus[match][1]);
                    break;
                }
                else
                {
                    printf("\nBooking seats greater than total seats %d", bus[match][1]);
                    break;
                }
            }
        }
        else
        {
            printf("Enter valid bus Number \n");
        }
    }
}

void cancel_ticket(int busnumb, int seatcancelled, int bus[5][2])
{

    while (1)
    {
        printf("\nEnter Bus number: ");
        if (scanf("%d", &busnumb) != 1)
        {
            while (getchar() != '\n')
                ;
            continue;
        }
        if (busnumb == 101 || busnumb == 102 || busnumb == 103 || busnumb == 104 || busnumb == 105)
        {
            int match = 0;
            for (int i = 0; i < 5; i++)
            {

                if (busnumb == bus[i][0])
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
                    scanf("%d", &seatcancelled); // 2

                    if (seatcancelled <= bus[match][1]) // 50
                    {
                        bus[match][1] = bus[match][1] + seatcancelled;
                        printf("\nSeats Cancelled: %d", seatcancelled);
                        printf("\nSeats Available: %d", bus[match][1]);
                        break;
                    }
                    else
                    {
                        printf("\nSeats to cancel are greater than avaiable seats");
                    }
                }
                break;
            }
        }
        else
        {
            printf("\nEnter valid Bus Number ");
        }
    }
}

void check_bus_status(int busnumb, int bus[5][2])
{
    while (1)
    {
        int fare[5] = {100, 150, 180, 200, 250};
        char sourcecity[5][10] = {"Delhi", "Noida", "Gurugram", "Haryana", "Faridabad"};
        char destinationcity[5][10] = {"Noida", "Gurugram", "Haryana", "Faridabad", "Agra"};

        printf("\nEnter Bus Number: ");
        if (scanf("%d", &busnumb) != 1) //  101  102..
        {
            while (getchar() != '\n')
                ;
            continue;
        }

        int match = -1;
        for (int i = 0; i < 5; i++)
        {
            if (bus[i][0] == busnumb)
            {
                match = i;
                break;
            }
        }

        if (match >= 0)
        {
            printf("\n Bus Number       :       %d", bus[match][0]);
            printf("\n Source           :       %s", sourcecity[match]);
            printf("\n Destination      :       %s", destinationcity[match]);
            printf("\n Total Seats      :       %d", 50);
            printf("\n Available Seats  :       %d", bus[match][1]);
            printf("\n Fare             :       %d", fare[match]);
        }
        break;
    }
}