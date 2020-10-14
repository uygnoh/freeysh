#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 16
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;

struct LNode {
	ElementType Data[MAXSIZE];
	Position Last;
};

List MakeEmpty()
{
	List L;
	L = (List)malloc(sizeof(struct LNode));
	L->Last = -1;
	return L;
}

#define ERROR -1
Position Find(List L, ElementType X)
{
	Position i = 0;
	while (i <= L->Last && L->Data[i] != X) {
		i++;
	}
	if (i > L->Last)
		return ERROR;
	else
		return i;
}

bool Insert(List L, ElementType X, Position P)
{
	Position i;
	if (L->Last == MAXSIZE-1) {
		printf("list full");
		return false;
	}
	if (P<0 || P>L->Last+1) {
		printf("iiiegal location");
		return false;
	}
	for (i=L->Last; i>=P; i--)
		L->Data[i+1] = L->Data[i];
	L->Data[P] = X;
	L->Last++;
	return true;
}

bool Delete(List L, Position P)
{
	Position i;
	if (P<0 || P>L->Last) {
		printf("位置%d不存在元素", P);
	}
	for (i=P+1; i<=L->Last; i++)
		L->Data[i-1] = L->Data[i];
	L->Last--;
	return true;
}

int main(int argc, char *argv[])
{
	List L;
	L = MakeEmpty();
	Insert(L, 123, 0);
	printf("%d   %d\n", L->Data[0], L->Last);
	return 0;
}
