#include <stdio.h>
#include <shmem.h>
#include "mpi.h"
#include "mdhim.h"
#include "shmem.h"
#include "db_options.h"

int main(int argc, char **argv) {
	//printf ("Simple2:hello  *************\n");
	int ret;
	int provided = 0;
	struct mdhim_t *md;
	int key;
	int value;
	struct mdhim_rm_t *rm;
	struct mdhim_getrm_t *grm;
        db_options_t *db_opts;

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

        db_opts = db_options_init();
        db_options_set_path(db_opts, "./");

	return 0;
}
