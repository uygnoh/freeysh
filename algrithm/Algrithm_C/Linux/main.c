#include <stdio.h>
#include "linux_list.h"

struct Node {
    struct list_head head;
    int value;
};
int main()
{
    struct Node l = {0};
    INIT_LIST_HEAD(&l.head);
    return 0;
}
