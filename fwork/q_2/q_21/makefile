
# $@ - the file on the left side of the :
# $< - the first name in the dependencies list
# $^ - the right side of :

all: check_pid
check_pid: check_pid.o 
	gcc -o $@ $^
check_pid.o: check_pid.c
	gcc -c $<

.PHONY: clean all

clean:
	rm -f *.o check_pid