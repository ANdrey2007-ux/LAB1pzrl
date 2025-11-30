ARGS ?= 
clean:
	rm a.out *.o
main.o:
	gcc -c main.c
calc.o:
	gcc -c calc.c
all:
	gcc main.o calc.o -o a.out
run:
	./a.out $(ARGS)	
