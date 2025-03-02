#include <stdio.h>
int main()
{
<<<<<<< HEAD
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
    
=======
    int number;
    int cancel = 0;
    int total = 50;

    while (1)
    {
        printf(" Enter Your Bus Number ");
>>>>>>> c56c4caa8b55ee0d27c256a1ce4870996f6bd196

        if (scanf("%d", &number) != 1) // agar bus number abc kuch esa dalega toh neeche while getchar()  inout jo bhi hai usse clear krdega ...aur continue neeche if ko skip krega aur loop phirse start hoga
        {
            while (getchar() != '\n'); // clear input (input buffer)
            continue;
        }

        printf("\nEnter Numbers Seats Want You Cancel ");
        scanf("%d", &cancel); // try here    // upar jaise number ke liiye kara hai yha tum try karo

        if (number == 101)
        {
            printf("\nYour Bus Number:%d ", number);
            printf("\nYou Canceled Tickets:%d ", cancel);
            printf("\nTotal Number Of Seats Remaining %d ", total - cancel);
        }
    }
}