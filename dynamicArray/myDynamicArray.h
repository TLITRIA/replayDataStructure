#ifndef __MYDYNAMICARRAY_H_
#define __MYDYNAMICARRAY_H_
// 防止重定义

// 两种元素类型

#if 1
#define ELEMENTTYPE int
#else
#define ELEMENTTYPE void*
#endif

// 动态数组类型-数组、长度、容量

typedef struct dynamicArray
{
    ELEMENTTYPE * data;
    int length;
    int capacity;
} dynamicArray;


/* 初始化动态数组 */
int dynamicInit(dynamicArray *pArray, int capcity);

/* 插入动态数组--行末 */
int dynamicInsertAppointData(dynamicArray *pArray, ELEMENTTYPE val);

/* 插入动态数组--指定位置 */
int dynamicInsertAppointPosData(dynamicArray *pArray, int pos, ELEMENTTYPE val);

/* 修改动态数组--指定位置 */
int dynamicModifyPosData(dynamicArray *pArray, int pos, ELEMENTTYPE val);

/* 删除动态数组数据--行末 */
int dynamicDelLastData(dynamicArray *pArray);

/* 删除动态数组数据-指定位置 */
int dynamicDelPosData(dynamicArray *pArray, int pos);

/* 删除动态数组数据-所有指定值 */
int dynamicDelData(dynamicArray *pArray, int val);

/* 销毁动态数组 */
int dynamicDestroy(dynamicArray *pArray);

/* 获取长度 */
int dynamicGetLength(dynamicArray *pArray, int *length);

/* 获取容量 */
int dynamicGetCapacity(dynamicArray *pArray, int *capacity);

/* 获取指定位置的值 */
int dynamicGetPosVal(dynamicArray *pArray, int pos, ELEMENTTYPE *pVal);












#endif








/*  END   */

