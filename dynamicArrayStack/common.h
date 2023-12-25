#ifndef _COMMON_H_
#define _COMMON_H_


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


#endif // _COMMON_H_