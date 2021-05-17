#include <stdio.h>
#include <stdlib.h>

struct list {
    int data;
    struct list *next;
};

/* 静态链表创建实现方法
int main()
{
    struct list list1 = {1, NULL};
    struct list list2 = {2, NULL};
    struct list list3 = {1, NULL};
    
    list1.next = &list2;
    list2.next = &list3;
}
*/

//创建一个链表的头部
//它不存放任何数据
struct list *create_list()
{
    struct list *head_list = (struct list*)malloc(sizeof(struct list));
    head_list->next = NULL;
    return head_list;
}


//创建新的节点
struct list * create_node(int data)
{
    struct list *new_node = (struct list*)malloc(sizeof(struct list));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}


//打印链表的数据
void print_list(struct list *head_list)
{
    struct list *ptr_mov = head_list->next;
    while (ptr_mov)
    {
        printf("%d", ptr_mov->data);
        ptr_mov = ptr_mov->next;
        printf("\n");
    }
}


//在链表的头节点处插入
void insert_list_head(struct list *head_list, int data)
{
    struct list *new_list = create_node(data);
    new_list->next = head_list->next;
    head_list->next = new_list;
}



//指定位置删除
void del_pos(struct list *head_list, int pos_dat)
{
    struct list *pos_node = head_list->next;
    struct list *pos_node_front = head_list;
    if (pos_node == NULL)
    {
        printf("无法删除链表，链表为空\n");
        return;
    }
    else
    {
        while (pos_node->data != pos_dat)
        {
            pos_node_front = pos_node;
            pos_node = pos_node_front->next;
            if (pos_node == NULL)
            {
                printf("未找到指定位置，无法删除\n");
                return;
            }
        }
        
        pos_node_front->next = pos_node->next;
        free(pos_node);
    }
}



int main()
{
    struct list *head_list = create_list();
    insert_list_head(head_list, 1);
    insert_list_head(head_list, 2);
    insert_list_head(head_list, 3);
    print_list(head_list);
    
    del_pos(head_list, 2);
    print_list(head_list);

}




