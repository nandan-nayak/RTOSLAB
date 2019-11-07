// Banker's Algorithm 
#include <stdio.h> 
int main() 
{ 
	// P0, P1, P2, P3, P4 are the Process names here 

	int iter=0,remainingprocess=0,count=0,x,t,flag2=0;
	int fakealloc[3]={0,0,0};
	int n, m, i, j, k; 
	n = 5; // Number of processes 
	m = 3; // Number of resources 
	int alloc[5][3] = { { 0, 1, 0 }, // P0 // Allocation Matrix 
						{ 2, 0, 0 }, // P1 
						{ 3, 0, 2 }, // P2 
						{ 2, 1, 1 }, // P3 
						{ 0, 0, 2 } }; // P4 

	int max[5][3] = { { 7, 5, 3 }, // P0 // MAX Matrix 
					{ 3, 2, 2 }, // P1 
					{ 9, 0, 2 }, // P2 
					{ 2, 2, 2 }, // P3 
					{ 4, 3, 3 } }; // P4 

	int avail[3] = { 1, 3, 2 }; // Available Resources 

	int f[n], safesequence[n], ind = 0; 
	for (k = 0; k < n; k++) { 
		f[k] = 0; 
	} 
	int need[n][m]; 
	for (i = 0; i < n; i++) { 
		for (j = 0; j < m; j++) 
			need[i][j] = max[i][j] - alloc[i][j]; 
	} 
	int y = 0; 




do { 
count=0;
for(i=0;i<n;i++)
{
if(f[i]==0)count++;

}
//printf("\nremaining process 1=%d",count);
remainingprocess=count;

		for (i = 0; i < n; i++) 
		{ 

		//printf("\nfor %d ",i);

			if (f[i] == 0)
			 { 
				for(j=0;j<m;j++)
				{
					if(need[i][j]<=avail[j])//check if need is > avail,  if yes then iterate otherwise break
					{//	printf("\n need %d  >   %d",need[i][j],avail[j]);	
						continue;
					}
					else
						break;
					
				}
				if(j==m)	//if j==m then need is satisfied	
				{
					//printf("\n safe %d",i);
					safesequence[ind++]=i;
					f[i]=1;
					for(k=0;k<m;k++)
					{
						avail[k]=avail[k]+need[i][k];
					}
					printf("\n\n avail = %d %d %d",avail[0],avail[1],avail[2]);
				}	
				


			} 
		} 
iter++;
count=0;
for(i=0;i<n;i++)
{
if(f[i]==0)count++;

}
if(remainingprocess==count && remainingprocess!=0)
{
for(x=0;x<3;x++)
{
	fakealloc[x]=alloc[x];
}
printf("\ndeadlock occured");

for(x=0;x<n;x++)
{
	if(f[x]==0)
	{
		for(t=0;t<m;t++)
		{	
			
		
		}
	}


}







}
//printf("\nremaining process 2=%d",count);
	

}while(iter<3); 






for(i=0;i<n;i++)
{
	printf("\n");
	for(j=0;j<m;j++)
	{
		printf("\t%d",need[i][j]);
		
	}




}

printf("\n\n");


	printf("Following is the SAFE Sequence\n"); 
	for (i = 0; i < ind-1; i++) 
		printf(" P%d ->", safesequence[i]); 
	printf(" P%d", safesequence[ind - 1]); 



printf("\n");
	return (0); 

	
} 

