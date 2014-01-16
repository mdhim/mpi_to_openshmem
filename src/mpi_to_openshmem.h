/*
 *  mpi_to_openshmem.h
 *  mpi_to_openshmem
 *
 *  Created on 9/23/13.
 *  Copyright 2013 LANL. All rights reserved.
 *
 */
#ifndef      __MPI_TO_OPENSHMEM_H
#define      __MPI_TO_OPENSHMEM_H

#include <stdio.h>
#include <stdlib.h>
#include <shmem.h>
#include <stdint.h>
#include <pthread.h>
#include "Mlog/mlog.h"
#include "Mlog/mlogfacs.h"

#define INT_32			4	// number of bytes for a 32 bit integer
#define INT_64			8	// number of bytes for a 64 bit integer

#define	FALSE			0
#define TRUE			1

#define SEND_TYPE		0
#define RECEIVE_TYPE	1

#define	MAX_BUFFER_SIZE	200000 //(in bytes)

long pSync[_SHMEM_BCAST_SYNC_SIZE];


/**** from mpi.h.in									****/

#define MPI_SUCCESS          0      /* Successful return code */
#define MPI_ERR_NO_MEM       1      /* Alloc_mem could not allocate memory */
#define MPI_ERR_BUFFER       2		// Invalid buffer pointer. Usually a null buffer where one is not valid.
#define MPI_ERR_COUNT        3		// Invalid count argument
#define MPI_ERR_TYPE         4		// Invalid datatype argument
#define MPI_ERR_SIZE         5      // Invalid size.
#define MPI_ERR_NO_SPACE     6      // Memory exhausted.
#define MPI_ERR_COMM         7      // Invalid communicator.
#define MPI_ERR_GROUP        8      // Null group passed to function.

typedef int MPI_Datatype;

#define MPI_CHAR           ((MPI_Datatype)1)
#define MPI_UNSIGNED_CHAR  ((MPI_Datatype)2)
#define MPI_BYTE           ((MPI_Datatype)3)
#define MPI_SHORT          ((MPI_Datatype)4)
#define MPI_UNSIGNED_SHORT ((MPI_Datatype)5)
#define MPI_INT            ((MPI_Datatype)6)
#define MPI_UNSIGNED       ((MPI_Datatype)7)
#define MPI_LONG           ((MPI_Datatype)8)
#define MPI_UNSIGNED_LONG  ((MPI_Datatype)9)
#define MPI_FLOAT          ((MPI_Datatype)10)
#define MPI_DOUBLE         ((MPI_Datatype)11)
#define MPI_LONG_DOUBLE    ((MPI_Datatype)12)
#define MPI_LONG_LONG_INT  ((MPI_Datatype)13)

/* MPI_LONG_LONG is in the complete ref 2nd edition, though not in the 
 standard.  Rather, MPI_LONG_LONG_INT is on page 40 in the HPCA version */
#define MPI_LONG_LONG      ((MPI_Datatype)13)
#define MPI_PACKED		   ((MPI_Datatype)14)

// Definitions for pftool
#define MPI_ANY_TAG		     (-1)
#define MPI_ANY_SOURCE	     (-2)

/* For supported thread levels */
#define MPI_THREAD_SINGLE		0
#define MPI_THREAD_FUNNELED		1
#define MPI_THREAD_SERIALIZED	2
#define MPI_THREAD_MULTIPLE		3
/****                									****/


/**** from mpidefs.h									****/
/* 
 Status object.  It is the only user-visible MPI data-structure 
 The "count" field is PRIVATE; use MPI_Get_count to access it. 
 */
int MPI_SOURCE;
int MPI_TAG;
int MPI_ERROR;

/* MPI_STATUS_SIZE is not strictly required in C; however, it should match
the value for Fortran */

#define MPI_STATUS_SIZE 4
typedef struct { 
    int count;
    int MPI_SOURCE;
    int MPI_TAG;
    int MPI_ERROR;
#if (MPI_STATUS_SIZE > 4)
    int extra[MPI_STATUS_SIZE - 4];
#endif
} MPI_Status;
/****                									****/

typedef struct MPID_Group {
    int               size;           /* Size of a group */
    int               rank;           /* rank of this process relative to this group */
    int               pe_rank;        /* original pe rank */
    int               *pesInGroup;     /* integer array of all of the PEs in this group. Rank is the index. */
} MPID_Group;

typedef struct MPID_Comm {
    int				rank;		 /* Value of MPI_Comm_rank */
    int				size;		 /* Value of MPI_Comm_size for local group */
    MPID_Group		*groupPtr;   /* Groups in communicator. */
	void			*bufferPtr;
	int				offset;      /* offset of the number of bytes into the buffer - placeholder. */
	/*****
	 *  This really need to be a structure that is growing:
	 *
	 *	startBufIndex
	 *  numBytes
	 *  endBufIndex  - just as a double check..
	 *  command?  I'm debating about this.  Is it really useful?
	 *
	 *  what about occassional garbage collecting? Do you want to clean up, or assuming everything is just prefect?
	 *******/
} MPID_Comm;

typedef struct MPID_Request{
	int				requestType;	/* either SEND_TYPE or RECEIVE_TYPE */
	int				rank;			/* Value of MPI_Comm_rank */
	MPI_Datatype	dataType;		/* type of the data sent/received */
	void			*lastBufPtr;	/* pointer to the last item in the buffer sent/rcvd */
	void			*expected;		/* pointer to expected value in the last address */
} MPID_Request;

typedef MPID_Group		MPI_Group;
typedef MPID_Request    MPI_Request;
typedef MPID_Comm		*MPI_Comm;
MPI_Comm MPI_COMM_WORLD;			/* Communicator handles are pointers to structures...*/

/* For MPI_Init_thread and multi-threaded support.
 * OpenShmem does not support multithreads.
 */
int isMultiThreads;
pthread_mutex_t	lockGetOffset;
pthread_mutex_t	lockCopyData;
pthread_mutex_t	lockAbort;
pthread_mutex_t	lockBarrier;
pthread_mutex_t	lockBcast;
pthread_mutex_t	lockCommCreate;
pthread_mutex_t	lockCommDup;
pthread_mutex_t	lockCommFree;
pthread_mutex_t	lockAllGather;
pthread_mutex_t	lockGather;
pthread_mutex_t	lockGatherV;
pthread_mutex_t	lockGroupIncl;
pthread_mutex_t	lockRecv;
pthread_mutex_t	lockSend;
pthread_mutex_t	lockIRecv;
pthread_mutex_t	lockISend;
pthread_mutex_t	lockUnpack;
pthread_mutex_t	lockPack;
pthread_mutex_t	lockTest;
pthread_mutex_t	lockIprobe;

/* Define all of the subroutines */
//struct mpi_to_openshmem_t * ( int mpiType, int required, int *provided, int debugLevel ); 
int MPI_Init( int *argc, char ***argv );
int MPI_Init_thread( int *argc, char ***argv, int required, int *provided );
int MPI_Abort (MPI_Comm comm, int errorcode);
int MPI_Barrier(MPI_Comm comm);

int MPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm);

int MPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm);
int MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm);
int MPI_Comm_free(MPI_Comm comm);
int MPI_Comm_group(MPI_Comm comm,	MPI_Group *group);
int MPI_Comm_rank(MPI_Comm comm, int *rank);
int MPI_Comm_size(MPI_Comm comm, int *size);
int MPI_Allgather(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm);
int MPI_Gather(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int masterRank, MPI_Comm comm);
int MPI_Gatherv(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int *recvcount, int *displs, MPI_Datatype recvtype, int masterRank, MPI_Comm comm);
int MPI_Group_incl(MPI_Group group, int n, int *ranks, MPI_Group *newgroup);
int MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag,MPI_Comm comm, MPI_Status *status);
int MPI_Send(void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm);
int MPI_Irecv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request);
int MPI_Isend(void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request);
int MPI_Unpack(void *inbuf, int insize, int *position, void *outbuf, int outcount, MPI_Datatype datatype, MPI_Comm comm);
int MPI_Pack(void *inbuf, int incount, MPI_Datatype datatype, void *outbuf, int outsize, int *position,  MPI_Comm comm);
int MPI_Finalize(void);
int MPI_Test(MPI_Request *request, int *flag, MPI_Status *status);

// Routine for pftool - this really doesn't work the correct MPI way.
int MPI_Iprobe(int source, int tag, MPI_Comm comm, int *flag, MPI_Status *status);

#endif
