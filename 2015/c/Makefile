CC=cc
CFLAGS=-std=c90 -pedantic -Wall

all: input.o day01

input.o: input.c input.h
	$(CC) $(CFLAGS) -c -o input.o input.c

day01: day01.c input.o
	$(CC) $(CFLAGS) -o day01 day01.c input.o
