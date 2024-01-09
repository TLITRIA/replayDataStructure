#ifndef __COMMON_H_
#define __COMMON_H_

#define ELEMENTTYPE void *


/* 枚举错误类型 */
enum MY_STATUS_CODE 
{
    NOT_FIND = -4,
    INVALID_ACCESS,
    NULL_PTR,
    MALLOC_ERROR,
    ON_SUCCESS,
};

/* 链表结点取别名 */
typedef struct DoubleLinkNode
{
    ELEMENTTYPE data;

    /* 指向前一个结点的指针 */
    struct DoubleLinkNode * prev;
    /* 指向下一个结点的指针 */
    struct DoubleLinkNode *next;   /* 指针的类型为什么是结点 */
} DoubleLinkNode;


/* 链表 */
typedef struct DoubleLinkList
{
    /* 链表的虚拟头结点 */
    DoubleLinkNode * head;
    DoubleLinkNode * tail;        /* 为什么尾指针不需要分配空间??? */
    /* 链表的长度 */
    int len;
} DoubleLinkList;



/* 判断malloc是否分配成功 */
#define JUDGE_MALLOC(p) \
if (NULL == p)          \
    return MALLOC_ERROR;  \

#define JUDGE_IFNULL(p) \
if (NULL == p)          \
    return NULL_PTR;  \

#define JUDGE_IFNULL_RETURN_NULL(p) \
if (NULL == p)          \
    return NULL;  \

/* 释放内存 */
#define FREE(tmpPtr)\
if (NULL != tmpPtr)\
{\
    free(tmpPtr);\
    tmpPtr = NULL;\
}\



#endif //__COMMON_H_