#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamicArray.h"
#include "common.h"

#define DEFAULT_CAPACITY 10


/* 静态函数声明 */
static int scaleCapacity(DynamicArray *pArray, int cap);
static int ifNeedScale(DynamicArray *pArray);
static int dynamicArrayGetPosAppointVal(DynamicArray *pArray, ELEMENTTYPE val, int *pPos);

static int scaleArrayCapacity(DynamicArray *pArray, int cap)
{
    JUDGE_IFNULL(pArray);
    ELEMENTTYPE *newData = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * cap);
    for (int idx = 0; idx < pArray->length; idx++)
    {
        newData[idx] = pArray->data[idx];
    }
    FREE(pArray->data);
    pArray->data = newData;

    return ON_SUCCESS;
}

/* 判断容量是否需要变更 */
static int ifNeedScale(DynamicArray *pArray)
{
    /* 到这里的函数0 < len < capacity */
    /* 判空 */
    JUDGE_IFNULL(pArray);
    /* 获取原容量、长度 */
    int cap = pArray->capacity;
    int len = pArray->length;
    /* 扩容与缩容的判断 */
    if (cap < (len + len >> 1))  /* 需要扩容 */
    {
        scaleArrayCapacity(pArray, (len + len >> 1));
    }
    else if (cap > len << 1)
    {
        scaleArrayCapacity(pArray, cap >> 1);
    }
    return ON_SUCCESS;
}
static int dynamicArrayGetPosAppointVal(DynamicArray *pArray, ELEMENTTYPE val, int *pPos)
{
    JUDGE_IFNULL(pArray);
    JUDGE_IFNULL(pPos);
    for (int idx = 0; idx < pArray->length; idx++)
    {
        if (pArray->data[idx] == val)
        {
            *pPos = idx;
            return idx;
        }
        
    }
    *pPos = NOT_FIND;
    return NOT_FIND;
}
/* 初始化 */
int dynamicArrayInit(DynamicArray **pArray, int cap,  int maxCap, int minCap,
                    int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2),
                    int (*printFunc)(ELEMENTTYPE val))
{
    /* 判空 */
    JUDGE_IFNULL(pArray);
    /* 判断非法访问 */
    if (cap <= 0)
    {
        cap = DEFAULT_CAPACITY;
    }
    /* 新建动态数组 */
    DynamicArray *newArray = (DynamicArray *)malloc(sizeof(DynamicArray) * 1);
    JUDGE_MALLOC(newArray);
    memset(newArray, 0, sizeof(DynamicArray) * 1);
    /* 新建数组指针 */
    newArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * cap);
    JUDGE_MALLOC(newArray->data);
    memset(newArray->data, 0, sizeof(ELEMENTTYPE) * cap);
    /* 维护结构体信息 */
    newArray->length = 0;
    newArray->capacity = cap;
    #if 1
    newArray->compareF = compareFunc;
    newArray->printF = compareFunc;
    #else
    newArray->compareF = compareIntFunc;
    newArray->printF = printIntFunc;
    #endif
    /*  */
    *pArray = newArray;
    return ON_SUCCESS;
}

/* 插入行末 */
int dynamicArrayInsertTail(DynamicArray *pArray, ELEMENTTYPE val)
{
    dynamicArrayInsertAppointPos(pArray, val, pArray->length);
}

/* 插入指定位置 */
int dynamicArrayInsertAppointPos(DynamicArray *pArray, ELEMENTTYPE val, int pos)
{
    /* 判空 */
    JUDGE_IFNULL(pArray);
    /* 判断非法访问 */
    if (pos < 0 || pos > pArray->length)
    {
        return INVILID_ACCESS;
    }
    /* 插入 */
    for (int idx = pArray->length; idx > pos; idx--)
    {
        pArray->data[idx] = pArray->data[idx - 1];
    }
    pArray->data[pos] = val;

    (pArray->length)++;

    /* 判断是否要放缩 */
    ifNeedScale(pArray);
    
}

/* 获取长度 */
int dynamicArrayGetLength(DynamicArray *pArray, int *pLen)
{
    JUDGE_IFNULL(pArray);
    JUDGE_IFNULL(pLen);
    *pLen = pArray->length;
    return ON_SUCCESS;
}

/* 获取容量 */
int dynamicArrayGetCapacity(DynamicArray *pArray, int *pCap)
{
    JUDGE_IFNULL(pArray);
    JUDGE_IFNULL(pCap);
    *pCap = pArray->length;
    return ON_SUCCESS;
}

/* 获取指定位置的值 */
int dynamicArrayGetValAppointPos(DynamicArray *pArray, int pos, ELEMENTTYPE *pVal)
{
    JUDGE_IFNULL(pArray);
    JUDGE_IFNULL(pVal);
    if (pos < 0 || pos > pArray->length)
    {
        return INVILID_ACCESS;
    }
    
    *pVal = pArray->data[pos];

    return ON_SUCCESS;
}

/* 修改指定位置的值 */
int dynamicArrayModify(DynamicArray *pArray, int pos, ELEMENTTYPE val)
{
    JUDGE_IFNULL(pArray);
    if (pos < 0 || pos > pArray->length)
    {
        return INVILID_ACCESS;
    }
    pArray->data[pos] = val;
    return ON_SUCCESS;
}

/* 删除行末 */
int dynamicArrayDelTail(DynamicArray *pArray)
{
    return dynamicArrayDelAppointPos(pArray, pArray->length - 1);
}

/* 删除指定位置的值 */
int dynamicArrayDelAppointPos(DynamicArray *pArray, int pos)
{
    JUDGE_IFNULL(pArray);
    if (pos < 0 || pos > pArray->length)
    {
        return INVILID_ACCESS;
    }
    for (int idx = pos; idx < pArray->length - 1; idx++)
    {
        pArray->data[idx] = pArray->data[idx + 1];
    }

    (pArray->length)--;
    ifNeedScale(pArray);
    return ON_SUCCESS;
}

/* 删除所有指定数据 */
int dynamicArrayDelAppointVal(DynamicArray *pArray, ELEMENTTYPE val)
{
    JUDGE_IFNULL(pArray);
    int *pos;
    while (dynamicArrayGetPosAppointVal(pArray, val, pos) >= 0)
    {
        dynamicArrayDelAppointPos(pArray, *pos);
    }
    return ON_SUCCESS;
}

/* 销毁动态数组 */
int dynamicArrayDestory(DynamicArray *pArray)
{
    while (pArray->length > 0)
    {
        dynamicArrayDelTail(pArray);
    }

    FREE(pArray);
    return ON_SUCCESS;
}

