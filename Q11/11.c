

#include <stdio.h>
int fact(int n)
{
if(n<=1)return 1;
else
return n*fact(n-1);

}
int main()
{
   
int n;
printf("\n enter the number :");
scanf("%d",&n);
printf("\n the factorial of the number %d is %d \n",n,fact(n));

   
   
    return 0;
}
