/*
 *  gatherv.c
 *  mpiToOpenshmem
 *
 *  Created by gingery on 10/31/13.
 *  Copyright 2013 LANL. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>
#include <shmem.h>
#include "mpi_to_openshmem.h"

#define SRC_SIZE 25

//static long pSync[_SHMEM_BCAST_SYNC_SIZE];

static int src[25] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };
//static int dst[DST_SIZE];

int me, npes;

int main(int argc, char *argv[]){
	int i, ret;
	int provided;
	int *rbuf, *displs, *rcounts;
	int stride = 2;
	int count = 3; // number of ints/pe
	int total = 0;
	int root = 1;
	
	ret = MPI_Init_thread(&argc, &argv,  MPI_THREAD_MULTIPLE, &provided);
	if (ret != MPI_SUCCESS) {
		printf("Error initializing MPI with threads\n");
		exit(1);
	}
	
	MPI_Comm_size(MPI_COMM_WORLD, &npes);
	MPI_Comm_rank(MPI_COMM_WORLD, &me);
	
	// Grab the space needed for displs & rcounts arrays.
	
	int size = npes * sizeof(int);
	total = stride * (npes-1) + (npes * count);
	
	if (me ==0) printf ("Total: %d, npes: %d, stride: %d\n", total, npes, stride); 
	if (me ==0) printf ("Size: %d\n", size);
	
	displs = (int *)shmalloc(npes *sizeof(int));
	rcounts = (int*)shmalloc(npes *sizeof(int));
	rbuf = (int *) shmalloc( total *sizeof(int));
	
	// Set the number of int to receive for each cpu:
	for (i = 0; i < npes; i++){
		rcounts[i] = 3;
	} 
	
	for (i = 0; i< npes;i++){
		displs[i] = me * (stride + count);
	}
	
	if (rbuf == NULL) printf("Shmalloc for rbuf failed\n");
	for (i = 0; i < total; i++){
		rbuf[i] = -1;
	}
    
	// set the data, so I can see it better
	for (i = 0; i < SRC_SIZE; i++){
		src[i] = src[i] + me*10;
	}
	/*printf ("Debug: src[%d/%d] =", me, npes);
	 for (i = 0; i < SRC_SIZE; i += 1) {
	 printf (" %d", src[i]);
	 }
	 printf("\n");
	 */
	
	// try to gather all data
	shmem_fence();
	printf(" me: %d, rbuf[%d] =  %d, displs[%d] = %d, root: %d\n", me, me, rbuf[me], me, displs[me], root);
	MPI_Gatherv (src, count, MPI_INT, rbuf, rcounts, displs, MPI_INT, root, MPI_COMM_WORLD);
	//shmem_int_put(&(rbuf[displs[me]]), src, rcounts[me], root);
	
	//shmem_fence();
	
	if (me == root){
		printf ("Total: %d\n", total);
		printf ("After gatherv,: dst[%d/%d] =", me, npes);
		for (i = 0; i < total; i++) {
			printf (" %d", rbuf[i]);
		}
		printf ("\n");
	}
	/**/
	return 0;
}
