
# $@ - the file on the left side of the :
# $< - the first name in the dependencies list
# $^ - the right side of :

all: dir_traversal
dir_traversal: dir_traversal.o 
	gcc -o $@ $^
dir_traversal.o: dir_traversal.c
	gcc -c $<
	
.PHONY: clean all

clean:
	rm -f *.o dir_traversal
