#include<stdio.h>

void descending(int* a)
{
   printf("\ndescending order\n");
    for(int i=9;i>=0;i--)
printf("%d ",*(a+i));    
}
void ascending(int* a)
{

    printf("\nascending order");
    int i,j,temp;
    for(i=0;i<10;i++)
    for(j=0;j<10;j++)
    if(a[i]<a[j])
    {
        temp=*(a+i);a[i]=*(a+j);a[j]=temp;
   
    }
    printf("\n");
    for(i=0;i<10;i++)
     printf("%d ",*(a+i)); 
    descending(&a[0]);
}


void main()
{
  int a[10],i;
  printf("\nenter 10 numbers \n");
  for(i=0;i<10;i++)scanf("%d",&a[i]);
  ascending(&a[0]);
 printf("\n");
}
