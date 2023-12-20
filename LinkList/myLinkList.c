#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "myLinkList.h"

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


#define PRINT_INT(num) \
printf("%s:%d\n", #num, num);\

#define PRINT printf("=========\n")

// #define FREE(p)         
// if (p != NULL)
// {

// }

/* 根据值获取指定结点在链表的位置 */
static int LinkListAppointValGetPos(LinkList * pList, ELEMENTTYPE val, int *pPos);



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

    /* 5.更新链表长度 */
    (pList->len)++;

    /* 同步尾结点 */
    if (flag)
    {
        printf("尾结点更新。\n");
        pList->tail = newNode;
    }
    return ON_SUCCESS;
}

/* 获取链表--长度 */
int myLinkListGetLength(LinkList * pList, int *size)
{
    JUDGE_NULL(pList);
    JUDGE_NULL(size);
    *size = pList->len;
    return ON_SUCCESS;
}

/* 获取链表--遍历链表元素 */
int myLinkListForeach(LinkList * pList)
{
    JUDGE_NULL(pList);
    LinkNode * travelNode = pList->head->next;
    while (travelNode != NULL)
    {
        printf("data:%d\n", travelNode->data);
        travelNode = travelNode->next;
    }
    
    return ON_SUCCESS;
}

/* 销毁链表 */
int myLinkListDestroy(LinkList * pList);




