#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
void main()
{

int pid;
int seq=0;

pid=fork();

if(pid==0)
{
//child
seq++;
printf("\n inside child %d ",seq++);
//printf(" %d ",seq);
}


else
{
// parent 
//wait(NULL);
seq++;
printf("\n inside parent %d",seq++);

}

printf(" %d \n",seq);

}
