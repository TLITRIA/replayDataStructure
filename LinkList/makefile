test02:myTest.o myLinkList.o
	gcc -g myTest.o myLinkList.o -o test02

myTest.o:myTest.c
	gcc -c myTest.c -o myTest.o

myLinkList.o:myLinkList.c
	gcc -c myLinkList.c -o myLinkList.o

clean:
	@rm -rf *.o test02