#include <stdio.h>

struct node {
	int data;
	struct node *next;
};


int main(int argc, char *argv[])
{
	struct node a, b, c;
	struct node *ptr, *head;

	a.data = 123;
	b.data = 456;
	c.data = 789;
	head = &a;
	a.next = &b;
	b.next = &c;
	c.next = NULL;

	ptr = head;
	do {
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	} while (ptr != NULL);

	return 0;
}
