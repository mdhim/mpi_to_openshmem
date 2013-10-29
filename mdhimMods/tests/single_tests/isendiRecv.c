*                                                                                                                             
*  isendiRcv.c                                                                                                                
*  mpiToOpenshmem                                                                                                             
*                                                                                                                             
*  Created by gingery on 10/28/13.                                                                                            
*  Copyright 2013 LANL. All rights reserved.                                                                                  
*                                                                                                                             
* Tests single int MPI_ISend/IRecvi                                                                                           
*/
#include <stdio.h>
#include <stdlib.h>
#include <shmem.h>

#include "mpi_to_openshmem.h"

int main(int argc, char *argv[])
{
	int provided, ret, size, rank;
	int nextpe;
	int src;
	int *dest;
	
	MPI_Status   status[2];
	MPI_Requests req[2];
	
	ret = MPI_Init_thread(&argc, &argv,  MPI_THREAD_MULTIPLE, &provided);
	if (ret != MPI_SUCCESS) {
		printf("Error initializing MPI with threads\n");
		exit(1);
	}
	
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	nextpe = (rank + 1) % size;
	
	src = rank;
	
	dest = (int *) shmalloc (sizeof (*dest));
	if (dest == NULL){
		printf("Couldn't shmalloc.\n");
	}
	
	*dest = 99;
	shmem_barrier_all ();
	
	//shmem_int_put (dest, &src, 1, nextpe);                                                                                     
	MPI_Isend(&src, 1, MPI_INT, nextpe, 123, MPI_COMM_WORLD, &req[0]);
	// shmem_int_get (dest, &src, 1, nextpe);                                                                                    
	MPI_Irecv(dest, 1, MPI_INT, nextpe, 123, MPI_COMM_WORLD, &req[1]);
	
	shmem_barrier_all ();
	
	printf ("%4d: got %4d, %4d: ", rank, *dest,src);
	if (*dest == rank)
    {
		printf ("CORRECT");
    }
	else
    {
		printf ("WRONG, expected %d", rank);
    }
	printf ("\n");
	
	shmem_barrier_all ();
	shfree (dest);
	return 0;
	
}
