#ifndef _COMMON_H_
#define _COMMON_H_


#if 1
#define ELEMENTTYPE int
#else
#define ELEMENTTYPE void*
#endif

// /* 枚举错误类型 */
// enum MY_STATUS_CODE 
// {
//     PTR_ERROR = -3,
//     MALLOC_ERROR,
//     INVALID_ACCESS,
//     ON_SUCCESS,
// };


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