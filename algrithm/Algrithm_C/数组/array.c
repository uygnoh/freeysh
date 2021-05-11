#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 16

struct array {
    int data[MAX_SIZE];
    int last;
};
typedef struct array * ptr_arr;


//初始化，创建空的顺序表
ptr_arr make_empty()
{
    ptr_arr ptr;
    ptr = (ptr_arr)malloc(sizeof(struct array));
    ptr->last = -1;
    return ptr;
}


//查找元素的值，返回元素的下标
int find_value(ptr_arr ptr, int value)
{
    int index = 0;

    while (index <= ptr->last && ptr->data[index]!=value)
        index++;

    if (index > ptr->last)
        return -1;
    else
        return index;
    
}

//插入(第pos{1<= pos <=(n+1)}个位置上插入一个值为value的新元素)
void insert_value(ptr_arr ptr, int pos, int value)
{
    int i;

    if (ptr->last == MAX_SIZE-1)
        printf("这个数组已满");
    if (pos < 1 || pos > ptr->last+2)
    {
        printf("插入的位置不合法");
        return;
    }

    for (i = ptr->last; i >= pos-1; i--)
        ptr->data[i+1] = ptr->data[i];
    
    ptr->data[pos-1] = value;
    ptr->last++;

    return;
}


//删除表的第pos{1<= pos <=n}个位置上的元素)
void delete_pos(ptr_arr ptr, int pos)
{
    int i;
    
    if (pos < 1 || pos > ptr->last+1)
    {
        printf("不存在%d个元素", pos);
        return;
    }
    
    for (i = pos; pos <= ptr->last; i++)
        ptr->data[i-1] = ptr->data[i];
        
     ptr->last--;
     
     return;
}



int main(int argc, char *argv[])
{
	ptr_arr ptr;
	ptr = make_empty();
	insert_value(ptr, 1, 123);
	printf("%d   %d\n", ptr->data[0], ptr->last);
	return 0;
}
