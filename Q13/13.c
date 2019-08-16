




#include<stdio.h>

#include<string.h>
struct student
{
    char name[20];
    char course[20];
    int marks;
    char grade;
    
};

void main()
{
    FILE *fp=fopen("13input.txt","r");
    FILE *fp1=fopen("13output.txt","a");
    
    char name[100],course[120];
    char c[150],grade;
   int marks,count=0;
struct student t[10],temp;
int i=0,j,len=0;

while(fgets(c, 255, fp) != NULL) {
 
   sscanf(c,"%s %s %d",name,course,&marks);
   
    strcpy(t[len].name,name);
   strcpy(t[len].course,course);
    t[len].marks=marks;
    if(marks>=90)
    t[len].grade='A';
    else if(marks>=70)
    t[len].grade='B';
    else if(marks>=40)
    t[len].grade='C';
    else
    t[len].grade='D';
len++;
    }  
    for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++)
        {
            if(t[i].marks<t[j].marks)
            {
                temp=t[i];
                t[i]=t[j];
                t[j]=temp;
                
            }
        }  
        
    }
printf("\n the input file content is :\n");
printf("=====================================\n");
    for(i=0;i<len;i++)
    {
        printf("\n %s %s %d ",(t[i].name),(t[i].course),t[i].marks);
    }
    printf("\n");
    //printf("%d l is ",l);



printf("\n the output file content is :\n");
printf("====================================\n");
for(i=0;i<len;i++)
{
    fprintf(fp1,"%s %s %d %c\n",t[i].name,t[i].course,t[i].marks,t[i].grade);
    
    
}
fclose(fp);
fclose(fp1);
fp1=fopen("13output.txt","r");
while(fgets(c,255,fp1)!=NULL)
{
    printf("\n%s ",c);
    sscanf(c,"%s %s %d %c\n",name,course,&marks,&grade);
    if(grade=='A')count++;
    
}
printf("\ntotal number of students with grade 'A' is %d \n",count);
   }
