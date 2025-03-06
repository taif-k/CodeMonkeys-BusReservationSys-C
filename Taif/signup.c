#include <stdio.h>
#include <string.h>

void signup(char uname[10], char pword[10]);

int main()
{
    char username[10];
    char password[10];
    signup(username, password);
    return 0;
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
                while (1)
                {
                    printf("Enter password: ");
                    scanf("%s", &pword[0]);  
                    int length = strlen(pword);

                    if (length >= 6) // re-ask for password if length is not equal or more than 6
                    {
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
                        break;
                    }
                    else
                    {
                        printf("\nPassword should be at least 6 characters long");
                    }
                }
                break;
            }
            else
            {
                printf("\nUsername should be at least 5 characters long");
            }
        }
    }
}