#include <stdio.h> // Headerfile

void logout_account(); //Declaration

int main() // system defined function
{
   
    logout_account(); // calling
    return 0;
}

void logout_account() // user define function
{
    int option;
    while (1)
    {
        printf("1-logout: ");
        if (scanf("%d", &option) != 1) 
        {
            while (getchar() != '\n')
                ;
            continue;
        }

        if (option == 1) //
        {
            break;
        }
    }
}