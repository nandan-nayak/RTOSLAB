#include<stdio.h>
#include<string.h>
int segregate(char *a,char *even,char *odd)
{ 
    int words=0,lines=0,i=0,j=0,k=0;
    FILE *fp2;
    FILE *fp3;
    char b[10],c[100],d[100];



    //printf("insode");
    for(;a[i]!='\0';i++)
    {


        if(a[i]!=' '  && ( a[i+1]==' ' ||a[i+1]=='\n' || a[i+1]=='\0'))
        {
            
            
            for(;j<=i;j++,k++)
            {
                b[k]=a[j];
                
            }
            b[k]=' ';b[k+1]='\0';j=j+1;k=0;
            words++;
       
            if(words%2==0)
            {
                fp2=fopen(even,"a");
                fwrite(b,1,strlen(b),fp2);
                fclose(fp2);
            }
            else
            {

                fp3=fopen(odd,"a");
                fwrite(b,1,strlen(b),fp3);
                 fclose(fp3);
            }
            b[0]='\0'; k=0;
        }
        
        
      //printf(%c",a[i]);  
    }
   b[0]='\0';
fclose(fp2);
fclose(fp3);


printf("\n even file content \n");
printf("==================================\n");
fp2=fopen(even,"r");
while(fscanf(fp2,"%s",a)!=-1)
{

printf("%s ",a);

}
fclose(fp2);






fp3=fopen(odd,"r");
printf("\n\n\nodd file content  \n");
printf("==================================\n");
while(fscanf(fp3,"%s",a)!=-1)
{

printf("%s ",a);

}
fclose(fp3);









}

void read(char *a,FILE* f)
{
    
    //printf("inside");
     fread(a,100,1,f);
    
}
int main(int argc,char* argv[])
{
    char a[100];
    FILE *fp1=fopen(argv[1],"r");


    if(argc!=4)
{
printf("%d",argc);
printf("\n usage ---> inputfile evenoutputfile  oddoutputfile ");
return 1;
}




printf("\n the content of input file is \n");
printf("==================================\n");
while(fgets(a,255,fp1))
{
printf("%s",a);

}
rewind(fp1);


  // printf("%s %s  %s",argv[1],argv[2],argv[3]);
  
   
   read(a,fp1);
   segregate(a,argv[2],argv[3]);
  // printf("%s",a);
   //segregate(a,fp2,fp3);
   
   fclose(fp1);
   printf("\n");
   
}
