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
#include <mpi.h>
#include <shmem.h>
#include <stdint.h>
#include <pthread.h>
#include "Mlog/mlog.h"
#include "Mlog/mlogfacs.h"

/* Success/fail return values */
#define MPI_TO_OPENSHMEM_SUCCESS	1
#define MPI_TO_OPENSHMEM_FAIL		0

// The following structures may be more than we actually need.
// Pruning and growing will occur as time progresses.
typedef struct MPID_Group_pmap_t {
    int          lrank;     /* Local rank in group (between 0 and size-1) */
    int          lpid;      /* local process id, from VCONN */
    int          next_lpid; /* Index of next lpid (in lpid order) */
    int          flag;      /* marker, used to implement group operations */
} MPID_Group_pmap_t;

typedef struct MPID_Group {
    int               size;           /* Size of a group */
    int               rank;           /* rank of this process relative to this group */
    int               idx_of_first_lpid;
    MPID_Group_pmap_t *lrank_to_lpid; /* Array mapping a local rank to local process number */
} MPID_Group;

typedef struct MPID_Comm {
    int				remote_size;  /* Value of MPI_Comm_(remote)_size */
    int				rank;         /* Value of MPI_Comm_rank */
    int				local_size;   /* Value of MPI_Comm_size for local group */
    MPID_Group		*local_group;     /* Groups in communicator. */
	struct MPID_Comm	*node_comm;       /* Comm of processes in this comm that are on the same node as this process. */
	struct MPID_Comm	*node_roots_comm; /* Comm of root processes for other nodes. */
	struct MPID_Comm	*comm_next;       /* Provides a chain through all active communicators */
} MPID_Comm;



/* Define all of the subroutines */
//struct mpi_to_openshmem_t * ( int mpiType, int required, int *provided, int debugLevel ); 
int MPI_Init( int *argc, char ***argv );
int MPI_Init_thread( int *argc, char ***argv, int required, int *provided );
int MPI_Abort (MPI_Comm comm, int errorcode);
int MPI_Barrier(MPI_Comm comm);
int MPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm);
int MPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm);
int MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm);
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
#endif
