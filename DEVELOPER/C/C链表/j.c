/*
 * 1.创建结构体类型,为创建结构体变量做准备
 * 2.创建一个链表的头，但不存放有效数据[此时已创建了一个结构体变量]
 * 3.创建新节点，为链表在插入做准备
 * 4.链表节点插入
 * 5.链表节点的遍历
 */    
#include <stdio.h>
#include <stdlib.h>

/* 创建一个结构体类型，它有2个成员 */
struct node {
	int data;
	struct node *next;
};

/* 创建一个链表的头 */
struct node *create_list()
{
	/* head 成了结构体变量 */
	struct node *head_node = (struct node *)malloc(sizeof(struct node));
	head_node->next = NULL;
	return head_node;
}

/* 创建节点 */
struct node *create_node(int data)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

/* 头插法，    参数：插入那个节点，插入节点的数据 */
void insert_node_head(struct node *head_node, int data)
{
	struct node *new_node = create_node(data);
	new_node->next = head_node->next;
	head_node->next = new_node;
}

/* 指定位置删除 */
void delete_node_pos(struct node *head, int data)
{
	struct node *pos = head->next;
	struct node *pos_prev = head;
	if (pos == NULL)
		printf("链表为空，无法删除！");
	else
	{
			while (pos->data != data)
			{
				pos_prev = pos;
				pos = pos_prev->next;
				if (pos == NULL)
				{	
					printf("没有找到相关信息");
					break;
				}
			}
			pos_prev->next = pos->next;
			free(pos);
	}

}


/* 打印节点内容 */
void print_list(struct node *head_node)
{
	struct node *traversal = head_node->next;
	while (traversal)
	{
		printf("%d,", traversal->data);
		traversal = traversal->next;
	}
	printf("\n");
}


int main(void)
{
	struct node *list = create_list();
	insert_node_head(list, 1);
	insert_node_head(list, 2);
	insert_node_head(list, 3);
	insert_node_head(list, 4);
	print_list(list);
	delete_node_pos(list, 3);
	print_list(list);
	return 0;
}



