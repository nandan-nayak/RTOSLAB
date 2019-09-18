#include<stdio.h>


void sjf(int AT[],int BT[], int n)
{
int WT[10],TAT[10],FT[10],tempBT[10],tempAT[10];
int i,j,temp;
int time=0;
int sum=0;
int totalbursttime=0;
int index=0;


float avgwt,avgtat;
printf("\n");

//sorting Arrival time
for(i=0;i<n-1;i++)
{
	for(j=i+1;j<n;j++)
	{
		if(AT[i]<AT[j] )
		{
			if(AT[i]>=totalbursttime)
			{
			//printf("\nentered");	
			}
			else
			{
				if(BT[i]>BT[j]){
				temp=AT[i];AT[i]=AT[j];AT[j]=temp;
				temp=BT[i];BT[i]=BT[j];BT[j]=temp;}
			}	
						
		}


		else
		{
			if(BT[i]>BT[j]){
			temp=AT[i];AT[i]=AT[j];AT[j]=temp;
			temp=BT[i];BT[i]=BT[j];BT[j]=temp;}
		}



		
	}
totalbursttime+=BT[i];
}



//calculate FT WT
for(i=0;i<n;i++)
{
time=time+BT[i];
//printf("\n%d",time);
FT[i]=time;

WT[i]=(FT[i]-BT[i]-AT[i]<0)? 0:FT[i]-BT[i]-AT[i];
TAT[i]=FT[i]-AT[i];

}









printf("\n waiting time is \n");


printf("\n================================================");
printf("\nprocess	AT	BT	FT	WT	TAT");
printf("\n================================================");
printf("\n");
for(i=0;i<n;i++)
{
printf("\n%d	%d	%d	%d	%d	%d\n",i,AT[i],BT[i],FT[i],WT[i],TAT[i]);

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
int AT[10],BT[10],n;
int i,j;

printf("\n enter number of process (<10) : ");
scanf("%d",&n); 

printf("\nenter the burst time \n");
for(i=0;i<n;i++)
scanf("%d",&BT[i]);




printf("\nenter the Arival time \n");
for(i=0;i<n;i++)
scanf("%d",&AT[i]);
sjf(AT,BT,n);





}
