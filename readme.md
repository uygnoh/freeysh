# https://github.com/uygnoh
# https://github.com/uygnoh/free_doc @最新


### 列出系统的服务
`systemctl --type=service`

### 列出SSH服务状态 
`systemctl status sshd.service`
`systemctl is-active sshd.service`

### 切换当前运行目标,该命令仅更改当前运行目标，对下次启动无影响
`systemctl isolate graphical.target` 

### 用 systemctl 检查当前的默认启动目标
```note
systemctl get-default
systemctl list-dependencies | grep target
systemctl list-dependencies graphical.target | grep target
```


### 用 systemctl 修改系统的运行级别
`systemctl set-default multi-user.target`



### grub2修改启动顺序, 表示要启动的第3个操作系统
`grub-set-default 2` 


### 启动进入救援状态（单用户状态）
`sudo systemctl rescue`


### systemctl
```note
systemctl start <unit>        立即激活单元
systemctl stop <unit>         立即停止单元
systemctl restart <unit>      重启单元
systemctl reload <unit>       重新加载配置
systemctl status <unit>       输出单元运行状态
systemctl is-enable <unit>    检查单元是否配置为自动启动
systemctl enable <unit>       开机自动激活单元
systemctl enable --now <unit> 设置单元为自动启动并立即启动这个单元
systemctl disable <unit>      取消开机自动激活单元
systemctl mask <unit>         禁用一个单元（禁用后，间接启动也是不可能的）： 
systemctl unmask <unit>       取消禁用一个单元
systemctl help <unit>         显示单元的手册页（必须由单元文件提供）
systemctl daemon-reload       重新载入 systemd 系统配置，扫描单元文件的变动
systemctl reboot              重启
systemctl poweroff            退出系统并关闭电源
systemctl suspend             待机
systemctl hibernate           休眠
systemctl hybrid-sleep        混合休眠模式（同时休眠到硬盘并待机）
```




### bash命令行提示符修改
```note
如果将以下内容放入 root 的家目录中的 .bashrc 文件中，
你将看到一个黑色背景上的红色的 root 提示符，
清楚地表明你（或其他任何人）应该谨慎行事。
实际上，你应该尽可能避免以 root 用户身份登录，
而是通过 sudo 运行大多数系统管理命令，但这是另一回事。
```
`export PS1="\[$(tput bold)$(tput setab 0)$(tput setaf 1)\]\u@\h:\w # \[$(tput sgr0)\]"`




### alias
列出文件大小
    `alias lt='ls --human-readable --size -1 -S --classify'`
增加一个复制进度条
    `alias cpv='rsync -ah --info=progress2'`


# 计算机语言编码风格 @freeysh

### 命名规则 <201908022150>
+ 手动去除这些行尾的空格是一件头大的事情，但对于sed来说不过是举手之劳
 `sed 's/[ \t]*$//g' your_code.c`
+ Linux命名规则
```noet
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
>  如“= + - < > * / % | & ^ <= >= == != ? :”；
9. 一元运算符后面不要空格，
>  如“& * + - ~ ! sizeof typeof alignof __attribute__ defined”；
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







