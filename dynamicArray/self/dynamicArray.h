#ifndef _DYNAMICARRAY_H_
#define _DYNAMICARRAY_H_

#if 1
    #define ELEMENTTYPE int
#else
    #define ELEMENTTYPE void*
#endif

typedef struct dynamicArray
{
    ELEMENTTYPE *data;
    int length;
    int capacity;
} dynamicArray;



/* 初始化动态数组 */
int dynamicArrayInit(dynamicArray ** pArray, int cap);

/* 插入动态数组--行末 */
int dynamicArrayInsertTail(dynamicArray *pArray, ELEMENTTYPE val);

/* 插入动态数组--指定位置 */
int dynamicArrayInsertAppointPos(dynamicArray *pArray, int pos, ELEMENTTYPE val);

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


#endif

/*===============END================*/
