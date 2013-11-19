/*
 *  mpi_packs.c
 *  mpiToOpenshmem
 *
 *  Created by gingery on 11/14/13.
 *  Copyright 2013 LANL. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <shmem.h>

#include "mpi_to_openshmem.h"

#define BUF_SIZE          14
#define MAX_CHAR_SIZE     10

int main(int argc, char *argv[])
{
  int provided, ret, size, rank;
  int i, value;
  char c[MAX_CHAR_SIZE];
  char rcv[MAX_CHAR_SIZE];
  static char buffer[BUF_SIZE];
  int position;
  MPI_Status status;
  
  ret = MPI_Init_thread(&argc, &argv,  MPI_THREAD_MULTIPLE, &provided);
  if (ret != MPI_SUCCESS) {
    printf("Error initializing MPI with threads\n");
    exit(1);
  }
  
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  
  // Initialize values:
  value = 2222;
  for (i = 0; i<MAX_CHAR_SIZE; i++){
    c[i] = 'a' + i;
    buffer[i] = 'A' + i;
    rcv[i] = 'A';
  }

  position = 0;

  // Pack:
  MPI_Pack( &value, 1, MPI_INT, buffer, BUF_SIZE, &position, MPI_COMM_WORLD);
  MPI_Pack( c, MAX_CHAR_SIZE, MPI_CHAR, buffer, BUF_SIZE, &position, MPI_COMM_WORLD);
  
  // Send
  MPI_Send(buffer, position, MPI_PACKED, 1, 0, MPI_COMM_WORLD);
  
  // Corresponding Receive
  MPI_Recv(buffer, BUF_SIZE, MPI_PACKED, 1, 0, MPI_COMM_WORLD, &status);
  
  // And Unpack:
  position = 0;
  MPI_Unpack(buffer, BUF_SIZE, &position, &i, 1, MPI_INT, MPI_COMM_WORLD );
  MPI_Unpack(buffer, BUF_SIZE, &position, rcv, MAX_CHAR_SIZE, MPI_CHAR, MPI_COMM_WORLD );
  
  if (i != value){
    printf("PE: %d, Incorrect value: %d should be %d \n", rank, i, value );
  }else {
    printf("PE: %d, Correct, value is  %d\n", rank, i);
  }
  
  // Look at the character buffer values:
  for (i=0; i<MAX_CHAR_SIZE; i++){
    printf("PE: %d, c[%d]:%c == rvc[%d]:%c\n", rank, i, c[i], i, rcv[i]);
  }
  printf("\n\n");
  
  return 0;
}

