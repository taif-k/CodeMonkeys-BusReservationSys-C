#include <stdio.h>

void login(); // ye ek declaration hai, ye compiler ko btata hai ki ek login finction exist karta hai, jise main ke ander call kiya ja skta hai

int main()
{
    // login function call
    login();  // function ko call karta hai taki user se input liya ja ske.
    return 0; // eska matlab hai program succesfully execute ho gya hai.
}

// login function definition
void login()
{ // ye function user se input lega aur usko process krega.
    int choice;

    while (1)
    { // infinite loop, jab tak valid input na mile
        printf("Enter 1 for Login\n");
        printf("Enter 2 for Exit\n");
        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            continue;
        }

        if (choice == 1)
        {
            printf("\nLogin Successful!\n");
            break; // loop ko terminate krega
        }
        else if (choice == 2)
        {
            printf("\nExiting...\n");
            break;
        }
        else
        {
            printf("\nInvalid Choice! Please enter 1 or 2.\n");
            login(); // dubara se input lene ke liye
        }
    }
}