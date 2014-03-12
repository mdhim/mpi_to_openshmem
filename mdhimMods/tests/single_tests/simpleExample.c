/*                                                                                  
 *                                                                                  
 *                                                                                  
 */
#include <stdio.h>
#include <stdlib.h>
#include "mpi_to_openshmem.h"
#include "hashUtils.h"

struct MPID_Hash *bufHashTbl = NULL;

#define BUF_SIZE 10

#define GOOD 1
#define BAD  0

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
	
	HASH_FIND_INT(bufHashTbl, &tag, newEntry);  /* id already in the hash? */
	printf ("AddBufEntry:: HASH_FIND_IT, newEntry: %x\n", newEntry);
	
	if (newEntry==NULL) {
		shmem_barrier_all();  // This needs to be here...                               
		newEntry = (struct MPID_Hash*)shmalloc(sizeof(struct MPID_Hash));
		shmem_fence();
		newEntry->id         = tag;
		printf("CreateEntry: Creating an entry, tag: %d\n", tag);
		HASH_ADD_INT( bufHashTbl, id, newEntry );  /* id: name of key field */
	}
	
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

void FindBuffPtr ( int tag, void **bufPtr ){
	struct MPID_Hash *getEntry;
	
	HASH_FIND_INT( bufHashTbl, &tag, getEntry);
	printf("FindBuffPtr: Tag is %d\n", tag);
	
	if (getEntry == NULL) printf("Could not find entry\n");
	else{
		int myTag = getEntry->tag;
		printf("Tag is %d\n", myTag);
		*bufPtr = getEntry->bufPtr;
	}
}

int main(int argc, char *argv[])
{
	int i, size, my_pe;
	int nextpe, provided;
	int didFail = GOOD;
	int useHash = BAD;
	long src[BUF_SIZE];
	long *buf = NULL;
	MPI_Comm  comm;
	
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
	
	useHash = AddBufEntry( tag, BUF_SIZE, datatype, my_pe, destRank, requestType, &bu\
						  fPtr, comm);
	
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
		FindBuffPtr( tag, &bufPtr );
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
	
	return 0;
	
}

