#include <stdio.h>

void menu(); // Declaration
void loginaccount();

int main() // User defined function
{
    loginaccount();
    return 0;
}

void menu() //  Defination
{
    printf("\n1- Login");
    printf("\n2- Exit");
}

void loginaccount()
{

    int option;
    char userinfo[2][10] = {"cm123", "cm@123"}; // username = cm123 | password = cm@123
    char username[10];
    char password[10];

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
            break;
        }
        else
        {
            printf("\nLogin to proceed further");
        }

    } while (option != 1);
}
