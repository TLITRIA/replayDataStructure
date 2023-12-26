test:main.o dynamicArrayStack.o
	gcc -g main.o dynamicArrayStack.o -o test

main.o:main.c
	gcc -c main.c -o main.o

dynamicArrayStack.o:dynamicArrayStack.c
	gcc -c dynamicArrayStack.c -o dynamicArrayStack.o

clean:
	@rm -rf *.o test