test01:main.o dynamicArray.o
	gcc main.o dynamicArray.o -o test01

main.o:main.c
	gcc -c main.c -o main.o

dynamicArray.o:dynamicArray.c
	gcc -c dynamicArray.c -o dynamicArray.o

clean:
	@rm -rf *.o test01