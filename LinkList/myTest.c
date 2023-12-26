#include <stdio.h>
#include "myLinkList.h"
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 3

#define PRINT_INT(num)          \
printf("%s:%d\n", #num, num);   \


#define JUDGE_MALLOC(p)     \
if (NULL == p)              \
    printf("MALLOC_ERROR\n");  return -1;    \


#define JUDGE_IFDESTROY(p)      \
if (NULL == p)                  \
    printf("链表已销毁\n");      \
else                            \
    printf("链表未销毁\n");      \


typedef struct stuInfo
{
    int age;
    char sex;
} stuInfo; 



int printFuncInt(int arg)
{
    int data = arg;
    printf("info:%d\n", data);
}

int compareFuncInt(int arg1, int arg2)
{
    return (arg1 == arg2) ? 1 : 0;
}
/* 对stuInfo特化打印 */
int printFuncStuInfo(void *arg)
{
    stuInfo * info = (stuInfo*)arg;
    printf("info->age:%d, info->sex:%c\n", info->age, info->sex);
}

int compareFuncStuInfo(void *arg1, void *arg2)
{/* 相同则返回1 */
    stuInfo *info1 = (void *)arg1;
    stuInfo *info2 = (void *)arg2;
    return (info1->age == info2->age && info1->sex == info2->sex) ? 1 : 0;
}

int main()
{
    //初始化
    LinkList *myList = NULL;
    

#if 0
    myLinkListInit(&myList, compareFuncInt, printFuncInt);
    //插入数据
    ELEMENTTYPE buffer[BUFFER_SIZE] = {1, 2, 3};
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        myLinkListInsertTail(myList, buffer[idx]);
        // myLinkListInsertHead(myList, buffer[idx]);
        
    }
    // 获取长度
    int size = 0;
    myLinkListGetLength(myList, &size);
    PRINT_INT(size);
    //遍历链表
    myLinkListForeach(myList);


    // 插入删除数据
    printf("头插3个2\n");//√
    myLinkListInsertHead(myList, 2);
    myLinkListInsertHead(myList, 2);
    myLinkListInsertHead(myList, 2);
    myLinkListForeach(myList);

    printf("尾插3个5\n");//√
    myLinkListInsertTail(myList, 5);
    myLinkListInsertTail(myList, 5);
    myLinkListInsertTail(myList, 5);
    myLinkListForeach(myList);

    /** 头删失效 
     * 参数错误，已解决 
     * */
    printf("头删2个\n");//√
    myLinkListDelHead(myList);
    myLinkListDelHead(myList);
    myLinkListForeach(myList);
    
    printf("尾删2个\n");//√
    myLinkListDelTail(myList);
    myLinkListDelTail(myList);
    myLinkListForeach(myList);
    
    printf("指定位置【位置为2】删\n");//√
    myLinkListDelAppointPos(myList, 2);
    myLinkListForeach(myList);
    
    printf("指定数据删【值为2】\n");//√
    int pos;
    myLinkListDelAppointVal(myList, 2);
    myLinkListForeach(myList);
    
    /**删除链表出现错误，因为调用了head
     * 没能删掉链表，因为判断已销毁的条件是头结点为NULL
    */
    myLinkListDestroy(myList);

    JUDGE_IFDESTROY(myList->head);


#else 
    myLinkListInit(&myList, compareFuncStuInfo, printFuncStuInfo);
    stuInfo stu1, stu2, stu3, stu4;
    memset(&stu1, 0, sizeof(stu1));
    memset(&stu2, 0, sizeof(stu2));
    memset(&stu3, 0, sizeof(stu3));

    stu1.age = 20;
    stu1.sex = 'f';
    stu2.age = 21;
    stu2.sex = 'f';
    stu3.age = 22;
    stu3.sex = 'm';
    stu4.age = 21;
    stu4.sex = 'f';
    
    stuInfo buffer[BUFFER_SIZE] = {stu1, stu2, stu3};

    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        myLinkListInsertHead(myList, (void *)&buffer[idx]);
    }

    /* 获取链表的长度 */
    int size = 0;
    myLinkListGetLength(myList, &size);
    printf("size:%d\n", size);

    /* 遍历 */
    myLinkListForeach(myList);


    printf("头插3个STU4\n");//
    myLinkListInsertHead(myList, (void *)&stu4);
    myLinkListInsertHead(myList, (void *)&stu4);
    myLinkListInsertHead(myList, (void *)&stu4);
    myLinkListForeach(myList);

    printf("尾插3个SU4\n");//
    myLinkListInsertTail(myList, (void *)&stu4);
    myLinkListInsertTail(myList, (void *)&stu4);
    myLinkListInsertTail(myList, (void *)&stu4);
    myLinkListForeach(myList);

    printf("头删2个\n");//
    myLinkListDelHead(myList);
    myLinkListDelHead(myList);
    myLinkListForeach(myList);
    
    printf("尾删2个\n");//
    myLinkListDelTail(myList);
    myLinkListDelTail(myList);
    myLinkListForeach(myList);
    
    printf("指定位置【位置为2】删\n");//
    myLinkListDelAppointPos(myList, 2);
    myLinkListForeach(myList);
    
    printf("指定数据删【stu4=stu2】\n");//
    int pos;
    myLinkListDelAppointVal(myList, (void *)&stu4);
    myLinkListForeach(myList);

    /* 删除链表 */
    myLinkListDestroy(myList);

    JUDGE_IFDESTROY(myList->head);

#endif

    return 0;
}