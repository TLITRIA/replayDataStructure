#include <stdio.h>
#include "dynamicArray.h"
#include "common.h"






/* 初始化 */
int dynamicArrayInit(DynamicArray **pArray, int cap);

/* 插入行末 */
int dynamicArrayInsertTail(DynamicArray *pArray, ELEMENTTYPE val);

/* 插入指定位置 */
int dynamicArrayInsertAppointPos(DynamicArray *pArray, ELEMENTTYPE val, int pos);

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

