#ifndef __DYNAMIC_ARRAY_H_
#define __DYNAMIC_ARRAY_H_

#if 1
#define ELEMENTTYPE int
// #define ELEMENTTYPE void*
#else
// typedef int ELEMENTTYPE;
// typedef void * ELEMENTTYPE;
#endif

/* 避免头文件的重复包含 */
typedef struct dynamicArray
{
    ELEMENTTYPE *data;      //数组的空间??为什么用ELEMENTTYPE?
    int len;                //数组的大小
    int capacity;           //数组的容量
} dynamicArray;

/* API: application program interface. */

/* 动态数组的初始化 */
int dynamicArrayInit(dynamicArray *pArray, int capacity);

/* 动态数组插入数据（默认插到数组的末尾） */
int dynamicArrayInsertData(dynamicArray *pArray, ELEMENTTYPE val);

/* 动态数组插入数据（在指定位置插入） */
int dynamicArrayAppointInsertData(dynamicArray *pArray, int pos, ELEMENTTYPE val);

/* 动态数组修改指定位置数据 */
int dynamicArrayModifyAppointPosData(dynamicArray *pArray, int pos, ELEMENTTYPE val);

/* 动态数组删除数据（默认删除末尾的数据） */
int dynaminArrayDeleteData(dynamicArray *pArray);

/* 动态数组删除数据（指定位置） */
int dynamicArrayDeleteAppointPosData(dynamicArray *pArray, int pos);

/* 动态数组删除数据（指定数据） */
int dynamicArrayDeleteAppointData(dynamicArray *pArray, ELEMENTTYPE val);

/* 动态数组销毁 */
int dynamicArrayDestory(dynamicArray *pArray);

/* 动态数组获取大小 */
int dynamicArrayGetSize(dynamicArray *pArray, int *pSize);

/* 动态数组获取容量 */
int dynamicArrayGetCapacity(dynamicArray *pArray, int *pSize);

/* 获取指定位置的数据 */
int dynamicArrayGetAppointPosVal(dynamicArray *pArray, int pos, ELEMENTTYPE *pVal);

#endif // __DYNAMIC_ARRAY_H_


/*  END   */

