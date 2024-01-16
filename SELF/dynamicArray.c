#include <stdio.h>
#include <stdlib.h>

#include "dynamicArray.h"
#include "common.h"



/* 静态函数声明 */
static int scaleCapacity(DynamicArray *pArray, int cap);
static int ifNeedScale(DynamicArray *pArray);


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

/* 操作之后判断 */
static int ifNeedScale(DynamicArray *pArray);

/* 初始化 */
int dynamicArrayInit(DynamicArray **pArray, int cap,  int maxCap, int minCap,
                    int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2),
                    int (*printFunc)(ELEMENTTYPE val))
{
    JUDGE_IFNULL(pArray);
    if (cap <= 0)
    {
        return INVILID_ACCESS;
    }

    DynamicArray *newArray = (DynamicArray *)malloc(sizeof(DynamicArray) * 1);
    JUDGE_MALLOC(newArray);
    memset(newArray, 0, sizeof(DynamicArray) * 1);

    newArray->length = 0;
    newArray->capacity = cap;
    #if 1
    newArray->compareF = compareFunc;
    newArray->printF = compareFunc;
    #else
    newArray->compareF = compareIntFunc;
    newArray->printF = printIntFunc;
    #endif
    newArray->data = NULL;

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
    JUDGE_IFNULL(pArray);
    if (pos < 0 || pos > pArray->length)
    {
        return INVILID_ACCESS;
    }

    /* 判断是否要放缩 */
    
    
}

/* 获取长度 */
int dynamicArrayGetLength(DynamicArray *pArray, int *pLen);

/* 获取容量 */
int dynamicArrayGetCapacity(DynamicArray *pArray, int *pCap);

/* 获取指定位置的值 */
int dynamicArrayGetValAppointPos(DynamicArray *pArray, int pos, ELEMENTTYPE *pVal);

/* 修改指定位置的值 */
int dynamicArrayModify(DynamicArray *pArray, int pos, ELEMENTTYPE val);

/* 删除行末 */
int dynamicArrayDelTail(DynamicArray *pArray);

/* 删除指定位置的值 */
int dynamicArrayDelAppointPos(DynamicArray *pArray, int pos);

/* 删除所有指定数据 */
int dynamicArrayDelAppointVal(DynamicArray *pArray, ELEMENTTYPE val);

/* 销毁动态数组 */
int dynamicArrayDestory(DynamicArray *pArray);

