#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubleLinkList.h"


/* =================静态函数声明================== */

static DoubleLinkNode *createDoubleLinkNode();


/* =================================== */
static DoubleLinkNode *createDoubleLinkNode(ELEMENTTYPE val)
{
    /* 创建头结点 */
    DoubleLinkNode *newNode = (DoubleLinkNode *)malloc(sizeof(DoubleLinkNode) * 1);
    JUDGE_MALLOC_ERROR(newNode);
    memset(newNode, 0, sizeof(newNode));
    /* 初始化头结点结构体 */
    {
        newNode->data = val;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    return newNode;
}

/* =================================== */

/* 初始化 */
int doubleLinkListInit(DoubleLinkList **pList,
    int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2),
    int (*printFunc)(ELEMENTTYPE val1)
)
{
    JUDGE_PTR_NULL(pList);
    DoubleLinkList *newList = (DoubleLinkList *)malloc(sizeof(DoubleLinkList) * 1);
    JUDGE_MALLOC_ERROR(newList);
    memset(newList, 0, sizeof(newList));
    /* 初始化链表结构体 */
    {
        newList->head = createDoubleLinkNode(0);
        newList->tail = newList->head;
        newList->length = 0;
        newList->printFunc = printFunc;
        newList->compareFunc = compareFunc;
    }
    *pList = newList;

    return ON_SUCCESS;
}




/* 插入--头插 */
int doubleLinkListInsertHead(DoubleLinkList *pList, ELEMENTTYPE val)
{
    doubleLinkListInsertAppointPos(pList, 0, val);
}

/* 插入--尾插 */
int doubleLinkListInsertTail(DoubleLinkList *pList, ELEMENTTYPE val)
{
    doubleLinkListInsertAppointPos(pList, pList->length, val);
}

/* 插入--指定位置 */
int doubleLinkListInsertAppointPos(DoubleLinkList *pList, int pos, ELEMENTTYPE val)
{
    JUDGE_PTR_NULL(pList);
    if (pos < 0 || pos > pList->length)
    {
        return INVALID_ACCESS;
    }
    DoubleLinkNode *newNode = createDoubleLinkNode(val);
    if (pos == pList->length)             /* 尾插 */
    {
        DoubleLinkNode *travelNode = pList->tail;
        
        newNode->prev = pList->tail;
        travelNode->next = newNode;
        pList->tail = newNode;

        (pList->length)++;
        return ON_SUCCESS;
    }
    else                    /* 不是尾插，todo从两头遍历以优化操作 */
    {
        DoubleLinkNode *travelNode = pList->head;

        while (pos--)
        {
            travelNode = travelNode->next;
        }

        newNode->prev = travelNode;
        newNode->next = travelNode->next;
        newNode->next->prev = travelNode;
        travelNode->next = newNode;
        
        (pList->length)++;
    }
    return ON_SUCCESS;
}

/* 获取--长度 */
int doubleLinkListGetLength(DoubleLinkList *pList, int *pSize)
{
    JUDGE_PTR_NULL(pList);
    JUDGE_PTR_NULL(pSize);
    *pSize = pList->length;
    return pList->length;
}

/* 获取--指定位置的值 */
int doubleLinkListGetValAppointPos(DoubleLinkList *pList, int pos, ELEMENTTYPE *pVal)
{
    JUDGE_PTR_NULL(pList);
    JUDGE_PTR_NULL(pVal);
    if (pos < 0 || pos > pList->length)
    {
        return INVALID_ACCESS;
    }
    
    if (pos == pList->length)       /* 尾结点 */
    {
        *pVal = pList->tail->data;
        return ON_SUCCESS;
    }
    else
    {
        DoubleLinkNode *travelNode = pList->head;
        while (pos--)
        {
            travelNode = travelNode->next;
        }

        *pVal = travelNode->data;
    }
    return ON_SUCCESS;
}

/* 获取--遍历 */
int doubleLinkListForeach(DoubleLinkList *pList)
{
    JUDGE_PTR_NULL(pList);
    DoubleLinkNode *travelNode = pList->head;
    int count = pList->length;
    while (travelNode != pList->tail && count > 0)
    {
        pList->printFunc(travelNode->data);
        travelNode = travelNode->next;
        count--;
    }
    return ON_SUCCESS;
}

/* 获取--逆序遍历 */
int doubleLinkListForeachReverse(DoubleLinkList *pList)
{
    JUDGE_PTR_NULL(pList);
    DoubleLinkNode *travelNode = pList->tail;
    int count = pList->length;
    while (travelNode != pList->head && count > 0)
    {
        pList->printFunc(travelNode->data);
        travelNode = travelNode->prev;
        count--;
    }
    return ON_SUCCESS;
}
