#include <stdio.h>


#include "setDataStructure.h"
#include "balanceBinarySearchTree.h"





/* 初始化集合 */
int setDataStructureInit(SetDataStructure ** pSet, 
                        int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), 
                        int (*printFunc)(ELEMENTTYPE val))
{
    balanceBinarySearchTreeInit(pSet, compareFunc, printFunc);
    return ON_SUCCESS;   
}

/* 向集合添加数据 */
int setDataStructureInsert(SetDataStructure * pSet, ELEMENTTYPE val)
{
    balanceBinarySearchTreeInsert(pSet, val);
    return ON_SUCCESS;
}


/* 判断元素是否在集合中 */
int setDataStructureIsExist(SetDataStructure * pSet, ELEMENTTYPE val)
{
    return balanceBinarySearchTreeIsContainAppointVal(pSet, val);
}


/* 删除集合中的元素 */
int setDataStructureDelAppointVal(SetDataStructure * pSet, ELEMENTTYPE val)
{
    balanceBinarySearchTreeDelete(pSet, val);
    return ON_SUCCESS;
}

/* 显示集合中的所有元素 */
int setDataStructureForeach(SetDataStructure * pSet)
{
    balanceBinarySearchTreeInOrderTravel(pSet);
    return ON_SUCCESS;
}

/* 获取集合大小 */
int setDataStructureGetSize(SetDataStructure * pSet, int *pSize)
{
    return balanceBinarySearchTreeGetNodeSize(pSet, pSize);
}

/* 销毁集合 */
int setDataStructureDestroy(SetDataStructure * pSet)
{
    balanceBinarySearchTreeDestroy(pSet);
    return ON_SUCCESS;
}






