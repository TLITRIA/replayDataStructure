









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
    int lenth;
    int capacity;
} dynamicArray;


/* 动态数组的初始化 */
int dynamicArrayInit(dynamicArray *pArray, int capcity);

/* 动态数组获取长度 */
int dynamicArrayGetLength(dynamicArray *pArray, int *length);


/* 动态数组获取容量 */














#endif








/*  END   */

