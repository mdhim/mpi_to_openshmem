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
 * @return status.
 */

int MPI_Init( int *argc, char ***argv ){

	int        i;
	int		   ret = MPI_SUCCESS;
	void       *sharedBuffer;
	MPID_Group *groupPtr;
	int		   *pesGroupPtr;
	
	//Open mlog - stolen from plfs
	ret = mlog_open((char *)"mpi_to_openshmem", 0, MLOG_CRIT, MLOG_CRIT, NULL, 0, MLOG_LOGPID, 0);
	
	start_pes(0);
	
	int npes =  _num_pes ();
	int my_pe = shmem_my_pe();
	
	sharedBuffer = (void *)shmalloc(sizeof(char) * MAX_BUFFER_SIZE);
	if (sharedBuffer == NULL ){
		mlog(MPI_ERR, "MPI_Init:: PE: %d, could not shmalloc space for symmetric memory.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}

	if (shmem_addr_accessible( sharedBuffer, my_pe) ) {
		mlog(MPI_DBG, "MPI_Init::Buffer is in a symmetric segment for target pe: %d\n", my_pe);
	}else{
		mlog(MPI_ERR, "MPI_Init::Buffer is NOT in a symmetric segment for target pe: %d\n", my_pe);
		return MPI_ERR_BUFFER;
	}
	
	// Make space for the initial MPI_COMM_WORLD
	MPI_COMM_WORLD = (MPID_Comm *)shmalloc( sizeof(MPID_Comm) );
	if (MPI_COMM_WORLD == NULL ){
		mlog(MPI_ERR, "MPI_Init_thread:: PE: %d, could not shmalloc space for MPI_COMM_WORLD.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}

	// Make space for the initial group & initialize:
	groupPtr = (MPID_Group *)shmalloc(sizeof(MPID_Group));	
	if (groupPtr == NULL ){
		mlog(MPI_ERR, "MPI_Init:: PE: %d, could not shmalloc space for MPID_Group.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
	pesGroupPtr = (int *)shmalloc(sizeof(int) * npes);
	if (pesGroupPtr == NULL ){
		mlog(MPI_ERR, "MPI_Init:: PE: %d, could not shmalloc space for MPID_Group.pesInGroup.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
	
	//printf("MPI_Init_Thread: after start_pes, set up rank and local size\n");
	
	// Set up the rank and local_size (npes)
	((MPID_Comm) *MPI_COMM_WORLD).rank          = my_pe;
	((MPID_Comm) *MPI_COMM_WORLD).size          = npes;
	((MPID_Comm) *MPI_COMM_WORLD).bufferPtr     = sharedBuffer;
 	((MPID_Comm) *MPI_COMM_WORLD).groupPtr = groupPtr;
	
	// Set values in the Comm's Group
	((MPID_Group)*groupPtr).rank    = my_pe;
	((MPID_Group)*groupPtr).size    = npes;
	((MPID_Group)*groupPtr).pe_rank = my_pe;
	((MPID_Group)*groupPtr).pesInGroup = pesGroupPtr;

	// Initially all processes belong in the group.
	for (i=0; i<npes; i++){
		((MPID_Group)*groupPtr).pesInGroup[i] = i;
	}
		
#ifdef DEBUG
	int me = _my_pe();
	printf("MPI_Init_Thread: Me: %d, MPI_COMM_WORLD.rank: %d, .size: %d\n", me,((MPID_Comm) *MPI_COMM_WORLD).rank,((MPID_Comm) *MPI_COMM_WORLD).size);
	mlog(MPI_DBG, "MPI_Init_Thread: Me: %d, MPI_COMM_WORLD.rank: %d, .size: %d, .bufferPtr: %x\n", me, ((MPID_Comm) *MPI_COMM_WORLD).rank, ((MPID_Comm) *MPI_COMM_WORLD).size,((MPID_Comm) *MPI_COMM_WORLD).bufferPtr);
#endif
	
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
 *
 * @return status.
 */

int MPI_Init_thread( int *argc, char ***argv, int required, int *provided ){
	int        i;
	int		   ret = MPI_SUCCESS;
	void       *sharedBuffer;
	MPID_Group *groupPtr;
	int		   *pesGroupPtr;
	
	//Open mlog - stolen from plfs
	ret = mlog_open((char *)"mpi_to_openshmem", 0, MLOG_CRIT, MLOG_CRIT, NULL, 0, MLOG_LOGPID, 0);

	start_pes(0);
	
	int npes =  _num_pes ();
	int my_pe = shmem_my_pe();
	
	sharedBuffer = (void *)shmalloc(sizeof(char) * MAX_BUFFER_SIZE);
	if (sharedBuffer == NULL ){
		mlog(MPI_ERR, "MPI_Init_thread:: PE: %d, could not shmalloc space for symmetric memory.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
	
	if (shmem_addr_accessible( sharedBuffer, my_pe) ) {
		mlog(MPI_DBG, "MPI_Init_thread::Buffer is in a symmetric segment for target pe: %d\n", my_pe);
	}else{
		mlog(MPI_ERR, "MPI_Init_thread::Buffer is NOT in a symmetric segment for target pe: %d\n", my_pe);
		return MPI_ERR_BUFFER;
	}

	// Make space for the initial MPI_COMM_WORLD
	MPI_COMM_WORLD = (MPID_Comm *)shmalloc( sizeof(MPID_Comm) );
	if (MPI_COMM_WORLD == NULL ){
		mlog(MPI_ERR, "MPI_Init_thread:: PE: %d, could not shmalloc space for MPI_COMM_WORLD.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
		
	// Make space for the initial group structure:
	groupPtr = (MPID_Group *)shmalloc(sizeof(MPID_Group));
	if (groupPtr == NULL ){
		mlog(MPI_ERR, "MPI_Init_thread:: PE: %d, could not shmalloc space for MPID_Group.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
	pesGroupPtr = (int *)shmalloc(sizeof(int) * npes);
	if (pesGroupPtr == NULL ){
		mlog(MPI_ERR, "MPI_Init_thread:: PE: %d, could not shmalloc space for MPID_Group.pesInGroup.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}	
	
	//printf("MPI_Init_Thread: after start_pes, set up rank and local size\n");
	
	// Set up the rank and local_size (npes)
	((MPID_Comm) *MPI_COMM_WORLD).rank          = my_pe;
	((MPID_Comm) *MPI_COMM_WORLD).size          = npes;
	((MPID_Comm) *MPI_COMM_WORLD).bufferPtr     = sharedBuffer;
 	((MPID_Comm) *MPI_COMM_WORLD).groupPtr = groupPtr;
	
	// Set values in the Comm's Group
	((MPID_Group)*groupPtr).rank    = my_pe;
	((MPID_Group)*groupPtr).size    = npes;
	((MPID_Group)*groupPtr).pesInGroup = pesGroupPtr;
	
	// Initially all processes belong in the group.
	for (i=0; i<npes; i++){
		((MPID_Group)*groupPtr).pesInGroup[i] = i;
	}
	
		
#ifdef DEBUG
		int me = _my_pe();
		printf("MPI_Init_Thread: Me: %d, MPI_COMM_WORLD.rank: %d, .size: %d\n", me, ((MPID_Comm) *MPI_COMM_WORLD).rank,((MPID_Comm) *MPI_COMM_WORLD).size);
		mlog(MPI_DBG, "MPI_Init_Thread: Me: %d, MPI_COMM_WORLD.rank: %d, .size: %d, .bufferPtr: %x\n", me, ((MPID_Comm) *MPI_COMM_WORLD).rank, ((MPID_Comm) *MPI_COMM_WORLD).size,((MPID_Comm) *MPI_COMM_WORLD).bufferPtr);
#endif
	
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

/**
 * MPI_Abort
 * Terminates MPI execution environment.
 *
 * @param comm		communicator (handle)
 * @param errorcode	error code to return to invoking environment 
 * 
 * @return status
 */
int MPI_Abort (MPI_Comm comm, int errorcode){
	int ret = MPI_SUCCESS;
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
	
	// Clear all of the outstanding puts, and that's pretty much all  we can do..
	shmem_barrier_all();
	errorcode = MPI_SUCCESS;
	
	return ret;
}

/**
 * MPI_Barrier
 * Blocks until all processors in the communicator ave reached this routine.
 *
 * @param comm	communicator (handle)
 *
 * @return status
 */
int MPI_Barrier (MPI_Comm comm){

	int ret = MPI_SUCCESS;

	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
	
	shmem_barrier_all ();  // shmem_barrier (int PE_start, int logPE_stride, int PE_size, long *pSync)
	return ret;
}

/**
 * MPI_Bcast
 * Broadcasts a message from the process with rank "root" to all other processes
 *	of the communicator.
 *
 * Input/Output Parameter
 *
 * @param  buffer		starting address of buffer (choice) 
 *
 * Input Parameters
 *
 * @param  count		number of entries in buffer (integer) 
 * @param  datatype	data type of buffer (handle) 
 * @param  root		rank of broadcast root (integer) 
 * @param  comm		communicator (handle) 
 *
 * @return status
 */
int MPI_Bcast ( void *source, int count, MPI_Datatype dataType, int root, MPI_Comm comm){
	
	int  i;
	int  npes, my_pe;
	void *target;

	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
	
	npes = _num_pes();
	my_pe = shmem_my_pe();
	
	target = (void *)((MPID_Comm)*comm).bufferPtr;
	if (target != NULL){
        mlog(MPI_DBG,"MPI_Bcast:: mpiComm[comm].bufferPtr: %x\n", target);
	}else{
		mlog(MPI_DBG,"MPI_Bcast:: target is NULL\n\n");
		return MPI_ERR_BUFFER;
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
	
	shmem_broadcast64( ((MPID_Comm)*comm).bufferPtr, source, count, root, 0, 0, npes, pSync);
	
	
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
 * @param comm	   communicator (handle) 
 * @param group	   group, which is a subset of the group of comm (handle)
 * @param newcomm  new communicator (handle) 
 *
 * @return		   status
 */
int MPI_Comm_create (MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm){

	int        i;
	void       *sharedBuffer;
	MPID_Group *groupPtr;
	int		   *pesGroupPtr;
	int		   bIsPeInGroup = 0; // boolean to see if the current pe is in comm's group.

	int npes =  _num_pes ();
	int my_pe = shmem_my_pe();

	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
	
	// Do the following, if the process is in comm's group
	i = 0;
	while ( ( i < ((MPID_Group)*((MPID_Comm)*comm).groupPtr).size ) && !bIsPeInGroup) {
		if ( my_pe == ((MPID_Group)*((MPID_Comm)*comm).groupPtr).pesInGroup[i] ) {
			bIsPeInGroup = 1;
		}
		i++;
	}
	
	if (bIsPeInGroup) {
				
		sharedBuffer = (void *)shmalloc(sizeof(char) * MAX_BUFFER_SIZE);
		if (sharedBuffer == NULL ){
			mlog(MPI_ERR, "MPI_Comm_create:: PE: %d, could not shmalloc space for symmetric memory.\n", my_pe);
			return MPI_ERR_NO_MEM;
		}
		
		if (shmem_addr_accessible( sharedBuffer, my_pe) ) {
			mlog(MPI_DBG, "MPI_Comm_create::Buffer is in a symmetric segment for target pe: %d\n", my_pe);
		}else{
			mlog(MPI_ERR, "MPI_Comm_create::Buffer is NOT in a symmetric segment for target pe: %d\n", my_pe);
			return MPI_ERR_BUFFER;
		}
		
		// Make space for the new comunicator & its group, then initialize:
		*newcomm = (MPI_Comm)shmalloc( sizeof(MPID_Comm) );
		if (*newcomm == NULL ){
			mlog(MPI_ERR, "MPI_Comm_create:: PE: %d, could not shmalloc space for a new communicator.\n", my_pe);
			return MPI_ERR_NO_MEM;
		}
		groupPtr = (MPID_Group *)shmalloc(sizeof(MPID_Group));
		if (groupPtr == NULL ){
			mlog(MPI_ERR, "MPI_Comm_create:: PE: %d, could not shmalloc space for MPID_Group.\n", my_pe);
			return MPI_ERR_NO_MEM;
		}
		pesGroupPtr = (int *)shmalloc(sizeof(int) * npes);
		if (pesGroupPtr == NULL ){
			mlog(MPI_ERR, "MPI_Comm_create:: PE: %d, could not shmalloc space for MPID_Group.pesInGroup.\n", my_pe);
			return MPI_ERR_NO_MEM;
		}
		((MPID_Group)*groupPtr).rank    = group.rank;
		((MPID_Group)*groupPtr).size    = group.size;
		((MPID_Group)*groupPtr).pesInGroup = pesGroupPtr;
				
		printf("MPI_Comm_create: after start_pes, set up rank and local size\n");
		
		// Set up the rank and local_size (npes)                                                       
		MPID_Comm *newCommStruct;		// Because this is confusing...
		newCommStruct = *newcomm;
		((MPID_Comm)*newCommStruct).rank      = my_pe;
		((MPID_Comm)*newCommStruct).size      = group.size;
		((MPID_Comm)*newCommStruct).bufferPtr = sharedBuffer;
		((MPID_Comm)*newCommStruct).groupPtr = groupPtr;
		
		for (i=0; i<group.size; i++){
			printf("MPI_Comm_create:: PE: %d, group[%d] = %d\n", my_pe, i, group.pesInGroup[i]);
			((MPID_Group)*groupPtr).pesInGroup[i] = group.pesInGroup[i];
		}
		
		
#ifdef DEBUG
		printf("MPI_Comm_Create: PE: %d, newcomm.rank: %d, .size: %d\n", my_pe, ((MPID_Comm)**newcomm).rank, ((MPID_Comm)**newcomm).size);
		mlog(MPI_DBG, "MPI_Comm_Create: Me: %d, newcomm.rank: %d, .size: %d, .bufferPtr: %x\n", my_pe, ((MPID_Comm)**newcomm).rank, ((MPID_Comm)**newcomm).size, ((MPID_Comm)**newcomm).bufferPtr);
#endif
	}
	return MPI_SUCCESS;
}

/**
 * MPI_Comm_dup
 * Duplicates an existing communicator with all its cached information 
 *
 * @param comm	   communicator (handle) 
 * @param newcomm  new communicator (handle) 
 *
 * @return		   status
 */
int MPI_Comm_dup (MPI_Comm comm, MPI_Comm *newcomm){
	int        i;
	void       *sharedBuffer;
	MPID_Group *groupPtr;
	int                *pesGroupPtr;
	int                numRanks;
	
	int npes =  _num_pes ();
	int my_pe = shmem_my_pe();
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
		
	// Create new shared memory space for the new communicator.                                                                                               
	sharedBuffer = (void *)shmalloc(sizeof(char) * MAX_BUFFER_SIZE);
	if (sharedBuffer == NULL ){
		mlog(MPI_ERR, "MPI_Comm_dup:: PE: %d, could not shmalloc space for symmetric memory.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
	
	if (shmem_addr_accessible( sharedBuffer, my_pe) ) {
		mlog(MPI_DBG, "MPI_Comm_dup::Buffer is in a symmetric segment for target pe: %d\n", my_pe);
	}else{
		mlog(MPI_ERR, "MPI_Comm_dup::Buffer is NOT in a symmetric segment for target pe: %d\n", my_pe);
		return MPI_ERR_BUFFER;
	}
	
	// Make space for the new comuninicator & its group, then duplicate:                                                                                      
	*newcomm = (MPI_Comm)shmalloc( sizeof(MPID_Comm) );
	if (*newcomm == NULL ){
		mlog(MPI_ERR, "MPI_Comm_dup:: PE: %d, could not shmalloc space for a new communicator.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
	groupPtr = (MPID_Group *)shmalloc(sizeof(MPID_Group));
	if (groupPtr == NULL ){
		mlog(MPI_ERR, "MPI_Comm_dup:: PE: %d, could not shmalloc space for MPID_Group.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
	
	// Get the details of the original communicator                                                                                                           
	numRanks = 0;
	MPID_Group      *origGroupPtr;
	origGroupPtr = ((MPID_Group*)((MPID_Comm)*comm).groupPtr);
	numRanks = ((MPID_Group)*origGroupPtr).size;
	
	pesGroupPtr = (int *)shmalloc(sizeof(int) * numRanks);
	if (pesGroupPtr == NULL ){
		mlog(MPI_ERR, "MPI_Comm_dup:: PE: %d, could not shmalloc space for MPID_Group.pesInGroup.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
	
	((MPID_Group)*groupPtr).rank    = ((MPID_Group)*origGroupPtr).rank;
	((MPID_Group)*groupPtr).size    = numRanks;
	((MPID_Group)*groupPtr).pesInGroup = pesGroupPtr;
	
	printf("MPI_Comm_dup: after start_pes, set up rank and local size\n");
	
	// Set up the rank and local_size (npes)                                                                                                                  
	MPID_Comm *newCommStruct;               // Because this is confusing...                                                                                   
	newCommStruct = *newcomm;
	((MPID_Comm)*newCommStruct).rank      = my_pe;
	((MPID_Comm)*newCommStruct).size      = numRanks;
	((MPID_Comm)*newCommStruct).bufferPtr = sharedBuffer;
	((MPID_Comm)*newCommStruct).groupPtr = groupPtr;
	
	for (i=0; i<numRanks; i++){
		printf("MPI_Comm_dup:: PE: %d, group[%d] = %d\n", my_pe, i, ((MPID_Group)*origGroupPtr).pesInGroup[i]);
		((MPID_Group)*groupPtr).pesInGroup[i] = ((MPID_Group)*origGroupPtr).pesInGroup[i];
	}
	
	
#ifdef DEBUG
	printf("MPI_Comm_dup: PE: %d, newcomm.rank: %d, .size: %d\n", my_pe, ((MPID_Comm)**newcomm).rank, ((MPID_Comm)**newcomm).size);
	mlog(MPI_DBG, "MPI_Comm_dup: Me: %d, newcomm.rank: %d, .size: %d, .bufferPtr: %x\n", my_pe, ((MPID_Comm)**newcomm).rank, ((MPID_Comm)**newcomm).size, ((MPID_Comm)**newcomm).bufferPtr);
#endif
	
	return MPI_SUCCESS;
	
}

/**
 * MPI_Comm_free
 * Marks the communicator object for deallocation
 *
 * @param comm	communicator
 * 
 * @return status
 */
int MPI_Comm_free (MPI_Comm comm){
	
	int ret = MPI_SUCCESS;
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
		
	return ret;
}

/**
 * MPI_Comm_group
 * Accesses the group associated with given communicator
 *
 * @param comm	communicator
 * @param group	pointer to the group in the communicator
 * 
 * @return status
 */
int MPI_Comm_group (MPI_Comm comm,	MPI_Group *group){
	
	int ret = MPI_SUCCESS;
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
	
	group = ((MPID_Comm)*comm).groupPtr;
	
	if (group == NULL){
		int my_pe = shmem_my_pe();
		mlog(MPI_ERR, "MPI_Comm_group, my_pe: %-8d, comm.groupPtr is NULL.\n",  my_pe);
		return MPI_ERR_COMM;
	}
	
	return ret;
}

/**
 * MPI_Comm_rank
 * Determines the rank of the calling process in the communicator
 *
 * @param comm communicator(handle)
 * @param rank of the calling process in the group of comm (integer)
 *
 * @return status
 */
int MPI_Comm_rank (MPI_Comm comm, int *rank){
	
	MPID_Group *groupPtr;
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
		
	groupPtr = ((MPID_Comm)*comm).groupPtr;
	
	if (groupPtr == NULL){
		int my_pe = shmem_my_pe();
		mlog(MPI_ERR, "MPI_Comm_rank, my_pe: %-8d, comm.groupPtr is NULL.\n",  my_pe);
		return MPI_ERR_COMM;
	}
	*rank = ((MPID_Group)*groupPtr).rank;
	
#ifdef DEBUG
	int my_pe = shmem_my_pe();
	printf("MPI_Comm_rank, my_pe: %-8d rank: %d\n",  my_pe, *rank);
#endif	
	return MPI_SUCCESS;
}

/**
 * MPI_Comm_size
 * Determines the size of the group associated with a communicator
 *
 * @param comm communicator(handle)
 * @param size number of processes in the group of comm (integer) 
 *
 * @return status
 */
int MPI_Comm_size(MPI_Comm comm, int *size ){
	
	MPID_Group *groupPtr;
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
		
	groupPtr = ((MPID_Comm)*comm).groupPtr;
	
	if (groupPtr == NULL){
		int my_pe = shmem_my_pe();
		mlog(MPI_ERR, "MPI_Comm_size, my_pe: %-8d, comm.groupPtr is NULL.\n",  my_pe);
		return MPI_ERR_COMM;
	}
	*size = ((MPID_Group)*groupPtr).size;
	
#ifdef DEBUG
	int my_pe = shmem_my_pe();
	printf("MPI_Comm_size, my_pe: %-8d size: %d\n", my_pe, *size);
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
 * @return status
 */
int MPI_Allgather (void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm){
	int i;
	int numPes, my_pe;
	int bytes;
	int isCollect32;    // see which collect we use, 1=collect32, 0=collect64, -1=error
	
	numPes = _num_pes();
	my_pe = shmem_my_pe();
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
		
	// Verify that you have valid buffer pointer and space:
	if ( (recvbuf == NULL) || (sendbuf == NULL) ){
		mlog(MPI_ERR, "Error: buffer has an invalid pointer (it's NULL) PE: %d\n", my_pe);
		return MPI_ERR_BUFFER;
	}
	
	if ( !shmem_addr_accessible( recvbuf, my_pe) || !shmem_addr_accessible( sendbuf, my_pe) ) {
		//printf("MPI_Allgather::Buffer is not in a symmetric segment, pe: %d\n", my_pe);
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
		//printf("MPI_Allgather:: wrong datatype, can only handle integers.\n");
		mlog(MPI_ERR, "Invalid datatype in sendtype, must be MPI_INT\n");
		return MPI_ERR_TYPE;
	}			
	
	// Do what opneshmem needs to do:
	for (i = 0; i < _SHMEM_BCAST_SYNC_SIZE; i += 1){
		pSync[i] = _SHMEM_SYNC_VALUE;
    }
	
	MPI_Barrier( comm );
	
	if ( isCollect32 ){
		shmem_collect32(recvbuf, sendbuf, sendcount, 0, 0, numPes, pSync);
	}
	else {
		shmem_collect64(recvbuf, sendbuf, sendcount, 0, 0, numPes, pSync);
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
 * @return status
 */
int MPI_Gather (void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm){
	//int i;
	int numPes, my_pe;
	
	numPes = _num_pes();
	my_pe = shmem_my_pe();
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
		
	// Verify that you have valid buffer pointer and space:
	if ( (recvbuf == NULL) || (sendbuf == NULL) ){
		mlog(MPI_ERR, "Error: buffer has an invalid pointer (it's NULL) PE: %d\n", my_pe);
		return MPI_ERR_BUFFER;
	}
	
	if ( !shmem_addr_accessible( recvbuf, my_pe) || !shmem_addr_accessible( sendbuf, my_pe) ) {
		//printf("MPI_Gather::Buffer is not in a symmetric segment, pe: %d\n", my_pe);
		mlog(MPI_ERR, "Error: Buffer is not in a symmetric segment, %d\n", my_pe);
		return MPI_ERR_BUFFER;
	}

	shmem_barrier_all ();
	
	switch (sendtype){
		case MPI_CHAR:
		case MPI_UNSIGNED_CHAR:
		case MPI_BYTE:
			shmem_putmem(&(((char*)recvbuf)[sendcount*my_pe]), sendbuf, sendcount, root);
			break;
		case MPI_SHORT:
		case MPI_UNSIGNED_SHORT:
			shmem_short_put(&(((short*)recvbuf)[sendcount*my_pe]), sendbuf, sendcount, root);
			break;
		case MPI_INT:
		case MPI_UNSIGNED:
			shmem_int_put(&(((int*)recvbuf)[sendcount*my_pe]), sendbuf, sendcount, root);
			//printf ("Debug:  - from %d to recvbuf[%d] =", root, my_pe);
			//for (i = 0; i < 20; i += 1) {
			//	printf (" %d", ((int*)recvbuf)[i]);
			///}
			//printf ("\n");
			break;
		case MPI_LONG:
		case MPI_UNSIGNED_LONG:
			shmem_long_put(&(((long*)recvbuf)[sendcount*my_pe]), sendbuf, sendcount, root);
			break;
		case MPI_FLOAT:
			shmem_float_put(&(((float*)recvbuf)[sendcount*my_pe]), sendbuf, sendcount, root);
			break;
		case MPI_DOUBLE:
			shmem_double_put(&(((double*)recvbuf)[sendcount*my_pe]), sendbuf, sendcount, root);
			break;
		case MPI_LONG_DOUBLE:
			shmem_longdouble_put(&(((long double*)recvbuf)[sendcount*my_pe]), sendbuf, sendcount, root);
			break;
		case MPI_LONG_LONG:
			shmem_longlong_put(&(((long long*)recvbuf)[sendcount*my_pe]), sendbuf, sendcount, root);
			break;
		default:
			shmem_putmem(&(((char*)recvbuf)[sendcount*my_pe]), sendbuf, sendcount, root);
			break;
	}
	
	// and to be on the safe side:
	shmem_barrier_all ();
	
	return MPI_SUCCESS;
}

/**
 * MPI_Gatherv
 * Gathers into specified locations from all processes in a group
 *
 * @param  sendbuf		starting address of send buffer (choice) 
 * @param  sendcount	number of elements in send buffer (integer) 
 * @param  sendtype		data type of send buffer elements (handle) 
 * @param  recvcounts	integer array (of length group size) containing the number of elements that are received from each process (significant only at root) 
 * @param  displs		integer array (of length group size). Entry i specifies the displacement relative to recvbuf at which to place the incoming data from process i (significant only at root) 
 * @param  recvtype		data type of recv buffer elements (significant only at root) (handle) 
 * @param  root			rank of receiving process (integer) 
 * @param  comm			communicator (handle) 
 *
 * Output Parameter
 *
 * @param   recvbuf		address of receive buffer (choice, significant only at root) 
 *
 * @return status
 */
int MPI_Gatherv (void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int *recvcount, int *displs, MPI_Datatype recvtype, int root, MPI_Comm comm){

	//int i;
	int numPes, my_pe;	
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
	
	numPes = _num_pes();
	my_pe = shmem_my_pe();
	
	// Verify that you have valid buffer pointer and space:
	if ( (recvbuf == NULL) || (sendbuf == NULL) ){
		mlog(MPI_ERR, "Error: buffer has an invalid pointer (it's NULL) PE: %d\n", my_pe);
		return MPI_ERR_BUFFER;
	}
	
	if ( !shmem_addr_accessible( recvbuf, my_pe) || !shmem_addr_accessible( sendbuf, my_pe) ) {
		//printf("MPI_Gather::Buffer is not in a symmetric segment, pe: %d\n", my_pe);
		mlog(MPI_ERR, "Error: Buffer is not in a symmetric segment, pe: %d\n", my_pe);
		return MPI_ERR_BUFFER;
	}
	// Need to check the sendcount not larger than recvcount...
	if (sendcount < recvcount[my_pe]){
		mlog(MPI_ERR, "Error: send buffer is smaller than number of items requested, pe: %d\n", my_pe);
		return MPI_ERR_SIZE;
	}

	shmem_barrier_all ();
	switch (sendtype){
		case MPI_CHAR:
		case MPI_UNSIGNED_CHAR:
		case MPI_BYTE:
			shmem_putmem(&(((char *)recvbuf)[displs[my_pe]]), sendbuf, recvcount[my_pe], root);
			break;
		case MPI_SHORT:
		case MPI_UNSIGNED_SHORT:
			shmem_short_put(&(((short *)recvbuf)[displs[my_pe]]), sendbuf, recvcount[my_pe], root);
			break;
		case MPI_INT:
		case MPI_UNSIGNED:
			shmem_int_put(&(((int *)recvbuf)[displs[my_pe]]), sendbuf, recvcount[my_pe], root);
			/** debug
			 if (my_pe == root){
				printf ("gatherv - recvbuf[%d->%d] =", my_pe, root);
				for (i = 0; i < 13; i++) {
					printf (" %d", ((int *)recvbuf)[i]);
				}
				printf ("\n");
			}
			 **/
			break;
		case MPI_LONG:
		case MPI_UNSIGNED_LONG:
			shmem_long_put(&(((long *)recvbuf)[displs[my_pe]]), sendbuf, recvcount[my_pe], root);
			break;
		case MPI_FLOAT:
			shmem_float_put(&(((float *)recvbuf)[displs[my_pe]]), sendbuf, recvcount[my_pe], root);
			break;
		case MPI_DOUBLE:
			shmem_double_put(&(((double *)recvbuf)[displs[my_pe]]), sendbuf, recvcount[my_pe], root);
			break;
		case MPI_LONG_DOUBLE:
			shmem_longdouble_put(&(((long double *)recvbuf)[displs[my_pe]]), sendbuf, recvcount[my_pe], root);
			break;
		case MPI_LONG_LONG:
			shmem_longlong_put(&(((long long *)recvbuf)[displs[my_pe]]), sendbuf, recvcount[my_pe], root);
			break;
		default:
			shmem_putmem(&(((char *)recvbuf)[displs[my_pe]]), sendbuf, recvcount[my_pe], root);
			break;
	}
	
	// and to be on the safe side:
	shmem_barrier_all ();
	
	return MPI_SUCCESS;
}

/**
 * MPI_Group_inc
 * Produces a group by reordering an existing group and taking only listed members
 *
 * @param group		a current Communicators group (handle) 
 * @param n			number of elements in array ranks
 * @param ranks		ranks of processes in group to appear in newgroup
 * @param newgroup	new group derived from above, in the order defined by ranks.
 *
 * @return status
 */
int MPI_Group_incl (MPI_Group group, int n, int *ranks, MPI_Group *newgroup){
	int i, my_pe, new_rank;
	int *pesGroupPtr;

	my_pe = shmem_my_pe();
	
	pesGroupPtr = (int *)shmalloc(sizeof(int) * n);
	if (pesGroupPtr == NULL ){
		mlog(MPI_ERR, "MPI_Group_incl:: PE: %d, could not shmalloc space for MPI_Group's rank array.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
	for (i = 0; i < n; i++){
		pesGroupPtr[i] = ranks[i];
		
		if (ranks[i] == my_pe){
			new_rank = i;
		}
		mlog(MPI_DBG, "MPI_Group_incl:: PE: %d,  groupArray[%d] = %d\n", my_pe, i, ranks[i]);
	}
	
	((MPID_Group)*newgroup).rank    = new_rank;
	((MPID_Group)*newgroup).size    = n;
	((MPID_Group)*newgroup).pe_rank = my_pe;
	((MPID_Group)*newgroup).pesInGroup = pesGroupPtr;
	
	mlog(MPI_DBG, "MPI_Group_incl:: PE: %d,  new rank: %d\n", my_pe, new_rank);
	
	return MPI_SUCCESS;
}

/**
 * MPI_Recv
 * Blocking receive for a message
 *
 * Output Parameters
 *
 * @param  buf		initial address of receive buffer (choice) 
 * @param  status	status object (Status) 
 *
 * Input Parameters
 *
 * @param count		maximum number of elements in receive buffer (integer) 
 * @param  datatype	datatype of each receive buffer element (handle) 
 * @param  source	rank of source (integer) 
 * @param  tag		message tag (integer) 
 * @param  comm		communicator (handle) * @return 
 *
 * @return status
 */
int MPI_Recv (void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status){
	
	int  ret;
	void *recv_buf;
	int my_pe = shmem_my_pe();
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
		
	recv_buf = ((MPID_Comm)*comm).bufferPtr;
	
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
		  shmem_getmem(buf, recv_buf, count, source);
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
 * @param  buf		initial address of send buffer (choice) 
 * @param  count	number of elements in send buffer (nonnegative integer) 
 * @param  datatype	datatype of each send buffer element (handle) 
 * @param  dest		rank of destination (integer) 
 * @param  tag		message tag (integer) 
 * @param  comm		communicator (handle) 
 *  
 * @return status
 */
int MPI_Send (void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm){
	
	int  ret;
	int my_pe = shmem_my_pe();
	void *recv_buf;
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
	
	recv_buf = ((MPID_Comm)*comm).bufferPtr;
	
	if (recv_buf == NULL){
		ret = MPI_ERR_BUFFER;// some sort of proper error here
		mlog(MPI_DBG, "Error: No symmetric memory for PE: %d\n", my_pe);
		return ret;
	}
	else {
		ret = MPI_SUCCESS;
	}
	//mlog(MPI_DBG,"MPI_Send: PE: %d, recv_buffer Addr = %x\n", my_pe, recv_buf);
	
	if (shmem_addr_accessible( recv_buf, my_pe) ) {
		mlog(MPI_DBG, "MPI_SEND::Buffer is in a symmetric segment, pe: %d\n", my_pe);
	}else{
		mlog(MPI_DBG, "MPI_SEND::Buffer is NOT in a symmetric segment, pe: %d\n", my_pe);
	}
	
	switch (datatype){
		case MPI_CHAR:
		case MPI_UNSIGNED_CHAR:
		case MPI_BYTE:
			shmem_putmem(recv_buf, buf, count, dest);
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
int MPI_Irecv (void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request){
	
	int  ret;
	void *recv_buf;
	int my_pe = shmem_my_pe();
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
		
	recv_buf = ((MPID_Comm)*comm).bufferPtr;
	
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
	
	// Get the address (this is of the current PE's buffer space)
	(*request).expected   = shmalloc( sizeof(int) );                             
	(*request).lastBufPtr = &((int *)recv_buf)[count-1];
	
	switch (datatype){
		case MPI_CHAR:
		case MPI_UNSIGNED_CHAR:
		case MPI_BYTE:
			shmem_getmem(buf, recv_buf, count, source);
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
	// Set-up MPI_Request for MPI_Irecv
	shmem_int_get( (*request).expected, (*request).lastBufPtr, 1, source);
	(*request).requestType = RECEIVE_TYPE;
	(*request).rank		= source;
	(*request).dataType	= datatype;
	
	//printf("Irecv: PE: %d, From PE: %d, got: ? \n", my_pe, (*request).rank );
	
	return ret;
}

/**
 * MPI_Isend
 * Performs a nonblocking send. 
 *
 * @param buf		initial address of receive buffer (choice) 
 * @param count		number of elements in receive buffer (integer) 
 * @param datatype	datatype of each receive buffer element (handle) 
 * @param dest		rank of destination (integer) 
 * @param tag		message tag (integer) 
 * @param comm		communicator (handle) 
 * 
 * Output Parameter
 * 
 * @param request	communication request (handle) 
 *  
 * @return status
 */
int MPI_Isend(void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request){
	
	int  ret;
	int my_pe = shmem_my_pe();
	void *recv_buf;
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
	
	recv_buf = ((MPID_Comm)*comm).bufferPtr;
	
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

	// In Request, put the expected last value:
	(*request).expected   = shmalloc( sizeof(int) );                             
	((int *)((*request).expected))[0] = ((int *)buf)[count-1];         

	switch (datatype){
		case MPI_CHAR:
		case MPI_UNSIGNED_CHAR:
		case MPI_BYTE:
			shmem_putmem(recv_buf, buf, count, dest);
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
	
	// Get the address (this is of the current PE)
	(*request).lastBufPtr   = &((int *)recv_buf)[count-1];

	// Set-up MPI_Request for MPI_Isend                                                                        
	(*request).requestType = SEND_TYPE;
	(*request).rank		   = dest;
	(*request).dataType	   = datatype;
	
	//printf("MPI_Isend: PE: %d to PE: %d, sent: %d\n", my_pe, (*request).rank, ( (int *)(buf))[0] );
	return ret;
}

/**
 * MPI_Unpack
 * Unpack a buffer according to a datatype into contiguous memory
 *
 * @param inbuf		input buffer start (choice)
 * @param insize	size of input buffer, in bytes (integer)
 * @param position	current position in bytes (integer)
 * @param outbuf	output buffer start (choice)
 * @param outcount	number of items to be unpacked (integer)
 * @param datatype	datatype of each output data item (handle)
 * @param comm		communicator for packed message (handle)
 *
 * @return 
 */
int MPI_Unpack (void *inbuf, int insize, int *position, void *outbuf, int outcount, MPI_Datatype datatype, MPI_Comm comm){
	
	int numBytes;
	int totalNumBytes = 0;
	int my_pe = shmem_my_pe();
	int rank;
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
	
	MPI_Comm_rank(comm, &rank);
	
	// Figure out how many bytes the datatype has                                                                                
	switch (datatype){
		case MPI_CHAR:
		case MPI_UNSIGNED_CHAR:
		case MPI_BYTE:
			numBytes = outcount * sizeof(char);
			break;
		case MPI_SHORT:
		case MPI_UNSIGNED_SHORT:
			numBytes = outcount * sizeof(short);
			break;
		case MPI_INT:
		case MPI_UNSIGNED:
			numBytes = outcount * sizeof(int);
			break;
		case MPI_LONG:
		case MPI_UNSIGNED_LONG:
			numBytes = outcount * sizeof(unsigned long);
			break;
		case MPI_FLOAT:
			numBytes = outcount * sizeof(float);
			break;
		case MPI_DOUBLE:
			numBytes = outcount * sizeof(double);
			break;
		case MPI_LONG_DOUBLE:
			numBytes = outcount * sizeof(long double);
			break;
		case MPI_LONG_LONG:
			numBytes = outcount * sizeof(long long);
			break;
		default:
			numBytes = outcount * sizeof(char);
			break;
	}
	//mlog(MPI_DBG,"MPI_Unpack, PE: %d, Number of bytes: %d, position: %d \n", my_pe, numBytes, *position);
	//mlog(MPI_DBG,"MPI_Unpack, PE: %d, inbuf: %c, outbuf: %c \n", rank, ((char *)inbuf)[*position], ((char *)outbuf)[0]);
	
	// Check to see if there is enough space for the send:
	totalNumBytes = numBytes + *position;
	if (totalNumBytes > insize) {
		mlog(MPI_DBG,"MPI_Unpack:: PE: %d total bytes is larger (%d) than buffer size (%d).\n", my_pe, totalNumBytes, insize);
		return MPI_ERR_NO_SPACE;
	}
	
	// Send inbuf to outbuf with an offset of position: 
	//shmem_getmem(buf, recv_buf, count, source);
	shmem_getmem( outbuf, &(((char *)inbuf)[*position]), numBytes, rank);
	
	// Don't forget to increment the position
	*position = *position + numBytes;
	
	return MPI_SUCCESS;	
}

/**
 * MPI_Pack
 * Pack a buffer according to a datatype into contiguous memory
 *
 * @param inbuf		input buffer start (choice)
 * @param incount	number of input data items (integer)
 * @param datatype	datatype of each input data item (handle)
 * @param outbuf	output buffer start (choice)
 * @param outsize	output buffer size, in bytes (integer)
 * @param position	current position in buffer, in bytes (integer)
 * @param comm		communicator for packed message (handle)
 *
 * @return status
 */
int MPI_Pack(void *inbuf, int incount, MPI_Datatype datatype, void *outbuf, int outsize, int *position,  MPI_Comm comm){
	
	int numBytes;
	int totalNumBytes = 0;
	int my_pe = shmem_my_pe();
	int rank;
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
		
	MPI_Comm_rank(comm, &rank);
	
	// Figure out how many bytes the datatype has                                                                               
	switch (datatype){
		case MPI_CHAR:
		case MPI_UNSIGNED_CHAR:
		case MPI_BYTE:
			numBytes = incount * sizeof(char);
			break;
		case MPI_SHORT:
		case MPI_UNSIGNED_SHORT:
			numBytes = incount * sizeof(short);
			break;
		case MPI_INT:
		case MPI_UNSIGNED:
			numBytes = incount * sizeof(int);
			break;
		case MPI_LONG:
		case MPI_UNSIGNED_LONG:
			numBytes = incount * sizeof(unsigned long);
			break;
		case MPI_FLOAT:
			numBytes = incount * sizeof(float);
			break;
		case MPI_DOUBLE:
			numBytes = incount * sizeof(double);
			break;
		case MPI_LONG_DOUBLE:
			numBytes = incount * sizeof(long double);
			break;
		case MPI_LONG_LONG:
			numBytes = incount * sizeof(long long);
			break;
		default:
			numBytes = incount * sizeof(char);
			break;
	}
	
	//mlog(MPI_DBG,"MPI_Pack, PE: %d, Number of bytes: %d, position: %d \n", my_pe, numBytes, *position);
	//mlog(MPI_DBG,"MPI_Pack, PE: %d, inbuf: %c, outbuf: %c \n", rank, ((char *)inbuf)[*position], ((char *)outbuf)[0]);
	
	// Check to see if there is enough space for the send:
	totalNumBytes = numBytes + *position;
	if (totalNumBytes > outsize) {
		mlog(MPI_ERR,"MPI_Pack::, pe: %d total bytes is larger (%d) than buffer size (%d).\n", my_pe, totalNumBytes, outsize);
		return MPI_ERR_NO_SPACE;
	}
	
	// Send inbuf to outbuf with an offset of position:
	shmem_putmem( &(((char *)outbuf)[*position]), inbuf, numBytes, rank);
	
	// and to be on the safe side:
	shmem_fence();
	
	// Don't forget to increment the position
	*position = *position + numBytes;
	
	return MPI_SUCCESS;	
}

/**
 * MPI_Finalize
 * Terminates MPI execution environment 
 *
 * @return status
 */
int MPI_Finalize(void){
	// Clear all of the outstanding puts, and that's pretty much all  we can do..
	shmem_barrier_all();
	int ret = MPI_SUCCESS; //MPI_Finalize ();
	return ret;
}

/**
 * MPI_Test
 * Tests for the completion of a request
 *
 * @param request	MPI request (handle)
 * @param flag		true if operation completed (logical)
 * @param status	status object
 *
 * @return MPI_SUCCESS
 */
int MPI_Test (MPI_Request *request, int *flag, MPI_Status *status){
	int value = 0;
	
	// Asssume transfer not there:                                                                   
	*flag = 0;
	
	value = shmem_int_cswap( (*request).lastBufPtr, ((int *)((*request).expected))[0], ((int *)((*request).expected))[0], (*request).rank);
	
	if (value == ((int *)((*request).expected))[0] ){
		*flag = 1;
	}
	//mlog(MPI_DBG,"MPI_Test, flag: %d For Pe: %d, value = %d", *flag, (*request).rank, value);
	//mlog(MPI_DBG," lastBufPtr = %d, expected: %d\n",( (int *)((*request).lastBufPtr))[0], ( (int *)((*request).expected))[0] );
	
	return MPI_SUCCESS;
}
