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


static void prvInitialiseNewTask(TaskFunction_t pxTaskCode,             /* 任务入口 */
                                 const char * const pcName,             /* 任务名称，为字符串形式 */
                                 const unit32_t ulStackDepth,           /* 任务栈大小，单位为字 */
                                 void * const pvParameters,             /* 任务形参 */
                                 TaskHandle_t * const pxCreatedTask,    /* 任务句柄 */
                                 TCB_t *pxNewTCB)                       /* 任务控制块指针 */
{
    StackType_t *pxTopOfStack;
    UBaseType_t x;
    
    /* 获取栈顶地址 */
    pxTopOfStack = pxNewTCB->pxStack + ( ulStackDepth - ( uint32-t )1 );
    
    /* 将栈顶指针向下做8字节对齐 */
    pxTopOfStack = ( StackType_t * ) \
                   ( ( (uint32_t)pxTopOfStack ) & ( ~( (uint32_t)0x0007 ) ) );
                   
    /* 将任务名称存储在TCB中 */         
    for ( x = (UBaseType_t)0; x < (UfBaseType_t)configMAX_TASK_NAME_LEN; x++ )
    {
        pxNewTCB->pcTaskName[ x ] = pcName[ x ];
        if ( pcName[ x ] == 0x00;
        {
            break;
        }
    }
    
    /* 任务名称的长度不能超过configMAX_TASK_NAME_LEN, 并以'\0'结尾 */
    pxNewTCB->pcTaskName[ configMAX_TASK_NAME_LEN - 1 ] = '\0';
    
    /* 初始化TCB中的xStateListItem节点，即初始化该节点的链表为空，表示节点还没有插入任何链表 */
    vListInitialiseItem( &(pxNewTCB->xStateListItem) );
    
    /* 设置xStateListItem节点的拥有者，即拥有这个节点本身的TCB */
    listSET_LIST_ITEM_OWNER( &(pxNewTCB->xStateListItem), pxNewTCB );
    
    /* 调用pxPortInitialiseStack()函数初始化任务栈，并更新栈顶指针
       任务第一次运行的环境参数就存在任务栈中
    */
    pxNewTCB->pxTopOfStack = pxPortInitialiseStack( pxTopOfStack,
                                                    pxTaskCode,
                                                    pvParameters );
                                                    
    if ( (void*)pxCreatedTask != NULL )
    {
        *pxCreatedTask = (TaskHandle_t)pxNewTCB;
    }
}


static void prvTaskExitError( void )
{
    /* 函数停在这里 */
    for (;;);
}
StackType_t * pxPortInitialiseStack( StackType_t *pxTopOfStack,
                                     TaskFunction_t pxCode,
                                     void *pvParameters )
{
    /* 异常发生时，自动加载到CPU寄存器中的内容 */
    pxTopOfStack--;
    *pxTopOfStack = portINITIAL_XPSR;
    pxTopOfStack--;
    *pxTopOfStack = ( (StackType_t)pxCode ) & portSTART_ADDRESS_MASK;
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )prvTaskExitError;
    pxTopOfStack--;
    pxTopOfStack -= 5; /* r12, r3, r2, r1默认初始化为0 */
    *pxTopOfStack = ( StackType_t )pvParameters;
    
    /* 异常发生时，手动加载到CPU寄存器中的内容 */
    pxTopOfStack -= 8;
    
    /* 返回栈顶指针， 此时 pxTopOfStack 指向空栈 */
    return pxTopOfStack;
}                                     











