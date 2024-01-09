
#include "binarySearchTree.h"
#include "common.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>





/* 静态函数前置 */
/**/
static BSTreeNode * creatBinarySearchNode(BSTreeNode *parent, ELEMENTTYPE val);

int compareFunc(ELEMENTYPE val1, ELEMENTYPE val2);

int printFunc(ELEMENTYPE val);
    

/* 静态函数声明 */
static BSTreeNode * creatBinarySearchNode(BSTreeNode *parent, ELEMENTTYPE val)
{
    BSTreeNode* newNode = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    JUDGE_MALLOC_ERROR(newNode);
    memset(newNode, 0, sizeof(newNode));

    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = parent;

    return newNode;
}





/* 二叉树初始化 */
int binarySearchTreeInit(BSTreeList **pBSTree, 
                        int (compareFunc)(ELEMENTYPE val1, ELEMENTYPE val2),
                        int (printFunc)(ELEMENTYPE val))
{
    JUDGE_NULL_PTR(pBSTree);
    
    BSTreeList *newList = (BSTreeList *)malloc(sizeof(BSTreeList) * 1);
    JUDGE_MALLOC_ERROR(newList);
    memset(newList, 0, sizeof(newList));

    newList->root = creatBinarySearchNode(NULL, NULL);
    JUDGE_NULL_PTR(newList->root);
    newList->size = 0;
    newList->compareFunc = compareFunc;
    newList->printFunc = printFunc;

    *pBSTree = newList;

    return ON_SUCCESS;
}



/* 树的插入--指定数据 */
int binarySearchTreeInsertAppointVal(BSTreeList *pBSTree, ELEMENTYPE val);


/* 询问树是否包含指定元素 */
int binarySearchTreeAppointValIsExist(BSTreeList *pBSTree, ELEMENTYPE val);


/* 中序遍历 */
int binarySearchTreeInOrderTravel(BSTreeList *pBSTree);

/* 前序遍历 */
int binarySearchTreePreOrderTravel(BSTreeList *pBSTree);

/* 后续遍历 */
int binarySearchTreePostOrderTravel(BSTreeList *pBSTree);

/* 层序遍历 */
int binarySearchTreeLevelOrderTravel(BSTreeList *pBSTree);

/* 获取结点总数 */
int binarySearchTreeGetSize(BSTreeList *pBSTree, int *pSize);

/* 获取树的高度 */
int binarySearchTreeGetHeigth(BSTreeList *pBSTree, int *pHeight);

/* 结点删除 */
int binarySearchTreeDelAppointVal(BSTreeList *pBSTree, ELEMENTYPE val);

/* 二叉树的销毁 */
int binarySearchTreeDestroy(BSTreeList *pBSTree);


