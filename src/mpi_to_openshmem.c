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
		mlog(MPI_DBG, "MPI_Init_thread::Buffer is in a symmetric segment for target pe: %d\n", my_pe);
	}else{
		mlog(MPI_DBG, "MPI_Init_thread::Buffer is NOT in a symmetric segment for target pe: %d\n", my_pe);
	}
		
#ifdef DEBUG
		int me = _my_pe();
		//printf("MPI_Init_Thread: Me: %d, [%d].rank: %d, [%d].local_size: %d\n", me, i, mpiComm[i].rank, i, mpiComm[i].local_size);
		mlog(MPI_DBG, "MPI_Init_Thread: Me: %d, [0].rank: %d, [0].size: %d, [0].bufferPtr: %x\n", me, mpiComm[MPI_COMM_WORLD].rank, mpiComm[MPI_COMM_WORLD].size, mpiComm[MPI_COMM_WORLD].bufferPtr);
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
	    //mlog(MPI_DBG, "MPI_Bcast1, dataType: %d, %d npes: %d, com's npes: %d\n", dataType, MPI_LONG, npes, i);
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
		mlog(MPI_DBG, "MPI_Bcast1: my pe: %-8d source: %ld target: %ld\n", my_pe, ((long*)source)[i], ((long*)target)[i]);                                                
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
	//int my_pe = shmem_my_pe();
	//printf("MPI_Comm_size, my_pe: %-8d size: %d\n", my_pe, *size);
#endif	

	return MPI_SUCCESS;
}

/**
 * MPI_Allgather
 * Gathers data from all tasks and distribute the combined data to all tasks 
 *
 * The jth block of data sent from each process is received by every process and placed in the jth block of the buffer recvbuf. 
 *
 *  This is misleading; a better description is
 *  The block of data sent from the jth process is received by every process and placed in the jth block of the buffer recvbuf. 
 * 
 * @param  sendbuf		starting address of send buffer (choice) 
 * @param  sendcount	number of elements in send buffer (integer) 
 * @param  sendtype		data type of send buffer elements (handle)
 * @param  recvbuf		address of receive buffer (choice) (output parameter)
 * @param  recvcount	number of elements received from any process (integer) 
 * @param  recvtype		data type of receive buffer elements (handle) 
 * @param  comm			communicator (handle)  
 *  
 * @return 
 */
int MPI_Allgather (void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm){
	int i;
	int numPes, my_pe;
	int bytes;
	int isCollect32;    // see which collect we use, 1=collect32, 0=collect64, -1=error
	
	numPes = _num_pes();
	my_pe = shmem_my_pe();
	
	// Verify that you have valid buffer pointer and space:
	if ( (recvbuf == NULL) || (sendbuf == NULL) ){
		mlog(MPI_ERR, "Error: buffer has an invalid pointer (it's NULL) PE: %d\n", my_pe);
		return MPI_ERR_BUFFER;
	}
	
	if ( !shmem_addr_accessible( recvbuf, my_pe) || !shmem_addr_accessible( sendbuf, my_pe) ) {
		printf("MPI_Allgather::Buffer is not in a symmetric segment, pe: %d\n", my_pe);
		mlog(MPI_ERR, "Error: Buffer is not in a symmetric segment, %d\n", my_pe);
		return MPI_ERR_BUFFER;
	}
	
	// Check to see if the datatype (send) is correct...
	bytes = sizeof (int);
	
	if ( (sendtype == MPI_INT) || (sendtype == MPI_UNSIGNED) ){
		if (bytes == INT_32) {
			isCollect32 = 1;
		}
		else if (bytes == INT_64) {
			isCollect32 = 0;
		}
		else isCollect32 = -1;
	}
	else if ( (sendtype == MPI_LONG) || (sendtype == MPI_UNSIGNED_LONG) ){
		if (bytes == INT_32) {
			isCollect32 = 1;
		}
		else if (bytes == INT_64) {
			isCollect32 = 0;
		}
		else isCollect32 = -1;
	}	
	if ( isCollect32 == -1 ){
		printf("MPI_Allgather:: wrong datatype, can only handle integers.\n");
		mlog(MPI_ERR, "Invalid datatype in sendtype, must be MPI_INT\n");
		return MPI_ERR_TYPE;
	}			
	
	// Do what opneshmem needs to do:
	for (i = 0; i < _SHMEM_BCAST_SYNC_SIZE; i += 1){
		pSync[i] = _SHMEM_SYNC_VALUE;
    }
	
	MPI_Barrier( MPI_COMM_WORLD );
	
	if ( isCollect32 ){
		shmem_collect32(recvbuf, sendbuf, sendcount, masterRank, 0, numPes, pSync);
	}
	else {
		shmem_collect64(recvbuf, sendbuf, sendcount, masterRank, 0, numPes, pSync);
	}	
	
	return MPI_SUCCESS;
}


/**
 * MPI_Gather
 * Gathers together values from a group of processes
 *
 * The jth block of data sent from each process is received by every process and placed in the jth block of the buffer recvbuf.
 *
 *  This is misleading; a better description is
 *  The block of data sent from the jth process is received by every process and placed in the jth block of the buffer recvbuf.
 * 
 * @param  sendbuf		starting address of send buffer (choice) 
 * @param  sendcount	number of elements in send buffer (integer) 
 * @param  sendtype		data type of send buffer elements (handle)
 * @param  recvbuf		address of receive buffer (choice) (output parameter)
 * @param  recvcount	number of elements received from any process (integer) 
 * @param  recvtype		data type of receive buffer elements (handle) 
 * @param  comm			communicator (handle)  
 *  
 * @return 
 */
int MPI_Gather (void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int masterRank, MPI_Comm comm){
	int i;
	int numPes, my_pe;
	int bytes;
	int isCollect32;    // see which collect we use, 1=collect32, 0=collect64, -1=error
	
	numPes = _num_pes();
	my_pe = shmem_my_pe();
	
	// Verify that you have valid buffer pointer and space:
	if ( (recvbuf == NULL) || (sendbuf == NULL) ){
		mlog(MPI_ERR, "Error: buffer has an invalid pointer (it's NULL) PE: %d\n", my_pe);
		return MPI_ERR_BUFFER;
	}
	
	if ( !shmem_addr_accessible( recvbuf, my_pe) || !shmem_addr_accessible( sendbuf, my_pe) ) {
		printf("MPI_Gather::Buffer is not in a symmetric segment, pe: %d\n", my_pe);
		mlog(MPI_ERR, "Error: Buffer is not in a symmetric segment, %d\n", my_pe);
		return MPI_ERR_BUFFER;
	}
	
	// Check to see if the datatype (send) is correct...
	bytes = sizeof (int);
	

	return MPI_SUCCESS;
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
	
	recv_buf = mpiComm[comm].bufferPtr;
	
	if (recv_buf == NULL){
	  ret = MPI_ERR_BUFFER;// some sort of proper error here
		mlog(MPI_DBG, "Error: No symmetric memory for PE: %d\n", my_pe);
		return ret;
	}
	else {
	  ret = MPI_SUCCESS;
	}
	
#ifdef DEBUG
	if (shmem_addr_accessible( recv_buf, my_pe) ) {
	  mlog(MPI_DBG, "MPI_Recv::Buffer is in a symmetric segment, pe: %d\n", my_pe);
	}else{
	  mlog(MPI_DBG, "MPI_Recv::Buffer is NOT in a symmetric segment, pe: %d\n", my_pe);
	}
#endif
	
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
	
	recv_buf = mpiComm[comm].bufferPtr;
	
	if (recv_buf == NULL){
		ret = MPI_ERR_BUFFER;// some sort of proper error here
		mlog(MPI_DBG, "Error: No symmetric memory for PE: %d\n", my_pe);
		return ret;
	}
	else {
		ret = MPI_SUCCESS;
	}
	printf("MPI_Send: PE: %d, recv_buffer Addr = %x\n", my_pe, recv_buf);
	
	if (shmem_addr_accessible( recv_buf, my_pe) ) {
		mlog(MPI_DBG, "MPI_SEND::Buffer is in a symmetric segment, pe: %d\n", my_pe);
	}else{
		mlog(MPI_DBG, "MPI_SEND::Buffer is NOT in a symmetric segment, pe: %d\n", my_pe);
	}
	
	switch (datatype){
		case MPI_CHAR:
		case MPI_UNSIGNED_CHAR:
		case MPI_BYTE:
			shmem_char_put(recv_buf, buf, count, dest);
			break;
		case MPI_SHORT:
		case MPI_UNSIGNED_SHORT:
			shmem_short_put(recv_buf, buf, count, dest);
			break;
		case MPI_INT:
		case MPI_UNSIGNED:
			shmem_int_put(recv_buf, buf, count, dest);
			break;
		case MPI_LONG:
		case MPI_UNSIGNED_LONG:
			shmem_long_put(recv_buf, buf, count, dest);
			break;
		case MPI_FLOAT:
			shmem_float_put(recv_buf, buf, count, dest);
			break;
		case MPI_DOUBLE:
			shmem_double_put(recv_buf, buf, count, dest);
			break;
		case MPI_LONG_DOUBLE:
			shmem_longdouble_put(recv_buf, buf, count, dest);
			break;
		case MPI_LONG_LONG:
			shmem_longlong_put(recv_buf, buf, count, dest);
			break;
		default:
			shmem_putmem(recv_buf, buf, count, dest);
			break;
	}
	
	// and to be on the safe side:
	shmem_fence();
	
	return ret;
}

/**
 * MPI_Irecv
 * Nonblocking receive for a message
 * Which doesn't exist in openShmem...
 * So I am ignoring the requestComm and have no idea how to do MPI_Test.
 *
 * @param buf		initial address of receive buffer (choice) 
 * @param count		number of elements in receive buffer (integer) 
 * @param datatype	datatype of each receive buffer element (handle) 
 * @param source	rank of source (integer) 
 * @param tag		message tag (integer) 
 * @param comm		communicator (handle) 
 * 
 * Output Parameter
 * 
 * @param request	communication request (handle) 
 *  
 * @return status
 */
int MPI_Irecv (void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *requestComm){
	
	int  ret;
	void *recv_buf;
	int my_pe = shmem_my_pe();
	
	recv_buf = mpiComm[comm].bufferPtr;
	
	if (recv_buf == NULL){
		ret = MPI_ERR_BUFFER;// some sort of proper error here
		mlog(MPI_DBG, "Error: No symmetric memory for PE: %d\n", my_pe);
		return ret;
	}
	else {
		ret = MPI_SUCCESS;
	}
	
#ifdef DEBUG
	if (shmem_addr_accessible( recv_buf, my_pe) ) {
		mlog(MPI_DBG, "MPI_Irecv::Buffer is in a symmetric segment, pe: %d\n", my_pe);
	}else{
		mlog(MPI_DBG, "MPI_Irecv::Buffer is NOT in a symmetric segment, pe: %d\n", my_pe);
	}
#endif
	
	// ToDo: add in info to requestCom to track the get in MPI_Test
	
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
	
	return ret;
}

/**
 * MPI_Isend
 * Performs a nonblocking send. which really doesnt exist in openShmem...
 * So I am ignoring the requestComm and have no idea how to do MPI_Test.
 * However, we will not do the fence at the end (to speed things up...)
 *
 * @param 
 * @param 
 * @param 
 * @return 
 */
int MPI_Isend(void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *requestComm){
	
	int  ret;
	int my_pe = shmem_my_pe();
	void *recv_buf;
	
	recv_buf = mpiComm[comm].bufferPtr;
	
	if (recv_buf == NULL){
		ret = MPI_ERR_BUFFER;// some sort of proper error here
		mlog(MPI_DBG, "Error: No symmetric memory for PE: %d\n", my_pe);
		return ret;
	}
	else {
		ret = MPI_SUCCESS;
	}
	mlog(MPI_DBG,"MPI_Isend: PE: %d, recv_buffer Addr = %x\n", my_pe, recv_buf);
	
	if (shmem_addr_accessible( recv_buf, my_pe) ) {
		 mlog(MPI_DBG,"MPI_Isend::Buffer is in a symmetric segment, pe: %d\n", my_pe);
	}else{
		mlog(MPI_DBG,"MPI_Isend::Buffer is NOT in a symmetric segment, pe: %d\n", my_pe);
	}

	// ToDo: add in info to requestCom to track the put in MPI_Test

	switch (datatype){
		case MPI_CHAR:
		case MPI_UNSIGNED_CHAR:
		case MPI_BYTE:
			shmem_char_put(recv_buf, buf, count, dest);
			break;
		case MPI_SHORT:
		case MPI_UNSIGNED_SHORT:
			shmem_short_put(recv_buf, buf, count, dest);
			break;
		case MPI_INT:
		case MPI_UNSIGNED:
			shmem_int_put(recv_buf, buf, count, dest);
			break;
		case MPI_LONG:
		case MPI_UNSIGNED_LONG:
			shmem_long_put(recv_buf, buf, count, dest);
			break;
		case MPI_FLOAT:
			shmem_float_put(recv_buf, buf, count, dest);
			break;
		case MPI_DOUBLE:
			shmem_double_put(recv_buf, buf, count, dest);
			break;
		case MPI_LONG_DOUBLE:
			shmem_longdouble_put(recv_buf, buf, count, dest);
			break;
		case MPI_LONG_LONG:
			shmem_longlong_put(recv_buf, buf, count, dest);
			break;
		default:
			shmem_putmem(recv_buf, buf, count, dest);
			break;
	}
	
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
	
	int ret = MPI_SUCCESS;//MPI_Test (request, flag, status);

	// ToDo: Change this to polling the buffer to see if send/recv complete.
	
	shmem_barrier_all ();
	// Fence and quiet sometimes do the same thing...
	shmem_fence();   // Ensures ordering of outgoing write (put) operations to a single PE
	shmem_quiet();   // Waits for completion of all outstanding remote writes initiated from the calling PE
	
	return ret;
}
