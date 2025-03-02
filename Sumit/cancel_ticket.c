#include<stdio.h>
int main()
{
    char number;
     int cancel=0; 
     int total=50;
    while(1)
    {
      printf(" Enter Your Bus Number ");

     scanf( "%d",&number);
    if( number==1 )
     {

        break;
     }
     else
      {
        printf("! Invalid input !");

      }
    }
    
 printf("\nEnter Number of Seats Want You Cancel ");
     scanf("%d",&cancel );
     printf("\nYour Bus Number:%d ",number);
     printf("\nYou Canceled Tickets:%d ",cancel);
printf("\nTotal Number Of Seats Remaining %d ",total-cancel );
    

}