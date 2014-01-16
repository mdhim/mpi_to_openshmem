/*
 *  testStart.c
 *  mpiToOpenshmem
 *
 *  Created by gingery on 10/17/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <shmem.h>
#include "mpi_to_openshmem.h"

#define TRUE      1
#define FALSE     0
#define MPI_CHAR  1

long pSync[_SHMEM_BCAST_SYNC_SIZE];

void initOpenShmem(){
	printf ("testStart::initOpenShmem.\n");
		
	start_pes (0);

	int rank = _my_pe ();
	int npes = _num_pes ();
	
	printf ("testStart::initOpenShmem. rank = %d, npes = %d\n", rank, npes);	
	
}

int main(int argc, char **argv) {
	printf ("testStart: begin  *************\n");

	int i;
	long *target;
	long *source;
	int me, npes, provided;
	
	//initOpenShmem();
	printf ("Before calling mpi_init  *************\n");
	
	int ret = MPI_Init_thread(&argc, &argv, MPI_THREAD_MULTIPLE, &provided);
	if (ret != MPI_SUCCESS) {
	  printf("Error initializing MPI with threads\n");
	  exit(1);
       	}

	me = _my_pe ();
	npes = _num_pes ();

	printf ("testStart::main. me = %d, npes = %d\n", me, npes);	
	
       	source = (long *) shmalloc (npes * sizeof (*source));
	for (i = 0; i < npes; i += 1)
	{
	    source[i] = i + 1;
	}
	
	//target = (long *) shmalloc (npes * sizeof (*target));
	//for (i = 0; i < npes; i += 1)
	//{
	//    target[i] = -999;
	//}
	
	/*for (i = 0; i < _SHMEM_BCAST_SYNC_SIZE; i += 1)
	{
	    pSync[i] = _SHMEM_SYNC_VALUE;
	}
	shmem_barrier_all ();
	
	shmem_broadcast64 (target, source, npes, 0, 0, 0, npes, pSync);
	
	for (i = 0; i < npes; i++)
	{
	    printf ("%-8d %ld\n", me, target[i]);
	}
	
	shmem_barrier_all ();
	
	shfree (target);
	shfree (source);
	*/
	int root;
	root = 0;
	int dataType;
	MPI_Comm  comm;
	dataType = MPI_LONG;
	printf("main: dataType: %d, %d\n", dataType, MPI_LONG);

	MPI_Bcast(source, npes, MPI_LONG,  root, comm);
	return 0;
}
