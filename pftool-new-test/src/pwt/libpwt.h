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

#ifndef _LIBPWT_H
#define _LIBPWT_H

#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>

#include "debug.h"
//mpi
//#include "mpi.h"
#include "/users/gingery/mpi_to_openshmem/src/mpi_to_openshmem.h"

#define MPI_DEBUG

#define MANAGER_PROC 0
#define START_PROC 1

#define PATHSIZE_PLUS (FILENAME_MAX+30)
#define ERRORSIZE PATHSIZE_PLUS
#define MESSAGESIZE PATHSIZE_PLUS

extern int pwt_mpi_debug;		// Global debug flags. See debug.h and pwt.c
extern int pwt_poll_debug;		
extern int pwt_sched_debug;		

#endif
