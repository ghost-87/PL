
/*
Implement concurrent prims algorithm using OPENMP

*/

#include<stdio.h>
#include<omp.h>


int a,b,u,v,n,i,j,ne=1;
int visited[10]={0},min,mincost=0,cost[10][10];
void main()
{
	#pragma omp parallel
	
	printf("\nEnter the number of nodes:");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		scanf("%d",&cost[i][j]);
		if(cost[i][j]==0)
		cost[i][j]=999;
	}
	
visited[1]=1;
printf("\n");

  
#pragma omp parallel
while(ne < n)
{
printf("\n\t---- WHILE -----");
min=999;

		
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(cost[i][j]< min){
				if(visited[i]!=0)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
	}			
	if(visited[u]==0 || visited[v]==0)
	{
		printf("\n Edge %d:(%d %d) cost:%d",ne++,a,b,min);
		mincost+=min;
		visited[b]=1;
	}
	
	cost[a][b]=cost[b][a]=999;

}

	printf("\n Minimun cost=%d",mincost);
printf("\n\t---- END -----");
printf("\n");

}//main()

/*
OUTPUT

prjlab36@prjlab36-HP-dx2480-MT-KL969AV:~$ gcc -fopenmp primscon.c
prjlab36@prjlab36-HP-dx2480-MT-KL969AV:~$ export OMP_NUM_THREADS=3
prjlab36@prjlab36-HP-dx2480-MT-KL969AV:~$ ./a.out

Enter the number of nodes:4

Enter the adjacency matrix:
0 2 0 1
2 0 0 2
0 0 0 3
1 2 3 0

	---- WHILE -----
 Edge 1:(1 4) cost:1
	---- WHILE -----
 Edge 2:(1 2) cost:2
	---- WHILE -----
	---- WHILE -----
 Edge 3:(4 3) cost:3
 Minimun cost=6
	---- END -----
prjlab36@prjlab36-HP-dx2480-MT-KL969AV:~/TE74$ 
*/

