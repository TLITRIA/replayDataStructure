test:main.o binarySearchTree.o doubleLinkList.o doubleLinkListQueue.o
	gcc -g main.o binarySearchTree.o doubleLinkList.o doubleLinkListQueue.o -o test

main.o:main.c
	gcc -g -c main.c -o main.o

binarySearchTree.o:binarySearchTree.c
	gcc -g -c binarySearchTree.c -o binarySearchTree.o

doubleLinkList.o:doubleLinkList.c
	gcc -g -c doubleLinkList.c -o doubleLinkList.o

doubleLinkListQueue.o:doubleLinkListQueue.c
	gcc -g -c doubleLinkListQueue.c -o doubleLinkListQueue.o

clean:
	@rm -rf *.o test