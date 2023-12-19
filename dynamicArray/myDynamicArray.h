#ifndef __MYDYNAMICARRAY_H_
#define __MYDYNAMICARRAY_H_

#if 1
#define ELEMENTTYPE int
#else
#define ELEMENTTYPE void*
#endif


typedef struct dynamicArray
{
    ELEMENTTYPE * data;
    int length;
    int capacity;
} dynamicArray;


/* 动态数组的初始化 */
int dynamicInit(dynamicArray *pArray, int capcity);

/* 动态数组插入-行末 */
int dynamicInsertAppointData(dynamicArray *pArray, ELEMENTTYPE val);

/* 动态数组插入-指定位置 */
int dynamicInsertAppointPosData(dynamicArray *pArray, int pos, ELEMENTTYPE val);

/* 动态数组修改指定位置数据 */
int dynamicModifyPosData(dynamicArray *pArray, int pos, ELEMENTTYPE val);


/* 动态数组删除数据-行末 */
int dynamicDelLastData(dynamicArray *pArray);

/* 动态数组删除数据-指定位置 */
int dynamicDelPosData(dynamicArray *pArray, int pos);

/* 动态数组删除数据-指定值 */
int dynamicDelData(dynamicArray *pArray, int val);

/* 动态数组销毁 */
int dynamicDestroy(dynamicArray *pArray);

/* 动态数组获取长度 */
int dynamicGetLength(dynamicArray *pArray, int *length);

/* 动态数组获取容量 */
int dynamicGetCapacity(dynamicArray *pArray, int *capacity);

/* 动态数组获取指定元素 */
int dynamicGetPosVal(dynamicArray *pArray, int pos, ELEMENTTYPE *pVal);












#endif








/*  END   */

