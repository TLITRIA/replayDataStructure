#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_
#include "common.h"



typedef struct AVLTreeNode
{
    ELEMENTTYPE data;
    int height;                 /* 结点维护高度属性 */
    struct AVLTreeNode *left;   /* 左子树 */
    struct AVLTreeNode *right;  /* 右子树 */
    struct AVLTreeNode *parent; /* 父节点 */
} AVLTreeNode;

typedef struct BalanceBinarySearchTree
{
   
    AVLTreeNode *root;                                          /* 根节点 */ 
    int size;                                                   /* 树结点个数 */
    int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2);     /* 钩子 比较器（把比较器放入结构体内部） */
    int (*printFunc)(ELEMENTTYPE val);                          /* 钩子函数 包装器实现自定义打印函数接口 */
    
    // DoubleLinkListQueue *pQueue;/* 优化todo 把队列的属性放入队列 */
} BalanceBinarySearchTree;


/* 二叉搜索树的初始化√ */
int balanceBinarySearchTreeInit(BalanceBinarySearchTree **pBstree, 
            int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), 
            int printFunc(ELEMENTTYPE val));

/* 二叉搜索树的插入 */
int balanceBinarySearchTreeInsert(BalanceBinarySearchTree *pBstree, ELEMENTTYPE val);

/* 二叉搜索树是否包含指定的元素 */
int balanceBinarySearchTreeIsContainAppointVal(BalanceBinarySearchTree *pBstree, ELEMENTTYPE val);

/* 二叉搜索树的前序遍历 */
int balanceBinarySearchTreePreOrderTravel(BalanceBinarySearchTree *pBstree);

/* 二叉搜索树的中序遍历 */
int balanceBinarySearchTreeInOrderTravel(BalanceBinarySearchTree *pBstree);

/* 二叉搜索树的后序遍历 */
int balanceBinarySearchTreePostOrderTravel(BalanceBinarySearchTree *pBstree);

/* 二叉搜索树的层序遍历 */
int balanceBinarySearchTreeLevelOrderTravel(BalanceBinarySearchTree *pBstree);

/* 获取二叉搜索树的结点个数 */
int balanceBinarySearchTreeGetNodeSize(BalanceBinarySearchTree *pBstree, int *pSize);

/* 获取二叉搜索树的高度 */
int balanceBinarySearchTreeGetHeight(BalanceBinarySearchTree *pBstree, int *pHeight);

/* 二叉搜索树的删除 */
int balanceBinarySearchTreeDelete(BalanceBinarySearchTree *pBstree, ELEMENTTYPE val);

/* 二叉搜索树的销毁 */
int balanceBinarySearchTreeDestory(BalanceBinarySearchTree *pBstree);

/* 判断二叉搜索树是否是完全二叉树 */
// int balanceBinarySearchTreeIsComplete(BalanceBinarySearchTree *pBstree);
#endif //_BINARY_SEARCH_TREE_H_