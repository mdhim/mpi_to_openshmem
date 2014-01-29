/*
 *  gather.c
 *  mpiToOpenshmem
 *
 *  Created by gingery on 10/31/13.
 *  Copyright 2013 LANL. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <shmem.h>
#include "mpi_to_openshmem.h"

#define DST_SIZE 40
#define SRC_SIZE 11

int me, npes;

int main(int argc, char *argv[]){
	int i, ret;
	int provided;
	int *src, *dst;
	
	ret = MPI_Init_thread(&argc, &argv,  MPI_THREAD_MULTIPLE, &provided);
	if (ret != MPI_SUCCESS) {
		printf("Error initializing MPI with threads\n");
		exit(1);
	}
	
	MPI_Comm_size(MPI_COMM_WORLD, &npes);
	MPI_Comm_rank(MPI_COMM_WORLD, &me);
	
	// If you want a thorough test, you need to try all combinations:
	//src = (int*)shmalloc( SRC_SIZE * sizeof(int));
	src = (int*)malloc( SRC_SIZE * sizeof(int));
	//dst = (int*)shmalloc( DST_SIZE * sizeof(int));
	dst = (int*)malloc( DST_SIZE * sizeof(int));
	
	
	for (i = 0; i < DST_SIZE; i++){
		dst[i] = -1;
	}
	
	for (i = 0; i < SRC_SIZE; i++){
		src[i] = 10+i;
	}
	
	int count = 10;
	
	// set the data, so I can see it better
	for (i = 0; i < count; i++){
		src[i] = src[i] + me;
	}
	printf ("Debug: src[%d/%d] =", me, npes);
	for (i = 0; i < count; i += 1) {
		printf (" %d", src[i]);
	}
	printf("\n");
	
	
	// try to gather all data
	int root = 2;
	//shmem_barrier_all();
	MPI_Gather (src, count, MPI_INT, dst, count, MPI_INT, root, MPI_COMM_WORLD);
	// shmem_int_put(&dst[count*me], src, count, root);
	
	if (me == root){
		printf ("After gather,: dst[%d/%d] =", me, npes);
		for (i = 0; i < DST_SIZE; i += 1) {
			printf (" %d", dst[i]);
		}
		printf ("\n");
	}
	
	return 0;
}

