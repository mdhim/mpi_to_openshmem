




































































[gingery@ca-fe tests]$ emacs single_tests/lock.c
[gingery@ca-fe tests]$ make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
[gingery@ca-fe tests]$ cd ../../
[gingery@ca-fe ~/mpi_to_openshmem]$ pwd
/users/gingery/mpi_to_openshmem
[gingery@ca-fe ~/mpi_to_openshmem]$ ls
./   English.lproj/  makefacs.pl*  mdhimMods/		    mpiCallsInMdhim.txt  mpi.h	 README.md
../  .git/	     Makefile	   mdhimNet-1.moved-aside/  mpidefs.h		 README  src/
[gingery@ca-fe ~/mpi_to_openshmem]$ cd ..
[gingery@ca-fe ~]$ ls
./		  .emacs		   mpi_to_openshmem/	       README
../		  .emacs.d/		   mpiToOpenshmem/	       README_GN_RESULTS
authorized_keys   GASNet-1.20.2/	   mpi_to_openshmem.tar        README_TEST_RESULTS_GasNet_Standard
.bash_logout	  GASNet-1.20.2_standard/  openshmem-1.0d_IBV/	       .saves-2782-rrz-fe1.localdomain
.bash_profile	  GASNet-1.20.2.tar.gz	   openshmem-1.0d_SMP/	       src/
.bash_profile~	  .gitconfig		   openshmem-1.0d_UDP/	       .ssh/
.bashrc		  .gnome2/		   openshmem-1.0e_IBV/	       .texlive2007/
.bashrc~	  .history		   openshmem-1.0e_UDP/	       .viminfo
config.h	  .local_env_Linux~	   openshmem-release-1.0e.tar  .Xauthority
config.status*	  .local_env_Linux_save    openshmemReleases/	       .xemacs/
.cshrc		  mdhim-tng/		   openshmem.tar.gz	       y
.cshrc.local_sv   mdhim-tng.tar.gz	   openshmem-test-1.0b/        y.pub
.cshrc.local_sv~  mpidefs.h		   openshmemTest.tar.gz
doc/		  mpi.h			   pftools.tar
[gingery@ca-fe ~]$ ls mpiToOpenshmem/
./  ../  .git/	Makefile  mpiCallsInMdhim.txt  README  README.md  src/
[gingery@ca-fe ~]$ cd mpi_
mpi_to_openshmem/     mpi_to_openshmem.tar  
[gingery@ca-fe ~]$ cd mpi_to_openshmem
[gingery@ca-fe ~/mpi_to_openshmem]$ ls
./   English.lproj/  makefacs.pl*  mdhimMods/		    mpiCallsInMdhim.txt  mpi.h	 README.md
../  .git/	     Makefile	   mdhimNet-1.moved-aside/  mpidefs.h		 README  src/
[gingery@ca-fe ~/mpi_to_openshmem]$ ls md
mdhimMods/              mdhimNet-1.moved-aside/ 
[gingery@ca-fe ~/mpi_to_openshmem]$ ls mdhimMods/
./   Makefile	Makefile.cfg   perftest-1.5/  pftool-new-test/	      pftools.tar  src/
../  Makefile~	Makefile.cfg~  perftest.tar   pftool-new-test.tar.gz  pftool.tar   tests/
[gingery@ca-fe ~/mpi_to_openshmem]$ cd md
mdhimMods/              mdhimNet-1.moved-aside/ 
[gingery@ca-fe ~/mpi_to_openshmem]$ cd mdhimMods/pft
pftool-new-test/        pftool-new-test.tar.gz  pftools.tar             pftool.tar 
[gingery@ca-fe ~/mpi_to_openshmem]$ cd mdhimMods/pftool-
pftool-new-test/        pftool-new-test.tar.gz  
[gingery@ca-fe ~/mpi_to_openshmem]$ cd mdhimMods/pftool-new-test
[gingery@ca-fe pftool-new-test]$ ls
./		cmp.o	     fileinfo.o  Makefile.orig	pathinfo.o  pftool.o	 src/	     worker.o	 workreq.o
../		converse.o   .gitignore  Makefile.save	perfstat.o  pwt.o	 str.o	     workitem.o
CMakeLists.txt	fchunktbl.o  Makefile	 manager.o	pftool*     scheduler.o  treewalk.o  workq.o
[gingery@ca-fe pftool-new-test]$ grep Iprob*/*.c
grep: No match.
[gingery@ca-fe pftool-new-test]$ grep Iprob */*.c
[gingery@ca-fe pftool-new-test]$ grep -i  Iprob */*.c
[gingery@ca-fe pftool-new-test]$ grep -i Iprob */*/*.c
src/pwt/converse.c:* function is essentially a wrapper for MPI_Iprobe(). If MPI_IProbe()
src/pwt/converse.c:	printf("converse::message_ready mpi_iprobe\n");
src/pwt/converse.c:	if( MPI_Iprobe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &is_message, &status) != MPI_SUCCESS) {
src/pwt/converse.c:	  fprintf(stderr,"Rank %d: MPI_Iprobe failed\n",local_rank);
src/pwt/converse.c:	printf("converse::message_ready mpi_iprobe, is_message: %d\n", is_message);
src/pwt/worker.c:  int probecount = 0;							// count of calls to MPI_Iprobe()
[gingery@ca-fe pftool-new-test]$ more src/p
pftool.c~      pftool.c       pftool.c.orig  pftool.h       pwt/           
[gingery@ca-fe pftool-new-test]$ more src/pwt/con
converse.c~  converse.c   converse.h   
[gingery@ca-fe pftool-new-test]$ more src/pwt/converse.c

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
								// pack the buffer, with allocated pointers at the 
end
	MPI_Pack(item, sizeof(WorkItem), MPI_CHAR, sendbuf, sendsize, &sendidx, MPI_COMM_WORLD);
	printf("converse::send_workitem MPI_Pack 1\n");
        if(item->workdata)
	  MPI_Pack(item->workdata, item->workdata_size, MPI_CHAR, sendbuf, sendsize, &sendidx, MPI_COMM_WORLD);
	printf("converse::send_workitem MPI_Pack 2\n");
	PRINT_MPI_DEBUG("Rank %d: Sending work item to target rank %d (originator = %d)\n", source_rank, target_ran
k,item->originator);
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
/Ipro
...skipping
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
[gingery@ca-fe pftool-new-test]$ more src/pwt/converse.c

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
								// pack the buffer, with allocated pointers at the 
end
	MPI_Pack(item, sizeof(WorkItem), MPI_CHAR, sendbuf, sendsize, &sendidx, MPI_COMM_WORLD);
	printf("converse::send_workitem MPI_Pack 1\n");
        if(item->workdata)
	  MPI_Pack(item->workdata, item->workdata_size, MPI_CHAR, sendbuf, sendsize, &sendidx, MPI_COMM_WORLD);
	printf("converse::send_workitem MPI_Pack 2\n");
	PRINT_MPI_DEBUG("Rank %d: Sending work item to target rank %d (originator = %d)\n", source_rank, target_ran
k,item->originator);
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
	orig_rank = status.MPI_SOURCE;				// make sure next MPI_Recv() is talking to orig_ran
k!

        PRINT_MPI_DEBUG("Rank %d: Receiving work item from rank %d (remote_rank = %d, size of work = %d bytes)\n", 
local_rank, orig_rank, remote_rank, recvsize);
	if (MPI_Recv(recvbuf, recvsize, MPI_PACKED, orig_rank, MPI_ANY_TAG, MPI_COMM_WORLD, &status) != MPI_SUCCESS
) {
	  fprintf(stderr,"Rank %d: Failed to receive recvbuf from rank %d\n", local_rank, orig_rank);
          MPI_Abort(MPI_COMM_WORLD, -1);
    	}

	MPI_Unpack(recvbuf, recvsize, &recvidx, item, sizeof(WorkItem), MPI_CHAR, MPI_COMM_WORLD);
//printf("Rank %d: AFTER receiving item. recvidx = %d (out of %d)\n", local_rank, recvidx, recvsize);
								// allocate and unpack any allocated pointers in th
e work item
        if(item->workdata) {
          item->workdata = (void *)malloc(item->workdata_size);
	  MPI_Unpack(recvbuf, recvsize, &recvidx, item->workdata, item->workdata_size, MPI_CHAR, MPI_COMM_WORLD);
	}

	if(item->originator != orig_rank)
	  fprintf(stderr,"Rank %d: Warning! Recieved work item MAY BE corrupted! (item originator rank = %d, orig_r
ank= %d)\n", 
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
[gingery@ca-fe pftool-new-test]$ pwd
/users/gingery/mpi_to_openshmem/mdhimMods/pftool-new-test
[gingery@ca-fe pftool-new-test]$ ls
./		cmp.o	     fileinfo.o  Makefile.orig	pathinfo.o  pftool.o	 src/	     worker.o	 workreq.o
../		converse.o   .gitignore  Makefile.save	perfstat.o  pwt.o	 str.o	     workitem.o
CMakeLists.txt	fchunktbl.o  Makefile	 manager.o	pftool*     scheduler.o  treewalk.o  workq.o
[gingery@ca-fe pftool-new-test]$ make
make: Nothing to be done for `all'.
[gingery@ca-fe pftool-new-test]$ make all
make: Nothing to be done for `all'.
[gingery@ca-fe pftool-new-test]$ make clean
/bin/rm -f *~
/bin/rm -f *.o
/bin/rm -f *.x
/bin/rm -f pftool
[gingery@ca-fe pftool-new-test]$ make
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include  -L/usr/lib64 -L/users/gingery/mpi_to_openshmem/src -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++  -c src/pftool.c
gcc: /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so: linker input file unused because linking not done
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/str.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/perfstat.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/apps/cmp.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/apps/fchunktbl.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/apps/fileinfo.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/apps/pathinfo.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/workitem.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/workq.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/workreq.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/scheduler.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/converse.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/pwt.c
src/pwt/pwt.c: In function ‘set_pwt_instance_to_worker’:
src/pwt/pwt.c:56: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘int (*)(struct options)’
src/pwt/pwt.c:57: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘void (*)(struct options)’
src/pwt/pwt.c:58: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘int (*)(void)’
src/pwt/pwt.c: In function ‘set_pwt_instance_to_manager’:
src/pwt/pwt.c:69: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘int (*)(struct options)’
src/pwt/pwt.c:70: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘void (*)(struct options)’
src/pwt/pwt.c:71: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘int (*)(void)’
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/apps/treewalk.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/worker.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/manager.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -L -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib -L/usr/lib64 -L/users/gingery/mpi_to_openshmem/src -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++   pftool.o str.o perfstat.o cmp.o fchunktbl.o fileinfo.o pathinfo.o workitem.o workq.o workreq.o scheduler.o converse.o pwt.o treewalk.o worker.o manager.o  /users/gingery/mpi_to_openshmem/src/libmpi_to_openshmem.a /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -o pftool
[gingery@ca-fe pftool-new-test]$ exit
logout
Connection to ca-fe closed.
[gingery@ccstargate ~]$ exit
logout
Connection to ccstargate closed.
kef-gay:~ gingery$ ssh ccstargate
gingery@ccstargate's password: 
Warning: untrusted X11 forwarding setup failed: xauth key data not generated
Warning: No xauth data; using fake authentication data for X11 forwarding.
Last login: Wed Feb 12 10:54:21 2014 from jvpn-132-50.lanl.gov
[gingery@ccstargate ~]$ !ssh
ssh ca-fe
Last login: Wed Feb 12 10:54:49 2014 from 10.128.10.240
******************************************************************************
                              Notice to Users

This is a Federal computer system and is the property of the United
States Government.  It is for authorized used only.  Users (authorized or
unauthorized) have no explicit or implicit expectation of privacy.

Any or all uses of this system and all files on this system may be
intercepted, monitored, recorded, copied, audited, inspected, and disclosed
to authorized site, Department of Energy, and law enforcement personnel, as
well as authorized officials of other agencies, both domestic and foreign.
By using this system, the user consents to such interception, monitoring,
recording, copying, auditing, inspection, and disclosure at the discretion
of authorized site or Department of Energy personnel.

Unauthorized or improper use of this system may result in administrative
disciplinary action and civil and criminal penalties.  By continuing to
use this system you indicate your awareness of and consent to these terms
and conditions of use.  LOG OFF IMMEDIATELY if you do not agree to the
conditions stated in this warning.

******************************************************************************

[gingery@ca-fe ~]$ !sou
source ~/.cshrc.local_sv
Adding OpenShmem-1.0e_IBV
Currently Loaded Modulefiles:
  1) mvapich2-gnu-ofa/1.7
[gingery@ca-fe ~]$ wrk
[gingery@ca-fe src]$ cd ..
[gingery@ca-fe ~/mpi_to_openshmem]$ ls
./   English.lproj/  makefacs.pl*  mdhimMods/		    mpiCallsInMdhim.txt  mpi.h	 README.md
../  .git/	     Makefile	   mdhimNet-1.moved-aside/  mpidefs.h		 README  src/
[gingery@ca-fe ~/mpi_to_openshmem]$ cd mdh
mdhimMods/              mdhimNet-1.moved-aside/ 
[gingery@ca-fe ~/mpi_to_openshmem]$ cd mdhimMods/pft
pftool-new-test/        pftool-new-test.tar.gz  pftools.tar             pftool.tar 
[gingery@ca-fe ~/mpi_to_openshmem]$ cd mdhimMods/pftool-
pftool-new-test/        pftool-new-test.tar.gz  
[gingery@ca-fe ~/mpi_to_openshmem]$ cd mdhimMods/pftool-new-test
[gingery@ca-fe pftool-new-test]$ ls
./		cmp.o	     fileinfo.o  Makefile.orig	pathinfo.o  pftool.o	 src/	     worker.o	 workreq.o
../		converse.o   .gitignore  Makefile.save	perfstat.o  pwt.o	 str.o	     workitem.o
CMakeLists.txt	fchunktbl.o  Makefile	 manager.o	pftool*     scheduler.o  treewalk.o  workq.o
[gingery@ca-fe pftool-new-test]$ more src/
apps/          pftool.c~      pftool.c.orig  pwt/           str.h          
debug.h        pftool.c       pftool.h       str.c          
[gingery@ca-fe pftool-new-test]$ more src/
apps/          pftool.c~      pftool.c.orig  pwt/           str.h          
debug.h        pftool.c       pftool.h       str.c          
[gingery@ca-fe pftool-new-test]$ more src/pf
pftool.c~      pftool.c       pftool.c.orig  pftool.h       
[gingery@ca-fe pftool-new-test]$ more src/pftool.c
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

[gingery@ca-fe pftool-new-test]$ pwd
/users/gingery/mpi_to_openshmem/mdhimMods/pftool-new-test
[gingery@ca-fe pftool-new-test]$ grep message_ready *.c
grep: No match.
[gingery@ca-fe pftool-new-test]$ grep message_ready */*.c
[gingery@ca-fe pftool-new-test]$ grep message_ready */*/*.c
src/pwt/converse.c:int message_ready(int local_rank) {
src/pwt/converse.c:	printf("converse::message_ready mpi_iprobe\n");
src/pwt/converse.c:	printf("converse::message_ready mpi_iprobe, is_message: %d\n", is_message);
src/pwt/manager.c:  int probecount = 0;							// count of calls to message_ready()
src/pwt/manager.c:	while(!message_ready(o.rank)) {					// loop to look for message - if no message ...
src/pwt/worker.c:	while(!message_ready(o.rank)) {
[gingery@ca-fe pftool-new-test]$ exit
logout
Connection to ca-fe closed.
[gingery@ccstargate ~]$ exit
logout
Connection to ccstargate closed.
kef-gay:~ gingery$ ssh ccstargate
gingery@ccstargate's password: 
Warning: untrusted X11 forwarding setup failed: xauth key data not generated
Warning: No xauth data; using fake authentication data for X11 forwarding.
Last login: Thu Feb 13 05:20:09 2014 from kef-gay.lanl.gov
[gingery@ccstargate ~]$ !sou
source ~/.cshrc.local_sv
Adding OpenShmem-1.0e_IBV
module: Command not found.
module: Command not found.
[gingery@ccstargate ~]$ !ss
ssh ca-fe
Last login: Thu Feb 13 10:46:38 2014 from 10.128.10.240
******************************************************************************
                              Notice to Users

This is a Federal computer system and is the property of the United
States Government.  It is for authorized used only.  Users (authorized or
unauthorized) have no explicit or implicit expectation of privacy.

Any or all uses of this system and all files on this system may be
intercepted, monitored, recorded, copied, audited, inspected, and disclosed
to authorized site, Department of Energy, and law enforcement personnel, as
well as authorized officials of other agencies, both domestic and foreign.
By using this system, the user consents to such interception, monitoring,
recording, copying, auditing, inspection, and disclosure at the discretion
of authorized site or Department of Energy personnel.

Unauthorized or improper use of this system may result in administrative
disciplinary action and civil and criminal penalties.  By continuing to
use this system you indicate your awareness of and consent to these terms
and conditions of use.  LOG OFF IMMEDIATELY if you do not agree to the
conditions stated in this warning.

******************************************************************************

[gingery@ca-fe ~]$ !sou
source ~/.cshrc.local_sv
Adding OpenShmem-1.0e_IBV
Currently Loaded Modulefiles:
  1) mvapich2-gnu-ofa/1.7
[gingery@ca-fe ~]$ wrk
[gingery@ca-fe src]$ cd ../
[gingery@ca-fe ~/mpi_to_openshmem]$ ls
./   English.lproj/  makefacs.pl*  mdhimMods/		    mpiCallsInMdhim.txt  mpi.h	 README.md
../  .git/	     Makefile	   mdhimNet-1.moved-aside/  mpidefs.h		 README  src/
[gingery@ca-fe ~/mpi_to_openshmem]$ cd mdh
mdhimMods/              mdhimNet-1.moved-aside/ 
[gingery@ca-fe ~/mpi_to_openshmem]$ cd mdhimMods/pf
pftool-new-test/        pftool-new-test.tar.gz  pftools.tar             pftool.tar 
[gingery@ca-fe ~/mpi_to_openshmem]$ cd mdhimMods/pftool
mdhimMods/pftool: No such file or directory.
[gingery@ca-fe ~/mpi_to_openshmem]$ cd mdhimMods/pftool-
pftool-new-test/        pftool-new-test.tar.gz  
[gingery@ca-fe ~/mpi_to_openshmem]$ cd mdhimMods/pftool-new-test
[gingery@ca-fe pftool-new-test]$ cd src/
[gingery@ca-fe src]$ more pf
pftool.c~      pftool.c       pftool.c.orig  pftool.h       
[gingery@ca-fe src]$ more pftool.c
pftool.c~      pftool.c       pftool.c.orig  
[gingery@ca-fe src]$ more pftool.c
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

[gingery@ca-fe src]$ exit
logout
Connection to ca-fe closed.
[gingery@ccstargate ~]$ exit
logout
Connection to ccstargate closed.
kef-gay:~ gingery$ ssh ccstargate
gingery@ccstargate's password: 
Warning: untrusted X11 forwarding setup failed: xauth key data not generated
Warning: No xauth data; using fake authentication data for X11 forwarding.
Last login: Thu Feb 13 10:46:30 2014 from jvpn-132-155.lanl.gov
[gingery@ccstargate ~]$ !ssh
ssh ca-fe
Last login: Tue Feb 18 05:19:59 2014 from 10.128.10.240
******************************************************************************
                              Notice to Users

This is a Federal computer system and is the property of the United
States Government.  It is for authorized used only.  Users (authorized or
unauthorized) have no explicit or implicit expectation of privacy.

Any or all uses of this system and all files on this system may be
intercepted, monitored, recorded, copied, audited, inspected, and disclosed
to authorized site, Department of Energy, and law enforcement personnel, as
well as authorized officials of other agencies, both domestic and foreign.
By using this system, the user consents to such interception, monitoring,
recording, copying, auditing, inspection, and disclosure at the discretion
of authorized site or Department of Energy personnel.

Unauthorized or improper use of this system may result in administrative
disciplinary action and civil and criminal penalties.  By continuing to
use this system you indicate your awareness of and consent to these terms
and conditions of use.  LOG OFF IMMEDIATELY if you do not agree to the
conditions stated in this warning.

******************************************************************************

[gingery@ca-fe ~]$ !sou
source ~/.cshrc.local_sv
Adding OpenShmem-1.0e_IBV
Currently Loaded Modulefiles:
  1) mvapich2-gnu-ofa/1.7
[gingery@ca-fe ~]$ wk
wk: Command not found.
[gingery@ca-fe ~]$ wrk
[gingery@ca-fe src]$ make
ar rvs libmpi_to_openshmem.a mpi_to_openshmem.o mlog.o 
r - mpi_to_openshmem.o
r - mlog.o
[gingery@ca-fe src]$ make
ar rvs libmpi_to_openshmem.a mpi_to_openshmem.o mlog.o 
r - mpi_to_openshmem.o
r - mlog.o
[gingery@ca-fe src]$ make
oshcc -g -O0 -Wall -c mpi_to_openshmem.c -I/users/gingery/openshmem-1.0e_IBV/include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/  -L/users/gingery/openshmem-1.0e_IBV/lib -L/users/gingery/GASNet-1.20.2_standard/lib  
mpi_to_openshmem.c: In function ‘MPI_Init’:
mpi_to_openshmem.c:101: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Init_thread’:
mpi_to_openshmem.c:192: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘CopyMyData’:
mpi_to_openshmem.c:332: warning: implicit declaration of function ‘memcpy’
mpi_to_openshmem.c:332: warning: incompatible implicit declaration of built-in function ‘memcpy’
mpi_to_openshmem.c: In function ‘GetBufferOffset’:
mpi_to_openshmem.c:422: warning: dereferencing ‘void *’ pointer
mpi_to_openshmem.c: In function ‘MPI_Comm_create’:
mpi_to_openshmem.c:644: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Comm_dup’:
mpi_to_openshmem.c:756: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Isend’:
mpi_to_openshmem.c:1983: warning: format ‘%x’ expects type ‘unsigned int’, but argument 4 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Iprobe’:
mpi_to_openshmem.c:2476: warning: implicit declaration of function ‘sleep’
ar rvs libmpi_to_openshmem.a mpi_to_openshmem.o mlog.o 
r - mpi_to_openshmem.o
r - mlog.o
[gingery@ca-fe src]$ wrks;make clean; make
rm -rf *.o libmdhim.a
oshcc -g -O0 -Wall -c Mlog/mlog.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c client.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c local_client.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c data_store.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c partitioner.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c messages.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c range_server.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c mdhim_options.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c ds_leveldb.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c mdhim.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
ar rvs libmdhim.a mdhim.o mlog.o client.o local_client.o data_store.o partitioner.o messages.o range_server.o mdhim_options.o ds_leveldb.o
ar: creating libmdhim.a
a - mdhim.o
a - mlog.o
a - client.o
a - local_client.o
a - data_store.o
a - partitioner.o
a - messages.o
a - range_server.o
a - mdhim_options.o
a - ds_leveldb.o
[gingery@ca-fe src]$ wtkt;make
wtkt: Command not found.
ar rvs libmdhim.a mdhim.o mlog.o client.o local_client.o data_store.o partitioner.o messages.o range_server.o mdhim_options.o ds_leveldb.o
r - mdhim.o
r - mlog.o
r - client.o
r - local_client.o
r - data_store.o
r - partitioner.o
r - messages.o
r - range_server.o
r - mdhim_options.o
r - ds_leveldb.o
[gingery@ca-fe src]$ wrkp
/users/gingery/mpi_to_openshmem/mdhimMods/pftool-new-test-pftool-new-test: No such file or directory.
[gingery@ca-fe src]$ emacs ~/.csh
.cshrc            .cshrc.local_sv~  .cshrc.local_sv   
[gingery@ca-fe src]$ emacs ~/.cshrc.
.cshrc.local_sv~  .cshrc.local_sv   
[gingery@ca-fe src]$ emacs ~/.cshrc
[gingery@ca-fe src]$ ls ~
./		  .emacs		   mpi_to_openshmem/	       README
../		  .emacs.d/		   mpiToOpenshmem/	       README_GN_RESULTS
authorized_keys   GASNet-1.20.2/	   mpi_to_openshmem.tar        README_TEST_RESULTS_GasNet_Standard
.bash_logout	  GASNet-1.20.2_standard/  openshmem-1.0d_IBV/	       .saves-2782-rrz-fe1.localdomain
.bash_profile	  GASNet-1.20.2.tar.gz	   openshmem-1.0d_SMP/	       src/
.bash_profile~	  .gitconfig		   openshmem-1.0d_UDP/	       .ssh/
.bashrc		  .gnome2/		   openshmem-1.0e_IBV/	       .texlive2007/
.bashrc~	  .history		   openshmem-1.0e_UDP/	       .viminfo
config.h	  .local_env_Linux~	   openshmem-release-1.0e.tar  .Xauthority
config.status*	  .local_env_Linux_save    openshmemReleases/	       .xemacs/
.cshrc		  mdhim-tng/		   openshmem.tar.gz	       y
.cshrc.local_sv   mdhim-tng.tar.gz	   openshmem-test-1.0b/        y.pub
.cshrc.local_sv~  mpidefs.h		   openshmemTest.tar.gz
doc/		  mpi.h			   pftools.tar
[gingery@ca-fe src]$ !sou
source ~/.cshrc.local_sv
Adding OpenShmem-1.0e_IBV
Currently Loaded Modulefiles:
  1) mvapich2-gnu-ofa/1.7
[gingery@ca-fe src]$ emacs ~/.cs
.cshrc            .cshrc.local_sv~  .cshrc.local_sv   
[gingery@ca-fe src]$ emacs ~/.cshrc.
.cshrc.local_sv~  .cshrc.local_sv   
[gingery@ca-fe src]$ emacs ~/.cshrc.local_sv
[gingery@ca-fe src]$ !sou
source ~/.cshrc.local_sv
Adding OpenShmem-1.0e_IBV
Currently Loaded Modulefiles:
  1) mvapich2-gnu-ofa/1.7
[gingery@ca-fe src]$ wrkp
[gingery@ca-fe pftool-new-test]$ make
make: Nothing to be done for `all'.
[gingery@ca-fe pftool-new-test]$ make clean
/bin/rm -f *~
/bin/rm -f *.o
/bin/rm -f *.x
/bin/rm -f pftool
[gingery@ca-fe pftool-new-test]$ make
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include  -L/usr/lib64 -L/users/gingery/mpi_to_openshmem/src -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++  -c src/pftool.c
gcc: /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so: linker input file unused because linking not done
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/str.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/perfstat.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/apps/cmp.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/apps/fchunktbl.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/apps/fileinfo.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/apps/pathinfo.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/workitem.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/workq.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/workreq.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/scheduler.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/converse.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/pwt.c
src/pwt/pwt.c: In function ‘set_pwt_instance_to_worker’:
src/pwt/pwt.c:56: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘int (*)(struct options)’
src/pwt/pwt.c:57: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘void (*)(struct options)’
src/pwt/pwt.c:58: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘int (*)(void)’
src/pwt/pwt.c: In function ‘set_pwt_instance_to_manager’:
src/pwt/pwt.c:69: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘int (*)(struct options)’
src/pwt/pwt.c:70: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘void (*)(struct options)’
src/pwt/pwt.c:71: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘int (*)(void)’
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/apps/treewalk.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/worker.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/manager.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -L -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib -L/usr/lib64 -L/users/gingery/mpi_to_openshmem/src -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++   pftool.o str.o perfstat.o cmp.o fchunktbl.o fileinfo.o pathinfo.o workitem.o workq.o workreq.o scheduler.o converse.o pwt.o treewalk.o worker.o manager.o  /users/gingery/mpi_to_openshmem/src/libmpi_to_openshmem.a /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -o pftool
[gingery@ca-fe pftool-new-test]$ wrkt
[gingery@ca-fe tests]$ emacs Makefile
[gingery@ca-fe tests]$ make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
make: *** No rule to make target `testSendRecv', needed by `all'.  Stop.
[gingery@ca-fe tests]$ wrk
[gingery@ca-fe src]$ more mpi
mpi_to_openshmem.c~  mpi_to_openshmem.c   mpi_to_openshmem.h~  mpi_to_openshmem.h   mpi_to_openshmem.o 
[gingery@ca-fe src]$ more mpi_to_openshmem.c
/*
 *  ! \mainpage mpi_to_openshmem.c
 *  mpi_to_openshmem 
 *
 *\section intro_sec Introduction
 *
 * mpi_to_openshmem is a library MDHIM TNG uses for its interface for parallel programming
 *
 *  Created on 9/23/13.
 *  Copyright 2013 LANL. All rights reserved.
 *
 */

#include "mpi_to_openshmem.h"

#define DEBUG 1

/**
 * MPI_Init
 * Initializes for Openshmem
 *
 * @param argc Pointer to the number of arguments 
 * @param argv Pointer to the argument vector 
 * @return status.
 */

int MPI_Init( int *argc, char ***argv ){

	int        i;
	int		   ret = MPI_SUCCESS;
	void       *sharedBuffer;
	MPID_Group *groupPtr;
	int		   *pesGroupPtr;
	
	//Open mlog - stolen from plfs
	ret = mlog_open((char *)"mpi_to_openshmem", 0, MLOG_CRIT, MLOG_CRIT, NULL, 0, MLOG_LOGPID, 0);
	
	start_pes(0);
	
	int npes =  _num_pes ();
	int my_pe = shmem_my_pe();
	
	// It is not threaded:
	isMultiThreads = FALSE;
	
	sharedBuffer = (void *)shmalloc(sizeof(char) * MAX_BUFFER_SIZE);
	if (sharedBuffer == NULL ){
		mlog(MPI_ERR, "MPI_Init:: PE: %d, could not shmalloc space for symmetric memory.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}

	if (shmem_addr_accessible( sharedBuffer, my_pe) ) {
		mlog(MPI_DBG, "MPI_Init::Buffer is in a symmetric segment for target pe: %d\n", my_pe);
	}else{
		mlog(MPI_ERR, "MPI_Init::Buffer is NOT in a symmetric segment for target pe: %d\n", my_pe);
		return MPI_ERR_BUFFER;
	}
	
	// Make space for the initial MPI_COMM_WORLD
	MPI_COMM_WORLD = (MPID_Comm *)shmalloc( sizeof(MPID_Comm) );
	if (MPI_COMM_WORLD == NULL ){
		mlog(MPI_ERR, "MPI_Init_thread:: PE: %d, could not shmalloc space for MPI_COMM_WORLD.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}

	// Make space for the initial group & initialize:
	groupPtr = (MPID_Group *)shmalloc(sizeof(MPID_Group));	
	if (groupPtr == NULL ){
		mlog(MPI_ERR, "MPI_Init:: PE: %d, could not shmalloc space for MPID_Group.\n", my_pe);
/tag:
...skipping
	}
#endif
	printf ("MPI_Recv: me: %d, tag: %d\n", my_pe,tag);
	
	switch (datatype){
		case MPI_CHAR:
		case MPI_UNSIGNED_CHAR:
		case MPI_BYTE:
		  shmem_getmem(buf, recv_buf, count, source);
		  break;
		case MPI_SHORT:
		case MPI_UNSIGNED_SHORT:
		  shmem_short_get(buf, recv_buf, count, source);
		  break;
		case MPI_INT:
		case MPI_UNSIGNED:
		  shmem_int_get(buf, recv_buf, count, source);
		  break;
		case MPI_LONG:
		case MPI_UNSIGNED_LONG:
		  shmem_long_get(buf, recv_buf, count, source);
		  break;
		case MPI_FLOAT:
		  shmem_float_get(buf, recv_buf, count, source);
		  break;
		case MPI_DOUBLE:
		  shmem_double_get(buf, recv_buf, count, source);
		  break;
		case MPI_LONG_DOUBLE:
		  shmem_longdouble_get(buf, recv_buf, count, source);
		  break;
		case MPI_LONG_LONG:
		  shmem_longlong_get(buf, recv_buf, count, source);
		  break;
		default:
		  shmem_getmem(buf, recv_buf, count, source);
			/** DEBUG **
			if (my_pe == 1){
				printf("MPI_Recv: pe: %d count: %d\n", my_pe, count);
				int i;
				for (i=0;i<count;i++){
					printf("MPI_Recv: pe: %d buf[] = %d\n", my_pe, ((char*) buf)[i]);
				}
			} **/
			break;
	}
	
	if (isMultiThreads){
		pthread_mutex_unlock(&lockRecv);
	}

	return ret;
}

/**
 * MPI_Send
 * Performs a blocking send
 *
 * @param 
 * @param  buf		initial address of send buffer (choice) 
 * @param  count	number of elements in send buffer (nonnegative integer) 
 * @param  datatype	datatype of each send buffer element (handle) 
 * @param  dest		rank of destination (integer) 
 * @param  tag		message tag (integer) 
 * @param  comm		communicator (handle) 
 *  
 * @return status
 */
[gingery@ca-fe src]$ erkt
erkt: Command not found.
[gingery@ca-fe src]$ wrkt
[gingery@ca-fe tests]$ make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
make: *** No rule to make target `testSendRecv', needed by `all'.  Stop.
[gingery@ca-fe tests]$ more Mak
Makefile~  Makefile   
[gingery@ca-fe tests]$ more Makefile
MPI_ROOT	= /usr/local
LEVEL_DB_ROOT   = /users/hng/leveldb-1.12.0
MDHIM_ROOT	 = /users/gingery/mdhim/src

MPI_TO_OPENSHMEM_ROOT	= /users/gingery/mpi_to_openshmem/src
OPENSHMEM_ROOT	= /users/gingery/openshmem-1.0e_IBV/
GASNET_ROOT	= /users/gingery/GASNet-1.20.2_standard

CC	= oshcc -g -O0 -Wall
CLIBS   =  -L../src -L${LEVEL_DB_ROOT} -L${MDHIM_ROOT} -L${MPI_TO_OPENSHMEM_ROOT} -L${OPENSHMEM_ROOT}/lib -L${GASNE
T_ROOT}/lib 
CINC    = -I${LEVEL_DB_ROOT}/include/leveldb -I${MDHIM_ROOT} -I${MPI_TO_OPENSHMEM_ROOT} -I${OPENSHMEM_ROOT}/include
 -I${GASNET_ROOT}/include -IMlog/ -Iuthash -I../src -I../src/uthash
#CLIBS	= -L${MPI_ROOT}/lib  -L../src -L${LEVEL_DB_ROOT}
#CINC	= -I${MPI_ROOT}/include -I${LEVEL_DB_ROOT}/include -IMlog/ -Iuthash -I../src -I../src/uthash
SINGLE = single_tests
TESTER = tester
CFLAGS	= -lmdhim -L/usr/lib64 -lmpi_to_openshmem ${OPENSHMEM_ROOT}/lib/libopenshmem.so -lgasnet-ibv-par -libverbs 
-lm -lpthread -lstdc++ ${LEVEL_DB_ROOT}/libleveldb.a
#CFLAGS  = -lmpich -lmdhim -lm -lpthread -lstdc++ ${LEVEL_DB_ROOT}/libleveldb.a

#all:	put-getn startPesExample broadcast1 testStart testSendRcv sendRcvChar isendiRecv gather allgather gatherv m
pi_test_int mpi_test_char mpi_test mpi_packs groups

all: lock testSendRecv #mpi_packs isendiRecv  broadcast1 allgather gather gatherv

put-getn: $(SINGLE)/put-getn.c
	$(CC) $< $(CINC) $(CLIBS) $(CFLAGS) -o $(SINGLE)/$@

startPesExample: $(SINGLE)/startPesExample.c
	$(CC) $< $(CINC) $(CLIBS) $(CFLAGS) -o $(SINGLE)/$@

testStart: $(SINGLE)/testStart.c
	$(CC) $< $(CINC) $(CLIBS) $(CFLAGS) -o $(SINGLE)/$@

broadcastExample: $(SINGLE)/broadcastExample.c
	$(CC) $< $(CINC) $(CLIBS) $(CFLAGS) -o $(SINGLE)/$@

broadcast1: $(SINGLE)/broadcast1.c
	$(CC) $< $(CINC) $(CLIBS) $(CFLAGS) -o $(SINGLE)/$@

testSendRcv: $(SINGLE)/testSendRcv.c
	$(CC) $< $(CINC) $(CLIBS) $(CFLAGS) -o $(SINGLE)/$@

sendRcvChar: $(SINGLE)/sendRcvChar.c
	$(CC) $< $(CINC) $(CLIBS) $(CFLAGS) -o $(SINGLE)/$@

isendiRecv: $(SINGLE)/isendiRecv.c
	$(CC) $< $(CINC) $(CLIBS) $(CFLAGS) -o $(SINGLE)/$@

allgather: $(SINGLE)/allgather.c
	$(CC) $< $(CINC) $(CLIBS) $(CFLAGS) -o $(SINGLE)/$@

gather: $(SINGLE)/gather.c
	$(CC) $< $(CINC) $(CLIBS) $(CFLAGS) -o $(SINGLE)/$@

gatherv: $(SINGLE)/gatherv.c
	$(CC) $< $(CINC) $(CLIBS) $(CFLAGS) -o $(SINGLE)/$@

mpi_test_int: $(SINGLE)/mpi_test_int.c
	$(CC) $< $(CINC) $(CLIBS) $(CFLAGS) -o $(SINGLE)/$@

mpi_test_char: $(SINGLE)/mpi_test_char.c
	$(CC) $< $(CINC) $(CLIBS) $(CFLAGS) -o $(SINGLE)/$@

mpi_test: $(SINGLE)/mpi_test.c
	$(CC) $< $(CINC) $(CLIBS) $(CFLAGS) -o $(SINGLE)/$@

mpi_packsExample: $(SINGLE)/mpi_packsExample.c
[gingery@ca-fe tests]$ emacs Makefile
[gingery@ca-fe tests]$ make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
oshcc -g -O0 -Wall single_tests/testSendRcv.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/testSendRcv
[gingery@ca-fe tests]$ wrkp
[gingery@ca-fe pftool-new-test]$ make
make: Nothing to be done for `all'.
[gingery@ca-fe pftool-new-test]$ make clean
/bin/rm -f *~
/bin/rm -f *.o
/bin/rm -f *.x
/bin/rm -f pftool
[gingery@ca-fe pftool-new-test]$ make
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include  -L/usr/lib64 -L/users/gingery/mpi_to_openshmem/src -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++  -c src/pftool.c
gcc: /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so: linker input file unused because linking not done
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/str.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/perfstat.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/apps/cmp.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/apps/fchunktbl.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/apps/fileinfo.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/apps/pathinfo.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/workitem.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/workq.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/workreq.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/scheduler.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/converse.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/pwt.c
src/pwt/pwt.c: In function ‘set_pwt_instance_to_worker’:
src/pwt/pwt.c:56: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘int (*)(struct options)’
src/pwt/pwt.c:57: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘void (*)(struct options)’
src/pwt/pwt.c:58: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘int (*)(void)’
src/pwt/pwt.c: In function ‘set_pwt_instance_to_manager’:
src/pwt/pwt.c:69: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘int (*)(struct options)’
src/pwt/pwt.c:70: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘void (*)(struct options)’
src/pwt/pwt.c:71: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘int (*)(void)’
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/apps/treewalk.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/worker.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/manager.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -L -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib -L/usr/lib64 -L/users/gingery/mpi_to_openshmem/src -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++   pftool.o str.o perfstat.o cmp.o fchunktbl.o fileinfo.o pathinfo.o workitem.o workq.o workreq.o scheduler.o converse.o pwt.o treewalk.o worker.o manager.o  /users/gingery/mpi_to_openshmem/src/libmpi_to_openshmem.a /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -o pftool
[gingery@ca-fe pftool-new-test]$ emacs src/p
pftool.c~      pftool.c       pftool.c.orig  pftool.h       pwt/           
[gingery@ca-fe pftool-new-test]$ emacs src/pwt/co
converse.c~  converse.c   converse.h   
[gingery@ca-fe pftool-new-test]$ emacs src/pwt/converse.c
[gingery@ca-fe pftool-new-test]$ make
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include  -L/usr/lib64 -L/users/gingery/mpi_to_openshmem/src -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++  -c src/pftool.c
gcc: /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so: linker input file unused because linking not done
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -L -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib -L/usr/lib64 -L/users/gingery/mpi_to_openshmem/src -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++   pftool.o str.o perfstat.o cmp.o fchunktbl.o fileinfo.o pathinfo.o workitem.o workq.o workreq.o scheduler.o converse.o pwt.o treewalk.o worker.o manager.o  /users/gingery/mpi_to_openshmem/src/libmpi_to_openshmem.a /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -o pftool
[gingery@ca-fe pftool-new-test]$ wrk
[gingery@ca-fe src]$ make
oshcc -g -O0 -Wall -c mpi_to_openshmem.c -I/users/gingery/openshmem-1.0e_IBV/include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/  -L/users/gingery/openshmem-1.0e_IBV/lib -L/users/gingery/GASNet-1.20.2_standard/lib  
mpi_to_openshmem.c: In function ‘MPI_Init’:
mpi_to_openshmem.c:101: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Init_thread’:
mpi_to_openshmem.c:192: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘CopyMyData’:
mpi_to_openshmem.c:332: warning: implicit declaration of function ‘memcpy’
mpi_to_openshmem.c:332: warning: incompatible implicit declaration of built-in function ‘memcpy’
mpi_to_openshmem.c: In function ‘GetBufferOffset’:
mpi_to_openshmem.c:422: warning: dereferencing ‘void *’ pointer
mpi_to_openshmem.c: In function ‘MPI_Comm_create’:
mpi_to_openshmem.c:644: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Comm_dup’:
mpi_to_openshmem.c:756: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Isend’:
mpi_to_openshmem.c:1983: warning: format ‘%x’ expects type ‘unsigned int’, but argument 4 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Iprobe’:
mpi_to_openshmem.c:2476: warning: implicit declaration of function ‘sleep’
ar rvs libmpi_to_openshmem.a mpi_to_openshmem.o mlog.o 
r - mpi_to_openshmem.o
r - mlog.o
[gingery@ca-fe src]$ wrks ; make clean ; make
rm -rf *.o libmdhim.a
oshcc -g -O0 -Wall -c Mlog/mlog.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c client.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c local_client.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c data_store.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c partitioner.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c messages.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c range_server.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c mdhim_options.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c ds_leveldb.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c mdhim.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
ar rvs libmdhim.a mdhim.o mlog.o client.o local_client.o data_store.o partitioner.o messages.o range_server.o mdhim_options.o ds_leveldb.o
ar: creating libmdhim.a
a - mdhim.o
a - mlog.o
a - client.o
a - local_client.o
a - data_store.o
a - partitioner.o
a - messages.o
a - range_server.o
a - mdhim_options.o
a - ds_leveldb.o
[gingery@ca-fe src]$ wrkt;make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
oshcc -g -O0 -Wall single_tests/testSendRcv.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/testSendRcv
[gingery@ca-fe tests]$ wrkp;make
make: Nothing to be done for `all'.
[gingery@ca-fe pftool-new-test]$ make clean
/bin/rm -f *~
/bin/rm -f *.o
/bin/rm -f *.x
/bin/rm -f pftool
[gingery@ca-fe pftool-new-test]$ make
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include  -L/usr/lib64 -L/users/gingery/mpi_to_openshmem/src -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++  -c src/pftool.c
gcc: /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so: linker input file unused because linking not done
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/str.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/perfstat.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/apps/cmp.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/apps/fchunktbl.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/apps/fileinfo.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/apps/pathinfo.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/workitem.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/workq.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/workreq.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/scheduler.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/converse.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/pwt.c
src/pwt/pwt.c: In function ‘set_pwt_instance_to_worker’:
src/pwt/pwt.c:56: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘int (*)(struct options)’
src/pwt/pwt.c:57: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘void (*)(struct options)’
src/pwt/pwt.c:58: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘int (*)(void)’
src/pwt/pwt.c: In function ‘set_pwt_instance_to_manager’:
src/pwt/pwt.c:69: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘int (*)(struct options)’
src/pwt/pwt.c:70: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘void (*)(struct options)’
src/pwt/pwt.c:71: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘int (*)(void)’
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/apps/treewalk.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/worker.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/manager.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -L -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib -L/usr/lib64 -L/users/gingery/mpi_to_openshmem/src -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++   pftool.o str.o perfstat.o cmp.o fchunktbl.o fileinfo.o pathinfo.o workitem.o workq.o workreq.o scheduler.o converse.o pwt.o treewalk.o worker.o manager.o  /users/gingery/mpi_to_openshmem/src/libmpi_to_openshmem.a /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -o pftool
[gingery@ca-fe pftool-new-test]$ emacs pft
pftool*   pftool.o  
[gingery@ca-fe pftool-new-test]$ emacs src/pf
pftool.c~      pftool.c       pftool.c.orig  pftool.h       
[gingery@ca-fe pftool-new-test]$ emacs src/pftool.c
[gingery@ca-fe pftool-new-test]$ make clean
/bin/rm -f *~
/bin/rm -f *.o
/bin/rm -f *.x
/bin/rm -f pftool
[gingery@ca-fe pftool-new-test]$ make
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include  -L/usr/lib64 -L/users/gingery/mpi_to_openshmem/src -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++  -c src/pftool.c
gcc: /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so: linker input file unused because linking not done
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/str.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/perfstat.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/apps/cmp.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/apps/fchunktbl.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/apps/fileinfo.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/apps/pathinfo.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/workitem.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/workq.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/workreq.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/scheduler.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/converse.c
src/pwt/converse.c: In function ‘get_workitem’:
src/pwt/converse.c:74: error: ‘null’ undeclared (first use in this function)
src/pwt/converse.c:74: error: (Each undeclared identifier is reported only once
src/pwt/converse.c:74: error: for each function it appears in.)
make: *** [converse.o] Error 1
[gingery@ca-fe pftool-new-test]$ emacs src/pwt/con
converse.c~  converse.c   converse.h   
[gingery@ca-fe pftool-new-test]$ emacs src/pwt/converse.c
[gingery@ca-fe pftool-new-test]$ make
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/converse.c
src/pwt/converse.c: In function ‘get_workitem’:
src/pwt/converse.c:73: warning: ‘orig_rank’ is used uninitialized in this function
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/pwt.c
src/pwt/pwt.c: In function ‘set_pwt_instance_to_worker’:
src/pwt/pwt.c:56: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘int (*)(struct options)’
src/pwt/pwt.c:57: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘void (*)(struct options)’
src/pwt/pwt.c:58: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘int (*)(void)’
src/pwt/pwt.c: In function ‘set_pwt_instance_to_manager’:
src/pwt/pwt.c:69: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘int (*)(struct options)’
src/pwt/pwt.c:70: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘void (*)(struct options)’
src/pwt/pwt.c:71: warning: format ‘%d’ expects type ‘int’, but argument 2 has type ‘int (*)(void)’
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/apps/treewalk.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/worker.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/manager.c
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -L -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib -L/usr/lib64 -L/users/gingery/mpi_to_openshmem/src -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++   pftool.o str.o perfstat.o cmp.o fchunktbl.o fileinfo.o pathinfo.o workitem.o workq.o workreq.o scheduler.o converse.o pwt.o treewalk.o worker.o manager.o  /users/gingery/mpi_to_openshmem/src/libmpi_to_openshmem.a /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -o pftool
[gingery@ca-fe pftool-new-test]$ Read from remote host ccstargate: Connection reset by peer
Connection to ccstargate closed.
kef-gay:~ gingery$ ssh ccstargate
gingery@ccstargate's password: 
Warning: untrusted X11 forwarding setup failed: xauth key data not generated
Warning: No xauth data; using fake authentication data for X11 forwarding.
Last login: Wed Feb 19 05:08:24 2014 from kef-gay.lanl.gov
[gingery@ccstargate ~]$ !ssh
ssh ca-fe
Last login: Wed Feb 19 05:08:30 2014 from 10.128.10.240
******************************************************************************
                              Notice to Users

This is a Federal computer system and is the property of the United
States Government.  It is for authorized used only.  Users (authorized or
unauthorized) have no explicit or implicit expectation of privacy.

Any or all uses of this system and all files on this system may be
intercepted, monitored, recorded, copied, audited, inspected, and disclosed
to authorized site, Department of Energy, and law enforcement personnel, as
well as authorized officials of other agencies, both domestic and foreign.
By using this system, the user consents to such interception, monitoring,
recording, copying, auditing, inspection, and disclosure at the discretion
of authorized site or Department of Energy personnel.

Unauthorized or improper use of this system may result in administrative
disciplinary action and civil and criminal penalties.  By continuing to
use this system you indicate your awareness of and consent to these terms
and conditions of use.  LOG OFF IMMEDIATELY if you do not agree to the
conditions stated in this warning.

******************************************************************************

[gingery@ca-fe ~]$ !sou
source ~/.cshrc.local_sv
Adding OpenShmem-1.0e_IBV
Currently Loaded Modulefiles:
  1) mvapich2-gnu-ofa/1.7
[gingery@ca-fe ~]$ wrkp
[gingery@ca-fe pftool-new-test]$ emacs src/pwt/wo
worker.c~   worker.c    worker.h    workitem.c  workitem.h  workq.c     workq.h     workreq.c   workreq.h 
[gingery@ca-fe pftool-new-test]$ emacs src/pwt/worke
worker.c~  worker.c   worker.h   
[gingery@ca-fe pftool-new-test]$ emacs src/pwt/worker.c
[gingery@ca-fe pftool-new-test]$ make
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include   -c src/pwt/worker.c
src/pwt/worker.c: In function ‘worker_run’:
src/pwt/worker.c:48: warning: statement with no effect
oshcc -g -O0 -Wall -I -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -L -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib -L/usr/lib64 -L/users/gingery/mpi_to_openshmem/src -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++   pftool.o str.o perfstat.o cmp.o fchunktbl.o fileinfo.o pathinfo.o workitem.o workq.o workreq.o scheduler.o converse.o pwt.o treewalk.o worker.o manager.o  /users/gingery/mpi_to_openshmem/src/libmpi_to_openshmem.a /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -o pftool
[gingery@ca-fe pftool-new-test]$ wrkt
[gingery@ca-fe tests]$ emacs Makefile
[gingery@ca-fe tests]$ make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
oshcc -g -O0 -Wall single_tests/testMultiSendRcv.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/testMultiSendRcv
single_tests/testMultiSendRcv.c: In function ‘main’:
single_tests/testMultiSendRcv.c:74: error: expected ‘)’ before ‘}’ token
single_tests/testMultiSendRcv.c:74: warning: format ‘%ld’ expects type ‘long int’, but argument 5 has type ‘long int *’
single_tests/testMultiSendRcv.c:74: error: expected ‘;’ before ‘}’ token
make: *** [testMultiSendRcv] Error 1
[gingery@ca-fe tests]$ make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
oshcc -g -O0 -Wall single_tests/testMultiSendRcv.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/testMultiSendRcv
single_tests/testMultiSendRcv.c: In function ‘main’:
single_tests/testMultiSendRcv.c:74: error: expected ‘)’ before ‘}’ token
single_tests/testMultiSendRcv.c:74: warning: format ‘%ld’ expects type ‘long int’, but argument 5 has type ‘long int *’
single_tests/testMultiSendRcv.c:74: error: expected ‘;’ before ‘}’ token
make: *** [testMultiSendRcv] Error 1
[gingery@ca-fe tests]$ make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
oshcc -g -O0 -Wall single_tests/testMultiSendRcv.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/testMultiSendRcv
single_tests/testMultiSendRcv.c: In function ‘main’:
single_tests/testMultiSendRcv.c:74: error: expected ‘)’ before ‘}’ token
single_tests/testMultiSendRcv.c:74: error: expected ‘;’ before ‘}’ token
make: *** [testMultiSendRcv] Error 1
[gingery@ca-fe tests]$ make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
oshcc -g -O0 -Wall single_tests/testMultiSendRcv.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/testMultiSendRcv
[gingery@ca-fe tests]$ 
[gingery@ca-fe tests]$ 
[gingery@ca-fe tests]$ 
[gingery@ca-fe tests]$ exit
logout
Connection to ca-fe closed.
[gingery@ccstargate ~]$ exit
logout
Connection to ccstargate closed.
kef-gay:~ gingery$ ssh ccstargate
gingery@ccstargate's password: 
Warning: untrusted X11 forwarding setup failed: xauth key data not generated
Warning: No xauth data; using fake authentication data for X11 forwarding.
Last login: Wed Feb 19 05:08:44 2014 from kef-gay.lanl.gov
[gingery@ccstargate ~]$ ~/GASNet-1.20.2_standard/bin/gasnetrun_ibv -n3 -- ./testMultiSendRcv
[gingery@ccstargate ~]$ !ssh
ssh ca-fe
Last login: Wed Feb 19 05:08:50 2014 from 10.128.10.240
******************************************************************************
                              Notice to Users

This is a Federal computer system and is the property of the United
States Government.  It is for authorized used only.  Users (authorized or
unauthorized) have no explicit or implicit expectation of privacy.

Any or all uses of this system and all files on this system may be
intercepted, monitored, recorded, copied, audited, inspected, and disclosed
to authorized site, Department of Energy, and law enforcement personnel, as
well as authorized officials of other agencies, both domestic and foreign.
By using this system, the user consents to such interception, monitoring,
recording, copying, auditing, inspection, and disclosure at the discretion
of authorized site or Department of Energy personnel.

Unauthorized or improper use of this system may result in administrative
disciplinary action and civil and criminal penalties.  By continuing to
use this system you indicate your awareness of and consent to these terms
and conditions of use.  LOG OFF IMMEDIATELY if you do not agree to the
conditions stated in this warning.

******************************************************************************

[gingery@ca-fe ~]$ 
[gingery@ca-fe ~]$ !sou
source ~/.cshrc.local_sv
Adding OpenShmem-1.0e_IBV
Currently Loaded Modulefiles:
  1) mvapich2-gnu-ofa/1.7
[gingery@ca-fe ~]$ wrk
[gingery@ca-fe src]$ wrk
[gingery@ca-fe src]$ make
oshcc -g -O0 -Wall -c mpi_to_openshmem.c -I/users/gingery/openshmem-1.0e_IBV/include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/  -L/users/gingery/openshmem-1.0e_IBV/lib -L/users/gingery/GASNet-1.20.2_standard/lib  
In file included from mpi_to_openshmem.c:14:
mpi_to_openshmem.h:99: error: expected ‘{’ before ‘(’ token
mpi_to_openshmem.h:115: error: expected ‘:’, ‘,’, ‘;’, ‘}’ or ‘__attribute__’ before ‘void’
mpi_to_openshmem.c: In function ‘MPI_Init’:
mpi_to_openshmem.c:101: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Init_thread’:
mpi_to_openshmem.c:192: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘CopyMyData’:
mpi_to_openshmem.c:332: warning: implicit declaration of function ‘memcpy’
mpi_to_openshmem.c:332: warning: incompatible implicit declaration of built-in function ‘memcpy’
mpi_to_openshmem.c: In function ‘GetBufferOffset’:
mpi_to_openshmem.c:422: warning: dereferencing ‘void *’ pointer
mpi_to_openshmem.c: In function ‘MPI_Comm_create’:
mpi_to_openshmem.c:644: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Comm_dup’:
mpi_to_openshmem.c:756: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Irecv’:
mpi_to_openshmem.c:1922: error: ‘RECEIVE_TYPE’ undeclared (first use in this function)
mpi_to_openshmem.c:1922: error: (Each undeclared identifier is reported only once
mpi_to_openshmem.c:1922: error: for each function it appears in.)
mpi_to_openshmem.c: In function ‘MPI_Isend’:
mpi_to_openshmem.c:1983: warning: format ‘%x’ expects type ‘unsigned int’, but argument 4 has type ‘void *’
mpi_to_openshmem.c:2099: error: ‘SEND_TYPE’ undeclared (first use in this function)
mpi_to_openshmem.c: In function ‘MPI_Iprobe’:
mpi_to_openshmem.c:2476: warning: implicit declaration of function ‘sleep’
make: *** [mpi_to_openshmem.o] Error 1
[gingery@ca-fe src]$ make
oshcc -g -O0 -Wall -c mpi_to_openshmem.c -I/users/gingery/openshmem-1.0e_IBV/include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/  -L/users/gingery/openshmem-1.0e_IBV/lib -L/users/gingery/GASNet-1.20.2_standard/lib  
In file included from mpi_to_openshmem.c:14:
mpi_to_openshmem.h:99: error: expected ‘{’ before ‘(’ token
mpi_to_openshmem.h:115: error: expected ‘:’, ‘,’, ‘;’, ‘}’ or ‘__attribute__’ before ‘void’
mpi_to_openshmem.c: In function ‘MPI_Init’:
mpi_to_openshmem.c:101: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Init_thread’:
mpi_to_openshmem.c:192: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘GetNumBytes’:
mpi_to_openshmem.c:282: error: ‘lockGetNumBytes’ undeclared (first use in this function)
mpi_to_openshmem.c:282: error: (Each undeclared identifier is reported only once
mpi_to_openshmem.c:282: error: for each function it appears in.)
mpi_to_openshmem.c:320: error: ‘ret’ undeclared (first use in this function)
mpi_to_openshmem.c: In function ‘CopyMyData’:
mpi_to_openshmem.c:357: warning: implicit declaration of function ‘memcpy’
mpi_to_openshmem.c:357: warning: incompatible implicit declaration of built-in function ‘memcpy’
mpi_to_openshmem.c: In function ‘GetBufferOffset’:
mpi_to_openshmem.c:416: warning: dereferencing ‘void *’ pointer
mpi_to_openshmem.c: In function ‘MPI_Bcast’:
mpi_to_openshmem.c:522: warning: implicit declaration of function ‘shmem_free’
mpi_to_openshmem.c: In function ‘MPI_Comm_create’:
mpi_to_openshmem.c:647: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Comm_dup’:
mpi_to_openshmem.c:759: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Irecv’:
mpi_to_openshmem.c:1925: error: ‘IRECV’ undeclared (first use in this function)
mpi_to_openshmem.c: In function ‘MPI_Isend’:
mpi_to_openshmem.c:1986: warning: format ‘%x’ expects type ‘unsigned int’, but argument 4 has type ‘void *’
mpi_to_openshmem.c:2102: error: ‘ISEND’ undeclared (first use in this function)
mpi_to_openshmem.c: In function ‘MPI_Iprobe’:
mpi_to_openshmem.c:2479: warning: implicit declaration of function ‘sleep’
make: *** [mpi_to_openshmem.o] Error 1
[gingery@ca-fe src]$ make
oshcc -g -O0 -Wall -c mpi_to_openshmem.c -I/users/gingery/openshmem-1.0e_IBV/include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/  -L/users/gingery/openshmem-1.0e_IBV/lib -L/users/gingery/GASNet-1.20.2_standard/lib  
In file included from mpi_to_openshmem.c:14:
mpi_to_openshmem.h:99: error: expected ‘{’ before ‘(’ token
mpi_to_openshmem.h:115: error: expected ‘:’, ‘,’, ‘;’, ‘}’ or ‘__attribute__’ before ‘void’
mpi_to_openshmem.h:130: error: expected specifier-qualifier-list before ‘requestType_t’
mpi_to_openshmem.c: In function ‘MPI_Init’:
mpi_to_openshmem.c:101: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Init_thread’:
mpi_to_openshmem.c:192: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘GetNumBytes’:
mpi_to_openshmem.c:282: error: ‘lockGetNumBytes’ undeclared (first use in this function)
mpi_to_openshmem.c:282: error: (Each undeclared identifier is reported only once
mpi_to_openshmem.c:282: error: for each function it appears in.)
mpi_to_openshmem.c:320: error: ‘ret’ undeclared (first use in this function)
mpi_to_openshmem.c: In function ‘CopyMyData’:
mpi_to_openshmem.c:357: warning: implicit declaration of function ‘memcpy’
mpi_to_openshmem.c:357: warning: incompatible implicit declaration of built-in function ‘memcpy’
mpi_to_openshmem.c: In function ‘GetBufferOffset’:
mpi_to_openshmem.c:416: warning: dereferencing ‘void *’ pointer
mpi_to_openshmem.c: In function ‘MPI_Bcast’:
mpi_to_openshmem.c:522: warning: implicit declaration of function ‘shmem_free’
mpi_to_openshmem.c: In function ‘MPI_Comm_create’:
mpi_to_openshmem.c:647: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Comm_dup’:
mpi_to_openshmem.c:759: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Irecv’:
mpi_to_openshmem.c:1885: error: ‘MPI_Request’ has no member named ‘expected’
mpi_to_openshmem.c:1886: error: ‘MPI_Request’ has no member named ‘lastBufPtr’
mpi_to_openshmem.c:1924: error: ‘MPI_Request’ has no member named ‘expected’
mpi_to_openshmem.c:1924: error: ‘MPI_Request’ has no member named ‘lastBufPtr’
mpi_to_openshmem.c:1925: error: ‘MPI_Request’ has no member named ‘requestType’
mpi_to_openshmem.c:1925: error: ‘IRECV’ undeclared (first use in this function)
mpi_to_openshmem.c:1926: error: ‘MPI_Request’ has no member named ‘rank’
mpi_to_openshmem.c:1927: error: ‘MPI_Request’ has no member named ‘dataType’
mpi_to_openshmem.c: In function ‘MPI_Isend’:
mpi_to_openshmem.c:1986: warning: format ‘%x’ expects type ‘unsigned int’, but argument 4 has type ‘void *’
mpi_to_openshmem.c:2015: error: ‘MPI_Request’ has no member named ‘expected’
mpi_to_openshmem.c:2016: error: ‘MPI_Request’ has no member named ‘expected’
mpi_to_openshmem.c:2099: error: ‘MPI_Request’ has no member named ‘lastBufPtr’
mpi_to_openshmem.c:2102: error: ‘MPI_Request’ has no member named ‘requestType’
mpi_to_openshmem.c:2102: error: ‘ISEND’ undeclared (first use in this function)
mpi_to_openshmem.c:2103: error: ‘MPI_Request’ has no member named ‘rank’
mpi_to_openshmem.c:2104: error: ‘MPI_Request’ has no member named ‘dataType’
mpi_to_openshmem.c: In function ‘MPI_Test’:
mpi_to_openshmem.c:2428: error: ‘MPI_Request’ has no member named ‘lastBufPtr’
mpi_to_openshmem.c:2428: error: ‘MPI_Request’ has no member named ‘expected’
mpi_to_openshmem.c:2428: error: ‘MPI_Request’ has no member named ‘expected’
mpi_to_openshmem.c:2428: error: ‘MPI_Request’ has no member named ‘rank’
mpi_to_openshmem.c:2430: error: ‘MPI_Request’ has no member named ‘expected’
mpi_to_openshmem.c: In function ‘MPI_Iprobe’:
mpi_to_openshmem.c:2479: warning: implicit declaration of function ‘sleep’
make: *** [mpi_to_openshmem.o] Error 1
[gingery@ca-fe src]$ emacs mpi
mpi_to_openshmem.c~  mpi_to_openshmem.c   mpi_to_openshmem.h~  mpi_to_openshmem.h   mpi_to_openshmem.o 
[gingery@ca-fe src]$ emacs mpi_to_openshmem.h
[gingery@ca-fe src]$ make
oshcc -g -O0 -Wall -c mpi_to_openshmem.c -I/users/gingery/openshmem-1.0e_IBV/include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/  -L/users/gingery/openshmem-1.0e_IBV/lib -L/users/gingery/GASNet-1.20.2_standard/lib  
In file included from mpi_to_openshmem.c:14:
mpi_to_openshmem.h:115: error: expected ‘:’, ‘,’, ‘;’, ‘}’ or ‘__attribute__’ before ‘void’
mpi_to_openshmem.c: In function ‘MPI_Init’:
mpi_to_openshmem.c:101: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Init_thread’:
mpi_to_openshmem.c:192: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘GetNumBytes’:
mpi_to_openshmem.c:282: error: ‘lockGetNumBytes’ undeclared (first use in this function)
mpi_to_openshmem.c:282: error: (Each undeclared identifier is reported only once
mpi_to_openshmem.c:282: error: for each function it appears in.)
mpi_to_openshmem.c:320: error: ‘ret’ undeclared (first use in this function)
mpi_to_openshmem.c: In function ‘CopyMyData’:
mpi_to_openshmem.c:357: warning: implicit declaration of function ‘memcpy’
mpi_to_openshmem.c:357: warning: incompatible implicit declaration of built-in function ‘memcpy’
mpi_to_openshmem.c: In function ‘GetBufferOffset’:
mpi_to_openshmem.c:416: warning: dereferencing ‘void *’ pointer
mpi_to_openshmem.c: In function ‘MPI_Bcast’:
mpi_to_openshmem.c:522: warning: implicit declaration of function ‘shmem_free’
mpi_to_openshmem.c: In function ‘MPI_Comm_create’:
mpi_to_openshmem.c:647: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Comm_dup’:
mpi_to_openshmem.c:759: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Isend’:
mpi_to_openshmem.c:1986: warning: format ‘%x’ expects type ‘unsigned int’, but argument 4 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Iprobe’:
mpi_to_openshmem.c:2479: warning: implicit declaration of function ‘sleep’
make: *** [mpi_to_openshmem.o] Error 1
[gingery@ca-fe src]$ make
oshcc -g -O0 -Wall -c mpi_to_openshmem.c -I/users/gingery/openshmem-1.0e_IBV/include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/  -L/users/gingery/openshmem-1.0e_IBV/lib -L/users/gingery/GASNet-1.20.2_standard/lib  
In file included from mpi_to_openshmem.c:14:
mpi_to_openshmem.h:115: error: expected ‘:’, ‘,’, ‘;’, ‘}’ or ‘__attribute__’ before ‘void’
mpi_to_openshmem.c: In function ‘MPI_Init’:
mpi_to_openshmem.c:101: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Init_thread’:
mpi_to_openshmem.c:192: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘GetNumBytes’:
mpi_to_openshmem.c:320: error: ‘ret’ undeclared (first use in this function)
mpi_to_openshmem.c:320: error: (Each undeclared identifier is reported only once
mpi_to_openshmem.c:320: error: for each function it appears in.)
mpi_to_openshmem.c: In function ‘CopyMyData’:
mpi_to_openshmem.c:357: warning: implicit declaration of function ‘memcpy’
mpi_to_openshmem.c:357: warning: incompatible implicit declaration of built-in function ‘memcpy’
mpi_to_openshmem.c: In function ‘GetBufferOffset’:
mpi_to_openshmem.c:416: warning: dereferencing ‘void *’ pointer
mpi_to_openshmem.c: In function ‘MPI_Bcast’:
mpi_to_openshmem.c:522: warning: implicit declaration of function ‘shmem_free’
mpi_to_openshmem.c: In function ‘MPI_Comm_create’:
mpi_to_openshmem.c:647: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Comm_dup’:
mpi_to_openshmem.c:759: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Isend’:
mpi_to_openshmem.c:1986: warning: format ‘%x’ expects type ‘unsigned int’, but argument 4 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Iprobe’:
mpi_to_openshmem.c:2479: warning: implicit declaration of function ‘sleep’
make: *** [mpi_to_openshmem.o] Error 1
[gingery@ca-fe src]$ make
oshcc -g -O0 -Wall -c mpi_to_openshmem.c -I/users/gingery/openshmem-1.0e_IBV/include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/  -L/users/gingery/openshmem-1.0e_IBV/lib -L/users/gingery/GASNet-1.20.2_standard/lib  
In file included from mpi_to_openshmem.c:14:
mpi_to_openshmem.h:115: error: expected ‘:’, ‘,’, ‘;’, ‘}’ or ‘__attribute__’ before ‘void’
mpi_to_openshmem.c: In function ‘MPI_Init’:
mpi_to_openshmem.c:101: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Init_thread’:
mpi_to_openshmem.c:192: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘CopyMyData’:
mpi_to_openshmem.c:359: warning: implicit declaration of function ‘memcpy’
mpi_to_openshmem.c:359: warning: incompatible implicit declaration of built-in function ‘memcpy’
mpi_to_openshmem.c: In function ‘GetBufferOffset’:
mpi_to_openshmem.c:418: warning: dereferencing ‘void *’ pointer
mpi_to_openshmem.c: In function ‘MPI_Bcast’:
mpi_to_openshmem.c:524: warning: implicit declaration of function ‘shmem_free’
mpi_to_openshmem.c: In function ‘MPI_Comm_create’:
mpi_to_openshmem.c:649: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Comm_dup’:
mpi_to_openshmem.c:761: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Isend’:
mpi_to_openshmem.c:1988: warning: format ‘%x’ expects type ‘unsigned int’, but argument 4 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Iprobe’:
mpi_to_openshmem.c:2481: warning: implicit declaration of function ‘sleep’
make: *** [mpi_to_openshmem.o] Error 1
[gingery@ca-fe src]$ emacs mpi_to_openshmem.h
[gingery@ca-fe src]$ make
oshcc -g -O0 -Wall -c mpi_to_openshmem.c -I/users/gingery/openshmem-1.0e_IBV/include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/  -L/users/gingery/openshmem-1.0e_IBV/lib -L/users/gingery/GASNet-1.20.2_standard/lib  
mpi_to_openshmem.c: In function ‘MPI_Init’:
mpi_to_openshmem.c:101: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Init_thread’:
mpi_to_openshmem.c:192: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘CopyMyData’:
mpi_to_openshmem.c:359: warning: implicit declaration of function ‘memcpy’
mpi_to_openshmem.c:359: warning: incompatible implicit declaration of built-in function ‘memcpy’
mpi_to_openshmem.c: In function ‘GetBufferOffset’:
mpi_to_openshmem.c:418: warning: dereferencing ‘void *’ pointer
mpi_to_openshmem.c: In function ‘MPI_Bcast’:
mpi_to_openshmem.c:524: warning: implicit declaration of function ‘shmem_free’
mpi_to_openshmem.c: In function ‘MPI_Comm_create’:
mpi_to_openshmem.c:649: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Comm_dup’:
mpi_to_openshmem.c:761: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Isend’:
mpi_to_openshmem.c:1988: warning: format ‘%x’ expects type ‘unsigned int’, but argument 4 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Iprobe’:
mpi_to_openshmem.c:2481: warning: implicit declaration of function ‘sleep’
ar rvs libmpi_to_openshmem.a mpi_to_openshmem.o mlog.o 
r - mpi_to_openshmem.o
r - mlog.o
[gingery@ca-fe src]$ wrks;make clean;make
rm -rf *.o libmdhim.a
oshcc -g -O0 -Wall -c Mlog/mlog.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c client.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c local_client.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c data_store.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c partitioner.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c messages.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c range_server.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c mdhim_options.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c ds_leveldb.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c mdhim.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
ar rvs libmdhim.a mdhim.o mlog.o client.o local_client.o data_store.o partitioner.o messages.o range_server.o mdhim_options.o ds_leveldb.o
ar: creating libmdhim.a
a - mdhim.o
a - mlog.o
a - client.o
a - local_client.o
a - data_store.o
a - partitioner.o
a - messages.o
a - range_server.o
a - mdhim_options.o
a - ds_leveldb.o
[gingery@ca-fe src]$ wrkt
[gingery@ca-fe tests]$ emacs Mak
Makefile~  Makefile   
[gingery@ca-fe tests]$ emacs Makefile
[gingery@ca-fe tests]$ make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
oshcc -g -O0 -Wall single_tests/broadcast1.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/broadcast1
/users/gingery/mpi_to_openshmem/src/libmpi_to_openshmem.a(mpi_to_openshmem.o): In function `MPI_Bcast':
/users/gingery/mpi_to_openshmem/src/mpi_to_openshmem.c:524: undefined reference to `shmem_free'
/users/gingery/mpi_to_openshmem/src/mpi_to_openshmem.c:525: undefined reference to `shmem_free'
collect2: ld returned 1 exit status
make: *** [broadcast1] Error 1
[gingery@ca-fe tests]$ make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
oshcc -g -O0 -Wall single_tests/broadcast1.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/broadcast1
/users/gingery/mpi_to_openshmem/src/libmpi_to_openshmem.a(mpi_to_openshmem.o): In function `MPI_Bcast':
/users/gingery/mpi_to_openshmem/src/mpi_to_openshmem.c:524: undefined reference to `shmem_free'
/users/gingery/mpi_to_openshmem/src/mpi_to_openshmem.c:525: undefined reference to `shmem_free'
collect2: ld returned 1 exit status
make: *** [broadcast1] Error 1
[gingery@ca-fe tests]$ wrk
[gingery@ca-fe src]$ make
oshcc -g -O0 -Wall -c mpi_to_openshmem.c -I/users/gingery/openshmem-1.0e_IBV/include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/  -L/users/gingery/openshmem-1.0e_IBV/lib -L/users/gingery/GASNet-1.20.2_standard/lib  
mpi_to_openshmem.c: In function ‘MPI_Init’:
mpi_to_openshmem.c:101: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Init_thread’:
mpi_to_openshmem.c:192: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘CopyMyData’:
mpi_to_openshmem.c:359: warning: implicit declaration of function ‘memcpy’
mpi_to_openshmem.c:359: warning: incompatible implicit declaration of built-in function ‘memcpy’
mpi_to_openshmem.c: In function ‘GetBufferOffset’:
mpi_to_openshmem.c:418: warning: dereferencing ‘void *’ pointer
mpi_to_openshmem.c: In function ‘MPI_Comm_create’:
mpi_to_openshmem.c:649: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Comm_dup’:
mpi_to_openshmem.c:761: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Isend’:
mpi_to_openshmem.c:1988: warning: format ‘%x’ expects type ‘unsigned int’, but argument 4 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Iprobe’:
mpi_to_openshmem.c:2481: warning: implicit declaration of function ‘sleep’
ar rvs libmpi_to_openshmem.a mpi_to_openshmem.o mlog.o 
r - mpi_to_openshmem.o
r - mlog.o
[gingery@ca-fe src]$ wrks ; make clean ; make
rm -rf *.o libmdhim.a
oshcc -g -O0 -Wall -c Mlog/mlog.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c client.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c local_client.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c data_store.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c partitioner.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c messages.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c range_server.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c mdhim_options.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c ds_leveldb.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c mdhim.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
ar rvs libmdhim.a mdhim.o mlog.o client.o local_client.o data_store.o partitioner.o messages.o range_server.o mdhim_options.o ds_leveldb.o
ar: creating libmdhim.a
a - mdhim.o
a - mlog.o
a - client.o
a - local_client.o
a - data_store.o
a - partitioner.o
a - messages.o
a - range_server.o
a - mdhim_options.o
a - ds_leveldb.o
[gingery@ca-fe src]$ wrkt;make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
oshcc -g -O0 -Wall single_tests/broadcast1.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/broadcast1
oshcc -g -O0 -Wall single_tests/testMultiSendRcv.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/testMultiSendRcv
[gingery@ca-fe tests]$ wrkt ; make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
oshcc -g -O0 -Wall single_tests/broadcast1.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/broadcast1
oshcc -g -O0 -Wall single_tests/testMultiSendRcv.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/testMultiSendRcv
[gingery@ca-fe tests]$ wrk;make
oshcc -g -O0 -Wall -c mpi_to_openshmem.c -I/users/gingery/openshmem-1.0e_IBV/include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/  -L/users/gingery/openshmem-1.0e_IBV/lib -L/users/gingery/GASNet-1.20.2_standard/lib  
mpi_to_openshmem.c: In function ‘MPI_Init’:
mpi_to_openshmem.c:101: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Init_thread’:
mpi_to_openshmem.c:192: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘CopyMyData’:
mpi_to_openshmem.c:359: warning: implicit declaration of function ‘memcpy’
mpi_to_openshmem.c:359: warning: incompatible implicit declaration of built-in function ‘memcpy’
mpi_to_openshmem.c: In function ‘GetBufferOffset’:
mpi_to_openshmem.c:418: warning: dereferencing ‘void *’ pointer
mpi_to_openshmem.c: In function ‘MPI_Comm_create’:
mpi_to_openshmem.c:654: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Comm_dup’:
mpi_to_openshmem.c:766: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Isend’:
mpi_to_openshmem.c:1993: warning: format ‘%x’ expects type ‘unsigned int’, but argument 4 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Iprobe’:
mpi_to_openshmem.c:2486: warning: implicit declaration of function ‘sleep’
ar rvs libmpi_to_openshmem.a mpi_to_openshmem.o mlog.o 
r - mpi_to_openshmem.o
r - mlog.o
[gingery@ca-fe src]$ wrks ; make clean ; make
rm -rf *.o libmdhim.a
oshcc -g -O0 -Wall -c Mlog/mlog.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c client.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c local_client.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c data_store.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c partitioner.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c messages.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c range_server.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c mdhim_options.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c ds_leveldb.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c mdhim.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
ar rvs libmdhim.a mdhim.o mlog.o client.o local_client.o data_store.o partitioner.o messages.o range_server.o mdhim_options.o ds_leveldb.o
ar: creating libmdhim.a
a - mdhim.o
a - mlog.o
a - client.o
a - local_client.o
a - data_store.o
a - partitioner.o
a - messages.o
a - range_server.o
a - mdhim_options.o
a - ds_leveldb.o
[gingery@ca-fe src]$ wrkt ; make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
oshcc -g -O0 -Wall single_tests/broadcast1.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/broadcast1
oshcc -g -O0 -Wall single_tests/testMultiSendRcv.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/testMultiSendRcv
[gingery@ca-fe tests]$ wrkt ; make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
oshcc -g -O0 -Wall single_tests/broadcast1.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/broadcast1
oshcc -g -O0 -Wall single_tests/testMultiSendRcv.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/testMultiSendRcv
[gingery@ca-fe tests]$ wrkt ; make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
oshcc -g -O0 -Wall single_tests/broadcast1.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/broadcast1
single_tests/broadcast1.c: In function ‘main’:
single_tests/broadcast1.c:50: error: ‘target’ undeclared (first use in this function)
single_tests/broadcast1.c:50: error: (Each undeclared identifier is reported only once
single_tests/broadcast1.c:50: error: for each function it appears in.)
single_tests/broadcast1.c:50: error: ‘root’ undeclared (first use in this function)
make: *** [broadcast1] Error 1
[gingery@ca-fe tests]$ wrkt ; make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
oshcc -g -O0 -Wall single_tests/broadcast1.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/broadcast1
oshcc -g -O0 -Wall single_tests/testMultiSendRcv.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/testMultiSendRcv
[gingery@ca-fe tests]$ wrk ; make
oshcc -g -O0 -Wall -c mpi_to_openshmem.c -I/users/gingery/openshmem-1.0e_IBV/include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/  -L/users/gingery/openshmem-1.0e_IBV/lib -L/users/gingery/GASNet-1.20.2_standard/lib  
mpi_to_openshmem.c: In function ‘MPI_Init’:
mpi_to_openshmem.c:101: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Init_thread’:
mpi_to_openshmem.c:192: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘CopyMyData’:
mpi_to_openshmem.c:359: warning: implicit declaration of function ‘memcpy’
mpi_to_openshmem.c:359: warning: incompatible implicit declaration of built-in function ‘memcpy’
mpi_to_openshmem.c: In function ‘GetBufferOffset’:
mpi_to_openshmem.c:418: warning: dereferencing ‘void *’ pointer
mpi_to_openshmem.c: In function ‘MPI_Bcast’:
mpi_to_openshmem.c:532: warning: dereferencing ‘void *’ pointer
mpi_to_openshmem.c:532: error: invalid use of void expression
mpi_to_openshmem.c:532: error: expected ‘)’ before ‘;’ token
mpi_to_openshmem.c:533: error: expected ‘;’ before ‘}’ token
mpi_to_openshmem.c: In function ‘MPI_Comm_create’:
mpi_to_openshmem.c:655: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Comm_dup’:
mpi_to_openshmem.c:767: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Isend’:
mpi_to_openshmem.c:1994: warning: format ‘%x’ expects type ‘unsigned int’, but argument 4 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Iprobe’:
mpi_to_openshmem.c:2487: warning: implicit declaration of function ‘sleep’
make: *** [mpi_to_openshmem.o] Error 1
[gingery@ca-fe src]$ wrk
[gingery@ca-fe src]$ emacs mpi
mpi_to_openshmem.c~  mpi_to_openshmem.c   mpi_to_openshmem.h~  mpi_to_openshmem.h   mpi_to_openshmem.o 
[gingery@ca-fe src]$ emacs mpi_to_openshmem.c
[gingery@ca-fe src]$ make
oshcc -g -O0 -Wall -c mpi_to_openshmem.c -I/users/gingery/openshmem-1.0e_IBV/include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/  -L/users/gingery/openshmem-1.0e_IBV/lib -L/users/gingery/GASNet-1.20.2_standard/lib  
mpi_to_openshmem.c: In function ‘MPI_Init’:
mpi_to_openshmem.c:101: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Init_thread’:
mpi_to_openshmem.c:192: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘CopyMyData’:
mpi_to_openshmem.c:359: warning: implicit declaration of function ‘memcpy’
mpi_to_openshmem.c:359: warning: incompatible implicit declaration of built-in function ‘memcpy’
mpi_to_openshmem.c: In function ‘GetBufferOffset’:
mpi_to_openshmem.c:418: warning: dereferencing ‘void *’ pointer
mpi_to_openshmem.c: In function ‘MPI_Comm_create’:
mpi_to_openshmem.c:655: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Comm_dup’:
mpi_to_openshmem.c:767: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Isend’:
mpi_to_openshmem.c:1994: warning: format ‘%x’ expects type ‘unsigned int’, but argument 4 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Iprobe’:
mpi_to_openshmem.c:2487: warning: implicit declaration of function ‘sleep’
ar rvs libmpi_to_openshmem.a mpi_to_openshmem.o mlog.o 
r - mpi_to_openshmem.o
r - mlog.o
[gingery@ca-fe src]$ wrks ; make clean ; make
rm -rf *.o libmdhim.a
oshcc -g -O0 -Wall -c Mlog/mlog.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c client.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c local_client.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c data_store.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c partitioner.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c messages.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c range_server.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c mdhim_options.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c ds_leveldb.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c mdhim.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
ar rvs libmdhim.a mdhim.o mlog.o client.o local_client.o data_store.o partitioner.o messages.o range_server.o mdhim_options.o ds_leveldb.o
ar: creating libmdhim.a
a - mdhim.o
a - mlog.o
a - client.o
a - local_client.o
a - data_store.o
a - partitioner.o
a - messages.o
a - range_server.o
a - mdhim_options.o
a - ds_leveldb.o
[gingery@ca-fe src]$ wrkt ; make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
oshcc -g -O0 -Wall single_tests/broadcast1.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/broadcast1
oshcc -g -O0 -Wall single_tests/testMultiSendRcv.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/testMultiSendRcv
[gingery@ca-fe tests]$ wrk
[gingery@ca-fe src]$ emacs mpi_to_openshmem.c
[gingery@ca-fe src]$ make
oshcc -g -O0 -Wall -c mpi_to_openshmem.c -I/users/gingery/openshmem-1.0e_IBV/include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/  -L/users/gingery/openshmem-1.0e_IBV/lib -L/users/gingery/GASNet-1.20.2_standard/lib  
mpi_to_openshmem.c: In function ‘MPI_Init’:
mpi_to_openshmem.c:101: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Init_thread’:
mpi_to_openshmem.c:192: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘CopyMyData’:
mpi_to_openshmem.c:359: warning: implicit declaration of function ‘memcpy’
mpi_to_openshmem.c:359: warning: incompatible implicit declaration of built-in function ‘memcpy’
mpi_to_openshmem.c: In function ‘GetBufferOffset’:
mpi_to_openshmem.c:418: warning: dereferencing ‘void *’ pointer
mpi_to_openshmem.c: In function ‘MPI_Comm_create’:
mpi_to_openshmem.c:656: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Comm_dup’:
mpi_to_openshmem.c:768: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Isend’:
mpi_to_openshmem.c:1995: warning: format ‘%x’ expects type ‘unsigned int’, but argument 4 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Iprobe’:
mpi_to_openshmem.c:2488: warning: implicit declaration of function ‘sleep’
ar rvs libmpi_to_openshmem.a mpi_to_openshmem.o mlog.o 
r - mpi_to_openshmem.o
r - mlog.o
[gingery@ca-fe src]$ wrks ; make clean ; make
rm -rf *.o libmdhim.a
oshcc -g -O0 -Wall -c Mlog/mlog.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c client.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c local_client.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c data_store.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c partitioner.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c messages.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c range_server.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
^[[Aoshcc -g -O0 -Wall -c mdhim_options.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c ds_leveldb.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c mdhim.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
^[[Aar rvs libmdhim.a mdhim.o mlog.o client.o local_client.o data_store.o partitioner.o messages.o range_server.o mdhim_options.o ds_leveldb.o
ar: creating libmdhim.a
a - mdhim.o
a - mlog.o
a - client.o
a - local_client.o
a - data_store.o
a - partitioner.o
a - messages.o
a - range_server.o
a - mdhim_options.o
a - ds_leveldb.o
[gingery@ca-fe src]$ wrkt ; make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
oshcc -g -O0 -Wall single_tests/broadcast1.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/broadcast1
oshcc -g -O0 -Wall single_tests/testMultiSendRcv.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/testMultiSendRcv
[gingery@ca-fe tests]$ wrk
[gingery@ca-fe src]$ emacs mpi_to_openshmem.c
[gingery@ca-fe src]$ make
oshcc -g -O0 -Wall -c mpi_to_openshmem.c -I/users/gingery/openshmem-1.0e_IBV/include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/  -L/users/gingery/openshmem-1.0e_IBV/lib -L/users/gingery/GASNet-1.20.2_standard/lib  
mpi_to_openshmem.c: In function ‘MPI_Init’:
mpi_to_openshmem.c:101: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Init_thread’:
mpi_to_openshmem.c:192: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘CopyMyData’:
mpi_to_openshmem.c:359: warning: implicit declaration of function ‘memcpy’
mpi_to_openshmem.c:359: warning: incompatible implicit declaration of built-in function ‘memcpy’
mpi_to_openshmem.c: In function ‘GetBufferOffset’:
mpi_to_openshmem.c:418: warning: dereferencing ‘void *’ pointer
mpi_to_openshmem.c: In function ‘MPI_Comm_create’:
mpi_to_openshmem.c:656: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Comm_dup’:
mpi_to_openshmem.c:768: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Isend’:
mpi_to_openshmem.c:1995: warning: format ‘%x’ expects type ‘unsigned int’, but argument 4 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Iprobe’:
mpi_to_openshmem.c:2488: warning: implicit declaration of function ‘sleep’
ar rvs libmpi_to_openshmem.a mpi_to_openshmem.o mlog.o 
r - mpi_to_openshmem.o
r - mlog.o
[gingery@ca-fe src]$ make
oshcc -g -O0 -Wall -c mpi_to_openshmem.c -I/users/gingery/openshmem-1.0e_IBV/include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/  -L/users/gingery/openshmem-1.0e_IBV/lib -L/users/gingery/GASNet-1.20.2_standard/lib  
mpi_to_openshmem.c: In function ‘MPI_Init’:
mpi_to_openshmem.c:101: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Init_thread’:
mpi_to_openshmem.c:192: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘CopyMyData’:
mpi_to_openshmem.c:359: warning: implicit declaration of function ‘memcpy’
mpi_to_openshmem.c:359: warning: incompatible implicit declaration of built-in function ‘memcpy’
mpi_to_openshmem.c: In function ‘GetBufferOffset’:
mpi_to_openshmem.c:418: warning: dereferencing ‘void *’ pointer
mpi_to_openshmem.c: In function ‘MPI_Comm_create’:
mpi_to_openshmem.c:642: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Comm_dup’:
mpi_to_openshmem.c:754: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Isend’:
mpi_to_openshmem.c:1981: warning: format ‘%x’ expects type ‘unsigned int’, but argument 4 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Iprobe’:
mpi_to_openshmem.c:2474: warning: implicit declaration of function ‘sleep’
ar rvs libmpi_to_openshmem.a mpi_to_openshmem.o mlog.o 
r - mpi_to_openshmem.o
r - mlog.o
[gingery@ca-fe src]$ wrks ; make clean ; make
rm -rf *.o libmdhim.a
oshcc -g -O0 -Wall -c Mlog/mlog.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c client.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c local_client.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c data_store.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c partitioner.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c messages.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c range_server.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c mdhim_options.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c ds_leveldb.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c mdhim.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
ar rvs libmdhim.a mdhim.o mlog.o client.o local_client.o data_store.o partitioner.o messages.o range_server.o mdhim_options.o ds_leveldb.o
ar: creating libmdhim.a
a - mdhim.o
a - mlog.o
a - client.o
a - local_client.o
a - data_store.o
a - partitioner.o
a - messages.o
a - range_server.o
a - mdhim_options.o
a - ds_leveldb.o
[gingery@ca-fe src]$ wrkt ; make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
oshcc -g -O0 -Wall single_tests/broadcast1.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/broadcast1
oshcc -g -O0 -Wall single_tests/testMultiSendRcv.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/testMultiSendRcv
[gingery@ca-fe tests]$ wrkt ; make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
oshcc -g -O0 -Wall single_tests/broadcast1.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/broadcast1
oshcc -g -O0 -Wall single_tests/testMultiSendRcv.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/testMultiSendRcv
[gingery@ca-fe tests]$ wrk;make
oshcc -g -O0 -Wall -c mpi_to_openshmem.c -I/users/gingery/openshmem-1.0e_IBV/include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/  -L/users/gingery/openshmem-1.0e_IBV/lib -L/users/gingery/GASNet-1.20.2_standard/lib  
mpi_to_openshmem.c: In function ‘MPI_Init’:
mpi_to_openshmem.c:101: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Init_thread’:
mpi_to_openshmem.c:192: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘CopyMyData’:
mpi_to_openshmem.c:359: warning: implicit declaration of function ‘memcpy’
mpi_to_openshmem.c:359: warning: incompatible implicit declaration of built-in function ‘memcpy’
mpi_to_openshmem.c: In function ‘GetBufferOffset’:
mpi_to_openshmem.c:418: warning: dereferencing ‘void *’ pointer
mpi_to_openshmem.c: In function ‘MPI_Comm_create’:
mpi_to_openshmem.c:638: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Comm_dup’:
mpi_to_openshmem.c:750: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Isend’:
mpi_to_openshmem.c:1977: warning: format ‘%x’ expects type ‘unsigned int’, but argument 4 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Iprobe’:
mpi_to_openshmem.c:2470: warning: implicit declaration of function ‘sleep’
ar rvs libmpi_to_openshmem.a mpi_to_openshmem.o mlog.o 
r - mpi_to_openshmem.o
r - mlog.o
[gingery@ca-fe src]$ wrks ; make clean ; make
rm -rf *.o libmdhim.a
oshcc -g -O0 -Wall -c Mlog/mlog.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c client.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c local_client.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c data_store.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c partitioner.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c messages.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c range_server.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c mdhim_options.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c ds_leveldb.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c mdhim.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
ar rvs libmdhim.a mdhim.o mlog.o client.o local_client.o data_store.o partitioner.o messages.o range_server.o mdhim_options.o ds_leveldb.o
ar: creating libmdhim.a
a - mdhim.o
a - mlog.o
a - client.o
a - local_client.o
a - data_store.o
a - partitioner.o
a - messages.o
a - range_server.o
a - mdhim_options.o
a - ds_leveldb.o
[gingery@ca-fe src]$ wrkt ; make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
oshcc -g -O0 -Wall single_tests/broadcast1.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/broadcast1
oshcc -g -O0 -Wall single_tests/testMultiSendRcv.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/testMultiSendRcv
[gingery@ca-fe tests]$ wrkt ; make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
oshcc -g -O0 -Wall single_tests/broadcast1.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/broadcast1
oshcc -g -O0 -Wall single_tests/testMultiSendRcv.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/testMultiSendRcv
[gingery@ca-fe tests]$ exit
logout
Connection to ca-fe closed.
[gingery@ccstargate ~]$ exit
logout
Connection to ccstargate closed.
kef-gay:~ gingery$ ssh ccstargate
gingery@ccstargate's password: 
Warning: untrusted X11 forwarding setup failed: xauth key data not generated
Warning: No xauth data; using fake authentication data for X11 forwarding.
Last login: Wed Feb 19 11:12:50 2014 from jvpn-132-155.lanl.gov
[gingery@ccstargate ~]$ !ssh
ssh ca-fe
Last login: Wed Feb 19 11:13:07 2014 from 10.128.10.240
******************************************************************************
                              Notice to Users

This is a Federal computer system and is the property of the United
States Government.  It is for authorized used only.  Users (authorized or
unauthorized) have no explicit or implicit expectation of privacy.

Any or all uses of this system and all files on this system may be
intercepted, monitored, recorded, copied, audited, inspected, and disclosed
to authorized site, Department of Energy, and law enforcement personnel, as
well as authorized officials of other agencies, both domestic and foreign.
By using this system, the user consents to such interception, monitoring,
recording, copying, auditing, inspection, and disclosure at the discretion
of authorized site or Department of Energy personnel.

Unauthorized or improper use of this system may result in administrative
disciplinary action and civil and criminal penalties.  By continuing to
use this system you indicate your awareness of and consent to these terms
and conditions of use.  LOG OFF IMMEDIATELY if you do not agree to the
conditions stated in this warning.

******************************************************************************

[gingery@ca-fe ~]$ !spu
spu: Event not found.
[gingery@ca-fe ~]$ !sou
source ~/.cshrc.local_sv
Adding OpenShmem-1.0e_IBV
Currently Loaded Modulefiles:
  1) mvapich2-gnu-ofa/1.7
[gingery@ca-fe ~]$ wrk
[gingery@ca-fe src]$ Read from remote host ccstargate: Connection reset by peer
Connection to ccstargate closed.
kef-gay:~ gingery$ ssh ccstargate
gingery@ccstargate's password: 
Warning: untrusted X11 forwarding setup failed: xauth key data not generated
Warning: No xauth data; using fake authentication data for X11 forwarding.
Last login: Mon Feb 24 08:41:38 2014 from kef-gay.lanl.gov
[gingery@ccstargate ~]$ !ssh
ssh ca-fe
******************************************************************************
                              Notice to Users

This is a Federal computer system and is the property of the United
States Government.  It is for authorized used only.  Users (authorized or
unauthorized) have no explicit or implicit expectation of privacy.

Any or all uses of this system and all files on this system may be
intercepted, monitored, recorded, copied, audited, inspected, and disclosed
to authorized site, Department of Energy, and law enforcement personnel, as
well as authorized officials of other agencies, both domestic and foreign.
By using this system, the user consents to such interception, monitoring,
recording, copying, auditing, inspection, and disclosure at the discretion
of authorized site or Department of Energy personnel.

Unauthorized or improper use of this system may result in administrative
disciplinary action and civil and criminal penalties.  By continuing to
use this system you indicate your awareness of and consent to these terms
and conditions of use.  LOG OFF IMMEDIATELY if you do not agree to the
conditions stated in this warning.

******************************************************************************

[gingery@ca-fe ~]$ !sou
source ~/.cshrc.local_sv
Adding OpenShmem-1.0e_IBV
Currently Loaded Modulefiles:
  1) mvapich2-gnu-ofa/1.7
[gingery@ca-fe ~]$ !wrk
wrk
[gingery@ca-fe src]$ wrk;make
oshcc -g -O0 -Wall -c mpi_to_openshmem.c -I/users/gingery/openshmem-1.0e_IBV/include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/  -L/users/gingery/openshmem-1.0e_IBV/lib -L/users/gingery/GASNet-1.20.2_standard/lib  
mpi_to_openshmem.c: In function ‘MPI_Init’:
mpi_to_openshmem.c:101: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Init_thread’:
mpi_to_openshmem.c:192: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘CopyMyData’:
mpi_to_openshmem.c:359: warning: implicit declaration of function ‘memcpy’
mpi_to_openshmem.c:359: warning: incompatible implicit declaration of built-in function ‘memcpy’
mpi_to_openshmem.c: In function ‘GetBufferOffset’:
mpi_to_openshmem.c:418: warning: dereferencing ‘void *’ pointer
mpi_to_openshmem.c: In function ‘MPI_Comm_create’:
mpi_to_openshmem.c:638: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Comm_dup’:
mpi_to_openshmem.c:750: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Send’:
mpi_to_openshmem.c:1765: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c:1767: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c:1780: error: request for member ‘key’ in something not a structure or union
mpi_to_openshmem.c:1781: error: request for member ‘tag’ in something not a structure or union
mpi_to_openshmem.c:1782: error: request for member ‘count’ in something not a structure or union
mpi_to_openshmem.c:1783: error: request for member ‘datatype’ in something not a structure or union
mpi_to_openshmem.c:1784: error: request for member ‘srcRank’ in something not a structure or union
mpi_to_openshmem.c:1785: error: request for member ‘destRank’ in something not a structure or union
mpi_to_openshmem.c:1786: error: request for member ‘requestType’ in something not a structure or union
mpi_to_openshmem.c:1787: error: request for member ‘isGrabbed’ in something not a structure or union
mpi_to_openshmem.c:1791: error: ‘recv_buf’ undeclared (first use in this function)
mpi_to_openshmem.c:1791: error: (Each undeclared identifier is reported only once
mpi_to_openshmem.c:1791: error: for each function it appears in.)
mpi_to_openshmem.c:1802: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c:1806: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c:1810: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c:1814: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c:1817: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c:1820: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c:1823: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c:1826: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c:1838: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c: In function ‘MPI_Isend’:
mpi_to_openshmem.c:2009: warning: format ‘%x’ expects type ‘unsigned int’, but argument 4 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Iprobe’:
mpi_to_openshmem.c:2502: warning: implicit declaration of function ‘sleep’
make: *** [mpi_to_openshmem.o] Error 1
[gingery@ca-fe src]$ wrk ; make
oshcc -g -O0 -Wall -c mpi_to_openshmem.c -I/users/gingery/openshmem-1.0e_IBV/include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/  -L/users/gingery/openshmem-1.0e_IBV/lib -L/users/gingery/GASNet-1.20.2_standard/lib  
mpi_to_openshmem.c: In function ‘MPI_Init’:
mpi_to_openshmem.c:101: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Init_thread’:
mpi_to_openshmem.c:192: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘CopyMyData’:
mpi_to_openshmem.c:359: warning: implicit declaration of function ‘memcpy’
mpi_to_openshmem.c:359: warning: incompatible implicit declaration of built-in function ‘memcpy’
mpi_to_openshmem.c: In function ‘GetBufferOffset’:
mpi_to_openshmem.c:418: warning: dereferencing ‘void *’ pointer
mpi_to_openshmem.c: In function ‘MPI_Comm_create’:
mpi_to_openshmem.c:638: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Comm_dup’:
mpi_to_openshmem.c:750: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Send’:
mpi_to_openshmem.c:1791: error: ‘recv_buf’ undeclared (first use in this function)
mpi_to_openshmem.c:1791: error: (Each undeclared identifier is reported only once
mpi_to_openshmem.c:1791: error: for each function it appears in.)
mpi_to_openshmem.c:1802: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c:1806: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c:1810: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c:1814: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c:1817: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c:1820: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c:1823: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c:1826: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c:1838: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c: In function ‘MPI_Isend’:
mpi_to_openshmem.c:2009: warning: format ‘%x’ expects type ‘unsigned int’, but argument 4 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Iprobe’:
mpi_to_openshmem.c:2502: warning: implicit declaration of function ‘sleep’
make: *** [mpi_to_openshmem.o] Error 1
[gingery@ca-fe src]$ wrk ; make
oshcc -g -O0 -Wall -c mpi_to_openshmem.c -I/users/gingery/openshmem-1.0e_IBV/include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/  -L/users/gingery/openshmem-1.0e_IBV/lib -L/users/gingery/GASNet-1.20.2_standard/lib  
mpi_to_openshmem.c: In function ‘MPI_Init’:
mpi_to_openshmem.c:101: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Init_thread’:
mpi_to_openshmem.c:192: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘CopyMyData’:
mpi_to_openshmem.c:359: warning: implicit declaration of function ‘memcpy’
mpi_to_openshmem.c:359: warning: incompatible implicit declaration of built-in function ‘memcpy’
mpi_to_openshmem.c: In function ‘GetBufferOffset’:
mpi_to_openshmem.c:418: warning: dereferencing ‘void *’ pointer
mpi_to_openshmem.c: In function ‘MPI_Comm_create’:
mpi_to_openshmem.c:638: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Comm_dup’:
mpi_to_openshmem.c:750: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Send’:
mpi_to_openshmem.c:1791: error: ‘recv_buf’ undeclared (first use in this function)
mpi_to_openshmem.c:1791: error: (Each undeclared identifier is reported only once
mpi_to_openshmem.c:1791: error: for each function it appears in.)
mpi_to_openshmem.c:1802: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c:1806: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c:1810: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c:1814: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c:1817: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c:1820: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c:1823: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c:1826: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c:1838: error: request for member ‘bufPtr’ in something not a structure or union
mpi_to_openshmem.c: In function ‘MPI_Isend’:
mpi_to_openshmem.c:2009: warning: format ‘%x’ expects type ‘unsigned int’, but argument 4 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Iprobe’:
mpi_to_openshmem.c:2502: warning: implicit declaration of function ‘sleep’
make: *** [mpi_to_openshmem.o] Error 1
[gingery@ca-fe src]$ wrk ; make
oshcc -g -O0 -Wall -c mpi_to_openshmem.c -I/users/gingery/openshmem-1.0e_IBV/include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/  -L/users/gingery/openshmem-1.0e_IBV/lib -L/users/gingery/GASNet-1.20.2_standard/lib  
mpi_to_openshmem.c: In function ‘MPI_Init’:
mpi_to_openshmem.c:101: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Init_thread’:
mpi_to_openshmem.c:192: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘CopyMyData’:
mpi_to_openshmem.c:359: warning: implicit declaration of function ‘memcpy’
mpi_to_openshmem.c:359: warning: incompatible implicit declaration of built-in function ‘memcpy’
mpi_to_openshmem.c: In function ‘GetBufferOffset’:
mpi_to_openshmem.c:418: warning: dereferencing ‘void *’ pointer
mpi_to_openshmem.c: In function ‘MPI_Comm_create’:
mpi_to_openshmem.c:638: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Comm_dup’:
mpi_to_openshmem.c:750: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Isend’:
mpi_to_openshmem.c:2003: warning: format ‘%x’ expects type ‘unsigned int’, but argument 4 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Iprobe’:
mpi_to_openshmem.c:2496: warning: implicit declaration of function ‘sleep’
ar rvs libmpi_to_openshmem.a mpi_to_openshmem.o mlog.o 
r - mpi_to_openshmem.o
r - mlog.o
[gingery@ca-fe src]$ cd ..
[gingery@ca-fe ~/mpi_to_openshmem]$ mkdir uthash-master
[gingery@ca-fe ~/mpi_to_openshmem]$ ls
./   English.lproj/  makefacs.pl*  mdhimMods/		    mpiCallsInMdhim.txt  mpi.h	 README.md  uthash-master/
../  .git/	     Makefile	   mdhimNet-1.moved-aside/  mpidefs.h		 README  src/
[gingery@ca-fe ~/mpi_to_openshmem]$ cd uthash-master/
[gingery@ca-fe uthash-master]$ ls
./  ../  doc/  LICENSE*  README.md*  src/  tests/
[gingery@ca-fe uthash-master]$ more README.md 

Documentation for uthash is available at:

http://troydhanson.github.com/uthash/


[gingery@ca-fe uthash-master]$ ls doc/
./	     ChangeLog.html*		   license.html*  todo.txt*	   utarray.txt*      utlist.html*
../	     ChangeLog.txt*		   Makefile*	  userguide.html*  uthash-mini.png*  utlist.txt*
banner.png*  google315d692c9c632ed0.html*  rss.png*	  userguide.txt*   uthash-mini.svg*  utstring.html*
banner.svg*  index.html*		   styles.css*	  utarray.html*    uthash.png*	     utstring.txt*
[gingery@ca-fe uthash-master]$ ls src/
./  ../  utarray.h*  uthash.h*	utlist.h*  utstring.h*
[gingery@ca-fe uthash-master]$ pwd
/users/gingery/mpi_to_openshmem/uthash-master
[gingery@ca-fe uthash-master]$ ls
./  ../  doc/  LICENSE*  README.md*  src/  tests/
[gingery@ca-fe uthash-master]$ cd src/
[gingery@ca-fe src]$ ls
./  ../  utarray.h*  uthash.h*	utlist.h*  utstring.h*
[gingery@ca-fe src]$ cd ../tests/
[gingery@ca-fe tests]$ make
cc -I../src  -g -Wall   -o test1 test1.c 
cc -I../src  -g -Wall   -o test2 test2.c 
cc -I../src  -g -Wall   -o test3 test3.c 
cc -I../src  -g -Wall   -o test4 test4.c 
cc -I../src  -g -Wall   -o test5 test5.c 
cc -I../src  -g -Wall   -o test6 test6.c 
cc -I../src  -g -Wall   -o test7 test7.c 
cc -I../src  -g -Wall   -o test8 test8.c 
cc -I../src  -g -Wall   -o test9 test9.c 
cc -I../src  -g -Wall   -o test10 test10.c 
cc -I../src  -g -Wall   -o test11 test11.c 
cc -I../src  -g -Wall   -o test12 test12.c 
cc -I../src  -g -Wall   -o test13 test13.c 
cc -I../src  -g -Wall   -o test14 test14.c 
cc -I../src  -g -Wall   -o test15 test15.c 
cc -I../src  -g -Wall   -o test16 test16.c 
cc -I../src  -g -Wall   -o test17 test17.c 
cc -I../src  -g -Wall   -o test18 test18.c 
cc -I../src  -g -Wall   -o test19 test19.c 
cc -I../src  -g -Wall   -o test20 test20.c 
cc -I../src  -g -Wall   -o test21 test21.c 
cc -I../src  -g -Wall   -o test22 test22.c 
cc -I../src  -g -Wall   -o test23 test23.c 
cc -I../src  -g -Wall   -o test24 test24.c 
cc -I../src  -g -Wall   -o test25 test25.c 
cc -I../src  -g -Wall   -o test26 test26.c 
cc -I../src  -g -Wall   -o test27 test27.c 
cc -I../src  -g -Wall   -o test28 test28.c 
cc -I../src  -g -Wall   -o test29 test29.c 
cc -I../src  -g -Wall   -o test30 test30.c 
cc -I../src  -g -Wall   -o test31 test31.c 
cc -I../src  -g -Wall   -o test32 test32.c 
cc -I../src  -g -Wall   -o test33 test33.c 
cc -I../src  -g -Wall   -o test34 test34.c 
cc -I../src  -g -Wall   -o test35 test35.c 
cc -I../src  -g -Wall   -o test36 test36.c 
cc -I../src  -g -Wall   -o test37 test37.c 
cc -I../src  -g -Wall   -o test38 test38.c 
cc -I../src  -g -Wall   -o test39 test39.c 
cc -I../src  -g -Wall   -o test40 test40.c 
cc -I../src  -g -Wall   -o test41 test41.c 
cc -I../src  -g -Wall   -o test42 test42.c 
cc -I../src  -g -Wall   -o test43 test43.c 
cc -I../src  -g -Wall   -o test44 test44.c 
cc -I../src  -g -Wall   -o test45 test45.c 
cc -I../src  -g -Wall   -o test46 test46.c 
cc -I../src  -g -Wall   -o test47 test47.c 
cc -I../src  -g -Wall   -o test48 test48.c 
cc -I../src  -g -Wall   -o test49 test49.c 
cc -I../src  -g -Wall   -o test50 test50.c 
cc -I../src  -g -Wall   -o test51 test51.c 
cc -I../src  -g -Wall   -o test52 test52.c 
cc -I../src  -g -Wall   -o test53 test53.c 
cc -I../src  -g -Wall   -o test54 test54.c 
cc -I../src  -g -Wall   -o test55 test55.c 
cc -I../src  -g -Wall   -o test56 test56.c 
cc -I../src  -g -Wall   -o test57 test57.c 
cc -I../src  -g -Wall   -o test58 test58.c 
cc -I../src  -g -Wall   -o test59 test59.c 
cc -I../src  -g -Wall   -o test60 test60.c 
cc -I../src  -g -Wall   -o test61 test61.c 
cc -I../src  -g -Wall   -o test62 test62.c 
cc -I../src  -g -Wall   -o test63 test63.c 
cc -I../src  -g -Wall   -o test64 test64.c 
cc -I../src  -g -Wall   -o test65 test65.c 
cc -I../src  -g -Wall   -o test66 test66.c 
cc -I../src  -g -Wall   -o test67 test67.c 
cc -I../src  -g -Wall   -o test68 test68.c 
cc -I../src  -g -Wall   -o test69 test69.c 
cc -I../src  -g -Wall   -o test70 test70.c 
cc -I../src  -g -Wall   -o test71 test71.c 
cc -I../src  -g -Wall   -o test72 test72.c 
cc -I../src  -g -Wall   -o test73 test73.c 
cc -I../src  -g -Wall   -o test74 test74.c 
cc -I../src  -g -Wall   -o test75 test75.c 
cc -I../src  -g -Wall   -o test76 test76.c 
cc -I../src  -g -Wall   -o test77 test77.c 
cc -I../src  -g -Wall   -o test78 test78.c 
cc -I../src  -g -Wall   -o test79 test79.c 
cc -I../src  -g -Wall   -o test80 test80.c 
cc -I../src  -g -Wall   -o test81 test81.c 
cc -I../src  -g -Wall   -o test82 test82.c 
cc -I../src  -g -Wall   -o emit_keys emit_keys.c 
cc -I../src  -g -Wall   -DHASH_USING_NO_STRICT_ALIASING -fno-strict-aliasing -o hashscan hashscan.c 
cc -I../src  -g -Wall   -DHASH_BLOOM=16 -o sleep_test sleep_test.c 
cc -I../src  -g -Wall   -DHASH_FUNCTION=HASH_BER -o keystat.BER keystat.c 
cc -I../src  -g -Wall   -DHASH_FUNCTION=HASH_SAX -o keystat.SAX keystat.c 
cc -I../src  -g -Wall   -DHASH_FUNCTION=HASH_FNV -o keystat.FNV keystat.c 
cc -I../src  -g -Wall   -DHASH_FUNCTION=HASH_OAT -o keystat.OAT keystat.c 
cc -I../src  -g -Wall   -DHASH_FUNCTION=HASH_JEN -o keystat.JEN keystat.c 
cc -I../src  -g -Wall   -DHASH_FUNCTION=HASH_SFH -o keystat.SFH keystat.c 
cc -I../src  -g -Wall   -DHASH_USING_NO_STRICT_ALIASING -fno-strict-aliasing -DHASH_FUNCTION=HASH_MUR -o keystat.MUR keystat.c 
perl ./do_tests
82 tests conducted, 0 failed.
[gingery@ca-fe tests]$ ls
./		     test13.ans*  test23.c*    test34*	    test44.c*	 test55*      test65.c*    test75.out
../		     test13.c*	  test23.out   test34.ans*  test44.out	 test55.ans*  test65.dat*  test76*
all_funcs*	     test13.out   test24*      test34.c*    test45*	 test55.c*    test65.out   test76.ans*
bloom_perf.c*	     test14*	  test24.ans*  test34.out   test45.ans*  test55.out   test66*	   test76.c*
bloom_perf.sh*	     test14.ans*  test24.c*    test35*	    test45.c*	 test56*      test66.ans*  test76.out
do_tests*	     test14.c*	  test24.out   test35.ans*  test45.out	 test56.ans*  test66.c*    test77*
do_tests.cygwin*     test14.dat*  test25*      test35.c*    test46*	 test56.c*    test66.out   test77.ans*
do_tests.mingw*      test14.out   test25.ans*  test35.out   test46.ans*  test56.out   test67*	   test77.c*
do_tests_win32.cmd*  test15*	  test25.c*    test36*	    test46.c*	 test57*      test67.ans*  test77.out
emit_keys*	     test15.ans*  test25.out   test36.ans*  test46.out	 test57.ans*  test67.c*    test78*
emit_keys.c*	     test15.c*	  test26*      test36.c*    test47*	 test57.c*    test67.out   test78.ans*
example.c*	     test15.out   test26.ans*  test36.out   test47.ans*  test57.out   test68*	   test78.c*
hashscan*	     test16*	  test26.c*    test37*	    test47.c*	 test58*      test68.ans*  test78.out
hashscan.c*	     test16.ans*  test26.out   test37.ans*  test47.out	 test58.ans*  test68.c*    test79*
keystat.BER*	     test16.c*	  test27*      test37.c*    test48*	 test58.c*    test68.out   test79.ans*
keystat.c*	     test16.out   test27.ans*  test37.out   test48.ans*  test58.out   test69*	   test79.c*
keystat.FNV*	     test17*	  test27.c*    test38*	    test48.c*	 test59*      test69.ans*  test79.out
keystat.JEN*	     test17.ans*  test27.out   test38.ans*  test48.out	 test59.ans*  test69.c*    test7.ans*
keystat.MUR*	     test17.c*	  test28*      test38.c*    test49*	 test59.c*    test69.out   test7.c*
keystat.OAT*	     test17.out   test28.ans*  test38.out   test49.ans*  test59.out   test6.ans*   test7.out
keystats*	     test18*	  test28.c*    test39*	    test49.c*	 test5.ans*   test6.c*	   test8*
keystat.SAX*	     test18.ans*  test28.out   test39.ans*  test49.out	 test5.c*     test6.out    test80*
keystat.SFH*	     test18.c*	  test29*      test39.c*    test4.ans*	 test5.out    test7*	   test80.ans*
lru_cache/	     test18.out   test29.ans*  test39.out   test4.c*	 test6*       test70*	   test80.c*
Makefile*	     test19*	  test29.c*    test3.ans*   test4.out	 test60*      test70.ans*  test80.out
mexpand*	     test19.ans*  test29.out   test3.c*     test5*	 test60.ans*  test70.c*    test81*
README*		     test19.c*	  test2.ans*   test3.out    test50*	 test60.c*    test70.out   test81.ans*
simkeys.pl*	     test19.out   test2.c*     test4*	    test50.ans*  test60.out   test71*	   test81.c*
sleep_test*	     test1.ans*   test2.out    test40*	    test50.c*	 test61*      test71.ans*  test81.out
sleep_test.c*	     test1.c*	  test3*       test40.ans*  test50.out	 test61.ans*  test71.c*    test82*
tdiff.cpp*	     test1.out	  test30*      test40.c*    test51*	 test61.c*    test71.out   test82.ans*
test1*		     test2*	  test30.ans*  test40.out   test51.ans*  test61.out   test72*	   test82.c*
test10*		     test20*	  test30.c*    test41*	    test51.c*	 test62*      test72.ans*  test82.out
test10.ans*	     test20.ans*  test30.out   test41.ans*  test51.out	 test62.ans*  test72.c*    test8.ans*
test10.c*	     test20.c*	  test31*      test41.c*    test52*	 test62.c*    test72.out   test8.c*
test10.out	     test20.out   test31.ans*  test41.out   test52.ans*  test62.out   test73*	   test8.out
test11*		     test21*	  test31.c*    test42*	    test52.c*	 test63*      test73.ans*  test9*
test11.ans*	     test21.ans*  test31.out   test42.ans*  test52.out	 test63.ans*  test73.c*    test9.ans*
test11.c*	     test21.c*	  test32*      test42.c*    test53*	 test63.c*    test73.out   test9.c*
test11.dat*	     test21.out   test32.ans*  test42.out   test53.ans*  test63.out   test74*	   test9.out
test11.out	     test22*	  test32.c*    test43*	    test53.c*	 test64*      test74.ans*  threads/
test12*		     test22.ans*  test32.out   test43.ans*  test53.out	 test64.ans*  test74.c*
test12.ans*	     test22.c*	  test33*      test43.c*    test54*	 test64.c*    test74.out
test12.c*	     test22.out   test33.ans*  test43.out   test54.ans*  test64.out   test75*
test12.out	     test23*	  test33.c*    test44*	    test54.c*	 test65*      test75.ans*
test13*		     test23.ans*  test33.out   test44.ans*  test54.out	 test65.ans*  test75.c*
[gingery@ca-fe tests]$ more example.c 
#include <stdio.h>   /* gets */
#include <stdlib.h>  /* atoi, malloc */
#include <string.h>  /* strcpy */
#include "uthash.h"

struct my_struct {
    int id;                    /* key */
    char name[10];             
    UT_hash_handle hh;         /* makes this structure hashable */
};

struct my_struct *users = NULL;

void add_user(int user_id, char *name) {
    struct my_struct *s;

    HASH_FIND_INT(users, &user_id, s);  /* id already in the hash? */
    if (s==NULL) {
      s = (struct my_struct*)malloc(sizeof(struct my_struct));
      s->id = user_id;
      HASH_ADD_INT( users, id, s );  /* id: name of key field */
    }
    strcpy(s->name, name);
}

struct my_struct *find_user(int user_id) {
    struct my_struct *s;

    HASH_FIND_INT( users, &user_id, s );  /* s: output pointer */
    return s;
}

void delete_user(struct my_struct *user) {
    HASH_DEL( users, user);  /* user: pointer to deletee */
    free(user);
}

void delete_all() {
  struct my_struct *current_user, *tmp; 

  HASH_ITER(hh, users, current_user, tmp) {
    HASH_DEL(users,current_user);  /* delete it (users advances to next) */
    free(current_user);            /* free it */
  } 
}

void print_users() {
    struct my_struct *s;

    for(s=users; s != NULL; s=(struct my_struct*)(s->hh.next)) {
        printf("user id %d: name %s\n", s->id, s->name);
    }
}

int name_sort(struct my_struct *a, struct my_struct *b) {
    return strcmp(a->name,b->name);
}

int id_sort(struct my_struct *a, struct my_struct *b) {
    return (a->id - b->id);
}

void sort_by_name() {
    HASH_SORT(users, name_sort);
}

void sort_by_id() {
    HASH_SORT(users, id_sort);
}

int main(int argc, char *argv[]) {
    char in[10];
    int id=1, running=1;
    struct my_struct *s;
    unsigned num_users;

    while (running) {
        printf(" 1. add user\n");
        printf(" 2. add/rename user by id\n");
        printf(" 3. find user\n");
        printf(" 4. delete user\n");
        printf(" 5. delete all users\n");
        printf(" 6. sort items by name\n");
        printf(" 7. sort items by id\n");
        printf(" 8. print users\n");
        printf(" 9. count users\n");
        printf("10. quit\n");
        gets(in);
        switch(atoi(in)) {
            case 1:
                printf("name?\n");
                add_user(id++, gets(in));
                break;
            case 2:
                printf("id?\n");
                gets(in); id = atoi(in);
                printf("name?\n");
                add_user(id, gets(in));
                break;
            case 3:
                printf("id?\n");
                s = find_user(atoi(gets(in)));
                printf("user: %s\n", s ? s->name : "unknown");
                break;
            case 4:
                printf("id?\n");
                s = find_user(atoi(gets(in)));
                if (s) delete_user(s);
                else printf("id unknown\n");
                break;
            case 5:
                delete_all();
                break;
            case 6:
                sort_by_name();
                break;
            case 7:
                sort_by_id();
                break;
            case 8:
                print_users();
                break;
            case 9:
                num_users=HASH_COUNT(users);
                printf("there are %u users\n", num_users);
                break;
            case 10:
                running=0;
                break;
        }
    }

    delete_all();  /* free any structures */
    return 0;
}
[gingery@ca-fe tests]$ exit
logout
Connection to ca-fe closed.
[gingery@ccstargate ~]$ exit
logout
Connection to ccstargate closed.
kef-gay:~ gingery$ ssh ccstargate
gingery@ccstargate's password: 
Warning: untrusted X11 forwarding setup failed: xauth key data not generated
Warning: No xauth data; using fake authentication data for X11 forwarding.
Last login: Mon Feb 24 08:41:49 2014 from kef-gay.lanl.gov
[gingery@ccstargate ~]$ !ssh
ssh ca-fe
Last login: Tue Feb 25 05:16:10 2014 from 10.128.10.240
******************************************************************************
                              Notice to Users

This is a Federal computer system and is the property of the United
States Government.  It is for authorized used only.  Users (authorized or
unauthorized) have no explicit or implicit expectation of privacy.

Any or all uses of this system and all files on this system may be
intercepted, monitored, recorded, copied, audited, inspected, and disclosed
to authorized site, Department of Energy, and law enforcement personnel, as
well as authorized officials of other agencies, both domestic and foreign.
By using this system, the user consents to such interception, monitoring,
recording, copying, auditing, inspection, and disclosure at the discretion
of authorized site or Department of Energy personnel.

Unauthorized or improper use of this system may result in administrative
disciplinary action and civil and criminal penalties.  By continuing to
use this system you indicate your awareness of and consent to these terms
and conditions of use.  LOG OFF IMMEDIATELY if you do not agree to the
conditions stated in this warning.

******************************************************************************

[gingery@ca-fe ~]$ !sou
source ~/.cshrc.local_sv
Adding OpenShmem-1.0e_IBV
Currently Loaded Modulefiles:
  1) mvapich2-gnu-ofa/1.7
[gingery@ca-fe ~]$ wrk
[gingery@ca-fe src]$ ls
./   libmpi_to_openshmem.a  Mlog/   mpi_to_openshmem.c	 #mpi_to_openshmem.h#  mpi_to_openshmem.h~
../  Makefile		    mlog.o  mpi_to_openshmem.c~  mpi_to_openshmem.h    mpi_to_openshmem.o
[gingery@ca-fe src]$ ls ..
./   English.lproj/  makefacs.pl*  mdhimMods/		    mpiCallsInMdhim.txt  mpi.h	 README.md  uthash-master/
../  .git/	     Makefile	   mdhimNet-1.moved-aside/  mpidefs.h		 README  src/
[gingery@ca-fe src]$ 
[gingery@ca-fe src]$ 
[gingery@ca-fe src]$ 
[gingery@ca-fe src]$ more m
mlog.o               mpi_to_openshmem.c   mpi_to_openshmem.h   
mpi_to_openshmem.c~  mpi_to_openshmem.h~  mpi_to_openshmem.o   
[gingery@ca-fe src]$ more mp
mpi_to_openshmem.c~  mpi_to_openshmem.c   mpi_to_openshmem.h~  mpi_to_openshmem.h   mpi_to_openshmem.o 
[gingery@ca-fe src]$ more mpi_to_openshmem.c
/*
 *  ! \mainpage mpi_to_openshmem.c
 *  mpi_to_openshmem 
 *
 *\section intro_sec Introduction
 *
 * mpi_to_openshmem is a library MDHIM TNG uses for its interface for parallel programming
 *
 *  Created on 9/23/13.
 *  Copyright 2013 LANL. All rights reserved.
 *
 */

#include "mpi_to_openshmem.h"

#define DEBUG 1

/**
 * MPI_Init
 * Initializes for Openshmem
 *
 * @param argc Pointer to the number of arguments 
 * @param argv Pointer to the argument vector 
 * @return status.
 */

int MPI_Init( int *argc, char ***argv ){

	int        i;
	int		   ret = MPI_SUCCESS;
	void       *sharedBuffer;
	MPID_Group *groupPtr;
	int		   *pesGroupPtr;
	
	//Open mlog - stolen from plfs
	ret = mlog_open((char *)"mpi_to_openshmem", 0, MLOG_CRIT, MLOG_CRIT, NULL, 0, MLOG_LOGPID, 0);
	
	start_pes(0);
	
	int npes =  _num_pes ();
	int my_pe = shmem_my_pe();
	
	// It is not threaded:
	isMultiThreads = FALSE;
	
	sharedBuffer = (void *)shmalloc(sizeof(char) * MAX_BUFFER_SIZE);
	if (sharedBuffer == NULL ){
		mlog(MPI_ERR, "MPI_Init:: PE: %d, could not shmalloc space for symmetric memory.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}

	if (shmem_addr_accessible( sharedBuffer, my_pe) ) {
		mlog(MPI_DBG, "MPI_Init::Buffer is in a symmetric segment for target pe: %d\n", my_pe);
	}else{
		mlog(MPI_ERR, "MPI_Init::Buffer is NOT in a symmetric segment for target pe: %d\n", my_pe);
		return MPI_ERR_BUFFER;
	}
	
	// Make space for the initial MPI_COMM_WORLD
	MPI_COMM_WORLD = (MPID_Comm *)shmalloc( sizeof(MPID_Comm) );
	if (MPI_COMM_WORLD == NULL ){
		mlog(MPI_ERR, "MPI_Init_thread:: PE: %d, could not shmalloc space for MPI_COMM_WORLD.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}

	// Make space for the initial group & initialize:
	groupPtr = (MPID_Group *)shmalloc(sizeof(MPID_Group));	
	if (groupPtr == NULL ){
		mlog(MPI_ERR, "MPI_Init:: PE: %d, could not shmalloc space for MPID_Group.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
	pesGroupPtr = (int *)shmalloc(sizeof(int) * npes);
	if (pesGroupPtr == NULL ){
		mlog(MPI_ERR, "MPI_Init:: PE: %d, could not shmalloc space for MPID_Group.pesInGroup.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
	
	//printf("MPI_Init_Thread: after start_pes, set up rank and local size\n");
	
	// Set up the rank and local_size (npes)
	((MPID_Comm) *MPI_COMM_WORLD).rank      = my_pe;
	((MPID_Comm) *MPI_COMM_WORLD).size      = npes;
	((MPID_Comm) *MPI_COMM_WORLD).bufferPtr = sharedBuffer;
 	((MPID_Comm) *MPI_COMM_WORLD).groupPtr  = groupPtr;
 	((MPID_Comm) *MPI_COMM_WORLD).offset    = 0;
	
	// Set values in the Comm's Group
	((MPID_Group)*groupPtr).rank    = my_pe;
	((MPID_Group)*groupPtr).size    = npes;
	((MPID_Group)*groupPtr).pe_rank = my_pe;
	((MPID_Group)*groupPtr).pesInGroup = pesGroupPtr;

	// Initially all processes belong in the group.
	for (i=0; i<npes; i++){
		((MPID_Group)*groupPtr).pesInGroup[i] = i;
	}
	
#ifdef DEBUG
	int me = _my_pe();
	printf("MPI_Init_Thread: Me: %d, MPI_COMM_WORLD.rank: %d, .size: %d\n", me,((MPID_Comm) *MPI_COMM_WORLD).ra
nk,((MPID_Comm) *MPI_COMM_WORLD).size);
	mlog(MPI_DBG, "MPI_Init_Thread: Me: %d, MPI_COMM_WORLD.rank: %d, .size: %d, .bufferPtr: %x\n", me, ((MPID_C
omm) *MPI_COMM_WORLD).rank, ((MPID_Comm) *MPI_COMM_WORLD).size,((MPID_Comm) *MPI_COMM_WORLD).bufferPtr);
#endif
	
	return ret;
	
}

/**
 * MPI_Init_thread
 * Initializes for Openshmem, the thread stuff is ignored for now.
 *
 * @param argc		Pointer to the number of arguments 
 * @param argv		Pointer to the argument vector 
 * @param required	Level of desired thread support provided
 * @param provided	Level of provided thread support 
 *
 * @return status.
 */

int MPI_Init_thread( int *argc, char ***argv, int required, int *provided ){
	int          i;
	int		     ret = MPI_SUCCESS;
	void         *sharedBuffer;
	MPID_Group   *groupPtr;
	int		     *pesGroupPtr;
	
	//Open mlog - stolen from plfs
	ret = mlog_open((char *)"mpi_to_openshmem", 0, MLOG_CRIT, MLOG_CRIT, NULL, 0, MLOG_LOGPID, 0);

	start_pes(0);
	
	int npes =  _num_pes ();
	int my_pe = shmem_my_pe();

	// It is threaded:
	isMultiThreads = TRUE;

	sharedBuffer = (void *)shmalloc(sizeof(char) * MAX_BUFFER_SIZE);
	if (sharedBuffer == NULL ){
		mlog(MPI_ERR, "MPI_Init_thread:: PE: %d, could not shmalloc space for symmetric memory.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
	
	if (shmem_addr_accessible( sharedBuffer, my_pe) ) {
		mlog(MPI_DBG, "MPI_Init_thread::Buffer is in a symmetric segment for target pe: %d\n", my_pe);
	}else{
		mlog(MPI_ERR, "MPI_Init_thread::Buffer is NOT in a symmetric segment for target pe: %d\n", my_pe);
		return MPI_ERR_BUFFER;
	}

	// Make space for the initial MPI_COMM_WORLD
	MPI_COMM_WORLD = (MPID_Comm *)shmalloc( sizeof(MPID_Comm) );
	if (MPI_COMM_WORLD == NULL ){
		mlog(MPI_ERR, "MPI_Init_thread:: PE: %d, could not shmalloc space for MPI_COMM_WORLD.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
		
	// Make space for the initial group structure:
	groupPtr = (MPID_Group *)shmalloc(sizeof(MPID_Group));
	if (groupPtr == NULL ){
		mlog(MPI_ERR, "MPI_Init_thread:: PE: %d, could not shmalloc space for MPID_Group.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
	pesGroupPtr = (int *)shmalloc(sizeof(int) * npes);
	if (pesGroupPtr == NULL ){
		mlog(MPI_ERR, "MPI_Init_thread:: PE: %d, could not shmalloc space for MPID_Group.pesInGroup.\n", my
_pe);
		return MPI_ERR_NO_MEM;
	}	
	
	//printf("MPI_Init_Thread: after start_pes, set up rank and local size\n");
	
	// Set up the rank and local_size (npes)
	((MPID_Comm) *MPI_COMM_WORLD).rank      = my_pe;
	((MPID_Comm) *MPI_COMM_WORLD).size      = npes;
	((MPID_Comm) *MPI_COMM_WORLD).bufferPtr = sharedBuffer;
 	((MPID_Comm) *MPI_COMM_WORLD).groupPtr  = groupPtr;
 	((MPID_Comm) *MPI_COMM_WORLD).offset    = 0;
	
	// Set values in the Comm's Group
	((MPID_Group)*groupPtr).rank    = my_pe;
	((MPID_Group)*groupPtr).size    = npes;
	((MPID_Group)*groupPtr).pesInGroup = pesGroupPtr;
	
	// Initially all processes belong in the group.
	for (i=0; i<npes; i++){
		((MPID_Group)*groupPtr).pesInGroup[i] = i;
	}
		
#ifdef DEBUG
		int me = _my_pe();
		//printf("MPI_Init_Thread: Me: %d, MPI_COMM_WORLD.rank: %d, .size: %d\n", me, ((MPID_Comm) *MPI_COM
M_WORLD).rank,((MPID_Comm) *MPI_COMM_WORLD).size);
		mlog(MPI_DBG, "MPI_Init_Thread: Me: %d, MPI_COMM_WORLD.rank: %d, .size: %d, .bufferPtr: %x\n", me, 
((MPID_Comm) *MPI_COMM_WORLD).rank, ((MPID_Comm) *MPI_COMM_WORLD).size,((MPID_Comm) *MPI_COMM_WORLD).bufferPtr);
#endif
	
	/* Types of thread support:
	 * MPI_THREAD_SINGLE
     *		Only one thread will execute. 
	 * MPI_THREAD_FUNNELED
     *		The process may be multi-threaded, but only the main thread will 
	 *		make MPI calls (all MPI calls are funneled to the main thread). 
	 * MPI_THREAD_SERIALIZED
     *		The process may be multi-threaded, and multiple threads may make 

...back 1 page
	}

	// Make space for the initial group & initialize:
	groupPtr = (MPID_Group *)shmalloc(sizeof(MPID_Group));	
	if (groupPtr == NULL ){
		mlog(MPI_ERR, "MPI_Init:: PE: %d, could not shmalloc space for MPID_Group.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
	pesGroupPtr = (int *)shmalloc(sizeof(int) * npes);
	if (pesGroupPtr == NULL ){
		mlog(MPI_ERR, "MPI_Init:: PE: %d, could not shmalloc space for MPID_Group.pesInGroup.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
	
	//printf("MPI_Init_Thread: after start_pes, set up rank and local size\n");
	
	// Set up the rank and local_size (npes)
	((MPID_Comm) *MPI_COMM_WORLD).rank      = my_pe;
	((MPID_Comm) *MPI_COMM_WORLD).size      = npes;
	((MPID_Comm) *MPI_COMM_WORLD).bufferPtr = sharedBuffer;
 	((MPID_Comm) *MPI_COMM_WORLD).groupPtr  = groupPtr;
 	((MPID_Comm) *MPI_COMM_WORLD).offset    = 0;
	
	// Set values in the Comm's Group
	((MPID_Group)*groupPtr).rank    = my_pe;
	((MPID_Group)*groupPtr).size    = npes;
	((MPID_Group)*groupPtr).pe_rank = my_pe;
	((MPID_Group)*groupPtr).pesInGroup = pesGroupPtr;

	// Initially all processes belong in the group.
	for (i=0; i<npes; i++){
		((MPID_Group)*groupPtr).pesInGroup[i] = i;
	}
	
#ifdef DEBUG
	int me = _my_pe();
	printf("MPI_Init_Thread: Me: %d, MPI_COMM_WORLD.rank: %d, .size: %d\n", me,((MPID_Comm) *MPI_COMM_WORLD).ra
nk,((MPID_Comm) *MPI_COMM_WORLD).size);
	mlog(MPI_DBG, "MPI_Init_Thread: Me: %d, MPI_COMM_WORLD.rank: %d, .size: %d, .bufferPtr: %x\n", me, ((MPID_C
omm) *MPI_COMM_WORLD).rank, ((MPID_Comm) *MPI_COMM_WORLD).size,((MPID_Comm) *MPI_COMM_WORLD).bufferPtr);
#endif
	
	return ret;
	
}

/**
 * MPI_Init_thread
 * Initializes for Openshmem, the thread stuff is ignored for now.
 *
 * @param argc		Pointer to the number of arguments 
 * @param argv		Pointer to the argument vector 
 * @param required	Level of desired thread support provided
 * @param provided	Level of provided thread support 
 *
 * @return status.
 */

int MPI_Init_thread( int *argc, char ***argv, int required, int *provided ){
	int          i;
	int		     ret = MPI_SUCCESS;
	void         *sharedBuffer;
	MPID_Group   *groupPtr;
	int		     *pesGroupPtr;
	
	//Open mlog - stolen from plfs
	ret = mlog_open((char *)"mpi_to_openshmem", 0, MLOG_CRIT, MLOG_CRIT, NULL, 0, MLOG_LOGPID, 0);

	start_pes(0);
	

...back 1 page
/*
 *  ! \mainpage mpi_to_openshmem.c
 *  mpi_to_openshmem 
 *
 *\section intro_sec Introduction
 *
 * mpi_to_openshmem is a library MDHIM TNG uses for its interface for parallel programming
 *
 *  Created on 9/23/13.
 *  Copyright 2013 LANL. All rights reserved.
 *
 */

#include "mpi_to_openshmem.h"

#define DEBUG 1

/**
 * MPI_Init
 * Initializes for Openshmem
 *
 * @param argc Pointer to the number of arguments 
 * @param argv Pointer to the argument vector 
 * @return status.
 */

int MPI_Init( int *argc, char ***argv ){

	int        i;
	int		   ret = MPI_SUCCESS;
	void       *sharedBuffer;
	MPID_Group *groupPtr;
	int		   *pesGroupPtr;
	
	//Open mlog - stolen from plfs
	ret = mlog_open((char *)"mpi_to_openshmem", 0, MLOG_CRIT, MLOG_CRIT, NULL, 0, MLOG_LOGPID, 0);
	
	start_pes(0);
	
	int npes =  _num_pes ();
	int my_pe = shmem_my_pe();
	
	// It is not threaded:
	isMultiThreads = FALSE;
	
	sharedBuffer = (void *)shmalloc(sizeof(char) * MAX_BUFFER_SIZE);
	if (sharedBuffer == NULL ){
		mlog(MPI_ERR, "MPI_Init:: PE: %d, could not shmalloc space for symmetric memory.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}

	if (shmem_addr_accessible( sharedBuffer, my_pe) ) {
		mlog(MPI_DBG, "MPI_Init::Buffer is in a symmetric segment for target pe: %d\n", my_pe);
	}else{
		mlog(MPI_ERR, "MPI_Init::Buffer is NOT in a symmetric segment for target pe: %d\n", my_pe);
		return MPI_ERR_BUFFER;
	}
	
	// Make space for the initial MPI_COMM_WORLD
	MPI_COMM_WORLD = (MPID_Comm *)shmalloc( sizeof(MPID_Comm) );
	if (MPI_COMM_WORLD == NULL ){
		mlog(MPI_ERR, "MPI_Init_thread:: PE: %d, could not shmalloc space for MPI_COMM_WORLD.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}

	// Make space for the initial group & initialize:
	groupPtr = (MPID_Group *)shmalloc(sizeof(MPID_Group));	
	if (groupPtr == NULL ){
		mlog(MPI_ERR, "MPI_Init:: PE: %d, could not shmalloc space for MPID_Group.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
	pesGroupPtr = (int *)shmalloc(sizeof(int) * npes);
	if (pesGroupPtr == NULL ){
		mlog(MPI_ERR, "MPI_Init:: PE: %d, could not shmalloc space for MPID_Group.pesInGroup.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
	
	//printf("MPI_Init_Thread: after start_pes, set up rank and local size\n");
	
	// Set up the rank and local_size (npes)
	((MPID_Comm) *MPI_COMM_WORLD).rank      = my_pe;
	((MPID_Comm) *MPI_COMM_WORLD).size      = npes;
	((MPID_Comm) *MPI_COMM_WORLD).bufferPtr = sharedBuffer;
 	((MPID_Comm) *MPI_COMM_WORLD).groupPtr  = groupPtr;
 	((MPID_Comm) *MPI_COMM_WORLD).offset    = 0;
	
	// Set values in the Comm's Group
	((MPID_Group)*groupPtr).rank    = my_pe;
	((MPID_Group)*groupPtr).size    = npes;
	((MPID_Group)*groupPtr).pe_rank = my_pe;
	((MPID_Group)*groupPtr).pesInGroup = pesGroupPtr;

	// Initially all processes belong in the group.
	for (i=0; i<npes; i++){
		((MPID_Group)*groupPtr).pesInGroup[i] = i;
	}
	
#ifdef DEBUG
	int me = _my_pe();
	printf("MPI_Init_Thread: Me: %d, MPI_COMM_WORLD.rank: %d, .size: %d\n", me,((MPID_Comm) *MPI_COMM_WORLD).ra
nk,((MPID_Comm) *MPI_COMM_WORLD).size);
	mlog(MPI_DBG, "MPI_Init_Thread: Me: %d, MPI_COMM_WORLD.rank: %d, .size: %d, .bufferPtr: %x\n", me, ((MPID_C
omm) *MPI_COMM_WORLD).rank, ((MPID_Comm) *MPI_COMM_WORLD).size,((MPID_Comm) *MPI_COMM_WORLD).bufferPtr);
#endif
	
	return ret;
	
}

/**
 * MPI_Init_thread
 * Initializes for Openshmem, the thread stuff is ignored for now.
 *
 * @param argc		Pointer to the number of arguments 
 * @param argv		Pointer to the argument vector 
 * @param required	Level of desired thread support provided
 * @param provided	Level of provided thread support 
 *
 * @return status.
 */

int MPI_Init_thread( int *argc, char ***argv, int required, int *provided ){
	int          i;
	int		     ret = MPI_SUCCESS;
	void         *sharedBuffer;
	MPID_Group   *groupPtr;
	int		     *pesGroupPtr;
	
	//Open mlog - stolen from plfs
	ret = mlog_open((char *)"mpi_to_openshmem", 0, MLOG_CRIT, MLOG_CRIT, NULL, 0, MLOG_LOGPID, 0);

	start_pes(0);
	
	int npes =  _num_pes ();
	int my_pe = shmem_my_pe();

	// It is threaded:
	isMultiThreads = TRUE;

	sharedBuffer = (void *)shmalloc(sizeof(char) * MAX_BUFFER_SIZE);
	if (sharedBuffer == NULL ){
		mlog(MPI_ERR, "MPI_Init_thread:: PE: %d, could not shmalloc space for symmetric memory.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
	
	if (shmem_addr_accessible( sharedBuffer, my_pe) ) {
		mlog(MPI_DBG, "MPI_Init_thread::Buffer is in a symmetric segment for target pe: %d\n", my_pe);
	}else{
		mlog(MPI_ERR, "MPI_Init_thread::Buffer is NOT in a symmetric segment for target pe: %d\n", my_pe);
		return MPI_ERR_BUFFER;
	}

	// Make space for the initial MPI_COMM_WORLD
	MPI_COMM_WORLD = (MPID_Comm *)shmalloc( sizeof(MPID_Comm) );
	if (MPI_COMM_WORLD == NULL ){
		mlog(MPI_ERR, "MPI_Init_thread:: PE: %d, could not shmalloc space for MPI_COMM_WORLD.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
		
	// Make space for the initial group structure:
	groupPtr = (MPID_Group *)shmalloc(sizeof(MPID_Group));
	if (groupPtr == NULL ){
		mlog(MPI_ERR, "MPI_Init_thread:: PE: %d, could not shmalloc space for MPID_Group.\n", my_pe);
		return MPI_ERR_NO_MEM;
	}
	pesGroupPtr = (int *)shmalloc(sizeof(int) * npes);
	if (pesGroupPtr == NULL ){
		mlog(MPI_ERR, "MPI_Init_thread:: PE: %d, could not shmalloc space for MPID_Group.pesInGroup.\n", my
_pe);
		return MPI_ERR_NO_MEM;
	}	
	
	//printf("MPI_Init_Thread: after start_pes, set up rank and local size\n");
	
	// Set up the rank and local_size (npes)
	((MPID_Comm) *MPI_COMM_WORLD).rank      = my_pe;
	((MPID_Comm) *MPI_COMM_WORLD).size      = npes;
	((MPID_Comm) *MPI_COMM_WORLD).bufferPtr = sharedBuffer;
 	((MPID_Comm) *MPI_COMM_WORLD).groupPtr  = groupPtr;
 	((MPID_Comm) *MPI_COMM_WORLD).offset    = 0;
	
	// Set values in the Comm's Group
	((MPID_Group)*groupPtr).rank    = my_pe;
	((MPID_Group)*groupPtr).size    = npes;
	((MPID_Group)*groupPtr).pesInGroup = pesGroupPtr;
	
	// Initially all processes belong in the group.
	for (i=0; i<npes; i++){
		((MPID_Group)*groupPtr).pesInGroup[i] = i;
	}
		
#ifdef DEBUG
		int me = _my_pe();
		//printf("MPI_Init_Thread: Me: %d, MPI_COMM_WORLD.rank: %d, .size: %d\n", me, ((MPID_Comm) *MPI_COM
M_WORLD).rank,((MPID_Comm) *MPI_COMM_WORLD).size);
		mlog(MPI_DBG, "MPI_Init_Thread: Me: %d, MPI_COMM_WORLD.rank: %d, .size: %d, .bufferPtr: %x\n", me, 
((MPID_Comm) *MPI_COMM_WORLD).rank, ((MPID_Comm) *MPI_COMM_WORLD).size,((MPID_Comm) *MPI_COMM_WORLD).bufferPtr);
#endif
	
	/* Types of thread support:
	 * MPI_THREAD_SINGLE
     *		Only one thread will execute. 
	 * MPI_THREAD_FUNNELED
     *		The process may be multi-threaded, but only the main thread will 
	 *		make MPI calls (all MPI calls are funneled to the main thread). 
	 * MPI_THREAD_SERIALIZED
     *		The process may be multi-threaded, and multiple threads may make 
	 *		MPI calls, but only one at a time: MPI calls are not made concurrently 
	 *		from two distinct threads (all MPI calls are serialized). 
	 * MPI_THREAD_MULTIPLE
     *		Multiple threads may call MPI, with no restrictions.These values are 
	 *		monotonic; i.e., MPI_THREAD_SINGLE < MPI_THREAD_FUNNELED < 
	 *		MPI_THREAD_SERIALIZED < MPI_THREAD_MULTIPLE.
	 * 
	 */
	// Fake the multiple thread stuff with mutix, return the expected values.
	*provided = MPI_THREAD_MULTIPLE;
		
	return ret;
	
}

/**
 * MPI_Abort
 * Terminates MPI execution environment.
 *
 * @param comm		communicator (handle)
 * @param errorcode	error code to return to invoking environment 
 * 
 * @return status
 */
int MPI_Abort (MPI_Comm comm, int errorcode){
	int ret = MPI_SUCCESS;
	
	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
	
	// Clear all of the outstanding puts, and that's pretty much all  we can do..
	shmem_barrier_all();

	errorcode = MPI_SUCCESS;
	
	return ret;
}

/**
 * MPI_Barrier
 * Blocks until all processors in the communicator ave reached this routine.
 *
 * @param comm	communicator (handle)
 *
 * @return status
 */
int MPI_Barrier (MPI_Comm comm){

	int ret = MPI_SUCCESS;

	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
	
	shmem_barrier_all ();  // shmem_barrier (int PE_start, int logPE_stride, int PE_size, long *pSync)
	
	return ret;
}

/**
 * GetNumBytes
 *   Get the number of bytes from the count and MPI_Datatype.
 *
 * Input/Output Parameter
 *
 * @param  count	number of items.
 * @param  dataType	data type of the items
 *
 * @return numBytes number of bytes.
 */
int GetNumBytes( int count, MPI_Datatype dataType ){
	
	//int my_pe;
	int	 ret;
	long numBytes;
	
	if (isMultiThreads){
		pthread_mutex_lock(&lockGetNumBytes);
	}
	
	//my_pe = shmem_my_pe();
	ret = MPI_SUCCESS;
	numBytes = 0;
	
	switch (dataType){
		case MPI_CHAR:
		case MPI_UNSIGNED_CHAR:
		case MPI_BYTE:
			numBytes = count * sizeof(char);
			break;
		case MPI_SHORT:
		case MPI_UNSIGNED_SHORT:
			numBytes = count * sizeof(short);
			break;
		case MPI_INT:
		case MPI_UNSIGNED:
			numBytes = count * sizeof(int);
			break;
		case MPI_LONG:
		case MPI_UNSIGNED_LONG:
			numBytes = count * sizeof(long);
			break;
		case MPI_FLOAT:
			numBytes = count * sizeof(float);
			break;
		case MPI_DOUBLE:
			numBytes = count * sizeof(double);
			break;
		case MPI_LONG_DOUBLE:
			numBytes = count * sizeof(long double);
			break;
		case MPI_LONG_LONG:
			numBytes = count * sizeof(long long);
			break;
		default:
			numBytes = count * sizeof(char);
			ret = MPI_ERR_TYPE;
			break;
	}

	if (isMultiThreads){
		pthread_mutex_unlock(&lockGetNumBytes);
	}
	
	return numBytes;
} // GetNumBytes

/**
 * CopyMyData
 *   Copy data from one buffer to another.  Why am I not using memcpy?  
 *   because it didn't work.  The values never ended up in the destination 
 *	 buffer...
 *
 * Input/Output Parameter
 *
 * @param  toBuf	destination buffer
 * @param  fromBuf	source buffer
 * @param  count	number of items to copy
 * @param  dataType	data type of the items
 *
 * @return status
 */

int CopyMyData( void *toBuf, void *fromBuf, int count, MPI_Datatype dataType ){

	long numBytes;

	if (isMultiThreads){
		pthread_mutex_lock(&lockCopyData);
	}
	
	numBytes = GetNumBytes(count, dataType);
	
	memcpy(toBuf, fromBuf, numBytes);
	
	/**
	 int my_pe;
	 int i;
	 my_pe    = shmem_my_pe();

	 for (i=0; i<count; i++){
		printf("CopyMyData: my pe: %-8d fromBuf: %ld, numBytes: %ld \n", my_pe, ((int*)fromBuf)[i], numByte
s);
	}
	for (i=0; i<count; i++){
		printf("CopyMyData: my pe: %-8d symSource: %ld\n", my_pe, ((int*)toBuf)[i]);
	}
	**/
	
	if (isMultiThreads){
		pthread_mutex_unlock(&lockCopyData);
	}
	
	return MPI_SUCCESS;
	
}
/**
 * GetBufferOffset
 *   Calculate the offset of comm's buffer, since you are
 *   using part of it for something...
 *   Adjust the offset in comm as well... Which needs to be cleared.
 *
 * Input/Output Parameter
 *
 * @param  count		number of items currently in the buffer
 * @param  offset		number of bytes in buffer.
 * @param  dataType		data type of the items
 * @param  comm		communicator (handle) 
 *
 * @return  bufferPtr	calculate the offset from the last offset of the symmetric buffer.
 */

void *GetBufferOffset( int count, int *numBytes, MPI_Datatype dataType,  MPI_Comm comm){
	
	int my_pe;
	int currentOffset;
	int newOffset;
	void *bufferPtr;
	
	if (isMultiThreads){
		pthread_mutex_lock(&lockGetOffset);
	}

	my_pe = shmem_my_pe();
    
	// Get the current offset from the comm.
	*numBytes = GetNumBytes(count, dataType);
	currentOffset = ((MPID_Comm)*comm).offset;
	newOffset     = currentOffset + *numBytes;
	
	//printf("GetBufferOffset: rank: %d comm's offset: %d numByters in buffer: %d, long size: %ld\n", my_pe, cu
rrentOffset, *numBytes, sizeof(long));
	mlog(MPI_DBG, "GetBufferOffset: rank: %d numByters in buffer: %d, long size: %ld\n", my_pe, *numBytes, size
of(long));

	bufferPtr = &(((void*)((MPID_Comm)*comm).bufferPtr)[newOffset]);

	if (isMultiThreads){
		pthread_mutex_unlock(&lockGetOffset);
	}

	return bufferPtr;
	
}

/**
 * MPI_Bcast
 * Broadcasts a message from the process with rank "root" to all other processes
 *	of the communicator.
 *
 * Input/Output Parameter
 *
 * @param  buffer		starting address of buffer (choice) 
 *
 * Input Parameters
 *
 * @param  count		number of entries in buffer (integer) 
 * @param  datatype	data type of buffer (handle) 
 * @param  root		rank of broadcast root (integer) 
 * @param  comm		communicator (handle) 
 *
 * @return status
 */
int MPI_Bcast ( void *source, int count, MPI_Datatype dataType, int root, MPI_Comm comm){
	
	int  i;
	int  npes, my_pe;
	void *symSource;
	void *destBuffer;
	int  createSymSource;
	int  numBytes;

	if (comm == NULL) {
		mlog(MPI_ERR, "Invalid communicator.\n");
		return MPI_ERR_COMM;
	}
	
	if (isMultiThreads){
		pthread_mutex_lock(&lockBcast);
	}
		
	npes = _num_pes();
	my_pe = shmem_my_pe();

	createSymSource = FALSE;
	
	if ( !shmem_addr_accessible( source, my_pe) ) {
		// Okay, try to find a work around
		//printf("MPI_Bcast::Buffer is not in a symmetric segment, pe: %d\n", my_pe);
		mlog(MPI_DBG, "Debug: Buffer is not in a symmetric segment, %d\n", my_pe);
		
		symSource = ((void*)((MPID_Comm)*comm).bufferPtr);
		
		// Move user's source into the symmetric buffer, since they can't create one.
		CopyMyData( symSource, source, count, dataType);
		
#ifdef DEBUG
		/**for (i=0; i<count; i++){
			printf("MPI_Bcast: rank: %d symSource: %ld\n", my_pe, ((long*)symSource)[i]);
		}**/
#endif
		// Make the destination start at an offset:
		numBytes = 0;
		destBuffer = GetBufferOffset( count, &numBytes, dataType, comm );
		
		createSymSource = TRUE;
	}
	
	for (i = 0; i < _SHMEM_BCAST_SYNC_SIZE; i += 1){
		pSync[i] = _SHMEM_SYNC_VALUE;
    }
	
	shmem_barrier_all (); // This barrier has to be here, per OpenShmem Spec.
	
	if (createSymSource) {
		shmem_broadcast64( destBuffer, symSource, count, root, 0, 0, npes, pSync);
		
	}
	else{
		shmem_broadcast64( ((MPID_Comm)*comm).bufferPtr, source, count, root, 0, 0, npes, pSync);
	}
	
	shmem_barrier_all();
	
	// Move the symmetric buffer data into source, which is the target...
	if (my_pe != root) {

		if (!createSymSource) 
			CopyMyData(source, ((MPID_Comm)*comm).bufferPtr, count, dataType);
		else 
			CopyMyData(source, destBuffer, count, dataType);
	}
		
#ifdef DEBUG
	for (i = 0; i < count; i++){
		mlog(MPI_DBG, "MPI_Bcast1: rank: %-8d source: %ld\n", my_pe, ((long*)source)[i]); 
		//printf("MPI_Bcast1: rank: %-8d source: %ld\n", my_pe, ((long*)source)[i]);
		//if (!createSymSource) 
		//	printf("MPI_Bcast1: rank: %-8d bufferPtr: %ld\n", my_pe, ((long*)((MPID_Comm)*comm).bufferP
tr)[i]);
	}
#endif

	if (isMultiThreads){
		pthread_mutex_unlock(&lockBcast);
	}
	
	return MPI_SUCCESS;	
}

/**
 * MPI_Comm_create
 * Creates a new communicator
 *
 * @param comm	   communicator (handle) 
 * @param group	   group, which is a subset of the group of comm (handle)
 * @param newcomm  new communicator (handle) 
 *
 * @return		   status
 */
int MPI_Comm_create (MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm){

	int          i;
[gingery@ca-fe src]$ pwd
/users/gingery/mpi_to_openshmem/src
[gingery@ca-fe src]$ ls
./	     libmpi_to_openshmem.a  mlog.o		 #mpi_to_openshmem.h#  mpi_to_openshmem.o
../	     Makefile		    mpi_to_openshmem.c	 mpi_to_openshmem.h
hashUtils.c  Mlog/		    mpi_to_openshmem.c~  mpi_to_openshmem.h~
[gingery@ca-fe src]$ make
oshcc -g -O0 -Wall -c mpi_to_openshmem.c -I/users/gingery/openshmem-1.0e_IBV/include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/  -L/users/gingery/openshmem-1.0e_IBV/lib -L/users/gingery/GASNet-1.20.2_standard/lib  
mpi_to_openshmem.c: In function ‘MPI_Init’:
mpi_to_openshmem.c:101: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Init_thread’:
mpi_to_openshmem.c:192: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘CopyMyData’:
mpi_to_openshmem.c:359: warning: implicit declaration of function ‘memcpy’
mpi_to_openshmem.c:359: warning: incompatible implicit declaration of built-in function ‘memcpy’
mpi_to_openshmem.c: In function ‘GetBufferOffset’:
mpi_to_openshmem.c:418: warning: dereferencing ‘void *’ pointer
mpi_to_openshmem.c: In function ‘MPI_Comm_create’:
mpi_to_openshmem.c:638: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Comm_dup’:
mpi_to_openshmem.c:750: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Isend’:
mpi_to_openshmem.c:2003: warning: format ‘%x’ expects type ‘unsigned int’, but argument 4 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Iprobe’:
mpi_to_openshmem.c:2496: warning: implicit declaration of function ‘sleep’
/tmp/ccRvdaZL.s: Assembler messages:
/tmp/ccRvdaZL.s:12034: Fatal error: can't close mpi_to_openshmem.o: No space left on device
make: *** [mpi_to_openshmem.o] Error 1
[gingery@ca-fe src]$ ls
./   hashUtils.c	    Makefile  mlog.o		  mpi_to_openshmem.c~	mpi_to_openshmem.h
../  libmpi_to_openshmem.a  Mlog/     mpi_to_openshmem.c  #mpi_to_openshmem.h#	mpi_to_openshmem.h~
[gingery@ca-fe src]$ cd ..
[gingery@ca-fe ~/mpi_to_openshmem]$ ls
./   English.lproj/  makefacs.pl*  mdhimMods/		    mpiCallsInMdhim.txt  mpi.h	 README.md  uthash-master/
../  .git/	     Makefile	   mdhimNet-1.moved-aside/  mpidefs.h		 README  src/
[gingery@ca-fe ~/mpi_to_openshmem]$ mount
tmpfs on / type tmpfs (rw)
proc on /proc type proc (rw)
sysfs on /sys type sysfs (rw)
devpts on /dev/pts type devpts (rw,gid=5,mode=620)
tmpfs on /dev/shm type tmpfs (rw,size=2g,mode=1777)
tmpfs on /tmp type tmpfs (rw,size=2g,mode=1777)
none on /proc/sys/fs/binfmt_misc type binfmt_misc (rw)
sunrpc on /var/lib/nfs/rpc_pipefs type rpc_pipefs (rw)
192.168.0.155:/var/lib/perceus/vnfs on /var/lib/perceus/vnfs type nfs (ro,nolock,tcp,nfsvers=3,wsize=32768,rsize=32768,addr=192.168.0.155)
10.129.0.1:/vol/users on /users type nfs (rw,hard,intr,nfsvers=3,lock,tcp,timeo=600,retrans=2,wsize=32768,rsize=32768,addr=10.129.0.1)
10.129.0.1:/vol/projects on /usr/projects type nfs (rw,hard,intr,nfsvers=3,lock,tcp,timeo=600,retrans=2,wsize=32768,rsize=32768,addr=10.129.0.1)
panfs://10.131.0.1/ on /panfs/pas8 type panfs (rw,noauto,panauto,iscsi-sock-rsize=524288,callback-network-allow=10.0.3.0/255.255.255.0,rmlist=(10.131.0.1;10.131.0.181;10.131.0.199),callback-address-ping=0)
panfs://10.132.0.1/ on /panfs/pas12a type panfs (rw,noauto,panauto,iscsi-sock-rsize=524288,callback-network-allow=10.0.3.0/255.255.255.0,rmlist=(10.132.0.1;10.132.0.192;10.132.0.228),callback-address-ping=0)
panfs://10.136.0.1/ on /panfs/pas12b type panfs (rw,noauto,panauto,iscsi-sock-rsize=524288,callback-network-allow=10.0.3.0/255.255.255.0,rmlist=(10.136.0.1;10.136.0.230;10.136.0.219),callback-address-ping=0)
[gingery@ca-fe ~/mpi_to_openshmem]$ mount -a
mount: only root can do that
[gingery@ca-fe ~/mpi_to_openshmem]$ man mount
[gingery@ca-fe ~/mpi_to_openshmem]$ df -k
Filesystem           1K-blocks      Used Available Use% Mounted on
tmpfs                  2097152         0   2097152   0% /dev/shm
tmpfs                  2097152         0   2097152   0% /tmp
192.168.0.155:/var/lib/perceus/vnfs
                     558779104 175607744 354786944  34% /var/lib/perceus/vnfs
10.129.0.1:/vol/users
                     8160437888 8160437760       128 100% /users
10.129.0.1:/vol/projects
                     4080218944 303490944 3776728000   8% /usr/projects
panfs://10.131.0.1/  188403333024  14878416 188388454608   1% /panfs/pas8
panfs://10.132.0.1/  249795931200 22016616576 227779314624   9% /panfs/pas12a
panfs://10.136.0.1/  198817169920 26047519696 172769650224  14% /panfs/pas12b
[gingery@ca-fe ~/mpi_to_openshmem]$ ls /users
./				bsa/	   gaber/      jnunez/	    mitcher/			     rrkroiss/
../				bsantos/   gap/        johnbent/    mjacobi/			     rroy/
aarella9/			bte/	   gars/       jon/	    mlang/			     ruben/
aarone/				bwelch/    gazebo/     jonb/	    mmason/			     samuel/
acaldwell/			ccranor/   gdh/        josip/	    mmbackup.audit.nfzhome.DSMSERV3  sanchezk/
adamm/				cferenba/  ggrider/    jti/	    mscholz/			     satsang/
afm/				chash/	   gingery/    jun/	    mturley/			     seanb/
afn/				chh/	   gmackey/    junhe/	    naps/			     shellys/
agtorre/			cluening/  gpryzby/    kak/	    nbrown/			     shewa/
ajd/				conega/    grahamvh/   kdb/	    ndebard/			     .snapshot/
akonwins/			cornell/   greene/     kedlund/     nlmills/			     stjohn/
alex/				crb/	   hbchen/     kevint/	    noah/			     sutton/
amy/				cscott/    hjelmn/     kgn/	    noranzyk/			     tbowman/
annika/				cwi/	   hng/        klamb/	    orozco/			     theaton/
atorrez/			dbonnie/   hquinn/     knielson/    pakin/			     tmachado/
auditBadPaths.nfzhome.DSMSERV3	dhd/	   htahani/    kristine/    pamelas/			     tmorris/
auditUnresolved.DSMSERV3	dhk/	   hughw/      lally/	    parks/			     toh/
avinash/			digem/	   jack/       lionkov/     paw/			     trandles/
azaroth/			dla/	   jbakosi/    lisa/	    pearley/			     tyilk/
bdmyers/				dmont/	   jbooth/     lmonroe/     pmw/			     u112310/
ben/				dog/	   jbremer/    lost+found/  prr/			     wdn/
bergen/				dsherril/  jennyp/     lucasb/	    pvs/			     wilder/
bhagwan/			dshrader/  jepowell/   markus/	    qtree_users/		     wnr/
bigelow/			dwg/	   jet/        marshall/    quellyn/			     wozniak/
bloewe/				edav/	   jgatencio/  mattmorgan/  rgurule/			     wwtucker/
bmueller/			eed/	   jgreen/     mdaniels/    rjdamore/			     yeti/
bob/				eestolan/  jhr/        meghan/	    rjk/			     yxu/
bretth/				elovato/   jimmyd/     mfisk/	    rlsmith/
brettk/				esamanas/  jimw/       mhill/	    robd/
brianc/				evanl/	   jmartinez/  michalak/    rocr/
bridges/			fieldsr/   jmpeters/   mitchell/    royjuan/
[gingery@ca-fe ~/mpi_to_openshmem]$ df -k
Filesystem           1K-blocks      Used Available Use% Mounted on
tmpfs                  2097152         0   2097152   0% /dev/shm
tmpfs                  2097152         0   2097152   0% /tmp
192.168.0.155:/var/lib/perceus/vnfs
                     558779104 175607776 354786912  34% /var/lib/perceus/vnfs
10.129.0.1:/vol/users
                     8160437888 8160437792        96 100% /users
10.129.0.1:/vol/projects
                     4080218944 303490944 3776728000   8% /usr/projects
panfs://10.131.0.1/  188403333024  14878416 188388454608   1% /panfs/pas8
panfs://10.132.0.1/  249795931200 22016616576 227779314624   9% /panfs/pas12a
panfs://10.136.0.1/  198817169920 26047519696 172769650224  14% /panfs/pas12b
[gingery@ca-fe ~/mpi_to_openshmem]$ cd ../
[gingery@ca-fe ~]$ ls
./		  .emacs		   mpi_to_openshmem/	       README
../		  .emacs.d/		   mpiToOpenshmem/	       README_GN_RESULTS
authorized_keys   GASNet-1.20.2/	   mpi_to_openshmem.tar        README_TEST_RESULTS_GasNet_Standard
.bash_logout	  GASNet-1.20.2_standard/  openshmem-1.0d_IBV/	       .saves-2782-rrz-fe1.localdomain
.bash_profile	  GASNet-1.20.2.tar.gz	   openshmem-1.0d_SMP/	       src/
.bash_profile~	  .gitconfig		   openshmem-1.0d_UDP/	       .ssh/
.bashrc		  .gnome2/		   openshmem-1.0e_IBV/	       temp/
.bashrc~	  .history		   openshmem-1.0e_UDP/	       .texlive2007/
config.h	  .local_env_Linux~	   openshmem-release-1.0e.tar  .viminfo
config.status*	  .local_env_Linux_save    openshmemReleases/	       .Xauthority
.cshrc		  mdhim-tng/		   openshmem.tar.gz	       .xemacs/
.cshrc.local_sv   mdhim-tng.tar.gz	   openshmem-test-1.0b/        y
.cshrc.local_sv~  mpidefs.h		   openshmemTest.tar.gz        y.pub
doc/		  mpi.h			   pftools.tar
[gingery@ca-fe ~]$ cd mp
mpidefs.h             mpi.h                 mpi_to_openshmem/     mpiToOpenshmem/       mpi_to_openshmem.tar 
[gingery@ca-fe ~]$ cd mpi_
mpi_to_openshmem/     mpi_to_openshmem.tar  
[gingery@ca-fe ~]$ cd mpi_to_openshmem/
[gingery@ca-fe ~/mpi_to_openshmem]$ ls
./   English.lproj/  makefacs.pl*  mdhimMods/		    mpiCallsInMdhim.txt  mpi.h	 README.md  uthash-master/
../  .git/	     Makefile	   mdhimNet-1.moved-aside/  mpidefs.h		 README  src/
[gingery@ca-fe ~/mpi_to_openshmem]$ cd uthash-master/
[gingery@ca-fe uthash-master]$ ls
./  ../  doc/  LICENSE*  README.md*  src/  tests/
[gingery@ca-fe uthash-master]$ cd tests/
[gingery@ca-fe tests]$ ls
./		     test13.ans*  test23.c*    test34*	    test44.c*	 test55*      test65.c*    test75.out
../		     test13.c*	  test23.out   test34.ans*  test44.out	 test55.ans*  test65.dat*  test76*
all_funcs*	     test13.out   test24*      test34.c*    test45*	 test55.c*    test65.out   test76.ans*
bloom_perf.c*	     test14*	  test24.ans*  test34.out   test45.ans*  test55.out   test66*	   test76.c*
bloom_perf.sh*	     test14.ans*  test24.c*    test35*	    test45.c*	 test56*      test66.ans*  test76.out
do_tests*	     test14.c*	  test24.out   test35.ans*  test45.out	 test56.ans*  test66.c*    test77*
do_tests.cygwin*     test14.dat*  test25*      test35.c*    test46*	 test56.c*    test66.out   test77.ans*
do_tests.mingw*      test14.out   test25.ans*  test35.out   test46.ans*  test56.out   test67*	   test77.c*
do_tests_win32.cmd*  test15*	  test25.c*    test36*	    test46.c*	 test57*      test67.ans*  test77.out
emit_keys*	     test15.ans*  test25.out   test36.ans*  test46.out	 test57.ans*  test67.c*    test78*
emit_keys.c*	     test15.c*	  test26*      test36.c*    test47*	 test57.c*    test67.out   test78.ans*
example.c*	     test15.out   test26.ans*  test36.out   test47.ans*  test57.out   test68*	   test78.c*
hashscan*	     test16*	  test26.c*    test37*	    test47.c*	 test58*      test68.ans*  test78.out
hashscan.c*	     test16.ans*  test26.out   test37.ans*  test47.out	 test58.ans*  test68.c*    test79*
keystat.BER*	     test16.c*	  test27*      test37.c*    test48*	 test58.c*    test68.out   test79.ans*
keystat.c*	     test16.out   test27.ans*  test37.out   test48.ans*  test58.out   test69*	   test79.c*
keystat.FNV*	     test17*	  test27.c*    test38*	    test48.c*	 test59*      test69.ans*  test79.out
keystat.JEN*	     test17.ans*  test27.out   test38.ans*  test48.out	 test59.ans*  test69.c*    test7.ans*
keystat.MUR*	     test17.c*	  test28*      test38.c*    test49*	 test59.c*    test69.out   test7.c*
keystat.OAT*	     test17.out   test28.ans*  test38.out   test49.ans*  test59.out   test6.ans*   test7.out
keystats*	     test18*	  test28.c*    test39*	    test49.c*	 test5.ans*   test6.c*	   test8*
keystat.SAX*	     test18.ans*  test28.out   test39.ans*  test49.out	 test5.c*     test6.out    test80*
keystat.SFH*	     test18.c*	  test29*      test39.c*    test4.ans*	 test5.out    test7*	   test80.ans*
lru_cache/	     test18.out   test29.ans*  test39.out   test4.c*	 test6*       test70*	   test80.c*
Makefile*	     test19*	  test29.c*    test3.ans*   test4.out	 test60*      test70.ans*  test80.out
mexpand*	     test19.ans*  test29.out   test3.c*     test5*	 test60.ans*  test70.c*    test81*
README*		     test19.c*	  test2.ans*   test3.out    test50*	 test60.c*    test70.out   test81.ans*
simkeys.pl*	     test19.out   test2.c*     test4*	    test50.ans*  test60.out   test71*	   test81.c*
sleep_test*	     test1.ans*   test2.out    test40*	    test50.c*	 test61*      test71.ans*  test81.out
sleep_test.c*	     test1.c*	  test3*       test40.ans*  test50.out	 test61.ans*  test71.c*    test82*
tdiff.cpp*	     test1.out	  test30*      test40.c*    test51*	 test61.c*    test71.out   test82.ans*
test1*		     test2*	  test30.ans*  test40.out   test51.ans*  test61.out   test72*	   test82.c*
test10*		     test20*	  test30.c*    test41*	    test51.c*	 test62*      test72.ans*  test82.out
test10.ans*	     test20.ans*  test30.out   test41.ans*  test51.out	 test62.ans*  test72.c*    test8.ans*
test10.c*	     test20.c*	  test31*      test41.c*    test52*	 test62.c*    test72.out   test8.c*
test10.out	     test20.out   test31.ans*  test41.out   test52.ans*  test62.out   test73*	   test8.out
test11*		     test21*	  test31.c*    test42*	    test52.c*	 test63*      test73.ans*  test9*
test11.ans*	     test21.ans*  test31.out   test42.ans*  test52.out	 test63.ans*  test73.c*    test9.ans*
test11.c*	     test21.c*	  test32*      test42.c*    test53*	 test63.c*    test73.out   test9.c*
test11.dat*	     test21.out   test32.ans*  test42.out   test53.ans*  test63.out   test74*	   test9.out
test11.out	     test22*	  test32.c*    test43*	    test53.c*	 test64*      test74.ans*  threads/
test12*		     test22.ans*  test32.out   test43.ans*  test53.out	 test64.ans*  test74.c*
test12.ans*	     test22.c*	  test33*      test43.c*    test54*	 test64.c*    test74.out
test12.c*	     test22.out   test33.ans*  test43.out   test54.ans*  test64.out   test75*
test12.out	     test23*	  test33.c*    test44*	    test54.c*	 test65*      test75.ans*
test13*		     test23.ans*  test33.out   test44.ans*  test54.out	 test65.ans*  test75.c*
[gingery@ca-fe tests]$ more te
test1*      test18.c*   test26.out  test35*     test43.ans* test51.c*   test6*      test68.out  test77*
test10*     test18.out  test27*     test35.ans* test43.c*   test51.out  test60*     test69*     test77.ans*
test10.ans* test19*     test27.ans* test35.c*   test43.out  test52*     test60.ans* test69.ans* test77.c*
test10.c*   test19.ans* test27.c*   test35.out  test44*     test52.ans* test60.c*   test69.c*   test77.out 
test10.out  test19.c*   test27.out  test36*     test44.ans* test52.c*   test60.out  test69.out  test78*
test11*     test19.out  test28*     test36.ans* test44.c*   test52.out  test61*     test6.ans*  test78.ans*
test11.ans* test1.ans*  test28.ans* test36.c*   test44.out  test53*     test61.ans* test6.c*    test78.c*
test11.c*   test1.c*    test28.c*   test36.out  test45*     test53.ans* test61.c*   test6.out   test78.out 
test11.dat* test1.out   test28.out  test37*     test45.ans* test53.c*   test61.out  test7*      test79*
test11.out  test2*      test29*     test37.ans* test45.c*   test53.out  test62*     test70*     test79.ans*
test12*     test20*     test29.ans* test37.c*   test45.out  test54*     test62.ans* test70.ans* test79.c*
test12.ans* test20.ans* test29.c*   test37.out  test46*     test54.ans* test62.c*   test70.c*   test79.out 
test12.c*   test20.c*   test29.out  test38*     test46.ans* test54.c*   test62.out  test70.out  test7.ans*
test12.out  test20.out  test2.ans*  test38.ans* test46.c*   test54.out  test63*     test71*     test7.c*
test13*     test21*     test2.c*    test38.c*   test46.out  test55*     test63.ans* test71.ans* test7.out 
test13.ans* test21.ans* test2.out   test38.out  test47*     test55.ans* test63.c*   test71.c*   test8*
test13.c*   test21.c*   test3*      test39*     test47.ans* test55.c*   test63.out  test71.out  test80*
test13.out  test21.out  test30*     test39.ans* test47.c*   test55.out  test64*     test72*     test80.ans*
test14*     test22*     test30.ans* test39.c*   test47.out  test56*     test64.ans* test72.ans* test80.c*
test14.ans* test22.ans* test30.c*   test39.out  test48*     test56.ans* test64.c*   test72.c*   test80.out 
test14.c*   test22.c*   test30.out  test3.ans*  test48.ans* test56.c*   test64.out  test72.out  test81*
test14.dat* test22.out  test31*     test3.c*    test48.c*   test56.out  test65*     test73*     test81.ans*
test14.out  test23*     test31.ans* test3.out   test48.out  test57*     test65.ans* test73.ans* test81.c*
test15*     test23.ans* test31.c*   test4*      test49*     test57.ans* test65.c*   test73.c*   test81.out 
test15.ans* test23.c*   test31.out  test40*     test49.ans* test57.c*   test65.dat* test73.out  test82*
test15.c*   test23.out  test32*     test40.ans* test49.c*   test57.out  test65.out  test74*     test82.ans*
test15.out  test24*     test32.ans* test40.c*   test49.out  test58*     test66*     test74.ans* test82.c*
test16*     test24.ans* test32.c*   test40.out  test4.ans*  test58.ans* test66.ans* test74.c*   test82.out 
test16.ans* test24.c*   test32.out  test41*     test4.c*    test58.c*   test66.c*   test74.out  test8.ans*
test16.c*   test24.out  test33*     test41.ans* test4.out   test58.out  test66.out  test75*     test8.c*
test16.out  test25*     test33.ans* test41.c*   test5*      test59*     test67*     test75.ans* test8.out 
test17*     test25.ans* test33.c*   test41.out  test50*     test59.ans* test67.ans* test75.c*   test9*
test17.ans* test25.c*   test33.out  test42*     test50.ans* test59.c*   test67.c*   test75.out  test9.ans*
test17.c*   test25.out  test34*     test42.ans* test50.c*   test59.out  test67.out  test76*     test9.c*
test17.out  test26*     test34.ans* test42.c*   test50.out  test5.ans*  test68*     test76.ans* test9.out 
test18*     test26.ans* test34.c*   test42.out  test51*     test5.c*    test68.ans* test76.c*   
test18.ans* test26.c*   test34.out  test43*     test51.ans* test5.out   test68.c*   test76.out  
[gingery@ca-fe tests]$ more test10.out
9 found in hh
9 found in alth
10 not found in hh
10 found in alth
[gingery@ca-fe tests]$ rm *.out
[gingery@ca-fe tests]$ cd ..
[gingery@ca-fe uthash-master]$ cd src/
[gingery@ca-fe src]$ make
make: *** No targets specified and no makefile found.  Stop.
[gingery@ca-fe src]$ pwd
/users/gingery/mpi_to_openshmem/uthash-master/src
[gingery@ca-fe src]$ wrk
[gingery@ca-fe src]$ make
oshcc -g -O0 -Wall -c mpi_to_openshmem.c -I/users/gingery/openshmem-1.0e_IBV/include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/  -L/users/gingery/openshmem-1.0e_IBV/lib -L/users/gingery/GASNet-1.20.2_standard/lib  
mpi_to_openshmem.c: In function ‘MPI_Init’:
mpi_to_openshmem.c:101: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Init_thread’:
mpi_to_openshmem.c:192: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘CopyMyData’:
mpi_to_openshmem.c:359: warning: implicit declaration of function ‘memcpy’
mpi_to_openshmem.c:359: warning: incompatible implicit declaration of built-in function ‘memcpy’
mpi_to_openshmem.c: In function ‘GetBufferOffset’:
mpi_to_openshmem.c:418: warning: dereferencing ‘void *’ pointer
mpi_to_openshmem.c: In function ‘MPI_Comm_create’:
mpi_to_openshmem.c:638: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Comm_dup’:
mpi_to_openshmem.c:750: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Isend’:
mpi_to_openshmem.c:2003: warning: format ‘%x’ expects type ‘unsigned int’, but argument 4 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Iprobe’:
mpi_to_openshmem.c:2496: warning: implicit declaration of function ‘sleep’
ar rvs libmpi_to_openshmem.a mpi_to_openshmem.o mlog.o 
r - mpi_to_openshmem.o
r - mlog.o
[gingery@ca-fe src]$ wrks;make clean;make
rm -rf *.o libmdhim.a
oshcc -g -O0 -Wall -c Mlog/mlog.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c client.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c local_client.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
Assembler messages:
Fatal error: can't create local_client.o: No space left on device
make: *** [local_client.o] Error 1
[gingery@ca-fe src]$ wrkt
[gingery@ca-fe tests]$ ls
./  ../  Makefile  Makefile~  OrigMakefile  put-get.o  README  single_tests/  tester/  wrkingExample.txt
[gingery@ca-fe tests]$ emacs Ma
Makefile~  Makefile   
[gingery@ca-fe tests]$ emacs Makefile
[gingery@ca-fe tests]$ cp M
Makefile~  Makefile   
[gingery@ca-fe tests]$ cp Makefile Ma
Makefile~  Makefile   
[gingery@ca-fe tests]$ cp Makefile Makefile.orig
[gingery@ca-fe tests]$ emacs Makefile
[gingery@ca-fe tests]$ ls
./   Makefile	Makefile.orig  put-get.o  single_tests/  wrkingExample.txt
../  Makefile~	OrigMakefile   README	  tester/
[gingery@ca-fe tests]$ make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem//src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/ -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
/usr/bin/ld: cannot find -lmdhim
collect2: ld returned 1 exit status
make: *** [lock] Error 1
[gingery@ca-fe tests]$ cp Makefile.orig Makefile
[gingery@ca-fe tests]$ make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
/usr/bin/ld: cannot find -lmdhim
collect2: ld returned 1 exit status
make: *** [lock] Error 1
[gingery@ca-fe tests]$ emacs Ma
Makefile~      Makefile       Makefile.orig  
[gingery@ca-fe tests]$ emacs Makefile
[gingery@ca-fe tests]$ make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/gingery/mpi_to_openshmem//src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L/users/gingery/mpi_to_openshmem//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -L/usr/lib64 /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
oshcc -g -O0 -Wall single_tests/broadcast1.c -I/users/gingery/mpi_to_openshmem//src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L/users/gingery/mpi_to_openshmem//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -L/usr/lib64 /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ -o single_tests/broadcast1
/tmp/ccusz9YV.o: In function `main':
/users/gingery/mpi_to_openshmem/mdhimMods/tests/single_tests/broadcast1.c:24: undefined reference to `MPI_Init_thread'
/users/gingery/mpi_to_openshmem/mdhimMods/tests/single_tests/broadcast1.c:30: undefined reference to `MPI_Comm_rank'
/users/gingery/mpi_to_openshmem/mdhimMods/tests/single_tests/broadcast1.c:31: undefined reference to `MPI_Comm_size'
/users/gingery/mpi_to_openshmem/mdhimMods/tests/single_tests/broadcast1.c:48: undefined reference to `MPI_Bcast'
collect2: ld returned 1 exit status
make: *** [broadcast1] Error 1
[gingery@ca-fe tests]$ wrk
[gingery@ca-fe src]$ make
ar rvs libmpi_to_openshmem.a mpi_to_openshmem.o mlog.o 
r - mpi_to_openshmem.o
r - mlog.o
[gingery@ca-fe src]$ wrks
[gingery@ca-fe src]$ make
oshcc -g -O0 -Wall -c local_client.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c data_store.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c partitioner.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c messages.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c range_server.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c mdhim_options.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c ds_leveldb.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c mdhim.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
ar rvs libmdhim.a mdhim.o mlog.o client.o local_client.o data_store.o partitioner.o messages.o range_server.o mdhim_options.o ds_leveldb.o
ar: creating libmdhim.a
a - mdhim.o
a - mlog.o
a - client.o
a - local_client.o
a - data_store.o
a - partitioner.o
a - messages.o
a - range_server.o
a - mdhim_options.o
a - ds_leveldb.o
[gingery@ca-fe src]$ wrkt
[gingery@ca-fe tests]$ cp Ma
Makefile~      Makefile       Makefile.orig  
[gingery@ca-fe tests]$ cp Makefile.orig Mak
Makefile~      Makefile       Makefile.orig  
[gingery@ca-fe tests]$ cp Makefile.orig Makefile
[gingery@ca-fe tests]$ make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
oshcc -g -O0 -Wall single_tests/broadcast1.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/broadcast1
oshcc -g -O0 -Wall single_tests/testMultiSendRcv.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/testMultiSendRcv
[gingery@ca-fe tests]$ emacs Mak
Makefile~      Makefile       Makefile.orig  
[gingery@ca-fe tests]$ emacs Makefile
[gingery@ca-fe tests]$ df -a
Filesystem           1K-blocks      Used Available Use% Mounted on
tmpfs                        0         0         0   -  /
proc                         0         0         0   -  /proc
sysfs                        0         0         0   -  /sys
devpts                       0         0         0   -  /dev/pts
tmpfs                  2097152         0   2097152   0% /dev/shm
tmpfs                  2097152         0   2097152   0% /tmp
none                         0         0         0   -  /proc/sys/fs/binfmt_misc
sunrpc                       0         0         0   -  /var/lib/nfs/rpc_pipefs
192.168.0.155:/var/lib/perceus/vnfs
                     558779104 175607968 354786720  34% /var/lib/perceus/vnfs
10.129.0.1:/vol/users
                     8160437888 8160374272     63616 100% /users
10.129.0.1:/vol/projects
                     4080218944 303490944 3776728000   8% /usr/projects
panfs://10.131.0.1/  188403333024  14878416 188388454608   1% /panfs/pas8
panfs://10.132.0.1/  249795931200 22016616576 227779314624   9% /panfs/pas12a
panfs://10.136.0.1/  198817169920 26047519696 172769650224  14% /panfs/pas12b
[gingery@ca-fe tests]$ df -a
Filesystem           1K-blocks      Used Available Use% Mounted on
tmpfs                        0         0         0   -  /
proc                         0         0         0   -  /proc
sysfs                        0         0         0   -  /sys
devpts                       0         0         0   -  /dev/pts
tmpfs                  2097152         0   2097152   0% /dev/shm
tmpfs                  2097152         0   2097152   0% /tmp
none                         0         0         0   -  /proc/sys/fs/binfmt_misc
sunrpc                       0         0         0   -  /var/lib/nfs/rpc_pipefs
192.168.0.155:/var/lib/perceus/vnfs
                     558779104 175607968 354786720  34% /var/lib/perceus/vnfs
10.129.0.1:/vol/users
                     8160437888 8160374240     63648 100% /users
10.129.0.1:/vol/projects
                     4080218944 303490944 3776728000   8% /usr/projects
panfs://10.131.0.1/  188403333024  14878416 188388454608   1% /panfs/pas8
panfs://10.132.0.1/  249795931200 22016616576 227779314624   9% /panfs/pas12a
panfs://10.136.0.1/  198817169920 26047519696 172769650224  14% /panfs/pas12b
[gingery@ca-fe tests]$ wrk
[gingery@ca-fe src]$ make
oshcc -g -O0 -Wall -c mpi_to_openshmem.c -I/users/gingery/openshmem-1.0e_IBV/include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/  -L/users/gingery/openshmem-1.0e_IBV/lib -L/users/gingery/GASNet-1.20.2_standard/lib  
mpi_to_openshmem.c: In function ‘MPI_Init’:
mpi_to_openshmem.c:101: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Init_thread’:
mpi_to_openshmem.c:192: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘GetBufferOffset’:
mpi_to_openshmem.c:419: warning: dereferencing ‘void *’ pointer
mpi_to_openshmem.c: In function ‘MPI_Comm_create’:
mpi_to_openshmem.c:639: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Comm_dup’:
mpi_to_openshmem.c:751: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Send’:
mpi_to_openshmem.c:1798: error: ‘my_’ undeclared (first use in this function)
mpi_to_openshmem.c:1798: error: (Each undeclared identifier is reported only once
mpi_to_openshmem.c:1798: error: for each function it appears in.)
mpi_to_openshmem.c:1735: warning: unused variable ‘numBytes’
mpi_to_openshmem.c: In function ‘MPI_Isend’:
mpi_to_openshmem.c:1969: warning: format ‘%x’ expects type ‘unsigned int’, but argument 4 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Iprobe’:
mpi_to_openshmem.c:2462: warning: implicit declaration of function ‘sleep’
make: *** [mpi_to_openshmem.o] Error 1
[gingery@ca-fe src]$ emacs mp
mpi_to_openshmem.c~  mpi_to_openshmem.c   mpi_to_openshmem.h~  mpi_to_openshmem.h   mpi_to_openshmem.o 
[gingery@ca-fe src]$ emacs mpi_to_openshmem.c
[gingery@ca-fe src]$ make
oshcc -g -O0 -Wall -c mpi_to_openshmem.c -I/users/gingery/openshmem-1.0e_IBV/include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/  -L/users/gingery/openshmem-1.0e_IBV/lib -L/users/gingery/GASNet-1.20.2_standard/lib  
mpi_to_openshmem.c: In function ‘MPI_Init’:
mpi_to_openshmem.c:101: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Init_thread’:
mpi_to_openshmem.c:192: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘GetBufferOffset’:
mpi_to_openshmem.c:419: warning: dereferencing ‘void *’ pointer
mpi_to_openshmem.c: In function ‘MPI_Comm_create’:
mpi_to_openshmem.c:639: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Comm_dup’:
mpi_to_openshmem.c:751: warning: format ‘%x’ expects type ‘unsigned int’, but argument 6 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Send’:
mpi_to_openshmem.c:1735: warning: unused variable ‘numBytes’
mpi_to_openshmem.c: In function ‘MPI_Isend’:
mpi_to_openshmem.c:1969: warning: format ‘%x’ expects type ‘unsigned int’, but argument 4 has type ‘void *’
mpi_to_openshmem.c: In function ‘MPI_Iprobe’:
mpi_to_openshmem.c:2462: warning: implicit declaration of function ‘sleep’
mpi_to_openshmem.c: In function ‘MPI_Send’:
mpi_to_openshmem.c:1756: warning: ‘hash’ may be used uninitialized in this function
mpi_to_openshmem.c:1809: warning: ‘ret’ may be used uninitialized in this function
ar rvs libmpi_to_openshmem.a mpi_to_openshmem.o mlog.o 
r - mpi_to_openshmem.o
r - mlog.o
[gingery@ca-fe src]$ wrks ; make clean ; make
rm -rf *.o libmdhim.a
oshcc -g -O0 -Wall -c Mlog/mlog.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c client.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c local_client.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c data_store.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c partitioner.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c messages.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c range_server.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c mdhim_options.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c ds_leveldb.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
oshcc -g -O0 -Wall -c mdhim.c -I/users/hng/leveldb-1.12.0/include -I/src  -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard//include  -IMlog/ -Iuthash -I/users/hng/leveldb-1.12.0/include -L/usr/lib64 -L/users/hng/leveldb-1.12.0 -L/users/gingery/mpi_to_openshmem/src//src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard//lib/gasnet-ibv-par -libverbs -L/users/hng/leveldb-1.12.0 -DLEVELDB_SUPPORT
ar rvs libmdhim.a mdhim.o mlog.o client.o local_client.o data_store.o partitioner.o messages.o range_server.o mdhim_options.o ds_leveldb.o
ar: creating libmdhim.a
a - mdhim.o
a - mlog.o
a - client.o
a - local_client.o
a - data_store.o
a - partitioner.o
a - messages.o
a - range_server.o
a - mdhim_options.o
a - ds_leveldb.o
[gingery@ca-fe src]$ wrkt;make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
oshcc -g -O0 -Wall single_tests/broadcast1.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/broadcast1
/users/gingery/mpi_to_openshmem/src/libmpi_to_openshmem.a(mpi_to_openshmem.o): In function `mlog_filter':
/users/gingery/mpi_to_openshmem/src/Mlog/mlog.h:114: multiple definition of `bufferHash'
/tmp/ccV4rEH7.o:/users/gingery/mpi_to_openshmem/mdhimMods/tests/single_tests/broadcast1.c:15: first defined here
collect2: ld returned 1 exit status
make: *** [broadcast1] Error 1
[gingery@ca-fe tests]$ wrkt ; make
oshcc -g -O0 -Wall single_tests/lock.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/lock
single_tests/lock.c: In function ‘main’:
single_tests/lock.c:21: warning: implicit declaration of function ‘sleep’
oshcc -g -O0 -Wall single_tests/broadcast1.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/broadcast1
/users/gingery/mpi_to_openshmem/src/libmpi_to_openshmem.a(mpi_to_openshmem.o): In function `mlog_filter':
/users/gingery/mpi_to_openshmem/src/Mlog/mlog.h:114: multiple definition of `bufferHash'
/tmp/cc1hMYkA.o:/users/gingery/mpi_to_openshmem/mdhimMods/tests/single_tests/broadcast1.c:15: first defined here
collect2: ld returned 1 exit status
make: *** [broadcast1] Error 1
[gingery@ca-fe tests]$ emacs Mak
Makefile~      Makefile       Makefile.orig  
[gingery@ca-fe tests]$ emacs Makefile
[gingery@ca-fe tests]$ make
oshcc -g -O0 -Wall single_tests/testMultiSendRcv.c -I/users/hng/leveldb-1.12.0/include/leveldb -I/users/gingery/mdhim/src -I/users/gingery/mpi_to_openshmem/src -I/users/gingery/openshmem-1.0e_IBV//include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/ -Iuthash -I../src -I../src/uthash -L../src -L/users/hng/leveldb-1.12.0 -L/users/gingery/mdhim/src -L/users/gingery/mpi_to_openshmem/src -L/users/gingery/openshmem-1.0e_IBV//lib -L/users/gingery/GASNet-1.20.2_standard/lib  -lmdhim -L/usr/lib64 -lmpi_to_openshmem /users/gingery/openshmem-1.0e_IBV//lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ /users/hng/leveldb-1.12.0/libleveldb.a -o single_tests/testMultiSendRcv
/users/gingery/mpi_to_openshmem/src/libmpi_to_openshmem.a(mpi_to_openshmem.o): In function `mlog_filter':
/users/gingery/mpi_to_openshmem/src/Mlog/mlog.h:114: multiple definition of `bufferHash'
/tmp/ccLVYLse.o:/users/gingery/mpi_to_openshmem/mdhimMods/tests/single_tests/testMultiSendRcv.c:19: first defined here
collect2: ld returned 1 exit status
make: *** [testMultiSendRcv] Error 1
[gingery@ca-fe tests]$ wrk
[gingery@ca-fe src]$ make
ar rvs libmpi_to_openshmem.a mpi_to_openshmem.o mlog.o 
r - mpi_to_openshmem.o
r - mlog.o
[gingery@ca-fe src]$ emacs Makefile
[gingery@ca-fe src]$ make
make: Circular hashUtils.o <- hashUtils.o dependency dropped.
oshcc -g -O0 -Wall -c hashUtils.c -I/users/gingery/openshmem-1.0e_IBV/include -I/users/gingery/GASNet-1.20.2_standard/include -IMlog/  -L/users/gingery/openshmem-1.0e_IBV/lib -L/users/gingery/GASNet-1.20.2_standard/lib  
hashUtils.c:9:23: error: hashUtils.h: No such file or directory
hashUtils.c:33: error: expected declaration specifiers or ‘...’ before ‘MPI_Datatype’
hashUtils.c:33: error: expected declaration specifiers or ‘...’ before ‘requestType_t’
hashUtils.c: In function ‘AddBufferSpace’:
hashUtils.c:35: error: ‘MPID_Hash’ undeclared (first use in this function)
hashUtils.c:35: error: (Each undeclared identifier is reported only once
hashUtils.c:35: error: for each function it appears in.)
hashUtils.c:35: error: ‘hash’ undeclared (first use in this function)
hashUtils.c:38: error: ‘isMultiThreads’ undeclared (first use in this function)
hashUtils.c:39: warning: implicit declaration of function ‘pthread_mutex_lock’
hashUtils.c:39: error: ‘lockAddBufferSpace’ undeclared (first use in this function)
hashUtils.c:42: error: ‘FALSE’ undeclared (first use in this function)
hashUtils.c:44: warning: implicit declaration of function ‘HASH_FIND_INT’
hashUtils.c:44: error: ‘bufferHash’ undeclared (first use in this function)
hashUtils.c:47: error: ‘NULL’ undeclared (first use in this function)
hashUtils.c:49: error: ‘TRUE’ undeclared (first use in this function)
hashUtils.c:52: warning: implicit declaration of function ‘shfree’
hashUtils.c:57: error: expected expression before ‘)’ token
hashUtils.c:60: error: ‘ret’ undeclared (first use in this function)
hashUtils.c:60: error: ‘MPI_ERR_BUFFER’ undeclared (first use in this function)
hashUtils.c:63: warning: implicit declaration of function ‘pthread_mutex_unlock’
hashUtils.c:65: warning: ‘return’ with a value, in function returning void
hashUtils.c:68: error: ‘MPI_SUCCESS’ undeclared (first use in this function)
hashUtils.c:78: error: ‘numBytes’ undeclared (first use in this function)
hashUtils.c:78: warning: implicit declaration of function ‘GetNumBytes’
hashUtils.c:78: error: ‘datatype’ undeclared (first use in this function)
hashUtils.c:79: warning: implicit declaration of function ‘shmalloc’
hashUtils.c:85: error: ‘lockSend’ undeclared (first use in this function)
hashUtils.c:87: warning: ‘return’ with a value, in function returning void
hashUtils.c:97: error: ‘my_pe’ undeclared (first use in this function)
hashUtils.c:98: error: ‘dest’ undeclared (first use in this function)
hashUtils.c:99: error: ‘requestType’ undeclared (first use in this function)
hashUtils.c:102: error: ‘time_t’ undeclared (first use in this function)
hashUtils.c:102: error: expected ‘;’ before ‘mytime’
hashUtils.c:103: error: ‘mytime’ undeclared (first use in this function)
hashUtils.c:103: warning: implicit declaration of function ‘time’
hashUtils.c:104: warning: implicit declaration of function ‘printf’
hashUtils.c:104: warning: incompatible implicit declaration of built-in function ‘printf’
hashUtils.c:105: warning: implicit declaration of function ‘ctime’
make: *** [hashUtils.o] Error 1
[gingery@ca-fe src]$ emacs Mak
Makefile~  Makefile   
[gingery@ca-fe src]$ emacs Makefile

File Edit Options Buffers Tools Makefile Help                                                                      
_ROOT   = /usr/local
#OPENSHMEM_ROOT = /users/gingery/openshmem-1.0d_UDP                                                                
OPENSHMEM_ROOT = /users/gingery/openshmem-1.0e_IBV

GASNET_ROOT     = /users/gingery/GASNet-1.20.2_standard

CC      = oshcc -g -O0 -Wall
#CLIBS  = -L${MPI_ROOT}/lib -L${OPENSHMEM_ROOT}/lib -L${GASNET_ROOT}/lib                                           
#CINC   = -I${MPI_ROOT}/include -I${OPENSHMEM_ROOT}/include -I${GASNET_ROOT}/include -IMlog/                       
CLIBS   = -L${OPENSHMEM_ROOT}/lib -L${GASNET_ROOT}/lib
CINC    = -I${OPENSHMEM_ROOT}/include -I${GASNET_ROOT}/include -IMlog/

FLAGS   =  -lopenshmem -L/usr/lib64 -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++


OBJS    = mlog.o
all:    mlog.o mpi_to_openshmem.o lib

hashUtils.o: hashUtils.c $(OBJS)
        $(CC) -c $< $(CINC) $(CLIBS) $(CFLAGS) 

mpi_to_openshmem.o: mpi_to_openshmem.c $(OBJS)
        $(CC) -c $< $(CINC) $(CLIBS) $(CFLAGS) 

mlog.o: Mlog/mlog.c
        $(CC) -c $^ $(CINC) $(CLIBS) $(CFLAGS) 

lib:
        ar rvs libmpi_to_openshmem.a mpi_to_openshmem.o $(OBJS)

clean:
        rm -rf *.o libmpi_to_openshmem.a



































-UU-:----F1  Makefile       All L1     (GNUmakefile)---------------------------------------------------------------
Loading vc-git...done
