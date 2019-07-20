#include <stdio.h>
#include <stdlib.h>

// 创建链表节点结构
struct node {
    int data;
    struct node* next;
};



// 创建一个链表的头
struct node* create_node(int data) {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = data;
    head->next = NULL;
    return head;
}



//在链表尾部插入一个节点，返回头结点
struct node* insert(struct node* head, int data) {
    struct node* add = create_node(data); 
    if (head == NULL) {
        return add;
    }
    struct node* tail = head;
    while (tail->next != NULL)
        tail = tail->next;
    tail->next = add;
    return head;
}



// 查找节点值，返回节点指针
struct node* search(struct node* head, int data) {
    if (head == NULL || head->data == data) //节点为空，或者头结点就是要找的节点
        return head;
    struct node* p = head->next; //p指向第2个节点，如果有的话
    while ( p != NULL) {
        if (p->data == data) //找到
            return p;
        p = p->next;
    }
    
    return NULL; //没有找到，返回空
}



//删除节点值
struct node* delete(struct node* head, int data) {
    if (head == NULL)
        return head;
    if (head->data == data) { //要删除的节点是头节点
        struct node* p = head->next;
        free(head); //释放节点内存 
        return p;   //第2个节步作为头节点返回
    }
    struct node *p1, *p2;
    p1 = head;
    p2 = head->next;
    while (p2 != NULL) { //寻找节点，p1指向删除节点的前一个节点，p2指向要删除的节点
        if (p2-data == data)
            break;
        p1 = p2;
        p2 = p2->next;
    }
    if (p2 != NULL && p2->data == data) {
        p1->next = p2-next; //删除节点p2,并且将链表连接起来
        free(p2);
    }
    return head; //返回头节点
}



//释放链表
void destroy(struct node* head) {
    if (head != NULL) { //递归释放内存
        destroy(head->next);
        free(head);
    }
}



void print(struct node* head) {
    struct node* p = head;
    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}



int main(int argc, char **argv) {

    struct node* head = NULL;
    head = insert(head, 2);
    head = insert(head, 3);
    print(head);
    struct node* s = search(head, 2);
    if (s != NULL)
        printf("find it: %d\n", s->data);        
    head = delete(head, 3);
    print(head);
    destroy(head);
    head = NULL;
    return 0;
}



