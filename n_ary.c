

/*
N - ary search
*/

#include<stdio.h>
#include<omp.h>

int main()
{
	int arr[100],n,e,p,beg,end,mid,item,part,temp,t=0;


	printf("Enter No. of Elements= ");
	scanf("%d",&n);

	int th_id, nthreads;

	int i=0;
	for(i=0; i < n;i++)
	{		
		arr[i]=i;
	}
	
	printf("\nEnter the element to be searched :  ");
	scanf("%d",&item);
	printf("\n\tEnter number of parts : ");
	scanf("%d",&part);
	
	temp=n/part;
	
		//printf("\nTEMP = %d \n",temp);
	
	beg=0;
	end=temp-1;
	
	
	while(beg<=end)
	{

	 #pragma omp parallel
	
		mid=end;	
		printf(" MId =  %d",mid);
		
		if(arr[mid]==item)
		{
			printf("\nItem found at %d \n",mid);
			break;
		}	
			
		else if (item<arr[mid])
				end=mid-1;
			else
			{	beg=mid+1;
				end=end+temp;
			}
		
		if(end>n-1)
		{
			end=n-1;
		}
		
		
	}
if(beg>end)
	printf("\nELement not found\n");


	
	return 0;
}
/*
prjlab36@prjlab36-HP-dx2480-MT-KL969AV:~/TE74$ gcc -fopenmp n_ary.c
prjlab36@prjlab36-HP-dx2480-MT-KL969AV:~/TE74$ OMP_NUM_THREADS=5
prjlab36@prjlab36-HP-dx2480-MT-KL969AV:~/TE74$ ./a.out

Enter the element to be searched :  5

	Enter number of parts : 6

TEMP = 3 
Hello World from thread 0
Hello World from thread 1
There are 2 threads
  2  5
Item found at 5 prjlab36@prjlab36-HP-dx2480-MT-KL969AV:~/TE74$ 
*/





