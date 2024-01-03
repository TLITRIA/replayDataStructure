#ifndef _COMMON_H_
#define _COMMON_H_

#define ELEMENTTYPE void *

enum STATUS_CODE
{
    INVALID_ACCESS = -3,
    MALLOC_ERROR,
    PTR_NULL,
    ON_SUCCESS,
};

/* 判空 */
#define JUDGE_PTR_NULL(ptr) \
if (NULL == ptr)            \
    return PTR_NULL;        \

/* 判空返回NULL */
#define JUDGE_PTR_NULL_RETURN_NULL(ptr) \
if (NULL == ptr)                        \
    return NULL;                        \

/* 判断malloc是否成功分配 */
#define JUDGE_MALLOC_ERROR(ptr) \
if (NULL == ptr)                \
    return MALLOC_ERROR;        \
    


#endif //__DOUBLELINKLIST_H_