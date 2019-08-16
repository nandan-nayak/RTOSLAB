#include<stdio.h>




void main()
{
    
    FILE *fp=fopen("6input.txt","r");
    int i,c;
char a[100];
printf("\n original file content ");
printf("\n=============================\n");
fread(a,100,1,fp);
printf("%s",a);
for(i=0;a[i]!='\0';i++)
{
    c=a[i];
    if(c>=97)
    a[i]=a[i]-32;
    
    
}

printf("\n\n\nfile content in uppercase is \n");
printf("==================================\n");
printf("\n %s ",a);
fclose(fp);
printf("\n");
}
