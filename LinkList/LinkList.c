#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"




enum STATUS_CODE 
{
    ON_SUCCESS,
    PTR_ERROR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};

/* 链表判空 */
#define JUDGE_NULL(pin)\
if (NULL == pin)\
    return PTR_ERROR;\

/* malloc是否成功分配？ */
#define JUDGE_MALLOC(pin)\
if (NULL == pin)\
{\
    printf("%-5s\n", #pin);\
    return MALLOC_ERROR;\
}\

/* 判断位置是否合法 两种 */
#define JUDGE_POS_INSERT(pos, len)\
if (pos < 0 || pos > len)\
    return INVALID_ACCESS;\

#define JUDGE_POS_GET(pos, len)\
if (pos < 0 || pos >= len)\
    return INVALID_ACCESS;\


/* 链表初始化 */
int LinkListInit(LinkList ** pList)
{
    LinkList *list = (LinkList *)malloc(sizeof(LinkList) * 1);
    JUDGE_MALLOC(list);
    memset(list, 0, sizeof(LinkList) * 1);                      //  清空脏数据

    list->head = (LinkNode * )malloc(sizeof(LinkNode) * 1);
    JUDGE_MALLOC(list->head);
    memset(list->head, 0, sizeof(LinkNode) * 1);                //  清空脏数据
    list->head->data = 0;
    list->head->next = NULL;

    /* 初始化时，尾指针 = 头指针 */
    list->tail = list->head;

    /* 链表长度为0 */
    list->len = 0; 

    /* 二级指针 */
    *pList = list;

    return ON_SUCCESS;
}

/* 链表头插 */
int LinkListHeadInsert(LinkList * pList, ELEMENTTYPE val)
{
    return LinkListAppointPosInsert(pList, 0, val);
}

/* 链表尾插 */
int LinkListTailInsert(LinkList * pList, ELEMENTTYPE val)
{
    return LinkListAppointPosInsert(pList, pList->len, val);
}

/* 链表指定位置插入 */
int LinkListAppointPosInsert(LinkList * pList, int pos, ELEMENTTYPE val)
{
    JUDGE_NULL(pList);
    JUDGE_POS_INSERT(pos, pList->len);

    /* 封装结点 */
    LinkNode * newNode = (LinkNode *)malloc(sizeof(LinkNode) * 1);
    JUDGE_MALLOC(newNode);
    memset(newNode, 0, sizeof(LinkNode) * 1);

#if 1
/* todo 什么 */
#endif
    newNode->data = val;

#if 1
    /* 从虚拟头结点开始遍历 */
    LinkNode * travelNode = pList->head;
#else
    LinkNode * travelNode = pList->head->next;
#endif
    int flag = 0; //判断是否要同步尾指针
    /* 需要同步尾指针 */
    if (pos == pList->len)
    {
        travelNode = pList->tail; //
        flag = 1;
#if 0
        // newNode->next = travelNode->next;
        // travelNode->next = newNode;
        // pList->tail = newNode;
#endif
    }
    else
    {
        while (pos--)
        {
            travelNode = travelNode->next;
        }
    }
    /* 修改节点指向 */
        /* 先动哪一个结点？ */
    newNode->next = travelNode->next;
    travelNode->next = newNode;
    if (flag)
    {
        pList->tail = newNode;
    }

    /* 更新链表长度 */
    (pList->len)++;
    return ON_SUCCESS;
}

/* 链表头删 */
int LinkListHeadDel(LinkList * pList)
{
    
}

/* 链表尾删 */
int LinkListTailDel(LinkList * pList)
{
    
}

/* 链表指定位置删 */
int LinkListDelAppointPos(LinkList * pList, int pos)
{
    
}

/* 链表删除指定值 */
int LinkListDelAppointData(LinkList * pList, int val)
{
    
}

/* 获取链表的长度 */
int LinkListGetLength(LinkList * pList, int *pSize)
{
    JUDGE_NULL(pList);
    JUDGE_NULL(pSize);
    *pSize = pList->len;
    return ON_SUCCESS;
}

/* 链表销毁 */
int LinkListDestroy(LinkList * pList)
{
    
}


/* 链表遍历接口 */
int LinkListForeach(LinkList * pList)
{
    JUDGE_NULL(pList);

    
#if 1
    /* travelNode指向虚拟头结点 */
    LinkNode * travelNode = pList->head;
    while (travelNode->next != NULL)
    {
        travelNode = travelNode->next;
        printf("travelNode->data:%d\n", travelNode->data);
    }
#else
    /* travelNode指向链表第一个元素 */ 
    LinkNode * travelNode = pList->head->next;
    while (travelNode != NULL)
    {
        printf("travelNode->data:%d\n", travelNode->data);
        travelNode = travelNode->next;
    }
#endif
    return ON_SUCCESS;
}

/* END */
