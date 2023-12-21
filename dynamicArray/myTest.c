#include <string.h>
#include <stdio.h>
#include "myDynamicArray.h"

// 宏定义默认缓存长度
#define BUFFER_SIZE 20
#define DEFAULT_NUM 3


#define PRINT(a)\
printf("%-5s : %d\n", #a, a);\
// 判断是否销毁
#define JUDGE_IFDESTROY(array)\
if (NULL == array.data)\
        printf("动态数组已销毁\n");\
    else\
        printf("动态数组未销毁\n");\

int main()
{
    // 创建动态数组和标志，试试二级指针
    int sign = 0;
    dynamicArray array;
    // 初始化
    sign = dynamicInit(&array, BUFFER_SIZE);
    // PRINT(sign);

    // 插入数据
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        dynamicInsertAppointData(&array, idx);
    }
    // 获取长度
    int len = 0;
    dynamicGetLength(&array, &len);
    PRINT(len);
// 获取容量
    int cap = 0;
    dynamicGetCapacity(&array, &cap);
    PRINT(cap);
// 取一个
    int pos = 6;
    ELEMENTTYPE tmpNum = 0;
    dynamicGetPosVal(&array, pos, &tmpNum);
    PRINT(tmpNum);


// 自定义输出
    printf("===========\n");
    dynamicGetLength(&array, &len);
    for (int idx = 0; idx < len; idx++)
    {
        dynamicGetPosVal(&array, idx, &tmpNum);
        printf("array[%d]:%d\n", idx, tmpNum);
    }
    printf("===========\n");

// 测试修改、删除末尾、删除指定位置、删除指定值并输出

#if 0
    pos = 6;
    tmpNum = 10;
    dynamicModifyPosData(&array, pos, tmpNum);
#elif 0
    dynamicDelLastData(&array);
#elif 0
    pos = 6;
    dynamicDelPosData(&array, pos);
#elif 0
    pos = 6;
    dynamicDelPosData(&array, pos);
    tmpNum = 7;
    dynamicDelData(&array, tmpNum);
#endif

    dynamicGetLength(&array, &len);
    for (int idx = 0; idx < len; idx++)
    {
        dynamicGetPosVal(&array, idx, &tmpNum);
        printf("array[%d]:%d\n", idx, tmpNum);
    }
    printf("===========\n");
// 销毁数组
    JUDGE_IFDESTROY(array);
    dynamicDestroy(&array);
    JUDGE_IFDESTROY(array);

    return 0;
}









/*    END    */

