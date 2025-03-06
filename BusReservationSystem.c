#include <stdio.h>
#include <string.h>

void bus_reservation_sys();
void user_menu();
void menu();
void login_account(char username[10], char password[10]);
void book_bus_ticket(int busnumb, int seatbooked, int bus[5][2], int alreadybooked[5]);
void cancel_bus_ticket(int busnumb, int seatcancelled, int bus[5][2], int booked[5]);
void check_bus_status(int busnumb, int bus[5][2], int seattotal[5]);
int exit_variable = 0;

int main()
{
    printf("\n------------------------Bus Reservation System------------------------");
    bus_reservation_sys(); // bus reservation system
    return 0;
}

void bus_reservation_sys()
{

    int option = 0;

    char username[10] = {"cm123"};
    char password[10] = {"cm@123"};
    int seatcancel = 0;
    int busnumber = 0;
    int seatbook = 0;
    int count = 0;
    int buses[5][2] = {{101, 60}, {102, 70}, {103, 80}, {104, 95}, {105, 100}};
    int total_seats[5] = {60, 70, 80, 95, 100};
    int alreadybooked[5] = {0, 0, 0, 0, 0}; // store the booked seats

    login_account(username, password);

    if (exit_variable == 1)
    {
        return;
    }

    while (1)
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
            book_bus_ticket(busnumber, seatbook, buses, alreadybooked);
        }
        else if (option == 2)
        {
            cancel_bus_ticket(busnumber, seatcancel, buses, alreadybooked);
        }
        else if (option == 3)
        {
            check_bus_status(busnumber, buses, total_seats);
        }
        else if (option == 4)
        {
            login_account(username, password);
            break;
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
            exit_variable = 1;
            break;
        }

    } while (option != 1);
}

void menu()
{
    printf("\nLogin credentials (Testing purpose)  username - cm123  password - cm@123");
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

void book_bus_ticket(int busnumb, int seatbooked, int bus[5][2], int alreadybooked[5])
{
    while (1)
    {
        printf("\nEnter Bus number for booking: ");
        if (scanf("%d", &busnumb) != 1)
        {
            while (getchar() != '\n')
                ;
            continue;
        }

        int match = -1;
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
                printf("\nEnter number of seats to book: ");
                if (scanf("%d", &seatbooked) != 1)
                {
                    while (getchar() != '\n')
                        ;
                    continue;
                } // 2

                if (seatbooked <= 0) // If seat number is entered in negative, rest if-else are skipped and while loop keeps on running
                {
                    printf("Seats cannot be Negative");
                    continue;
                }

                if (seatbooked <= bus[match][1]) // 50
                {
                    printf("\nTotal Seats %d", bus[match][1]);
                    bus[match][1] = bus[match][1] - seatbooked;
                    printf("\nCongratulations! Seat Booked: %d", seatbooked);
                    printf("\nSeat left %d", bus[match][1]);
                    alreadybooked[match] = alreadybooked[match] + seatbooked;

                    break;
                }
                else
                {
                    printf("\nBooking seats greater than total seats %d", bus[match][1]);
                }
            }
            break;
        }
        else
        {
            printf("Enter valid bus Number \n");
        }
    }
}

void cancel_bus_ticket(int busnumb, int seatcancelled, int bus[5][2], int booked[5])
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

        int match = -1;
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
                if (scanf("%d", &seatcancelled) != 1)
                {
                    while (getchar() != '\n')
                        ;
                    continue;
                } // 2
                if (seatcancelled < 0)
                {
                    printf("\nSeats cannot be negative ");
                    continue;
                }

                if (seatcancelled <= booked[match]) // booked[0] booked[1]..........booked[5]
                {
                    booked[match] = booked[match] - seatcancelled;
                    bus[match][1] = bus[match][1] + seatcancelled;
                    printf("\nSeats Cancelled: %d", seatcancelled);
                    printf("\nSeats Available: %d", bus[match][1]);
                    break;
                }
                else
                {
                    printf("\nSeats to cancel are greater than booked seats");
                }
            }
            break;
        }

        else
        {
            printf("\nEnter valid Bus Number ");
        }
    }
}

void check_bus_status(int busnumb, int bus[5][2], int seattotal[5])
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
            printf("\n Total Seats      :       %d", seattotal[match]);
            printf("\n Available Seats  :       %d", bus[match][1]);
            printf("\n Fare             :       %d", fare[match]);
            break;
        }
    }
}