#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "doubleLinkList.h"


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




/* 根据值获取指定结点在链表的位置 */
static int myDoubleLinkListGetPosAccordVal(DoubleLinkList * pList, ELEMENTTYPE val, int *pPos);
static DoubleLinkNode * createDoubleLinkNode(ELEMENTTYPE val);

static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2);
static int printFunc(ELEMENTTYPE val);


/* 链表初始化 */
int myDoubleLinkListInit(DoubleLinkList ** pList,
            int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2),
            int (*printFunc)(ELEMENTTYPE val))
{
    /* 1.初始化新链表 */
    DoubleLinkList * newList = (DoubleLinkList *)malloc(sizeof(DoubleLinkList) * 1);
    JUDGE_MALLOC(newList);
    memset(newList, 0, sizeof(newList));
    /* 2.初始化虚拟表头 */
    newList->head = (DoubleLinkNode *)malloc(sizeof(DoubleLinkNode) * 1);
    JUDGE_MALLOC(newList->head);
    memset(newList->head, 0, sizeof(newList->head));
    /* 3.初始化链表数据 */
    // 链表
    newList->len = 0;  // ！！链表的长度不包括头结点
    newList->tail = newList->head;
    // 头结点
    newList->head->data = 0;
    newList->head->next = NULL;
    newList->head->prev = NULL;

    newList->compareFunc = compareFunc;
    newList->printFunc = printFunc;
    /* 4.赋值 */
    *pList = newList;

    return ON_SUCCESS;
}

/* 插入链表--头插 */
int myDoubleLinkListInsertHead(DoubleLinkList * pList, ELEMENTTYPE val)
{
    myDoubleLinkListInsertAppointPos(pList, START_POS, val); 
}

/* 插入链表--尾插 */
int myDoubleLinkListInsertTail(DoubleLinkList * pList, ELEMENTTYPE val)
{
    myDoubleLinkListInsertAppointPos(pList, pList->len, val);
}



/* 新建新结点封装成函数 */
static DoubleLinkNode * createDoubleLinkNode(ELEMENTTYPE val)
{
    DoubleLinkNode * newNode = (DoubleLinkNode *)malloc(sizeof(DoubleLinkNode) * 1);
    JUDGE_IFNULL_RETURN_NULL(newNode);
    memset(newNode, 0, sizeof(DoubleLinkNode) * 1);
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

/* 插入链表--指定位置插入 */
int myDoubleLinkListInsertAppointPos(DoubleLinkList * pList, int pos, ELEMENTTYPE val)
{
    /* 1.确认指针非空、插入位置合法、判断尾指针是否要同步 */
    JUDGE_NULL(pList);
    if (pos < START_POS || pos > pList->len)
    {
        return INVALID_ACCESS;
    }

    /* 2.封装待插入结点 */
#if 0
    DoubleLinkNode * newNode = (DoubleLinkNode *)malloc(sizeof(DoubleLinkNode) * 1);
    JUDGE_MALLOC(newNode);
    memset(newNode, 0 ,sizeof(newNode));
    newNode->data = val;
    newNode->next = NULL;
#else
    DoubleLinkNode * newNode = createDoubleLinkNode(val);
    JUDGE_NULL(newNode);
#endif

    /* 3.travelNode遍历到插入位置 */
    int flag = 0;
    DoubleLinkNode * travelNode = pList->head;
    if (pos == pList->len)
    {
        flag = 1;
        travelNode = pList->tail;
    }
    else
    {
        while (pos--)
        {
            travelNode = travelNode->next;
        }
        travelNode->next->prev = newNode;/*3*/
    }
    newNode->next = travelNode->next;   /*1*/
    newNode->prev = travelNode;         /*2*/
    travelNode->next = newNode;         /*4*/

    /* 5.更新链表长度、同步尾结点todo */
    (pList->len)++;
    if (flag)
    {
        pList->tail = newNode;
    }

    return ON_SUCCESS;
}



/* 删除链表--头删 */
int myDoubleLinkListDelHead(DoubleLinkList * pList)
{
    myDoubleLinkListDelAppointPos(pList, START_POS + 1);//头结点不能删
}

/* 删除链表--尾删 */
int myDoubleLinkListDelTail(DoubleLinkList * pList)
{
    myDoubleLinkListDelAppointPos(pList, pList->len);
}


/* 删除链表--指定位置删 */
int myDoubleLinkListDelAppointPos(DoubleLinkList * pList, int pos)
{
    /* 1.确认指针非空、插入位置合法、判断尾指针是否要同步 */
    JUDGE_NULL(pList);
    if (pos <= START_POS || pos > pList->len) // 头结点不删
    {
        return INVALID_ACCESS;
    }
    /* 2.封装遍历结点、待删除结点 */
    DoubleLinkNode * travelNode = pList->head;
    DoubleLinkNode * needDelNode = NULL;

    if (pos == pList->len)
    {
    /*beifen 尾删 */
        DoubleLinkNode * tmpNode = pList->tail;
        pList->tail = pList->tail->prev;
        pList->tail->next = NULL;
        needDelNode = tmpNode;
    }
    else
    {
        /* 3.遍历到删除位置 */
        while (--pos)
        {
            travelNode = travelNode->next;
        }
        /* 4.删除结点删除 */
        needDelNode = travelNode->next;
        travelNode->next = needDelNode->next;
        needDelNode->next->prev = travelNode;
    }
    /* 5.释放结点 */
    FREE(needDelNode);
    /* 6.更新链表长度 */
    (pList->len)--;

    return ON_SUCCESS;
}

/* 根据值获取指定结点在链表的位置 */
int myDoubleLinkListGetPosAccordVal(DoubleLinkList * pList, 
                                    ELEMENTTYPE val, 
                                    int *pPos)
{
    /* 1.封装遍历结点 */
    int pos = 1;
    DoubleLinkNode * travelNode = pList->head->next;
    /* 2.寻找符合值的结点，返回pos */
    while (travelNode != NULL)
    {
        if (pList->compareFunc(val, travelNode->data))
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
/* 如果链表存储的是地址则用钩子函数比较、删除 */
int myDoubleLinkListDelAppointVal(DoubleLinkList * pList, ELEMENTTYPE val)
{
    JUDGE_IFNULL(pList);
    // pos存放地址或错误信息，size获取链表长度
    int pos = 0;
    int size = 0;
    while (myDoubleLinkListGetLength(pList, &size) >= 0 && pos != NOT_FIND)
    {
        myDoubleLinkListGetPosAccordVal(pList, val, &pos);
        myDoubleLinkListDelAppointPos(pList, pos);
    }
    return ON_SUCCESS;
}


/* 获取链表--长度 */
int myDoubleLinkListGetLength(DoubleLinkList * pList, int *size)
{
    // 两指针判空
    JUDGE_NULL(pList);
    JUDGE_NULL(size);
    *size = pList->len;
    return pList->len;
}

/* 获取链表--遍历链表元素，双向链表可以逆序打印 */
int myDoubleLinkListForeach(DoubleLinkList * pList, int (*printFunc)(ELEMENTTYPE))
{
    JUDGE_NULL(pList);
    DoubleLinkNode * travelNode = pList->head->next;
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

int myDoubleLinkListReversePirnt(DoubleLinkList * pList, int (*printFunc)(ELEMENTTYPE))
{
    JUDGE_NULL(pList);
    DoubleLinkNode * travelNode = pList->tail;
    while (travelNode != pList->head)
    // while (travelNode->prev != NULL)
    {
        printFunc(travelNode->data);
        travelNode = travelNode->prev;
    }
    return ON_SUCCESS;
}


/* 销毁链表 */
int myDoubleLinkListDestroy(DoubleLinkList * pList)
{
    JUDGE_NULL(pList);
    int size = 0;
    /* 先销毁结点，后销毁链表指针 */
    while (myDoubleLinkListGetLength(pList, &size))
    {
        myDoubleLinkListDelTail(pList);
    }
    if (pList->head != NULL)
    {
        free(pList->head);//释放头结点
        pList->head = NULL;//链表指针
        pList->tail = NULL;//链表指针
    }
    return ON_SUCCESS;
}

/* 获取链表 头位置的值 */
int myDoubleLinkListGetHeadVal(DoubleLinkList *pList, ELEMENTTYPE *pVal)
{
#if 0
    myDoubleLinkListGetPosVal(pList, 0, pVal);
#else
    JUDGE_NULL(pList);
    if (pVal)
    {
        *pVal = pList->head->next->data;
    }
    
    
    return ON_SUCCESS;
#endif

}

/* 获取链表 尾位置的值 */
int myDoubleLinkListGetTailVal(DoubleLinkList *pList, ELEMENTTYPE *pVal)
{
    myDoubleLinkListGetPosVal(pList, pList->len, pVal);
}

/* 获取链表 指定位置的值 */
int myDoubleLinkListGetPosVal(DoubleLinkList *pList, int pos, ELEMENTTYPE *pVal)
{
    /* todo... */
}



