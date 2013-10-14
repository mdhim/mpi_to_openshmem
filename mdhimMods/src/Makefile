#MPI_ROOT	= /usr/local
LEVEL_DB_ROOT   = /users/hng/leveldb-1.12.0
MPI_TO_OPENSHMEM_ROOT	= /users/gingery/mpi_to_openshmem/src/
OPENSHMEM_ROOT	= /users/gingery/openshmem-1.0e_IBV/
GASNET_ROOT		= /users/gingery/GASNet-1.20.2_standard/

CC		= mpicc -g -O0 -Wall
CLIBS	= -L/usr/lib64 -L${LEVEL_DB_ROOT} -L${MPI_TO_OPENSHMEM_ROOT}/src -L${OPENSHMEM_ROOT}/lib -L${GASNET_ROOT}/lib/gasnet-ibv-par -libverbs
CINC	=  -I${LEVEL_DB_ROOT}/include -I${MPI_TO_OPENSHMEM__ROOT}/src  -I${OPENSHMEM_ROOT}/include -I${GASNET_ROOT}/include  -IMlog/ -Iuthash
#CLIBS  = -L${MPI_ROOT}/lib -L${LEVEL_DB_ROOT}
#CINC   = -I${MPI_ROOT}/include -I${LEVEL_DB_ROOT}/include -IMlog/ -Iuthash
CFLAGS	= 

OBJS    = mlog.o unqlite.o client.o local_client.o data_store.o ds_unqlite.o ds_leveldb.o partitioner.o messages.o range_server.o db_options.o
all:	mdhim.o lib

mdhim.o: mdhim.c $(OBJS)
	$(CC) -c $< $(CINC) $(CLIBS)

mlog.o: Mlog/mlog.c
	$(CC) -c $^ $(CINC) $(CLIBS)

unqlite.o: unqlite.c
	$(CC) -c $^ $(CINC) $(CLIBS)

client.o: client.c
	$(CC) -c $^ $(CINC) $(CLIBS)

local_client.o: local_client.c
	$(CC) -c $^ $(CINC) $(CLIBS)

messages.o: messages.c
	$(CC) -c $^ $(CINC) $(CLIBS)

partitioner.o: partitioner.c
	$(CC) -c $^ $(CINC) $(CLIBS)

data_store.o: data_store.c
	$(CC) -c $^ $(CINC) $(CLIBS)

ds_unqlite.o: ds_unqlite.c
	$(CC) -c $^ $(CINC) $(CLIBS)

ds_leveldb.o: ds_leveldb.c
	$(CC) -c $^ $(CINC) $(CLIBS)

range_server.o: range_server.c
	$(CC) -c $^ $(CINC) $(CLIBS)
	
db_options.o : db_options.c
	$(CC) -c $^ $(CINC) $(CLIBS)

lib:	
	ar rvs libmdhim.a mdhim.o $(OBJS)

clean:
	rm -rf *.o libmdhim.a
