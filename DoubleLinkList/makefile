test02:myTest.o myDoubleLinkList.o
	gcc myTest.o myDoubleLinkList.o -o test02

myTest.o:myTest.c
	gcc -c myTest.c -o myTest.o

myDoubleLinkList.o:myDoubleLinkList.c
	gcc -c myDoubleLinkList.c -o myDoubleLinkList.o

clean:
	@rm -rf *.o test02