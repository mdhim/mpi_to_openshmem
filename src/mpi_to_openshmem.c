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

void GetLongEnvVariable( char* envName, long *envValue, long defaultValue){
	char*         envVariable;
	
	int my_pe = shmem_my_pe();
	
	// Get the enivornament variable values:
	envVariable = NULL;
	envVariable = getenv(envName);
	
	if (envVariable == NULL){
		*envValue = defaultValue;
		if (my_pe == 0 )
			printf("GetLongEnvVariable:: envName: %s envVariable: %s\n", envName, envVariable);
	}else {
		*envValue = atol( envVariable );
		if (my_pe == 0 )
			printf("GetLongEnvVariable:: envName: %s envVariable: %s, envValue: %ld\n", envName, envVariable, *envValue);
	}
}

/**
 * MPI_Init
 * Initializes for Openshmem
 *
 * @param argc Pointer to the number of arguments 
 * @param argv Pointer to the argument vector 
 * @return status.
 */

int MPI_Init( int *argc, char ***argv ){

	int           i;
	int		      ret = MPI_SUCCESS;
	void          *sharedBuffer;
	void          *packedBuffer;
	void          *scratchBuffer;
	MPID_Group    *groupPtr;
	int		      *pesGroupPtr;
	MPID_SendRecv *sendRcvPtr;
	long		  maxNumTracked;
	long		  maxSizeSend;
	long		  maxSizePack;
	long		  maxSizeScratch;
	
	//Open mlog - stolen from plfs
	ret = mlog_open((char *)"mpi_to_openshmem", 0, MLOG_CRIT, MLOG_CRIT, NULL, 0, MLOG_LOGPID, 0);
	
	start_pes(0);
	
	int npes =  _num_pes ();
	int my_pe = shmem_my_pe();
	
	// It is not threaded:
	isMultiThreads = FALSE;
	
	
	GetLongEnvVariable("MAX_NUM_TRACKED",  &maxNumTracked,  MAX_NUM_TRACKED);
	GetLongEnvVariable("MAX_SIZE_SEND",    &maxSizeSend,    MAX_BUFFER_SIZE);
	GetLongEnvVariable("MAX_SIZE_PACK",    &maxSizePack,    MAX_BUFFER_SIZE);
	GetLongEnvVariable("MAX_SIZE_SCRATCH", &maxSizeScratch, MAX_BUFFER_SIZE);

	// Make space for the various buffers:
	sharedBuffer = (void *)shmalloc(sizeof(char) * (maxSizeSend * maxNumTracked));
	if (sharedBuffer == NULL ){
		mlog(MPI_ERR, "MPI_Init_thread:: PE: %d, could not shmalloc space for Send/Recv's symmetric memory.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
	packedBuffer = (void *)shmalloc(sizeof(char) * maxSizePack);
	if (packedBuffer == NULL ){
		mlog(MPI_ERR, "MPI_Init_thread:: PE: %d, could not shmalloc space for Pack/Unpack's symmetric memory.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
	scratchBuffer = (void *)shmalloc(sizeof(char) * maxSizeScratch);
	if (scratchBuffer == NULL ){
		mlog(MPI_ERR, "MPI_Init_thread:: PE: %d, could not shmalloc space for Scratch's symmetric memory.\n", my_pe);
		return MPI_ERR_NO_MEM;
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
	
	// Make space for the array of send/recv data
	sendRcvPtr = (MPID_SendRecv *)shmalloc(sizeof(MPID_SendRecv) * maxNumTracked);
	if (sendRcvPtr == NULL ){
		mlog(MPI_ERR, "MPI_Init_thread:: PE: %d, could not shmalloc space for MPID_SendRecv structures.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
	// Initialize values in array:
	for (i=0; i<maxNumTracked; i++) {
		sendRcvPtr[i].tag      = 0;
		sendRcvPtr[i].datatype = -1;
		sendRcvPtr[i].count    = 0;
		sendRcvPtr[i].bufPtr   = sharedBuffer; // (this is a calculated offset into shared buffer...)
		sendRcvPtr[i].afterBufAreaPtr = sharedBuffer; // (this is a calculated offset into shared buffer for the next buffer...)
		// GINGER: Need a way to track we don't overrun memory!
	}

	//printf("MPI_Init_Thread: after start_pes, set up rank and local size\n");
	
	// Set up the rank and local_size (npes)
	((MPID_Comm) *MPI_COMM_WORLD).rank       = my_pe;
	((MPID_Comm) *MPI_COMM_WORLD).size       = npes;
	((MPID_Comm) *MPI_COMM_WORLD).bufferPtr  = sharedBuffer;
	((MPID_Comm) *MPI_COMM_WORLD).packPtr    = packedBuffer;
	((MPID_Comm) *MPI_COMM_WORLD).scratchPtr = scratchBuffer;
 	((MPID_Comm) *MPI_COMM_WORLD).groupPtr   = groupPtr;
 	((MPID_Comm) *MPI_COMM_WORLD).offset     = 0;
	for (i=0; i<maxNumTracked; i++) {
		((MPID_Comm) *MPI_COMM_WORLD).sendInfo[i] = sendRcvPtr[i];
	}
	
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
	int           i;
	int		      ret = MPI_SUCCESS;
	void          *sharedBuffer; // This is going to be used for send/recv only...
	void          *packedBuffer;
	void          *scratchBuffer;
	MPID_Group    *groupPtr;
	int		      *pesGroupPtr;
	MPID_SendRecv *sendRcvPtr;
	long		  maxNumTracked;
	long		  maxSizeSend;
	long		  maxSizePack;
	long		  maxSizeScratch;
	
	//Open mlog - stolen from plfs
	ret = mlog_open((char *)"mpi_to_openshmem", 0, MLOG_CRIT, MLOG_CRIT, NULL, 0, MLOG_LOGPID, 0);

	start_pes(0);
	
	int npes =  _num_pes ();
	int my_pe = shmem_my_pe();

	// It is threaded:
	isMultiThreads = TRUE;

	GetLongEnvVariable("MAX_NUM_TRACKED",  &maxNumTracked,  MAX_NUM_TRACKED);
	GetLongEnvVariable("MAX_SIZE_SEND",    &maxSizeSend,    MAX_BUFFER_SIZE);
	GetLongEnvVariable("MAX_SIZE_PACK",    &maxSizePack,    MAX_BUFFER_SIZE);
	GetLongEnvVariable("MAX_SIZE_SCRATCH", &maxSizeScratch, MAX_BUFFER_SIZE);
	
	if (my_pe == 0){
		printf("MPI_Init_Thread:: maxNumTracked: %ld maxSizeSend: %ld maxSizePack: %ld  maxSizeScratch: %ld \n", maxNumTracked, maxSizeSend, maxSizePack, maxSizeScratch);
	}
	
	// Make Space for the various buffers:
	sharedBuffer = (void *)shmalloc(sizeof(char) * (maxSizeSend * maxNumTracked));
	if (sharedBuffer == NULL ){
		mlog(MPI_ERR, "MPI_Init_thread:: PE: %d, could not shmalloc space for Send/Recv's symmetric memory.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
	packedBuffer = (void *)shmalloc(sizeof(char) * maxSizePack);
	if (packedBuffer == NULL ){
		mlog(MPI_ERR, "MPI_Init_thread:: PE: %d, could not shmalloc space for Pack/Unpack's symmetric memory.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
	scratchBuffer = (void *)shmalloc(sizeof(char) * maxSizeScratch);
	if (scratchBuffer == NULL ){
		mlog(MPI_ERR, "MPI_Init_thread:: PE: %d, could not shmalloc space for Scratch's symmetric memory.\n", my_pe);
		return MPI_ERR_NO_MEM;
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

	// Make space for the array of send/recv data
	sendRcvPtr = (MPID_SendRecv *)shmalloc(sizeof(MPID_SendRecv) * maxNumTracked);
	if (sendRcvPtr == NULL ){
		mlog(MPI_ERR, "MPI_Init_thread:: PE: %d, could not shmalloc space for MPID_SendRecv structures.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
	// Initialize values in array:
	for (i=0; i<maxNumTracked; i++) {
		sendRcvPtr[i].tag      = 0;
		sendRcvPtr[i].datatype = -1;
		sendRcvPtr[i].count    = 0;
		sendRcvPtr[i].bufPtr   = sharedBuffer; // (this is a calculated offset into shared buffer...)
		sendRcvPtr[i].afterBufAreaPtr = sharedBuffer; // (this is a calculated offset into shared buffer for the next buffer...)
		// GINGER: Need a way to track we don't overrun memory!
	}
	
	//printf("MPI_Init_Thread: after start_pes, set up rank and local size\n");
	
	// Set up the rank and local_size (npes)
	((MPID_Comm) *MPI_COMM_WORLD).rank       = my_pe;
	((MPID_Comm) *MPI_COMM_WORLD).size       = npes;
	((MPID_Comm) *MPI_COMM_WORLD).bufferPtr  = sharedBuffer;
	((MPID_Comm) *MPI_COMM_WORLD).packPtr    = packedBuffer;
	((MPID_Comm) *MPI_COMM_WORLD).scratchPtr = scratchBuffer;
 	((MPID_Comm) *MPI_COMM_WORLD).groupPtr   = groupPtr;
 	((MPID_Comm) *MPI_COMM_WORLD).offset     = 0;
	for (i=0; i<maxNumTracked; i++) {
		((MPID_Comm) *MPI_COMM_WORLD).sendInfo[i] = sendRcvPtr[i];
	}
	
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
		//printf("MPI_Init_Thread: Me: %d, MPI_COMM_WORLD.rank: %d, .size: %d\n", me, ((MPID_Comm) *MPI_COMM_WORLD).rank,((MPID_Comm) *MPI_COMM_WORLD).size);
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
 * GetNumBytes
 *   Get the number of bytes from the count and MPI_Datatype.
 *
 * Input/Output Parameter
 *
 * @param  count	number of items.
 * @param  dataType	data type of the items
 *
 * @return numBytes number of bytes.
 */
int GetNumBytes( int count, MPI_Datatype dataType ){
	
	//int my_pe;
	int	 ret;
	long numBytes;
	
	if (isMultiThreads){
		pthread_mutex_lock(&lockGetNumBytes);
	}
	
	//my_pe = shmem_my_pe();
	ret = MPI_SUCCESS;
	numBytes = 0;
	
	switch (dataType){
		case MPI_CHAR:
		case MPI_UNSIGNED_CHAR:
		case MPI_BYTE:
			numBytes = count * sizeof(char);
			break;
		case MPI_SHORT:
		case MPI_UNSIGNED_SHORT:
			numBytes = count * sizeof(short);
			break;
		case MPI_INT:
		case MPI_UNSIGNED:
			numBytes = count * sizeof(int);
			break;
		case MPI_LONG:
		case MPI_UNSIGNED_LONG:
			numBytes = count * sizeof(long);
			break;
		case MPI_FLOAT:
			numBytes = count * sizeof(float);
			break;
		case MPI_DOUBLE:
			numBytes = count * sizeof(double);
			break;
		case MPI_LONG_DOUBLE:
			numBytes = count * sizeof(long double);
			break;
		case MPI_LONG_LONG:
			numBytes = count * sizeof(long long);
			break;
		default:
			numBytes = count * sizeof(char);
			ret = MPI_ERR_TYPE;
			break;
	}

	if (isMultiThreads){
		pthread_mutex_unlock(&lockGetNumBytes);
	}
	
	return numBytes;
} // GetNumBytes

/**
 * CopyMyData
 *   Copy data from one buffer to another.  Why am I not using memcpy?  
 *   because it didn't work.  The values never ended up in the destination 
 *	 buffer...
 *
 * Input/Output Parameter
 *
 * @param  toBuf	destination buffer
 * @param  fromBuf	source buffer
 * @param  count	number of items to copy
 * @param  dataType	data type of the items
 *
 * @return status
 */

int CopyMyData( void *toBuf, void *fromBuf, int count, MPI_Datatype dataType ){

	long numBytes;

	if (isMultiThreads){
		pthread_mutex_lock(&lockCopyData);
	}
	
	numBytes = GetNumBytes(count, dataType);
	
	memcpy(toBuf, fromBuf, numBytes);
	
	/**
	 int my_pe;
	 int i;
	 my_pe    = shmem_my_pe();

	 for (i=0; i<count; i++){
		printf("CopyMyData: my pe: %-8d fromBuf: %ld, numBytes: %ld \n", my_pe, ((int*)fromBuf)[i], numBytes);
	}
	for (i=0; i<count; i++){
		printf("CopyMyData: my pe: %-8d symSource: %ld\n", my_pe, ((int*)toBuf)[i]);
	}
	**/
	
	if (isMultiThreads){
		pthread_mutex_unlock(&lockCopyData);
	}
	
	return MPI_SUCCESS;
	
}

/**
 * GetBufferOffset
 *   Calculate the offset of comm's buffer, since you are
 *   using part of it for something...
 *   Adjust the offset in comm as well... Which needs to be cleared.
 *
 * Input/Output Parameter
 *
 * @param  count		number of items currently in the buffer
 * @param  offset		number of bytes in buffer.
 * @param  dataType		data type of the items
 * @param  comm		    communicator (handle) 
 *
 * @return  bufferPtr	calculate the offset from the last offset of the symmetric buffer.
 */

void *GetBufferOffset( int count, int *numBytes, MPI_Datatype dataType,  MPI_Comm comm){
	
	int my_pe;
	int currentOffset;
	int newOffset;
	void *bufferPtr;
	
	if (isMultiThreads){
		pthread_mutex_lock(&lockGetOffset);
	}

	my_pe = shmem_my_pe();
    
	// Get the current offset from the comm.
	*numBytes = GetNumBytes(count, dataType);
	currentOffset = ((MPID_Comm)*comm).offset;
	newOffset     = currentOffset + *numBytes;
	
	//printf("GetBufferOffset: rank: %d comm's offset: %d numByters in buffer: %d, long size: %ld\n", my_pe, currentOffset, *numBytes, sizeof(long));
	mlog(MPI_DBG, "GetBufferOffset: rank: %d numByters in buffer: %d, long size: %ld\n", my_pe, *numBytes, sizeof(long));

	bufferPtr = &(((void*)((MPID_Comm)*comm).bufferPtr)[newOffset]);

	if (isMultiThreads){
		pthread_mutex_unlock(&lockGetOffset);
	}

	return bufferPtr;
	
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
	void *symSource;
	void *destBuffer;
	int  createSymSource;
	int  numBytes;

	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
	
	if (isMultiThreads){
		pthread_mutex_lock(&lockBcast);
	}
		
	npes = _num_pes();
	my_pe = shmem_my_pe();

	createSymSource = FALSE;
	
	if ( !shmem_addr_accessible( source, my_pe) ) {
		// Okay, try to find a work around
		//printf("MPI_Bcast::Buffer is not in a symmetric segment, pe: %d\n", my_pe);
		mlog(MPI_DBG, "Debug: Buffer is not in a symmetric segment, %d\n", my_pe);
		
		symSource = ((void*)((MPID_Comm)*comm).bufferPtr);
		
		// Move user's source into the symmetric buffer, since they can't create one.
		CopyMyData( symSource, source, count, dataType);
		
#ifdef DEBUG
		/**for (i=0; i<count; i++){
			printf("MPI_Bcast: rank: %d symSource: %ld\n", my_pe, ((long*)symSource)[i]);
		}**/
#endif
		// Make the destination start at an offset:
		numBytes = 0;
		destBuffer = GetBufferOffset( count, &numBytes, dataType, comm );
		
		createSymSource = TRUE;
	}
	
	for (i = 0; i < _SHMEM_BCAST_SYNC_SIZE; i += 1){
		pSync[i] = _SHMEM_SYNC_VALUE;
    }
	
	shmem_barrier_all (); // This barrier has to be here, per OpenShmem Spec.
	
	if (createSymSource) {
		shmem_broadcast64( destBuffer, symSource, count, root, 0, 0, npes, pSync);
		
	}
	else{
		shmem_broadcast64( ((MPID_Comm)*comm).bufferPtr, source, count, root, 0, 0, npes, pSync);
	}
	
	shmem_barrier_all();
	
	// Move the symmetric buffer data into source, which is the target...
	if (my_pe != root) {

		if (!createSymSource) 
			CopyMyData(source, ((MPID_Comm)*comm).bufferPtr, count, dataType);
		else 
			CopyMyData(source, destBuffer, count, dataType);
	}
		
#ifdef DEBUG
	for (i = 0; i < count; i++){
		mlog(MPI_DBG, "MPI_Bcast1: rank: %-8d source: %ld\n", my_pe, ((long*)source)[i]); 
		//printf("MPI_Bcast1: rank: %-8d source: %ld\n", my_pe, ((long*)source)[i]);
		//if (!createSymSource) 
		//	printf("MPI_Bcast1: rank: %-8d bufferPtr: %ld\n", my_pe, ((long*)((MPID_Comm)*comm).bufferPtr)[i]);
	}
#endif

	if (isMultiThreads){
		pthread_mutex_unlock(&lockBcast);
	}
	
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

	int          i;
	void         *sharedBuffer;
	MPID_Group   *groupPtr;
	int		     *pesGroupPtr;
	int		     bIsPeInGroup = 0; // boolean to see if the current pe is in comm's group.

	int npes =  _num_pes ();
	int my_pe = shmem_my_pe();

	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
	
	if (isMultiThreads){
		pthread_mutex_lock(&lockCommCreate);
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
			if (isMultiThreads){
				pthread_mutex_unlock(&lockCommCreate);
			}
			return MPI_ERR_NO_MEM;
		}
		
		if (shmem_addr_accessible( sharedBuffer, my_pe) ) {
			mlog(MPI_DBG, "MPI_Comm_create::Buffer is in a symmetric segment for target pe: %d\n", my_pe);
		}else{
			mlog(MPI_ERR, "MPI_Comm_create::Buffer is NOT in a symmetric segment for target pe: %d\n", my_pe);
			if (isMultiThreads){
				pthread_mutex_unlock(&lockCommCreate);
			}
			return MPI_ERR_BUFFER;
		}
		
		// Make space for the new comunicator & its group, then initialize:
		*newcomm = (MPI_Comm)shmalloc( sizeof(MPID_Comm) );
		if (*newcomm == NULL ){
			mlog(MPI_ERR, "MPI_Comm_create:: PE: %d, could not shmalloc space for a new communicator.\n", my_pe);
			if (isMultiThreads){
				pthread_mutex_unlock(&lockCommCreate);
			}
			return MPI_ERR_NO_MEM;
		}
		groupPtr = (MPID_Group *)shmalloc(sizeof(MPID_Group));
		if (groupPtr == NULL ){
			mlog(MPI_ERR, "MPI_Comm_create:: PE: %d, could not shmalloc space for MPID_Group.\n", my_pe);
			if (isMultiThreads){
				pthread_mutex_unlock(&lockCommCreate);
			}
			return MPI_ERR_NO_MEM;
		}
		pesGroupPtr = (int *)shmalloc(sizeof(int) * npes);
		if (pesGroupPtr == NULL ){
			mlog(MPI_ERR, "MPI_Comm_create:: PE: %d, could not shmalloc space for MPID_Group.pesInGroup.\n", my_pe);
			if (isMultiThreads){
				pthread_mutex_unlock(&lockCommCreate);
			}
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
		((MPID_Comm)*newCommStruct).groupPtr  = groupPtr;
		
		for (i=0; i<group.size; i++){
			printf("MPI_Comm_create:: PE: %d, group[%d] = %d\n", my_pe, i, group.pesInGroup[i]);
			((MPID_Group)*groupPtr).pesInGroup[i] = group.pesInGroup[i];
		}
		
#ifdef DEBUG
		printf("MPI_Comm_Create: PE: %d, newcomm.rank: %d, .size: %d\n", my_pe, ((MPID_Comm)**newcomm).rank, ((MPID_Comm)**newcomm).size);
		mlog(MPI_DBG, "MPI_Comm_Create: Me: %d, newcomm.rank: %d, .size: %d, .bufferPtr: %x\n", my_pe, ((MPID_Comm)**newcomm).rank, ((MPID_Comm)**newcomm).size, ((MPID_Comm)**newcomm).bufferPtr);
#endif
	}

	if (isMultiThreads){
		pthread_mutex_unlock(&lockCommCreate);
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
	int           i;
	void         *sharedBuffer;
	MPID_Group   *groupPtr;
	int          *pesGroupPtr;
	int           numRanks;
	
	int my_pe = shmem_my_pe();
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
		
	if (isMultiThreads){
		pthread_mutex_lock(&lockCommDup);
	}

	// Create new shared memory space for the new communicator.                                                                                               
	sharedBuffer = (void *)shmalloc(sizeof(char) * MAX_BUFFER_SIZE);
	if (sharedBuffer == NULL ){
		mlog(MPI_ERR, "MPI_Comm_dup:: PE: %d, could not shmalloc space for symmetric memory.\n", my_pe);
		if (isMultiThreads){
			pthread_mutex_unlock(&lockCommDup);
		}
		return MPI_ERR_NO_MEM;
	}
	
	if (shmem_addr_accessible( sharedBuffer, my_pe) ) {
		mlog(MPI_DBG, "MPI_Comm_dup::Buffer is in a symmetric segment for target pe: %d\n", my_pe);
	}else{
		mlog(MPI_ERR, "MPI_Comm_dup::Buffer is NOT in a symmetric segment for target pe: %d\n", my_pe);
		if (isMultiThreads){
			pthread_mutex_unlock(&lockCommDup);
		}
		return MPI_ERR_BUFFER;
	}
	
	// Make space for the new comuninicator & its group, then duplicate:                                                                                      
	*newcomm = (MPI_Comm)shmalloc( sizeof(MPID_Comm) );
	if (*newcomm == NULL ){
		mlog(MPI_ERR, "MPI_Comm_dup:: PE: %d, could not shmalloc space for a new communicator.\n", my_pe);
		if (isMultiThreads){
			pthread_mutex_unlock(&lockCommDup);
		}
		return MPI_ERR_NO_MEM;
	}
	groupPtr = (MPID_Group *)shmalloc(sizeof(MPID_Group));
	if (groupPtr == NULL ){
		mlog(MPI_ERR, "MPI_Comm_dup:: PE: %d, could not shmalloc space for MPID_Group.\n", my_pe);
		if (isMultiThreads){
			pthread_mutex_unlock(&lockCommDup);
		}
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
		if (isMultiThreads){
			pthread_mutex_unlock(&lockCommDup);
		}
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
	
	if (isMultiThreads){
		pthread_mutex_unlock(&lockCommDup);
	}

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
	int		      *pesGroupPtr;
	MPID_Group    *groupPtr;
	void          *sharedBuffer;
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}

	if (isMultiThreads){
		pthread_mutex_lock(&lockCommFree);
	}
	
	// Start freeing the various parts of a comm.
	groupPtr     = (MPID_Group *)(((MPID_Comm)*comm).groupPtr);
	pesGroupPtr  = ((MPID_Group)*groupPtr).pesInGroup;
	sharedBuffer = (void *)((MPID_Comm)*comm).bufferPtr;
	
	shfree(pesGroupPtr);
	shfree(groupPtr);
	shfree(sharedBuffer);
		
	if (isMultiThreads){
		pthread_mutex_unlock(&lockCommFree);
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
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
	
	if (((MPID_Comm)*comm).groupPtr == NULL){
		int my_pe = shmem_my_pe();
		mlog(MPI_ERR, "MPI_Comm_rank, my_pe: %-8d, comm.groupPtr is NULL.\n",  my_pe);
		return MPI_ERR_COMM;
	}
	
	*rank = ((MPID_Group)*((MPID_Comm)*comm).groupPtr).rank;
	
#ifdef DEBUG
	int my_pe = shmem_my_pe();
	mlog(MPI_DBG, "MPI_Comm_rank, my_pe: %-8d rank: %d\n",  my_pe, *rank);
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
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
			
	if (((MPID_Comm)*comm).groupPtr == NULL){
		int my_pe = shmem_my_pe();
		mlog(MPI_ERR, "MPI_Comm_size, my_pe: %-8d, comm.groupPtr is NULL.\n",  my_pe);
		return MPI_ERR_COMM;
	}
	
	*size = ((MPID_Group)*((MPID_Comm)*comm).groupPtr).size;
	
#ifdef DEBUG
	int my_pe = shmem_my_pe();
	mlog(MPI_DBG, "MPI_Comm_size, my_pe: %-8d size: %d\n", my_pe, *size);
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
	int  i;
	int  numPes, my_pe;
	int  numBytes;
	int  createSymSend, createSymRecv;
	void *symSend, *symRecv;
	void *recvBufIndex;
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}

	if (isMultiThreads){
		pthread_mutex_lock(&lockAllGather);
	}
	
	numPes = _num_pes();
	my_pe = shmem_my_pe();
	
	createSymSend = FALSE;
	createSymRecv = FALSE;
	recvBufIndex  = NULL;
	
	// Verify that you have valid buffer pointer and space:
	if ( (recvbuf == NULL) || (sendbuf == NULL) ){
		mlog(MPI_ERR, "Error: buffer has an invalid pointer (it's NULL) PE: %d\n", my_pe);
		if (isMultiThreads){
			pthread_mutex_unlock(&lockAllGather);
		}
		return MPI_ERR_BUFFER;
	}
	
	// Check the send buffer, use work around if not symmetric
	if ( !shmem_addr_accessible( sendbuf, my_pe) ) {
		//printf("MPI_Allgather::Buffer is not in a symmetric segment, pe: %d\n", my_pe);
		mlog(MPI_DBG, "DEBUG: Send Buffer is not in a symmetric segment, %d\n", my_pe);

		symSend = ((void*)((MPID_Comm)*comm).bufferPtr);
		
		// Move user's source into the symmetric buffer, since they can't create one.
		CopyMyData( symSend, sendbuf, sendcount, sendtype);
		
#ifdef DEBUG
		/**for (i=0; i<sendcount; i++){
		 printf("MPI_Allgather: rank: %d symSend: %ld, sendcount: %d\n", my_pe, ((long*)symSend)[i], sendcount);
		 }**/
#endif
		// Make the destination start at an offset:
		numBytes = 0;
		recvBufIndex = GetBufferOffset( sendcount, &numBytes, sendtype, comm );
		
		createSymSend = TRUE;
	}
	
	if ( !shmem_addr_accessible( recvbuf, my_pe) ) {
		//printf("MPI_Allgather::Buffer is not in a symmetric segment, pe: %d\n", my_pe);
		mlog(MPI_DBG, "DEBUG: Buffer is not in a symmetric segment, %d\n", my_pe);
		
		if ( recvBufIndex != NULL ){
			symRecv = recvBufIndex;
		}else {
			symRecv = ((void*)((MPID_Comm)*comm).bufferPtr);
		}
				
#ifdef DEBUG
		/**for (i=0; i<recvcount; i++){
		 printf("MPI_Allgather: rank: %d symRecv: %ld\n", my_pe, ((long*)symRecv)[i]);
		 }**/
#endif		
		createSymRecv = TRUE;
	}
	
	// Do what opneshmem needs to do:
	for (i = 0; i < _SHMEM_BCAST_SYNC_SIZE; i += 1){
		pSync[i] = _SHMEM_SYNC_VALUE;
    }
	
	shmem_barrier_all ();
	
	if ( !createSymSend && !createSymRecv ){
		shmem_fcollect64(recvbuf, sendbuf, sendcount, 0, 0, numPes, pSync);
	}
	else if ( !createSymSend && createSymRecv ){
		shmem_fcollect64(symRecv, sendbuf, sendcount, 0, 0, numPes, pSync);
	}
	else if ( createSymSend && !createSymRecv ){
		shmem_fcollect64(recvbuf, symSend, sendcount, 0, 0, numPes, pSync);
	}
	else if ( createSymSend && createSymRecv ){
		shmem_fcollect64(symRecv, symSend, sendcount, 0, 0, numPes, pSync);
	}
	
	shmem_barrier_all();
	

	// if receive symmetric buffer was not created, there's nothing to transfer. The data is there...
	if (createSymRecv){ 
		CopyMyData(recvbuf, symRecv, sendcount*numPes, recvtype);
	}
	
	if (isMultiThreads){
		pthread_mutex_unlock(&lockAllGather);
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
	int  numBytes;
	int  createSymSend, createSymRecv;
	void *symSend, *symRecv;
	void *recvBufIndex;
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
		
	if (isMultiThreads){
		pthread_mutex_lock(&lockGather);
	}

	createSymSend = FALSE;
	createSymRecv = FALSE;
	recvBufIndex  = NULL;
	
	numPes = _num_pes();
	my_pe = shmem_my_pe();

	// Verify that you have valid buffer pointer and space:
	if ( (recvbuf == NULL) || (sendbuf == NULL) ){
		mlog(MPI_ERR, "Error: buffer has an invalid pointer (it's NULL) PE: %d\n", my_pe);
		if (isMultiThreads){
			pthread_mutex_unlock(&lockGather);
		}
		return MPI_ERR_BUFFER;
	}
		
	// Check the send buffer, use work around if not symmetric
	if ( !shmem_addr_accessible( sendbuf, my_pe) ) {
		//printf("MPI_Gather::Buffer is not in a symmetric segment, pe: %d\n", my_pe);
		mlog(MPI_DBG, "DEBUG: Send Buffer is not in a symmetric segment, %d\n", my_pe);
		
		symSend = ((void*)((MPID_Comm)*comm).bufferPtr);
		
		// Move user's source into the symmetric buffer, since they can't create one.
		CopyMyData( symSend, sendbuf, sendcount, sendtype);
		
#ifdef DEBUG
		/**for (i=0; i<sendcount; i++){
		 printf("MPI_Gather: rank: %d symSend: %ld, sendcount: %d\n", my_pe, ((long*)symSend)[i], sendcount);
		 }**/
#endif
		// Make the destination start at an offset:
		numBytes = 0;
		recvBufIndex = GetBufferOffset( sendcount, &numBytes, sendtype, comm );
		
		createSymSend = TRUE;
	}
	
	if ( !shmem_addr_accessible( recvbuf, my_pe) ) {
		//printf("MPI_Gather::Buffer is not in a symmetric segment, pe: %d\n", my_pe);
		mlog(MPI_DBG, "DEBUG: Buffer is not in a symmetric segment, %d\n", my_pe);
		
		if ( recvBufIndex != NULL ){
			symRecv = recvBufIndex;
		}else {
			symRecv = ((void*)((MPID_Comm)*comm).bufferPtr);
		}
		
		createSymRecv = TRUE;
	}
	
	
	shmem_barrier_all ();
	
	switch (sendtype){
		case MPI_CHAR:
		case MPI_UNSIGNED_CHAR:
		case MPI_BYTE:
			if ( !createSymSend && !createSymRecv ){
				shmem_putmem(&(((char*)recvbuf)[sendcount*my_pe]), sendbuf, sendcount, root);
			}
			else if ( !createSymSend && createSymRecv ){
				shmem_putmem(&(((char*)symRecv)[sendcount*my_pe]), sendbuf, sendcount, root);
			}
			else if ( createSymSend && !createSymRecv ){
				shmem_putmem(&(((char*)recvbuf)[sendcount*my_pe]), symSend, sendcount, root);
			}
			else if ( createSymSend && createSymRecv ){
				shmem_putmem(&(((char*)symRecv)[sendcount*my_pe]), symSend, sendcount, root);
			}
			break;
		case MPI_SHORT:
		case MPI_UNSIGNED_SHORT:
			if ( !createSymSend && !createSymRecv ){
				shmem_short_put(&(((short*)recvbuf)[sendcount*my_pe]), sendbuf, sendcount, root);
			}
			else if ( !createSymSend && createSymRecv ){
				shmem_short_put(&(((short*)symRecv)[sendcount*my_pe]), sendbuf, sendcount, root);
			}
			else if ( createSymSend && !createSymRecv ){
				shmem_short_put(&(((short*)recvbuf)[sendcount*my_pe]), symSend, sendcount, root);
			}
			else if ( createSymSend && createSymRecv ){
				shmem_short_put(&(((short*)symRecv)[sendcount*my_pe]), symSend, sendcount, root);
			}
			break;
		case MPI_INT:
		case MPI_UNSIGNED:
			if ( !createSymSend && !createSymRecv ){
				shmem_int_put(&(((int*)recvbuf)[sendcount*my_pe]), sendbuf, sendcount, root);
			}
			else if ( !createSymSend && createSymRecv ){
				shmem_int_put(&(((int*)symRecv)[sendcount*my_pe]), sendbuf, sendcount, root);
			}
			else if ( createSymSend && !createSymRecv ){
				shmem_int_put(&(((int*)recvbuf)[sendcount*my_pe]), symSend, sendcount, root);
			}
			else if ( createSymSend && createSymRecv ){
				shmem_int_put(&(((int*)symRecv)[sendcount*my_pe]), symSend, sendcount, root);
			}
			//printf ("Debug:  - from %d to recvbuf[%d] =", root, my_pe);
			//for (i = 0; i < 20; i += 1) {
			//	printf (" %d", ((int*)recvbuf)[i]);
			///}
			//printf ("\n");
			break;
		case MPI_LONG:
		case MPI_UNSIGNED_LONG:
			if ( !createSymSend && !createSymRecv ){
				shmem_long_put(&(((long*)recvbuf)[sendcount*my_pe]), sendbuf, sendcount, root);
			}
			else if ( !createSymSend && createSymRecv ){
				shmem_long_put(&(((long*)symRecv)[sendcount*my_pe]), sendbuf, sendcount, root);
			}
			else if ( createSymSend && !createSymRecv ){
				shmem_long_put(&(((long*)recvbuf)[sendcount*my_pe]), symSend, sendcount, root);
			}
			else if ( createSymSend && createSymRecv ){
				shmem_long_put(&(((long*)symRecv)[sendcount*my_pe]), symSend, sendcount, root);
			}
			break;
		case MPI_FLOAT:
			if ( !createSymSend && !createSymRecv ){
				shmem_float_put(&(((float*)recvbuf)[sendcount*my_pe]), sendbuf, sendcount, root);
			}
			else if ( !createSymSend && createSymRecv ){
				shmem_float_put(&(((float*)symRecv)[sendcount*my_pe]), sendbuf, sendcount, root);
			}
			else if ( createSymSend && !createSymRecv ){
				shmem_float_put(&(((float*)recvbuf)[sendcount*my_pe]), symSend, sendcount, root);
			}
			else if ( createSymSend && createSymRecv ){
				shmem_float_put(&(((float*)symRecv)[sendcount*my_pe]), symSend, sendcount, root);
			}
			break;
		case MPI_DOUBLE:
			if ( !createSymSend && !createSymRecv ){
				shmem_double_put(&(((double*)recvbuf)[sendcount*my_pe]), sendbuf, sendcount, root);
			}
			else if ( !createSymSend && createSymRecv ){
				shmem_double_put(&(((double*)symRecv)[sendcount*my_pe]), sendbuf, sendcount, root);
			}
			else if ( createSymSend && !createSymRecv ){
				shmem_double_put(&(((double*)recvbuf)[sendcount*my_pe]), symSend, sendcount, root);
			}
			else if ( createSymSend && createSymRecv ){
				shmem_double_put(&(((double*)symRecv)[sendcount*my_pe]), symSend, sendcount, root);
			}
			break;
		case MPI_LONG_DOUBLE:
			if ( !createSymSend && !createSymRecv ){
				shmem_longdouble_put(&(((long double*)recvbuf)[sendcount*my_pe]), sendbuf, sendcount, root);
			}
			else if ( !createSymSend && createSymRecv ){
				shmem_longdouble_put(&(((long double*)symRecv)[sendcount*my_pe]), sendbuf, sendcount, root);
			}
			else if ( createSymSend && !createSymRecv ){
				shmem_longdouble_put(&(((long double*)recvbuf)[sendcount*my_pe]), symSend, sendcount, root);
			}
			else if ( createSymSend && createSymRecv ){
				shmem_longdouble_put(&(((long double*)symRecv)[sendcount*my_pe]), symSend, sendcount, root);
			}
			break;
		case MPI_LONG_LONG:
			if ( !createSymSend && !createSymRecv ){
				shmem_longlong_put(&(((long long*)recvbuf)[sendcount*my_pe]), sendbuf, sendcount, root);
			}
			else if ( !createSymSend && createSymRecv ){
				shmem_longlong_put(&(((long long*)symRecv)[sendcount*my_pe]), sendbuf, sendcount, root);
			}
			else if ( createSymSend && !createSymRecv ){
				shmem_longlong_put(&(((long long*)recvbuf)[sendcount*my_pe]), symSend, sendcount, root);
			}
			else if ( createSymSend && createSymRecv ){
				shmem_longlong_put(&(((long long*)symRecv)[sendcount*my_pe]), symSend, sendcount, root);
			}
			break;
		default:
			if ( !createSymSend && !createSymRecv ){
				shmem_putmem(&(((char*)recvbuf)[sendcount*my_pe]), sendbuf, sendcount, root);
			}
			else if ( !createSymSend && createSymRecv ){
				shmem_putmem(&(((char*)symRecv)[sendcount*my_pe]), sendbuf, sendcount, root);
			}
			else if ( createSymSend && !createSymRecv ){
				shmem_putmem(&(((char*)recvbuf)[sendcount*my_pe]), symSend, sendcount, root);
			}
			else if ( createSymSend && createSymRecv ){
				shmem_putmem(&(((char*)symRecv)[sendcount*my_pe]), symSend, sendcount, root);
			}
			break;
	}
	
	// and to be on the safe side:
	shmem_barrier_all ();

	// if receive symmetric buffer was not created, there's nothing to transfer. The data is there...
	if ( (my_pe == root) && createSymRecv){ 
		CopyMyData(recvbuf, symRecv, sendcount*numPes, recvtype);
	}
	
	if (isMultiThreads){
		pthread_mutex_unlock(&lockGather);
	}

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

	int i;
	int numPes, my_pe;	
	int  numBytes;
	int  createSymSend, createSymRecv;
	void *symSend, *symRecv;
	void *recvBufIndex;
	int   totalNumSent;
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
	
	if (isMultiThreads){
		pthread_mutex_lock(&lockGatherV);
	}

	numPes = _num_pes();
	my_pe = shmem_my_pe();
	
	// Verify that you have valid buffer pointer and space:
	if ( (recvbuf == NULL) || (sendbuf == NULL) ){
		mlog(MPI_ERR, "Error: buffer has an invalid pointer (it's NULL) PE: %d\n", my_pe);
		if (isMultiThreads){
			pthread_mutex_unlock(&lockGatherV);
		}
		return MPI_ERR_BUFFER;
	}
		
	// Check the send buffer, use work around if not symmetric
	if ( !shmem_addr_accessible( sendbuf, my_pe) ) {
		//printf("MPI_Gatherv::Send Buffer is not in a symmetric segment, pe: %d\n", my_pe);
		mlog(MPI_DBG, "DEBUG: Send Buffer is not in a symmetric segment, %d\n", my_pe);
		
		symSend = ((void*)((MPID_Comm)*comm).bufferPtr);
		
		// Move user's source into the symmetric buffer, since they can't create one.
		CopyMyData( symSend, sendbuf, sendcount, sendtype);
		shmem_barrier_all ();
		
#ifdef DEBUG
		/**for (i=0; i<sendcount; i++){
			printf("MPI_Gatherv: rank: %d symSend: %ld, sendcount: %d\n", my_pe, ((int*)symSend)[i], sendcount);
		}**/
#endif
		// Make the destination start at an offset:
		numBytes = 0;
		recvBufIndex = GetBufferOffset( sendcount, &numBytes, sendtype, comm );
		
		createSymSend = TRUE;
	}
	
	// Figure out the total being sent to recv buffer:
	totalNumSent = 0;
	for (i=0; i<numPes; i++) {
		totalNumSent = displs[i] + totalNumSent ;
	}
	
	if ( !shmem_addr_accessible( recvbuf, my_pe) ) {
		//printf("MPI_Gatherv::Recv Buffer is not in a symmetric segment, pe: %d\n", my_pe);
		mlog(MPI_DBG, "DEBUG: Buffer is not in a symmetric segment, %d\n", my_pe);
		
		if ( recvBufIndex != NULL ){
			symRecv = recvBufIndex;
		}else {
			symRecv = ((void*)((MPID_Comm)*comm).bufferPtr);
		}
		
		// Move user's source into the symmetric buffer, since they can't create one.
		CopyMyData( symRecv, recvbuf, totalNumSent, recvtype);
		shmem_barrier_all ();
		
#ifdef DEBUG
		/**for (i=0; i<recvcount[my_pe]; i++){
			printf("MPI_Gatherv: rank: %d recvbuf: %ld, recvcount: %d, dataType = %d \n", my_pe, ((int*)recvbuf)[i], totalNumSent, recvtype);
		}**/
#endif
		
		createSymRecv = TRUE;
	}

	// Need to check the sendcount not larger than recvcount...
	if (sendcount < recvcount[my_pe]){
		mlog(MPI_ERR, "Error: send buffer is smaller than number of items requested, pe: %d\n", my_pe);
		if (isMultiThreads){
			pthread_mutex_unlock(&lockGatherV);
		}
		return MPI_ERR_SIZE;
	}

	shmem_barrier_all ();
	switch (sendtype){
		case MPI_CHAR:
		case MPI_UNSIGNED_CHAR:
		case MPI_BYTE:
			if ( !createSymSend && !createSymRecv ){
				shmem_putmem(&(((char*)recvbuf)[displs[my_pe]]), sendbuf, recvcount[my_pe], root);
			}
			else if ( !createSymSend && createSymRecv ){
				shmem_putmem(&(((char*)symRecv)[displs[my_pe]]), sendbuf, recvcount[my_pe], root);
			}
			else if ( createSymSend && !createSymRecv ){
				shmem_putmem(&(((char*)recvbuf)[displs[my_pe]]), symSend, recvcount[my_pe], root);
			}
			else if ( createSymSend && createSymRecv ){
				shmem_putmem(&(((char*)symRecv)[displs[my_pe]]), symSend, recvcount[my_pe], root);
			}
			break;
		case MPI_SHORT:
		case MPI_UNSIGNED_SHORT:
			if ( !createSymSend && !createSymRecv ){
				shmem_short_put(&(((short*)recvbuf)[displs[my_pe]]), sendbuf, recvcount[my_pe], root);
			}
			else if ( !createSymSend && createSymRecv ){
				shmem_short_put(&(((short*)symRecv)[displs[my_pe]]), sendbuf, recvcount[my_pe], root);
			}
			else if ( createSymSend && !createSymRecv ){
				shmem_short_put(&(((short*)recvbuf)[displs[my_pe]]), symSend, recvcount[my_pe], root);
			}
			else if ( createSymSend && createSymRecv ){
				shmem_short_put(&(((short*)symRecv)[displs[my_pe]]), symSend, recvcount[my_pe], root);
			}
			break;
		case MPI_INT:
		case MPI_UNSIGNED:
			if ( !createSymSend && !createSymRecv ){
				shmem_int_put(&(((int*)recvbuf)[displs[my_pe]]), sendbuf, recvcount[my_pe], root);
			}
			else if ( !createSymSend && createSymRecv ){
				shmem_int_put(&(((int*)symRecv)[displs[my_pe]]), sendbuf, recvcount[my_pe], root);
			}
			else if ( createSymSend && !createSymRecv ){
				shmem_int_put(&(((int*)recvbuf)[displs[my_pe]]), symSend, recvcount[my_pe], root);
			}
			else if ( createSymSend && createSymRecv ){
				shmem_int_put(&(((int*)symRecv)[displs[my_pe]]), symSend, recvcount[my_pe], root);
				/** debug **
				 if (my_pe == root){
				 printf ("gatherv - recvbuf[%d->%d] =", my_pe, root);
				 for (i = 0; i < 13; i++) {
				 printf (" %d", ((int *)symRecv)[i]);
				 }
				 printf ("\n");
				 }
				 **/
			}
			break;
		case MPI_LONG:
		case MPI_UNSIGNED_LONG:
			if ( !createSymSend && !createSymRecv ){
				shmem_long_put(&(((long*)recvbuf)[displs[my_pe]]), sendbuf, recvcount[my_pe], root);
			}
			else if ( !createSymSend && createSymRecv ){
				shmem_long_put(&(((long*)symRecv)[displs[my_pe]]), sendbuf, recvcount[my_pe], root);
			}
			else if ( createSymSend && !createSymRecv ){
				shmem_long_put(&(((long*)recvbuf)[displs[my_pe]]), symSend, recvcount[my_pe], root);
			}
			else if ( createSymSend && createSymRecv ){
				shmem_long_put(&(((long*)symRecv)[displs[my_pe]]), symSend, recvcount[my_pe], root);
			}
			break;
		case MPI_FLOAT:
			if ( !createSymSend && !createSymRecv ){
				shmem_float_put(&(((float*)recvbuf)[displs[my_pe]]), sendbuf, recvcount[my_pe], root);
			}
			else if ( !createSymSend && createSymRecv ){
				shmem_float_put(&(((float*)symRecv)[displs[my_pe]]), sendbuf, recvcount[my_pe], root);
			}
			else if ( createSymSend && !createSymRecv ){
				shmem_float_put(&(((float*)recvbuf)[displs[my_pe]]), symSend, recvcount[my_pe], root);
			}
			else if ( createSymSend && createSymRecv ){
				shmem_float_put(&(((float*)symRecv)[displs[my_pe]]), symSend, recvcount[my_pe], root);
			}
			break;
		case MPI_DOUBLE:
			if ( !createSymSend && !createSymRecv ){
				shmem_double_put(&(((double*)recvbuf)[displs[my_pe]]), sendbuf, recvcount[my_pe], root);
			}
			else if ( !createSymSend && createSymRecv ){
				shmem_double_put(&(((double*)symRecv)[displs[my_pe]]), sendbuf, recvcount[my_pe], root);
			}
			else if ( createSymSend && !createSymRecv ){
				shmem_double_put(&(((double*)recvbuf)[displs[my_pe]]), symSend, recvcount[my_pe], root);
			}
			else if ( createSymSend && createSymRecv ){
				shmem_double_put(&(((double*)symRecv)[displs[my_pe]]), symSend, recvcount[my_pe], root);
			}
			break;
		case MPI_LONG_DOUBLE:
			if ( !createSymSend && !createSymRecv ){
				shmem_longdouble_put(&(((long double*)recvbuf)[displs[my_pe]]), sendbuf, recvcount[my_pe], root);
			}
			else if ( !createSymSend && createSymRecv ){
				shmem_longdouble_put(&(((long double*)symRecv)[displs[my_pe]]), sendbuf, recvcount[my_pe], root);
			}
			else if ( createSymSend && !createSymRecv ){
				shmem_longdouble_put(&(((long double*)recvbuf)[displs[my_pe]]), symSend, recvcount[my_pe], root);
			}
			else if ( createSymSend && createSymRecv ){
				shmem_longdouble_put(&(((long double*)symRecv)[displs[my_pe]]), symSend, recvcount[my_pe], root);
			}
			break;
		case MPI_LONG_LONG:
			if ( !createSymSend && !createSymRecv ){
				shmem_longlong_put(&(((long long*)recvbuf)[displs[my_pe]]), sendbuf, recvcount[my_pe], root);
			}
			else if ( !createSymSend && createSymRecv ){
				shmem_longlong_put(&(((long long*)symRecv)[displs[my_pe]]), sendbuf, recvcount[my_pe], root);
			}
			else if ( createSymSend && !createSymRecv ){
				shmem_longlong_put(&(((long long*)recvbuf)[displs[my_pe]]), symSend, recvcount[my_pe], root);
			}
			else if ( createSymSend && createSymRecv ){
				shmem_longlong_put(&(((long long*)symRecv)[displs[my_pe]]), symSend, recvcount[my_pe], root);
			}
			break;
		default:
			if ( !createSymSend && !createSymRecv ){
				shmem_putmem(&(((char*)recvbuf)[displs[my_pe]]), sendbuf, recvcount[my_pe], root);
			}
			else if ( !createSymSend && createSymRecv ){
				shmem_putmem(&(((char*)symRecv)[displs[my_pe]]), sendbuf, recvcount[my_pe], root);
			}
			else if ( createSymSend && !createSymRecv ){
				shmem_putmem(&(((char*)recvbuf)[displs[my_pe]]), symSend, recvcount[my_pe], root);
			}
			else if ( createSymSend && createSymRecv ){
				shmem_putmem(&(((char*)symRecv)[displs[my_pe]]), symSend, recvcount[my_pe], root);
			}
			break;
	}
	
	// and to be on the safe side:
	shmem_fence ();
	shmem_barrier_all ();
	
	// if receive symmetric buffer was not created, there's nothing to transfer. The data is there...
	if ( (my_pe == root) && createSymRecv){ 

		CopyMyData(recvbuf, symRecv, totalNumSent, MPI_INT);
		
		/** debug **
		if (my_pe == root){
			printf ("MPI_Gatherv - recvbuf[%d->%d] =", my_pe, root);
			for (i = 0; i < count; i++) {
				printf (" %d", ((int *)symRecv)[i]);
				//((int *)recvbuf)[i] =  ((int *)symRecv)[i];
			}
			printf ("\n");
			for (i = 0; i < count; i++) {
				printf (" %d", ((int *)recvbuf)[i]);
			}
			printf ("\n");
		}
		**/
	}

	if (isMultiThreads){
		pthread_mutex_unlock(&lockGatherV);
	}

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

	if (isMultiThreads){
		pthread_mutex_lock(&lockGroupIncl);
	}

	my_pe = shmem_my_pe();
	
	pesGroupPtr = (int *)shmalloc(sizeof(int) * n);
	if (pesGroupPtr == NULL ){
		mlog(MPI_ERR, "MPI_Group_incl:: PE: %d, could not shmalloc space for MPI_Group's rank array.\n", my_pe);
		if (isMultiThreads){
			pthread_mutex_unlock(&lockGroupIncl);
		}
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
	
	if (isMultiThreads){
		pthread_mutex_unlock(&lockGroupIncl);
	}

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
	
	int  ret, i;
	void *recv_buf;
	int my_pe;
	int tagIndex;
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
	
	if (isMultiThreads){
		pthread_mutex_lock(&lockRecv);
	}
	
	my_pe = shmem_my_pe();
/*	recv_buf = ((MPID_Comm)*comm).bufferPtr; */
	
	// Check to see if data is there: find via tag...
	// Use SendInfo structure to send/recv:
	// This is the first code snippet, so set the index to 0...
	i = FALSE;
	tagIndex = 0;
	// Look for the buffer space 
	if ( comm->sendInfo[tagIndex].tag ==  tag ){
		printf("MPI_Recv: Tags match!");
		i = 1;
	}
	if ( comm->sendInfo[tagIndex].count ==  count ){
		printf("MPI_Recv: Tags match!");
		i = 100 + i;
	}
	if ( comm->sendInfo[tagIndex].datatype ==  datatype ){
		printf("MPI_Recv: datatype match!");
		i = 100 + i;
	}
	recv_buf = comm->sendInfo[tagIndex].bufPtr;
	printf("MPI_Recv: i = %d!", i);
	
	// Data is already there, we just need to find it.
	CopyMyData(buf, recv_buf, count, datatype);
	
	shmem_fence(); // I believe this is necessary...
	
	// Reset the symmetric space so it can be re-used:
	comm->sendInfo[tagIndex].tag = 0;
	comm->sendInfo[tagIndex].count = 0;
	comm->sendInfo[tagIndex].datatype = -1;
	comm->sendInfo[tagIndex].bufPtr = comm->bufferPtr;
	comm->sendInfo[tagIndex].afterBufAreaPtr = comm->bufferPtr;
	/*
	switch (datatype){
		case MPI_CHAR:
		case MPI_UNSIGNED_CHAR:
		case MPI_BYTE:
			shmem_getmem(buf, recv_buf, count, source);
			//if (my_pe == 1){
				printf("MPI_Recv: pe: %d from pe: %d, count: %d\n", my_pe, source, count);
				for (i=0;i<count;i++){
					printf("MPI_Recv: pe: %d buf[] = %c\n", my_pe, ((char*) buf)[i]);
					printf("MPI_Recv: pe: %d recv_buf[] = %c\n", my_pe, ((char*) recv_buf)[i]);
				}
			//}
			break;
		case MPI_SHORT:
		case MPI_UNSIGNED_SHORT:
		  shmem_short_get(buf, recv_buf, count, source);
		  break;
		case MPI_INT:
		case MPI_UNSIGNED:
		  shmem_int_get(buf, recv_buf, count, source);
			if (my_pe == 1){
				printf("MPI_Recv: pe: %d count: %d, source: %d\n", my_pe, count, source);
				int i;
				for (i=0;i<count/4;i++){
					printf("MPI_Recv: pe: %d buf[] = %d\n", my_pe, ((int*) buf)[i]);
					printf("MPI_Recv: pe: %d recv_buf[] = %d\n", my_pe, ((int*) recv_buf)[i]);
				}
			}
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
	*/
	if (isMultiThreads){
		pthread_mutex_unlock(&lockRecv);
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
	int   ret;
	int   my_pe;
	void  *recv_buf;
	void  *offset;
	int	  tagIndex;
	int   isItThereFlag;
	int   numBytes;
	int   expectedInt;
	long  expectedLong;
	long long expectedLongLong;
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
	
	if (isMultiThreads){
		pthread_mutex_lock(&lockSend);
	}
	
	my_pe = shmem_my_pe();
	/*recv_buf = ((MPID_Comm)*comm).bufferPtr;
	
	if (recv_buf == NULL){
		ret = MPI_ERR_BUFFER;// some sort of proper error here
		mlog(MPI_DBG, "Error: No symmetric memory for PE: %d\n", my_pe);
		if (isMultiThreads){
			pthread_mutex_unlock(&lockSend);
		}
		return ret;
	}*/
	
	// Use SendInfo structure to send/recv:
	// This is the first code snippet, so set the index to 0...
	comm->sendInfo[0].tag = tag;
	comm->sendInfo[0].datatype = datatype;
	comm->sendInfo[0].count = count;
	recv_buf = comm->sendInfo[0].bufPtr;
	
	//mlog(MPI_DBG,"MPI_Send: PE: %d, recv_buffer Addr = %x\n", my_pe, recv_buf);
		
	// To make sure data has been sent; set up the follwoing
	isItThereFlag = 0;
		
	switch (datatype){
		case MPI_CHAR:
		case MPI_UNSIGNED_CHAR:
		case MPI_BYTE:
			expectedInt = 12345;
			numBytes    = 0;
			
			shmem_putmem(recv_buf, buf, count, dest);
			
			// get the next buffer space:
			offset = GetBufferOffset(count, &numBytes, datatype, comm);
			shmem_int_put(offset, &expectedInt, 1, dest);
			shmem_fence(); // To guarentee order.

			// Wait until the values are sent:
			isItThereFlag = shmem_int_cswap(offset, expectedInt, expectedInt, dest);
			printf ("MPI_SEND: isItThereFlag: %d\n", isItThereFlag);
			
			while (isItThereFlag != expectedInt) {
				isItThereFlag = shmem_int_cswap(offset, expectedInt, expectedInt, dest);
				printf ("MPI_SEND: looped:: isItThereFlag: %d\n", isItThereFlag);
			}
			break;
			
		case MPI_SHORT:
		case MPI_UNSIGNED_SHORT:
			expectedInt = 23456;
			numBytes    = 0;
			
			shmem_short_put(recv_buf, buf, count, dest);

			// get the next buffer space:
			offset = GetBufferOffset(count, &numBytes, datatype, comm);
			shmem_int_put(offset, &expectedInt, 1, dest);
			shmem_fence(); // To guarentee order.
			
			// Wait until the values are sent:
			isItThereFlag = shmem_int_cswap(offset, expectedInt, expectedInt, dest);
			printf ("MPI_SEND: isItThereFlag: %d\n", isItThereFlag);
			
			while (isItThereFlag != expectedInt) {
				isItThereFlag = shmem_int_cswap(offset, expectedInt, expectedInt, dest);
				printf ("MPI_SEND: looped:: isItThereFlag: %d\n", isItThereFlag);
			}
			break;
			
		case MPI_INT:
		case MPI_UNSIGNED:
			expectedInt = ((int*)buf)[count-1];
			offset      = &(((int*)recv_buf)[count-1]);
			
			printf ("MPI_SEND: expecting: %d\n", expectedInt);

			shmem_int_put(recv_buf, buf, count, dest);

			// Wait until the values are sent:
			isItThereFlag = shmem_int_cswap(offset, expectedInt, expectedInt, dest);
			printf ("MPI_SEND: isItThereFlag: %d\n", isItThereFlag);
			
			while (isItThereFlag != expectedInt) {
				isItThereFlag = shmem_int_cswap(offset, expectedInt, expectedInt, dest);
				printf ("MPI_SEND: looped:: isItThereFlag: %d\n", isItThereFlag);
			}
			
			break;
			
		case MPI_LONG:
		case MPI_UNSIGNED_LONG:
			expectedLong = ((long*)buf)[count-1];
			offset       = &(((long*)recv_buf)[count-1]);

			shmem_long_put(recv_buf, buf, count, dest);
			
			// Wait until the values are sent:
			isItThereFlag = shmem_long_cswap(offset, expectedLong, expectedLong, dest);
			printf ("MPI_SEND: isItThereFlag: %d\n", isItThereFlag);
			
			while (isItThereFlag != expectedLong) {
				isItThereFlag = shmem_long_cswap(offset, expectedLong, expectedLong, dest);
				printf ("MPI_SEND: looped:: isItThereFlag: %d\n", isItThereFlag);
			}
			break;
			
		case MPI_FLOAT:
			expectedInt = 34567;
			numBytes    = 0;
			
			shmem_float_put(recv_buf, buf, count, dest);
			
			// get the next buffer space:
			offset = GetBufferOffset(count, &numBytes, datatype, comm);
			shmem_int_put(offset, &expectedInt, 1, dest);
			shmem_fence(); // To guarentee order.
			
			// Wait until the values are sent:
			isItThereFlag = shmem_int_cswap(offset, expectedInt, expectedInt, dest);
			printf ("MPI_SEND: isItThereFlag: %d\n", isItThereFlag);
			
			while (isItThereFlag != expectedInt) {
				isItThereFlag = shmem_int_cswap(offset, expectedInt, expectedInt, dest);
				printf ("MPI_SEND: looped:: isItThereFlag: %d\n", isItThereFlag);
			}
			break;
			
		case MPI_DOUBLE:
			expectedInt = 45678;
			numBytes    = 0;
			
			shmem_double_put(recv_buf, buf, count, dest);

			// get the next buffer space:
			offset = GetBufferOffset(count, &numBytes, datatype, comm);
			shmem_int_put(offset, &expectedInt, 1, dest);
			shmem_fence(); // To guarentee order.
			
			// Wait until the values are sent:
			isItThereFlag = shmem_int_cswap(offset, expectedInt, expectedInt, dest);
			printf ("MPI_SEND: isItThereFlag: %d\n", isItThereFlag);
			
			while (isItThereFlag != expectedInt) {
				isItThereFlag = shmem_int_cswap(offset, expectedInt, expectedInt, dest);
				printf ("MPI_SEND: looped:: isItThereFlag: %d\n", isItThereFlag);
			}
			break;
			
		case MPI_LONG_DOUBLE:
			expectedInt = 56789;
			numBytes    = 0;
			
			shmem_longdouble_put(recv_buf, buf, count, dest);

			// get the next buffer space:
			offset = GetBufferOffset(count, &numBytes, datatype, comm);
			shmem_int_put(offset, &expectedInt, 1, dest);
			shmem_fence(); // To guarentee order.
			
			// Wait until the values are sent:
			isItThereFlag = shmem_int_cswap(offset, expectedInt, expectedInt, dest);
			printf ("MPI_SEND: isItThereFlag: %d\n", isItThereFlag);
			
			while (isItThereFlag != expectedInt) {
				isItThereFlag = shmem_int_cswap(offset, expectedInt, expectedInt, dest);
				printf ("MPI_SEND: looped:: isItThereFlag: %d\n", isItThereFlag);
			}
			break;
			
		case MPI_LONG_LONG:
			expectedLongLong = ((long long*)buf)[count-1];
			offset           = &(((long long*)recv_buf)[count-1]);
			
			shmem_longlong_put(recv_buf, buf, count, dest);
			
			// Wait until the values are sent:
			isItThereFlag = shmem_longlong_cswap(offset, expectedLongLong, expectedLongLong, dest);
			printf ("MPI_SEND: isItThereFlag: %d\n", isItThereFlag);
			
			while (isItThereFlag != expectedLongLong) {
				isItThereFlag = shmem_longlong_cswap(offset, expectedLongLong, expectedLongLong, dest);
				printf ("MPI_SEND: looped:: isItThereFlag: %d\n", isItThereFlag);
			}
			break;
			
		default:
			/* DEBUG *
			 if (my_pe == 1) {
			 printf("MPI_Send: pe: %d count: %d\n", my_pe, count);
			 int i;
			 for (i=0;i<count;i++){
			 printf("MPI_Send: pe: %d buf[] = %d\n", my_pe, ((char*) buf)[i]);
			 }
			 }**/
			expectedInt = 67890;
			numBytes    = 0;
			
			shmem_putmem(recv_buf, buf, count, dest);
			
			// get the next buffer space:
			offset = GetBufferOffset(count, &numBytes, datatype, comm);
			shmem_int_put(offset, &expectedInt, 1, dest);
			shmem_fence(); // To guarentee order.
			
			// Wait until the values are sent:
			isItThereFlag = shmem_int_cswap(offset, expectedInt, expectedInt, dest);
			printf ("MPI_SEND: isItThereFlag: %d\n", isItThereFlag);
			
			while (isItThereFlag != expectedInt) {
				isItThereFlag = shmem_int_cswap(offset, expectedInt, expectedInt, dest);
				printf ("MPI_SEND: looped:: isItThereFlag: %d\n", isItThereFlag);
			}
			break;
	}
		
	if (isMultiThreads){
		pthread_mutex_unlock(&lockSend);
	}
	
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
	int my_pe;
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
		
	if (isMultiThreads){
		pthread_mutex_lock(&lockIRecv);
	}

	my_pe = shmem_my_pe();
	recv_buf = ((MPID_Comm)*comm).bufferPtr;
	
	if (recv_buf == NULL){
		ret = MPI_ERR_BUFFER;// some sort of proper error here
		mlog(MPI_DBG, "Error: No symmetric memory for PE: %d\n", my_pe);
		if (isMultiThreads){
			pthread_mutex_unlock(&lockIRecv);
		}
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
			printf("shmem_long_get: count %d, source: %d\n", count, source);
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
	(*request).requestType = IRECV;
	(*request).rank		= source;
	(*request).dataType	= datatype;
	
	//printf("Irecv: PE: %d, From PE: %d, got: ? \n", my_pe, (*request).rank );
	
	if (isMultiThreads){
		pthread_mutex_unlock(&lockIRecv);
	}
	
	return ret;
} // Irecv

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
	
	int   my_pe;
	int	  numBytes;
	void *symRecvBuf;
	void *recvBufIndex;
	void *symSendBuf;
	void *symBufIndex;
	int   createSymSend;
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}

	if (isMultiThreads){
		pthread_mutex_lock(&lockISend);
	}
	
	my_pe = shmem_my_pe();
	symRecvBuf     = ((MPID_Comm)*comm).bufferPtr;
	recvBufIndex = GetBufferOffset( count, &numBytes, datatype, comm );

	if (symRecvBuf == NULL){
		mlog(MPI_DBG, "Error: No symmetric memory for PE: %d\n", my_pe);
		if (isMultiThreads){
			pthread_mutex_unlock(&lockISend);
		}
		return MPI_ERR_BUFFER;
	}
	
	mlog(MPI_DBG,"MPI_Isend: PE: %d, symRecvBuf Addr = %x\n", my_pe, symRecvBuf);
	
	// Check the send buffer, use work around if not symmetric
	createSymSend = FALSE;
	
	if ( !shmem_addr_accessible( buf, my_pe) ) {
		//printf("MPI_Isend::Buffer is not in a symmetric segment, pe: %d\n", my_pe);
		mlog(MPI_DBG, "DEBUG: Buffer is not in a symmetric segment, %d\n", my_pe);
		
		symSendBuf = recvBufIndex;

		// Move user's source into the symmetric buffer, since they can't create one.
		CopyMyData( symSendBuf, buf, count, datatype);
		
#ifdef DEBUG
		/**
		 int i;
		 for (i=0; i<count; i++){
		 printf("MPI_Isend: rank: %d symBuf: %ld, count: %d\n", my_pe, ((long*)symSendBuf)[i], count);
		 }**/
#endif
		// Make the destination start at an offset:
		numBytes = 0;
		symBufIndex = GetBufferOffset( count, &numBytes, datatype, comm );
		
		createSymSend = TRUE;
	}

	// In Request, put the expected last value:
	(*request).expected   = shmalloc( sizeof(int) );                             
	((int *)((*request).expected))[0] = ((int *)buf)[count-1];         

	switch (datatype){
		case MPI_CHAR:
		case MPI_UNSIGNED_CHAR:
		case MPI_BYTE:
			if (createSymSend){
				shmem_putmem(symRecvBuf, symSendBuf, count, dest);
			}
			else {
				shmem_putmem(symRecvBuf, buf, count, dest);
			}
			break;
		case MPI_SHORT:
		case MPI_UNSIGNED_SHORT:
			if (createSymSend){
				shmem_short_put(symRecvBuf, symSendBuf, count, dest);
			}
			else {
				shmem_short_put(symRecvBuf, buf, count, dest);
			}
			break;
		case MPI_INT:
		case MPI_UNSIGNED:
			if (createSymSend){
				shmem_int_put(symRecvBuf, symSendBuf, count, dest);
			}
			else {
				shmem_int_put(symRecvBuf, buf, count, dest);
			}
			break;
		case MPI_LONG:
		case MPI_UNSIGNED_LONG:
			if (createSymSend){
				shmem_long_put(symRecvBuf, symSendBuf, count, dest);
			}
			else {
				shmem_long_put(symRecvBuf, buf, count, dest);
			}
			break;
		case MPI_FLOAT:
			if (createSymSend){
				shmem_float_put(symRecvBuf, symSendBuf, count, dest);
			}
			else {
				shmem_float_put(symRecvBuf, buf, count, dest);
			}
			break;
		case MPI_DOUBLE:
			if (createSymSend){
				shmem_double_put(symRecvBuf, symSendBuf, count, dest);
			}
			else {
				shmem_double_put(symRecvBuf, buf, count, dest);
			}
			break;
		case MPI_LONG_DOUBLE:
			if (createSymSend){
				shmem_longdouble_put(symRecvBuf, symSendBuf, count, dest);
			}
			else {
				shmem_longdouble_put(symRecvBuf, buf, count, dest);
			}
			break;
		case MPI_LONG_LONG:
			if (createSymSend){
				shmem_longlong_put(symRecvBuf, symSendBuf, count, dest);
			}
			else {
				shmem_longlong_put(symRecvBuf, buf, count, dest);
			}
			break;
		default:
			if (createSymSend){
				shmem_putmem(symRecvBuf, symSendBuf, count, dest);
			}
			else {
				shmem_putmem(symRecvBuf, buf, count, dest);
			}
			break;
	}
	
	// Get the address (this is of the current PE)
	(*request).lastBufPtr   = &((int *)symRecvBuf)[count-1];

	// Set-up MPI_Request for MPI_Isend                                                                        
	(*request).requestType = ISEND;
	(*request).rank		   = dest;
	(*request).dataType	   = datatype;
	
	// This routine needs to relinquish synSendBuf

	//printf("MPI_Isend: PE: %d to PE: %d, sent: %d\n", my_pe, (*request).rank, ( (int *)(buf))[0] );
	if (isMultiThreads){
		pthread_mutex_unlock(&lockISend);
	}

	return MPI_SUCCESS;
}// Isend

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
	int totalNumBytes;
	int my_pe;
	int rank;
	int createSymInbuf;
	void *symInbuf;
	int  numSymBytes;
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
	
	if (isMultiThreads){
		pthread_mutex_lock(&lockUnpack);
	}

	totalNumBytes = 0;
	numSymBytes   = 0;
	my_pe         = shmem_my_pe();
	
	MPI_Comm_rank(comm, &rank);

	createSymInbuf = FALSE;
	if ( !shmem_addr_accessible( inbuf, my_pe) ) {
		//printf("MPI_Unpack::Buffer is not in a symmetric segment, pe: %d\n", my_pe);
		mlog(MPI_DBG, "DEBUG: Buffer is not in a symmetric segment, %d\n", my_pe);
		
		symInbuf = ((MPID_Comm)*comm).bufferPtr;
		
		// Move user's source into the symmetric buffer, since they can't create one.
		CopyMyData( symInbuf, inbuf, outcount, datatype);
		
#ifdef DEBUG
		/**
		 int i;
		 for (i=0; i<insize; i++){
		 printf("MPI_Unpack: rank: %d symOutBuf: %d, insize: %d\n", my_pe, ((int*)symInbuf)[i], insize);
		 }**/
#endif
		
		createSymInbuf = TRUE;
	}
	
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
	mlog(MPI_DBG,"MPI_Unpack, PE: %d, Number of bytes: %d, position: %d \n", my_pe, numBytes, *position);
	mlog(MPI_DBG,"MPI_Unpack, PE: %d, inbuf: %c, outbuf: %c \n", rank, ((char *)inbuf)[*position], ((char *)outbuf)[0]);
	
	// Check to see if there is enough space for the send:
	totalNumBytes = numBytes + *position;
	if (totalNumBytes > insize) {
		mlog(MPI_DBG,"MPI_Unpack:: PE: %d total bytes is larger (%d) than buffer size (%d).\n", my_pe, totalNumBytes, insize);
		if (isMultiThreads){
			pthread_mutex_unlock(&lockUnpack);
		}
		return MPI_ERR_NO_SPACE;
	}
	
	// Send inbuf to outbuf with an offset of position: 
	//shmem_getmem(buf, recv_buf, count, source);
	
	if (createSymInbuf){
		shmem_getmem( outbuf, &(((char *)symInbuf)[*position]), numBytes, rank);
	}
	else {
		shmem_getmem( outbuf, &(((char *)inbuf)[*position]), numBytes, rank);
	}
	
	// Don't forget to increment the position, and fix the comm's pointers..
	*position = *position + numBytes;
	
	if (isMultiThreads){
		pthread_mutex_unlock(&lockUnpack);
	}
	
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
	int totalNumBytes;
	int my_pe;
	int rank;
	void *symOutbuf;
	int createSymOutbuf;
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
		
	if (isMultiThreads){
		pthread_mutex_lock(&lockPack);
	}
	
	totalNumBytes = 0;
	my_pe         = shmem_my_pe();
	
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
	
	mlog(MPI_DBG,"MPI_Pack, PE: %d, Number of bytes: %d, position: %d \n", my_pe, numBytes, *position);
	mlog(MPI_DBG,"MPI_Pack, PE: %d, inbuf: %c, outbuf: %c \n", rank, ((char *)inbuf)[*position], ((char *)outbuf)[0]);

	/** Debug 
	 if (my_pe == 1) {
		printf("MPI_PACK, PE: %d, numBytes: %d, position: %d \n", my_pe, numBytes, *position);
		printf("MPI_Pack, PE: %d, inbuf: %d, outbuf: %c \n", rank, ((int *)inbuf)[*position], ((char *)outbuf)[0]);
	}**/

	// Check to see if there is enough space for the send:
	totalNumBytes = numBytes + *position;
	if (totalNumBytes > outsize) {
		mlog(MPI_ERR,"MPI_Pack::, pe: %d total bytes is larger (%d) than buffer size (%d).\n", my_pe, totalNumBytes, outsize);
		//printf("MPI_Pack::, pe: %d total bytes is larger (%d) than buffer size (%d).\n", my_pe, totalNumBytes, outsize);
		if (isMultiThreads){
			pthread_mutex_unlock(&lockPack);
		}
		return MPI_ERR_NO_SPACE;
	}
	
	// Check the send buffer, use work around if not symmetric
	createSymOutbuf = FALSE;
	if ( !shmem_addr_accessible( outbuf, my_pe) ) {
		//printf("MPI_Pack::Out Buffer is not in a symmetric segment, pe: %d\n", my_pe);
		mlog(MPI_DBG, "DEBUG: Out Buffer is not in a symmetric segment, %d\n", my_pe);
		
		symOutbuf = ((void*)((MPID_Comm)*comm).bufferPtr);
		
		createSymOutbuf = TRUE;
	}
		
	// Send inbuf to outbuf with an offset of position:
	if (createSymOutbuf){
		shmem_putmem( &(((char *)symOutbuf)[*position]), inbuf, numBytes, rank);
	}
	else {
		shmem_putmem( &(((char *)outbuf)[*position]), inbuf, numBytes, rank);
	}

	// and to be on the safe side:
	shmem_fence();

	/* DEBUG **
	if (my_pe == 1){
	    int i;
		for (i=0;i<numBytes;i++){
			printf("MPI_Pack: pe: %d inbuf[]: %c, %d\n", my_pe, ((char*)inbuf)[i], ((int*)inbuf)[i]);
		}
		if (createSymOutbuf){
			for (i=0;i<numBytes;i++){
				printf("MPI_Pack: pe: %d symOutbuf[]: %c\n", my_pe, ((char*)symOutbuf)[i]);
			}
		}
		else {
			for (i=0;i<numBytes;i++){
				printf("MPI_Pack: pe: %d outbuf[]: %c\n", my_pe, ((char*)outbuf)[i]);
			}
		}
		
	}**/
	
	// Don't forget to increment the position
	*position = *position + numBytes;
	
	// If using local symmetric memory, move the results to the user's buffer
	if (createSymOutbuf) {
		CopyMyData(outbuf, symOutbuf, numBytes, MPI_CHAR);
	}

	if (isMultiThreads){
		pthread_mutex_unlock(&lockPack);
	}

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
	int value;

	if (isMultiThreads){
		pthread_mutex_lock(&lockTest);
	}

	value = 0;
	
	// Asssume transfer not there:                                                                   
	*flag = 0;
	
	value = shmem_int_cswap( (*request).lastBufPtr, ((int *)((*request).expected))[0], ((int *)((*request).expected))[0], (*request).rank);
	
	if (value == ((int *)((*request).expected))[0] ){
		*flag = 1;
	}
	//mlog(MPI_DBG,"MPI_Test, flag: %d For Pe: %d, value = %d", *flag, (*request).rank, value);
	//mlog(MPI_DBG," lastBufPtr = %d, expected: %d\n",( (int *)((*request).lastBufPtr))[0], ( (int *)((*request).expected))[0] );
	
	if (isMultiThreads){
		pthread_mutex_unlock(&lockTest);
	}
	
	return MPI_SUCCESS;
}

/**
 * MPI_Iprobe
 * This was created for pftool, and this routine should not be used.
 * There is no way to tell if a put/get is finished in openshmem.
 * This relies on a sleep, which is very inaccurate.
 *
 * @param source	source rank
 * @param tag		tag value
 * @param comm		communicator
 * @param flag		True if a message with the specified source, tag, and communicator and available (not reliable)
 * @param status	status object (not used).
 *
 * @return MPI_SUCCESS
 */
int MPI_Iprobe(int source, int tag, MPI_Comm comm, int *flag, MPI_Status *status){

	int rank;
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
	
	if (isMultiThreads){
		pthread_mutex_lock(&lockIprobe);
	}
	
	MPI_Comm_rank(comm, &rank);
	
	//if (source == rank){
		shmem_fence();
		shmem_barrier_all();
		
		*flag = 1;
	//}
	
	sleep(40);
	
	if (isMultiThreads){
		pthread_mutex_unlock(&lockIprobe);
	}

	return MPI_SUCCESS;
	
}
