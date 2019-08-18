##### https://github.com/uygnoh/free_doc
##### https://www.runoob.com/           <菜鸟教程>
##### https://tv.sohu.com/v/cGwvOTI5MDc1MS85ODUwNjE2MC5zaHRtbA==.html   <cortex-m>
##### https://stackoverflow.com/        <软件类问答网站>

### 字体大小调整
+ Maximum     ->ctrl+shift++
+ Minimum     ->ctrl+-
+ F11         ->全屏

### tmux
+ <shift +上下左右箭头>  #窗口(window)切换
+ <alt   +上下左右箭头>  #窗格(pane)切换
+ <ctrl  +b h>         #窗格(pane)，水平方向创建窗格 %
+ <ctrl  +b v>         #窗格(pane)，垂直方向创建窗格 "
+ <ctrl  +b z>         #全屏窗格(pane)
+ 会话
+ <crtl+a   >                                     #激活控制台(系统默认Ctrl+b)
+ <ctrl+a s >                                     #会话切换     s
+ tmux new-session -s <session_name>              #创建一个会话
+ tmux list-sessions                              #查看会话	
+ tmux detach                                     #分离会话     d
+ tmux attach-session -t <target_session_name>    #连接会话
+ tmux rename-session -t session_old session_new  #重命名会话    $
+ tmux kill-server                                #关闭tmux服务器
+ tmux kill-server -t session_name                #关闭指定的会话
+ tmux kill-server -a -t session_name             #关闭所有会话，除了这个会话<session_name>
+ 窗口
+ tmux new-window                                 #创建一个新的 window
+ <ctrl+a , >                                     #重命明当前窗口
+ <ctrl+a c >                                     #创建一个新窗口
+ <ctrl+a & >                                     #关闭当前窗口
+ <ctrl+a l >                                     #前后窗口间互相切换
+ tmux list-windows                               #列出当前窗口

### vim
`inoremap { {}<ESC>i<CR><ESC>O`
```
---数组则不换行
inoremap { {}<ESC>i
---函数左括号加回车则换行
inoremap {<CR> {<CR>}<ESC>O
补充：这样改还是有点小问题，当定义一个函数时，先敲入左括号，如果约一秒钟内没有敲入回车键，
     再敲入回车键就不会进行回车换行了。不过影响不大。
```

# 计算机语言编码风格 @freeysh<201908022150> 
```noet
计算机语言命名规则
****************************************************************
宏或者常量用所有大写  #define MAXLENGTH 10;  const int MAXLENGTH = 10；
函数名或者类名用 do_something
变量名用 do_something
****************************************************************
```
### swithc-case if-else
```c
void print_msg(int a)
{
    switch (a) {
    case 1:
        printf("a == 1\n");
        break;
    case 2:
        printf("a == 2\n");
        break;
    }
    if (x is true) {
        we do y
    }

    if (condition)      /* 如果只有一行语句，则不需要用花括号 */
        action();

    if (condition) {    /* 但是，对于条件语句来说，如果一个分支是一行语句，*/
        do_this();      /* 另一个分支是多行，则需要保持一致，使用花括号： */
        do_that();
    } else {
        otherwise();
    }

}
```
### 一些需要注意的代码风格
1. 使用空格缩进为: “4个空格”
2. switch ... case ...语句中，switch和case具有相同的缩进（参考上文）
3. 花括号的使用参考K&R风格
4. 如果是函数，左花括号另起一行, 否则, 花括号紧接在语句的最后
5. 空格, 在关键字“if, switch, case, for, do, while”之后需要加上空格，如：
    `if (something)`
6. 在关键字“sizeof, typeof, alignof, or __attribute__”之后不要加空格，如：
    `sizeof(struct file)`
7. 在括号里的表达式两边不要加空格，比如，下面是一个反面的例子：
    `sizeof( struct file ) warnings... `
8. 大多说的二元和三元运算符两边需要空格，
   `如“= + - < > * / % | & ^ <= >= == != ? :”；`
9. 一元运算符后面不要空格，
   `如“& * + - ~ ! sizeof typeof alignof __attribute__ defined”；`
10. 在前缀自增自减运算符之后和后缀自增自减运算符之前不需要空格（“++”和“--”）；
11. 成员运算符（“.”和“->”）的两边不需要空格；
12. 行尾不需要空格；
13. 注释, 使用C89的“/* ... */”风格.
14. 对于多行注释，可以参考下例：
```note
/*
 * This is the preferred style for multi-line
 * comments in the Linux kernel source code.
 * Please use it consistently.
 *
 * Description: A column of asterisks on the left side,
 * with beginning and ending almost-blank lines.
 */
```
15. 多行的宏定义需要用“do .. while”封装，如：
```c
    #define macrofun(a, b, c)   \
    do {                        \
        if (a == 5)             \
            do_this(b, c);      \
    } while (0)
```







