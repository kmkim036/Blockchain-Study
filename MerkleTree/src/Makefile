execs := merkletree

SHA256 = ../../SHA256/src/sha256.o

# build
merkletree: main.o merkletree.o $(SHA256)
	gcc -o merkletree main.o merkletree.o $(SHA256) -lm

# clean
.PHONY: clean
clean:
	-rm -f *.o
	-rm -f $(SHA256)
	-rm -f $(execs)
