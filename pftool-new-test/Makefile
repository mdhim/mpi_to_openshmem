makeMPI_TO_OPENSHMEM_ROOT	= /users/gingery/mpi_to_openshmem/src
OPENSHMEM_ROOT		= /users/gingery/openshmem-1.0e_IBV/
GASNET_ROOT		= /users/gingery/GASNet-1.20.2_standard
MPI_ROOT 		= /usr/local

DLIB		=	-L/usr/lib64 -L/users/gingery/mpi_to_openshmem/src -lmpi_to_openshmem ${OPENSHMEM_ROOT}/lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ 
MPICC		=	oshcc -g -O0 -Wall -I${MPI_TO_OPENSHMEM_ROOT} -I${OPENSHMEM_ROOT}/include -I${GASNET_ROOT}/include
MPICLIBS	=	-L${MPI_TO_OPENSHMEM_ROOT} -L${OPENSHMEM_ROOT}/lib -L${GASNET_ROOT}/lib
SOURCEDIR 	= src

all: pftool

pftool: pftool.o str.o perfstat.o cmp.o fchunktbl.o fileinfo.o pathinfo.o workitem.o workq.o workreq.o scheduler.o converse.o pwt.o treewalk.o worker.o manager.o

	$(MPICC) $(MPICLIBS) $(DLIB)  pftool.o str.o perfstat.o cmp.o fchunktbl.o fileinfo.o pathinfo.o workitem.o workq.o workreq.o scheduler.o converse.o pwt.o treewalk.o worker.o manager.o  /users/gingery/mpi_to_openshmem/src/libmpi_to_openshmem.a ${OPENSHMEM_ROOT}/lib/libopenshmem.so -o pftool

pftool.o: $(SOURCEDIR)/pftool.c $(SOURCEDIR)/pftool.h 
	$(MPICC) $(CFLAGS) $(DLIB) -c $(SOURCEDIR)/pftool.c

pfutils.o: $(SOURCEDIR)/pfutils.c $(SOURCEDIR)/pfutils.h 
	$(MPICC) $(CFLAGS) $(GENERIC_FS_FLAGS) -c $(SOURCEDIR)/pfutils.c

str.o: $(SOURCEDIR)/str.c $(SOURCEDIR)/str.h 
	$(MPICC) $(CFLAGS) $(GENERIC_FS_FLAGS) -c $(SOURCEDIR)/str.c

converse.o: $(SOURCEDIR)/pwt/converse.c $(SOURCEDIR)/pwt/converse.h 
	$(MPICC) $(CFLAGS) $(GENERIC_FS_FLAGS) -c $(SOURCEDIR)/pwt/converse.c

pathinfo.o: $(SOURCEDIR)/apps/pathinfo.c $(SOURCEDIR)/apps/pathinfo.h 
	$(MPICC) $(CFLAGS) $(GENERIC_FS_FLAGS) -c $(SOURCEDIR)/apps/pathinfo.c

workq.o: $(SOURCEDIR)/pwt/workq.c $(SOURCEDIR)/pwt/workq.h 
	$(MPICC) $(CFLAGS) $(GENERIC_FS_FLAGS) -c $(SOURCEDIR)/pwt/workq.c

workitem.o: $(SOURCEDIR)/pwt/workitem.c $(SOURCEDIR)/pwt/workitem.h 
	$(MPICC) $(CFLAGS) $(GENERIC_FS_FLAGS) -c $(SOURCEDIR)/pwt/workitem.c

perfstat.o: $(SOURCEDIR)/pwt/perfstat.c $(SOURCEDIR)/pwt/perfstat.h
	$(MPICC) $(CFLAGS) $(GENERIC_FS_FLAGS) -c $(SOURCEDIR)/pwt/perfstat.c

workreq.o: $(SOURCEDIR)/pwt/workreq.c $(SOURCEDIR)/pwt/workreq.h
	$(MPICC) $(CFLAGS) $(GENERIC_FS_FLAGS) -c $(SOURCEDIR)/pwt/workreq.c

scheduler.o: $(SOURCEDIR)/pwt/scheduler.c $(SOURCEDIR)/pwt/scheduler.h 
	$(MPICC) $(CFLAGS) $(GENERIC_FS_FLAGS) -c $(SOURCEDIR)/pwt/scheduler.c

pwt.o: $(SOURCEDIR)/pwt/pwt.c $(SOURCEDIR)/pwt/pwt.h 
	$(MPICC) $(CFLAGS) $(GENERIC_FS_FLAGS) -c $(SOURCEDIR)/pwt/pwt.c

cmp.o: $(SOURCEDIR)/apps/cmp.c $(SOURCEDIR)/apps/cmp.h
	$(MPICC) $(CFLAGS) $(GENERIC_FS_FLAGS) -c $(SOURCEDIR)/apps/cmp.c

fchunktbl.o: $(SOURCEDIR)/apps/fchunktbl.c $(SOURCEDIR)/apps/fchunktbl.h
	$(MPICC) $(CFLAGS) $(GENERIC_FS_FLAGS) -c $(SOURCEDIR)/apps/fchunktbl.c

fileinfo.o: $(SOURCEDIR)/apps/fileinfo.c $(SOURCEDIR)/apps/fileinfo.h
	$(MPICC) $(CFLAGS) $(GENERIC_FS_FLAGS) -c $(SOURCEDIR)/apps/fileinfo.c

treewalk.o: $(SOURCEDIR)/apps/treewalk.c $(SOURCEDIR)/apps/treewalk.h 
	$(MPICC) $(CFLAGS) $(GENERIC_FS_FLAGS) -c $(SOURCEDIR)/apps/treewalk.c

worker.o: $(SOURCEDIR)/pwt/worker.c $(SOURCEDIR)/pwt/worker.h 
	$(MPICC) $(CFLAGS) $(GENERIC_FS_FLAGS) -c $(SOURCEDIR)/pwt/worker.c

manager.o: $(SOURCEDIR)/pwt/manager.c $(SOURCEDIR)/pwt/manager.h 
	$(MPICC) $(CFLAGS) $(GENERIC_FS_FLAGS) -c $(SOURCEDIR)/pwt/manager.c

clean:
	- /bin/rm -f *~
	- /bin/rm -f *.o
	- /bin/rm -f *.x
	- /bin/rm -f pftool

