
#include <stdio.h>

int main()
{ char str[100],temp[10];
   
    int i,j=0,k=0,number;
   FILE *fp=fopen("14input.txt","r");
   FILE *fp1=fopen("14outputeven.txt","a");
   FILE *fp2=fopen("14outputodd.txt","a");
   printf("\n the contents of input file is \n");
printf("===========================================\n");  

 while(fgets(str,255,fp)!=NULL)
   {
           sscanf(str,"%d",&number);
           
           if(number%2==0)
           {
              fprintf(fp1,"%d ",number);
           }
           else
           {
               fprintf(fp2,"%d ",number);
           }
       
   printf(" %s",str);j=0;
   }


fclose(fp1);fclose(fp2);
printf("\n\n\n");
fp1=fopen("14outputeven.txt","r");
printf("\n the contents of the even output file \n");
printf("===========================================\n");
while(fgets(str,255,fp1)!=NULL)printf("%s",str);




printf("\n\n\n");

fp2=fopen("14outputodd.txt","r");
printf("\n the contents of the odd output file \n");
printf("===========================================\n");
while(fgets(str,255,fp2)!=NULL)printf("%s",str);



fclose(fp1);fclose(fp2);
printf("\n");














   return 0;
}
