clean:
	rm a.out *.o
main.o:
	gcc -c main.c
all:
	gcc main.o -o a.out	
