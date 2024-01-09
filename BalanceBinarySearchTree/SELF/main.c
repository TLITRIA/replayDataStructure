#include <stdio.h>
#include <string.h>
#include "balanceBinarySearchTree.h"

#define DEFAULT_SIZE 10

typedef struct stuInfo
{
    int age;
    char sex;
} stuInfo;


int printFuncstuInfo(void *arg)
{
    stuInfo *info = (stuInfo *)arg;
    printf("age:%d\tsex:%c\n", info->age, info->sex);/* todo */
}

int compareFuncstuInfo(void *arg1, void *arg2)
{
    stuInfo *info1 = (stuInfo *)arg1;
    stuInfo *info2 = (stuInfo *)arg2;
    return (info1->age == info2->age && info1->sex == info2->sex) ? 1 : 0;
}

int compareBasicDataFunc(void *arg1, void *arg2)
{
    int val1 = *(int *)arg1;
    int val2 = *(int *)arg2;
    return val1 - val2;
}

int printBasicData(void *arg)
{
    int val = *(int *)arg;
    printf("data:%d\t", val);
    return ON_SUCCESS;
}


int main()
{
    #if 0
    BalanceBinarySearchTree *tree = NULL;
    balanceBinarySearchTreeInit(&tree, compareFuncstuInfo, printFuncstuInfo);
    

    stuInfo stu1, stu2, stu3, stu4, stu5;
    stu1.age = 20;
    stu1.sex = 'f';
    stu2.age = 20;
    stu2.sex = 'f';
    stu3.age = 20;
    stu3.sex = 'f';
    stu4.age = 20;
    stu4.sex = 'f';
    stu5.age = 20;
    stu5.sex = 'f';
    
    stuInfo buffer[DEFAULT_SIZE] = {};
    
    #endif


    /*  */
    BalanceBinarySearchTree *BST;
    balanceBinarySearchTreeInit(&BST, compareBasicDataFunc, printBasicData);

    // int buffer[DEFAULT_SIZE] = {56, 28, 75, 73, 77, 13, 7, 26, 100, 12};
    int buffer[] = {11, 22, 33};
    int size = 0;
    int height = 0;
    for (int idx = 0; idx < 3; idx++)
    {
        balanceBinarySearchTreeInsert(BST, (void *)&buffer[idx]);
        /* 获取二叉搜索树的结点个数 */
        balanceBinarySearchTreeGetNodeSize(BST, &size);
        printf("size:%d\n", size);
        /* 获取二叉搜索树的高度 */
        balanceBinarySearchTreeGetHeight(BST, &height);
        printf("height:%d\n", height);
    }

#if 0
    /* 中序遍历 */
    balanceBinarySearchTreeInOrderTravel(BST);
    printf("\n");

    /* 层序遍历 */
    balanceBinarySearchTreeLevelOrderTravel(BST);
    printf("\n");

    /* 删除度为2 */
    int delVal = 56;
    balanceBinarySearchTreeDelete(BST, &delVal);
    balanceBinarySearchTreeLevelOrderTravel(BST);
    printf("\n");
    balanceBinarySearchTreeGetNodeSize(BST, &size);
    printf("size:%d\n", size);
    balanceBinarySearchTreeGetHeight(BST, &height);
    printf("height:%d\n", height);

    /* 删除度为1 */
    delVal = 7;
    balanceBinarySearchTreeDelete(BST, &delVal);
    balanceBinarySearchTreeLevelOrderTravel(BST);
    printf("\n");
    balanceBinarySearchTreeGetNodeSize(BST, &size);
    printf("size:%d\n", size);
    balanceBinarySearchTreeGetHeight(BST, &height);
    printf("height:%d\n", height);

    /* 删除度为0 */
    delVal = 12;
    balanceBinarySearchTreeDelete(BST, &delVal);
    balanceBinarySearchTreeLevelOrderTravel(BST);
    printf("\n");
    balanceBinarySearchTreeGetNodeSize(BST, &size);
    printf("size:%d\n", size);
    balanceBinarySearchTreeGetHeight(BST, &height);
    printf("height:%d\n", height);
#endif
    return 0;
}