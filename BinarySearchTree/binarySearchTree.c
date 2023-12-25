#include "binarySearchTree.h"
#include "common.h"
#include <stdio.h>

enum STATUS_CODE
{
    MALLOC_ERR,
    ON_SUCCESS,
};

/* 静态函数前置声明 */
static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2);
    /* 创建结点 */
static BSTTreeNode * createBSTreeNewNode(ELEMENTTYPE val, BSTTreeNode * parentNode);
    /* 根据指定是值获取二叉搜索树的结点 */
static BSTTreeNode * baseAppointValGetBSTreeNode(BinarySearchTree *pBstree, ELEMENTTYPE val);

#define JUDGE_MALLOC(p) \
if (NULL == p)          \
    return MALLOC_ERR;  \

static BSTTreeNode * createBSTreeNewNode(ELEMENTTYPE val, BSTTreeNode * parentNode)
{
    /* 分配根节点 */
    BSTTreeNode *newBstNode = (BSTTreeNode *)malloc(sizeof(BSTTreeNode) * 1);
    memset(newBstNode, 0, sizeof(BSTTreeNode) * 1);
    {
        newBstNode->data = 0;/* 新结点赋值 */
        newBstNode->left = NULL;
        newBstNode->right = NULL;
        newBstNode->parent = NULL;
    }
    newBstNode->data = val;
    newBstNode->parent = parentNode;
    return newBstNode;
}

/* 二叉搜索树的初始化 */
int binarySearchTreeInit(BinarySearchTree **pBstree, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2))
{
    BinarySearchTree * bstree = (BinarySearchTree *)malloc(sizeof(BinarySearchTree) * 1);
    JUDGE_MALLOC(bstree);
    memset(bstree, 0, sizeof(BinarySearchTree) * 1);
    {
        bstree->root = NULL;
        bstree->size = 0;
        bstree->compareFunc = compareFunc;
    }
#if 0
    /* 分配根节点 */
    bstree->root = (BSTTreeNode *)malloc(sizeof(BSTTreeNode) * 1);
    JUDGE_MALLOC(bstree->root);
    memset(bstree->root, 0, sizeof(BSTTreeNode) * 1); 
    {
        bstree->root->data = 0;
        bstree->root->left = NULL;
        bstree->root->right = NULL;
        bstree->root->parent = NULL;
    }
#endif
    bstree->root = createBSTreeNewNode(0, NULL);
    JUDGE_MALLOC(bstree->root);
    *pBstree = bstree;
    return ON_SUCCESS;
}

#if 0
static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2)
{
#if 0
    if (val1 < val2)
    {
        return -1;
    }
    else if (val1 > val2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
#else
    return val1 - val2;
#endif
}
#endif

/* 二叉搜索树的插入 */
int binarySearchTreeInsert(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    if (pBstree->size == 0)
    {
        (pBstree->size)++;
        pBstree->root->data = val;
    }
    
    /* travelNode指向根节点 */
    BSTTreeNode *travelNode = pBstree->root;
    BSTTreeNode *parentNode = pBstree->root;

    /* 确定符号：放在左边还是右边 */
    int cmp = 0;
    while (travelNode != NULL)
    {
        parentNode = travelNode;
        // cmp = val - travelNode->data;
        cmp = pBstree->compareFunc(val, travelNode->data);
        /* 插入元素 < 遍历到的结点 */
        if (cmp < 0)
        {
            travelNode = travelNode->left;
        }
        else if (cmp > 0)
        {
            travelNode = travelNode->right;
        }
        else
        {
            /* 覆盖或返回 */
            return ON_SUCCESS;
        }
        
    }

    /* 分配根节点 */
#if 0
    BSTTreeNode *newBstNode = (BSTTreeNode *)malloc(sizeof(BSTTreeNode) * 1);
    JUDGE_MALLOC(newBstNode);
    memset(newBstNode, 0, sizeof(BSTTreeNode) * 1);
    {
        newBstNode->data = val;
        newBstNode->left = NULL;
        newBstNode->right = NULL;
        newBstNode->parent = parentNode;
    }
#else
    BSTTreeNode *newBstNode = createBSTreeNewNode(val, parentNode);
    JUDGE_MALLOC(newBstNode);
#endif

    if (cmp < 0)
    {
        parentNode->left = newBstNode;
    }
    else if (cmp > 0)
    {
        parentNode->right = newBstNode;
    }
    (pBstree->size)++;
    return ON_SUCCESS;
}


/* 二叉搜索树的前序遍历 */
int binarySearchTreePreOrderTravel(BinarySearchTree *pBstree)
{

}

/* 二叉搜索树的中序遍历 */
int binarySearchTreeInOrderTravel(BinarySearchTree *pBstree)
{

}

/* 二叉搜索树的后序遍历 */
int binarySearchTreePostOrderTravel(BinarySearchTree *pBstree)
{

}

/* 二叉搜索树的层序遍历 */
int binarySearchTreeLevelOrderTravel(BinarySearchTree *pBstree)
{

}

static BSTTreeNode * baseAppointValGetBSTreeNode(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    int cmp = 0;
    BSTTreeNode * travelNode = pBstree->root;
    while (travelNode != NULL)
    {
        cmp = pBstree->compareFunc(val, travelNode->data);

        if (cmp < 0)
        {
            travelNode = travelNode->left;
        }
        else if (cmp > 0)
        {
            travelNode = travelNode->right;
        }
        else
        {
            /* 找到 */
            return travelNode;
        }


    }
    return NULL;
    
}
/*  */
int binarySearchTreeIsContainAppointVal(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    baseAppointValGetBSTreeNode(pBstree, val);
}