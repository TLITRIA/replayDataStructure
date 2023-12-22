test01:main.o doubleLinkList.o
	gcc main.o doubleLinkList.o -o test01

main.o:main.c
	gcc -c main.c -o main.o

doubleLinkList.o:doubleLinkList.c
	gcc -c doubleLinkList.c -o doubleLinkList.o

clean:
	@rm -rf *.o test01