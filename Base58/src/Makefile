execs := base58

# build
base58: main.o base58.o
	gcc -o base58 main.o base58.o

# clean
.PHONY: clean
clean:
	-rm -f *.o
	-rm -f $(execs)
