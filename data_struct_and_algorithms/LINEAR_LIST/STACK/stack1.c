#include <stdio.h>
#include <stdlib.h>

typedef struct SNode *PtrToSNode;
struct SNode {
	ElementType Data;
	PtrToSNode next;
}
typedef PtrToSNode Stack;

Stack CreateStack()
{
	/* 构建一个堆栈的头节点，返回该结点指针 */
	Stack s;
	s = (Stack)malloc(sizeof(struct Snode));
	s->Next = NULL;
	return s;
}

boll IsEmpty(Stack s)
{
	return (s->Next == NULL);
}

bool Push(Stack s, ElementType x)
{
	PtrToSNode TmpCell;
	TmpCell = (PtrTOSNode)malloc(sizeof(struct SNode));
	TmpCell->Data = x;
	TmpCell->Next = s->Next;
	s->Next = TmpCell;
	return true;
}

ElementType Pop(Stack s)
{
	PTrToSNode FirstCell;
	ElementType TopElem;
	if (IsEmpty(s)) {
		printf("堆栈空");
		return ERROR;
	} else {
		FirstCell = s->Next;
		TopElem = FirstCell->Data;
		s->Next = FirstCell->Next;
		free(FristCell);
	}
}

