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
//#include <mpi.h>
#include <shmem.h>
#include <stdint.h>
#include <pthread.h>
#include "Mlog/mlog.h"
#include "Mlog/mlogfacs.h"

#define MASTER			0
#define MAX_NUM_COMM   10
#define INT_32			4	// number of bytes for a 32 bit integer
#define INT_64			8	// number of bytes for a 64 bit integer

#define SEND_TYPE		0
#define RECEIVE_TYPE	1

#define	MAX_BUFFER_SIZE	200000 //(in bytes)

long pSync[_SHMEM_BCAST_SYNC_SIZE];


/**** from mpi.h.in									****/
#define MPI_COMM_WORLD	     0

#define MPI_SUCCESS          0      /* Successful return code */
#define MPI_ERR_NO_MEM       1      /* Alloc_mem could not allocate memory */
#define MPI_ERR_BUFFER       2		// Invalid buffer pointer. Usually a null buffer where one is not valid.
#define MPI_ERR_COUNT        3		// Invalid count argument
#define MPI_ERR_TYPE         4		// Invalid datatype argument
#define MPI_ERR_SIZE         5      // Invalid size.
#define MPI_ERR_NO_SPACE     6      // Memory exhausted.
/*
 MPI_SUCCESS              0      Successful return code.
 MPI_ERR_BUFFER           1      Invalid buffer pointer.
 MPI_ERR_COUNT            2      Invalid count argument.
 MPI_ERR_TYPE             3      Invalid datatype argument.
 MPI_ERR_TAG              4      Invalid tag argument.
 MPI_ERR_COMM             5      Invalid communicator.
 MPI_ERR_RANK             6      Invalid rank.
 MPI_ERR_REQUEST          7      Invalid MPI_Request handle.
 MPI_ERR_ROOT             7      Invalid root.
 MPI_ERR_GROUP            8      Null group passed to function.
 MPI_ERR_OP               9      Invalid operation.
 MPI_ERR_TOPOLOGY        10      Invalid topology.
 MPI_ERR_DIMS            11      Illegal dimension argument.
 MPI_ERR_ARG             12      Invalid argument.
 MPI_ERR_UNKNOWN         13      Unknown error.
 MPI_ERR_TRUNCATE        14      Message truncated on receive.
 MPI_ERR_OTHER           15      Other error; use Error_string.
 MPI_ERR_INTERN          16      Internal error code.
 MPI_ERR_IN_STATUS       17      Look in status for error value.
 MPI_ERR_PENDING         18      Pending request.
 MPI_ERR_ACCESS          19      Permission denied.
 MPI_ERR_AMODE           20      Unsupported amode passed to open.
 
 MPI_ERR_ASSERT          21      Invalid assert.
 MPI_ERR_BAD_FILE        22      Invalid file name (for example,
 path name too long).
 MPI_ERR_BASE            23      Invalid base.
 MPI_ERR_CONVERSION      24      An error occurred in a user-supplied
 data-conversion function.
 MPI_ERR_DISP            25      Invalid displacement.
 MPI_ERR_DUP_DATAREP     26      Conversion functions could not be registered because a data
 representation identifier that was
 already defined was passed to
 MPI_REGISTER_DATAREP.
 MPI_ERR_FILE_EXISTS     27      File exists.
 MPI_ERR_FILE_IN_USE     28      File operation could not be
 completed, as the file is currently
 open by some process.
 MPI_ERR_FILE            29
 MPI_ERR_INFO_KEY        30      Illegal info key.
 MPI_ERR_INFO_NOKEY      31      No such key.
 MPI_ERR_INFO_VALUE      32      Illegal info value.
 MPI_ERR_INFO            33      Invalid info object.
 MPI_ERR_IO              34      I/O error.
 MPI_ERR_KEYVAL          35      Illegal key value.
 MPI_ERR_LOCKTYPE        36      Invalid locktype.
 MPI_ERR_NAME            37      Name not found.
 MPI_ERR_NOT_SAME        39
 MPI_ERR_NO_SUCH_FILE    41      File (or directory) does not exist.
 MPI_ERR_PORT            42      Invalid port.
 MPI_ERR_QUOTA           43      Quota exceeded.
 MPI_ERR_READ_ONLY       44      Read-only file system.
 MPI_ERR_RMA_CONFLICT    45      Conflicting accesses to window.
 
 MPI_ERR_RMA_SYNC        46      Erroneous RMA synchronization.
 MPI_ERR_SERVICE         47      Invalid publish/unpublish.
 MPI_ERR_SPAWN           49      Error spawning.
 MPI_ERR_UNSUPPORTED_DATAREP
 50      Unsupported datarep passed to
 MPI_File_set_view.
 MPI_ERR_UNSUPPORTED_OPERATION
 51      Unsupported operation, such as
 seeking on a file that supports
 only sequential access.
 MPI_ERR_WIN             52      Invalid window.
 MPI_ERR_LASTCODE        53      Last error code.
 MPI_ERR_SYSRESOURCE     -2      Out of resources
 */
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
} MPID_Group;

typedef struct MPID_Comm {
    int				rank;			/* Value of MPI_Comm_rank */
    int				size;			/* Value of MPI_Comm_size for local group */
    MPID_Group		*local_group;   /* Groups in communicator. */
	void			*bufferPtr;
} MPID_Comm;

typedef struct MPID_Request{
	int				requestType;	/* either SEND_TYPE or RECEIVE_TYPE */
	int				rank;			/* Value of MPI_Comm_rank */
	MPI_Datatype	dataType;		/* type of the data sent/received */
	void			*lastBufPtr;	/* pointer to the last item in the buffer sent/rcvd */
	void			*expected;		/* pointer to expected value in the last address */
} MPID_Request;

MPID_Comm  mpiComm[MAX_NUM_COMM];
typedef MPID_Group MPI_Group;
typedef MPID_Request       MPI_Request;
typedef int		   MPI_Comm;

MPI_Comm comm;

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
