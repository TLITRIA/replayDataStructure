main:doubleLinkListQueue.o myDoubleLinkList.o main.o
	gcc doubleLinkListQueue.o myDoubleLinkList.o main.o -o main

doubleLinkListQueue.o:doubleLinkListQueue.c
	gcc -c doubleLinkListQueue.c -o doubleLinkListQueue.o

myDoubleLinkList.o:myDoubleLinkList.c
	gcc -c myDoubleLinkList.c -o myDoubleLinkList.o

main.o:main.c
	gcc -c main.c -o main.o

clean:
	@rm -rf *.o main