#include<iostream>

#include<omp.h>
using namespace std;

int main()
 {
 	int i,n,j,p,a[20],temp;
 	
 	//ARRAY INPUT
 	cout<<"\nEnter element count in array:";
 	cin>>n;
 	cout<<"\nEnter "<<n<<" elements:\n";
 	for(j=0;j<n;j++)
 	 {
 	 	cin>>a[j];
 	 }
 	 
 	 //DISPLAY ARRAY
 	 cout<<"\nArray elements are: \n";
 	 cout<<"[";
         for(j=0;j<n;j++)
          
          {
             cout<<"  ";
             cout<<a[j];
             
          }
          cout<<"  ]";
          cout<<"\n";
          
          //SORTING
          
          #pragma omp parallel
       
          for(p=0;p<n;p++)
           {
                cout<<"\nSorting:";
           	if (p%2==0)
           	 {
           	 	cout<<"\nIn EVEN phase";
           	 	for(i=2;i<n;i+=2)
           	 	 {
           	 	 	if(a[i]<a[i-1])
           	 	 	 {
           	 	 	 	temp=a[i];
           	 	 	 	a[i]=a[i-1];
           	 	 	 	a[i-1]=temp;
           	 	 	 }
           	 	 }
           	 	 cout<<"\n";
           	 	 cout<<"Iteration "<<p+1<<":  ";
           	 	 cout<<"[";
         		 for(j=0;j<n;j++)
          		  {
            			  cout<<"  ";
            			  cout<<a[j];
             
         		  }
          		  cout<<"  ]";
        		  cout<<"\n";	
           	 }
           	else
           	 {
           	 	cout<<"\nIn ODD phase";
      
           	 	for(i=1;i<n;i+=2)
           	 	 {
           	 	 	if(a[i]<a[i-1])
           	 	 	 {
           	 	 	 	temp=a[i];
           	 	 	 	a[i]=a[i-1];
           	 	 	 	a[i-1]=temp;
           	 	 	 }
           	 	 }	
           	 
           	 cout<<"\n";
           	  cout<<"Iteration "<<p+1<<":  ";
 	 	 cout<<"[";
         	 for(j=0;j<n;j++)
          	  {
            		  cout<<"  ";
            		  cout<<a[j];
             
         	  }
          	  cout<<"  ]";
        	  cout<<"\n";
               }	 
           }
           cout<<"\n**************************************************\n";
           cout<<"\nSorted Array is:\n";
            cout<<"[";
         	 for(j=0;j<n;j++)
          	  {
            		  cout<<"  ";
            		  cout<<a[j];
             
         	  }
          	  cout<<"  ]";
        	  cout<<"\n";
          
          
 } 
 
 /*OUTPUT
prjlab@prjlab-dx2480-MT:~$ g++ -fopenmp oddeven61.cpp
prjlab@prjlab-dx2480-MT:~$ export OMP_NUM_THREADS=4
prjlab@prjlab-dx2480-MT:~$ ./a.out

Enter element count in array:8

Enter 8 elements:
4 
2
7
8
5
1
3
6

Array elements are: 
[  4  2  7  8  5  1  3  6  ]

Sorting:
In EVEN phase
Iteration 1:  [  4  2  7  5  8  1  3  6  ]

Sorting:
In ODD phase
Iteration 2:  [  2  4  5  7  1  8  3  6  ]

Sorting:
In EVEN phase
Iteration 3:  [  2  4  5  1  7  3  8  6  ]

Sorting:
In ODD phase
Iteration 4:  [  2  4  1  5  3  7  6  8  ]

Sorting:
In EVEN phase
Iteration 5:  [  2  1  4  3  5  6  7  8  ]

Sorting:
In ODD phase
Iteration 6:  [  1  2  3  4  5  6  7  8  ]

Sorting:
In EVEN phase
Iteration 7:  [  1  2  3  4  5  6  7  8  ]

Sorting:
In ODD phase
Iteration 8:  [  1  2  3  4  5  6  7  8  ]

Sorting:
In EVEN phase
Iteration 1:  [  1  2  3  4  5  6  7  8  ]

Sorting:
In ODD phase
Iteration 2:  [  1  2  3  4  5  6  7  8  ]

Sorting:
In EVEN phase
Iteration 3:  [  1  2  3  4  5  6  7  8  ]

Sorting:
In ODD phase
Iteration 4:  [  1  2  3  4  5  6  7  8  ]

Sorting:
In EVEN phase
Iteration 5:  [  1  2  3  4  5  6  7  8  ]

Sorting:
In ODD phase
Iteration 6:  [  1  2  3  4  5  6  7  8  ]

Sorting:
In EVEN phase
Iteration 7:  [  1  2  3  4  5  6  7  8  ]

Sorting:
In ODD phase
Iteration 8:  [  1  2  3  4  5  6  7  8  ]

Sorting:
In EVEN phase
Iteration 1:  [  1  2  3  4  5  6  7  8  ]

Sorting:
In ODD phase
Iteration 2:  [  1  2  3  4  5  6  7  8  ]

Sorting:
In EVEN phase
Iteration 3:  [  1  2  3  4  5  6  7  8  ]

Sorting:
In ODD phase
Iteration 4:  [  1  2  3  4  5  6  7  8  ]

Sorting:
In EVEN phase
Iteration 5:  [  1  2  3  4  5  6  7  8  ]

Sorting:
In ODD phase
Iteration 6:  [  1  2  3  4  5  6  7  8  ]

Sorting:
In EVEN phase
Iteration 7:  [  1  2  3  4  5  6  7  8  ]

Sorting:
In ODD phase
Iteration 8:  [  1  2  3  4  5  6  7  8  ]

Sorting:
In EVEN phase
Iteration 1:  [  1  2  3  4  5  6  7  8  ]

Sorting:
In ODD phase
Iteration 2:  [  1  2  3  4  5  6  7  8  ]

Sorting:
In EVEN phase
Iteration 3:  [  1  2  3  4  5  6  7  8  ]

Sorting:
In ODD phase
Iteration 4:  [  1  2  3  4  5  6  7  8  ]

Sorting:
In EVEN phase
Iteration 5:  [  1  2  3  4  5  6  7  8  ]

Sorting:
In ODD phase
Iteration 6:  [  1  2  3  4  5  6  7  8  ]

Sorting:
In EVEN phase
Iteration 7:  [  1  2  3  4  5  6  7  8  ]

Sorting:
In ODD phase
Iteration 8:  [  1  2  3  4  5  6  7  8  ]

**************************************************

Sorted Array is:
[  1  2  3  4  5  6  7  8  ]
*/
