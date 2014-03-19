/*
 *
 *  
 */
#include <stdio.h>
#include <stdlib.h>
#include "mpi_to_openshmem.h"
#include "hashUtils.h"

struct MPID_Hash *bufHash = NULL;

#define BUF_SIZE 10

#define GOOD 1
#define BAD  0

MPI_Comm myComm;

int Local_MPI_Init_thread( int *argc, char ***argv, int required, int *provided ){
	int     ret = MPI_SUCCESS;
	struct MPID_Hash *bufHashTbl = NULL;
	
	start_pes(0);
	
	int npes =  _num_pes ();
	int my_pe = shmem_my_pe();
	
	// Make space for the initial MPI_COMM_WORLD
	myComm = (MPID_Comm *)shmalloc( sizeof(MPID_Comm) );
	if (myComm == NULL ){
		return MPI_ERR_NO_MEM;
	}
	
	// Add in a pointer to the hash:
	((MPID_Comm) *myComm).hashPtr = bufHashTbl;
	
	*provided = MPI_THREAD_MULTIPLE;
	
	return ret;
	
}

int AddComplexity(int count, long **bufPtr) {
	
	int results = BAD;
	
	shmem_barrier_all(); // This needs to be here...
	*bufPtr = (long*)shmalloc(sizeof(long) * count);
	
	if (*bufPtr != NULL ) results = GOOD;
	
	return results;
}

void putData (long **buf, long *src, int count, int dest){
	
	shmem_long_put(*buf, src, count, dest);
	
	// This needs to be here...: 
	shmem_fence();
	
}

int AddBufEntry(int tag, int count,  MPI_Datatype datatype, int srcRank, 
				int destRank, requestType_t requestType, void **bufPtr, 
				MPI_Comm comm) {
	
	int results = BAD;
	int createHash;
	int my_pe;
	int numBytes;
	
	struct MPID_Hash *newEntry;
	
	struct MPID_Hash *bufHashTbl = comm->hashPtr;
	//printf ("AddBufEntry: bufHashTbl: %x, \n",  bufHashTbl);
	//printf("\tcomm->hashPtr: %x,\n",comm->hashPtr);
	//printf("\t bufHash: %x \n", bufHash);
	
	HASH_FIND_INT(bufHashTbl, &tag, newEntry);  /* id already in the hash? */
	printf ("AddBufEntry:: HASH_FIND_IT, newEntry: %x\n", newEntry);
	
	if (newEntry==NULL) {
		shmem_barrier_all();  // This needs to be here...
		newEntry = (struct MPID_Hash*)shmalloc(sizeof(struct MPID_Hash));
		shmem_fence();
		newEntry->id = tag;
		printf("CreateEntry: Creating an entry, tag: %d\n", tag);
		HASH_ADD_INT( bufHashTbl, id, newEntry );  /* id: name of key field */
	}
	
	// Re-set the ptr to the hash table
	comm->hashPtr = bufHashTbl;
	
	// Fill in some data:
	newEntry->tag         = tag;
	newEntry->count       = count;
	newEntry->datatype    = datatype;
	newEntry->srcRank     = srcRank;
	newEntry->destRank    = destRank;
	newEntry->requestType = requestType;
	newEntry->isGrabbed   = FALSE;
	newEntry->time        = time(NULL);
	
	// Place where the buffer data is actually going:
	numBytes = GetNumBytes(count, datatype);
	shmem_barrier_all(); // This needs to be here...
	*bufPtr = (void*)shmalloc(numBytes);
	newEntry->bufPtr = *bufPtr;
	
	if (*bufPtr != NULL ) results = GOOD;
	
	return results;
}

void FindIdInHash ( int tag, void **bufPtr, MPI_Comm comm ){
	struct MPID_Hash *getEntry;
	
	struct MPID_Hash *bufHashTbl = comm->hashPtr;
	
	HASH_FIND_INT( bufHashTbl, &tag, getEntry);
	printf("FindBuffPtr: Tag is %d\n", tag);
	
	if (getEntry == NULL) printf("Could not find entry\n");
	else{
		int myTag = getEntry->tag;
		printf("Tag is %d, requestType: %d, Time: %d\n", myTag,getEntry->requestType, getEntry->time);
		*bufPtr = getEntry->bufPtr; 
	}
}//FindIdInHash

int GetBufPtrFromHash ( int tag, long count, requestType_t requestType, MPI_Datatype datatype, void **bufPtr, MPI_Comm comm ){
	int results = MPI_SUCCESS;
	struct MPID_Hash *getEntry;
	
	struct MPID_Hash *bufHashTbl = comm->hashPtr;
	
	HASH_FIND_INT( bufHashTbl, &tag, getEntry);
	printf("FindBuffPtr: Tag is %d\n", tag);
	
	if (getEntry == NULL){
		printf("Could not find entry\n");
		results =  9; // HASH_ID_NOT_FOUND;
	}
	else{
		int myTag = getEntry->tag;
		printf("Tag is %d, requestType: %d, Time: %d\n", myTag,getEntry->requestType, getEntry->time);
		
		// Verify it's the iytem you are looking for
		if ( count != getEntry->count ){
			results = 10; // HASH_MISMATCHED_COUNT;
		}
		else if ( requestType != getEntry->requestType ){
			results = 11; // HASH_MISMATCHED_REQUEST_TYPE; 
		}
		else if ( datatype != getEntry->datatype ){
			results = 12; // HASH_MISMATCHED_DATATYPE
		}
	}
    
	if (results == MPI_SUCCESS)
		*bufPtr = getEntry->bufPtr;
	
	return results;
    
}//GetBufPtrFromHash                                                                     

int DeleteEntry( int tag, long count, requestType_t requestType, MPI_Datatype datatype, void **bufPtr, MPI_Comm comm ){
	struct MPID_Hash *getEntry;
	int               results;
	
	struct MPID_Hash *bufHashTbl = comm->hashPtr;
	results = MPI_SUCCESS;
	
	HASH_FIND_INT( bufHashTbl, &tag, getEntry);
	printf("DeleteHashEntry:: Tag is %d\n", tag);
	
	if (getEntry == NULL){
		printf("DeleteHashEntry:: Could not find entry\n");
		mlog(MPI_DBG, "Didn't find entry id: %d for PE: %d\n", tag, comm->rank);
		results =  MPI_SUCCESS;;                                                                     
	}
	else{
		int myTag = getEntry->tag;
		printf("DeleteHashEntry:: Tag is %d, requestType: %d, Time: %d\n", myTag,getEntry->requestType, getEntry->time);
		
		// Verify it's the item you are looking for                                                            
		if ( count != getEntry->count ){
			mlog(MPI_ERR, "Error: Mismatched value expected count: %d, hash->count: %d for PE: %d\n", count, getEntry->count, comm->rank);
			results = HASH_ERR_MISMATCHED_COUNT;                                                               
		}
		else if ( requestType != getEntry->requestType ){
			mlog(MPI_ERR, "Error: Mismatched value expected requestType: %d, hash->requestType: %d for PE: %d\n", requestType, getEntry->datatype, comm->rank);
			results = HASH_ERR_MISMATCHED_REQUEST_TYPE;                                                        
		}
		else if ( datatype != getEntry->datatype ){
			mlog(MPI_ERR, "Error: Mismatched value expected datatype: %d, hash->datatype: %d for PE: %d\n", datatype, getEntry->datatype, comm->rank);
			results = HASH_ERR_MISMATCHED_DATATYPE;                                                            
		}
		
		if (results == MPI_SUCCESS){
			
			// Grab the buffer pointer to free that space.
			void *bufPtr;
			bufPtr = getEntry->bufPtr;
			
			HASH_DEL( bufHashTbl, getEntry);
			
			shmem_barrier_all(); // This has to be here... 
			shfree( bufPtr );
			shfree( getEntry );
			
		}
	}
}// DeleteEntry

int main(int argc, char *argv[])
{
	int i, size, my_pe;
	int nextpe, provided;
	int didFail = GOOD;
	int useHash = BAD;
	long src[BUF_SIZE];
	long *buf = NULL;
	
	int ret = MPI_Init_thread(&argc, &argv, MPI_THREAD_MULTIPLE, &provided);
	if (ret != MPI_SUCCESS) {
		printf("Error initializing MPI with threads\n");
		exit(1);
	}
	
	size =  _num_pes ();
	my_pe = shmem_my_pe();
	
	// Set up for creating a hash entry.
	void *bufPtr = NULL;
	int tag = 132;
	MPI_Datatype datatype = MPI_LONG;
	int destRank = nextpe;
	requestType_t requestType = SEND;
	
	useHash = AddBufferEntry( tag, BUF_SIZE, datatype, my_pe, destRank, requestType, &bufPtr, MPI_COMM_WORLD); 
	
	// Set up for sending:
	nextpe = (my_pe + 1) % size;
	
	if ( useHash == BAD){
		didFail = AddComplexity( BUF_SIZE, &buf);
		
		if (didFail == BAD){
			printf("Error: No symmetric memory for PE: %d\n", my_pe);
			return 0;
		}
	}
	// Try using the pointer from the hash table...
	else{
		GetBufferPtrFromHash( tag, BUF_SIZE, datatype, requestType, &bufPtr, MPI_COMM_WORLD );
	}
	
	for (i=0; i<BUF_SIZE;i++){
		src[i]  = i+1;
		if (useHash) 
			((long *)bufPtr)[i] = BUF_SIZE -i;
		else
			buf[i]  = BUF_SIZE - i;
	}
	
	if (useHash)
		putData(&bufPtr, src, BUF_SIZE, nextpe);
	else
		putData(&buf, src, BUF_SIZE, nextpe);
	
	for (i=0; i<BUF_SIZE;i++){
		if (useHash){
			if (((long *)bufPtr)[i] != src[i] ){
				printf("Failed PE; %d, bufPtr[%d] = %ld\n", my_pe, i, ((long*) bufPtr)[i]);
				didFail = BAD;
			}
		}
		else{
			if (buf[i] != src[i] ){
				printf("Failed PE; %d, buf[%d] = %ld\n", my_pe, i,  ((long*) buf)[i]);
				didFail = BAD;
			}
		}
	}
	
	if ( didFail == GOOD ){
		printf ("Passed, PE: %d\n", my_pe);
	}
	
	// Clean-up 
	if (useHash){
		didFail = DeleteHashEntry( tag, BUF_SIZE, datatype, requestType, &bufPtr, MPI_COMM_WORLD );
	}
	return 0;
    
}
