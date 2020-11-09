#include "list.h"

/* 链表节点数据初始化 */
void vListInitialiseItem( ListItem_t * const pxItem )
{
    pxItem->pvContainer = NULL;
}

/* 链表根节点数据初始化 */
void vListInitialise( List_t * const pxList )
{
    pxList->pxIndex = ( ListItem_t * ) &( pxList->xListEnd );
    pxList->xListEnd.xItemValue = 0xffff;
    pxList->xListEnd.pxNext = ( ListItem_t * ) &( pxList->xListEnd );
    pxList->xListEnd.pxPrevious = ( ListItem_t * ) &(pxList->xListEnd );
    pxList->uxnumberOfItems = 0;
}



//将节点插入链表尾部,      链表根节点（要插入的链表）原End节点，     新节点
void vListInsertEnd( List_t * const pxList, ListItem_t * const pxNewListItem )
{
    //定义一个索引指向新的根节点，就是End节点传递为不同的数据类型
    ListItem_t * const pxIndex = pxList->pxIndex;
    

	//(1)下一个节点Next指向End, 新节点的下一个节点 == 原End节点
    pxNewListItem->pxNext = pxIndex;
    //(2)新节点上一个节点 == 原End节点的上一个节点
    pxNewListItem->pxPrevious = pxIndex->pxPrevious;
    //(3)原End节点的上一个节点的下一个节点 == 新节点
    pxIndex->pxPrevious->pxNext = pxNewListItem;
    //(4)原End节点的上一个节点 == 新节点
    pxIndex->pxprevious = pxNewListItem;
    //(5)记记住该节点所在的链表
    pxNewListItem->pvContainer = ( void * )pxList;
    //(6)链表节点记数器++
    ( pxList->uxNumberOfItems )++;
}



/* 将节点按照升序排列插入链表 */
/* 如果两个链表节点相同，则新节点在旧节点后面插入 */
void vListInsert( List_t * const pxList, ListItem * const pxNewListItem )
{
    ListItem_t *pxIterator;
    const int xValueOfInsertion = pxNewListItem->xItemValue;
    
    if ( xValueOfInsertion == 0xffff )
    {
        pxIterator = pxList->xListEnd.pxPrevious;
    }
    else
    {
        for ( pxIterator = ( ListItem * ) &( pxList->xListEnd );
            pxIterator->pxNext->xItemValue <= xValueOfInsertion;
            pxIterator = pxIterator->pxNext; )
        {
        }
    }
    
    pxNewListItem->pxNext = pxIterator->pxNext;
    pxNewListItem->pxNext->pxPrevious = pxNewListItem;
    pxNewListItem->pxPrevious = pxIterator;
    pxIterator->pxNext = pxNewListItem;
    
    pxNewListItem->pvContainer = ( void * ) pxList;
    ( pxList->uxNumberOfItems )++;
}



/* 将节点从链表中删除 */
int uxListRemove( ListItem_t * const pxItemToRemove )
{
    /* 获取节点所在链表 */
    List_t * const pxList = ( List_t * ) pxItemToRemove->pvContainer;
    
    /* 将指定的链表从节点中删除 */
    pxItemToRemove->pxNext->pxPrevious = pxItemToRemove->pxPrevious;
    pxItemToRemove->pxPrevious->pxNext = pxItemToRemove->pxNext;
    
    /* 调整链表的索引指针 */
    if ( pxList->pxIndex == pxItemToRemove )
    {
        pxList->pxIndex = pxItemToRemove->pxPrevious;
    }
    
    /* 初始化该节点所在的链表为空， 表示该节点还没有插入任何节点 */
    pxItemToRemove->pvContainer = NULL;
    
    /* 链表节点计数器--*/
    ( pxList->uxNumberOfitems )--;
    
    /* 返回链表其它节点的个数 */
    return pxList->uxNumberOfitems;
}







