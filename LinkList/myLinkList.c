#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "myLinkList.h"

// 状态码
enum STATUS_CODE
{
    NOT_FIND = -4,
    INVALID_ACCESS,
    NULL_PTR,
    MALLOC_ERROR,
    ON_SUCCESS,
};

#define START_POS 0

#define JUDGE_NULL(p)   \
if (NULL == p)          \
    return NULL_PTR;    \

#define JUDGE_MALLOC(p)     \
if (NULL == p)              \
    return MALLOC_ERROR;    \


/* 输出 */
#define PRINT_INT(num) \
//printf("%s:%d\n", #num, num);

#define PRINT //printf("=========\n")
#define PRINT_TAIL //printf("！尾结点更新\n")

/* 释放指针 */
#define FREE(p) \
if (p != NULL)  \
{               \
    free(p);    \
    p = NULL;   \
}               \


/* 根据值获取指定结点在链表的位置 */
static int myLinkListGetPosAccordVal(LinkList * pList, ELEMENTTYPE val, int *pPos);



/* 链表初始化 */
int myLinkListInit(LinkList ** pList)
{
    /* 1.初始化新链表 */
    LinkList * newList = (LinkList *)malloc(sizeof(LinkList) * 1);
    JUDGE_MALLOC(newList);
    memset(newList, 0, sizeof(newList));
    /* 2.初始化虚拟表头 */
    newList->head = (LinkNode *)malloc(sizeof(LinkNode) * 1);
    JUDGE_MALLOC(newList->head);
    memset(newList->head, 0, sizeof(newList->head));
    /* 3.初始化链表数据 */
    // 链表
    newList->len = 0;  // ！！链表的长度不包括头结点
    newList->tail = newList->head;
    // 头结点
    newList->head->data = 0;
    newList->head->next = NULL;
    /* 4.赋值 */
    *pList = newList;

    return ON_SUCCESS;
}

/* 插入链表--头插 */
int myLinkListInsertHead(LinkList * pList, ELEMENTTYPE val)
{
    myLinkListInsertAppointPos(pList, START_POS, val); //！！链表地址不计头结点，从0开始
}

/* 插入链表--尾插 */
int myLinkListInsertTail(LinkList * pList, ELEMENTTYPE val)
{
    myLinkListInsertAppointPos(pList, pList->len, val);
}

/* 插入链表--指定位置插入 */
int myLinkListInsertAppointPos(LinkList * pList, int pos, ELEMENTTYPE val)
{
    /* 1.确认指针非空、插入位置合法、判断尾指针是否要同步 */
    JUDGE_NULL(pList);
    if (pos < START_POS || pos > pList->len)
    {
        return INVALID_ACCESS;
    }
    int flag = 0;
    if (pos == pList->len)
    {
        flag = 1;
    }
    PRINT_INT(pos);
    PRINT_INT(pList->len);
    PRINT_INT(flag);
    PRINT;

    /* 2.封装待插入结点 */
    LinkNode * newNode = (LinkNode *)malloc(sizeof(LinkNode) * 1);
    JUDGE_MALLOC(newNode);
    memset(newNode, 0 ,sizeof(newNode));
    newNode->data = val;
    newNode->next = NULL;

    /* 3.travelNode遍历到插入位置 */
    LinkNode * travelNode = pList->head;
    while (pos--)
    {
        travelNode = travelNode->next;
    }

    /**4.插入结点
     * 此时有三个节点：上一个结点A、待插入结点B、下一个结点C
     * 原本A->B  C独立， 先将待插入结点C指向B，再将原本指向
     * C的结点A指向B，得到的链表的顺序是：A->B->C
    */
    newNode->next = travelNode->next; 
    travelNode->next = newNode;      

    /* 5.更新链表长度、同步尾结点 */
    (pList->len)++;
    if (flag)
    {
        pList->tail = newNode;
    }

    return ON_SUCCESS;
}



/* 删除链表--头删 */
int myLinkListDelHead(LinkList * pList)
{
    myLinkListDelAppointPos(pList, START_POS + 1);//头结点不能删
}

/* 删除链表--尾删 */
int myLinkListDelTail(LinkList * pList)
{
    myLinkListDelAppointPos(pList, pList->len);
}


/* 删除链表--指定位置删 */
int myLinkListDelAppointPos(LinkList * pList, int pos)
{
    /* 1.确认指针非空、插入位置合法、判断尾指针是否要同步 */
    JUDGE_NULL(pList);
    if (pos <= START_POS || pos > pList->len) // 头结点不删
    {
        return INVALID_ACCESS;
    }
    int flag = 0;
    if (pos == pList->len)
    {
        flag = 1;
    }

    /* 2.封装遍历结点、待删除结点 */
    LinkNode * travelNode = pList->head;
    LinkNode * needDelNode = NULL;

    /* 3.遍历到删除位置 */
    while (--pos)
    {
        travelNode = travelNode->next;
    }
    /* 4.删除结点 */
    needDelNode = travelNode->next;
    travelNode->next = needDelNode->next;

    /* 5.释放取出的结点空间 */
    FREE(needDelNode);

    /* 6.更新尾结点、链表长度 */
    if (flag)
    {
        pList->tail = travelNode;
    }
    (pList->len)--;

    return ON_SUCCESS;
}

/* 根据值获取指定结点在链表的位置 */
int myLinkListGetPosAccordVal(LinkList * pList, \
                                    ELEMENTTYPE val, \
                                    int *pPos)
{
    /* 1.封装遍历结点 */
    int pos = 1;
    LinkNode * travelNode = pList->head->next;
    /* 2.寻找符合值的结点，返回pos */
    while (travelNode != NULL)
    {
        if (travelNode->data == val)
        {
            *pPos = pos;
            return pos;
        }
        travelNode = travelNode->next;
        pos++;
    }
    /* 3.找不到就返回错误信息 */
    /* 解引用用 */
    *pPos = NOT_FIND;
    return NOT_FIND;
}

/* 删除链表--指定数据删 */
int myLinkListDelAppointVal(LinkList * pList, ELEMENTTYPE val)
{
    // pos存放地址或错误信息，size获取链表长度
    int pos = 0;
    int size = 0;
    while (myLinkListGetLength(pList, &size) >= 0 && pos != NOT_FIND)
    {
        myLinkListGetPosAccordVal(pList, val, &pos);
        myLinkListDelAppointPos(pList, pos);
    }
    return ON_SUCCESS;
}


/* 获取链表--长度 */
int myLinkListGetLength(LinkList * pList, int *size)
{
    // 两指针判空
    JUDGE_NULL(pList);
    JUDGE_NULL(size);
    *size = pList->len;
    return pList->len;
}

/* 获取链表--遍历链表元素 */
int myLinkListForeach(LinkList * pList, int (*printFunc)(ELEMENTTYPE))
{
    JUDGE_NULL(pList);
    LinkNode * travelNode = pList->head->next;
    int pos = 1;
    while (travelNode != NULL)
    {
#if 0
        printf("data:%d\n", travelNode->data);  
#else
        printf("pos:%d\t", pos++);
        printFunc(travelNode->data);// 钩子函数实现自定义输出
#endif
        travelNode = travelNode->next;
    }
    
    return ON_SUCCESS;
}

/* 销毁链表 */
int myLinkListDestroy(LinkList * pList)
{
    JUDGE_NULL(pList);
    int size = 0;
    /* 先销毁结点，后销毁链表指针 */
    while (myLinkListGetLength(pList, &size))
    {
        myLinkListDelTail(pList);
    }
    if (pList->head != NULL)
    {
        free(pList->head);//释放头结点
        pList->head = NULL;//链表指针
        pList->tail = NULL;//链表指针
    }
    return ON_SUCCESS;
}




