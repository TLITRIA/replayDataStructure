#ifndef __LINKLIST_H_
#define __LINKLIST_H_

#define ELEMENTTYPE int

/* 链表结点取别名 */
typedef struct LinkNode
{
    ELEMENTTYPE data;
    /* 指向下一个结点的指针 */
    struct LinkNode *next; /* ??指针类型为什么是结点 */
} LinkNode;

/* 链表 */
typedef struct LinkList
{
    LinkNode * head;    //链表的虚拟头结点
    int len;            //链表的长度
} LinkList;



/* 链表初始化 */
int LinkListInit();

/* 链表头插 */
int LinkListHeadInsert();

/* 链表尾插 */
int LinkListTailInsert();

/* 链表指定位置插入 */
int LinkListAppointPosInsert();

/* 链表头删 */
int LinkListHeadDel();

/* 链表尾删 */
int LinkListTailDel();

/* 链表指定位置删 */
int LinkListDelAppointPos();

/* 链表指定删... */
int LinkListDelAppointData();

/* 获取链表的长度 */
int LinkListGetLength();

/* 链表销毁 */
int LinkListDestroy();



#endif
