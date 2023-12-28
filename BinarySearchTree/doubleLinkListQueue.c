#include "doubleLinkListQueue.h"
#include "doubleLinkList.h"
#include "common.h"
static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2);

static int printFunc(ELEMENTTYPE val);



/* 队列初始化 */
int doubleLinkListQueueInit(DoubleLinkListQueue **pQueue,
            int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2),
            int (*printFunc)(ELEMENTTYPE val))
{   
    myDoubleLinkListInit(pQueue, compareFunc, printFunc);
    return 0; 
}

/* 队列入队 */
int doubleLinkListQueuePush(DoubleLinkListQueue *pQueue, ELEMENTTYPE val)
{
    return myDoubleLinkListInsertTail(pQueue, val);/* 入队尾 */
}

/* 队列出队 */
int doubleLinkListQueuePop(DoubleLinkListQueue *pQueue)
{
    return myDoubleLinkListDelHead(pQueue);
}

/* 队头元素 */
int doubleLinkListQueueTop(DoubleLinkListQueue *pQueue, ELEMENTTYPE *pVal)
{
    return myDoubleLinkListGetHeadVal(pQueue, pVal);
}

/* 队尾元素 */
int doubleLinkListQueueRear(DoubleLinkListQueue *pQueue, ELEMENTTYPE *pVal)
{
    return myDoubleLinkListGetTailVal(pQueue, pVal);
}

/* 队列大小 */
int doubleLinkListQueueGetSize(DoubleLinkListQueue *pQueue, int *pSize)
{
    return myDoubleLinkListGetLength(pQueue, pSize);
}

/* 队列是否为空 */
int doubleLinkListQueueIsEmpty(DoubleLinkListQueue *pQueue)
{
    int size = 0;
    myDoubleLinkListGetLength(pQueue, &size);
    return size == 0 ? 1 : 0;
}

/* 队列销毁 */
int doubleLinkListQueueDestroy(DoubleLinkListQueue *pQueue)
{
    return myDoubleLinkListDestroy(pQueue);
}
