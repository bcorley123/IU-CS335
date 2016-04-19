CC = gcc
CFLAGS = -g
LDFLAGS = 


hw6.c: hw6.o
	$(CC) $(LDFLAGS) -o hw6 hw6.c

hw6.o: hw6.c 
	$(CC) $(LDFLAGS) -c  hw6.c



clean:
	-rm -f hw6.o
	-rm -f hw6 
