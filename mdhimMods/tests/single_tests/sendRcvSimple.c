*                                                                                                  
*  sendRcvSimple.c                                                                                 
*  mpiToOpenshmem                                                                                  
*                                                                                                  
*  Created by gingery on 3/13/14.                                                                  
*  Copyright 2014 LANL. All rights reserved.                                                       
*                                                                                                  
*/

#include <stdio.h>
#include <stdlib.h>
#include <shmem.h>

#include "mpi_to_openshmem.h"

#define BUF_SIZE 50

int main(int argc, char *argv[])
{
	int provided, ret, size, rank;
	int nextpe, i;
	static char src;
	//char src;                                                                                       
	char *dest;
	int srcInt [BUF_SIZE];
	int *destInt;
	
	MPI_Status status;
	
	ret = MPI_Init_thread(&argc, &argv,  MPI_THREAD_MULTIPLE, &provided);
	if (ret != MPI_SUCCESS) {
		printf("Error initializing MPI with threads, return value: %d\n",ret);
		exit(1);
	}
	
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	nextpe = (rank + 1) % size;
	
	if (rank == 0)
		src = 'a';
	else if (rank == 1)
		src = 'b';
	else
		src = 'c';
	
	dest = (char *) shmalloc (sizeof (char));
	if (dest == NULL){
		printf("Couldn't malloc.\n");
	}
	
	*dest = 'z';
	
	destInt = (int*) malloc (sizeof (int)*BUF_SIZE);
	if (destInt == NULL){
		printf("Couldn't malloc integer space.\n");
	}
	
	for (i=0; i<BUF_SIZE; i++){
		srcInt[i] = (rank * 50) + i;
		destInt[i] = 34560+i;
	}
	MPI_Barrier( MPI_COMM_WORLD );
	
	printf("PE: %d to PE: %d = %c\n", rank, nextpe, src);
	shmem_char_put (dest, &src, 1, nextpe);
	//MPI_Send(&src, 1, MPI_CHAR, nextpe, 123, MPI_COMM_WORLD);                                       
	//  MPI_Send(&srcInt, BUF_SIZE, MPI_INT, nextpe, 124, MPI_COMM_WORLD);                            
	MPI_Barrier(MPI_COMM_WORLD);
	shmem_char_get (dest, &src, 1, nextpe);
	//MPI_Recv(dest, 1, MPI_CHAR, nextpe, 123, MPI_COMM_WORLD, &status);                              
	//MPI_Recv(destInt, BUF_SIZE, MPI_INT, nextpe, 124, MPI_COMM_WORLD, &status);                     
	
	MPI_Barrier (MPI_COMM_WORLD );
	
	//printf ("%4d: got: %4c, src: %4c: \n", rank, *dest,src);                                        
	if (rank == 0){
		if (*dest == 'b'){
			printf ("pe: %d, CORRECT\n", rank);
		}
		else{
			printf("PE: %d from PE: %d, got: %c expected: b\n", rank, nextpe, *dest);
		}
	}
	else if (rank == 1){
		if (*dest == 'c'){
			printf ("pe: %d, CORRECT\n", rank);
		}
		else{
			printf("PE: %d from PE: %d, got: %c expected: c\n", rank, nextpe, *dest);
		}
	}
	else if (rank == 2){
		if (*dest == 'a'){
			printf ("pe: %d, CORRECT\n", rank);
		}
		else{
			printf("PE: %d from PE: %d, got: %c expected: a\n", rank, nextpe, *dest);
		}
	}
	
	/*                                                                                                
	 sleep(10);                                                                                        
	 shmem_barrier_all;                                                                                
	 // Look at integer values:                                                                        
	 for (i=0;i<10;i++){                                                                               
	 
	 printf("pe; %d, nextpe: %d, expected: %6d, got:%6d\n", rank, nextpe, srcInt[i], destInt[i]);    
	 
	 }   */
	
	 return 0;
}
	 
	 
