#ifndef _COMMON_H_
#define _COMMON_H_


#define ELEMENTTYPE void*

/* 双向链表结点 */
typedef struct DoubleLinkNode
{
    ELEMENTTYPE data;
    struct DoubleLinkNode *next;
    struct DoubleLinkNode *prev;
} DoubleLinkNode;

/* 双向链表 */
typedef struct DoubleLinkList
{
    DoubleLinkNode *head;
    DoubleLinkNode *tail;
    int len;
    int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2);
    int (*printFunc)(ELEMENTTYPE val);
} DoubleLinkList;

typedef DoubleLinkList DoubleLinkListQueue;

// 状态码
enum STATUS_CODE
{
    NOT_FIND = -4,
    INVALID_ACCESS,
    NULL_PTR,
    MALLOC_ERROR,
    ON_SUCCESS,
};

#define START_POS 0

/* 判空 */
#define JUDGE_NULL(p)   \
if (NULL == p)          \
    return NULL_PTR;    \

/* 判空返回值为NULL */
#define JUDGE_NULL_RETURN_NULL(p)   \
if (NULL == p)          \
    return NULL;    \

/* 判断MALLOC是否成功分配内存 */
#define JUDGE_MALLOC(p)     \
if (NULL == p)              \
    return MALLOC_ERROR;    \

/* 打印一个变量和它的变量名 */
#define PRINT_INT(num) \
//printf("%s:%d\n", #num, num);

/* 打印分割线 */
#define PRINT_BOUNDARY printf("=============\n")

/* 打印提示 */
#define PRINT_TIP //printf("！尾结点更新\n")

/* 释放指针 */
#define FREE(p) \
if (p != NULL)  \
{               \
    free(p);    \
    p = NULL;   \
}               \





#endif //_COMMON_H_