？？判断尾指针是否需要同步？

========================接口.h=========================
- 防止重定义

- LinkNode结点结构体
-   ELEMENTTYPE data    数据
-   struct LinkNode *next    指向下一结点的指针

- LinkList链表结构体
-   LinkNode *head    头指针
-   LinkNode *tail        尾指针
-   int len            链表长度
========================接口.c=========================

/* 链表初始化 */
int myLinkListInit(LinkList ** pList);
    1.初始化新链表结构体    newList
        a.分配空间
        b.分配空间必须判断分配成功
        c.分配空间必须清理脏数据
    2.初始化虚拟表头（头指针）结构体    newList->head
        a.分配空间
        b.判断
        c.清理脏数据
    3.初始化链表数据
        a.链表结构体
            i.len
            ii.tail
        b.头 结点结构体
            i.data
            ii.next
    4.将新链表结构体赋予二级指针：这些指针叫什么不重要，只是方便操作内存，重要的是内存空间的数据。所以不需要释放空间

/* 插入链表--头插 */
int myLinkListInsertHead(LinkList * pList, ELEMENTTYPE val);

/* 插入链表--尾插 */
int myLinkListInsertTail(LinkList * pList, ELEMENTTYPE val);

/* 插入链表--指定位置插入 */
int myLinkListInsertAppointPos(LinkList * pList, int pos, ELEMENTTYPE val);

    1.参数：pList pos val
        a.判空
        b.判非法访问，地址值可以视为数组下标，只是链表还在使用时就不会操作头指针。
        c.设置标志位，判断尾指针是否要同步
    2.初始化待插入结点
        a.分配空间
        b.分配空间必须判断成功
        c.分配空间必须清理脏数据
        d.赋值
        e.指向NULL
    3.初始化travelNode结点，遍历到待插入位置的前面(想想为什么)
        a.新建travelNode结点，初始指向头结点
    4.travelNode newNode 2步插入操作
        a.newNode指向原本位于插入位置的结点
        b.travelNode指向newNode
    5.更新
        a.链表长度
        b.尾结点同步
/* 删除链表--头删 */
int myLinkListDelHead(LinkList * pList);

/* 删除链表--尾删 */
int myLinkListDelTail(LinkList * pList);

/* 删除链表--指定位置删 */
int myLinkListDelAppointPos(LinkList * pList, int pos);

    1.参数处理
        a.判空
        b.判非法访问，不能删除头指针，todo使用尾指针
        c.判断是否要同步尾指针
    2.初始化待删除结点needDelNode：释放空间的需求，先改链表则找不到要释放的空间，先释放空间则找不到链表下半截，所以？需要一个结点标记要释放的空间。
        a.初始指向头结点
    3.初始化travelNode，并遍历到待删除结点之前的一个结点
    4.3步删除
        a.needDelNodel指向待删除结点
        b.travelNode指向下一个结点
        c.释放needDelNode
    5.更新
        a.链表长度
        b.尾结点同步
/*静态函数：根据指定值获取指定值在链表的位置*/
    1.参数：调用前已判空
    2.封装travelNode遍历结点，初始指向头结点后一个结点或NULL
    3.遍历结点，找到第一个就返回pos
    4.找不到就返回错误信息，解引用

/* 删除链表--指定数据删除 */
int myLinkListDelAppointVal(LinkList * pList, ELEMENTTYPE val);

    1.遍历结点并删除符合的数据直到链表删光或再也找不到符合的结点

/* 获取链表--长度 */
int myLinkListGetLength(LinkList * pList, int *size);

    1.参数
        a.判空*2
    2.写入数据
/* 获取链表--遍历链表元素 */
int myLinkListForeach(LinkList * pList, int (*printFunc)(ELEMENTTYPE));
这里使用了狗子函数，函数指针是指向函数的指针
    1.参数
        a.判空
    2.初始化遍历结点
    3.遍历结点并使用自定义的函数打印各种数据
/**指针函数与函数指针
 * 指针函数：返回值是指针的函数
 * 函数指针：指向函数的指针
*/

/* 销毁链表 */
int myLinkListDestroy(LinkList * pList);
1.参数
    a.判空
2.循环尾删链表
3.释放头指针
4.释放链表



========================测试.c=========================



