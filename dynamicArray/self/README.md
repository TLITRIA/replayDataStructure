
/* 初始化动态数组 */
int dynamicInit(dynamicArray *pArray, int capcity);

/* 插入动态数组--行末 */
int dynamicInsertAppointData(dynamicArray *pArray, ELEMENTTYPE val);

/* 插入动态数组--指定位置 */
int dynamicInsertAppointPosData(dynamicArray *pArray, int pos, ELEMENTTYPE val);

/* 修改动态数组--指定位置 */
int dynamicModifyPosData(dynamicArray *pArray, int pos, ELEMENTTYPE val);

/* 删除动态数组数据--行末 */
int dynamicDelLastData(dynamicArray *pArray);

/* 删除动态数组数据-指定位置 */
int dynamicDelPosData(dynamicArray *pArray, int pos);

/* 删除动态数组数据-所有指定值 */
int dynamicDelData(dynamicArray *pArray, int val);

/* 销毁动态数组 */
int dynamicDestroy(dynamicArray *pArray);

/* 获取长度 */
int dynamicGetLength(dynamicArray *pArray, int *length);

/* 获取容量 */
int dynamicGetCapacity(dynamicArray *pArray, int *capacity);

/* 获取指定位置的值 */
int dynamicGetPosVal(dynamicArray *pArray, int pos, ELEMENTTYPE *pVal);


初始化动态数组 dynamicInit(dynamicArray *pArray,int capacity)
    1.参数：*pArray     capcity
        a.判空
        b.判断容量是否合法，不合法要使用默认值
    2.为pArray->data指针分配空间 
        a.判断是否成功分配
        b.分配空间必须清理脏数据
    3.初始化动态数组的信息
        a.长度
        b.容量
    4.返回
（静态）扩容   exapndCapacity(dynamicArray *pArray)
    1.参数：由于在调用前已判空所以不需要重复
    2.备份pArray->data指向的地址，
    3.分配新的指定容量的内存（新的容量计算得出），让pArray->data指向新地址
    4.数据拷贝到新内存
    5.释放旧内存，使用宏函数简化
    6.更新数组容量
（静态）缩容   shrinkCapacity(dynamicArray *pArray)
    1.判空：由于在调用前已判空所以不需要重复
    2.备份pArray->data指向的地址，
    3.分配新的指定容量的内存（新的容量计算得出），让pArray->data指向新地址
    4.数据拷贝到新内存
    5.释放旧内存，使用宏函数简化
    6.更新数组容量
    todo...由于扩容缩容代码高度一致，可以尝试合并
动态数组插入---行末    dynamicInsertAppointData()
    调用下一函数，行末的位置是pArray->length
动态数组插入---指定位置   dynamicInsertAppointPosData
    1.参数：pArray    pos        val
        a.判空
        b.pos是否合法
        c.动态数组是否需要扩容？每次只插入一个值
    2.插入数据：数组从末尾开始后移一个，一直到腾出插入位置再插入指定值
    3.更新：数组长度
动态数组修改---指定位置   dynamicModifyAppointPosData
    1.参数：pArray    pos        val
        a.判空
        b.pos是否合法
    2.修改数据
动态数组删除---行末
动态数组删除---指定位置   dynamicDelAppointPosData
    1.参数：pArray    pos
        a.判空
        b.pos是否合法
        c.动态数组是否需要缩容？每次只删除一个值
    2.删除数据：数组从删除位置前移一个，直到末尾
    3.更新：数组长度
动态数组删除---指定数值   dynamicDelAppointData
    1.参数：pArray    val
        a.判空
    2.遍历数据，并调用删除指定位置数据的函数
    3.更新：数组长度

动态数组销毁    dynamicDestroy
    1.参数：pArray
        a.判空
    2.释放pArray->data指向的空间

动态数组获取长度
动态数组获取容量    dynamicGetCapicity
    1.参数：pArray    pVal
        a.两指针都要判空
    2.获取参数
===================END========================