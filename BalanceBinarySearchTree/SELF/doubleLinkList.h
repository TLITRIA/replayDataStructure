#ifndef __MYDoubleLinkList_H_
#define __MYDoubleLinkList_H_
#include "common.h"


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
int myDoubleLinkListForeach(DoubleLinkList * pList, int (*printFunc)(ELEMENTTYPE));

/* 双向链表逆序打印 */
int myDoubleLinkListReversePirnt(DoubleLinkList * pList, int (*printFunc)(ELEMENTTYPE));


/* 销毁链表 */
int myDoubleLinkListDestroy(DoubleLinkList * pList);


/* 获取链表 头位置的值 */
int myDoubleLinkListGetHeadVal(DoubleLinkList *pList, ELEMENTTYPE *pVal);

/* 获取链表 尾位置的值 */
int myDoubleLinkListGetTailVal(DoubleLinkList *pList, ELEMENTTYPE *pVal);

/* 获取链表 指定位置的值 */
int myDoubleLinkListGetPosVal(DoubleLinkList *pList, int pos, ELEMENTTYPE *pVal);


#endif