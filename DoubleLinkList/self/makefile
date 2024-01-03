all:testLinkList

# 双向链表测试
testLinkList:doubleLinkList.o mainLinkList.o
	gcc doubleLinkList.o mainLinkList.o -o testLinkList

doubleLinkList.o:doubleLinkList.c
	gcc -c doubleLinkList.c -o doubleLinkList.o

mainLinkList.o:mainLinkList.c
	gcc -c mainLinkList.c -o mainLinkList.o

clean:
	@rm -rf *.o testLinkList