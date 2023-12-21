#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamicArray.h"

/* 默认值 */
#define DEFAULT_SIZE 10

enum STATUS_CODE
{
    INVALID_ACCESS = -3,
    MALLOC_ERROR = -2,
    PTR_ERROR,
    ON_SUCCESS,
};


/* 判空 */
#define JUDGE_NULL(pArray)  \
if (NULL == pArray)         \
    return PTR_ERROR;       \

/* malloc是否成功分配？ */
#define JUDGE_MALLOC(p)     \
if (NULL == p)              \
    return MALLOC_ERROR;    \

/* 判断位置是否合法 两种 */
#define JUDGE_POS_INSERT(pos, len)\
if (pos < 0 || pos > len)\
    return INVALID_ACCESS;\

#define JUDGE_POS_GET(pos, len)\
if (pos < 0 || pos >= len)\
    return INVALID_ACCESS;\



#define JUDGE_IFNEEDZOOM(pArray)\



/* 初始化动态数组 */
int dynamicArrayInit(dynamicArray ** pArray, int cap)
{
    JUDGE_NULL(pArray);
    if (cap < 0)
    {
        cap = DEFAULT_SIZE;
    }

    dynamicArray * array;
    
    array->capacity = cap;
    array->length = 0;
    array->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * cap);
    JUDGE_MALLOC(array->data);
    memset(array->data, 0, sizeof(ELEMENTTYPE) * cap);

    *pArray = array;

    return ON_SUCCESS;
}

/* 插入动态数组--行末 */
int dynamicArrayInsertTail(dynamicArray *pArray, ELEMENTTYPE val)
{
    dynamicArrayInsertAppointPos(pArray, pArray->length, val);
}

/* 插入动态数组--指定位置 */
int dynamicArrayInsertAppointPos(dynamicArray *pArray, int pos, ELEMENTTYPE val)
{
    JUDGE_NULL(pArray);
    JUDGE_POS_INSERT(pos, pArray->length);
    JUDGE_IFNEEDZOOM(pArray);

    


}

/* 获取长度 */
int dynamicArrayGetLength(dynamicArray *pArray, int *len);

/* 获取容量 */
int dynamicArrayGetCapacity(dynamicArray *pArray, int *cap);

/* 获取指定位置的值 */
int dynamicArrayGetValAppointPos(dynamicArray *pArray, int pos, ELEMENTTYPE *pVal);

/* 修改动态数组--指定位置 */
int dynamicArrayModifyAppointPos(dynamicArray *pArray, int pos, ELEMENTTYPE val);

/* 删除动态数组数据--行末 */
int dynamicArrayDelTail(dynamicArray *pArray);

/* 删除动态数组数据-指定位置 */
int dynamicArrayDelAppointPos(dynamicArray *pArray, int pos);

/* 删除动态数组数据-所有指定值 */
int dynamicArrayDelAllAppointData(dynamicArray *pArray, ELEMENTTYPE val);

/* 销毁动态数组 */
int dynamicArrayDestroy(dynamicArray *pArray);







/*===============END================*/

