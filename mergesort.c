#include<stdio.h>
#include<omp.h>
void mergesort(int a[],int i,int j);
void merge(int a[],int i1,int j1,int i2,int j2);
 
int main()
{
    int a[30],n,i;
    printf("Enter no of elements:");
    scanf("%d",&n);
    printf("Enter array elements:");
    
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    #pragma omp parallel  
    mergesort(a,0,n-1);
    printf("\nSorted array is :");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
        
    return 0;
}
 
void mergesort(int a[],int i,int j)
{
    int mid;
        
    if(i<j)
    {
        mid=(i+j)/2;
        mergesort(a,i,mid);        //left recursion
        mergesort(a,mid+1,j);    //right recursion
        merge(a,i,mid,mid+1,j);    //merging of two sorted sub-arrays
    }
}
 
void merge(int a[],int i1,int j1,int i2,int j2)
{
    int temp[50];    //array used for merging
    int i,j,k;
    i=i1;    //beginning of the first list
    j=i2;    //beginning of the second list
    k=0;
    
    while(i<=j1 && j<=j2)    //while elements in both
     {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    
    while(i<=j1)    //copy remaining elements of the first list
        temp[k++]=a[i++];
        
    while(j<=j2)    //copy remaining elements of the second list
        temp[k++]=a[j++];
        
    //Transfer elements from temp[] back to a[]
    for(i=i1,j=0;i<=j2;i++,j++)
        a[i]=temp[j];
    //    printf("\nMerge sort executed");
}

/*prjlab39@prjlab39-dx2480-MT:~$ export OMP_NUM_THREADS=4
prjlab39@prjlab39-dx2480-MT:~$ gcc -fopenmp mergesort.c
prjlab39@prjlab39-dx2480-MT:~$ ./a.out
Enter no of elements:10
Enter array elements:2 1 4 6 5 9 7 3 8 10 

Sorted array is :1 2 3 4 5 6 7 8 9 10 prjlab39@prjlab39-dx2480-MT:~$ 
*/
