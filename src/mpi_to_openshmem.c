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

#define DEBUG 1

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
	int i;
	int ret = MPI_SUCCESS;
	void *sharedBuffer;

	//Open mlog - stolen from plfs
	ret = mlog_open((char *)"mpi_to_openshmem", 0, MLOG_CRIT, MLOG_CRIT, NULL, 0, MLOG_LOGPID, 0);

	start_pes(0);
	
	int npes =  _num_pes ();
	int my_pe = shmem_my_pe();
	
	sharedBuffer = (void *)shmalloc(sizeof(char) * MAX_BUFFER_SIZE);
	
	//printf("MPI_Init_Thread: after start_pes, set up rank and local size\n");
	
	// Set up the rank and local_size (npes)
	mpiComm[MPI_COMM_WORLD].rank      = my_pe;
	mpiComm[MPI_COMM_WORLD].size      = npes;
	mpiComm[MPI_COMM_WORLD].bufferPtr = sharedBuffer;
	
	if (shmem_addr_accessible( sharedBuffer, my_pe) ) {
		printf("MPI_Init_thread::Buffer is in a symmetric segment for target pe: %d\n", my_pe);
	}else{
		printf("MPI_Init_thread::Buffer is NOT in a symmetric segment for target pe: %d\n", my_pe);
	}
		
#ifdef DEBUG
		int me = _my_pe();
		//printf("MPI_Init_Thread: Me: %d, [%d].rank: %d, [%d].local_size: %d\n", me, i, mpiComm[i].rank, i, mpiComm[i].local_size);
		printf("MPI_Init_Thread: Me: %d, [0].rank: %d, [0].size: %d, [0].bufferPtr: %x\n", me, mpiComm[MPI_COMM_WORLD].rank, mpiComm[MPI_COMM_WORLD].size, mpiComm[MPI_COMM_WORLD].bufferPtr);
#endif
	//}
	
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
	*provided = MPI_THREAD_MULTIPLE;
		
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
	
	int ret = 1; //MPI_Abort (comm, errorcode);
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

	int ret = MPI_SUCCESS;
	shmem_barrier_all ();  // shmem_barrier (int PE_start, int logPE_stride, int PE_size, long *pSync)
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
int MPI_Bcast ( void *source, int count, MPI_Datatype dataType, int root, MPI_Comm comm){
	
	int i, npes, my_pe;
	void *target;

	npes = _num_pes();
	my_pe = shmem_my_pe();
	
	
	target = (void *)mpiComm[comm].bufferPtr;
	if (target != NULL){
        printf("mpiComm[comm].bufferPtr: %x\n", target);
	}else{
		printf("target is NULL\n\n");
		return 1;
	}
	
#ifdef DEBUG
	for (i = 0; i < count; i += 1){
	    //printf("MPI_Bcast1, dataType: %d, %d npes: %d, com's npes: %d\n", dataType, MPI_LONG, npes, i);
		((long*)target)[i] = -999;                                                                        
	}
#endif
	
	for (i = 0; i < _SHMEM_BCAST_SYNC_SIZE; i += 1){
		pSync[i] = _SHMEM_SYNC_VALUE;
    }
	
	shmem_barrier_all ();
	
	shmem_broadcast64( mpiComm[comm].bufferPtr, source, count, root, 0, 0, npes, pSync);
	
	
#ifdef DEBUG
	for (i = 0; i < count; i++){
		printf ("MPI_Bcast1: my pe: %-8d source: %ld target: %ld\n", my_pe, ((long*)source)[i], ((long*)target)[i]);                                                
	}
#endif
	
	shmem_barrier_all ();	
	
	return MPI_SUCCESS;	
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
	int ret = 1;//MPI_Comm_create ( comm,  group,  newcomm);
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
	int ret = 1;//MPI_Comm_dup (comm, newcomm);
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

	int ret = 1;//MPI_Comm_group(comm, group);
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
	
#ifdef DEBUG
	int my_pe = shmem_my_pe();
	//printf("MPI_Comm_rank, my_pe: %-8d rank: %d\n",  my_pe, *rank);
#endif	
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
	
	*size = _num_pes();
	
#ifdef DEBUG
	int my_pe = shmem_my_pe();
	//printf("MPI_Comm_size, my_pe: %-8d size: %d\n", my_pe, *size);
#endif	

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
	
	int ret = 1;//MPI_Allgather ( sendbuf,  sendcount,  sendtype,  recvbuf,  recvcount,  recvtype,  mpiComm[comm]);
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
	int ret = 1;//MPI_Gather (sendbuf,  sendcount,  sendtype,  recvbuf,  recvcount,  recvtype,  masterRank,  comm);
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

	int ret = 1;//MPI_Gatherv (sendbuf,  sendcount,  sendtype, recvbuf, recvcount, displs,  recvtype,  masterRank,  comm);
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
	
	int ret = 1;//MPI_Group_incl ( group,  n, ranks,  newgroup);
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
int MPI_Recv (void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status){
	
	int  ret;
	void *recv_buf;
	int my_pe = shmem_my_pe();
	
	// Really,  Does this go here?  
	// Do we have to worry about previous data.
	// Should I change the MPI_COMMD structure to have a recv_buffer then look to see if it needs to be increased?
	recv_buf = mpiComm[comm].bufferPtr;
	
	if (recv_buf == NULL){
	  ret = 1;// some sort of proper error here
	}
	else {
	  ret = MPI_SUCCESS;
	}
	
	if (shmem_addr_accessible( recv_buf, my_pe) ) {
	  printf("MPI_Recv::Buffer is in a symmetric segment, pe: %d\n", my_pe);
	  if (shmem_addr_accessible( buf, my_pe ))
	    printf("MPI_Recv::target buff %x, is in symmetric segment, pe: %d\n", buf, my_pe);
	  else
	    printf("MPI_Recv::target buff %x, is NOT symmetric segment, pe: %d\n", buf, my_pe);
	}else{
	  printf("MPI_Recv::Buffer is NOT in a symmetric segment, pe: %d\n", my_pe);
	}
	
	switch (datatype){
		case MPI_CHAR:
		case MPI_UNSIGNED_CHAR:
		case MPI_BYTE:
		  shmem_char_get(buf, recv_buf, count, source);
		  break;
		case MPI_SHORT:
		case MPI_UNSIGNED_SHORT:
		  shmem_short_get(buf, recv_buf, count, source);
		  break;
		case MPI_INT:
		case MPI_UNSIGNED:
		  shmem_int_get(buf, recv_buf, count, source);
		  break;
		case MPI_LONG:
		case MPI_UNSIGNED_LONG:
		  shmem_long_get(buf, recv_buf, count, source);
		  break;
		case MPI_FLOAT:
		  shmem_float_get(buf, recv_buf, count, source);
		  break;
		case MPI_DOUBLE:
		  shmem_double_get(buf, recv_buf, count, source);
		  break;
		case MPI_LONG_DOUBLE:
		  shmem_longdouble_get(buf, recv_buf, count, source);
		  break;
		case MPI_LONG_LONG:
		  shmem_longlong_get(buf, recv_buf, count, source);
		  break;
		default:
		  shmem_getmem(buf, recv_buf, count, source);
		  break;
	}
		
#ifdef DEBUG
	int i;
	
	//my_pe = shmem_my_pe();
	
	if (my_pe == source){
		for (i=0; i<count;i++){
			printf("MPI_Recv: PE: %d, recv_buffer[%d] = %d\n", my_pe, i, ((int *)recv_buf)[i]);
		}
	}
#endif
	
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
	
	int  ret;
	int my_pe = shmem_my_pe();
	void *recv_buf;
	
	// Really,  Does this go here?  
	// Do we have to worry about previous data.
	// Should I change the MPI_COMMD structure to have a recv_buffer then look to see if it needs to be increased?
	recv_buf = mpiComm[comm].bufferPtr;
	
	if (recv_buf == NULL){
		ret = 1;// some sort of proper error here
	}
	else {
		ret = MPI_SUCCESS;
	}
	printf("MPI_Send: PE: %d, recv_buffer Addr = %x\n", my_pe, recv_buf);

        if (shmem_addr_accessible( recv_buf, my_pe) ) {
          printf("MPI_SEND::Buffer is in a symmetric segment, pe: %d\n", my_pe);
          if (shmem_addr_accessible( buf, my_pe ))
            printf("MPI_SEND::target buf %x, is in symmetric segment, pe: %d\n", buf, my_pe);
          else
            printf("MPI_SEND::target buf %x, is NOT symmetric segment, pe: %d\n", buf, my_pe);
        }else{
          printf("MPI_SEND::Buffer is NOT in a symmetric segment, pe: %d\n", my_pe);
        }

	switch (datatype){
		case MPI_CHAR:
		case MPI_UNSIGNED_CHAR:
		case MPI_BYTE:
			printf("MPI_Send: bytish datatype: %d\n", datatype);
			shmem_char_put(recv_buf, buf, count, dest);
			break;
		case MPI_SHORT:
		case MPI_UNSIGNED_SHORT:
			printf("MPI_Send: short datatype: %d\n", datatype);
			shmem_short_put(recv_buf, buf, count, dest);
			break;
		case MPI_INT:
		case MPI_UNSIGNED:
			printf("MPI_Send: int datatype: %d\n", datatype);
			//shmem_int_put(recv_buf, buf, count, dest);
			break;
		case MPI_LONG:
		case MPI_UNSIGNED_LONG:
			printf("MPI_Send: long datatype: %d\n", datatype);
			shmem_long_put(recv_buf, buf, count, dest);
			break;
		case MPI_FLOAT:
			printf("MPI_Send: float datatype: %d\n", datatype);
			shmem_float_put(recv_buf, buf, count, dest);
			break;
		case MPI_DOUBLE:
			printf("MPI_Send: double datatype: %d\n", datatype);
			shmem_double_put(recv_buf, buf, count, dest);
			break;
		case MPI_LONG_DOUBLE:
			printf("MPI_Send: longDouble datatype: %d\n", datatype);
			shmem_longdouble_put(recv_buf, buf, count, dest);
			break;
		case MPI_LONG_LONG:
			printf("MPI_Send: longlong datatype: %d\n", datatype);
			shmem_longlong_put(recv_buf, buf, count, dest);
			break;
		default:
			printf("MPI_Send: not here datatype: %d\n", datatype);
			shmem_putmem(recv_buf, buf, count, dest);
			break;
	}
	
	// and to be on the safe side:
	shmem_fence();
	
#ifdef DEBUG
	int i;
	
	for (i=0; i<count;i++){
		printf("MPI_Send: PE: %d, buf[%d] = %d to recvBuf: %x \n", my_pe, i, ((int *)buf)[i], recv_buf);
	}
#endif
	
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
int MPI_Irecv (void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *requestComm){
	int ret = 1;//MPI_Irecv (buf, count, datatype, source, tag, comm, requestComm);
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
int MPI_Isend(void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *requestComm){
	
	int ret = 1;//MPI_Isend (buf, count, datatype, dest, tag, comm, requestComm);
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
	
	int ret = 1;//MPI_Unpack (inbuf, insize, position, outbuf, outcount, datatype, comm);
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
	int ret = 1;//MPI_Pack (inbuf, incount, datatype, outbuf, outsize, position, comm);
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
	//shfree (mpiComm);
	int ret = MPI_SUCCESS; //MPI_Finalize ();
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
	
	int ret = 1;//MPI_Test (request, flag, status);
	return ret;
}
