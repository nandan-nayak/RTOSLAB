
#include <stdio.h>
struct date 
{
    int day;
    int month;
    int year;
    
    
};
int main()
{
   struct date d1,d2;
   printf("\n enter the date d1 :\n");
   printf(" enter day ");
   scanf("%d",&d1.day);
   printf("enter month ");
   scanf("%d",&d1.month);
   printf("enter year ");
   scanf("%d",&d1.year);
   
   
    printf("\n enter the date d2 :\n");
   printf(" enter day ");
   scanf("%d",&d2.day);
   printf("enter month ");
   scanf("%d",&d2.month);
   printf("enter year ");
   scanf("%d",&d2.year);
   
   while(d1.day/31!=0)
   {
       
       d1.month+=1;
       d1.day=d1.day%30;
       
   }
   
   
   while(d1.month/13!=0)
   {
        d1.year+=1;
       d1.month=d1.month%12;
       
   }
   
   
   
   
   
   
   while(d2.day/31!=0)
   {
       
       d2.month+=1;
       d2.day=d2.day%30;
       
   }
   
   
   while(d2.month/13!=0)
   {
       
       d2.year+=1;
       d2.month=d2.month%12;
       
   }
   
   
   printf("\n the dates are \n");
   printf("\nd1 -> %d/%d/%d ",d1.day,d1.month,d1.year); 
   printf("\nd2 -> %d/%d/%d ",d2.day,d2.month,d2.year);
   
   if(d1.year>=d2.year && d1.month >=d2.month && d1.day > d2.day)
   {
       printf("\n latter date is %d/%d/%d",d1.day,d1.month,d1.year);
       
   }
   else
   printf("\n latter date is %d/%d/%d\n",d2.day,d2.month,d2.year);
   
   
   
    return 0;
}
