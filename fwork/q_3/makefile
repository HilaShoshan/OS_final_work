
# $@ - the file on the left side of the :
# $< - the first name in the dependencies list
# $^ - the right side of :

all: set_policy
set_policy: set_policy.o 
	gcc -o $@ $^
set_policy.o: set_policy.c
	gcc -c $<
	
.PHONY: clean all

clean:
	rm -f *.o set_policy
