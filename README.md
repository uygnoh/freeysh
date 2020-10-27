### 常用学习网站 
+ https://github.com/uygnoh/FREEYSH
+ https://www.runoob.com/           <菜鸟教程>
+ https://stackoverflow.com/        <软件类问答网站>
+ https://www.ostechnix.com/category/linux-basics/
+ https://www.3cschool.com



### 命令行终端字体大小调整
+ Maximum     ->ctrl+shift++
+ Minimum     ->ctrl+-
+ F11         ->全屏



### gnome3快捷键
```
.................................................
.                                               . 
. F2            ;Grub2                          .
. F11			;Screen Full                    .
. Super+L		;Lock Screen                    .
. Super+H		;Hide window                    .
. Super+Up		;Maximize window                .
. Super+Left    ;View split on left             .
. Super+right   ;View split on right            .
.                                               .
. Alt+F2		;Show the run command prompt    .
. Alt+F4		;Close window                   . 
. Alt+Tab       ;Browser Switching              .
.                                               .
. Ctrl+Shitf++  ;Increase font size             .
. Ctrl+-        ;Decrease font size             .
. Ctrl+7        ;turn terminal                  .
. Ctrl+H        ;Display hidden files           .
. Ctrl+C        ;Keyboard interrupt             .
. Ctrl+D        ;echo <<-EOF                    .
. Ctrl+Z        ;Stop the process[background]   .   
. Ctrl+/        ;Send SIGQUIT 3 [foreground]    .
. Ctrl+S        ;Interrupt console output       .
. Ctrl+Q        ;Recovery console output        .
. Ctrl+L        ;clear                          .
. Ctrl+Tab      ;Window Switching               .
.................................................
```



### tmux终端复用软件
+ <crtl  +a>           #激活控制台(系统默认Ctrl+b)
+ <shift +上下左右箭头>#窗口(window)切换
+ <alt   +上下左右箭头>#窗格(pane)切换
+ <ctrl  +b h>         #窗格(pane)，水平方向创建窗格 <%>Split the current panel into two, left and right.
+ <ctrl  +b v>         #窗格(pane)，垂直方向创建窗格 <">Split the current panel into two, top and bottom.
+ <ctrl  +b &>         #kill the current window
+ <cttrl +b x>         #Kill the current pane.
+ <ctrl  +b s>         #Select a new session for the attached client interactively.
+ <ctrl  +b w>         #Choose the current window interactively.
+ <ctrl  +b z>         #Toggle zoom state of the current panel.

tmux会话
+ tmux new-session -s <session_name>              #创建一个会话
+ tmux list-sessions                              #查看会话	
+ tmux detach                                     #分离会话     <d>Detach the current client.
+ tmux attach-session -t <target_session_name>    #连接会话
+ tmux rename-session -t session_old session_new  #重命名会话    <$>Rename the current session.
+ tmux kill-server                                #关闭tmux服务器
+ tmux kill-server -t session_name                #关闭指定的会话
+ tmux kill-server -a -t session_name             #关闭所有会话，除了这个会话<session_name>
+ <ctrl+a (>                                      #Switch the attached client to the previous session.
+ <ctrl+a )>                                      #Switch the attached client to the next session.

tmux窗口
+ tmux new-window      #创建一个新的 window
+ tmux list-windows    #列出当前窗口
+ <ctrl+a , >          #重命明当前窗口
+ <ctrl+a c >          #创建一个新窗口
+ <ctrl+a & >          #关闭当前窗口
+ <ctrl+a l >          #前后窗口间互相切换



### vim文本编辑器 
+ vim左括号加自动换行   "inoremap { {}<ESC>i<CR><ESC>O  <第一种方案>
+ 数组则不换行         "inoremap { {}<ESC>i            <第二种方案>
+ 函数左括号加回车则换行 "inoremap {<CR> {<CR>}<ESC>O    <第二种方案>
+ 补充说明：
`这样改还是有点小问题，当定义一个函数时，先敲入左括号，`
`如果约一秒钟内没有敲入回车键再敲入回车键就不会进行回车换行了。不过影响不大`



### 编码风格
+ 宏或者常量所有用大写  #define MAXLENGTH 10;  const int MAXLENGTH = 10；
+ 函数名或者类名用     do_something
+ 变量名用            do_something


##### swithc-case if-else
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
    
    if (condition)      
        action();       /* 如果只有一行语句，则不需要用花括号 */
    if (condition) {    /* 如果是多分支语句，则需要保持一致，使用花括号 */
        do_this();      
        do_that();
    } else {
        otherwise();
    }

}

+ 使用空格缩进为: “4个空格”
+ switch ... case ...语句中，switch和case具有相同的缩进（参考上文）
+ 花括号的使用参考K&R风格
+ 如果是函数，左花括号另起一行, 否则, 花括号紧接在语句的最后
+ 空格, 在关键字“if, switch, case, for, do, while”之后需要加上空格，如：
    `if (something)`
+ 在关键字“sizeof, typeof, alignof, or __attribute__”之后不要加空格，如：
    `sizeof(struct file)`
+ 在括号里的表达式两边不要加空格，比如，下面是一个反面的例子： 《ERROR》
    `sizeof( struct file ) warnings... `
+ 大多说的二元和三元运算符两边需要空格，
   `如“= + - < > * / % | & ^ <= >= == != ? :”；`
+ 一元运算符后面不要空格，
   `如“& * + - ~ ! sizeof typeof alignof __attribute__ defined”；`
+ 在前缀自增自减运算符之后和后缀自增自减运算符之前不需要空格（“++”和“--”）；
+ 成员运算符（“.”和“->”）的两边不需要空格；
+ 行尾不需要空格；
+ 注释, 使用C89的“/* ... */”风格.
+ 对于多行注释，可以参考下例：
+ 多行的宏定义需要用“do .. while”封装，如：
```c
    #define macrofun(a, b, c)   \
    do {                        \
        if (a == 5)             \
            do_this(b, c);      \
    } while (0)
```

```

