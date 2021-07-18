all: bf

bf: main.o bloom_filter.o test.o mylib.a
	gcc -lm -std=c11 -pedantic -Wall -Wextra -o bf main.o test.o mylib.a

main.o: main.c
	gcc -O -c main.c

test.o: test/test.c test/test.h
	gcc -O -c test.c test.h

bloom_filter.o: bloom_filter/bloom_filter.c bloom_filter/bloom_filter.h
	gcc -c bloom_filter.c bloom_filter.h

mylib.a: bloom_filter.o
	ar rcs mylib.a bloom_filter.o

libs: libmylib.a
