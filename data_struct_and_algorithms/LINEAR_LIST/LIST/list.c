#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode *List;

struct LNode {
	ElementType Data;
	List Next;
};
