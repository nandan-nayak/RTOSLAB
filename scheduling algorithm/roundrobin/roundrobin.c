#include<stdio.h>
#include "queue.c"



struct _execution_pool_ 
{

int processid;
int time;

};







void roundrobin(int AT[],int BT[], int n,int tq)
{
struct _execution_pool_ pool;
Queue q_instance=queue_new(10);
Queue *q = &q_instance;

Process process[10];
Process *executingprocess;
int currentprocessid;
int WT[10],TAT[10],FT[10],tempBT[10],p[10];
int i,j,temp;
int flag=0;
int timequantum=tq;
int sum=0,totalbursttime=0,time=0;
float avgwt,avgtat;


pool.time=-1;
pool.processid=-1;



for(i=0;i<n;i++)
p[i]=i+1;


printf("\n");
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		if(AT[i]<AT[j])
		{
			temp=AT[i];AT[i]=AT[j];AT[j]=temp;
			temp=BT[i];BT[i]=BT[j];BT[j]=temp;
			temp=p[i];p[i]=p[j];p[j]=temp;
		}
	}
}


for(i=0;i<n;i++)
{
process[i].bursttime=BT[i];
process[i].arrivaltime=AT[i];
process[i].processid=i;
process[i].finishtime=0;
process[i].waitingtime=0;
process[i].turnaroundtime=0;
process[i].totalbursttime=BT[i];

}





for(i=0;i<n;i++)
tempBT[i]=BT[i];

time=0;


while(1)
{
//printf("\n\n\ntime =%d\n",time);
	for(i=0;i<n;i++)
	{
		if(process[i].bursttime>0)
		{
			//printf("\nprocess %d with burst time %d",i,process[i].bursttime);
			flag=1;break;
		}	
	

	}
	if(flag==0)
	{
	//	printf("\nentered");
		break;
	
	}


	for(i=0;i<n;i++)
	{
		if(process[i].arrivaltime==time)
		{
		//	printf("\n process %d added to queue entered at %d",i,time);
			q=queue_add_head(q,&process[i]);		
			//printf("queue count is = %d ",q->count);		
		}
	}
	



	//printf("\npool time is %d",(time-pool.time)%tq);
	if((time-pool.time)%tq==0 && time!=0)
	{	pool.time=-1;
		if(pool.processid!=-1){
		//printf("\nprocess %d added to queue ",pool.processid);
		q=queue_add_head(q,&process[pool.processid]);
		}
		pool.processid=-1;
	}




	if(pool.time==-1 && q->count!=0){
		//printf("\n===================");
		executingprocess=queue_top(q);
	}else
		executingprocess=NULL; 
	



	if(executingprocess!=NULL)
	{
	//printf("\nexecuting  !NULL");
	currentprocessid=executingprocess->processid;
	//printf("\ncurrent process id is %d",currentprocessid);
	if(executingprocess->bursttime<=tq)
	{
		//printf("\n     process %d finished execution at %d",currentprocessid,time+process[currentprocessid].bursttime);
		process[currentprocessid].finishtime=time+process[currentprocessid].bursttime;
	process[currentprocessid].waitingtime=process[currentprocessid].finishtime-process[currentprocessid].totalbursttime-process[currentprocessid].arrivaltime;
		process[currentprocessid].turnaroundtime=process[currentprocessid].finishtime-process[currentprocessid].arrivaltime;		
		pool.processid=-1;
		pool.time=time+process[currentprocessid].bursttime;
		process[currentprocessid].bursttime=0;
		q=queue_remove(q);
		
		
		
	}
	else if(executingprocess->bursttime>tq)
	{
		process[currentprocessid].bursttime-=tq;
		//printf("\nprocess %d decreased burst time to %d",currentprocessid,process[currentprocessid].bursttime);
		pool.processid=currentprocessid;
		pool.time=time;
		q=queue_remove(q);
		//q=queue_add_head(&q,process[currentprocessid]);
		
	}
	
	}
	
	
	time++;
	flag=0;
}




printf("\ntotal burst time is %d",time);







printf("\n================================================");
printf("\nprocess	AT	BT	FT	WT	TAT");
printf("\n================================================");
printf("\n");
for(i=0;i<n;i++)
{
printf("\n%d	%d	%d	%d	%d	%d\n",p[i],process[i].arrivaltime,tempBT[i],process[i].finishtime,process[i].waitingtime,process[i].turnaroundtime);

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
int AT[10],BT[10],n,tq;
int i,j;

printf("\n enter number of process (<10) : ");
scanf("%d",&n); 

printf("\nenter the burst time \n");
for(i=0;i<n;i++)
scanf("%d",&BT[i]);




printf("\nenter the Arival time \n");
for(i=0;i<n;i++)
scanf("%d",&AT[i]);
printf("\n  enter time quantum :");
scanf("%d",&tq);
roundrobin(AT,BT,n,tq); 


}
