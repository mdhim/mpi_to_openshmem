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

#define DST_SIZE 20

static long src[4] = { 11, 12, 13, 14 };
static long dst[DST_SIZE];


int me, npes;

int main(int argc, char *argv[]){
	int i, ret;
	int provided;
	
	ret = MPI_Init_thread(&argc, &argv,  MPI_THREAD_MULTIPLE, &provided);
	if (ret != MPI_SUCCESS) {
		printf("Error initializing MPI with threads\n");
		exit(1);
	}
	
	MPI_Comm_size(MPI_COMM_WORLD, &npes);
	MPI_Comm_rank(MPI_COMM_WORLD, &me);
	
	for (i = 0; i < DST_SIZE; i++)
    {
		dst[i] = -1;
    }
	
	if (me == 1){
		src[1]=21;
	}
		
	MPI_Gather( src, 4, MPI_INT, dst, 20, MPI_INT, 0, MPI_COMM_WORLD); 
	show_dst ("AFTER");
	
	return 0;
}

show_dst (char *tag)
{
	int i;
	printf ("%8s: dst[%d/%d] =", tag, me, npes);
	for (i = 0; i < DST_SIZE; i += 1)
    {
		printf (" %ld", dst[i]);
    }
	printf ("\n");
}
