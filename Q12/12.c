





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
    FILE *fp=fopen("12input.txt","r");
    FILE *fp1=fopen("12output.txt","a");
    char name[100],course[120];
    char c[150];
   int marks;
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
    for(i=0;i<len;i++)
    {
        printf("\n %s %s %d %c ",(t[i].name),(t[i].course),t[i].marks,t[i].grade);
    }
    printf("\n");
    //printf("%d l is ",l);

for(i=0;i<len;i++)
{
    fprintf(fp1,"%s %s %d %c\n",t[i].name,t[i].course,t[i].marks,t[i].grade);
    
    
}


    
}
