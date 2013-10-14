MPI_ROOT	= /usr/local
LEVEL_DB_ROOT   = /users/hng/leveldb-1.12.0
MDHIM_ROOT	 = /users/gingery/mdhim/src

MPI_TO_OPENSHMEM_ROOT	= /users/gingery/mpi_to_openshmem/src
OPENSHMEM_ROOT	= /users/gingery/openshmem-1.0e_IBV/
GASNET_ROOT	= /users/gingery/GASNet-1.20.2_standard

CC	= oshcc -g -O0 -Wall
CLIBS   =  -L../src -L${LEVEL_DB_ROOT} -L${MDHIM_ROOT} -L${MPI_TO_OPENSHMEM_ROOT} -L${OPENSHMEM_ROOT}/lib -L${GASNET_ROOT}/lib 
CINC    = -I${LEVEL_DB_ROOT}/include/leveldb -I${MDHIM_ROOT}-I${MDHIMNET_ROOT} -I${OPENSHMEM_ROOT}/include -I${GASNET_ROOT}/include -IMlog/ -Iuthash -I../src -I../src/uthash
#CLIBS	= -L${MPI_ROOT}/lib  -L../src -L${LEVEL_DB_ROOT}
#CINC	= -I${MPI_ROOT}/include -I${LEVEL_DB_ROOT}/include -IMlog/ -Iuthash -I../src -I../src/uthash
SINGLE = single_tests
TESTER = tester
CFLAGS	= -lmdhim -L/usr/lib64 -lmpi_to_openshmem ${OPENSHMEM_ROOT}/lib/libopenshmem.so -lgasnet-ibv-par -libverbs -lm -lpthread -lstdc++ ${LEVEL_DB_ROOT}/libleveldb.a
#CFLAGS  = -lmpich -lmdhim -lm -lpthread -lstdc++ ${LEVEL_DB_ROOT}/libleveldb.a


all:   hello simple2 simple put-get puts-gets put-getn put-getp put-del bput-bget bput-bgetn bput-bdel mdhintst
hello: $(SINGLE)/hello.c
	$(CC) $< $(CINC) $(CLIBS) $(CFLAGS) -o $(SINGLE)/$@

simple2: $(SINGLE)/simple2.c
	$(CC) $< $(CINC) $(CLIBS) $(CFLAGS) -o $(SINGLE)/$@

simple: $(SINGLE)/simple.c
	$(CC) $< $(CINC) $(CLIBS) $(CFLAGS) -o $(SINGLE)/$@

put-get: $(SINGLE)/put-get.c 
	$(CC) $< $(CINC) $(CLIBS) $(CFLAGS) -o $(SINGLE)/$@

puts-gets: $(SINGLE)/puts-gets.c 
	$(CC) $< $(CINC) $(CLIBS) $(CFLAGS) -o $(SINGLE)/$@

put-getn: $(SINGLE)/put-getn.c 
	$(CC) $< $(CINC) $(CLIBS) $(CFLAGS) -o $(SINGLE)/$@

put-getp: $(SINGLE)/put-getp.c 
	$(CC) $< $(CINC) $(CLIBS) $(CFLAGS) -o $(SINGLE)/$@

put-del: $(SINGLE)/put-del.c 
	$(CC) $< $(CINC) $(CLIBS) $(CFLAGS) -o $(SINGLE)/$@

bput-bget: $(SINGLE)/bput-bget.c 
	$(CC) $< $(CINC) $(CLIBS) $(CFLAGS) -o $(SINGLE)/$@

bput-bgetn: $(SINGLE)/bput-bgetn.c 
	$(CC) $< $(CINC) $(CLIBS) $(CFLAGS) -o $(SINGLE)/$@

bput-bdel: $(SINGLE)/bput-bdel.c 
	$(CC) $< $(CINC) $(CLIBS) $(CFLAGS) -o $(SINGLE)/$@

mdhimtst: $(TESTER)/mdhimtst.c
	$(CC) $< $(CINC) $(CLIBS) $(CFLAGS) -o $(TESTER)/$@

clean:
	rm -rf $(SINGLE)/put-get $(SINGLE)/bput-bget $(SINGLE)/put-del $(SINGLE)/bput-bdel\
               $(TESTER)/mdhimtst $(SINGLE)/put-getn \
	       $(SINGLE)/put-getp $(SINGLE)/puts-gets \
               $(SINGLE)/bput-bgetn
