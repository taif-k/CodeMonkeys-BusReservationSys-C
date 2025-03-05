#include <stdio.h>\

void logout();

int main() {
    
    logout();
    return 0;
}

void logout() { 
    int number;
    
while (1) { 
    printf("Enter 0 for Logout\n");
    printf("Enter 1 for Exit\n");
    printf("Enter your number: ");
    scanf("%d", &number);

    if (number == 0) {
        printf("Logout Successful!\n");
        break; 
    } 
        else if (number == 1) {
        printf("Exiting..\n");
        break;
    }
        else {
        printf("Invalid Number! Please enter 0 or 1.\n");
        logout(); 
    }
}
}