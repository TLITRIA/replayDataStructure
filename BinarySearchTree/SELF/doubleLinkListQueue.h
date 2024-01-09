#ifndef _DOUBLE_LINK_LIST_QUEUE_
#define _DOUBLE_LINK_LIST_QUEUE_

#include "doubleLinkList.h"



typedef DoubleLinkList DoubleLinkListQueue;




/* 队列初始化 */
int doubleLinkListQueueInit(DoubleLinkListQueue **pQueue);

/* 队列入队 */
int doubleLinkListQueuePush(DoubleLinkListQueue *pQueue, ELEMENTTYPE val);

/* 队列出队 */
int doubleLinkListQueuePop(DoubleLinkListQueue *pQueue);

/* 队头元素 */
int doubleLinkListQueueTop(DoubleLinkListQueue *pQueue, ELEMENTTYPE *pVal);

/* 队尾元素 */
int doubleLinkListQueueRear(DoubleLinkListQueue *pQueue, ELEMENTTYPE *pVal);

/* 队列大小 */
int doubleLinkListQueueGetSize(DoubleLinkListQueue *pQueue, int *pSize);

/* 队列是否为空 */
int doubleLinkListQueueIsEmpty(DoubleLinkListQueue *pQueue);

/* 队列销毁 */
int doubleLinkListQueueDestroy(DoubleLinkListQueue *pQueue);

#endif //_DOUBLE_LINK_LIST_QUEUE_