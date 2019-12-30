
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 16

/* 创建一个结构体，它里面有2个成员 */
struct node {
	int data[MAXSIZE];
	int last;
};

/* 创建一个结构体指针变量，并为其申请内存空间，
 * 再为结构体成员变量装载初始值
 * 并返回这个结构体指针变量 
 */ 
struct node *list make_empty()
{
	struct node *list head;
	head = (struct node *list)malloc(sizeof(struct node)):
	head->last = -1;
	return head;
}

/*
 * 按给定值查找元素，返回下标
 * 判断i如果小于工
 */
int find_pos(struct node *list, int val)
{
	int i = 0;
	while (i <= list->last && list->data[i] != val) {
		i++;
	}
	if (i > list->last)
		return false;
	esle
		return true;
}

bool insert(struct node *list, int val, int pos)
{
	int i;
	if (list->last == MAXAIZE-1) {
		printf("list full\n");
		return false;
	}
	if (pos < 0 || pos > list->last+1) {
		printf("iiiegal location\n");
		return false;
	}
	for (i = list->last; i >= pos; i--)
		list->data[i+1] = list->data[i];
	list->data[p] = val;
	list->last++;
	return true;
}

bool delete(struct node *list, int pos)
{

}
