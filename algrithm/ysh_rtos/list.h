#ifndef __LIST_H__
#define __LIST_H__

#include "stm32_macro.h"
#include "stm32_config.h"

struct item {
    base_t item_value;
    struct item *next;
    struct item *prev;
    void *owner;
    void *container;
};
typedef struct item item_t;

struct mini {
    base_t mini_value;
    struct mini *next;
    struct mini *prev;
};
typedef struct mini mini_t

struct list {
    base_t number_of_item;
    item_t *index;
    mini_t list_end;
};
typedef struct list list_t;


  
#endif
