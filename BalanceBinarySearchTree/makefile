test:main.o binarySearchTree.o doubleLinkList.o doubleLinkListQueue.o
	gcc  main.o binarySearchTree.o doubleLinkList.o doubleLinkListQueue.o -o test

main.o:main.c
	gcc -c main.c -o main.o

binarySearchTree.o:binarySearchTree.c
	gcc -c binarySearchTree.c -o binarySearchTree.o

doubleLinkList.o:doubleLinkList.c
	gcc -c doubleLinkList.c -o doubleLinkList.o

doubleLinkListQueue.o:doubleLinkListQueue.c
	gcc -c doubleLinkListQueue.c -o doubleLinkListQueue.o

clean:
	@rm -rf *.o test