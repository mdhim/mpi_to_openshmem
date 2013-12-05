/*
 *  mpi_test.c
 *  mpiToOpenshmem
 *
 *  Created by gingery on 10/28/13.
 *  Copyright 2013 LANL. All rights reserved.
 *
 * Simple test for MPI_Test for Isend & Irecv.
 */
#include <stdio.h>
#include <stdlib.h>
#include <shmem.h>

#include "mpi_to_openshmem.h"

#define BUF_SIZE 6

int main(int argc, char *argv[])
{
	int provided, ret, size, rank;
	int nextpe, i;
	long src[BUF_SIZE];
	long dest[BUF_SIZE];
	
	ret = MPI_Init_thread(&argc, &argv,  MPI_THREAD_MULTIPLE, &provided);
	if (ret != MPI_SUCCESS) {
		printf("Error initializing MPI with threads\n");
		exit(1);
	}
	
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	MPI_Status   status[size];
	MPI_Request  req[size];
	
	nextpe = (rank +1) % size;
	
	for ( i = 0; i < BUF_SIZE; i++){
		dest[i] = 99;
		src[i]  = nextpe + i;
	}
	shmem_barrier_all ();
	
	//shmem_long_put (dest, src, BUF_SIZE, nextpe);
	//shmem_fence();
	printf("Sending: src[0]: %ld to PE: %d from PE: %d\n\n", src[0], nextpe, rank);
	MPI_Isend(&src, BUF_SIZE, MPI_LONG, nextpe, 123, MPI_COMM_WORLD, &req[0]);
	
	int flag = -1;
	MPI_Test( &req[0], &flag, &status[0]);
	
	
	//shmem_long_get (dest, &src, BUF_SIZE, nextpe);
	MPI_Irecv(dest, BUF_SIZE, MPI_LONG, nextpe, 123, MPI_COMM_WORLD, &req[1]);
	MPI_Test( &req[1], &flag, &status[1]);
	
	//shmem_barrier_all ();
	
	for (i=0; i<BUF_SIZE;i++){
		printf ("Rank: %4d: got src[%d]: %4ld, dest[]: %4ld\n", rank, i, src[i],dest[i]);
	}
	
	//printf ("Rank: %4d: got dest[5]: %4ld, src[5]: %4ld: ", rank, dest[5],src[5]);
	if (dest[0] == nextpe){
		printf ("CORRECT");
	}
	else{
		printf ("PE:%d, WRONG, expected %d", rank, nextpe);
	}
	
	printf ("\n");
	
	return 0;
	
}

