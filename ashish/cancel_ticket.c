#include <stdio.h>
#include <stdlib.h>

#define MAX_SEATS 50

void cancelReservation(int seats[], int size);
void viewReservations(int seats[], int size);               

int main() {
    int seats[MAX_SEATS] = {};  
    int choice;

    do {
        printf("\nBus Reservation System\n");
        printf("1. Reserve a Seat\n");
        printf("2. Cancel Reservation\n");
        printf("3. View Reserved Seats\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
            reserveSeat(seats, MAX_SEATS);
            break;
            case 2:
               cancelReservation(seats, MAX_SEATS);
             break;
           case 3:
                  viewReservations(seats, MAX_SEATS);
                break;
            case 4:
                printf("Exiting the system...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
void reserveSeat(int seats[], int size) {
    int seatNumber;

    printf("\nEnter seat number to reserve (1 to %d): ", size);
    scanf("%d", &seatNumber);

    if(seatNumber < 1 || seatNumber > size) {
        printf("Invalid seat number!\n");
    } else if(seats[seatNumber - 1] == 1) {
        printf("Sorry, Seat %d is already reserved.\n", seatNumber);
    } else {
        seats[seatNumber - 1] = 1;
        printf("Seat %d has been successfully reserved.\n", seatNumber);
    }
}
void cancelReservation(int seats[], int size) {
    int seatNumber;

    printf("\nEnter seat number to cancel reservation (1 to %d): ", size);
    scanf("%d", &seatNumber);

    if(seatNumber < 1 || seatNumber > size) {
        printf("Invalid seat number!\n");
    } else if(seats[seatNumber - 1] == 0) {
        printf("Seat %d is not reserved.\n", seatNumber);
    } else {
        seats[seatNumber - 1] = 0;
        printf("Reservation for seat %d has been successfully canceled.\n", seatNumber);
    }
}

void viewReservations(int seats[], int size) {
    printf("\nReserved Seats:\n");
    for(int i = 0; i < size; i++) {
        if(seats[i] == 1) {
            printf("Seat %d is reserved.\n", i + 1);
        }
    }
}
