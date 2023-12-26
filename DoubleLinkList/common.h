#ifndef _COMMON_H_
#define _COMMON_H_



// 状态码
enum STATUS_CODE
{
    NOT_FIND = -4,
    INVALID_ACCESS,
    NULL_PTR,
    MALLOC_ERROR,
    ON_SUCCESS,
};

#define START_POS 0/* todo */

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

/* 释放指针 */
#define FREE(p) \
if (p != NULL)  \
{               \
    free(p);    \
    p = NULL;   \
}               \

#endif //_COMMON_H_