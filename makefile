CC = g++
CFLAGS = -g -Wall -Wextra

default: collection

collection: library.o main.o
	$(CC) $(CFLAGS) -o collection library.o main.o

library.o: library.cpp library.h
	$(CC) $(CFLAGS) -c library.cpp

main.o: main.cpp library.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) *.o *~ collection
