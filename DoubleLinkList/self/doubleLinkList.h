#ifndef __DOUBLELINKLIST_H_
#define __DOUBLELINKLIST_H_

#define ELEMENTTYPE void *

typedef struct DoubleLinkNode
{
    ELEMENTTYPE data;
    DoubleLinkNode *next;
    DoubleLinkNode *prev;
} DoubleLinkNode;


typedef struct DoubleLinkList
{
    DoubleLinkNode *head;
    DoubleLinkNode *tail;
    int length;
    int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2);
    int (*printFunc)(ELEMENTTYPE val1);
} DoubleLinkList;

/* 双向链表的接口有什么？ */

/* 初始化 */
int doubleLinkListInit(DoubleLinkList **pList,
    int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2),
    int (*printFunc)(ELEMENTTYPE val1)
);

/* 插入--头插 */
int doubleLinkListInsertHead(DoubleLinkList *pList, ELEMENTTYPE val);

/* 插入--尾插 */
int doubleLinkListInsertTail(DoubleLinkList *pList, ELEMENTTYPE val);

/* 插入--指定位置 */
int doubleLinkListInsertAppointPos(DoubleLinkList *pList, int pos, ELEMENTTYPE val);

/* 获取--长度 */
int doubleLinkListGetLength(DoubleLinkList *pList, int *pSize);

/* 获取--指定位置的值 */
int doubleLinkListGetValAppointPos(DoubleLinkList *pList, int pos, ELEMENTTYPE *pVal);

/* 获取--遍历 */
int doubleLinkListForeach(DoubleLinkList *pList);

/* 获取--逆序遍历 */
int doubleLinkListForeachReverse(DoubleLinkList *pList);



#endif //__DOUBLELINKLIST_H_