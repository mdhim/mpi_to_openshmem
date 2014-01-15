/*
 *  broadcast1.c
 *  mpiToOpenshmem
 *
 *  Created by gingery on 10/16/13.
 *  Copyright 2013 LANL. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "mpi_to_openshmem.h"


int main(int argc, char **argv) {
	int i, ret;
	long *source;
	int  bufsize;
	int  rank, npes;
	int  size;
	int  provided;
	int  isGood = TRUE;
	
	ret = MPI_Init_thread(&argc, &argv, MPI_THREAD_MULTIPLE, &provided);
	if (ret != MPI_SUCCESS) {
		printf("Error initializing MPI with threads\n");
		exit(1);
	}
	
	MPI_Comm_rank ( MPI_COMM_WORLD, &rank);
	MPI_Comm_size ( MPI_COMM_WORLD, &npes);
    
	int my_pe = shmem_my_pe();
	//printf("Main,  my_pe: %-8d, rank: %d, size: %d\n", my_pe, rank, npes);
	
	size = npes * 3; 
	bufsize = size * sizeof( *source );
	source = (long *)malloc (bufsize);
	
	for (i = 0; i < size; i++){
		if (rank == 0) source[i] = 1 + i;
		else  source[i] = 999;
	}
	
	MPI_Bcast(source, size, MPI_LONG, 0, MPI_COMM_WORLD);
	//int root = 0;
	//shmem_broadcast64( target, source, size, root, 0, 0, npes, pSync);
	
	// Check that the value is as expected
	for (i = 0; i < size; i++){
		if ( source[i] != (i+1) ){
			isGood = FALSE;
			printf("Failed. my_pe: %-8d, source[%d] = %ld, expected %d\n", my_pe, i, source[i], (i+1));
		}
	}
	if (isGood){
		printf("Passed, my_pe: %d\n",my_pe);
	}
	
	return isGood;
	
}
