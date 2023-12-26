#include "binarySearchTree.h"
#include "doubleLinkListQueue.h"
#include "common.h"
#include <stdio.h>

// enum STATUS_CODE
// {
//     MALLOC_ERR,
//     ON_SUCCESS,
// };



/* ==================静态函数前置声明=============== */

/* 两个值比较大小 */
static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2);
/* 自定义输出 */
static int printFunc(ELEMENTTYPE val);
/* 创建结点 */
static BSTreeNode * createBSTreeNewNode(ELEMENTTYPE val, BSTreeNode * parentNode);
/* 根据指定是值获取二叉搜索树的结点 */
static BSTreeNode * baseAppointValGetBSTreeNode(BinarySearchTree *pBstree, ELEMENTTYPE val);

static BSTreeNode * createBSTreeNewNode(ELEMENTTYPE val, BSTreeNode * parentNode);

static int binarySearchTreeNodeHasTwoChildens(BSTreeNode *node);

static int binarySearchTreeNodeHasOneChilden(BSTreeNode *node);

static int binarySearchTreeNodeIsLeaf(BSTreeNode *node);

static BSTreeNode * bstreeNodePreDecessor(BSTreeNode *node);

static BSTreeNode * bstreeNodeSuccessor(BSTreeNode *node);


static BSTreeNode * createBSTreeNewNode(ELEMENTTYPE val, BSTreeNode * parentNode)
{
    /* 分配根节点 */
    BSTreeNode *newBstNode = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    memset(newBstNode, 0, sizeof(BSTreeNode) * 1);
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

/* 判断二叉搜索树的结点度为2 */
static int binarySearchTreeNodeHasTwoChildens(BSTreeNode *node)
{
    return (node->left != NULL && node->right != NULL);
}

/* 判断二叉搜索树的结点度为1 */
static int binarySearchTreeNodeHasOneChilden(BSTreeNode *node)
{
    return ((node->left != NULL && node->right == NULL) || \
            (node->left == NULL && node->right != NULL));
}

/* 判断二叉搜索树的结点度为0 */
static int binarySearchTreeNodeIsLeaf(BSTreeNode *node)
{
    return (node->left == NULL && node->right == NULL);
}

static int preOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node);
static int inOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node);
static int postOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node);

/* 获取当前结点的前驱结点 */
static BSTreeNode * bstreeNodePreDecessor(BSTreeNode *node)
{
    if (binarySearchTreeNodeHasTwoChildens(node))
    {
        BSTreeNode *travelNode = node->left;
        while (travelNode->right != NULL)
        {
            travelNode = travelNode->right;
        }
        return travelNode;
    }

    /* 剩下度为1、度为0 */
}

/* 获取当前结点的后继结点 */
static BSTreeNode * bstreeNodeSuccessor(BSTreeNode *node)
{

}









/* 二叉搜索树的初始化 */
int binarySearchTreeInit(
    BinarySearchTree **pBstree, 
    int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), 
    int printFunc(ELEMENTTYPE val)
)
{
    BinarySearchTree * bstree = (BinarySearchTree *)malloc(sizeof(BinarySearchTree) * 1);
    JUDGE_MALLOC(bstree);
    memset(bstree, 0, sizeof(BinarySearchTree) * 1);
    {
        bstree->root = NULL;
        bstree->size = 0;
        bstree->compareFunc = compareFunc;
        bstree->printFunc = printFunc;
    }
#if 0
    /* 分配根节点 */
    bstree->root = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    JUDGE_MALLOC(bstree->root);
    memset(bstree->root, 0, sizeof(BSTreeNode) * 1); 
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
    BSTreeNode *travelNode = pBstree->root;
    BSTreeNode *parentNode = pBstree->root;

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
    BSTreeNode *newBstNode = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    JUDGE_MALLOC(newBstNode);
    memset(newBstNode, 0, sizeof(BSTreeNode) * 1);
    {
        newBstNode->data = val;
        newBstNode->left = NULL;
        newBstNode->right = NULL;
        newBstNode->parent = parentNode;
    }
#else
    BSTreeNode *newBstNode = createBSTreeNewNode(val, parentNode);
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
/* 左子树 根结点 右子树 */
static int inOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node)
{
    JUDGE_IFNULL(node);
    /* 左子树 */
    inOrderTravel(pBstree, node->left);
    /* 根结点 */
    pBstree->printFunc(node->data);
    /* 右子树 */
    inOrderTravel(pBstree, node->right);
    return ON_SUCCESS;
}
int binarySearchTreeInOrderTravel(BinarySearchTree *pBstree)
{
    return inOrderTravel(pBstree, pBstree->root);
}

/* 二叉搜索树的后序遍历 */
int binarySearchTreePostOrderTravel(BinarySearchTree *pBstree)
{

}

/* 二叉搜索树的层序遍历 */
int binarySearchTreeLevelOrderTravel(BinarySearchTree *pBstree)
{
    BSTreeNode * nodeVal = NULL;
    // BSTreeNode * queueNode = pBstree->root;
    DoubleLinkListQueue * pQueue = NULL;
    doubleLinkListQueueInit(pBstree->root);
    doubleLinkListQueuePush(pQueue, pBstree->root);
    while (!doubleLinkListQueueIsEmpty(pQueue))
    {
        doubleLinkListQueueTop(pQueue, (void **)&nodeVal);
        #if 0
        printf("data%d\n", nodeVal->data);
        #else
        pBstree->printFunc(nodeVal->data);
        #endif
        doubleLinkListQueuePop(pQueue);
        /* 左右子树入队 */
        if (nodeVal->left != NULL)
        {
            doubleLinkListQueuePush(pQueue, nodeVal->left);
        }
        if (nodeVal->right != NULL)
        {
            doubleLinkListQueuePush(pQueue, nodeVal->right);
        }
    }
    FREE(nodeVal);
    FREE(pQueue);
    return ON_SUCCESS;
}

/* 根据指定值获取二叉搜索树的结点 */
static BSTreeNode * baseAppointValGetBSTreeNode(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    int cmp = 0;
    BSTreeNode * travelNode = pBstree->root;
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
/* 二叉树搜索是否包含指定的元素 */
int binarySearchTreeIsContainAppointVal(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    return baseAppointValGetBSTreeNode(pBstree, val) == NULL ? 0 : 1;
}

/* 获取二叉搜索树的高度 */
int binarySearchTreeGetHeight(BinarySearchTree *pBstree)
{
    return ON_SUCCESS;
}