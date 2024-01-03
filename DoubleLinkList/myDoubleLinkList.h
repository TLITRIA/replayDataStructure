#ifndef __MYDoubleLinkList_H_
#define __MYDoubleLinkList_H_

#if 0
#define ELEMENTTYPE int
#else
#define ELEMENTTYPE void*
#endif

typedef struct DoubleLinkNode
{
    ELEMENTTYPE data;
    struct DoubleLinkNode *next;
    struct DoubleLinkNode *prev;
} DoubleLinkNode;


typedef struct DoubleLinkList
{
    DoubleLinkNode *head;
    DoubleLinkNode *tail;
    int len;
    int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2);
    int (*printFunc)(ELEMENTTYPE val);
} DoubleLinkList;



/* 链表初始化 */
int myDoubleLinkListInit(DoubleLinkList ** pList,
            int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2),
            int (*printFunc)(ELEMENTTYPE val));

/* 插入链表--头插 */
int myDoubleLinkListInsertHead(DoubleLinkList * pList, ELEMENTTYPE val);

/* 插入链表--尾插 */
int myDoubleLinkListInsertTail(DoubleLinkList * pList, ELEMENTTYPE val);

/* 插入链表--指定位置插入 */
int myDoubleLinkListInsertAppointPos(DoubleLinkList * pList, int pos, ELEMENTTYPE val);

/* 删除链表--头删 */
int myDoubleLinkListDelHead(DoubleLinkList * pList);

/* 删除链表--尾删 */
int myDoubleLinkListDelTail(DoubleLinkList * pList);

/* 删除链表--指定位置删 */
int myDoubleLinkListDelAppointPos(DoubleLinkList * pList, int pos);

/* 删除链表--指定数据删 */
int myDoubleLinkListDelAppointVal(DoubleLinkList * pList, ELEMENTTYPE val);

/* 获取链表--长度 */
int myDoubleLinkListGetLength(DoubleLinkList * pList, int *size);

/* 获取链表--遍历链表元素 */
int myDoubleLinkListForeach(DoubleLinkList * pList);
/**指针函数与函数指针
 * 指针函数：返回值是指针的函数
 * 函数指针：指向函数的指针
*/

/* 双向链表打印接口 */
int myDoubleLinkListReversePirnt(DoubleLinkList * pList);


/* 销毁链表 */
int myDoubleLinkListDestroy(DoubleLinkList * pList);




#endif