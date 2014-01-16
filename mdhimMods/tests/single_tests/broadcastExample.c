/*
 *  broadcast1.c
 *  mpiToOpenshmem
 *
 *  Created by gingery on 10/16/13.
 *  Copyright 2013 LANL. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
//#include <shmem.h>
#include "mpi_to_openshmem.h"

/**
 * MPI_Bcast
 * Broadcasts a message from the process with rank "root" to all other processes
 *of the communicator.
 *
 * Input/Output Parameter
 *
 * @param  bufferstarting address of buffer (choice) 
 *
 * Input Parameters
 *
 * @param  countnumber of entries in buffer (integer) 
 * @param  datatypedata type of buffer (handle) 
 * @param  rootrank of broadcast root (integer) 
 * @param  commcommunicator (handle) 
 *
 * @return status
 */

int MPI_BcastLocal ( void *source, int count, MPI_Datatype dataType, int root, MPI_Comm comm){
  
  int  i;
  int  npes, my_pe;
  void *symSource;

  if (comm == NULL) {
    mlog(MPI_ERR, "Invalid communicator.\n");
    return MPI_ERR_COMM;
  }
  
  if (isMultiThreads){
    pthread_mutex_lock(&lockBcast);
  }
  
  npes = _num_pes();
  my_pe = shmem_my_pe();

  // Okay, try to find a work around
  printf("MPI_Bcast::Buffer is not in a symmetric segment, pe: %d\n", my_pe);
  mlog(MPI_DBG, "Debug: Buffer is not in a symmetric segment, %d\n", my_pe);
    
  symSource = ((void*)((MPID_Comm)*comm).bufferPtr);
  if (symSource == NULL) {
    mlog(MPI_ERR, "MPI_Bcast:: could not create symmetric buffer space for the source.\n");
    return MPI_ERR_BUFFER;
  }

  // Move user's source into the symmetric buffer, since they can't create one.
  CopyMyData( symSource, source, count, dataType);
#ifdef DEBUG
  for (i=0; i<count; i++){
    printf("MPI_Bcast: rank: %d symSource: %ld\n", my_pe, ((long*)symSource)[i]);
  }
#endif
    
  shmem_barrier_all ();
    
  for (i = 0; i < _SHMEM_BCAST_SYNC_SIZE; i += 1){
    pSync[i] = _SHMEM_SYNC_VALUE;
  }
  
  shmem_barrier_all ();
  
  shmem_broadcast64( ((MPID_Comm)*comm).bufferPtr, symSource, count, root, 0, 0, npes, pSync);
    
  shmem_barrier_all();
  
  // Move the symmetric buffer data into source, which is the target...
  if (my_pe != root) {
    CopyMyData(source, symSource, count, dataType);
  }

#ifdef DEBUG
  for (i = 0; i < count; i++){
    mlog(MPI_DBG, "MPI_Bcast1: rank: %-8d source: %ld\n", my_pe, ((long*)source)[i]); 
    printf("MPI_Bcast1: rank: %-8d source: %ld\n", my_pe, ((long*)source)[i]);
    printf("MPI_Bcast1: rank: %-8d symSource: %ld\n", my_pe, ((long*)symSource)[i]);
  }
#endif

  if (isMultiThreads){
    pthread_mutex_unlock(&lockBcast);
  }
  
  return MPI_SUCCESS;
}


int main(int argc, char **argv) {
  int i, ret;
  long *source;
  int  bufsize;
  int  rank, npes;
  int  size;
  int  provided;
  int  isGood = TRUE;
  
  ret = MPI_Init_thread(&argc, &argv, MPI_THREAD_MULTIPLE, &provided);
  if (ret != MPI_SUCCESS) {
    printf("Error initializing MPI with threads\n");
    exit(1);
  }
  
  MPI_Comm_rank ( MPI_COMM_WORLD, &rank);
  MPI_Comm_size ( MPI_COMM_WORLD, &npes);
    
  int my_pe = shmem_my_pe();
  printf("Main,  my_pe: %-8d, rank: %d, size: %d\n", my_pe, rank, npes);
 
  size = npes * 3; 
  bufsize = size * sizeof( *source );

  source = (long *)shmalloc (bufsize);
  //source = (long *)malloc (bufsize);

  for (i = 0; i < size; i++){
    if (rank == 0) source[i] = 1 + i;
    else  source[i] = 999;
   }

  MPI_BcastLocal(source, size, MPI_LONG, 0, MPI_COMM_WORLD);
  //int root = 0;
  //shmem_broadcast64( target, source, size, root, 0, 0, npes, pSync);

  // Check that the value is as expected
  for (i = 0; i < size; i++){
    if ( source[i] != (i+1) ){
      isGood = FALSE;
      printf("Failed. my_pe: %-8d, source[%d] = %ld, expected %d\n", my_pe, i, source[i], (i+1));
    }
  }
  if (isGood){
    printf("Passed, my_pe: %d\n",my_pe);
  }

  return isGood;

}

