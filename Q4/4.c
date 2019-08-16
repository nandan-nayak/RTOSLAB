#include<stdio.h>
FILE* open()
{
    
    return fopen("4input.txt","r");
}
int countwordsandlines(char *a)
{
    int words=0,lines=0,i;
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]!=' ' &&  a[i+1]==' ')words++;
      else if(a[i]=='\n'){lines++;words++;}
      //printf(%c",a[i]);  
    }
    lines++;words++;
    printf("\n no of words is %d and no of line is %d \n",words,lines);    
}
void read(char *a,FILE* f)
{
    
printf("\n the content of the file is \n");



while(fgets(a,255,f))
{
printf("%s",a);

}

a[0]='\0';
rewind(f);
   // printf("inside");
    fread(a,100,1,f);

    //printf(" %s ",a);
}
int main()
{
    char a[100];
    //FILE *fp=fopen("newfile.txt","r");
    FILE *fp=open();
    if(fp==NULL)
    {
        printf("file cannot be opened");
        return 1;
    }
read(a,fp);
    //fread(a,100,1,fp);
    countwordsandlines(a);
    //printf("%s",a);
fclose(fp);

}
