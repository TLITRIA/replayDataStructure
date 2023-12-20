#include <stdio.h>
#include "LinkList.h"
#include <string.h>

#define BUFFRE_SIZE 20


int main()
{
#if 1

    LinkList linkList;
    LinkListInit(&linkList);

    /* 初始化数据 */
    ELEMENTTYPE newData = 1;
    // LinkNode newNode;
    // memset(&newNode, 0, sizeof(newNode));
    // newNode.data = newData;
    // newNode.next = NULL;


    /* 插入数据 */
    LinkListTailInsert(&linkList, newData);
    for (int idx = 0; idx < BUFFRE_SIZE; idx++)
    {

    }


#endif
    return 0;
}