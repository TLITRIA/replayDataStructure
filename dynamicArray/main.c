#include <string.h>
#include <stdio.h>
#include "dynamicArray.h"


#define BUFFER_SIZE 20
#define DEFAULT_NUM 3

#define PRINT(a)\
printf("a=%d\n", a);\

typedef struct stuInfo
{
    int age;
    char sex;
} stuInfo;


void showAllData(dynamicArray stuArray, int size)
{
    stuInfo *tmpStu = NULL;
    dynamicArrayGetSize(&stuArray, &size);
    for (int idx = 0; idx < size; idx++)
    {
        dynamicArrayGetAppointPosVal(&stuArray, idx, (void *)&tmpStu);
        printf("stu[%d] age:%d sex:%c\n", idx, tmpStu->age, tmpStu->sex);
    }
}



int main()
{
    int sign = 0;

#if 0
    /* 测试判空宏注释 */
    sign = dynamicArrayInit(NULL, BUFFER_SIZE);
    printf("sign:%d\n", sign);

    int a = 1, b = 2;
    PRINT(a);
    PRINT(b);
#endif





#if 0
    /* 测试扩容缩容 */
    /***
     * shrinkDynamicCapacity
     * expandDynamicCapacity
    */
    dynamicArray array;
    dynamicArrayInit(&array, BUFFER_SIZE);
    printf("BUFFER_SIZE:%d\n", BUFFER_SIZE);

    /* 插入数据 */
    ELEMENTTYPE tmpNum = 0;
    for (int idx = 0; idx < BUFFER_SIZE * 50; idx++)
    {
        tmpNum = idx + 1;
        sign = dynamicArrayInsertData(&array, tmpNum);
        // printf("sign:%d\n", sign);
    }

    /* 删除数据 */
    for (int idx = 0; idx < BUFFER_SIZE * 49; idx++)
    {
        dynaminArrayDeleteData(&array);
    }

    /* 获取大小 */
    int numSize = 0;
    dynamicArrayGetSize(&array, &numSize);
    printf("numSize:%d\n", numSize);

    /* 获取容量 */
    int numCap = 0;
    dynamicArrayGetCapacity(&array, &numCap);
    printf("numCap:%d\n", numCap);
#endif



#if 0
    /* int型作为动态数组的元素 */
    /* 初始化动态数组-√ */
    dynamicArray numArray;
    dynamicArrayInit(&numArray, BUFFER_SIZE);

    /* 插入数据 */
    ELEMENTTYPE tmpNum = 0;
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        tmpNum = idx + 1;
        sign = dynamicArrayInsertData(&numArray, tmpNum);
        printf("sign:%d\n", sign);
    }

    /* 获取大小 */
    int numSize = 0;
    dynamicArrayGetSize(&numArray, &numSize);
    printf("numSize:%d\n", numSize);

    /* 获取容量 */
    int numCap = 0;
    dynamicArrayGetCapacity(&numArray, &numCap);
    printf("numCap:%d\n", numCap);

    /* 取一个指定的数据-√ */
    int numPos = 0;
    dynamicArrayGetAppointPosVal(&numArray, numPos, &tmpNum);
    printf("num[%d]:%d\n========\n", numPos, tmpNum);


    /* 查看所有数据 */
    dynamicArrayGetSize(&numArray, &numCap);
    for (int idx = 0; idx < numCap; idx++)
    {
        dynamicArrayGetAppointPosVal(&numArray, idx, &tmpNum);
        printf("num[%d]:%d\n", idx, tmpNum);
    }
    printf("========\n");

    /* 插入指定、修改指定、删除指定 */
    numPos = 2;
    tmpNum = 5;
#if 0
    dynamicArrayAppointInsertData(&numArray, numPos, tmpNum);
#elif 0
    dynamicArrayModifyAppointPosData(&numArray, numPos, tmpNum);
#elif 0
    dynamicArrayDeleteAppointPosData(&numArray, numPos);
#elif 0
    dynamicArrayDeleteAppointData(&numArray, tmpNum);
#endif
    /* 查看所有数据 */
    dynamicArrayGetSize(&numArray, &numCap);
    for (int idx = 0; idx < numCap; idx++)
    {
        dynamicArrayGetAppointPosVal(&numArray, idx, &tmpNum);
        printf("num[%d]:%d\n", idx, tmpNum);
    }
    printf("========\n");

    dynamicArrayDestory(&numArray);

    
    if (NULL == numArray.data)
    {
        printf("动态数组已销毁\n");
    }

    /* todo：验证自动扩容缩容的功能，已知不影响功能 */
#endif



#if 1
/* #define ELEMENTTYPE void* 将结构体做为元素 */
    /* 初始化动态数组-√ */
    dynamicArray stuArray;
    dynamicArrayInit(&stuArray, BUFFER_SIZE);

    /* 初始化数据 */
    stuInfo stu1, stu2, stu3;
    memset(&stu1, 0, sizeof(stu1));
    memset(&stu2, 0, sizeof(stu2));
    memset(&stu3, 0, sizeof(stu3));
    stu1.age = 10;
    stu1.sex = 'f';
    stu2.age = 20;
    stu2.sex = 'm';
    stu3.age = 30;
    stu3.sex = 'f';

    /* 插入数据-√ */
    dynamicArrayInsertData(&stuArray, (void *)&stu1);
    dynamicArrayInsertData(&stuArray, (void *)&stu2);
    dynamicArrayInsertData(&stuArray, (void *)&stu3);
    dynamicArrayInsertData(&stuArray, (void *)&stu3);
    dynamicArrayInsertData(&stuArray, (void *)&stu3);
    dynamicArrayInsertData(&stuArray, (void *)&stu3);
    
    /* 获取大小-√ */
    int size = 0;
    dynamicArrayGetSize(&stuArray, &size);
    printf("size:%d\n", size);

    /* 获取容量-√ */
    int cap = 0;
    dynamicArrayGetCapacity(&stuArray, &cap);
    printf("capicity:%d\n", cap);
    
    /* 取一个指定的数据-√ */
    int pos = 0;
    stuInfo *tmpStu = NULL;
    // memset(&tmpStu, 0, sizeof(tmpStu));指针结构体需要使用-》
    dynamicArrayGetAppointPosVal(&stuArray, pos, (void *)&tmpStu);
    printf("age:%d sex:%c\n", tmpStu->age, tmpStu->sex);
    
    /* 查看数组所有的数据 */
    #if 1
    dynamicArrayGetSize(&stuArray, &size);
    for (int idx = 0; idx < size; idx++)
    {
        dynamicArrayGetAppointPosVal(&stuArray, idx, (void *)&tmpStu);
        printf("stu[%d] age:%d sex:%c\n", idx, tmpStu->age, tmpStu->sex);
    }
    printf("===================\n");
    #else
    showAllData(stuArray, size);//为什么不能加&
    #endif

    /* 插入指定√、修改指定、（修改末尾）、删除指定*/
    stuInfo stuNew;
    memset(&stuNew, 0, sizeof(stuNew));
    stuNew.age = 500;
    stuNew.sex = 'A';

    stuInfo stuDel;
    memset(&stuDel, 0, sizeof(stuDel));
    stuDel.age = 10;
    stuDel.sex = 'f';
#if 1
    // stuInfo *stuNew = NULL;
    // stuNew->age = 500;
    // stuNew->sex = 'A';(void *)&stuNew段错误
    dynamicArrayAppointInsertData(&stuArray, 5, (void *)&stuNew);// 为什么1-5都变了？
#elif 0
    dynamicArrayModifyAppointPosData(&stuArray, 5, (void *)&stuNew);
#elif 0
    dynamicArrayDeleteAppointPosData(&stuArray, 5);
#elif 0
    dynamicArrayDeleteAppointData(&stuArray, &stuDel);// 如何判定数组元素一致呢
#endif
    dynamicArrayGetSize(&stuArray, &size);
    for (int idx = 0; idx < size; idx++)
    {
        dynamicArrayGetAppointPosVal(&stuArray, idx, (void *)&tmpStu);
        printf("stu[%d] age:%d sex:%c\n", idx, tmpStu->age, tmpStu->sex);
    }
    printf("===================\n");

    dynamicArrayDestory(&stuArray);

    
    if (NULL == stuArray.data)
    {
        printf("动态数组已销毁\n");
    }


    

#endif
    
    return 0;
}


/*  END   */

