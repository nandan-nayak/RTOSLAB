#include<stdio.h>
int divisible(int n)
{
    return n%8==0;
    
}
void main()
{
    FILE *fp=fopen("8input.txt","r");
    FILE *fp1=fopen("8output.txt","w");
    
    
    int x;
   
    fscanf(fp,"%d",&x);
printf("\n the content of the file is %d",x);

    if(divisible(x))
{printf("\n number is divisible by 8");
   fprintf(fp1,"%d",1);
 }   
    else
  {
printf("\n number is not divisible by 8");
  fprintf(fp1,"%d",0);
}    
    fclose(fp1);
   // printf("\n%c ",a[1]-48);


fp1=fopen("8output.txt","r");
fscanf(fp1,"%d",&x);
printf("\nthe content of output file is  %d",x);



printf("\n");
}
