# MakeFile

CC = gcc


all: compiler 

compiler: compiler.c
	$(CC) -o compiler compiler.c

clean:
	rm -f compiler
