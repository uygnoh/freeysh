#include "tash.h"

TaskHandle_t xTaskCreateStatic(TaskFunction_t pxTaskCode,           /* 任务的入口，任务函数名称 */
                               const char * const pcName,           /* 任务名称，以字符串形式 */
                               const uint32_t ulStackDepth,         /* 任务栈大小，单位为字 */
                               void * const pvParameters,           /* 任务形参 */
                               StackType_t * const puxStackBuffer,  /* 任务栈起始地址 */
                               TCB_t * const pxTaskBuffer)          /* 任务控制块指针 */
{
    TCB_t *pxNewTCB;                                                
    TaskHandle_t xReturn;                                           /* 定义一个任务句柄 */
    
    if ( ( pxTaskBuffer != NULL ) && ( puxStackBuffer != NULL ) )
    {
        pxNewTCB = ( TCB_t * ) pxTaskBuffer;
        pxNewTCB->pxStack = ( StackType_t * ) puxStackBuffer;
        
        /* 创建新的任务 */
        prvInitialiseNewTask(pxTaskCode,                            /* 任务入口 */
                             pcName,                                /* 任务名称，以字符串形式 */
                             ulStackDepth,                          /* 任务栈大小，单位为字 */
                             pvParamters,                           /* 任务形参 */
                             &xReturn,                              /* 任务句柄 */
                             pxNewTCB);                             /* 任务栈起始地址 */  
    }
    else
    {
        xReturn = NULL;
    }
    
    return xReturn;
}


static void prvInitialiseNewTask(TaskFunction_t pxTaskCode,
                                 const char * const pcName,
                                 const unit32_t ulStackDepth,
                                 void * const pvParameters,
                                 TaskHandle_t * const pxCreatedTask,
                                 TCB_t *pxNewTCB)
{
    StackType_t *pxTopOfStack;
    UBaseType_t x;
    
    pxTopOfStack = pxNewTCB->pxStack + ( ulStackDepth - ( uint32-t )1 );
    
    pxTopOfStack = ( StackType_t * ) \
                   ( ( (uint32_t)pxTopOfStack ) & ( ~( (uint32_t)0x0007 ) ) );
                   
    for ( x = (UBaseType_t)0; x < (UfBaseType_t)configMAX_TASK_NAME_LEN; x++ )
    {
        pxNewTCB->pcTaskName[ x ] = pcName[ x ];
        if ( pcName[ x ] == 0x00;
        {
            break;
        }
    }
    
    pxNewTCB->pcTaskName[ configMAX_TASK_NAME - 1 ] = '\0';
    
    vListInitialiseItem( &(pxNewTCB->xStateListItem) );
    
    listSET_LIST_ITEM_OWNER( &(pxNewTCB->xStateListItem), pxNewTCB );
    
    pxNewTCB->pxTopOfStack = pxPortInitialiseStack( pxTopOfStack,
                                                    pxTaskCode,
                                                    pvParameters );
                                                    
    if ( (void*)pxCreatedTask != NULL )
    {
        *pxCreatedTask = (TaskHandle_t)pxNewTCB;
    }
}









