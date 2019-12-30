#include <stdio.h>
struct student {
	int num;
	float score;
	struct student *next;
};
int main(void)
{
	struct student a, b, c, *head, *p;
	a.num = 123;	a.score = 55.78;
	b.num = 456;	b.score = 88.78;
	c.num = 789;	c.score = 95.78;

	head = &a;
	a.next = &b;
	b.next = &c;
	c.next = NULL;

	p = head;
	do {
		printf("%d, %5.1f\n", p->num, p->score);
		p = p->next;
	} while (p != NULL);

	return 0;
}
