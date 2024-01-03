#include <stdio.h>
#include "myDoubleLinkList.h"
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
    printf("age:%d, sex:%c\n", info->age, info->sex);
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
    DoubleLinkList *myList = NULL;
    

#if 0
/* int 型 */
    myDoubleLinkListInit(&myList, compareFuncInt, printFuncInt);
    //插入数据
    ELEMENTTYPE buffer[BUFFER_SIZE] = {1, 2, 3};
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        myDoubleLinkListInsertTail(myList, buffer[idx]);
        // myDoubleLinkListInsertHead(myList, buffer[idx]);
        
    }
    // 获取长度
    int size = 0;
    myDoubleLinkListGetLength(myList, &size);
    PRINT_INT(size);
    //遍历链表
    myDoubleLinkListForeach(myList);



    // 头插
    printf("头插2个4\n");
    myDoubleLinkListInsertHead(myList, 4);
    myDoubleLinkListInsertHead(myList, 4);
    myDoubleLinkListForeach(myList);
    // 尾插
    printf("尾插2个4\n");
    myDoubleLinkListInsertTail(myList, 4);
    myDoubleLinkListInsertTail(myList, 4);
    myDoubleLinkListForeach(myList);
    // 指定位置插入
    printf("指定位置插入5\n");
    myDoubleLinkListInsertAppointPos(myList, 1, 5);
    myDoubleLinkListForeach(myList);
    // 头删
    printf("头删1个\n");
    myDoubleLinkListDelHead(myList);
    myDoubleLinkListForeach(myList);
    // 尾删 有BUG
    printf("尾删1个\n");
    myDoubleLinkListDelTail(myList);
    myDoubleLinkListForeach(myList);
    // 逆序输出
    printf("逆序输出\n");
    myDoubleLinkListReversePirnt(myList);
    // 指定位置删
    printf("指定位置删\n");
    myDoubleLinkListDelAppointPos(myList, 4);
    myDoubleLinkListForeach(myList);
    // 指定数据删
    printf("删除所有4\n");
    myDoubleLinkListDelAppointVal(myList, 4);
    myDoubleLinkListForeach(myList);
    
   /* todo */
    myDoubleLinkListDestroy(myList);

    JUDGE_IFDESTROY(myList->head);


#else 
    myDoubleLinkListInit(&myList, compareFuncStuInfo, printFuncStuInfo);
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
        myDoubleLinkListInsertHead(myList, (void *)&buffer[idx]);
    }

    /* 获取链表的长度 */
    int size = 0;
    myDoubleLinkListGetLength(myList, &size);
    printf("size:%d\n", size);

    /* 遍历 */
    myDoubleLinkListForeach(myList);


    printf("头插3个STU4\n");//
    myDoubleLinkListInsertHead(myList, (void *)&stu4);
    myDoubleLinkListInsertHead(myList, (void *)&stu4);
    myDoubleLinkListInsertHead(myList, (void *)&stu4);
    myDoubleLinkListForeach(myList);

    printf("尾插3个SU4\n");//
    myDoubleLinkListInsertTail(myList, (void *)&stu4);
    myDoubleLinkListInsertTail(myList, (void *)&stu4);
    myDoubleLinkListInsertTail(myList, (void *)&stu4);
    myDoubleLinkListForeach(myList);

    printf("头删2个\n");//
    myDoubleLinkListDelHead(myList);
    myDoubleLinkListDelHead(myList);
    myDoubleLinkListForeach(myList);
    
    printf("尾删2个\n");//
    myDoubleLinkListDelTail(myList);
    myDoubleLinkListDelTail(myList);
    myDoubleLinkListForeach(myList);
    
    printf("指定位置【位置为2】删\n");//
    myDoubleLinkListDelAppointPos(myList, 2);
    myDoubleLinkListForeach(myList);
    
    printf("指定数据删【stu4=stu2】\n");//
    int pos;
    myDoubleLinkListDelAppointVal(myList, (void *)&stu4);
    myDoubleLinkListForeach(myList);

    /* 删除链表 */
    myDoubleLinkListDestroy(myList);

    JUDGE_IFDESTROY(myList->head);

#endif

    return 0;
}