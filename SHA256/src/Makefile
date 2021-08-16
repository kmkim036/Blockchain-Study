execs := sha256

# build
sha256: sha256.o
	gcc -o sha256 sha256.o

# clean
.PHONY: clean
clean:
	-rm -f *.o
	-rm -f $(execs)
