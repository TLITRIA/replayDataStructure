#include "dynamicArrayStack.h"

#define DEFAULT_SIZE 10

/* 栈的初始化 */
int dynamicArrayStackInit(dynamicArrayStack *pStack)
{
    return dynamicInit(pStack, DEFAULT_SIZE);
}

/* 压栈 */
int dynamicArrayStackPush(dynamicArrayStack *pStack, ELEMENTTYPE val)
{
    /* 调用动态数组的尾插 */
    return dynamicInsertAppointData(pStack, val);
}

/* 查看栈顶元素 */
int dynamicArrayStackTop(dynamicArrayStack *pStack, ELEMENTTYPE *pVal)
{
    /* 获取动态数组位置元素 */
    return dynamicGetPosVal(pStack, pStack->length-1, pVal);
}

/* 出栈 */
int dynamicArrayStackPop(dynamicArrayStack *pStack)
{
    return dynamicDelLastData(pStack);
}

/* 判断栈是否为空 */
int dynamicArrayStackIsEmpty(dynamicArrayStack *pStack)
{
    int size = 0;
    dynamicArrayStackGetSize(pStack, &size);
    return size == 0 ? 1 : 0;
}

/* 获取栈的大小 */
int dynamicArrayStackGetSize(dynamicArrayStack *pStack, int *pSize)
{
    return dynamicGetLength(pStack, pSize);
}

/* 栈的销毁 */
int dynamicArrayStackDestroy(dynamicArrayStack *pStack)
{
    return dynamicDestroy(pStack);
}



