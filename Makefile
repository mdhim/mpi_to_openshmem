.PHONY: mpi_to_openshmem

all: mpi_to_openshmem

mpi_to_openshmem:
	make -C src

clean:
	make -C src clean

