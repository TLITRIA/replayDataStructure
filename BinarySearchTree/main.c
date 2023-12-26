#include <stdio.h>
#include <string.h>
#include "binarySearchTree.h"


#define DEFAULT_SIZE 10

typedef struct stuInfo
{
    int age;
    char sex;
} stuInfo;






/* 自定义int函数 */
int printFuncInt(int arg)
{
    printf("info:%d\n", arg);
}
int compareFuncInt(int arg1, int arg2)
{
    return (arg1 == arg2) ? 1 : 0;
}
/*  */
int printFuncStuInfo(void *arg)
{
    stuInfo *info = (stuInfo *)arg;
    printf("age:%d\tsex:%c\n", info->age, info->sex);
}
int compareFuncStuInfo(void *arg1, void *arg2)
{
    stuInfo *info1 = (stuInfo *)arg1;
    stuInfo *info2 = (stuInfo *)arg2;
    return (info1->age == info2->age && info1->sex == info2->sex) ? 1 : 0;
}





int main()
{
    BinarySearchTree *tree = NULL;
    binarySearchTreeInit(&tree, compareFuncInt, printFuncInt);
    /* 插入 */
    int buffer[DEFAULT_SIZE] = {7, 4, 5, 6, 1, 8, 9};
    
    for (int idx = 0; idx < 7; idx++)
    {
        binarySearchTreeInsert(tree, buffer[idx]);
    }
    

    printf("root.data:%d\n", tree->root->data);

    /* 层序遍历 */
    binarySearchTreeLevelOrderTravel(tree);













    return 0;
}