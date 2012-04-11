PYTHON_VER=2.7

CC=gcc
CCFLAGS=-I/usr/include/python$(PYTHON_VER) -Wall -O -fPIC
LDFLAGS=-shared

all: mema_bare mema_methods mema_exceptions



mema_bare: mema_bare.o
	$(CC) $(LDFLAGS) mema_bare.o -o mema_bare.so

mema_bare.o: mema_bare.c
	$(CC) $(CCFLAGS) -c mema_bare.c -o mema_bare.o


mema_methods: mema_methods.o
	$(CC) $(LDFLAGS) mema_methods.o -o mema_methods.so

mema_methods.o: mema_methods.c
	$(CC) $(CCFLAGS) -c mema_methods.c -o mema_methods.o


mema_exceptions: mema_exceptions.o
	$(CC) $(LDFLAGS) mema_exceptions.o -o mema_exceptions.so

mema_exceptions.o: mema_exceptions.c
	$(CC) $(CCFLAGS) -c mema_exceptions.c -o mema_exceptions.o


clean:
	rm -f *.o

dist-clean: clean
	rm -f *.so
