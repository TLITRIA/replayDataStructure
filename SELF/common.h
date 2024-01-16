#ifndef __COMMON_H_
#define __COMMON_H_



/* 错误码 */
enum ERROR_CODE
{
    INVILID_ACCESS = -3,
    NULL_PTR,
    MALLOC_ERROR,
    ON_SUCCESS,
};

/* 宏函数 */
#define JUDGE_IFNULL(ptr)\
if (NULL == ptr)\
    return NULL_PTR;\

#define JUDGE_MALLOC(ptr)\
if (NULL == ptr)\
    return MALLOC_ERROR;\

#define JUDGE_IFNULL_RETURN_NULL(ptr)\
if (NULL == ptr)\
    return NULL;\

#define FREE(ptr)\
if (NULL == ptr)\
{\
    free(ptr);\
    ptr = NULL;\
}\


int compareIntFunc(ELEMENTTYPE val1, ELEMENTTYPE val2)
{
    int info1 =  *(int *)val1;
    int info2 =  *(int *)val2;
    return (info1 - info2);
    
}
int printIntFunc(ELEMENTTYPE val)
{
    int info = *(int *)val;
    printf("%d ", info);
    return ON_SUCCESS;
}








#endif // __COMMON_H_