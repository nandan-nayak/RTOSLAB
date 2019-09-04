#include<stdio.h>

void roundrobin(int AT[],int BT[], int n,int tq)
{
int WT[10],TAT[10],FT[10],tempBT[10];
int i,j,temp;
int timequantum=tq;
int sum=0,totalbursttime=0,time=0;
float avgwt,avgtat;
printf("\n");
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		if(AT[i]<AT[j])
		{
			temp=AT[i];AT[i]=AT[j];AT[j]=temp;
			temp=BT[i];BT[i]=BT[j];BT[j]=temp;
		}
	}
}

for(i=0;i<n;i++)
tempBT[i]=BT[i];

for(i=0;i<n;i++)
totalbursttime+=BT[i];

printf("total BT :%d",totalbursttime);
while(time<totalbursttime)
{
for(i=0;i<n;i++)
{
//printf("\nprocess %d %d %d",i+1,time,BT[i]);
	if(BT[i]>0)
	{
		
		if(BT[i]<=timequantum)
		{
			FT[i]=time+BT[i];
			time=time+BT[i];
			BT[i]=0;
		}
		else
		{
			time=time+timequantum;
			BT[i]=BT[i]-timequantum;
		}



	}

}


}





for(i=0;i<n;i++)
{
WT[i]=FT[i]-tempBT[i]-AT[i];
TAT[i]=FT[i]-AT[i];
}



printf("\n waiting time is \n");


printf("\n================================================");
printf("\nprocess	AT	BT	FT	WT	TAT");
printf("\n================================================");
printf("\n");
for(i=0;i<n;i++)
{
printf("\n%d	%d	%d	%d	%d	%d\n",i,AT[i],tempBT[i],FT[i],WT[i],TAT[i]);

}


for(i=0;i<n;i++)
{
sum=sum+WT[i];
}
avgwt=sum/(float)n;

sum=0;
for(i=0;i<n;i++)
{
sum=sum+TAT[i];
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
