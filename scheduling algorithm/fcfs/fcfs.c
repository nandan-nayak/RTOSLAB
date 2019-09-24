#include<stdio.h>
#include "queue.c"


struct _pool_
{

int time;


};




void fcfs(int AT[],int BT[], int n)
{

struct _pool_ pool;

Process *executingprocess;
Queue q_instance=queue_new(10);
Queue *q = &q_instance;
Process  process[10];


int flag=0;
int currentprocessid;
int p[10];
int i,j,temp;
int time=0;
int sum=0;
float avgwt,avgtat;
printf("\n");



for(i=0;i<n;i++)
{
p[i]=i+1;

}


for(i=0;i<n-1;i++)
{
	for(j=i;j<n;j++)
	{
		if(AT[i]>AT[j])
		{

			
			temp=AT[i];AT[i]=AT[j];AT[j]=temp;
			temp=BT[i];BT[i]=BT[j];BT[j]=temp;
			temp=p[i];p[i]=p[j];p[j]=temp;
			

		}
	}
}



for(i=0;i<n;i++)
{
//
process[i].processid=i;
process[i].arrivaltime=AT[i];
process[i].bursttime=BT[i];
process[i].totalbursttime=BT[i];

process[i].finishtime=0;
process[i].waitingtime=0;
process[i].turnaroundtime=0;

}

pool.time=-1;


while(1)
{

	for(i=0;i<n;i++)
	{
		if(process[i].bursttime>0)
		{
			
			flag=1;
			break;
		}
	}

	


	if(flag==0)
	{
		
		break;	
	}

	
	for(i=0;i<n;i++)
	{
		if(process[i].arrivaltime==time)
		{
			//printf("\n process %d arrived at time %d",i,time);
			q=queue_add_head(q,&process[i]);		
					
		}
	}

	if(time-pool.time==0)
	{
		
		pool.time=-1;
	}

	if(q->count!=0 && pool.time==-1)
	{
		executingprocess=queue_top(q);
	}	
	else
	{
		executingprocess=NULL;
	}


	if(executingprocess!=NULL)
	{
		
		currentprocessid=executingprocess->processid;
		
		pool.time=executingprocess->totalbursttime+time;
		process[currentprocessid].bursttime=0;
		process[currentprocessid].finishtime=process[currentprocessid].totalbursttime+time;
		
	process[currentprocessid].waitingtime=process[currentprocessid].finishtime-process[currentprocessid].totalbursttime-process[currentprocessid].arrivaltime;
		process[currentprocessid].turnaroundtime=process[currentprocessid].finishtime-process[currentprocessid].arrivaltime;
		q=queue_remove(q);	
			
	}






time++;
flag=0;

}

printf("\n waiting time is \n");


printf("\n================================================");
printf("\nprocess	AT	BT	FT	WT	TAT");
printf("\n================================================");
printf("\n");
for(i=0;i<n;i++)
{
printf("\n%d	%d	%d	%d	%d 	%d\n",p[i],process[i].arrivaltime,process[i].totalbursttime,process[i].finishtime,process[i].waitingtime,process[i].turnaroundtime);

}





for(i=0;i<n;i++)
{
sum=sum+process[i].waitingtime;
}
avgwt=sum/(float)n;

sum=0;
for(i=0;i<n;i++)
{
sum=sum+process[i].turnaroundtime;
}
avgtat=sum/(float)n;


printf("\n\naverage TAT is %f\n average WT is %f \n",avgtat,avgwt);


}


void main()
{
int AT[10],BT[10],n;
int i,j;
//Process process[10];
printf("\n enter number of process (<10) : ");
scanf("%d",&n); 

printf("\nenter the burst time \n");
for(i=0;i<n;i++)
scanf("%d",&BT[i]);




printf("\nenter the Arival time \n");
for(i=0;i<n;i++)
scanf("%d",&AT[i]);
fcfs(AT,BT,n);





}
