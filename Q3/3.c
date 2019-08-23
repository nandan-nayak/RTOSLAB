#include<stdio.h>

void display(char *str)
{

int i,count=0;
printf("\n input from the file is : ");
for(i=0;str[i]!='\0';i++)
{
printf("%c",str[i]);
count++;
}
printf("\n no of characters is :%d\n",count);


}
int main()
{
FILE *fp=fopen("3.txt","r");
char string[10];
if(fp==NULL)
{
printf("\nsomething went wrong");
return 1;

}
if(fscanf(fp,"%s",string)==1)
//printf("%s",string);
display(&string[0]);
else
printf("\n not found ");

return 0;
}
