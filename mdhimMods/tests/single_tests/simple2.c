#include <stdio.h>
#include <shmem.h>
#include "mdhim.h"
#include "shmem.h"
#include "db_options.h"

#define BUFSIZ  100
#define TRUE      1
#define FALSE     0
#define MPI_CHAR  1

int main(int argc, char **argv) {
	//printf ("Simple2:hello  *************\n");
	int ret;
	int provided = 0;
        //db_options_t *db_opts;
	int master = FALSE;
	int count;
       	char master_name[BUFSIZ];
	char send_buffer[BUFSIZ], recv_buffer[BUFSIZ];
	MPI_Status status;
	MPI_Comm comm;

  	printf ("Before calling mpi_init  *************\n");

	ret = MPI_Init_thread(&argc, &argv, MPI_THREAD_MULTIPLE, &provided);
	if (ret != MPI_SUCCESS) {
		printf("Error initializing MPI with threads\n");
		exit(1);
	}
        int me = _my_pe ();
        int npes = _num_pes ();
        
	printf ("Hello from node %4d of %4d\n", me, npes);
                printf ("Before calling mpi_init  *************\n");

 	printf ("Provided: %d *************\n", provided);
	if (provided != MPI_THREAD_MULTIPLE) {
                printf("Not able to enable MPI_THREAD_MULTIPLE mode\n");
                exit(1);
        }

        //db_opts = db_options_init();
        //db_options_set_path(db_opts, "./");

	if (me == 0) {
	  master = TRUE;
	  strcpy (master_name, "Master Process");
	}

	printf("Single2: datatype: %d\n", MPI_CHAR);
	MPI_Bcast(master_name, BUFSIZ, MPI_CHAR, 0, comm);
	/*
	if (master) 
	  for (count = 1; count < npes; count++) {
	    MPI_Recv (recv_buffer, BUFSIZ, MPI_CHAR, MPI_ANY_SOURCE, MPI_ANY_TAG,
		      MPI_COMM_WORLD, &status);
	    printf ("%s\n", recv_buffer);
	  }
	else {
	  sprintf(send_buffer, "hello %s, greetings from %s, rank = %d",
		  master_name, "Master Process", me);
	  MPI_Send (send_buffer, strlen(send_buffer) + 1, MPI_CHAR,
		    0, 0, MPI_COMM_WORLD);
	}

	MPI_Finalize();
	*/
	return 0;
}
