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

/* 二叉搜索树的插入 */
int binarySearchTreeInsert(BinarySearchTree *pBstree, ELEMENTTYPE val)
{

    int ret = 0;
    
    return ret;
}
