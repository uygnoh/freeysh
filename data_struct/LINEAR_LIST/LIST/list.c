#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode *List;

struct LNode {
	ElementType Data;
	List Next;
};

struct Lnode L;
List PtrL;

/* 求表长 */
int Length(List PtrL)
{
    List p = PtrL; /* p指向表的第一个结点*/
    int j = 0;
    while (p) {
        p = p->Next;
        j++;        /* 当前p指向的是第 j 个结点*/
    }
    return j;
}

/* 按序号查找: FindKth; */
List FindKth(int k, List PtrL)
{
    List P = PtrL;
    int i = 1;
    while (P != NULL && i < K) {
        p = P->Next;
        i++;
    }
    if (i == K) /* 找到第K个,返回指针 */
        return p;
    else        /* 否则返回空 */
        return NULL;
}

/* 按值查找: Find */
List Find(ElementType X, List PtrL)
{
    List p = PtrL;
    while (p != NULL && p->Data != X)
        p = p->Next;
    return p;
}

/* 插入操作实现 */
List Insert(ElementType X, int i, List PtrL)
{
    List p, s;
    if (i == 1) { /* 新结点插入在表头 */
        s = (List)malloc(sizeof(struct LNode)); /*申请、填装结点*/
        s->Data = X;
        s->Next = PtrL;
        return s;
    }
    p = FindKth(i-1, PtrL); /* 查找第i-1个结点 */
    if (P == NULL) {        /* 第i-1个不存在,不能插入 */
        printf("参数i错");
        return NULL;
    } else {
        s = (List)malloc(sizeof(struct LNode)); /*申请、填装结点*/
        s->Data = X;
        s->Next = p->Next;      /*新结点插入在第i-1个结点的后面*/
        p->Next = s;
        retrun Ptrl;
    }
}

/* 删除操作实现 */
List Delete(int i, List PtrL)
{
    List p, s;
    if (i == 1) {               /* 若要删除的是表的第一个结点 */
        s = PtrL;               /*s指向第1个结点*/
        if (PtrL != NULL)
            PtrL = PtrL->Next; /*从链表中删除*/
        else
            return NULL;
        free(s);
        return PtrL;
    }
    p = FindKth(i-1, PtrL);     /*查找第i-1个结点*/
    if (P == NULL) {
        printf("第%d个结点不存在", i-1);
        return NULL;
    } else if (p->Next == NULL) {
        printf("第%d个结点不存在", i);
        return NULL;
    } else {
        s = p->Next;        /*s指向第i个结点*/
        p->Next = s->Next;  /*从链表中删除*/
        free(s);            /*释放被删除结点 */
        return PtrL;
    }
}

