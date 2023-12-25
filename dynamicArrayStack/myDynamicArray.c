#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myDynamicArray.h"

/* 宏定义默认值 */
#define DEFAULT_SIZE 10
/* 枚举错误类型 */
enum MY_STATUS_CODE 
{
    ON_SUCCESS = -4,
    PTR_ERROR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};

/* 宏定义输出，后面用钩子函数自定义输出 */
#define PRINT(a)\
printf("%-5s : %d\n", #a, a);\

/* 判空 */
#define JUDGE_NULL(pArray)\
if (NULL == pArray)\
    return PTR_ERROR;\

/* malloc是否成功分配？ */
#define JUDGE_MALLOC(pArray)\
if (NULL == pArray->data)\
    return MALLOC_ERROR;\

/* 判断位置是否合法 两种 */
#define JUDGE_POS_INSERT(pos, len)\
if (pos < 0 || pos > len)\
    return INVALID_ACCESS;\


#define JUDGE_POS_GET(pos, len)\
if (pos < 0 || pos >= len)\
    return INVALID_ACCESS;\

/* 释放内存 */
#define FREE(tmpPtr)\
if (NULL != tmpPtr)\
{\
    free(tmpPtr);\
    tmpPtr = NULL;\
}\


/* 静态扩容缩容--两种操作可以结合代码 */
static int expandCapacity(dynamicArray *pArray);
static int shrinkCapacity(dynamicArray *pArray);

// 判断是否需要扩容缩容，可以合并
/* 判断是否需要扩容？？可以放到上面吗 */
#define IF_NEEDEXPAND(pArray)\
if (pArray->length + (pArray->length >> 1) > pArray->capacity)\
    expandCapacity(pArray); \

/* 判断是否需要缩容 */
#define IF_NEEDSHRINK(pArray)\
if (pArray->length < pArray->capacity >> 1 )\
    shrinkCapacity(pArray); \


    
/* 动态数组的初始化 */
int dynamicInit(dynamicArray *pArray, int capcity)
{
    /*判空*/
    JUDGE_NULL(pArray);
    
    if (capcity <= 0)
    {
        capcity = DEFAULT_SIZE;
    }
    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * capcity);
    JUDGE_MALLOC(pArray);
    memset(pArray->data, 0, sizeof(ELEMENTTYPE) * capcity);

    pArray->length = 0;
    pArray->capacity = capcity;

    return ON_SUCCESS;
}

/* 扩容 */
int expandCapacity(dynamicArray *pArray)
{
    int needExpandCapacity = pArray->capacity + (pArray->capacity >> 1);
    
    /* 1.备份指针 */
    ELEMENTTYPE * tmpPtr = pArray->data;
    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * needExpandCapacity);
    JUDGE_MALLOC(pArray);

    /* 2.数据拷贝到新内存 */
    for (int idx = 0; idx < pArray->length; idx++)//todo-001循环节写错了
    {
        pArray->data[idx] = tmpPtr[idx];
    }

    /* 3.释放内存 */
    FREE(tmpPtr);

    /* 4.更新数组容量 */
    // printf("原容量%d, 现容量%d\n", pArray->capacity, needExpandCapacity);
    pArray->capacity = needExpandCapacity;

    return ON_SUCCESS;
}

/* 缩容 */
int shrinkCapacity(dynamicArray *pArray)
{
    int needShrinkCapacity = pArray->capacity >> 1;
    
    /* 1.备份指针 */
    ELEMENTTYPE * tmpPtr = pArray->data;
    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * needShrinkCapacity);
    JUDGE_MALLOC(pArray);

    /* 2.数据拷贝到新内存 */
    for (int idx = 0; idx < pArray->length; idx++)
    {
        pArray->data[idx] = tmpPtr[idx];
    }

    /* 3.释放内存 */
    FREE(tmpPtr);

    /* 4.更新数组容量 */
    pArray->capacity = needShrinkCapacity;

    return ON_SUCCESS;
}

/* todo 扩容缩容代码重复度高 */


/* 动态数组插入行末 */
int dynamicInsertAppointData(dynamicArray *pArray, ELEMENTTYPE val)
{
    dynamicInsertAppointPosData(pArray, pArray->length, val);
}

/* 动态数组插入指定位置 */
int dynamicInsertAppointPosData(dynamicArray *pArray, int pos, ELEMENTTYPE val)
{
    /* 判空 */
    JUDGE_NULL(pArray);
    /* pos是否合法 */
    JUDGE_POS_INSERT(pos, pArray->length);
    /* 判断是否要扩容 */
    IF_NEEDEXPAND(pArray);

    for (int idx = pArray->length; idx > pos; idx--)
    {
        pArray->data[idx] = pArray->data[idx - 1];
    }
    pArray->data[pos] = val;

    /* 更新数组长度 */
    (pArray->length)++;
    return ON_SUCCESS;
}

/* 动态数组修改指定位置数据 */
int dynamicModifyPosData(dynamicArray *pArray, int pos, ELEMENTTYPE val)
{
    JUDGE_NULL(pArray);
    JUDGE_POS_GET(pos, pArray->length);
    pArray->data[pos] = val;
    return ON_SUCCESS;
}


/* 动态数组删除数据-行末 */
int dynamicDelLastData(dynamicArray *pArray)
{
    dynamicDelPosData(pArray, pArray->length - 1);
}

/* 动态数组删除数据-指定位置 */
int dynamicDelPosData(dynamicArray *pArray, int pos)
{
    JUDGE_NULL(pArray);
    JUDGE_POS_GET(pos, pArray->length);
    IF_NEEDSHRINK(pArray);

    for (int idx = pos; idx < pArray->length - 1; idx++)
    {
        pArray->data[idx] = pArray->data[idx + 1];
    }
    (pArray->length)--;
    return ON_SUCCESS;
}

/* 动态数组删除数据-指定值 */
int dynamicDelData(dynamicArray *pArray, int val)
{
    JUDGE_NULL(pArray);

    for (int idx = pArray->length - 1; idx >= 0; idx--)
    {
        if (val == pArray->data[idx])
        {
            dynamicDelPosData(pArray, idx);
        }
    }

    return ON_SUCCESS;
}

/* 动态数组销毁 */
int dynamicDestroy(dynamicArray *pArray)
{
    JUDGE_NULL(pArray);
    FREE(pArray->data);
    return ON_SUCCESS;
}

/* 动态数组获取长度 */
int dynamicGetLength(dynamicArray *pArray, int *length)
{
    JUDGE_NULL(pArray);
    JUDGE_NULL(length);
    *length = pArray->length;
    return ON_SUCCESS;
}

/* 动态数组获取容量 */
int dynamicGetCapacity(dynamicArray *pArray, int *capacity)
{
    JUDGE_NULL(pArray);
    JUDGE_NULL(capacity);
    *capacity = pArray->capacity;
    return ON_SUCCESS;
}

/* 动态数组获取指定数值 */
int dynamicGetPosVal(dynamicArray *pArray, int pos, ELEMENTTYPE *pVal)
{
    JUDGE_NULL(pArray);
    JUDGE_POS_GET(pos, pArray->length);
    JUDGE_NULL(pVal);
    *pVal = pArray->data[pos];
    return ON_SUCCESS;
}


/*  END   */

