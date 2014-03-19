/*
 *  hashUtils.c
 *  mpiToOpenshmem
 *
 *  Created on 2/24/14.
 *  Copyright 2014 LANL. All rights reserved.
 *
 */
#include "mpi_to_openshmem.h"
#include "hashUtils.h"

/**/
struct MPID_Hash *bufHashTbl = NULL;


int AddBufferEntry(int tag, long count, MPI_Datatype datatype, int srcRank, int destRank, 
				   requestType_t requestType, void **bufPtr, MPI_Comm comm) {

	int		   createHash;
	int		   my_pe;
	int		   numBytes;
    struct MPID_Hash *newEntry;

	if (isMultiThreads){
		pthread_mutex_lock(&lockAddBufferEntry);
	}
	
	struct MPID_Hash *bufHashTbl = comm->hashPtr;
	//printf ("AddBufEntry: bufHashTbl: %x, \n",  bufHashTbl);                        
	//printf("\tcomm->hashPtr: %x,\n",comm->hashPtr);                                 
	//printf("\t bufHash: %x \n", bufHash);                                           
	createHash = FALSE;
	
    HASH_FIND_INT(bufHashTbl, &tag, newEntry);  // id already in the hash?
	
	shmem_barrier_all();  // This has to be here.	
    if (newEntry == NULL) {
		newEntry = (struct MPID_Hash*)shmalloc(sizeof(struct MPID_Hash));
		shmem_fence();
		
		newEntry->id = tag;
		printf("AddBufferEntry: Creating an entry, tag: %d\n", tag);
		HASH_ADD_INT( bufHashTbl, id, newEntry );  /* id: name of key field */

		// Update the pointer, creating the hash table...
		comm->hashPtr = bufHashTbl;
    }

	// Re-set the ptr to the hash table GINGER???                                              
	//comm->hashPtr = bufHashTbl;	

	// Place where the buffer data is actually going:
	numBytes = GetNumBytes(count, datatype);
	shmem_barrier_all();  // Has to be here...	
	*bufPtr = (void*)shmalloc( numBytes );
	
	if (*bufPtr == NULL){
		mlog(MPI_ERR, "Error: Unable to create space for receive buffer PE: %d\n", srcRank);
		if (isMultiThreads){
			pthread_mutex_unlock(&lockAddBufferEntry);
		}
		return MPI_ERR_BUFFER;
	}
	
	// Fill in data:
	newEntry->tag         = tag;
	newEntry->count       = count;
	newEntry->datatype    = datatype;
	newEntry->srcRank     = srcRank;
	newEntry->destRank    = destRank;
	newEntry->requestType = requestType;
	newEntry->isGrabbed   = FALSE;
	newEntry->time        = time(NULL);
	newEntry->bufPtr	  = *bufPtr;

	/*
    HASH_FIND_INT(bufferHash, &id, hash);  // Is the key already in the hash?
	
	// If the key is in use, should we see if it's finisehd, and blast it?
	if (hash != NULL) {
		if ( hash->isGrabbed ){	
			createHash = TRUE;
			
			// Free old buffer space.
			shfree( hash->bufPtr );
		}
	}
	// Create the space for the hash:
    else{
		hash = (MPID_Hash*)shmalloc(sizeof(MPID_Hash));
		
		if (hash == NULL){
			mlog(MPI_ERR, "Error: Unable to create space for new Hash entry, PE: %d\n", srcRank);
			if (isMultiThreads){
				pthread_mutex_unlock(&lockAddBufferEntry);
			}
			return MPI_ERR_BUFFER;
		}
		
		hash->id = id;
    }
	
	// Now create and move data into the structure...
	if (createHash) {
		
		// Place where the buffer data is actually going:
		numBytes = GetNumBytes(count, datatype);
		hash->bufPtr = (void*)shmalloc( numBytes );
		
		if (hash->bufPtr == NULL){
			mlog(MPI_DBG, "Error: Unable to create space for receive buffer PE: %d\n", srcRank);
			if (isMultiThreads){
				pthread_mutex_unlock(&lockAddBufferEntry);
			}
			return MPI_ERR_BUFFER;
		}
		
		// Fill in data:
		hash->tag         = tag;
		hash->count       = count;
		hash->datatype    = datatype;
		hash->srcRank     = srcRank;
		hash->destRank    = destRank;
		hash->requestType = requestType;
		hash->isGrabbed   = FALSE;
		hash->time        = time(NULL);
	}
	else {
		// What do we do if it's not relinquished?
		// and there's a duplicate!
	}

**/
	if (isMultiThreads){
		pthread_mutex_unlock(&lockAddBufferEntry);
	}
	
	return MPI_SUCCESS;
}// AddBufferEntry

int DeleteHashEntry( int tag, long count, requestType_t requestType, MPI_Datatype datatype, void **bufPtr, MPI_Comm comm ){
	struct MPID_Hash *getEntry;
	int               results;
	
	if (isMultiThreads){
		pthread_mutex_lock(&lockDeleteHashEntry);
	}

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

	return results;
	
	if (isMultiThreads){
		pthread_mutex_unlock(&lockDeleteHashEntry);
	}

}// DeleteHashEntry                                                                                                                                           

			
int FindTagInHash ( int tag, void **bufPtr, MPI_Comm comm ){
	struct MPID_Hash *getEntry;
	int				 results;
	
	if (isMultiThreads){
		pthread_mutex_lock(&lockFindTagInHash);
	}
	
	struct MPID_Hash *bufHashTbl = comm->hashPtr;
	results = MPI_SUCCESS;
	
	HASH_FIND_INT( bufHashTbl, &tag, getEntry);
	printf("FindTagInHash:: Tag is %d\n", tag);
	
	if (getEntry == NULL){
		mlog(MPI_ERR, "Error: to find entry id: %d for PE: %d\n", tag, comm->rank);
		printf("FindTagInHash:: Could not find entry\n");
		results =  HASH_ERR_ID_NOT_FOUND;                                                                     
	}
	else{
		int myTag = getEntry->tag;
		printf("FindTagInHash:: Tag is %d\n", myTag);
		*bufPtr = getEntry->bufPtr;
	}

	if (isMultiThreads){
		pthread_mutex_unlock(&lockFindTagInHash);
	}
}// FindTagInHash

int GetBufferPtrFromHash ( int tag, long count, requestType_t requestType, MPI_Datatype datatype, void **bufPtr, MPI_Comm comm ){
	struct MPID_Hash *getEntry;
	int               results;
	
	if (isMultiThreads){
		pthread_mutex_lock(&lockGetBufferPtrFromHash);
	}

	struct MPID_Hash *bufHashTbl = comm->hashPtr;
	results = MPI_SUCCESS;
	
	HASH_FIND_INT( bufHashTbl, &tag, getEntry);
	//printf("GetBufferPtrFromHash:: Tag is %d\n", tag);
	
	if (getEntry == NULL){
		printf("GetBufferPtrFromHash:: Could not find entry\n");
		mlog(MPI_ERR, "Error: to find entry id: %d for PE: %d\n", tag, comm->rank);
		results =  HASH_ERR_ID_NOT_FOUND;                                                                     
	}
	else{
		int myTag = getEntry->tag;
		//printf("GetBufferPtrFromHash:: Tag is %d, requestType: %d, Time: %d\n", myTag,getEntry->requestType, getEntry->time);
		
		// Verify it's the iytem you are looking for                                                            
		if ( count != getEntry->count ){
			printf( "Error: Mismatched value expected count: %d, hash->count: %d for PE: %d\n", count, getEntry->count, comm->rank);
			mlog(MPI_ERR, "Error: Mismatched value expected count: %d, hash->count: %d for PE: %d\n", count, getEntry->count, comm->rank);
			results = HASH_ERR_MISMATCHED_COUNT;                                                               
		}
		else if ( requestType != getEntry->requestType ){
			printf( "Error: Mismatched value expected requestType: %d, hash->requestType: %d for PE: %d\n", requestType, getEntry->requestType, comm->rank);
			mlog(MPI_ERR, "Error: Mismatched value expected requestType: %d, hash->requestType: %d for PE: %d\n", requestType, getEntry->requestType, comm->rank);
			results = HASH_ERR_MISMATCHED_REQUEST_TYPE;                                                        
		}
		else if ( datatype != getEntry->datatype ){
			printf( "Error: Mismatched value expected datatype: %d, hash->datatype: %d for PE: %d\n", datatype, getEntry->datatype, comm->rank);
			mlog(MPI_ERR, "Error: Mismatched value expected datatype: %d, hash->datatype: %d for PE: %d\n", datatype, getEntry->datatype, comm->rank);
			results = HASH_ERR_MISMATCHED_DATATYPE;                                                            
		}
	}
	
	if (results == MPI_SUCCESS){
		*bufPtr = getEntry->bufPtr;

		// Also mark that this buffer has been grabbed:
		getEntry->isGrabbed = TRUE;
	}
	if (isMultiThreads){
		pthread_mutex_unlock(&lockGetBufferPtrFromHash);
	}

	return results;
	
}//GetBufferPtrFromHash                                                                                     


/*
 struct my_struct {
 int id;                    // key 
 char name[10];             
 UT_hash_handle hh;         // makes this structure hashable 
 };

 struct my_struct *find_user(int user_id) {
    struct my_struct *s;
	
    HASH_FIND_INT( bufHashTbl, &user_id, s );  // s: output pointer 
    return s;
}

void delete_user(struct my_struct *user) {
    HASH_DEL( bufHashTbl, user);  // user: pointer to deletee 
    free(user);
}

void delete_all() {
	struct my_struct *current_user, *tmp; 
	
	HASH_ITER(hh, bufHashTbl, current_user, tmp) {
		HASH_DEL(bufHashTbl,current_user);  // delete it (bufHashTbl advances to next) 
		free(current_user);            // free it 
	} 
}

void print_bufHashTbl() {
    struct my_struct *s;
	
    for(s=bufHashTbl; s != NULL; s=(struct my_struct*)(s->hh.next)) {
        printf("bufHashTbl id %d: name %s\n", s->id, s->name);
    }
}

int name_sort(struct my_struct *a, struct my_struct *b) {
    return strcmp(a->name,b->name);
}

int id_sort(struct my_struct *a, struct my_struct *b) {
    return (a->id - b->id);
}

void sort_by_name() {
    HASH_SORT(bufHashTbl, name_sort);
}

void sort_by_id() {
    HASH_SORT(bufHashTbl, id_sort);
}
*/

