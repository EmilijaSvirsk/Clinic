CC=gcc
CFLAGS=-I.

polik: polikgraph.o queue.o big_int_functions.o generate_func.o work_func.o
	$(CC) -o polikgraph polikgraph.o queue.o big_int_functions.o generate_func.o work_func.o
