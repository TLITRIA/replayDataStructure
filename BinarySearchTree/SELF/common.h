#ifndef __COMMON_H_
#define __COMMON_H_

#define ELEMENTTYPE void *

enum ERROR_CODE
{
    INVALID_ACCESS = -3,
    MALLOC_ERROR,
    NULL_PTR,
    ON_SUCCESS,
} ;


#define JUDGE_NULL_PTR(ptr) \
if (ptr == NULL)            \
{                           \
    return NULL_PTR;        \
}                           \


#define JUDGE_MALLOC_ERROR(ptr) \
if (ptr == NULL)            \
{                           \
    return MALLOC_ERROR;      \
}                           \


#define JUDGE_MALLOC_ERROR_RETURN_NULL(ptr) \
if (ptr == NULL)            \
{                           \
    return NULL;      \
}                           \

#define JUDGE_NULL_PTR_RETURN_NULL(ptr) \
if (ptr == NULL)            \
{                           \
    return NULL;        \
}                           \


#define FREE(ptr)           \
if (ptr != NULL)            \
{                           \
    free(ptr);              \
    ptr = NULL;             \
}                           \







#endif