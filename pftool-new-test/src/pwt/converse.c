
//#include "mpi.h"

#include "/users/gingery/mpi_to_openshmem/src/mpi_to_openshmem.h"

#include "workitem.h"

/**
* Routine that sends a Work Item to another MPI process. Note
* that this routine will send the item to the listed originator
* of the item. It then updates the item's originator with the 
* current or calling rank. After sending, the originator is updated
* original originator.
*
* @param item		the Work Item to send
* @param source_rank	the calling MPI Process number or rank
* @param target_rank	the rank of the MPI Process
*/
void send_workitem(WorkItem *item, int source_rank, int target_rank) {
	char *sendbuf;						// local send buffer
    	int sendsize = sizeof(WorkItem);			// size of the local send buffer
    	int sendidx = 0;					// index or position in the local send buffer
	int backup_rank = item->originator;			//  holds the original originator

	workitem_update_originator(item,source_rank);		// mark this item as coming from the source process
								// add the size of any allocated workdata pointer
	if(item->workdata) sendsize += item->workdata_size;
	sendbuf = (char *)shmalloc(sendsize * sizeof(char));
	printf("converse::send_workitem MPI_Pack \n");
								// pack the buffer, with allocated pointers at the end
	MPI_Pack(item, sizeof(WorkItem), MPI_CHAR, sendbuf, sendsize, &sendidx, MPI_COMM_WORLD);
	printf("converse::send_workitem MPI_Pack 1\n");
        if(item->workdata)
	  MPI_Pack(item->workdata, item->workdata_size, MPI_CHAR, sendbuf, sendsize, &sendidx, MPI_COMM_WORLD);
	printf("converse::send_workitem MPI_Pack 2\n");
	PRINT_MPI_DEBUG("Rank %d: Sending work item to target rank %d (originator = %d)\n", source_rank, target_rank,item->originator);
	printf("converse::send_workitem MPI_send to target_rank: %d \n",target_rank);
	if (MPI_Send(&sendsize, 1, MPI_INT, target_rank, target_rank, MPI_COMM_WORLD) != MPI_SUCCESS) {
	  fprintf(stderr, "Rank %d: Failed to send item size to rank %d\n", source_rank, target_rank);
	  printf("converse::send_workitem mpi_abort\n\n");
          MPI_Abort(MPI_COMM_WORLD, -1);

	}
	if (MPI_Send(sendbuf, sendsize, MPI_PACKED, target_rank, target_rank, MPI_COMM_WORLD) != MPI_SUCCESS) {
	  fprintf(stderr, "Rank %d: Failed to send item to rank %d\n", source_rank, target_rank);
	  printf("converse::send_workitem mpi_abort\n\n");
          MPI_Abort(MPI_COMM_WORLD, -1);
	}

	workitem_update_originator(item,backup_rank);		// set originator back to original value
	free(sendbuf);						// done with send buffer
	return;
}

/**
* Function that receives a Work Item from another MPI process.
* Basically this is a wrapper for MPI_Recv() and MPI_Unpack().
*
* @param local_rank	the calling MPI Process number or rank
* @param remote_rank	the MPI Process to receive the message from
*
* @return the Work Item that is received. If an error occures in
*	revcieving, then MPI_Abort() is called.
*/
WorkItem *get_workitem(int local_rank, int remote_rank) {
	MPI_Status status;					// MPI Status structure
	char *recvbuf;						// local receive buffer
	int recvsize;						// size of the local send buffer
	int recvidx = 0;					// index or position in the local send buffer
	int orig_rank;						// the sending or source rank
	WorkItem *item = workitem_new(local_rank);		// the WorkItem to return

	if (MPI_Recv(&recvsize, 1, MPI_INT, remote_rank, MPI_ANY_TAG, MPI_COMM_WORLD, &status) != MPI_SUCCESS) {
	  fprintf(stderr,"Rank %d: Failed to receive recvbuf size\n", local_rank);
          MPI_Abort(MPI_COMM_WORLD, -1);
    	}
	recvbuf = (char *)malloc(recvsize * sizeof(char));
	orig_rank = status.MPI_SOURCE;				// make sure next MPI_Recv() is talking to orig_rank!

        PRINT_MPI_DEBUG("Rank %d: Receiving work item from rank %d (remote_rank = %d, size of work = %d bytes)\n", local_rank, orig_rank, remote_rank, recvsize);
	if (MPI_Recv(recvbuf, recvsize, MPI_PACKED, orig_rank, MPI_ANY_TAG, MPI_COMM_WORLD, &status) != MPI_SUCCESS) {
	  fprintf(stderr,"Rank %d: Failed to receive recvbuf from rank %d\n", local_rank, orig_rank);
          MPI_Abort(MPI_COMM_WORLD, -1);
    	}

	MPI_Unpack(recvbuf, recvsize, &recvidx, item, sizeof(WorkItem), MPI_CHAR, MPI_COMM_WORLD);
//printf("Rank %d: AFTER receiving item. recvidx = %d (out of %d)\n", local_rank, recvidx, recvsize);
								// allocate and unpack any allocated pointers in the work item
        if(item->workdata) {
          item->workdata = (void *)malloc(item->workdata_size);
	  MPI_Unpack(recvbuf, recvsize, &recvidx, item->workdata, item->workdata_size, MPI_CHAR, MPI_COMM_WORLD);
	}

	if(item->originator != orig_rank)
	  fprintf(stderr,"Rank %d: Warning! Recieved work item MAY BE corrupted! (item originator rank = %d, orig_rank= %d)\n", 
			local_rank, item->originator, orig_rank);
	free(recvbuf);						// done with receive buffer
	return(item);
}

/**
* Function that receives a Work Item from another MPI process.
* This will receive a message from any MPI Process. Basically 
* this is a wrapper for MPI_Recv() and MPI_Unpack().
*
* @param local_rank	the calling MPI Process number or rank
*
* @return the Work Item that is received. If an error occures in
*	revcieving, then MPI_Abort() is called.
*/
WorkItem *receive_workitem(int local_rank) {
	return(get_workitem(local_rank,MPI_ANY_SOURCE));
}

/**
* Function that probes for an MPI message for the calling routine. This
* function is essentially a wrapper for MPI_Iprobe(). If MPI_IProbe()
* fails for any reason, this function aborts the process.
*
* @param local_rank	the calling MPI Process number or rank
*
* @return Non-zero if a message was received. Otherwise zero is 
*	returned.
*/
int message_ready(int local_rank) {
	MPI_Status status;					// MPI Status structure
	int is_message = 0;					// a flag indicating that a message has arrived

	printf("converse::message_ready mpi_iprobe\n");
	if( MPI_Iprobe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &is_message, &status) != MPI_SUCCESS) {
	  fprintf(stderr,"Rank %d: MPI_Iprobe failed\n",local_rank);
          MPI_Abort(MPI_COMM_WORLD, -1);
        }
	printf("converse::message_ready mpi_iprobe, is_message: %d\n", is_message);
	return(is_message);
}
