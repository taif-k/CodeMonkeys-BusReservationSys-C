#include <stdio.h> // Headerfile

void logout_account(int opt); //Declaration

int main()
{
    int option;
    logout_account(option);
    return 0;
}

void logout_account(int opt) // user define function
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

        if (opt == 1) //
        {
            break;
        }
        else
        {
            printf("\nPlease select valid option to logout");
        }
    }
}


