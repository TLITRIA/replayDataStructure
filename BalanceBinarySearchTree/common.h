#ifndef _COMMON_H_
#define _COMMON_H_


#if 0
#define ELEMENTTYPE int
#else
#define ELEMENTTYPE void*
#endif

#define QUEUETYPE void*


/* 枚举错误类型 */
enum MY_STATUS_CODE 
{
    NOT_FIND = -4,
    INVALID_ACCESS,
    NULL_PTR,
    MALLOC_ERROR,
    ON_SUCCESS,
};




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




#endif // _COMMON_H_