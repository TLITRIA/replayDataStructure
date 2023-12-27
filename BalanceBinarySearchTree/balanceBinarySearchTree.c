#include "balanceBinarySearchTree.h"
#include "doubleLinkListQueue.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/* ==================静态函数前置声明=============== */

/* 两个值比较大小 */
static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2);
/* 自定义输出 */
static int printFunc(ELEMENTTYPE val);
/* 创建结点-√ */
static AVLTreeNode * createBSTreeNewNode(ELEMENTTYPE val, AVLTreeNode * parentNode);
/* 根据指定值获取二叉搜索树的结点 */
static AVLTreeNode * baseAppointValGetBSTreeNode(BalanceBinarySearchTree *pBstree, ELEMENTTYPE val);
/* 判断二叉搜索树的度为2-√ */
static int balanceBinarySearchTreeNodeHasTwoChildens(AVLTreeNode *node);
/* 判断二叉搜索树的度为1-√ */
static int balanceBinarySearchTreeNodeHasOneChilden(AVLTreeNode *node);
/* 判断二叉搜索树的度为0-√ */
static int balanceBinarySearchTreeNodeIsLeaf(AVLTreeNode *node);
/* 前序遍历 */
static int preOrderTravel(BalanceBinarySearchTree *pBstree, AVLTreeNode *node);
/* 中序遍历 */
static int inOrderTravel(BalanceBinarySearchTree *pBstree, AVLTreeNode *node);
/* 后续遍历 */
static int postOrderTravel(BalanceBinarySearchTree *pBstree, AVLTreeNode *node);
/* 获取前驱结点 */
static AVLTreeNode * bstreeNodePreDecessor(AVLTreeNode *node);
/* 获取后继结点 */
static AVLTreeNode * bstreeNodeSuccessor(AVLTreeNode *node);

/***************************************/

/* 判断二叉搜索树的结点度为2 */
static int balanceBinarySearchTreeNodeHasTwoChildens(AVLTreeNode *node)
{
    return (node->left != NULL && node->right != NULL);
}

/* 判断二叉搜索树的结点度为1 */
static int balanceBinarySearchTreeNodeHasOneChilden(AVLTreeNode *node)
{
    return ((node->left != NULL && node->right == NULL) || \
            (node->left == NULL && node->right != NULL));
}

/* 判断二叉搜索树的结点度为0 */
static int balanceBinarySearchTreeNodeIsLeaf(AVLTreeNode *node)
{
    return (node->left == NULL && node->right == NULL);
}



/* ==================静态函数前置声明END=============== */



/* 二叉搜索树的初始化 */
int balanceBinarySearchTreeInit(
    BalanceBinarySearchTree **pBstree, 
    int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), 
    int printFunc(ELEMENTTYPE val)
)
{
    BalanceBinarySearchTree * bstree = (BalanceBinarySearchTree *)malloc(sizeof(BalanceBinarySearchTree) * 1);
    JUDGE_MALLOC(bstree);
    memset(bstree, 0, sizeof(BalanceBinarySearchTree) * 1);
    {
        bstree->root = createBSTreeNewNode(0, NULL);
        JUDGE_IFNULL(bstree->root);
        bstree->size = 0;
        bstree->compareFunc = compareFunc;
        bstree->printFunc = printFunc;
        // doubleLinkListQueueInit(&(bstree->pQueue));
    }
#if 0
    /* 分配根节点 */
    bstree->root = (AVLTreeNode *)malloc(sizeof(AVLTreeNode) * 1);
    JUDGE_MALLOC(bstree->root);
    memset(bstree->root, 0, sizeof(AVLTreeNode) * 1); 
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

/* 封装树结点 */
static AVLTreeNode * createBSTreeNewNode(ELEMENTTYPE val, AVLTreeNode * parentNode)
{
    /* 分配根节点 */
    AVLTreeNode *newBstNode = (AVLTreeNode *)malloc(sizeof(AVLTreeNode) * 1);
    JUDGE_IFNULL_RETURN_NULL(newBstNode);
    memset(newBstNode, 0, sizeof(AVLTreeNode) * 1);
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


/* 二叉搜索树的插入 */
int balanceBinarySearchTreeInsert(BalanceBinarySearchTree *pBstree, ELEMENTTYPE val)
{
    /* 空树 */
    if (pBstree->size == 0)
    {
        (pBstree->size)++;
        pBstree->root->data = val;
        return ON_SUCCESS;
    }
    
    /* travelNode指向根节点 */
    AVLTreeNode *travelNode = pBstree->root;
    AVLTreeNode *parentNode = pBstree->root;

    /* 确定符号：放在左边还是右边 */
    int cmp = 0;
    /* 遍历到指定位置 */
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
    AVLTreeNode *newBstNode = (AVLTreeNode *)malloc(sizeof(AVLTreeNode) * 1);
    JUDGE_MALLOC(newBstNode);
    memset(newBstNode, 0, sizeof(AVLTreeNode) * 1);
    {
        newBstNode->data = val;
        newBstNode->left = NULL;
        newBstNode->right = NULL;
        newBstNode->parent = parentNode;
    }
#else
    AVLTreeNode *newBstNode = createBSTreeNewNode(val, parentNode);
    JUDGE_MALLOC(newBstNode);
#endif

    /* 挂载 */
    if (cmp < 0)
    {
        parentNode->left = newBstNode;
    }
    else 
    {
        parentNode->right = newBstNode;
    }
    (pBstree->size)++;
    return ON_SUCCESS;
}


/* 获取当前结点的前驱结点 */
static AVLTreeNode * bstreeNodePreDecessor(AVLTreeNode *node)
{
    /* 有左子树 */
    if (node->left != NULL)
    {
        /**/
        AVLTreeNode *travelNode = node->left;
        while (travelNode->right != NULL)
        {
            travelNode = travelNode->right;
        }
        return travelNode;
    }

    while (node->parent != NULL && node == node->parent->left)
    {
        node = node->parent;
    }
    return node->parent;
}

/* 获取当前结点的后继结点 */
static AVLTreeNode * bstreeNodeSuccessor(AVLTreeNode *node)
{
    if (node->right != NULL)
    {
        AVLTreeNode *travelNode = node->right;
        while (travelNode->left != NULL)
        {
            travelNode = travelNode->left;
        }
        return travelNode;
    }
    while (node->parent != NULL && node == node->parent->right)
    {
        node = node->parent;
    }
    return node->parent;
}

/* 二叉搜索树的前序遍历todo 根节点 左子树 右子树 */
static int preOrderTravel(BalanceBinarySearchTree *pBstree, AVLTreeNode *node)
{
    JUDGE_IFNULL(node);
    pBstree->printFunc(node->data);
    inOrderTravel(pBstree, node->left);
    inOrderTravel(pBstree, node->right);
    return ON_SUCCESS;
}
int balanceBinarySearchTreePreOrderTravel(BalanceBinarySearchTree *pBstree)
{
    return preOrderTravel(pBstree, pBstree->root);
}

/* 二叉搜索树的中序遍历todo 左子树 根节点 右子树 */
static int inOrderTravel(BalanceBinarySearchTree *pBstree, AVLTreeNode *node)
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

int balanceBinarySearchTreeInOrderTravel(BalanceBinarySearchTree *pBstree)
{
    return inOrderTravel(pBstree, pBstree->root);
}

/* 二叉搜索树的后序遍历todo 左子树 右子树 根节点 */

static int postOrderTravel(BalanceBinarySearchTree *pBstree, AVLTreeNode *node)
{
    JUDGE_IFNULL(node);
    inOrderTravel(pBstree, node->left);
    inOrderTravel(pBstree, node->right);
    pBstree->printFunc(node->data);
    return ON_SUCCESS;
}
int balanceBinarySearchTreePostOrderTravel(BalanceBinarySearchTree *pBstree)
{
    return postOrderTravel(pBstree, pBstree->root);
}

/* 二叉搜索树的层序遍历 */
int balanceBinarySearchTreeLevelOrderTravel(BalanceBinarySearchTree *pBstree)
{
    AVLTreeNode *nodeVal = NULL;
    // AVLTreeNode * queueNode = pBstree->root;
    DoubleLinkListQueue * pQueue = NULL;
    doubleLinkListQueueInit(&pQueue);/* BUG */
    doubleLinkListQueuePush(pQueue, pBstree->root);
    while (!doubleLinkListQueueIsEmpty(pQueue))
    {
        doubleLinkListQueueTop(pQueue, (void **)&nodeVal);
        printf("data%d\n", *(int *)nodeVal->data);
        pBstree->printFunc(nodeVal->data);/* todo */
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
    doubleLinkListQueueDestroy(pQueue);
    return ON_SUCCESS;
}

/* 根据指定值获取二叉搜索树的结点 */
static AVLTreeNode * baseAppointValGetBSTreeNode(BalanceBinarySearchTree *pBstree, ELEMENTTYPE val)
{
    int cmp = 0;
    AVLTreeNode * travelNode = pBstree->root;
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
int balanceBinarySearchTreeIsContainAppointVal(BalanceBinarySearchTree *pBstree, ELEMENTTYPE val)
{
    return baseAppointValGetBSTreeNode(pBstree, val) == NULL ? 0 : 1;
}

/* 获取二叉搜索树的高度 */
int balanceBinarySearchTreeGetHeight(BalanceBinarySearchTree *pBstree, int *pHeight)
{
    /* 判空 */
    JUDGE_IFNULL(pBstree);
    /* 判空树 */
    if (pBstree->size == 0)
    {
        return 0;
    }
    
    AVLTreeNode *travelNode = NULL;
    DoubleLinkListQueue * pQueue = NULL;
    doubleLinkListQueueInit(&pQueue);

    /* 根节点入队，高度为1 */
    doubleLinkListQueuePush(pQueue, pBstree->root);
    int height = 0;          /* 树的高度 */
    int levelSize = 1;      /* 树每一层的结点数量 */
    while (!doubleLinkListQueueIsEmpty(pQueue))
    {
        doubleLinkListQueueTop(pQueue,  (void **)&travelNode);
        doubleLinkListQueuePop(pQueue);
        levelSize--;

        /* 左子树 */
        if (travelNode->left != NULL)
        {
            doubleLinkListQueuePush(pQueue, travelNode->left);
        }

        /* 右子树 */
        if (travelNode->right != NULL)
        {
            doubleLinkListQueuePush(pQueue, travelNode->right);
        }

        /* 树的当前层结点遍历结束 */
        if (levelSize == 0)
        {
            height++;
            doubleLinkListQueueGetSize(pQueue, &levelSize);
        }
    }
    
    *pHeight = height;
    /* 释放队列空间 */
#if 1
    doubleLinkListQueueDestroy(pQueue);
#else
    pBstree->pQueue(pQueue);
#endif
    return ON_SUCCESS;
}

/* todo删除指定位置的结点 */
static int balanceBinarySearchTreeDeleteNode(BalanceBinarySearchTree *pBstree, AVLTreeNode *node)
{
    JUDGE_IFNULL(pBstree);
    JUDGE_IFNULL(node);
    if (balanceBinarySearchTreeNodeHasTwoChildens(node))   /* 度为2 */
    {
        AVLTreeNode *preNode = bstreeNodePreDecessor(node);
        node->data = preNode->data;
#if 0
        balanceBinarySearchTreeDeleteNode(pBstree, preNode);
        return ON_SUCCESS;
#else
        node = preNode;
#endif
    }
    
    
    #if 0
    if (balanceBinarySearchTreeNodeHasOneChilden(node))
    {
        if (parentNode->left->data == node->data)
        {
            if (node->left != NULL)
            {
                node->left->parent = parentNode;
                FREE(parentNode->left);
                parentNode->left = node->left;
            }
            else
            {
                node->left->parent = parentNode;
                FREE(parentNode->left);
                parentNode->left = node->left;
            }    
        }
        else
        {
            if (node->left != NULL)
            {
                node->left->parent = parentNode;
                FREE(parentNode->left);
                parentNode->left = node->left;
            }
            else
            {
                node->left->parent = parentNode;
                FREE(parentNode->left);
                parentNode->left = node->left;
            }
        }
        
        return ON_SUCCESS;
    }
    if (balanceBinarySearchTreeNodeIsLeaf(node))
    {
        return ON_SUCCESS;
    }
    #endif
    AVLTreeNode *parentNode = node->parent;
    AVLTreeNode *childNode = (node->left != NULL) ? node->left : node->right;
    AVLTreeNode *delNode = NULL;
    if (childNode != NULL) /* 度为1 */
    {
        if (parentNode == NULL)/* 根节点 */
        {
            pBstree->root = childNode;
        }
        else
        {
            // if (parentNode->left->data == node->data)
            if (parentNode->left == node)
            {
                parentNode->left = childNode;
            }
            else
            {
                parentNode->right = childNode;
            }
            childNode->parent = parentNode;
        }
        delNode = node;
    }
    else                    /* 度为0 */
    {/* 可以直接删吗 */
        if (parentNode == NULL)
        {
            delNode = node;
        }
        else
        {
            if (parentNode->left != NULL)
            {
                delNode = parentNode->left;
            }
            else
            {
                delNode = parentNode->right;
            }
        }
    }
    FREE(delNode);
    (pBstree->size)--;
    return ON_SUCCESS;
}

/* 二叉搜索树的删除 */
int balanceBinarySearchTreeDelete(BalanceBinarySearchTree *pBstree, ELEMENTTYPE val)
{
    balanceBinarySearchTreeDeleteNode(pBstree, baseAppointValGetBSTreeNode(pBstree, val));
    return ON_SUCCESS;
}

/* 二叉搜索树的销毁 */
int balanceBinarySearchTreeDestory(BalanceBinarySearchTree *pBstree)
{
    AVLTreeNode *travelNode = NULL;
    DoubleLinkListQueue *pQueue;
    doubleLinkListQueueInit(&pQueue);

    #if 0
doubleLinkListQueueDestroy(pBstree->pQueue);
    doubleLinkListQueueInit(pBstree->pQueue);
    doubleLinkListQueuePush(pBstree->pQueue, pBstree->root);
    while (!doubleLinkListQueueIsEmpty(pBstree->pQueue))
    {
        doubleLinkListQueuePush(pBstree->pQueue, (void **)&travelNode);
        doubleLinkListQueuePop(pBstree->pQueue);

        if (travelNode->left != NULL)
        {
            doubleLinkListQueuePush(pBstree->pQueue, travelNode->left);
        }
        if (travelNode->right != NULL)
        {
            doubleLinkListQueuePush(pBstree->pQueue, travelNode->right);
        }
        /* 最后销毁 */
        FREE(travelNode);
    }
    /* 释放队列 */
    doubleLinkListQueueDestroy(pBstree->pQueue);
    #else
doubleLinkListQueueDestroy(pQueue);
    doubleLinkListQueueInit(&pQueue);
    doubleLinkListQueuePush(pQueue, pBstree->root);
    while (!doubleLinkListQueueIsEmpty(pQueue))
    {
        doubleLinkListQueuePush(pQueue, (void **)&travelNode);
        doubleLinkListQueuePop(pQueue);

        if (travelNode->left != NULL)
        {
            doubleLinkListQueuePush(pQueue, travelNode->left);
        }
        if (travelNode->right != NULL)
        {
            doubleLinkListQueuePush(pQueue, travelNode->right);
        }
        /* 最后销毁 */
        FREE(travelNode);
    }
    /* 释放队列 */
    doubleLinkListQueueDestroy(pQueue);
    #endif
    return ON_SUCCESS;
}


/* 判断二叉搜索树是否完全 */

/* 获取二叉搜索树的结点个数 */
int balanceBinarySearchTreeGetNodeSize(BalanceBinarySearchTree *pBstree, int *pSize)
{
    JUDGE_IFNULL(pBstree);
    if (pSize)
    {
        *pSize = pBstree->size;
    }
    return ON_SUCCESS;
}
