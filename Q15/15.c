
#include <stdio.h>

int main()
{ char str[100],temp[10];
   
    int i,j=0,k=0,number;
   FILE *fp=fopen("15input.txt","r");
   FILE *fp1=fopen("15output.txt","a");
 printf("\nThe content of the input file is\n ");
printf("========================================\n");
   while(fgets(str,255,fp)!=NULL)
   {
       for(i=0;str[i]!='\0';i++)
       {
          
          
           if(str[i]!='F' && (str[i+1]=='F' || str[i+1]=='\n' ||str[i+1]=='\0'))
           {
              
           for(;j<=i;j++,k++)
           {
              
               temp[k]=str[j];
               
           }
           
           temp[k]='\0';k=0;j++;
        fprintf(fp1,"%s ",temp);
           
           
       }
      
   }
   printf(" %s",str);j=0;
   }
   printf("\n\n\n");
  fclose(fp1);
  fp1=fopen("15output.txt","r");
  fgets(str,255,fp1);
  printf("\n the content of the output file is  \n");
printf("============================================\n");

printf("%s",str);
printf("\n");
   
   
   return 0;
}
