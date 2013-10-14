_ROOT	= /usr/local
#OPENSHMEM_ROOT	= /users/gingery/openshmem-1.0d_UDP
OPENSHMEM_ROOT = /users/gingery/openshmem-1.0e_IBV

GASNET_ROOT	= /users/gingery/GASNet-1.20.2_standard

CC	= mpicc -g -O0 -Wall
#CLIBS	= -L${MPI_ROOT}/lib -L${OPENSHMEM_ROOT}/lib -L${GASNET_ROOT}/lib
#CINC	= -I${MPI_ROOT}/include -I${OPENSHMEM_ROOT}/include -I${GASNET_ROOT}/include -IMlog/ 
CLIBS	= -L${OPENSHMEM_ROOT}/lib -L${GASNET_ROOT}/lib
CINC	= -I${OPENSHMEM_ROOT}/include -I${GASNET_ROOT}/include -IMlog/ 

FLAGS	=  -lopenshmem -L/usr/lib64 -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++


OBJS    = mlog.o 
all:	mpi_to_openshmem.o lib

mpi_to_openshmem.o: mpi_to_openshmem.c $(OBJS)
	$(CC) -c $< $(CINC) $(CLIBS) $(CFLAGS) 

mlog.o: Mlog/mlog.c
	$(CC) -c $^ $(CINC) $(CLIBS) $(CFLAGS) 

lib:	
	ar rvs libmpi_to_openshmem.a mpi_to_openshmem.o $(OBJS)

clean:
	rm -rf *.o libmpi_to_openshmem.a

