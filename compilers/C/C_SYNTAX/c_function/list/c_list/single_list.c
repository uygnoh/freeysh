
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
//创建一个链表头 
struct node *list_head(void);

//新建链表节点
struct node *new_node(int data);

//链表插入节点方法(头插法)
void insert_node_head(struct node *head, int data);



struct node *list_head(void)
{
	struct node *head = (struct node*)malloc(sizeof(struct ndoe));
	head->next = NULL;
	return head;
}


struct node *new_node(int data)
{
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->data = data;
	new->next = NULL;
	return new;
}


void insert_node_head(struct node *head, int data)
{
	struct node *new = create_new_node(data);
	new->next = head->next;
	head->next = new;
}
