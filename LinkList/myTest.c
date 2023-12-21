#include <stdio.h>
#include "myLinkList.h"

#define BUFFER_SIZE 3

#define PRINT_INT(num)          \
printf("%s:%d\n", #num, num);   \

#define JUDGE_IFDESTROY(p)      \
if (NULL == p)                  \
    printf("链表已销毁\n");      \
else                            \
    printf("链表未销毁\n");      \

int main()
{
#if 0
    //初始化
    LinkList *myList = NULL;
    myLinkListInit(&myList);
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
    printf("头插\n");//√
    myLinkListInsertHead(myList, 2);
    myLinkListInsertHead(myList, 2);
    myLinkListInsertHead(myList, 2);
    myLinkListForeach(myList);

    printf("尾插\n");//√
    myLinkListInsertTail(myList, 5);
    myLinkListInsertTail(myList, 5);
    myLinkListInsertTail(myList, 5);
    myLinkListForeach(myList);
    

    /**插入数据中
     * 
      */


    /** 头删失效 
     * 参数错误，已解决 
     * */
    printf("头删\n");//√
    myLinkListDelHead(myList);
    myLinkListDelHead(myList);
    myLinkListForeach(myList);
    
    printf("尾删\n");//√
    myLinkListDelTail(myList);
    myLinkListDelTail(myList);
    myLinkListForeach(myList);
    
    printf("指定位置删\n");//头、尾、中？
    myLinkListDelAppointPos(myList, 2);
    myLinkListForeach(myList);
    
    printf("指定数据删\n");//√
    myLinkListDelAppointVal(myList, 2);
    myLinkListForeach(myList);
    




    /**删除链表出现错误，因为调用了head
     * 没能删掉链表，因为判断已销毁的条件是头结点为NULL
    */
    myLinkListDestroy(myList);

    JUDGE_IFDESTROY(myList->head);
#endif 

#if 1




#endif

    return 0;
}