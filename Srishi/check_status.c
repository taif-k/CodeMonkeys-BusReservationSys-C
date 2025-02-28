#include <stdio.h>
#include <string.h>

#define TOTAL_SEATS 10  // Total seats in bus

// Structure banaya seat details store karne ke liye
typedef struct {
    int seatNo;
    char name[50];
    int booked;
} Seat;

Seat bus[TOTAL_SEATS];

// Bus seats ko initialize karega
void initializeBus() {
    for (int i = 0; i < TOTAL_SEATS; i++) {
        bus[i].seatNo = i + 1;
        bus[i].booked = 0;  // 0 means seat available
        strcpy(bus[i].name, "Not Booked");  // Default status
    }
}

// Bus ka seat status show karega
void showStatus() {
    printf("\nBus Seat Status:\n");
    printf("Seat No.\tStatus\t\tPassenger Name\n");
    for (int i = 0; i < TOTAL_SEATS; i++) {
        printf("%d\t\t%s\t\t%s\n", bus[i].seatNo, 
               bus[i].booked ? "Booked" : "Available", 
               bus[i].booked ? bus[i].name : "N/A");
    }
}

// Main function
int main() {
    initializeBus();  // Bus ko initialize karenge
    
    // Kuch seats manually book kar rahe hain (Demo ke liye)
    bus[2].booked = 1;
    strcpy(bus[2].name, "taif");

    bus[5].booked = 1;
    strcpy(bus[5].name, "sumit");

    bus[8].booked = 1;
    strcpy(bus[8].name, "Ashish");

    showStatus();  // Bus ka seat status show karega

    return 0;
}
