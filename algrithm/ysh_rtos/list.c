#include "list.h"

void list_init(list_t * const root)
{
    //将索引指针指向
    root->index = (item_t*)&(root->list_end);
    
    //
    root->list_end.next = (item_t*)&(root->list_end);
    
    //
    
}
