#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
#include "mdhim.h"
#include "shmem.h"
#include "db_options.h"

int main(int argc, char **argv) {
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
	printf ("Provided: %d *************\n", provided);
	if (provided != MPI_THREAD_MULTIPLE) {
                printf("Not able to enable MPI_THREAD_MULTIPLE mode\n");
                exit(1);
        }

	// Broadcast:
	//  start_pes (0);
	//    me = _my_pe ();
	//      npes = _num_pes ();
	//
	//        source = (long *) shmalloc (npes * sizeof (*source));
	//          for (i = 0; i < npes; i += 1)
	//              {
	//                    source[i] = i + 1;
	//                        }
	//
	//                          target = (long *) shmalloc (npes * sizeof (*target));
	//                            for (i = 0; i < npes; i += 1)
	//                                {
	//                                      target[i] = -999;
	//                                          }
	//
	//                                            for (i = 0; i < _SHMEM_BCAST_SYNC_SIZE; i += 1)
	//                                                {
	//                                                      pSync[i] = _SHMEM_SYNC_VALUE;
	//                                                          }
	//                                                            shmem_barrier_all ();
	//
	//                                                              shmem_broadcast64 (target, source, npes, 0, 0, 0, npes, pSync);
	//
	//                                                                for (i = 0; i < npes; i++)
	//                                                                    {
	//                                                                          printf ("%-8d %ld\n", me, target[i]);
	//                                                                              }
	//
	//                                                                                shmem_barrier_all ();
	//
	//                                                                                  shfree (target);
	//                                                                                    shfree (source);
	//
	//
        /**/

                printf("Set db options init\n");
	db_opts = db_options_init();
        db_options_set_path(db_opts, "./");
        db_options_set_name(db_opts, "mdhimTstDB");
        db_options_set_type(db_opts, 2); // type = 2 (LevelDB)
        db_options_set_key_type(db_opts, MDHIM_INT_KEY); //Key_type = 1 (int)
	db_options_set_debug_level(db_opts, MLOG_DBG);
                printf("After db optins..\n");

	md = mdhimInit(MPI_COMM_WORLD, db_opts);
	if (!md) {
		printf("Error initializing MDHIM\n");
		exit(1);
	}	


	return 0;
}
