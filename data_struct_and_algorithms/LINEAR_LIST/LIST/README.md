
### 什么是线性表
线性表(Linear List)”:由同类型数据元素构成有序序列的线性结构
+ 表中元素个数称为线性表的长度
+ 线性表没有元素时,称为空表
+ 表起始位置称表头,表结束位置称表尾


### 线性表的抽象数据类型描述
+ 类型名称:线性表(List)
+ 数据对象集:线性表是 n (≥0)个元素构成的有序序列( A1, A2, A3, ..., An )
+ 操作集:线性表L  List,整数i表示位置,元素X  ElementType,

线性表基本操作主要有:
1. List MakeEmpty():初始化一个空线性表L;
2. ElementType FindKth( int K, List L ):根据位序K,返回相应元素 ;
3. int Find( ElementType X, List L ):在线性表L中查找X的第一次出现位置;
4. void Insert( ElementType X, int i, List L):在位序i前插入一个新元素X;
5. void Delete( int i, List L ):删除指定位序i的元素;
6. int Length( List L ):返回线性表L的长度n。


### 线性表的顺序存储实现
> 利用数组的连续存储空间顺序存放线性表的各元素
> 访问下标为 i 的元素:L.Data[i] 或 PtrL->Data[i]
> 线性表的长度:L.Last+1 或 PtrL->Last+1
```c
typedef struct LNode *List;
struct LNode{
ElementType Data[MAXSIZE];
int Last;
} ;
struct LNode L;
List PtrL;
```

### 主要操作的实现
```c
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last;
};
 
/* 初始化 */
List MakeEmpty()
{
    List L;
 
    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;
 
    return L;
}
 
/* 查找 */
#define ERROR -1
 
Position Find( List L, ElementType X )
{
    Position i = 0;
 
    while( i <= L->Last && L->Data[i]!= X )
        i++;
    if ( i > L->Last )  return ERROR; /* 如果没找到，返回错误信息 */
    else  return i;  /* 找到后返回的是存储位置 */
}
 
/* 插入 */
/*注意:在插入位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是存储下标位置（从0开始），两者差1*/
bool Insert( List L, ElementType X, Position P ) 
{ /* 在L的指定位置P前插入一个新元素X */
    Position i;
 
    if ( L->Last == MAXSIZE-1) {
        /* 表空间已满，不能插入 */
        printf("表满"); 
        return false; 
    }  
    if ( P<0 || P>L->Last+1 ) { /* 检查插入位置的合法性 */
        printf("位置不合法");
        return false; 
    } 
    for( i=L->Last; i>=P; i-- )
        L->Data[i+1] = L->Data[i]; /* 将位置P及以后的元素顺序向后移动 */
    L->Data[P] = X;  /* 新元素插入 */
    L->Last++;       /* Last仍指向最后元素 */
    return true; 
} 
 
/* 删除 */
/*注意:在删除位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是存储下标位置（从0开始），两者差1*/
bool Delete( List L, Position P )
{ /* 从L中删除指定位置P的元素 */
    Position i;
 
    if( P<0 || P>L->Last ) { /* 检查空表及删除位置的合法性 */
        printf("位置%d不存在元素", P ); 
        return false; 
    }
    for( i=P+1; i<=L->Last; i++ )
        L->Data[i-1] = L->Data[i]; /* 将位置P+1及以后的元素顺序向前移动 */
    L->Last--; /* Last仍指向最后元素 */
    return true;   
```



### 线性表的链式存储实现
+ 不要求逻辑上相邻的两个元素物理上也相邻;
+ 通过“链”建立起数据元素之间的逻辑关系。
+ 插入、删除不需要移动数据元素,只需要修改“链”。
```
typedef struct LNode *List;
struct LNode{
ElementType Data;
List Next;
};
struct Lnode L;
List PtrL;
```

### 主要操作的实现
1.求表长
```c
int Length ( List PtrL )
{ 
    List p = PtrL; /* p指向表的第一个结点*/
    int j = 0;
        while ( p ) {
        p = p->Next;
        j++;     /* 当前p指向的是第 j 个结点*/
        }
    return j;
}
//时间性能为 O(n)
```


(1)按序号查找: FindKth;
```c
List FindKth(int K, List Ptr)
{
    List p = Ptr;
    int i = 1;
    while (p!=NULL && i<K) {
        p = p->Next;
        i++;
    }
    if (i == k) return p; /* 找到第K个,返回指针 */
    esle return NULL;     /* 否则返回空
}
//平均时间性能为 O(n)
```

(2)按值查找: Find
```c
List Find(ElementType X, List Ptr)
{
    List p = Ptr;
    while (p!=NULL && p->Data!=X)
        p = p->Next;
    return p;
}
平均时间性能为 O(n)
```


插入(在第 i-1(1≤i≤n+1)个结点后插入一个值为X的新结点)
+ (1)先构造一个新结点,用s指向;
+ (2)再找到链表的第 i-1个结点,用p指向;
+ (3)然后修改指针,插入结点 ( p之后插入新结点是 s)



### 插入操作实现
```c
List Insert(ElementType X, int i, List PtrL)
{
    List p, s;
    if (i == 1) {   /* 新结点插入在表头 */
        s = (List)malloc(sizeof(struct LNode)); /*申请、填装结点*/
        s->Data = X;
        s->Next = PtrL;
        return s;
    }
    p = FindfKth(i-1, PtrL); /* 查找第i-1个结点 */
    if (p == NULL) {         /* 第i-1个不存在,不能插入 */
        printf("参数i错");
        return NULL;
    } else {
        s = (List)malloc(sizeof(struct LNode)); /*申请、填装结点*/
        s->Data = X;
        s->Next = p->Next; /*新结点插入在第i-1个结点的后面*/
        p->Next = s;
        return PtrL;
    }
}
```


### 删除(删除链表的第 i (1≤i≤n)个位置上的结点)
+ (1)先找到链表的第 i-1个结点,用p指向;
+ (2)再用指针s指向要被删除的结点(p的下一个结点);
+ (3)然后修改指针,删除s所指结点;
+ (4)最后释放s所指结点的空间。

删除操作实现
List Delete(int i, List PtrL0
{
    List p, s;
    if (i == 1) { /* 若要删除的是表的第一个结点 */
        s = PtrL; /*s指向第1个结点*/
        if (PtrL != NULL) Ptr = PtrL->Next; /*从链表中删除*/
        else return NULL;
        free(s);
        return PtrL;
    }
    p = FindKth(i-1, PtrL); /*查找第i-1个结点*/
    if (p == NULL) {
        printf(“第%d个结点不存在”, i-1); 
        return NULL;
    } else if (p->Next == NULL) {
        printf(“第%d个结点不存在”, i);
        return NULL;  
    } else {
        s = p->Next;        /*s指向第i个结点*/
        p->next = s->Next;  /*从链表中删除*/
        free(s);            /*释放被删除结点 */
        return PtrL;
    }
}



### 广义表(Generalized List)
+ 广义表是线性表的推广
+ 对于线性表而言, n个元素都是基本的单元素;
+ 广义表中,这些元素不仅可以是单元素也可以是另一个广义表。


```c
typedef struct GNode *GList;
struct GNode{
    int Tag;    /*标志域:0表示结点是单元素,1表示结点是广义表 */
    union {     /*子表指针域Sublist与单元素数据域Data复用,即共用存储空间*/
        ElementType Data;
        GList SubList;
    } URegion;
    GList Next; /* 指向后继结点 */
};
```


### 多重链表
+ 多重链表:链表中的节点可能同时隶属于多个链
+ 多重链表中结点的指针域会有多个,如前面例子包含了Next和SubList两个指针域;
+ 但包含两个指针域的链表并不一定是多重链表,比如在双向链表不是多重链表。
多重链表有广泛的用途:
+ 基本上如树、图这样相对
+ 复杂的数据结构都可以采
+ 用多重链表方式实现存储






