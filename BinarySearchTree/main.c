#include <stdio.h>
#include <string.h>
#include "binarySearchTree.h"
#include "common.h"

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
    printf("%d ", val);
    return ON_SUCCESS;
}

int nodeData(void *arg)
{
    BSTreeNode node = *(BSTreeNode *)arg;
}


int main()
{
    #if 0
    BinarySearchTree *tree = NULL;
    binarySearchTreeInit(&tree, compareFuncstuInfo, printFuncstuInfo);
    

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


#if 1
    /* 初始化二叉树 */
    BinarySearchTree *BST;
    binarySearchTreeInit(&BST, compareBasicDataFunc, printBasicData);
    /* 初始化数据 */
    int buffer[] = {50, 23, 12, 33, 56, 70, 52, 64};
    int len = sizeof(buffer) / sizeof(buffer[0]);
    printf("len:%d\n", len);
    for (int idx = 0; idx < len; idx++)    
    {
        binarySearchTreeInsert(BST, (void *)&buffer[idx]);
    }


    PRINT_BOUNDARY;
    /* 获取二叉搜索树的结点个数 */
    int size = 0;
    binarySearchTreeGetNodeSize(BST, &size);
    printf("二叉搜索树结点个数size:%d\n", size);

    PRINT_BOUNDARY;
    /* 获取二叉搜索树的高度 */
    int height = 0;
    binarySearchTreeGetHeight(BST, &height);
    printf("二叉搜索树的高度height:%d\n", height);


    PRINT_BOUNDARY;
    // printf("中序遍历\n");
    // binarySearchTreeInOrderTravel(BST);
    // printf("\n");
    // printf("前序遍历\n");/* finished函数调用错误 */
    // binarySearchTreePreOrderTravel(BST);
    // printf("\n");
    // printf("后序遍历\n");/* finished函数调用错误 */
    // binarySearchTreePostOrderTravel(BST);
    // printf("\n");
    printf("层序遍历\n");
    binarySearchTreeLevelOrderTravel(BST);
    printf("\n");

    PRINT_BOUNDARY;
    /* 删除度为2 */
    int delVal = 23;
    printf("删除23\n");
    binarySearchTreeDelete(BST, &delVal);
    binarySearchTreePreOrderTravel(BST);        // 前序遍历
    printf("\n");
    binarySearchTreeGetNodeSize(BST, &size);
    printf("size:%d\n", size);
    binarySearchTreeGetHeight(BST, &height);
    printf("height:%d\n", height);

    PRINT_BOUNDARY;
    /* 删除度为1 */
    delVal = 70;
    printf("删除70\n");
    binarySearchTreeDelete(BST, &delVal);
    binarySearchTreePreOrderTravel(BST);        // 前序遍历
    printf("\n");
    binarySearchTreeGetNodeSize(BST, &size);
    printf("size:%d\n", size);
    binarySearchTreeGetHeight(BST, &height);
    printf("height:%d\n", height);

    PRINT_BOUNDARY;
    /* 删除度为0 */
    delVal = 52;
    printf("删除52\n");
    binarySearchTreeDelete(BST, &delVal);
    binarySearchTreePreOrderTravel(BST);        // 前序遍历
    printf("\n");
    binarySearchTreeGetNodeSize(BST, &size);
    printf("size:%d\n", size);
    binarySearchTreeGetHeight(BST, &height);
    printf("height:%d\n", height);

    // printf("中序遍历\n");
    // binarySearchTreeInOrderTravel(BST);
    // printf("\n");
    // printf("前序遍历\n");/* finished函数调用错误 */
    // binarySearchTreePreOrderTravel(BST);
    // printf("\n");
    // printf("后序遍历\n");/* finished函数调用错误 */
    // binarySearchTreePostOrderTravel(BST);
    // printf("\n");
    printf("层序遍历\n");
    binarySearchTreeLevelOrderTravel(BST);
    printf("\n");
#endif

    // printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    // printf("1111\n");






    return 0;
}