#ifndef __LIST_H
#define __LIST_H

/* 链表节点数据结构定义 */
struct xLIST_ITEM {
    int xItemValue;
    struct xLIST_ITEM * pxNext;
    struct xLIST_ITEM * pxPrevious;
    void * pvOwner;
    void * pvContainer;
};
typedef struct xLIST_ITEM ListItem_t;

/* 链表精简节点数据结构定义 */
struct xMINI_LIST_ITEM {
    int xItemValue;
    struct xMINI_LIST_ITEM * pxNext;
    struct xMINI_LIST_ITEM * pxPrevious;
};
typedef struct xMINI_LIST_ITEM MiniListItem_t;

/* 链表根节点数据结构定义 */
struct xLIST {
    int uxNumberOfItems;
    ListItem_t * pxIndex;
    MiniListItem_t xListEnd;
};
typedef struct xLIST List_t;

#endif
