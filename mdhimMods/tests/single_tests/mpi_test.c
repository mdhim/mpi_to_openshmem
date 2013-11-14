/*
 *  mpi_test.c
 *  mpiToOpenshmem
 *
 *  Created by gingery on 10/28/13.
 *  Copyright 2013 LANL. All rights reserved.
 *
 * Simple test for MPI_Test(long) for Isend & Irecv.
 */
#include <stdio.h>
#include <stdlib.h>
#include <shmem.h>

#include "mpi_to_openshmem.h"

#define BUF_SIZE 100000

int main(int argc, char *argv[])
{
	int provided, ret, size, rank;
	int nextpe, i;
	static long src[BUF_SIZE];
	long *dest;
	
	MPI_Status   status[2];
	MPI_Request  req[2];
	
	ret = MPI_Init_thread(&argc, &argv,  MPI_THREAD_MULTIPLE, &provided);
	if (ret != MPI_SUCCESS) {
		printf("Error initializing MPI with threads\n");
		exit(1);
	}
	
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	nextpe = (rank + 1) % size;
	
	//src = rank;
	
	dest = (long *) shmalloc (BUF_SIZE * sizeof (*dest));
	if (dest == NULL){
		printf("Couldn't shmalloc.\n");
	}
	
	for ( i = 0; i < BUF_SIZE; i++){
		dest[i] = 99;
		src[i]  = BUF_SIZE * rank + i;
	}
	shmem_barrier_all ();
	
	//shmem_int_put (dest, &src, 1, nextpe);
	printf("Sending: %ld to %d from %d\n\n", src[0], nextpe, rank);
	MPI_Isend(&src, BUF_SIZE, MPI_LONG, nextpe, 123, MPI_COMM_WORLD, &req[0]);
	int flag = -1;
	MPI_Test( &req[0], &flag, &status[0]);
	
	
	// shmem_int_get (dest, &src, 1, nextpe);
	MPI_Irecv(dest, BUF_SIZE, MPI_LONG, nextpe, 123, MPI_COMM_WORLD, &req[1]);
	MPI_Test( &req[1], &flag, &status[1]);
	
	shmem_barrier_all ();
	
	printf ("Rank: %4d: got[5] %4ld, %4ld: ", rank, dest[5],src[5]);
	if (dest[0] == rank * BUF_SIZE)
    {
		printf ("CORRECT");
    }
	else{
		printf ("WRONG, expected %d", rank);
	}
	printf ("\n");
	
	shmem_barrier_all ();
	
	return 0;
	
}
