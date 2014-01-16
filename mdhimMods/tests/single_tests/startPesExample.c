#include <stdio.h>
#include <stdlib.h>
#include <shmem.h>
//#include "mpi_to_openshmem.h"


long pSync[_SHMEM_BCAST_SYNC_SIZE];

void initOpenShmem(){
	start_pes (0);

	int rank = _my_pe ();
	int npes = _num_pes ();
	
	printf ("initOpenShmem. rank = %d, npes = %d\n", rank, npes);	
	
}

int main(int argc, char **argv) {
	printf ("startPESExample: begin  *************\n");

	initOpenShmem();
	printf ("After calling initOpenShmem  *************\n");
	
	start_pes(0);

       	return 0;
}
