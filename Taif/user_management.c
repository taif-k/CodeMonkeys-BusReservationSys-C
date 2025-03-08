#include <stdio.h>
#include <string.h>

void menu(); 
void loginaccount(char username[10], char password[10]);


int main() 
{
    char username[10] = {"cm123"};
    char password[10] = {"cm@123"};
  
    loginaccount(username, password);
    return 0;
}

void menu() 
{
    printf("\n Login credentials (testing purpose): username - cm123, password - cm@123");
    printf("\n1- Login");
    printf("\n2- Exit");
}

void loginaccount(char usrname[10], char usrpassword[10])
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
                for (int i = 0; loginusername[i] != '\0' || usrname[i] != '\0'; i++)
                {
                    if (loginusername[i] != usrname[i]) // if any char of signup username is not equal to char of login username
                    {
                        usermatch = 1;
                        break;
                    }
                }

                int passwordmatch = 0;
                for (int i = 0; loginpassword[i] != '\0' || usrpassword[i] != '\0'; i++)
                {
                    if (loginpassword[i] != usrpassword[i]) // if any char of signup password is not equal to char of login password
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
