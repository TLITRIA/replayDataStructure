#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_



#include "common.h"


typedef struct BSTreeNode
{
    ELEMENTTYPE data;
    struct BSTreeNode *left;   /* 左子树 */
    struct BSTreeNode *right;  /* 右子树 */
    struct BSTreeNode *parent; /* 父节点 */
} BSTreeNode;

typedef struct BinarySearchTree
{    
    BSTreeNode *root;           /* 根节点 */
    int size;                   /* 树结点个数 */
    
    int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2); /* 钩子 比较器（把比较器放入结构体内部） */
    int (*printFunc)(ELEMENTTYPE val);              /* 钩子函数 包装器实现自定义打印函数接口 */
    
    // DoubleLinkListQueue *pQueue;             /* 优化todo 把队列的属性放入队列 */
} BinarySearchTree;


/* 二叉搜索树的初始化 */
int binarySearchTreeInit(BinarySearchTree **pBstree, 
            int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), 
            int printFunc(ELEMENTTYPE val));

/* 二叉搜索树的插入 */
int binarySearchTreeInsert(BinarySearchTree *pBstree, ELEMENTTYPE val);

/* 二叉搜索树是否包含指定的元素 */
int binarySearchTreeIsContainAppointVal(BinarySearchTree *pBstree, ELEMENTTYPE val);

/* 二叉搜索树的前序遍历 */
int binarySearchTreePreOrderTravel(BinarySearchTree *pBstree);

/* 二叉搜索树的中序遍历 */
int binarySearchTreeInOrderTravel(BinarySearchTree *pBstree);

/* 二叉搜索树的后序遍历 */
int binarySearchTreePostOrderTravel(BinarySearchTree *pBstree);

/* 二叉搜索树的层序遍历 */
int binarySearchTreeLevelOrderTravel(BinarySearchTree *pBstree);

/* 获取二叉搜索树的结点个数 */
int binarySearchTreeGetNodeSize(BinarySearchTree *pBstree, int *pSize);

/* 获取二叉搜索树的高度 */
int binarySearchTreeGetHeight(BinarySearchTree *pBstree, int *pHeight);

/* 二叉搜索树的删除 */
int binarySearchTreeDelete(BinarySearchTree *pBstree, ELEMENTTYPE val);

/* 二叉搜索树的销毁 */
int binarySearchTreeDestory(BinarySearchTree *pBstree);

/* 二叉树打印树形 */
int binarySearchTreePrintStructure(BinarySearchTree *pBstree);



#endif //_BINARY_SEARCH_TREE_H_