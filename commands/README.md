### bash配置文件位置
```noet
cat /etc/shells ;查看linux下可用的shell

login shell; 登陆shell使用 ysh@localhost:~$ su - alice
{/etc/profile, /etc/bashrc, ~/.profile, ~/.bashrc} ;登陆的shell,这4个文件都执行

nologin shell; 非登陆shell使用 ysh@localhost:~$ su alice
{/etc/bashrc, ~/.bashrc} ;非登陆的shell,它只执行这2个文件

bash shell下的配置文件
/etc/profile                    系统级配置文件*
/etc/bashrc                     系统级配置文件*
~/.profile                      用户级配置文件
~/.bashrc                       用户级配置文件
~/.bash_logout                  离开shell写入~
~/.bash_history                 离开shell写入~
```


### linux文件备份
cp /var/log/messages{, .bak}


### base64
```note
base64,Base64是网络上最常见的用于传输8Bit字节码的编码方式之一
Base64就是一种基于64个可打印字符来表示二进制数据的方法。
可查看RFC2045～RFC2049，上面有MIME的详细规范。

% base64 <<< meimei
% base64 <<< 'meimeito'
```


### bash快捷键
```note
Ctrl+Shift++                    ;增大字体
Ctrl+-                          ;缩小字体：
Ctrl+D                          ;退出bash环境, exit
Ctrl+C                          ;杀死当前进程
Ctrl+R                          ;搜索1个历史命令
Ctrl+A                          ;光标移到行首
Ctrl+E                          ;光标移到行尾
Ctrl+L                          ;清屏
Ctrl+d                          ;删除光标所在字母
Ctrl+b                          ;光标左移
Ctrl+f                          ;光标右移
Ctrl+U                          ;清除光标前至行首的内容
Ctrl+K                          ;清除光标后至行尾的内容
```



### 前台后台控制
```note
 &, nohup, bg, fg, kill %3, jobs

nohup---将程序以忽略挂起信号的方式运行起来(不挂断地运行命令)
% nohup gedit a.c

&  将进程搬到后台运行
bg 将进程搬到后台运行（Background）；
fg 将进程搬到前台运行（Foreground）； 

job-number 指出进程组号，以和 wait、fg、bg 和 kill 命令一起使用。
当和这些命令一起使用时，在作业号前面加上一个“%”（百分号标志）。
```


### kill 命令参数
```note
-l  信号，若果不加信号的编号参数，则使用“-l”参数会列出全部的信号名称
-a  当处理当前进程时，不限制命令名和进程号的对应关系
-p  指定kill 命令只打印相关进程的进程号，而不发送任何信号
-s  指定发送信号
-u  指定用户 
只有第9种信号(SIGKILL)才可以无条件终止进程，其他信号进程都有权利忽略。 
% 下面是常用的信号;     kill -l
SIGHUP          1               终端断线
SIGINT          2               中断（同 Ctrl + C）
SIGQUIT         3               退出（同 Ctrl + \）
SIGKILL         9               强制终止
SIGTERM         15              终止
SIGCONT         18              继续（与STOP相反, fg/bg命令）
SIGSTOP         19              暂停（同 Ctrl + Z）
```


### 输入输出重定向
```note
ysh@debian:~$ ls -l  /dev/std*
lrwxrwxrwx 1 root root 15 3月  14 13:04 /dev/stdin  -> /proc/self/fd/0
lrwxrwxrwx 1 root root 15 3月  14 13:04 /dev/stdout -> /proc/self/fd/1
lrwxrwxrwx 1 root root 15 3月  14 13:04 /dev/stderr -> /proc/self/fd/2

>file_name_ok, >>file_name_ok            ;重定向正确输出到文件file_name_ok中
2>file_name_err, 2>>file_name_err        ;重定向错误输出到文件file_name_ok中
&>file_name                              ;正确输出和错误输出重定向到file_name中
&>/dev/null                              ;正确输出和错误输出重定向到/dev/null中

2>&1                                     ;将标准错误输出重定向到标准输出
% nohup java -jar app.jar >log 2>&1 &
% 每次都写”>log 2>&1”太麻烦，能简写吗？
% 简写方式:   &>log

<, <<;输入重定向(覆盖,append)     >, >>;输出重定向(覆盖,append)    
<<;两个小于号连在一起表示接受一个输入结束的标识，当输入这个标识是结束输入
% cat </etc/passwd >a.password          ;把/ect/passwd文件重定向到a.password
```




### bash逻辑判断
```note
command1 && command2 ;只有在 && 左边的命令返回真（命令返回值 $? == 0），&& 右边的命令才会被执行
command1 || command2 ;只有在 || 左边的命令返回假（命令返回值 $? == 1），|| 右边的命令才会被执行
% ping -c3 www.baidu.com &>/dev/null && echo "is up" || echo "is down"
```






### 命令行参数的三种风格
```note
% 类似dd命令的风格
% 特点: 命令行参数采用param=value的风格
  dd if=sysdisk.img of=/dev/sdb
          
% 用dd命令将硬盘映像拷贝到硬盘:if指定输入文件,of指定输出文件
% 用dd命令,生成512KB测试数据文件test.dat。
% 命令行参数中:if,of,bs,count分别
% 指定输入文件,输出文件,块大小(block size),以及块计数
  dd if=/dev/urandom of=test.dat bs=1024 count=512

% 类似find和gcc的风格
% 特点:  以减号打头的一个由多个字符构成的单词用作选项
% 将所有扩展名.c的普通文件由Windows文本格式转为Linux格式
  find src -name ’*.c’ -type f -exec dos2unix --keepdate {} \;

% 编译C语言源程序文件mytest.c并生成C程序与汇编代码对比的列表信息
  gcc -O0 -Wall -g -masm=intel -Wa,-ahl -c shudu.c
  
  

% 类似ls和grep的风格:现今流行的格式
% 特点:长选项与短选项,有的选项同时有两种格式,也有的选项仅有长格式或仅有短格式
% 例如:ls(其中-w选项指定一个整数参数值告知ls排版时屏幕的列宽度)
  ls --classify --all --size --human-readable --width=80 /home/jiang 长选项

% 多个选项挤在一起
  ls -Fashw80 /home/jiang
  
% 多个选项分开
  ls -F -a -s -h -w 80 /home/jiang

% 可以把选项放到后面
% 用独立的命令行参数--显式地标识选项结束
% 选项的处理统一由C语言标准动态链接库libc.so中库函数getopt_long()完成
  ls -F -w80 /home/jiang -has
```



  

  
  






