#include <stdio.h>
int main()
{
    int number;
    int cancel = 0;
    int total = 50;

    while (1)
    {
        printf("\nEnter Your Bus Number ");

        if (scanf("%d", &number) != 1) // agar bus number abc kuch esa dalega toh neeche while getchar()  inout jo bhi hai usse clear krdega ...aur continue neeche if ko skip krega aur loop phirse start hoga
        {
            while (getchar() != '\n')
                ; // clear input (input buffer)
            continue;
        }
        while (1)
        {
        printf("\nEnter Numbers Seats Want You Cancel ");
        if (scanf("%d", &cancel) != 1)
        while (getchar()  != '\n') // try here    // upar jaise number ke liiye kara hai yha tum try karo
        continue;
        if (number == 101)
        {
            printf("\nYour Bus Number:%d ", number);
            printf("\nYou Canceled Tickets:%d ", cancel);
            printf("\nTotal Number Of Seats Remaining %d ", total - cancel);
            break;
        }
        else
        {
            printf("\nEnter 101 bus number ");
        }
    
    
}
    }
}