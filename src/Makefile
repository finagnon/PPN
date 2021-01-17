CC=gcc
EXE=main

.PHONY: clean main

all: main

main: main.c 
	$(CC) main.c fixed_tools.c -o $(EXE)

clean:
	rm -Rf *~ *.o $(EXE)
