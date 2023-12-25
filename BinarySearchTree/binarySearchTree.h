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
int binarySearchTreeInsert(BinarySearchTree *pBstree, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2));

/* 二叉搜索树的前序遍历 */
int binarySearchTreePreOrderTravel(BinarySearchTree *pBstree);

/* 二叉搜索树的中序遍历 */
int binarySearchTreeInOrderTravel(BinarySearchTree *pBstree);

/* 二叉搜索树的后序遍历 */
int binarySearchTreePostOrderTravel(BinarySearchTree *pBstree);

/* 二叉搜索树的层序遍历 */
int binarySearchTreeLevelOrderTravel(BinarySearchTree *pBstree);




#endif //_BINARY_SEARCH_TREE_H_