/*
 *  ! \mainpage mpi_to_openshmem.c
 *  mpi_to_openshmem 
 *
 *\section intro_sec Introduction
 *
 * mpi_to_openshmem is a library MDHIM TNG uses for its interface for parallel programming
 *
 *  Created on 9/23/13.
 *  Copyright 2013 LANL. All rights reserved.
 *
 */

#include "mpi_to_openshmem.h"


/**
 * MPI_Init
 * Initializes for Openshmem
 *
 * @param argc Pointer to the number of arguments 
 * @param argv Pointer to the argument vector 
 * @return MPI_SUCCESS, this always succeeds.
 */

int MPI_Init( int *argc, char ***argv ){

	int ret = MPI_SUCCESS;
	
	//Open mlog - stolen from plfs
	ret = mlog_open((char *)"mpi_to_openshmem", 0, MLOG_CRIT, MLOG_CRIT, NULL, 0, MLOG_LOGPID, 0);

	start_pes(0);
	
	return ret;
	
}

/**
 * MPI_Init_thread
 * Initializes for Openshmem, the thread stuff is ignored for now.
 *
 * @param argc		Pointer to the number of arguments 
 * @param argv		Pointer to the argument vector 
 * @param required	Level of desired thread support provided
 * @param provided	Level of provided thread support  
 * @return MPI_SUCCESS, this always succeeds.
 */

int MPI_Init_thread( int *argc, char ***argv, int required, int *provided ){
	
	int ret = MPI_SUCCESS;

	//Open mlog - stolen from plfs
	ret = mlog_open((char *)"mpi_to_openshmem", 0, MLOG_CRIT, MLOG_CRIT, NULL, 0, MLOG_LOGPID, 0);

	start_pes(0);
	
	/* Types of thread support:
	 * MPI_THREAD_SINGLE
     *		Only one thread will execute. 
	 * MPI_THREAD_FUNNELED
     *		The process may be multi-threaded, but only the main thread will 
	 *		make MPI calls (all MPI calls are funneled to the main thread). 
	 * MPI_THREAD_SERIALIZED
     *		The process may be multi-threaded, and multiple threads may make 
	 *		MPI calls, but only one at a time: MPI calls are not made concurrently 
	 *		from two distinct threads (all MPI calls are serialized). 
	 * MPI_THREAD_MULTIPLE
     *		Multiple threads may call MPI, with no restrictions.These values are 
	 *		monotonic; i.e., MPI_THREAD_SINGLE < MPI_THREAD_FUNNELED < 
	 *		MPI_THREAD_SERIALIZED < MPI_THREAD_MULTIPLE.
	 * 
	 */
	// Fake the multiple thread stuff with mutix, return the expected values.
	*provided = required;
		
	return ret;
	
}

/* The rest are in stubs - to be filled out one by one */
/**
 * MPI_Abort
 * Terminates MPI execution environment.
 *
 * @param 
 * @param 
 * @param 
 * @return 
 */
int MPI_Abort (MPI_Comm comm, int errorcode){
	
	int ret = MPI_Abort (comm, errorcode);
	return ret;
}

/**
 * MPI_Barrier
 * Blocks until all processors in the communicator ave reached this routine.
 *
 * @param 
 * @param 
 * @param 
 * @return 
 */
int MPI_Barrier (MPI_Comm comm){

	int ret = MPI_Barrier (comm);
	// shmem_barrier_all (void)
	// shmem_barrier (int PE_start, int logPE_stride, int PE_size, long *pSync)
	return ret;
}

/**
 * MPI_Bcast
 * Broadcasts a message from the process with rank "root" to all other processes
 *	of the communicator.
 *
 * @param 
 * @param 
 * @param 
 * @return 
 */
int MPI_Bcast (void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm){
	int ret = MPI_Bcast (buffer, count,  datatype, root, comm);
	
	return ret;
}

/**
 * MPI_Comm_create
 * Creates a new communicator
 *
 * @param 
 * @param 
 * @param 
 * @return 
 */
int MPI_Comm_create (MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm){
	int ret = MPI_Comm_create ( comm,  group,  newcomm);
	return ret;
}

/**
 * MPI_Comm_dup
 * Duplicates an existing communicator with all its cached information 
 *
 * @param 
 * @param 
 * @param 
 * @return 
 */
int MPI_Comm_dup (MPI_Comm comm, MPI_Comm *newcomm){
	int ret = MPI_Comm_dup (comm, newcomm);
	return ret;
}

/**
 * MPI_Comm_group
 * Accesses the group associated with given communicator
 *
 * @param 
 * @param 
 * @param 
 * @return 
 */
int MPI_Comm_group (MPI_Comm comm,	MPI_Group *group){

	int ret = MPI_Comm_group(comm, group);
	return ret;
}

/**
 * MPI_Comm_rank
 * Determines the rank of the calling process in the communicator
 *
 * @param comm communicator(handle)
 * @param rank of the calling process in the group of comm (integer)
 * @return 
 */
int MPI_Comm_rank (MPI_Comm comm, int *rank){
	
	*rank = shmem_my_pe();
	
	return MPI_SUCCESS;
}

/**
 * MPI_Comm_size
 * Determines the size of the group associated with a communicator
 *
 * @param comm communicator(handle)
 * @param size number of processes in the group of comm (integer) 
 * @return 
 */
int MPI_Comm_size(MPI_Comm comm, int *size ){
	
	*size = shmem_n_pes();
	return MPI_SUCCESS;
}

/**
 * MPI_Allgather
 * Gathers data from all tasks and distribute the combined data to all tasks 
 *
 * @param 
 * @param 
 * @param 
 * @return 
 */
int MPI_Allgather (void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm){
	
	int ret = MPI_Allgather ( sendbuf,  sendcount,  sendtype,  recvbuf,  recvcount,  recvtype,  comm);
	return ret;
}

/**
 * MPI_Gather
 * Gathers together values from a group of processes
 *
 * @param 
 * @param 
 * @param 
 * @return 
 */
int MPI_Gather (void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int masterRank, MPI_Comm comm){
	int ret = MPI_Gather (sendbuf,  sendcount,  sendtype,  recvbuf,  recvcount,  recvtype,  masterRank,  comm);
	return ret;
}

/**
 * MPI_Gatherv
 * Gathers into specified locations from all processes in a group
 *
 * @param 
 * @param 
 * @param
 
 sendbuf		starting address of send buffer (choice) 
 sendcount		number of elements in send buffer (integer) 
 sendtype		data type of send buffer elements (handle) 
 recvcounts		integer array (of length group size) containing the number of elements that are received from each process (significant only at root) 
 displs			integer array (of length group size). Entry i specifies the displacement relative to recvbuf at which to place the incoming data from process i (significant only at root) 
 recvtype		data type of recv buffer elements (significant only at root) (handle) 
 root			rank of receiving process (integer) 
 comm			communicator (handle) 
 
 Output Parameter
 
 recvbuf		address of receive buffer (choice, significant only at root) 
 
 
 * @return 
 */
int MPI_Gatherv (void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int *recvcount, int *displs, MPI_Datatype recvtype, int masterRank, MPI_Comm comm){

	int ret = MPI_Gatherv (sendbuf,  sendcount,  sendtype, recvbuf, recvcount, displs,  recvtype,  masterRank,  comm);
	return ret;
}

/**
 * MPI_Group_inc
 * Produces a group by reordering an existing group and taking only listed members
 *
 * @param 
 * @param 
 * @param 
 * @return 
 */
int MPI_Group_incl (MPI_Group group, int n, int *ranks, MPI_Group *newgroup){
	
	int ret = MPI_Group_incl ( group,  n, ranks,  newgroup);
	return ret;
}

/**
 * MPI_Recv
 * Blocking receive for a message
 *
 * @param 
 * @param 
 * @param 
 * @return 
 */
int MPI_Recv (void *buf, int count, MPI_Datatype datatype, int source, int tag,MPI_Comm comm, MPI_Status *status){
	
	int ret = MPI_Recv (buf, count, datatype, source, tag, comm, status);
	return ret;
}

/**
 * MPI_Send
 * Performs a blocking send
 *
 * @param 
 * @param 
 * @param 
 * @return 
 */
int MPI_Send (void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm){
	
	int ret = MPI_Send (buf, count, datatype, dest, tag, comm);
	return ret;
}

/**
 * MPI_Irecv
 * Nonblocking receive for a message
 *
 buf		initial address of receive buffer (choice) 
 count		number of elements in receive buffer (integer) 
 datatype	datatype of each receive buffer element (handle) 
 source		rank of source (integer) 
 tag		message tag (integer) 
 comm		communicator (handle) 
 
 Output Parameter
 
 request	communication request (handle) 
 * @param 
 * @param 
 * @param 
 * @return 
 */
int MPI_Irecv (void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Comm *requestComm){

	int ret = MPI_Irecv (buf, count, datatype, source, tag, comm, requestComm);
	return ret;
}

/**
 * MPI_Isend
 * Performs a nonblocking send
 *
 * @param 
 * @param 
 * @param 
 * @return 
 */
int MPI_Isend (void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Comm *requestComm){
	
	int ret = MPI_Isend (buf, count, datatype, dest, tag, comm, requestComm);
	return ret;
}

/**
 * MPI_Unpack
 * Unpack a buffer according to a datatype into contiguous memory
 *
 * @param 
 * @param 
 * @param 
 * @return 
 */
int MPI_Unpack (void *inbuf, int insize, int *position, void *outbuf, int outcount, MPI_Datatype datatype, MPI_Comm comm){
	
	int ret = MPI_Unpack (inbuf, insize, position, outbuf, outcount, datatype, comm);
	return ret;
}

/**
 * MPI_Unpack
 * Unpack a buffer according to a datatype into contiguous memory
 *
 * @param 
 * @param 
 * @param 
 * @return 
 */
int MPI_Pack(void *inbuf, int incount, MPI_Datatype datatype, void *outbuf, int outsize, int *position,  MPI_Comm comm){
	int ret = MPI_Pack (inbuf, incount, datatype, outbuf, outsize, position, comm);
	return ret;
	
}

/**
 * MPI_Pack
 * Pack a buffer according to a datatype into contiguous memory
 *
 * @param 
 * @param 
 * @param 
 * @return 
 */
int MPI_Finalize(void){
	int ret = MPI_Finalize ();
	return ret;
}

/**
 * MPI_Test
 * Tests for the completion of a request
 *
 * @param 
 * @param 
 * @param 
 * @return 
 */
int MPI_Test (MPI_Request *request, int *flag, MPI_Status *status){
	
	int ret = MPI_Test (request, flag, status);
	return ret;
}
