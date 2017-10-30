/*Assignment No-
Title:Implement a parallel quick sort algorithm using NVIDIA GPU or equivalent ARM Board
Roll NO-

*/


#include<stdio.h>
#include<omp.h>
void quicksort(int [10],int,int);

int main()
{
    int x[20],size,i;

    printf("Enter size of the array: ");
    scanf("%d",&size);

	printf("Enter %d elements: ",size);
	for(i=0;i<size;i++)
        scanf("%d",&x[i]);
	#pragma omp parallel
	{
	   quicksort(x,0,size-1);

	   printf("Sorted elements: ");
        for(i=0;i<size;i++)
	 
        printf(" %d",x[i]);

	printf("\n");
	 // return 0;
}
}

void quicksort(int x[10],int first,int last)
{
    int pivot,i,temp,j;

     if(first<last)
     {
         pivot=first;
         i=first;
         j=last;

         while(i<j)
         {
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
                 
             if(i<j)
             {
                 temp=x[i];
                 x[i]=x[j];
                 x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

    }
}

/*--------------------------------------------------
OUTPUT


prjlab27@prjlab27-dx2480-MT:~/Desktop$ gcc -fopenmp quick.c
prjlab27@prjlab27-dx2480-MT:~/Desktop$ ./a.out

Enter size of the array: 4
Enter 4 elements: 8
9
1
4
Sorted elements:  1 4 8 9
Sorted elements:  1 4 8 9
*/
