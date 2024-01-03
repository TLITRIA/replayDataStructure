all:testLinkList

# 双向链表测试
testLinkList:doubleLinkList.o testLinkList.o
	gcc -g doubleLinkList.o testLinkList.o -o testLinkList

doubleLinkList.o:doubleLinkList.c
	gcc -c -g doubleLinkList.c -o doubleLinkList.o

testLinkList.o:testLinkList.c
	gcc -c -g testLinkList.c -o testLinkList.o

clean:
	@rm -rf *.o testLinkList