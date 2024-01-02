#include "binarySearchTree.h"
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
static BSTreeNode * createBSTreeNewNode(ELEMENTTYPE val, BSTreeNode * parentNode);
/* 根据指定值获取二叉搜索树的结点 */
static BSTreeNode * baseAppointValGetBSTreeNode(BinarySearchTree *pBstree, ELEMENTTYPE val);
/* 判断二叉搜索树的度为2-√ */
static int binarySearchTreeNodeHasTwoChildens(BSTreeNode *node);
/* 判断二叉搜索树的度为1-√ */
static int binarySearchTreeNodeHasOneChilden(BSTreeNode *node);
/* 判断二叉搜索树的度为0-√ */
static int binarySearchTreeNodeIsLeaf(BSTreeNode *node);
/* 前序遍历 */
static int preOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node);
/* 中序遍历 */
static int inOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node);
/* 后续遍历 */
static int postOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node);
/* 获取前驱结点 */
static BSTreeNode * bstreeNodePreDecessor(BSTreeNode *node);
/* 获取后继结点 */
static BSTreeNode * bstreeNodeSuccessor(BSTreeNode *node);

/*****************静态函数声明**********************/
int printFunc(void *arg)
{
    int data = *(int *)arg;
    printf("data:%d\n", data);
}

int compareFunc(void *arg1, void *arg2)
{
    return (arg1 == arg2) ? 1 : 0;
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

/* 封装树结点 */
static BSTreeNode * createBSTreeNewNode(ELEMENTTYPE val, BSTreeNode * parentNode)
{
    BSTreeNode *newBstNode = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    JUDGE_NULL_RETURN_NULL(newBstNode);
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
/* 获取当前结点的前驱结点 */
static BSTreeNode * bstreeNodePreDecessor(BSTreeNode *node)
{
    /* 有左子树 */
    if (node->left != NULL)
    {
        /**/
        BSTreeNode *travelNode = node->left;
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
static BSTreeNode * bstreeNodeSuccessor(BSTreeNode *node)
{
    if (node->right != NULL)
    {
        BSTreeNode *travelNode = node->right;
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
static int preOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node)
{
    JUDGE_NULL(node);
#if 0
    pBstree->printFunc(node->data);
    inOrderTravel(pBstree, node->left);
    inOrderTravel(pBstree, node->right);
#else
    pBstree->printFunc(node->data);
    preOrderTravel(pBstree, node->left);
    preOrderTravel(pBstree, node->right);
#endif
    return ON_SUCCESS;
}
    

/* 二叉搜索树的中序遍历todo 左子树 根节点 右子树 */
static int inOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node)
{
    JUDGE_NULL(node);
    /* 左子树 */
    inOrderTravel(pBstree, node->left);
    /* 根结点 */
    pBstree->printFunc(node->data);
    /* 右子树 */
    inOrderTravel(pBstree, node->right);
    return ON_SUCCESS;
}

/* 二叉搜索树的后序遍历todo 左子树 右子树 根节点 */

static int postOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node)
{
    JUDGE_NULL(node);
#if 0
    inOrderTravel(pBstree, node->left);
    inOrderTravel(pBstree, node->right);
    pBstree->printFunc(node->data);
#else
    postOrderTravel(pBstree, node->left);
    postOrderTravel(pBstree, node->right);
    pBstree->printFunc(node->data);
#endif    
    
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

#if 0
/* todo该bug有继承性删除指定位置的结点 */
static int binarySearchTreeDeleteNode(BinarySearchTree *pBstree, BSTreeNode *node)
{
    JUDGE_NULL(pBstree);
    JUDGE_NULL(node);
    if (binarySearchTreeNodeHasTwoChildens(node))   /* 度为2 */
    {
        BSTreeNode *preNode = bstreeNodePreDecessor(node);
        node->data = preNode->data;
#if 0
        binarySearchTreeDeleteNode(pBstree, preNode);
        return ON_SUCCESS;
#else
        node = preNode;
#endif
    }
    BSTreeNode *parentNode = node->parent;
    BSTreeNode *childNode = (node->left != NULL) ? node->left : node->right;
    BSTreeNode *delNode = NULL;
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
#else
static int binarySearchTreeDeleteNode(BinarySearchTree *pBstree, BSTreeNode *node)
{
    JUDGE_NULL(node);
    (pBstree->size)--;
    /* 度为2 */
    if (binarySearchTreeNodeHasTwoChildens(node))
    {
        BSTreeNode *preNode = bstreeNodePreDecessor(node);
        node->data = preNode->data;
        node = preNode;
    }
    /* 度为1 或0 */
    BSTreeNode *childNode = node->left != NULL ? node->left : node->right;
    BSTreeNode *delNode = NULL;
    if (childNode != NULL)
    {
        childNode->parent = node->parent;
        if (node->parent == NULL)   /* 度为1 */
        {
            pBstree->root = childNode;
            delNode = node;
        }
        else
        {
            if (node == node->parent->left)
            {
                node->parent->left = childNode;
            }
            else if (node == node->parent->right)
            {
                node->parent->right = childNode;
            }
            delNode = node;
        }
    } 
    else /* 度为0 */
    {
        if (node->parent == NULL)
        {
            delNode = node;
        }
        else
        {
            if (node == node->parent->left)
            {
                node->parent->left = NULL;
            }
            else if (node == node->parent->right)
            {
                node->parent->right = NULL;
            }
            delNode = node;
        }
        
    }
    FREE(delNode);
    return ON_SUCCESS;
}
#endif
/* ==================静态函数前置声明END=============== */



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
        bstree->root = createBSTreeNewNode(0, NULL);
        JUDGE_NULL(bstree->root);
        bstree->size = 0;
        bstree->compareFunc = compareFunc;
        bstree->printFunc = printFunc;
        // doubleLinkListQueueInit(&(bstree->pQueue));
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

    *pBstree = bstree;
    return ON_SUCCESS;
}


/* 二叉搜索树的插入 */
int binarySearchTreeInsert(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    /* 空树 */
    if (pBstree->size == 0)
    {
        (pBstree->size)++;
        pBstree->root->data = val;
        // printf("pBstree->size:%d\t", pBstree->size);
        // pBstree->printFunc(val);
        return ON_SUCCESS;
    }
    
    /* travelNode指向根节点 */
    BSTreeNode *travelNode = pBstree->root;
    BSTreeNode *parentNode = pBstree->root;

    /* 确定符号：放在左边还是右边 */
    int cmp = 0;
    /* 遍历到指定位置 */
    while (travelNode != NULL)
    {
        parentNode = travelNode;
        // cmp = val - travelNode->data;
        cmp = pBstree->compareFunc(val, travelNode->data);
        /* 插入元素 < 遍历到的结点 */
        if (cmp < 0)    /* 值比当前结点小 */
        {
            travelNode = travelNode->left;
        }
        else if (cmp > 0)
        {
            travelNode = travelNode->right;
        }
        else
        {
            /* 插入元素=遍历到的结点 */
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
    // printf("pBstree->size:%d\t", pBstree->size);
    // pBstree->printFunc(val);
    return ON_SUCCESS;
}



int binarySearchTreePreOrderTravel(BinarySearchTree *pBstree)
{
    return preOrderTravel(pBstree, pBstree->root);
}


int binarySearchTreeInOrderTravel(BinarySearchTree *pBstree)
{
    return inOrderTravel(pBstree, pBstree->root);
}


int binarySearchTreePostOrderTravel(BinarySearchTree *pBstree)
{
    return postOrderTravel(pBstree, pBstree->root);
}

/* 二叉搜索树的层序遍历 */
int binarySearchTreeLevelOrderTravel(BinarySearchTree *pBstree)
{
    BSTreeNode *nodeVal = NULL;
    // BSTreeNode * queueNode = pBstree->root;
    DoubleLinkListQueue * pQueue = NULL;
    doubleLinkListQueueInit(&pQueue, compareFunc, printFunc);
    doubleLinkListQueuePush(pQueue, pBstree->root);
    while (!doubleLinkListQueueIsEmpty(pQueue))
    {
        doubleLinkListQueueTop(pQueue, (void **)&nodeVal);
        // printf("data:%d\n", *(int *)nodeVal->data);
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


/* 二叉树搜索是否包含指定的元素 */
int binarySearchTreeIsContainAppointVal(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    return baseAppointValGetBSTreeNode(pBstree, val) == NULL ? 0 : 1;
}

/* 获取二叉搜索树的高度 */
int binarySearchTreeGetHeight(BinarySearchTree *pBstree, int *pHeight)
{
    /* 判空 */
    JUDGE_NULL(pBstree);
    /* 判空树 */
    if (pBstree->size == 0)
    {
        return 0;
    }
    
    BSTreeNode *travelNode = NULL;
    DoubleLinkListQueue * pQueue = NULL;
    doubleLinkListQueueInit(&pQueue, compareFunc, printFunc);

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

/* 二叉搜索树的删除 */
int binarySearchTreeDelete(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    binarySearchTreeDeleteNode(pBstree, baseAppointValGetBSTreeNode(pBstree, val));
    return ON_SUCCESS;
}

/* 二叉搜索树的销毁 */
int binarySearchTreeDestory(BinarySearchTree *pBstree)
{
    BSTreeNode *travelNode = NULL;
    DoubleLinkListQueue *pQueue;
    doubleLinkListQueueInit(&pQueue, compareFunc, printFunc);

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
    doubleLinkListQueueInit(&pQueue, compareFunc, printFunc);
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



/* 获取二叉搜索树的结点个数 */
int binarySearchTreeGetNodeSize(BinarySearchTree *pBstree, int *pSize)
{
    JUDGE_NULL(pBstree);
    if (pSize)
    {
        *pSize = pBstree->size;
    }
    return ON_SUCCESS;
}


/**二叉树打印树形
 * ┏    左子树
 * ┓    右子树
 * ━    横线
 * ┛    仅有左子树的父节点
 * ┗    仅有右子树的父节点
 * ┻    有左右子树的父节点
*/
int binarySearchTreePrintStructure(BinarySearchTree *pBstree)
{
    return ON_SUCCESS;
}