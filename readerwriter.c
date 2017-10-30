#ifdef _OPENMP
#include <omp.h>
#endif
#include<stdio.h>

int  rcount,data;
omp_lock_t readlock;
omp_lock_t writelock;

void *reader(int argc)
{
	int f= ((int)argc);
	omp_set_lock(&readlock);
        rcount = rcount + 1;
        if ( rcount == 1 )
	    omp_set_lock(&writelock);
	omp_unset_lock(&readlock);
	printf("\nData read by the reader %d is %d\n", f, data);
	printf("Reader going to sleep for 3 sec.\n");
	sleep(3);
	omp_set_lock(&readlock);
	rcount = rcount - 1 ;
	if ( rcount == 0 )
		omp_unset_lock(&writelock);
	omp_unset_lock(&readlock);
     
}

void *writer(int argc)
{
	int f;
	f = ((int)argc);
	omp_set_lock(&writelock);
	data++;
	printf("\nData written by the writer %d is %d\n", f, data);
	printf("Writer going to sleep for 3 sec.\n");
	sleep(3);
	omp_unset_lock(&writelock);
}

int main()
{
omp_init_lock(&readlock);
omp_init_lock(&writelock);
omp_set_num_threads(3);
#pragma omp parallel
{
 int threadID=omp_get_thread_num();
  switch(threadID)
{
   case 0:sleep();
   case 1:writer(3);
          reader(3);
          threadID++;
     
}
}
return 0;
}

/*
to run program gcc -fopenmp filename.c
*/
