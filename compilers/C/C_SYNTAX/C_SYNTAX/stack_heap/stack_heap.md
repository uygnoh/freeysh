### stack based memory
+ 生存期由函数决定
+ 特点
1. 由编译器自动分配释放，无需程序员管理
2. 生长方向向下
3. 分配效率高
4. 无碎片问题

### heap based memory
+ 生存期由程序员决定
+ 特点
1. 程序员不释放，会造成内存泄漏(memory leakage)
2. 生长方向向上
3. 分配效率低
4. 频繁申请/释放易造成内存碎片(heap fragmentaiton)
