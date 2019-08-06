#include <stdio.h>
#include <stdlib.h>

typedef int Position;
struct SNode {
	ElementType *Data; /* 存储元素数组 */    
	Positon Top;      /* 栈顶指针 */
	int MaxSize;      /* 堆栈最大容量 */
};

typedef struct SNode *stack;

Stack CreateStack(int MaxSize)
{
	Stack s = (Stack)malloc(sizeof(struct SNode));
	s->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
	s->Top = -1;
	S->MaxSize = MaxSize;
	return s;
}

bool IsFull(Stack s)
{
	return (s->Top == s->MaxSize-1);
}

bool Push(Stack s, ElementType x)
{
	if (IsFull(s)) {
		printf("堆栈满");
		return false;
	} else {
		s->Data[++(s->Top)] = x;
		return true;
	}
}

bool IsEmpty(Stack s)
{
	return (s->Top == -1);
}

ElementType Pop(Stack s)
{
	if (IsEmpty(s)) {
		printf("堆栈空");
		return ERROR;
	} else {
		return (s->Data[s->Top--]);
	}
}
