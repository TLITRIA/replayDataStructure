#include <stdio.h>
#include "doubleLinkListQueue.h"

#define BUFFER_SIZE 5

typedef struct stuInfo
{
    int age;
    char sex;
} stuInfo; 


int printFuncInt(void *arg)
{
    int data = *(int *)arg;
    printf("info:%d\n", data);
}

int compareFuncInt(void *arg1, void *arg2)
{
    return (arg1 == arg2) ? 1 : 0;
}
/* 对stuInfo特化打印 */
int printFuncStuInfo(void *arg)
{
    stuInfo * info = (stuInfo*)arg;
    printf("age:%d, sex:%c\n", info->age, info->sex);
}

int compareFuncStuInfo(void *arg1, void *arg2)
{/* 相同则返回1 */
    stuInfo *info1 = (void *)arg1;
    stuInfo *info2 = (void *)arg2;
    return (info1->age == info2->age && info1->sex == info2->sex) ? 1 : 0;
}


int main()
{
    DoubleLinkListQueue *queue = NULL;
    doubleLinkListQueueInit(&queue, compareFuncInt, printFuncInt);

    int buffer[BUFFER_SIZE] = {111, 222, 333, 444, 555};
    
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        doubleLinkListQueuePush(queue, (void *)&buffer[idx]);
    }

    int size = 0;
    doubleLinkListQueueGetSize(queue, &size);
    printf("size:%d\n", size);

    int *val = NULL;
    while (!doubleLinkListQueueIsEmpty(queue))
    {
        doubleLinkListQueueTop(queue, (void **)&val);
        printf("val:%d\n", *val);
        doubleLinkListQueuePop(queue);
    }

    doubleLinkListQueueDestroy(queue);
    

    return 0;
}






