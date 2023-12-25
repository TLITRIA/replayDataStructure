#include "binarySearchTree.h"
#include "common.h"
#include <stdio.h>

enum STATUS_CODE
{
    MALLOC_ERR,
    ON_SUCCESS,
};

#define JUDGE_MALLOC(p)\
if (NULL == p)\
    return MALLOC_ERR;\

/* 二叉搜索树的初始化 */
int binarySearchTreeInit(BinarySearchTree **pBstree)
{

    BinarySearchTree * bstree = (BinarySearchTree *)malloc(sizeof(BinarySearchTree) * 1);
    JUDGE_MALLOC(bstree);
    memset(bstree, 0, sizeof(BinarySearchTree) * 1);


    {
        bstree->root = NULL;
        bstree->size = 0;
    }

    #if 1
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
    *pBstree = bstree;
    return ON_SUCCESS;
}

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

    /* todo */
    /* 确定符号：放在左边还是右边 */
    int cmp = 0;
    while (travelNode != NULL)
    {
        parentNode = travelNode;
        // cmp = val - travelNode->data;
        cmp = compareFunc(val, travelNode->data);
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
    BSTTreeNode *newBstNode = (BSTTreeNode *)malloc(sizeof(BSTTreeNode) * 1);
    JUDGE_MALLOC(newBstNode);
    memset(newBstNode, 0, sizeof(BSTTreeNode) * 1);
    {
        newBstNode->data = 0;
        newBstNode->left = NULL;
        newBstNode->right = NULL;
        newBstNode->parent = NULL;
    }

    /* 新结点赋值 */
    newBstNode->data = val;

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
