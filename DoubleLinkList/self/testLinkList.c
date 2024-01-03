#include <stdio.h>
#include "doubleLinkList.h"
#include "common.h"


int printFunc(ELEMENTTYPE arg)
{
    int info = (void *)arg;
    printf("data:%d\n", info);
}


int compareFunc(ELEMENTTYPE arg1, ELEMENTTYPE arg2)
{
    int val1 = (void *)arg1;
    int val2 = (void *)arg2;
    return (val1 == val2) ? 1 : 0;
}




int main()
{
    DoubleLinkList *list1 = (DoubleLinkList *)malloc(sizeof(DoubleLinkList) * 1);
    JUDGE_MALLOC_ERROR(list1);
    memset(list1, 0, sizeof(list1));


    doubleLinkListInit(list1, compareFunc, printFunc);

    int buffer[] = {1, 2, 3, 5, 6};
    int len = sizeof(buffer) / sizeof(buffer[0]);

    for (int idx = 0; idx < len; idx++)
    {
        doubleLinkListInsertTail(list1, (ELEMENTTYPE *)&buffer[idx]);
    }

    doubleLinkListForeach(list1);

    return ON_SUCCESS;
}