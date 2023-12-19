#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamicArray.h"

/* 状态码 */
enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};

#define DEFAULT_SIZE 10

/* 判空 */
#define JUDGE_NULL(pArray)          \
if (NULL == pArray)                 \
{                                   \
    return NULL_PTR;                \
}                                   \

/* 判断pos合法性 */
#define JUDGE_POS(pos, len)         \
if (pos < 0 || pos >= len)          \
{                                   \
    return INVALID_ACCESS;          \
}


/* 静态函数---前置声明 */
static int expandDynamicCapacity(dynamicArray *pArray);
static int shrinkDynamicCapacity(dynamicArray *pArray);


/* 动态数组---初始化 */
int dynamicArrayInit(dynamicArray *pArray, int capacity)
{   /* 判空 */
    JUDGE_NULL(pArray);

    /* 分配空间 */
    if (capacity < 0)
    {
        capacity = DEFAULT_SIZE;//避免传入非法值
    }
    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * capacity);
    if (NULL == pArray->data)
    {
        return MALLOC_ERROR;
    }
    memset(pArray->data, 0, sizeof(ELEMENTTYPE) * capacity);//清除脏数据


    /* 初始化动态数组的参数属性 */
    pArray->len = 0;
    pArray->capacity = capacity;

    
    return ON_SUCCESS;
}

/* 动态数组---插入数据（默认查到数组的末尾） */
int dynamicArrayInsertData(dynamicArray *pArray, ELEMENTTYPE val)
{
    dynamicArrayAppointInsertData(pArray, pArray->len, val);//核心代码在这里面
}

/* 动态数组---扩容 */
static int expandDynamicCapacity(dynamicArray *pArray)  //原文件使用
{
    int ret = 0;

    int needExpandCapacity = pArray->capacity + (pArray->capacity >> 1);
    /* 备份指针 */
    ELEMENTTYPE * tmpPtr = pArray->data;
    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * needExpandCapacity);
    if (pArray->data == NULL)
    {
        return MALLOC_ERROR;
    }

    /* 把数据全部拷贝到新内存 */
    for (int idx = 0; idx < pArray->len; idx++)
    {
        pArray->data[idx] = tmpPtr[idx];//??为什么不能pArray->data = tmpPtr
    }

    /* 释放以前的内存，避免内存泄漏 */
    if (tmpPtr != NULL)
    {
        free(tmpPtr);
        tmpPtr = NULL;
    }

    /* 更新动态数组的容量 */
    // printf("[扩容]长度：%d\t原容量：%d\t现容量：%d\n", pArray->len, pArray->capacity, needExpandCapacity);
    pArray->capacity = needExpandCapacity;

    return ret;
}

/* 动态数组---插入数据（在指定位置插入） */
int dynamicArrayAppointInsertData(dynamicArray *pArray, int pos, ELEMENTTYPE val)
{
    /* 指针判空 */
    JUDGE_NULL(pArray);

    /* 判断位置合法性 */
    JUDGE_POS(pos, pArray->len);


    /***扩容机制
     * 扩容算法未雨绸缪：数组大小的1.5倍 >= 数组容量
     *    */
    if ((pArray->len >> 1) + pArray->len > pArray->capacity)
    {
        expandDynamicCapacity(pArray);
    }

#if 1
    for (int idx = pArray->len; idx > pos; idx--)
    {
        pArray->data[idx] = pArray->data[idx - 1];
    }   
#else 
    /* 数据后移会覆盖数据 */
    for (int idx = pos; idx > pArray->len; idx++)
    {
        pArray->data[idx] = pArray->data[idx + 1];
    }
#endif
    /* 找到对应的值，写入到数组中，数组大小加一 */
    pArray->data[pos] = val;
    (pArray->len)++;

    return ON_SUCCESS;

}

/* 动态数组---修改指定位置数据 */
int dynamicArrayModifyAppointPosData(dynamicArray *pArray, int pos, ELEMENTTYPE val)
{
    /* 指针判空 */
    JUDGE_NULL(pArray);

    /* 判断位置的合法性 */
    JUDGE_POS(pos, pArray->len);

    /* 更新位置的数据 */
    pArray->data[pos] = val;

    return ON_SUCCESS;
}

/* 动态数组---删除数据（默认删除末尾的数据） */
int dynaminArrayDeleteData(dynamicArray *pArray)
{
    dynamicArrayDeleteAppointPosData(pArray, pArray->len - 1);
}

/* 动态数组---缩容 */
static int shrinkDynamicCapacity(dynamicArray *pArray)
{
    int needShrinkCapacity = pArray->capacity - (pArray->capacity >> 1);
    ELEMENTTYPE * tmpPtr = pArray->data;
    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * needShrinkCapacity);
    if (NULL == pArray->data)
    {
        return MALLOC_ERROR;
    }

    /* 拷贝数据到新的空间 */
    for (int idx = 0; idx < pArray->len; idx++)
    {
        pArray->data[idx] = tmpPtr[idx];
    }

    /* 释放内存空间 避免内存泄露 */
    if (tmpPtr != NULL)
    {
        free(tmpPtr);
        tmpPtr = NULL;
    }

    /* 更新容量 */
    printf("[缩容]长度：%d\t原容量：%d\t现容量：%d\n", pArray->len, pArray->capacity, needShrinkCapacity);
    pArray->capacity = needShrinkCapacity;
    return ON_SUCCESS;
}

/* 动态数组---删除数据（指定位置） */
int dynamicArrayDeleteAppointPosData(dynamicArray *pArray, int pos)
{
    /* 指针判空 */
    JUDGE_NULL(pArray);
    
    /* 判断位置的合法性 */
    JUDGE_POS(pos, pArray->len);

    /* 缩容 */
    if (pArray->len < (pArray->capacity >> 1)) // ??要缩多少就所多少不能有差错
    {
        shrinkDynamicCapacity(pArray);
    }    

    /* 数据前移 */
    for (int idx = pos; idx < pArray->len; idx++)
    {
        pArray->data[idx] = pArray->data[idx + 1];
    }

    /* 更新数组大小 */
    (pArray->len)--;
    return ON_SUCCESS;
}

/* 动态数组---删除数据（指定数据） */
int dynamicArrayDeleteAppointData(dynamicArray *pArray, ELEMENTTYPE val)
{
#if 0
    int idx = 0;
    for (idx; idx < pArray->len; idx++)
    {
        if (val == pArray->data[idx])
        {
            dynamicArrayDeleteAppointPosData(pArray, idx);
            idx = 0;
        }
    }
#elif 1
    for (int idx = pArray->len - 1; idx >= 0; idx--)
    {
        if (val == pArray->data[idx])
        {
            dynamicArrayDeleteAppointPosData(pArray, idx);
        }
    }
#elif 0
    // for

#endif
    return ON_SUCCESS;
}

/* 动态数组---销毁 */
int dynamicArrayDestory(dynamicArray *pArray)
{
    if (pArray == NULL)
    {
        return NULL_PTR;
    }

    if (pArray->data != NULL)
    {
        free(pArray->data);
        pArray->data = NULL;
    }
    return ON_SUCCESS;
}

/* 动态数组获取---大小 */
int dynamicArrayGetSize(dynamicArray *pArray, int *pSize)
{
    if (pArray == NULL)
    {
        return NULL_PTR;
    }
    /* 解引用 */
    if (pSize != NULL)
    {
        *pSize = pArray->len;
    }
    
    return ON_SUCCESS;
}

/* 动态数组获取---容量 */
int dynamicArrayGetCapacity(dynamicArray *pArray, int *pSize)
{
    if (pArray == NULL)
    {
        return NULL_PTR;
    }
    /* 解引用 */
    if (pSize != NULL)
    {
        *pSize = pArray->capacity;
    }
    
    return ON_SUCCESS;
}


/* 获取指定位置的数据 */
int dynamicArrayGetAppointPosVal(dynamicArray *pArray, int pos, ELEMENTTYPE *pVal)
{
    /* 判空 */
    JUDGE_NULL(pArray);
    
    
    /* 判断位置的合法性 */
    JUDGE_POS(pos, pArray->len);

    if (pVal)
    {
        *pVal = pArray->data[pos];
    }

    return ON_SUCCESS;

    
}


/*  END   */

