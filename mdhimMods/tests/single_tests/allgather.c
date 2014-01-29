/*
 *  Allgather.c
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

#define DEST_SIZE 20
#define SRC_SIZE   4

int me, npes;

int main(int argc, char *argv[]){
	int i, ret;
	int provided;
	long *src;
	long *dest;
	
	ret = MPI_Init_thread(&argc, &argv,  MPI_THREAD_MULTIPLE, &provided);
	if (ret != MPI_SUCCESS) {
		printf("Error initializing MPI with threads\n");
		exit(1);
	}
	
	// Test the various configurations:
	//src = shmalloc ( SRC_SIZE  * sizeof(long) );
	//dest = shmalloc ( DEST_SIZE * sizeof(long) );  
	src = malloc ( SRC_SIZE  * sizeof(long) );
	dest = malloc ( DEST_SIZE * sizeof(long) );
	
	MPI_Comm_size(MPI_COMM_WORLD, &npes);
	MPI_Comm_rank(MPI_COMM_WORLD, &me);
	
	for (i = 0; i <SRC_SIZE; i++){
		src[i] = 11 + i;
	}
	for (i = 0; i < DEST_SIZE; i++) {
		dest[i] = -1;
	}
	
	if (me == 1){
		src[1]=21;
	}
	
	/* DEBUG:: *
	 for (i = 0; i <SRC_SIZE; i++){
	 printf ("rank: %d Src[%d] = %ld\n", me, i, src[i]);
	 } **/
	
	MPI_Allgather( src, SRC_SIZE, MPI_LONG, dest, DEST_SIZE, MPI_LONG, MPI_COMM_WORLD); 
	show_dst ("AFTER", dest);
	
	return 0;
}

void show_dst (char *tag, long *dest){
	int i;
	printf ("%8s: dest[%d/%d] =", tag, me, npes);
	for (i = 0; i < DEST_SIZE; i += 1){
		printf (" %ld", dest[i]);
    }
	printf ("\n");
	
	return;
}

