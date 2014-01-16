/*
*This material was prepared by the Los Alamos National Security, LLC (LANS) under
*Contract DE-AC52-06NA25396 with the U.S. Department of Energy (DOE). All rights
*in the material are reserved by DOE on behalf of the Government and LANS
*pursuant to the contract. You are authorized to use the material for Government
*purposes but it is not to be released or distributed to the public. NEITHER THE
*UNITED STATES NOR THE UNITED STATES DEPARTMENT OF ENERGY, NOR THE LOS ALAMOS
*NATIONAL SECURITY, LLC, NOR ANY OF THEIR EMPLOYEES, MAKES ANY WARRANTY, EXPRESS
*OR IMPLIED, OR ASSUMES ANY LEGAL LIABILITY OR RESPONSIBILITY FOR THE ACCURACY,
*COMPLETENESS, OR USEFULNESS OF ANY INFORMATION, APPARATUS, PRODUCT, OR PROCESS
*DISCLOSED, OR REPRESENTS THAT ITS USE WOULD NOT INFRINGE PRIVATELY OWNED RIGHTS.
*/

//Standard includes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>
#include <time.h>
#include <syslog.h>
#include <getopt.h>
#include <ctype.h>
#include <string.h>

#include "pftool.h"
#include "pwt/pwt.h"				// has options definition
#include "apps/treewalk.h"			// has AppOptions definition
#include "apps/cmp.h"				// has Compare definition
//#include "mpi.h"
#include "/users/gingery/mpi_to_openshmem/src/mpi_to_openshmem.h"

#define GETOPT_OPTIONS "Rd:hmqrs:v"		// Command line options

int main(int argc, char *argv[]){
    int nproc, rank;
    int c;
    options *o;
    AppOptions *app_o;
    processarg_t process_appargs;
    pwt *pwt_instance = NULL;


    //setup mpi
    if (MPI_Init(&argc, &argv) != MPI_SUCCESS) {
        fprintf(stderr, "Error in MPI_Init\n");
        return -1;
    }    

    //    bzero(&app_o,sizeof(app_o));			// initialize options structures
    //    bzero(&o,sizeof(o));
    app_o = (AppOptions*) shmalloc (sizeof(AppOptions));
    o     = (options*) shmalloc (sizeof(options));

    // Initialize the space
    memset(app_o, 0, sizeof(AppOptions));
    memset(o, 0, sizeof(options));

    // Get the number of procs
    if (MPI_Comm_size(MPI_COMM_WORLD, &nproc) != MPI_SUCCESS) {
        fprintf(stderr, "Error in MPI_Comm_size\n");
        return -1;
    }    
    // Get your rank
    if (MPI_Comm_rank(MPI_COMM_WORLD, &rank) != MPI_SUCCESS) {
        fprintf(stderr, "Error in MPI_Comm_rank\n");
        return -1;
    }   

    //collect the procs
    if (rank == MANAGER_PROC){
      //set defaults
      o->nproc = nproc;
      
      for (c =0;c<argc;c++){
	printf("argv[0] = %s\n", argv[c]);
      }
    }

    // Need to set the parameters, since gasnet is not passing them through...
    if ( strstr(argv[1], "GASNET") ){
      argv[1] = "/users/gingery";
    }


    /* */

   
    if (strstr(argv[0],"pfcmp")) {			// want to compare files
        o->startwork = cmp_startwork;			// set up for comparing
        o->endwork = cmp_endwork;
        app_o->processfile = cmp_process_file;
        process_appargs = cmp_process_args;
        o->nqueues = 2;					// use 2 queues when doing compares
    }
    else {						// treewalk/stat by default
        o->startwork = treewalk_startwork;			// set up for treewalking
        o->endwork = treewalk_endwork;
        app_o->processfile = treewalk_process_file;
        process_appargs = treewalk_process_args;
    }

    //fill them in using getopt
    while ((c = getopt (argc, argv, GETOPT_OPTIONS)) != -1){

      if (rank == MANAGER_PROC){
	printf(" optarg: %s, c = %c\n",optarg, c);
      }
      switch(c){
      case 'd':
	if(strstr(optarg,"file"))
	  AppFileDebug(1);
	if(strstr(optarg,"mpi"))
	  PwtMpiDebug(1);
	if(strstr(optarg,"sched"))
	  PwtSchedDebug(1);
	break;
      case 'h':
	printf("help!\n");
	return 0;
	break;
      case 'm':
	app_o->meta_only = 1;
	break;
      case 'q':
	app_o->quiet = 1;
	break;
      case 'R':
      case 'r':
	app_o->recursive = 1;
      break;
      case 's':
	strncpy(app_o->start_path, optarg, PATHSIZE_PLUS);
	break;
      case 'v':
	app_o->verbose = 1;
	break;
      case '?':
	return 1;
      }
    }

    if(optind < argc) {			// there are non-option arguments
      app_o->args = (argv + optind);
      app_o->argc = argc - optind;
    }

    if(!process_appargs(app_o)){		// process the application's arguments
      printf( "Yikes!, optind: %d, argc: %d\n", optind, argc);
      return -1;
    }
    // End Manager command line
    else {					// Worker commandline options. Most should be feed through the manager!
      while ((c = getopt (argc, argv, GETOPT_OPTIONS)) != -1){
	if (rank == MANAGER_PROC){
	  printf(" optarg: %s, c = %c\n",optarg, c);
	}
 
        switch(c){
          case 'd':
            if(strstr(optarg,"file")){
	      AppFileDebug(1);
	    }
            if(strstr(optarg,"mpi"))
	      PwtMpiDebug(1);
            break;
        }
      }
    } // End Worker command line
    

    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Bcast(o, sizeof(o), MPI_CHAR, MANAGER_PROC, MPI_COMM_WORLD);
    MPI_Bcast(app_o, sizeof(app_o), MPI_CHAR, MANAGER_PROC, MPI_COMM_WORLD);

    o->app_ops = (void *)app_o;			// make sure that application options are included in options!
    o->rank = rank;				// Assigned after MPI_Bcast so that it is unique for this process

    pwt_instance = pwt_new((rank == MANAGER_PROC)?MANAGER_TYPE:WORKER_TYPE);

    // Create the correct PWT instance for this process    
    if (pwt_instance->init(*o) == PWT_SUCCESS){
      printf("pftool::main, pwt_instance->init successful\n");
      pwt_instance->run(*o);			// Main routine for this process ...
    }
    printf("pftool::main, before fini\n");
    pwt_instance->fini();

    printf("pftool::main, before free\n");
    free(pwt_instance);

    printf("pftool::main, after free\n");
    MPI_Finalize();
    printf("pftool::main, after finalize\n");
    return 0;
}
/* */
