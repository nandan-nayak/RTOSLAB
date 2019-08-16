#include<stdio.h>
#include <stdlib.h>
#include<string.h>
struct telephone
{
    char first[20];
    char last[20];
    char contact[20];
    
    
};
void display(struct telephone t[], int l)
{
    
    int i;
    printf("\n the content is :");
    for(i=0;i<l;i++)
    {
        printf("\n%s  %s  %s  ",t[i].first,t[i].last,t[i].contact);
        
    }
    
    printf("\n\n");
    
}

void byname(struct telephone *t ,int l)
{
    int i,j,k;
    struct telephone temp;
    for(i=0;i<l;i++)
    {
        for(j=i;j<l;j++)
        {
          
               if(strcmp(t[i].first,t[j].first)>0 )
               {
	         temp=t[i];
                   t[i]=t[j];
                   t[j]=temp;
                   break;
               }
           
        }
    }
    
}

void bynumber(struct telephone *t, int l)
{
    
    
      int i,j,k;
    struct telephone temp;
    for(i=0;i<l;i++)
    {
        for(j=i;j<l;j++)
        {
            //printf("contact %s  %s ",t[i].contact,t[j].contact);
          
               if(strcmp(t[i].contact,t[j].contact)>0 )
               {
                   //printf("\n%c %c",t[i].contact[k],t[j].contact[k]);
                   temp=t[i];
                   t[i]=t[j];
                   t[j]=temp;break;
               }
           
        }
    }
    
    
    
    
}
void main()
{
    FILE *fp=fopen("9input.txt","r");
    char c[150];
    int choice;
struct telephone t[10];
int i=0,j=0,k=0,l=0,count=0;
 //count=0;
while(fgets(c, 255, fp) != NULL) {
sscanf(c,"%s %s %s",t[count].first,t[count].last,t[count].contact);   
	    


count++;
     l++;j=0;
    
        //printf("%s", c);
    }
    printf("\n");
    //printf("%d l is ",l);
do{
    
    printf("\n1:view entries ");
    printf("\n2:order base on name ");
    
    printf("\n3:order based on number");
    printf("\n4:exit");
    printf("\n enter your choice ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:display(t,l);break;
        case 2:byname(&t[0],l);display(t,l);break;
        case 3:bynumber(&t[0],l);display(t,l);break;
    default :exit(0);
        
        
    }
    
}while(choice!=4);




    
}
