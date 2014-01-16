/*
 *  testSendRcv.c
 *  mpiToOpenshmem
 *
 *  Created by gingery on 10/28/13.
 *  Copyright 2013 LANL. All rights reserved.
 *
 * Tests single int send/receive
 */
#include <stdio.h>
#include <stdlib.h>
#include <shmem.h>

#include "mpi_to_openshmem.h"

#define BUF_SIZE 10

int main(int argc, char *argv[])
{
  int i, provided, ret, size, rank;
  int nextpe;
  long src[BUF_SIZE];
  long *dest;

  MPI_Status status;
  
  ret = MPI_Init_thread(&argc, &argv,  MPI_THREAD_MULTIPLE, &provided);
  if (ret != MPI_SUCCESS) {
    printf("Error initializing MPI with threads\n");
    exit(1);
  }

  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  nextpe = (rank + 1) % size;

  dest = (long *) malloc (sizeof (*dest) * BUF_SIZE);
  if (dest == NULL){
    printf("Couldn't malloc.\n");
  }

  for (i=0; i<BUF_SIZE;i++){
    dest[i] = 99;
    src[i] = i+1;
  }
  shmem_barrier_all ();

  //shmem_int_put (dest, &src, 1, nextpe);
  MPI_Send(&src, BUF_SIZE, MPI_LONG, nextpe, 123, MPI_COMM_WORLD);
  // shmem_int_get (dest, &src, 1, nextpe);
  MPI_Recv(dest, BUF_SIZE, MPI_LONG, nextpe, 123, MPI_COMM_WORLD, &status);

  shmem_barrier_all ();

  for (i=0;i<BUF_SIZE;i++){
    printf("PE: %d, src[%d] = %ld, dest[] = %ld\n",rank,i,src[i],dest[i]); 
  }

  //printf ("%4d: got %4d, %4ld: ", rank, dest[0],src[0]);
  if (dest[0] == src[0])
    {
      printf ("CORRECT");
    }
  else
    {
      printf ("PE: %d, WRONG, expected %ld", rank, src[0]);
    }
  printf ("\n");

  shmem_barrier_all ();
  free (dest);
  return 0;

}
