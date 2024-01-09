#ifndef __SET_DATA_STRUCTURE_
#define __SET_DATA_STRUCTURE_


#include "balanceBinarySearchTree.h"


#define ELEMENTTYPE void*


typedef BalanceBinarySearchTree SetDataStructure;



/* 初始化集合 */
int setDataStructureInit(SetDataStructure ** pSet, 
                        int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), 
                        int (*printFunc)(ELEMENTTYPE val));

/* 向集合添加数据 */
int setDataStructureInsert(SetDataStructure * pSet, ELEMENTTYPE val);


/* 判断元素是否在集合中 */
int setDataStructureIsExist(SetDataStructure * pSet, ELEMENTTYPE val);


/* 删除集合中的元素 */
int setDataStructureDelAppointVal(SetDataStructure * pSet, ELEMENTTYPE val);

/* 显示集合中的所有元素 */
int setDataStructureForeach(SetDataStructure * pSet);

/* 获取集合大小 */
int setDataStructureGetSize(SetDataStructure * pSet, int *pSize);

/* 销毁集合 */
int setDataStructureDestroy(SetDataStructure * pSet);










#endif //__SET_DATA_STRUCTURE_