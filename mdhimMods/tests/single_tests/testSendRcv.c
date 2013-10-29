/*                                                                                                                             
 *  testSendRcv.c                                                                                                              
 *  mpiToOpenshmem                                                                                                             
 *                                                                                                                             
 *  Created by gingery on 10/28/13.                                                                                            
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
  int nextpe;
  char src;
  char *dest;

  MPI_Status status;

  MPI_Init_thread(&argc, &argv,  MPI_THREAD_MULTIPLE, &provided);
  if (ret != MPI_SUCCESS) {
    printf("Error initializing MPI with threads\n");
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

  //  src = rank;                                                                                                              

  dest = (char *) shmalloc (sizeof (*dest));
  if (dest == NULL){
    printf("Couldn't shmalloc.\n");
  }

  *dest = 'z';
  shmem_barrier_all ();

  //shmem_int_put (dest, &src, 1, nextpe);                                                                                     
  MPI_Send(&src, 1, MPI_CHAR, nextpe, 123, MPI_COMM_WORLD);
  // shmem_int_get (dest, &src, 1, nextpe);                                                                                    
  MPI_Recv(dest, 1, MPI_CHAR, nextpe, 123, MPI_COMM_WORLD, &status);

  shmem_barrier_all ();

  printf ("%4d: got %4c, %4c: ", rank, *dest,src);
  if (*dest == rank)
    {
      printf ("CORRECT");
    }
  else
    {
      printf ("WRONG, expected %c", rank);
    }
  printf ("\n");

  shmem_barrier_all ();
  shfree (dest);
  return 0;

}

