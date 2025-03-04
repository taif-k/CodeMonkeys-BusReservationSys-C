#include <stdio.h>

int main()
{
    int option;
    while (1)
    {
        printf("\nEnter 1 to logout: ");
        if (scanf("%d", &option) != 1)
        {
            while (getchar() != '\n');
            continue;
        }

        if (option == 1)
        {
            break;
        }
        else
        {
            printf("\nPlease select valid option to logout");
        }
    }

    return 0;
}

void logout()
{
    printf("\nEnter 4 to Logout");
}