#include<stdio.h>
int main()
{
    int busnumbers[5] ;
int number;
     int cancel=0;
     int total=50;
    
     printf(" Enter Your Bus Number ");
     scanf("%d",&number);
    
     printf("\nEnter Numbers Seats Want You Cancel ");
     scanf("%d",&cancel );

     printf("\nYour Bus Number:%d ",number);
     printf("\nYou Cancel Tickets:%d ",cancel);
printf("\n Total Number Of Seats Remaining%d ",total-cancel );

}