
#include "binarySearchTree.h"
#include "doubleLinkListQueue.h"
#include "common.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>





/* =======静态函数前置======= */
/* 封装结点 */
static BSTreeNode * creatBinarySearchNode(BSTreeNode *parent, ELEMENTTYPE val);
/* 比较函数 */
int compareFunc(ELEMENTYPE val1, ELEMENTYPE val2);
/* 自定义输出 */
int printFunc(ELEMENTYPE val);
/* 根据指定值获取二叉搜索树的结点todo */
static BSTreeNode * baseAppointValGetBSTreeNode(BSTreeList *pBstree, ELEMENTTYPE val);
/* 判断二叉搜索树的度为2todo */
static int binarySearchTreeNodeHasTwoChildens(BSTreeNode *node);
/* 判断二叉搜索树的度为1todo */
static int binarySearchTreeNodeHasOneChilden(BSTreeNode *node);
/* 判断二叉搜索树的度为0todo */
static int binarySearchTreeNodeIsLeaf(BSTreeNode *node);
/* 前序遍历 */
static int preOrderTravel(BSTreeList *pBstree, BSTreeNode *node);
/* 中序遍历 */
static int inOrderTravel(BSTreeList *pBstree, BSTreeNode *node);
/* 后续遍历 */
static int postOrderTravel(BSTreeList *pBstree, BSTreeNode *node);
/* 获取前驱结点todo */
static BSTreeNode * bstreeNodePreDecessor(BSTreeNode *node);
/* 获取后继结点todo */
static BSTreeNode * bstreeNodeSuccessor(BSTreeNode *node);




/* =======静态函数声明======= */
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
/* 根据指定值获取二叉搜索树的结点todo */
static BSTreeNode * baseAppointValGetBSTreeNode(BSTreeList *pBstree, ELEMENTTYPE val);
/* 判断二叉搜索树的度为2todo */
static int binarySearchTreeNodeHasTwoChildens(BSTreeNode *node);
/* 判断二叉搜索树的度为1todo */
static int binarySearchTreeNodeHasOneChilden(BSTreeNode *node);
/* 判断二叉搜索树的度为0todo */
static int binarySearchTreeNodeIsLeaf(BSTreeNode *node);
/* 获取前驱结点todo */
static BSTreeNode * bstreeNodePreDecessor(BSTreeNode *node);
/* 获取后继结点todo */
static BSTreeNode * bstreeNodeSuccessor(BSTreeNode *node);



/* =======接口函数======= */
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
int binarySearchTreeAppointValIsExist(BSTreeList *pBSTree, ELEMENTYPE val)
{

}



/* 前序遍历 */
static int preOrderTravel(BSTreeList *pBstree, BSTreeNode *node)
{
    JUDGE_NULL_PTR(node);
    pBstree->printFunc(node->data);
    preOrderTravel(pBstree, node->left);
    preOrderTravel(pBstree, node->right);
    return ON_SUCCESS;
}
int binarySearchTreePreOrderTravel(BSTreeList *pBSTree)
{
    JUDGE_NULL_PTR(pBSTree);
    preOrderTravel(pBSTree, pBSTree->root);
    return ON_SUCCESS;
}

/* 中序遍历 */
static int inOrderTravel(BSTreeList *pBstree, BSTreeNode *node)
{
    JUDGE_NULL_PTR(node);
    inOrderTravel(pBstree, node->left);
    pBstree->printFunc(node->data);
    inOrderTravel(pBstree, node->right);
    return ON_SUCCESS;
}
int binarySearchTreeInOrderTravel(BSTreeList *pBSTree)
{
    JUDGE_NULL_PTR(pBSTree);
    inOrderTravel(pBSTree, pBSTree->root);
    return ON_SUCCESS;
}

/* 后续遍历 */
static int postOrderTravel(BSTreeList *pBstree, BSTreeNode *node)
{
    JUDGE_NULL_PTR(node);
    postOrderTravel(pBstree, node->left);
    postOrderTravel(pBstree, node->right);
    pBstree->printFunc(node->data);
    return ON_SUCCESS;
}
int binarySearchTreePostOrderTravel(BSTreeList *pBSTree)
{
    JUDGE_NULL_PTR(pBSTree);
    postOrderTravel(pBSTree, pBSTree->root);
    return ON_SUCCESS;
}

/* 层序遍历 */
int binarySearchTreeLevelOrderTravel(BSTreeList *pBSTree)
{
    JUDGE_NULL_PTR(pBSTree);
    DoubleLinkListQueue * tmpQueue = (DoubleLinkListQueue *)malloc(sizeof(DoubleLinkListQueue) * 1);
    BSTreeNode * tmpNode;
    doubleLinkListQueueInit(&tmpQueue);
    doubleLinkListQueuePush(tmpQueue, pBSTree->root);
    while (!doubleLinkListQueueIsEmpty(tmpQueue))
    {
        doubleLinkListQueueTop(tmpQueue, tmpNode);
        doubleLinkListQueuePop(tmpQueue);
        pBSTree->printFunc(tmpNode->data);
        if (tmpNode->left != NULL)
        {
            doubleLinkListQueuePush(tmpQueue, tmpNode->left);    
        }
        if (tmpNode->right != NULL)
        {
            doubleLinkListQueuePush(tmpQueue, tmpNode->right);    
        }
    }
    return ON_SUCCESS;
}

/* 获取结点总数todo */
int binarySearchTreeGetSize(BSTreeList *pBSTree, int *pSize)
{
    JUDGE_NULL_PTR(pBSTree);
    JUDGE_NULL_PTR(pSize);
    *pSize = pBSTree->size;
    return *pSize;
}

/* 获取树的高度todo */
int binarySearchTreeGetHeigth(BSTreeList *pBSTree, int *pHeight)
{
    JUDGE_NULL_PTR(pBSTree);
    DoubleLinkListQueue * tmpQueue = (DoubleLinkListQueue *)malloc(sizeof(DoubleLinkListQueue) * 1);
    BSTreeNode * tmpNode;
    doubleLinkListQueueInit(&tmpQueue);
    doubleLinkListQueuePush(tmpQueue, pBSTree->root);
    int length = 1;
    int count = 0;
    int height = 0;
    while (!doubleLinkListQueueIsEmpty(tmpQueue))
    {
        doubleLinkListQueueTop(tmpQueue, tmpNode);
        doubleLinkListQueuePop(tmpQueue);
        // pBSTree->printFunc(tmpNode->data);
        if (tmpNode->left != NULL)
        {
            doubleLinkListQueuePush(tmpQueue, tmpNode->left);    
            count++;
        }
        if (tmpNode->right != NULL)
        {
            doubleLinkListQueuePush(tmpQueue, tmpNode->right);    
            count++;
        }
        length--;
        if (length == 0)
        {
            height++;
            length = count;
            count = 0;
        }
    }
    return height;
}

/* 结点删除--HARD */
int binarySearchTreeDelAppointVal(BSTreeList *pBSTree, ELEMENTYPE val);

/* 二叉树的销毁--队列删除 */
int binarySearchTreeDestroy(BSTreeList *pBSTree);


