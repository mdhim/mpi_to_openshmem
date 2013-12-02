/*                                                                                       
 *  groups.c                                                                             
 *  mpiToOpenshmem                                                                       
 *                                                                                       
 *  Simple test for doing groups and communicator commands.  Needs 4 PEs!   
 *  It's a rather silly test, since it is hard coded for 4 PEs.
 *                                                                                       
 *  Created by gingery on 11/20/13.                                                      
 *  Copyright 2013 LANL. All rights reserved.                                            
 *                                                                                       
 */
#include <stdio.h>
#include <stdlib.h>
#include <shmem.h>
#include "mpi_to_openshmem.h"
int main(int argc, char *argv[])
{
	int provided, ret, size, rank;
	int i;
	int comm_size;
	int *ranks;
	
	MPI_Group orig, new_group;
	MPI_Comm new_comm;
	
	ret = MPI_Init_thread(&argc, &argv,  MPI_THREAD_MULTIPLE, &provided);
	if (ret != MPI_SUCCESS) {
		printf("Error initializing MPI with threads\n");
		exit(1);
	}
	
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	MPI_Comm_size(MPI_COMM_WORLD, &comm_size);
	size = comm_size/2;
	ranks = malloc(sizeof(int) * (size) );
	
	/* Divide tasks into two distinct groups based upon rank */
	if (rank <size) {
		ranks[0] = 0;
		ranks[1] = 1;
	}
	else {
		ranks[0] = 2;
		ranks[1] = 3;
	}
	//Create a new group                                                                   
	if ((ret = MPI_Comm_group(MPI_COMM_WORLD, &orig)) != MPI_SUCCESS) {
		printf("Rank: %d - Error when trying to get the pointer to the group\n", rank);
		return MPI_ERR_COMM;
	}
	
	if ((rank ==1)||(rank==3)){
		for (i=0; i<size;i++) printf("PE: %d, ranks[%d] = %d\n", rank, i, ranks[i]);
	}
	if ((ret = MPI_Group_incl(orig, size , ranks, &new_group)) != MPI_SUCCESS) {
		printf("Rank: %d - Error while creating adding ranks to the new group\n", rank);
		return MPI_ERR_COMM;
	}
	
	if ((ret = MPI_Comm_create(MPI_COMM_WORLD, new_group, &new_comm)) != MPI_SUCCESS) {
		printf( "Rank: %d - Error while creating the new communicator\n", rank);
		return MPI_ERR_COMM;
	}

	if ((ret = MPI_Comm_dup(new_comm, &dup_comm)) != MPI_SUCCESS) {
		printf( "Rank: %d - Error while duplicating the new communicator\n", rank);
		return MPI_ERR_COMM;
	}
	
	return 0;
}
