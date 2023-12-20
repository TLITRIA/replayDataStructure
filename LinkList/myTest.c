#include <stdio.h>
#include "myLinkList.h"

#define BUFFER_SIZE 3

#define PRINT_INT(num) \
printf("%s:%d\n", #num, num);\

int main()
{
    //初始化
    LinkList *myList = NULL;
    myLinkListInit(&myList);
    //插入数据
    ELEMENTTYPE buffer[BUFFER_SIZE] = {1, 2, 3};
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        myLinkListInsertTail(myList, buffer[idx]);
        // myLinkListInsertHead(myList, buffer[idx]);
        
    }

    int size = 0;
    myLinkListGetLength(myList, &size);
    PRINT_INT(size);

    myLinkListForeach(myList);


    return 0;
}