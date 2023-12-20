#ifndef __MYLINKLIST_H_
#define __MYLINKLIST_H_

#define ELEMENTTYPE int


typedef struct LinkNode
{
    ELEMENTTYPE data;
    struct LinkNode *next;
} LinkNode;


typedef struct LinkList
{
    LinkNode *head;
    LinkNode *tail;
    int len;
} LinkList;

static int myLinkListGetPosAccordVal(LinkList * pList, ELEMENTTYPE val, int *pPos);

/* 链表初始化 */
int myLinkListInit(LinkList ** pList);

/* 插入链表--头插 */
int myLinkListInsertHead(LinkList * pList, ELEMENTTYPE val);

/* 插入链表--尾插 */
int myLinkListInsertTail(LinkList * pList, ELEMENTTYPE val);

/* 插入链表--指定位置插入 */
int myLinkListInsertAppointPos(LinkList * pList, int pos, ELEMENTTYPE val);

/* 删除链表--头删 */
int myLinkListDelHead(LinkList * pList);

/* 删除链表--尾删 */
int myLinkListDelTail(LinkList * pList);

/* 删除链表--指定位置删 */
int myLinkListDelAppointPos(LinkList * pList, int pos);

/* 删除链表--指定数据删 */
int myLinkListDelAppointVal(LinkList * pList, int val);

/* 获取链表--长度 */
int myLinkListGetLength(LinkList * pList, int *size);

/* 获取链表--遍历链表元素 */
int myLinkListForeach(LinkList * pList);

/* 销毁链表 */
int myLinkListDestroy(LinkList * pList);




#endif