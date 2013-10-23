*  broadcast1.c
*  mpiToOpenshmem
*
*  Created by gingery on 10/16/13.
*  Copyright 2013 LANL. All rights reserved.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <shmem.h>
//#include <mpi.h>
#include "mpi_to_openshmem.h"


int main(int argc, char **argv) {
	printf ("broadcast1: begin  *************\n");
	
	int i, ret;
	long *source;
	int  bufsize;
	int  rank, npes;
	int  size;
	int  provided;
	MPI_Comm comm;
	
	printf ("Before calling mpi_init  *************\n");
	
	
	ret = MPI_Init_thread(&argc, &argv, MPI_THREAD_MULTIPLE, &provided);
	if (ret != MPI_SUCCESS) {
		printf("Error initializing MPI with threads\n");
		exit(1);
	}
	
	MPI_Comm_rank ( comm, &rank);
	MPI_Comm_size ( comm, &npes);
	
	int my_pe = shmem_my_pe();
	//printf("Main,  my_pe: %-8d, rank: %d, size: %d\n", my_pe, rank, npes);
	
	size = npes * 3; 
	bufsize = size * sizeof( *source );
	
	
	source = (long *) shmalloc (bufsize);
	
	for (i = 0; i < size; i += 1)
    {
		source[i] = i + 1;
		//printf("Main. my_pe: %-8d, source[%d] = %d\n", my_pe, i, source[i]); 
	}
	
	//printf("Before Calling mpi_bcast.\n");
	MPI_Bcast(source, size, MPI_LONG, 0, comm);
	//printf("After Calling mpi_bcast.\n");
	
	printf("Before Calling mpi_bcast. Root = 1\n");
	MPI_Bcast(source, size, MPI_LONG, 1, comm);
	//printf("After Calling mpi_bcast.\n");
	
	MPI_Finalize();
}
