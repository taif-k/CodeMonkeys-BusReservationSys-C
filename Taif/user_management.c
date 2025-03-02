#include <stdio.h>
#include <string.h>

void menu(); // Declaration
void loginaccount(char username[10], char password[10]);
void signup(char uname[10], char password[10]);

int main() // User defined function
{
    char username[10];
    char password[10];
    signup(username, password); // calling(has Arguments)
    loginaccount(username, password);
    return 0;
}

void menu() // Definition
{
    printf("\n1- Login");
    printf("\n2- Exit");
}

void signup(char uname[10], char pword[10])
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
                printf("Username is: %s", uname);
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
        printf("\nEnter password: ");
        scanf("%s", &pword[0]);
        int length = strlen(pword);

        if (length >= 6) // re-ask for password if length is not equal or more than 6
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
