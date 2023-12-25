#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#define ELEMENTTYPE int

typedef struct BSTTreeNode
{
    ELEMENTTYPE data;
    struct BSTTreeNode *left;   /* 左子树 */
    struct BSTTreeNode *right;  /* 右子树 */

    #if 1
    struct BSTTreeNode *parent; /* 父节点 */
    #else
    #endif
    
} BSTTreeNode;

typedef struct BinarySearchTree
{
    /* 根节点 */
    BSTTreeNode *root;
    /* 树结点个数 */
    int size;
} BinarySearchTree;


/* 二叉搜索树的初始化 */
int binarySearchTreeInit(BinarySearchTree **pBstree);

/* 二叉搜索树的插入 */
int binarySearchTreeInsert(BinarySearchTree *pBstree, ELEMENTTYPE val);


#endif //_BINARY_SEARCH_TREE_H_