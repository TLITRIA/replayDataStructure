#include <stdio.h>
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
    /* todo */
}

/* 插入--指定位置 */
int doubleLinkListInsertAppointPos(DoubleLinkList *pList, int pos, ELEMENTTYPE val)
{
    JUDGE_PTR_NULL(pList);
    if (pos < 0 || pos > pList->length)
    {
        return INVALID_ACCESS;
    }
    if (pos == pList->length)               /* 调用尾插 */
    {
        doubleLinkListInsertTail(pList, val);
    }
    else                    /* 不是尾插，todo从两头遍历以优化操作 */
    {
        DoubleLinkNode *newNode = createDoubleLinkNode(val);
        DoubleLinkNode *travelNode = pList->head;

        while (pos--)
        {
            travelNode = travelNode->next;
        }

        
        

    }
    


    
}

/* 获取--长度 */
int doubleLinkListGetLength(DoubleLinkList *pList, int *pSize);

/* 获取--指定位置的值 */
int doubleLinkListGetValAppointPos(DoubleLinkList *pList, int pos, ELEMENTTYPE *pVal);

/* 获取--遍历 */
int doubleLinkListForeach(DoubleLinkList *pList);

/* 获取--逆序遍历 */
int doubleLinkListForeachReverse(DoubleLinkList *pList);
