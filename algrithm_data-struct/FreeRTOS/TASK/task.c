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


/*
参数          	功能
pvTaskCode	    任务是简单的C函数，永远不会退出，因此，通常被实现为一个无限循环。
                pvTaskCode参数只是一个指针，指向实现任务的函数(实际上就是函数名)。
            
pcName	        任务的描述性名称。这主要用于方便调试，但也可以用于调用xTaskGetHandle()来获得任务句柄。
                应用程序定义的常量configMAX_TASK_NAME_LEN以字符定义名称的最大长度—包括空终止符。
                提供的字符串长度超过这个最大值将导致字符串被自动截断。
            
ulStackDepth	puxStackBuffer参数用于将StackType_t变量数组传递给xTaskCreateStatic()。
                ulStackDepth必须设置为数组中索引的数量。
                
pvParameters	任务函数接受类型为“指针指向void”(void*)的参数。分配给pvParameters的值将是传递给任务的值。
                此参数具有类型“指针指向void”，以允许任务参数有效地、间接地通过强制转换接收任何类型的参数。
                例如，可以将整数类型传递到任务函数中，方法是在任务创建时将该整数类型转换为void指针，
                然后将void指针参数转换回任务函数定义本身中的整数。
                
uxPriority	    定义任务执行的优先级。优先级可以从0(最低优先级)分配到(configMAX_PRIORITIES - 1)(最高优先级)。
                configMAX_PRIORITIES是一个用户定义的常量。
                如果configUSE_PORT_OPTIMISED_TASK_SELECTION设置为0然后没有上限的优先级数量可用
                (除了使用的数据类型的极限和可用的RAM单片机),
                但建议使用所需的最低数量的优先级,以避免浪费内存。
                传递上面的uxPriority值(configMAX_PRIORITIES - 1)将导致分配给任务的优先级被静默封顶为最大合法值。
                
puxStackBuffer	必须指向至少具有ulStackDepth索引的StackType_t变量数组(请参阅上面的ulStackDepth参数)。
                数组将被用作已创建任务的堆栈，因此必须是持久的(不能在函数创建的堆栈框架中声明，
                也不能在任何其他可以在应用程序执行时合法覆盖的内存中声明)。
                
pxTaskBuffer	必须指向类型为StaticTask_t的变量。该变量将用于保存创建的任务的数据结构(TCB)，
                因此它必须是持久的(不是在函数创建的堆栈框架中声明的，也不是在应用程序执行时可以合法覆盖的任何其他内存中声明的)。

% 返回值	        意义
None	        无法创建任务，因为puxStackBuffer或pxTaskBuffer为空
Any other value	如果返回一个非空值，则创建任务，返回的值是创建的任务的句柄。
*/





