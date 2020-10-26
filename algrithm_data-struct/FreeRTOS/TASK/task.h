#ifndef __TASK_H
#define __TASK_H

typedef struct tskTaskControlBlock {
    volatile StackType_t *pxTopOfStack;
    ListItem_t xStateListItem;
    StackType_t *pxStack;
    char pcTaskName[16];
}tskTCB;
typedef tskTCB TCB_t;



#endif
