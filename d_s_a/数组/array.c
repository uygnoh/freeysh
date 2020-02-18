/* 线性表(Linear List) 由同类数据元素构成有序序列的线性结构
 * 1 表中元素的个数称为线性表的长度 
 * 2 线性表没有元素时，称为空表
 * 3 表的起始位置称表头，表结束位置称为表尾
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 16

/* 创建一个结构体，它里面有2个成员 */
struct node {
	int data[MAXSIZE];
	int last;
};


/* 
 * 定义一个结构体指针函数，作为线性表数组的初始化
 * 再为结构体成员变量装载初始值
 * 并返回这个结构体指针
 */ 
struct node * make_empty()
{
	struct node *head;
	head = (struct node *)malloc(sizeof(struct node));
	head->last = -1;
	return head;
}

/*
 * 给定一个结构体指针
 * 按给定值查找元素，返回下标
 * 
 */
int find_pos(struct node *list, int val)
{
	int i = 0;
	while (i <= list->last && list->data[i] != val) {
		i++;
	}
	if (i > list->last)
		return -1;
	else
		return i;
}

/*
 * 给定一个结构体指针，再指定位置插入数值
 * 并返回是否插入成功
 * (pos(1<=pos<=n+1))位置上插入一个值为val的新元素。
 */
bool insert(struct node *list, int pos, int val)
{
	int i;
	if (list->last == MAXSIZE-1) { //表空间已满不能插入
		printf("list full\n");
		return false;
	}
	if (pos < 1 || pos > list->last+2) { //检查插入位置的合法性;
		printf("iiiegal location\n");
		return false;
	}
	for (i = list->last; i >= pos-1; i--)
		list->data[i+1] = list->data[i]; //将Ai~An倒序向后移动
	list->data[pos-1] = val;                //新元素插入
	list->last++;                       //Last仍指向最后一个元素
	return true;                        //
}

/*
 * 删除（删除表在第pos(1<=pos<=n)个位置上的元素）
 */
bool delete(struct node *list, int pos) 
{
    int i;
    if (pos < 1 || pos > list->last+1) {
        printf("不存在%d个元素", pos);
        return false;
    }

    for (i = pos; i <= list->last; i++)
        list->data[i-1] = list->data[i]; //将Ai+1~An顺序向前移动
    list->last--;                       //last仍指向最后一个元素
    return true;
}


int main(int argc, int *argv[])
{
    struct node *head = make_empty();
    printf("%d\n", head->last);
    insert(head, 1, 123);
    insert(head, 2, 456);
    printf("%d\n", head->data[0]);
    printf("%d\n", head->data[1]);
    printf("%d\n", head->last);
    return 0;
}

