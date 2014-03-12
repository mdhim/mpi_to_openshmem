/*
 *  hashUtils.c
 *  mpiToOpenshmem
 *
 *  Created by gingery on 2/24/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */
#include "mpi_to_openshmem.h"
#include "hashUtils.h"

/**/
 struct my_struct {
    int id;                    // key 
    char name[10];             
    UT_hash_handle hh;         // makes this structure hashable 
};
struct MPID_Hash *bufHashTbl = NULL;

/**
void add_user(int user_id, char *name) {
	struct my_struct *s;
	
	HASH_FIND_INT(users, &user_id, s);  // id already in the hash? 
	if (s==NULL) {
		s = (struct my_struct*)malloc(sizeof(struct my_struct));
		s->id = user_id;
		HASH_ADD_INT( users, id, s );  // id: name of key field 
	}
	strcpy(s->name, name);
}
*/

int AddBufferSpace(int tag, long count, MPI_Datatype datatype, int srcRank, int destRank, 
				   requestType_t requestType, void **bufPtr, MPI_Comm comm) {

	int		   createHash;
	int		   my_pe;
	int		   numBytes;

	if (isMultiThreads){
		pthread_mutex_lock(&lockAddBufferSpace);
	}
    struct MPID_Hash *newEntry;
	
	createHash = FALSE;
		
    //HASH_FIND_INT(comm->hashPtr, &id, newEntry);  /* id already in the hash? */
    HASH_FIND_INT(bufHashTbl, &tag, newEntry);  /* id already in the hash? */
	shmem_barrier_all();  // Has to be here...	
    if (newEntry==NULL) {
		newEntry = (struct MPID_Hash*)shmalloc(sizeof(struct MPID_Hash));
		shmem_fence();
		newEntry->id = tag;
		printf("CreateEntry: Creating an entry, tag: %d\n", tag);
 		//HASH_ADD_INT( comm->hashPtr, id, newEntry );  /* id: name of key field */
		HASH_ADD_INT( bufHashTbl, id, newEntry );  /* id: name of key field */
    }
	
	// GINGER!  IS this correct????
	comm->hashPtr = bufHashTbl;

	// Place where the buffer data is actually going:
	numBytes = GetNumBytes(count, datatype);
	shmem_barrier_all();  // Has to be here...	
	*bufPtr = (void*)shmalloc( numBytes );
	
	if (*bufPtr == NULL){
		mlog(MPI_DBG, "Error: Unable to create space for receive buffer PE: %d\n", srcRank);
		if (isMultiThreads){
			pthread_mutex_unlock(&lockAddBufferSpace);
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
				pthread_mutex_unlock(&lockAddBufferSpace);
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
				pthread_mutex_unlock(&lockAddBufferSpace);
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
		pthread_mutex_unlock(&lockAddBufferSpace);
	}
	
	return MPI_SUCCESS;
}

void FindTagInHash ( int tag, void **bufPtr ){
	struct MPID_Hash *getEntry;
	
	HASH_FIND_INT( bufHashTbl, &tag, getEntry);
	printf("FindTagInHash: Tag is %d\n", tag);
	
	if (getEntry == NULL) printf("FindTagInHash: Could not find entry\n");
	else{
		int myTag = getEntry->tag;
		printf("Tag is %d\n", myTag);
		*bufPtr = getEntry->bufPtr;
	}
}

/*
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

