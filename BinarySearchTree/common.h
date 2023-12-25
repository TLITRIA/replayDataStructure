#ifndef _COMMON_H_
#define _COMMON_H_




/* 枚举错误类型 */
enum MY_STATUS_CODE 
{
    PTR_ERROR = -3,
    MALLOC_ERROR,
    INVALID_ACCESS,
    ON_SUCCESS,
};




/* 判断malloc是否分配成功 */
#define JUDGE_MALLOC(p) \
if (NULL == p)          \
    return MALLOC_ERROR;  \

#define JUDGE_IFNULL(p) \
if (NULL == p)          \
    return PTR_ERROR;  \

/* 释放内存 */
#define FREE(tmpPtr)\
if (NULL != tmpPtr)\
{\
    free(tmpPtr);\
    tmpPtr = NULL;\
}\






typedef struct dynamicArray
{
    ELEMENTTYPE * data;
    int length;
    int capacity;
} dynamicArray;


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
} DoubleLinkList;


typedef DoubleLinkList DoubleLinkListQueue;

#endif // _COMMON_H_