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

int AddBufferSpace(int tag, long count, MPI_Datatype datatype, int srcRank, int destRank, requestType_t requestType, void **bufPtr, MPI_Comm comm);

pthread_mutex_t	lockAddBufferSpace;

#endif