#include <string.h>
#include <stdio.h>
#include "dynamicArray.h"


#define BUFFER_SIZE 20
#define DEFAULT_NUM 3

typedef struct stuInfo
{
    int age;
    int sex;
} stuInfo;


int main()
{
    dynamicArray array;
    /* 初始化 */
    dynamicArrayInit(&array, BUFFER_SIZE);
#if 1
/* typedef int ELEMENTTYPE; */

    /* 初始化--插入数据 */
    for (int idx = 0; idx <= DEFAULT_NUM; idx++)
    {
        dynamicArrayInsertData(&array, idx);
    }

    /* 获取动态数组大小 */
    int size = 0;
    dynamicArrayGetSize(&array, &size);
    printf("size:%d\n", size);

    /* 获取动态数组容量 */
    int capacity = 0;
    dynamicArrayGetCapacity(&array, &capacity);
    printf("capacity:%ld\n", capacity / sizeof(int));

    
    /* 操作前打印 */
    int val = 0;
    dynamicArrayGetSize(&array, &size);
    printf("操作前打印");
    for (int idx = 0; idx < size; idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx, &val);
        printf("val[%d]:%d ", idx, val);
    }
    printf("\n");


#if 0
    /* 删除指定数据 */
    dynamicArrayDeleteAppointData(&array, 5);
#elif 0
    /* 删除指定位置 */
    dynamicArrayDeleteAppointPosData(&array, 2);
#elif 1
    /* 插入数据 */
    dynamicArrayInsertData(&array, 3);
    for (int idx = 0; idx <= DEFAULT_NUM; idx++)
    {
        dynamicArrayInsertData(&array, 21);
    }


#endif
    /* 操作后打印 */
    dynamicArrayGetSize(&array, &size);
    printf("操作后打印");
    for (int idx = 0; idx < size; idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx, &val);
        printf("val[%d]:%d ", idx, val);
    }
    printf("\n");
    
#endif

    stuInfo stu1, stu2, stu3;
    memset(&stu1, 0, sizeof(stu1));
    memset(&stu2, 0, sizeof(stu2));
    memset(&stu3, 0, sizeof(stu3));
    
    stu1.age = 10;
    stu1.sex = 'm';

    stu2.age = 20;
    stu2.sex = 'f';

    stu3.age = 30;
    stu3.sex = 'm';
#if 0

    dynamicArrayInsertData(&array, (void *)&stu1);
    dynamicArrayInsertData(&array, (void *)&stu1);
    dynamicArrayInsertData(&array, (void *)&stu1);
    

    int size = 0;
    dynamicArrayGetSize(&array, &size);
    printf("%d\n", size);

#elif 0
    stuInfo buffer[DEFAULT_NUM] = {stu1, stu2, stu3};
    for (int idx = 0; idx < DEFAULT_NUM; idx++)
    {
        dynamicArrayInsertData(&array, (void *)&buffer[idx]);
    }
    stuInfo *info = NULL;
    for (int idx = 0; idx < DEFAULT_NUM; idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx, (void *)info);
        printf("info.age:%d\tinfo.sex:%c\n", info->age, info->sex);
    }

#endif

#if 0
    int buffer[DEFAULT_NUM] = {1,2,3};
    for (int idx = 0; idx < DEFAULT_NUM; idx++)
    {
        dynamicArrayInsertData(&array, (void *)&buffer[idx]);
    }
    int size = 0;
    dynamicArrayGetSize(&array, &size);
    printf("size:%d\n", size);    

    int *val = NULL;
    for (int idx = 0; idx < DEFAULT_NUM; idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx, (void *)&val);
        printf("val:%d\n", *val);
    }
#endif

    return 0;
}

#if 1
#endif

