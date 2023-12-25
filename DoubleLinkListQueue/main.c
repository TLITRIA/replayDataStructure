#include "doubleLinkListQueue.h"
#include <stdio.h>

#define BUFFER_SIZE 5

int main()
{
    DoubleLinkListQueue *queue = NULL;
    doubleLinkListQueueInit(queue);

    int buffer[BUFFER_SIZE] = {111, 222, 333, 444, 555};

    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        doubleLinkListQueuePush(queue, buffer[idx]);
    }

    int size = 0;
    doubleLinkListQueueGetSize(queue, &size);
    printf("size:%d\n", size);


    int *val = NULL;
    while (!doubleLinkListQueueIsEmpty(queue))
    {
        doubleLinkListQueueTop(queue, val);
        printf("%d\n", *val);
        doubleLinkListQueuePop(queue);
    }
    
    
    return 0;
}