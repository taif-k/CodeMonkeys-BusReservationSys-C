#include<stdio.h>
int main()
{
int option;
while(1)
{
printf("\nEnter Your Option ");

if(scanf("%d",&option)!= 1)
{
    while (getchar() != '\n')
    continue;
}


if(option==101)
{ 
    printf("Fare= 100");
    printf("\nSource = Delhi");
    printf("\nDestination = Gurgaon");
    printf("\nTotal Seats = 60 ");
   break;
}
else if(option==102)
{
    printf("Fare= 100");
    printf("\nSource = Delhi");
    printf("\nDestination = Gurgaon");
    printf("\nTotal Seats = 60 ");
   break;
}
else if(option==103)
{
    printf("Fare= 100");
    printf("\nSource = Delhi");
    printf("\nDestination = Gurgaon");
    printf("\nTotal Seats = 60 ");
   break;
}
else if(option==104)
{
    printf("Fare= 100");
    printf("\nSource = Delhi");
    printf("\nDestination = Gurgaon");
    printf("\nTotal Seats = 60 ");
   break;
}
else if(option==105)
{
    printf("Fare= 100");
    printf("\nSource = Delhi");
    printf("\nDestination = Gurgaon");
    printf("\nTotal Seats = 60 ");
   break;
}
else
{
printf("Invalid Bus Number");

}

}
}