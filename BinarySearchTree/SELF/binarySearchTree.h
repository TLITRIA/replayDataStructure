#ifndef __BINARY_SEARCH_TREE_
#define __BINARY_SEARCH_TREE_

#define ELEMENTYPE void*


/**二叉树结点
 * 值
 * 
 * 
*/

typedef struct BSTreeNode
{
    ELEMENTYPE data;
    BSTreeNode* parent;
    BSTreeNode* left;
    BSTreeNode* right;
} BSTreeNode;


typedef struct BSTreeList
{
    BSTreeNode * root;
    int size;
    int (*compareFunc)(ELEMENTYPE val1, ELEMENTYPE val2);
    int (*printFunc)(ELEMENTYPE val);
    
} BSTreeList;

/* 二叉树初始化 */
int binarySearchTreeInit(BSTreeList **pBSTree, 
                        int (compareFunc)(ELEMENTYPE val1, ELEMENTYPE val2),
                        int (printFunc)(ELEMENTYPE val));



/* 树的插入--指定数据 */
int binarySearchTreeInsertAppointVal(BSTreeList *pBSTree, ELEMENTYPE val);


/* 询问树是否包含指定元素 */
int binarySearchTreeAppointValIsExist(BSTreeList *pBSTree, ELEMENTYPE val);


/* 中序遍历 */
int binarySearchTreeInOrderTravel(BSTreeList *pBSTree);

/* 前序遍历 */
int binarySearchTreePreOrderTravel(BSTreeList *pBSTree);

/* 后续遍历 */
int binarySearchTreePostOrderTravel(BSTreeList *pBSTree);

/* 层序遍历 */
int binarySearchTreeLevelOrderTravel(BSTreeList *pBSTree);

/* 获取结点总数 */
int binarySearchTreeGetSize(BSTreeList *pBSTree, int *pSize);

/* 获取树的高度 */
int binarySearchTreeGetHeigth(BSTreeList *pBSTree, int *pHeight);

/* 结点删除 */
int binarySearchTreeDelAppointVal(BSTreeList *pBSTree, ELEMENTYPE val);

/* 二叉树的销毁 */
int binarySearchTreeDestroy(BSTreeList *pBSTree);

#endif