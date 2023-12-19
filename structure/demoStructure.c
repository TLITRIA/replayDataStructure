#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEFAULT_SIZE 2
#define BUFFER_SIZE 16

/*****结构体
 * 1. 什么叫结构体？将不同类型的属性封装成一个类型
 * 2. 怎么定义结构体？
*/
typedef struct stuInfo
{
    int age;
    int weight;
    int height;
    char sex;
    char name[BUFFER_SIZE];
    char *address;
#if 0
    char clothes;
    char shoes;
    char phones;//??
#endif
} stuInfo;

#if 0
/* 取别名 */
typedef struct stuInfo stuInfo;
#endif

/***
 * 结构体会默认进行字节对齐：读取速度快但是浪费空间
 * 结构的位域到网络编程再探究，todo...
 * 什么叫变长结构体？
*/

/* 函数：结构体做函数 */
#if 0
/* 值传递：不影响实参 */
int printStruct(stuInfo stu)
{
    /* 栈空间小的很，不允许超过8M */
    stu.age = 100;
    printf("stu.age:%d, stu.height:%d, stu.sex:%c, stu.weight%d, stu.name%s\n",\
            stu.age, stu.height, stu.sex, stu.weight, stu.name);
    
    return 0;
}

#else
/* 传入参数：不要改变值 */
int printStruct(const stuInfo *stu)
{
    /* 栈空间小的很，不允许超过8M */
    /* 结构体必须使用指针 省内存空间 */
    int ret = 0;
    int len = sizeof(stu);
    printf("len:%d\n", len);
    /* 栈空间小，不允许超过8M */
    // printf("stu.age:%d, stu.height:%d, stu.sex:%c, stu.weight%d, stu.name%s\n",\
    //         stu.age, stu.height, stu.sex, stu.weight, stu.name);
    return 0;
}
#endif

/* 结构体数组做函数参数 */
int printStructBuffer(stuInfo *stu, int stuSize)
{
    for(int idx = 0; idx < stuSize; idx++)
    {
        printf("stu.age:%d, stu.height:%d, stu.sex:%c, stu.weight%d, stu.name%s\n",\
            stu[idx].age, stu[idx].height, stu[idx].sex, stu[idx].weight, stu[idx].name);
    
    }

    return 0;

}

int main()
{
#if 1
    /* 3. 怎么使用结构体 */
    stuInfo stu;
    memset(&stu, 0, sizeof(stu));

#if 0
    stu.age = 10;
    stu.height = 100;
    stu.sex = 'M';
    stu.weight = 50;
    strncpy(stu.name, "zhangsan", sizeof(stu.name) - 1);

    printf("stu.age:%d, stu.height:%d, stu.sex:%c, stu.weight%d, stu.name%s\n",\
            stu.age, stu.height, stu.sex, stu.weight, stu.name);
#endif

#if 0
    /* 4. 结构体的大小 */
    int len = sizeof(stu);
    printf("len:%d\n", len);

    /* 5. 结构体数组 */
    /**
     * 数组：
     * 1. 连续的一块内存空间
     * 2. 存放一致的数据类型
    */

    stuInfo buffer[DEFAULT_SIZE];

    buffer[0].age = 10;
    buffer[0].weight = 30;
    buffer[0].sex = 'M';
    buffer[0].height = 130;
    strncpy(buffer[0].name, "zhangsan", sizeof(buffer[0].name) - 1);

    buffer[1].age = 20;
    buffer[1].weight = 50;
    buffer[1].sex = 'F';
    buffer[1].height = 160;
    strncpy(buffer[1].name, "wangwu", sizeof(buffer[1].name) - 1);

    printf("buffer.age:%d, buffer.height:%d, buffer.sex:%c, buffer.weight%d, buffer.name%s\n",\
            buffer[0].age, buffer[0].height, buffer[0].sex, buffer[0].weight, buffer[0].name);
    printf("buffer.age:%d, buffer.height:%d, buffer.sex:%c, buffer.weight%d, buffer.name%s\n",\
            buffer[1].age, buffer[1].height, buffer[1].sex, buffer[1].weight, buffer[1].name);
#endif

#if 0
    /* 结构体指针 */
    stu.age = 10;
    stu.weight = 30;
    stu.sex = 'M';
    stu.height = 130;
    strncpy(stu.name, "zhangsan", sizeof(stu.name) - 1);
/* L:126 */

#if 0
    int a = 5;
    int *p = &a;

    stuInfo * info = &stu;
    info->age = 30;
#endif
    printStruct(&stu);
    printf("stu.age:%d\n", stu.age);

#endif




#if 0
    /* 结构体数组 */
    stuInfo buffer[DEFAULT_SIZE];
    buffer[0].age = 10;
    buffer[0].weight = 30;
    buffer[0].sex = 'M';
    buffer[0].height = 130;
    strncpy(buffer[0].name, "zhangsan", sizeof(buffer[0].name) - 1);

    buffer[1].age = 20;
    buffer[1].weight = 50;
    buffer[1].sex = 'F';
    buffer[1].height = 160;
    strncpy(buffer[1].name, "zhangsan", sizeof(buffer[0].name) - 1);

    printStructBuffer(buffer, sizeof(buffer) / sizeof(buffer[0]));    
#endif



#if 0

    /* 结构体指针 */
    stu.age = 10;
    stu.weight = 30;
    stu.sex = 'M';
    stu.height = 130;
    strncpy(stu.name, "zhangsan", sizeof(stu.name) - 1);

    /* 结构体内有指针 必须分配空间 */
    stu.address = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    if (NULL == stu.address)
    {
        return -1;
    }
    // strcpy(stu.address, "china");

#endif


#endif


    return 0;
}

#if 1
#endif