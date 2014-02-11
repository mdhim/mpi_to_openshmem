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

int me, npes;

int main(int argc, char *argv[]){
	int i, ret;
	int provided;
	int *src, *rbuf, *displs, *rcounts;
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
	total = (stride + count) * (npes);
	
	//if (me ==0) printf ("Total: %d, npes: %d, stride: %d\n", total, npes, stride); 
	//if (me ==0) printf ("Size: %d\n", size);
	
	// One needs to switch the src & rbuf *malloc's around to test all combinations...
	//src     = (int *)shmalloc(SRC_SIZE *sizeof(int));
	src     = (int *)malloc(SRC_SIZE *sizeof(int));
	//rbuf    = (int *)shmalloc(total *sizeof(int));
	rbuf    = (int *)malloc(total *sizeof(int));
	displs  = (int *)malloc(npes  *sizeof(int));
	rcounts = (int *)malloc(npes  *sizeof(int));
	
	// Init source:
	for (i=0; i < SRC_SIZE; i++){
		src[i] = i;
	}
	
	// Set the number of int to receive for each cpu:
	for (i = 0; i < npes; i++){
		rcounts[i] = 3;
	} 
	
	for (i = 0; i< npes;i++){
		displs[i] = i * (stride + count);
	}
	
	if (rbuf == NULL) printf("Shmalloc for rbuf failed\n");
	for (i = 0; i < total; i++){
		rbuf[i] = 200;
	}
    
	// set the data, so I can see it better
	for (i = 0; i < SRC_SIZE; i++){
		src[i] = src[i] + me*10;
	}
	/*printf ("Debug: src[%d/%d] =", me, npes);
	 *
	 for (i = 0; i < SRC_SIZE; i += 1) {
	 printf (" %d", src[i]);
	 }
	 printf("\n");
	 **/
	
	// try to gather all data
	//shmem_fence();
	//printf(" me: %d, rbuf[%d] =  %d, displs[%d] = %d, root: %d\n", me, me, rbuf[me], me, displs[me], root
	);
	MPI_Gatherv (src, count, MPI_INT, rbuf, rcounts, displs, MPI_INT, root, MPI_COMM_WORLD);
	//shmem_int_put(&(rbuf[displs[me]]), src, rcounts[me], root);
	
	//shmem_fence();
	
	if (me == root){
		//printf ("Total: %d\n", total);
		printf ("After gatherv,: dst[%d/%d] =", me, npes);
		for (i = 0; i < total; i++) {
			printf (" %d", rbuf[i]);
		}
		printf ("\n");
	}
	/**/
	return 0;
}
