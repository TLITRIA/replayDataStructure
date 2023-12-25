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

/* 对stuInfo特化打印 */
int printStuInfo(void *arg)
{
    stuInfo * info = (stuInfo*)arg;
    printf("info->age:%d, info->sex:%c\n", info->age, info->sex);
}

int printInt(int arg)
{
    int data = arg;
    printf("info:%d\n", data);
}

int main()
{
    //初始化
    LinkList *myList = NULL;
    myLinkListInit(&myList);

#if 1
    
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
    myLinkListForeach(myList, printInt);


    // 插入删除数据
    printf("头插\n");//√
    myLinkListInsertHead(myList, 2);
    myLinkListInsertHead(myList, 2);
    myLinkListInsertHead(myList, 2);
    myLinkListForeach(myList, printInt);

    printf("尾插\n");//√
    myLinkListInsertTail(myList, 5);
    myLinkListInsertTail(myList, 5);
    myLinkListInsertTail(myList, 5);
    myLinkListForeach(myList, printInt);

    /** 头删失效 
     * 参数错误，已解决 
     * */
    printf("头删\n");//√
    myLinkListDelHead(myList);
    myLinkListDelHead(myList);
    myLinkListForeach(myList, printInt);
    
    printf("尾删\n");//√
    myLinkListDelTail(myList);
    myLinkListDelTail(myList);
    myLinkListForeach(myList, printInt);
    
    printf("指定位置删\n");//头、尾、中？
    myLinkListDelAppointPos(myList, 2);
    myLinkListForeach(myList, printInt);
    
    printf("指定数据删\n");//√
    int pos;
    myLinkListDelAppointVal(myList, 2, &pos);
    myLinkListForeach(myList, printInt);
    
    /**删除链表出现错误，因为调用了head
     * 没能删掉链表，因为判断已销毁的条件是头结点为NULL
    */
    myLinkListDestroy(myList);

    JUDGE_IFDESTROY(myList->head);


#else 
    stuInfo stu1, stu2, stu3;
    memset(&stu1, 0, sizeof(stu1));
    memset(&stu2, 0, sizeof(stu2));
    memset(&stu3, 0, sizeof(stu3));

    stu1.age = 20;
    stu1.sex = 'f';
    stu2.age = 21;
    stu2.sex = 'f';
    stu3.age = 22;
    stu3.sex = 'm';
    
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
    myLinkListForeach(myList, printStuInfo);
#endif

    return 0;
}