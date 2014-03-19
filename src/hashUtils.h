/*
 *  hashUtils.h
 *  mpiToOpenshmem
 *
 *  Created on 2/25/14.
 *  Copyright 2014 LANL. All rights reserved.
 *
 */
#ifndef      __HASHUTILS_H
#define      __HASHUTILS_H

int AddBufferEntry       ( int tag, long count, MPI_Datatype datatype, int srcRank, int destRank, requestType_t requestType, void **bufPtr, MPI_Comm comm);
int DeleteHashEntry      ( int tag, long count, requestType_t requestType, MPI_Datatype datatype, void **bufPtr, MPI_Comm comm );
int FindTagInHash        ( int tag, void **bufPtr, MPI_Comm comm );
int GetBufferPtrFromHash ( int tag, long count, requestType_t requestType, MPI_Datatype datatype, void **bufPtr, MPI_Comm comm );

// For multiThreading:
pthread_mutex_t	lockAddBufferEntry;
pthread_mutex_t	lockDeleteHashEntry;
pthread_mutex_t lockFindTagInHash;
pthread_mutex_t lockGetBufferPtrFromHash;

#endif