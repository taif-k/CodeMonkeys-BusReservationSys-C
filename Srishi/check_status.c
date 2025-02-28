//test comment

#include<stdio.h>

int main ()
{
    checkstatus(); // calling
}
void checkstatus(){
    printf("\nseat status: \n");// ye seat status ka header print karta hai
    printf("seat No | status | pessenge Name\n"); // ye line format me print hoga 

    printf("-------------------------\n"); // ye ek separator line -------------- print karta hai table ko clean dikhane ke liye 
    for  (int i =0; <MAX SEATS; i++) // ye loop chal rha hai jo 0 se lekar MAX_SEATS -1 tak jayega, ye har ek seat ka status cheak krega 

    printf("%-10d | %-10s | 10s\n",
        seats[i] .isBooked ? "Booked" : "Available" ,
        seats[i].passengerName);

        return 0;





}