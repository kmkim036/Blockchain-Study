execs := merkletree

# build
merkletree: merkletree.o
	gcc -o merkletree merkletree.o

# clean
.PHONY: clean
clean:
	-rm -f *.o
	-rm -f $(execs)

