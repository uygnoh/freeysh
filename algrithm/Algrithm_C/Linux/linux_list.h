#ifndef __LINUX_LIST_H__
#define __LINUX_LIST_H__

//include <linux/types.h>
struct list_head {
    struct list_head *next, *prev;
};

struct hlist_head {
    struct hlist_node *first;
};

struct hlist_node {
    struct hlist_node *next, **pprev;
};


//include <linux/stddef.h>
#ifndef offsetof
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#endif
#ifndef container_of
#define container_of(ptr, type, member) (\
    (type *)( (char *)ptr - offsetof(type, member) ))
#endif

//include <linux/poison.h>
#define LIST_POISON1 (NULL)
#define LIST_POISON2 (NULL)


//include <linux/prefetch.h>
#define prefetch(x) ((void)x)



#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define LIST_HEAD(name) \
    struct list_head name = LIST_HEAD_INIT(name)

static void INIT_LIST_HEAD(struct list_head *list)
{
    list->next = list;
    list->prev = list;
}


static void list_add(struct list_head *new, struct list_head *head)
{
    __list_add(new, head, head->next);
}
static void __list_add(struct list_head *new,
                        struct list_head *prev,
                        struct list_head *next)
{
    next->prev = new;
    new->next  = next;
    new->prev  = prev;
    prev->next = new;
}


void list_del(*entry)
{
    __list_del(entry->prev, entry->next);
    entry->next = LIST_POISON1;
    entry->prev = LIST_POISON2;
}
void __list_del(*prev, *next)
{
    next->prev = prev;
    prev->next = next;
}






















#endif
