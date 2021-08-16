execs := sha256

# build
sha256: main.o sha256.o
	gcc -o sha256 main.o sha256.o

# clean
.PHONY: clean
clean:
	-rm -f *.o
	-rm -f $(execs)
