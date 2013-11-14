MPI_ROOT	= /usr/local
LEVEL_DB_ROOT   = /users/hng/leveldb-1.12.0
MDHIM_ROOT	 = /users/gingery/mdhim/src

MPI_TO_OPENSHMEM_ROOT	= /users/gingery/mpi_to_openshmem/src
OPENSHMEM_ROOT	= /users/gingery/openshmem-1.0e_IBV/
GASNET_ROOT	= /users/gingery/GASNet-1.20.2_standard

CC	= oshcc -g -O0 -Wall
CLIBS   =  -L../src -L${LEVEL_DB_ROOT} -L${MDHIM_ROOT} -L${MPI_TO_OPENSHMEM_ROOT} -L${OPENSHMEM_ROOT}/lib -L${GASNET_ROOT}/lib 
CINC    = -I${LEVEL_DB_ROOT}/include/leveldb -I${MDHIM_ROOT} -I${MPI_TO_OPENSHMEM_ROOT} -I${OPENSHMEM_ROOT}/include -I${GASNET_ROOT}/include -IMlog/ -Iuthash -I../src -I../src/uthash
#CLIBS	= -L${MPI_ROOT}/lib  -L../src -L${LEVEL_DB_ROOT}
#CINC	= -I${MPI_ROOT}/include -I${LEVEL_DB_ROOT}/include -IMlog/ -Iuthash -I../src -I../src/uthash
SINGLE = single_tests
TESTER = testeråçå
CFLAGS	= -lmdhim -L/usr/lib64 -lmpi_to_openshmem ${OPENSHMEM_ROOT}/lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ ${LEVEL_DB_ROOT}/libleveldb.a
#CFLAGS  = -lmpich -lmdhim -lm -lpthread -lstdc++ ${LEVEL_DB_ROOT}/libleveldb.a

#all:	startPesExample broadcast1 testStart testSendRcv sendRcvChar isendiRecv gather allgather gatherv mpi_test_int mpi_test_char
all:	mpi_test

startPesExample: $(SINGLE)/startPesExample.c
	$(CC) $< $(CINC) $(CLIBS) $(CFLAGS) -o $(SINGLE)/$@

testStart: $(SINGLE)/testStart.c
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

clean:
	rm -rf $(SINGLE)/startPesExample $(SINGLE)/broadcast1 $(SINGLE)/testStart $(SINGLE)/testSendRcv\
               $(SINGLE)/sendRcvChar
