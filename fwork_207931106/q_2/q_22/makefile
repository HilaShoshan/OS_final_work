
# $@ - the file on the left side of the :
# $< - the first name in the dependencies list
# $^ - the right side of :

all: client server
client: client.o 
	gcc -o $@ $^
client.o: client.c
	gcc -c $<
server: server.o
	gcc -o $@ $^
server.o: server.c
	gcc -c $<
	
.PHONY: clean all

clean:
	rm -f *.o check_pid