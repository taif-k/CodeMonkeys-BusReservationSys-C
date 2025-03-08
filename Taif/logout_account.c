#include <stdio.h>

void logout_account(int opt); 
void login();

int main()
{
    int option;
    logout_account(option);
    return 0;
}

void logout_account(int opt)
{
    while (1)
    {
        printf("\nEnter 1 to logout: ");
        if (scanf("%d", &opt) != 1)
        {
            while (getchar() != '\n')
                ;
            continue;
        }

        if (opt == 1)
        {
            login();
            break;
        }
        else
        {
            printf("\nPlease select valid option to logout");
        }
    }
}

void login()
{
    printf("\n1- Login");
}