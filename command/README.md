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



  

  
  
--------------------------------------------------------------------------------
# 正则表达式, Linux中的 vi more grep yacc lex awk sed 都支持正则表达式(RE)



###  特殊字符(元字符)
```note
% 正则表达式的特殊字符(元字符), 6个元字符, 其它字符与其自身匹配
  .    *    [    \    ^    $

% 正则表达式的转义
% 用反斜线可以取消特殊字符的特殊含义。
  如:正则表达end\.只与字符串end.匹配

% 单字符正则表达式
% 长的正则表达式由单字符正则表达式构成的, 非特殊字符与其自身匹配
如:正则表达式a与字符串a匹配, b与b,/与/
```



### 转义字符(\)
```note
\. \* \$ \^ \[ \\  ;%正则表达式\*与字符串*匹配,与字符串\*不匹配
% 转义字符后除以上六种之外的不该出现其他字符,例如:不该出现\u,这样
% 的组合被视为undefined(未定义的),后出的软件有可能会有特殊的解释
% 圆点(·),匹配任意单字符
```


### 定义集合(1)
```note
% 单字符正则表达式:定义集合(1)
在一对方括号之间的字符为集合的内容,
如:单字符正则表达式[abcd]与a或b,c,d匹配
圆点,星号,反斜线在方括号内时,代表它们自己
如:[\*.]可匹配3个单字符
```


#### 定义集合(2)
```note
% 单字符正则表达式:定义集合(2)
用减号-定义一个区间
如[a-d] [A-Z] [a-zA-Z0-9]
[][] 集合含左右中括号两个字符
%减号在最后,则失去表示区间的意义,[ad-]只与3个字符匹配

% 用^表示补集
% ^在开头,则表示与集合内字符之外的任意字符匹配
如:[^a-z]匹配任一非小写字母
   [^][]匹配任一非中括号字符
%^不在开头,则失去其表示补集的意义
如:[a-z^]能匹配27个单字符
```



### 表达式的组合(1)
```note
% 单字符正则表达式的组合(1)
串结, 如abc, [A-Z].[0-9]·

% 星号(*)
单字符正则表达式后跟*,匹配此单字符正则表达式的0次或任意多次出现
例:正则表达式12*4
与字符串1234不匹配,与1224,12224,14匹配
% 例: 正则表达式[A-Z][0-9]*
此例中*作用的单字符正则表式为[0-9],代表
    [A-Z]
    [A-Z][0-9]
    [A-Z][0-9][0-9]
    [A-Z][0-9][0-9][0-9],等等
与A,A1,C45,D768匹配,与b64512,T56t不匹配
```



### 表达式的组合(2)
```note
% 单字符正则表达式的组合(2)
例:正则表达式[Cc]hapter *[1-4]
在*号前有一个空格,允许数字1-4之前有多个或者0个空格。可匹配Chapter2, chapter 3等等。

例:正则表达式a\[i] *= *b\[j] *\* *c\[k]
匹配字符串a[i]=b[j]*c[k],容许等号和星号两侧有空格

例:在vi中使用
:1,$s/[0-9]*/xx/g
```



### 锚点:$与^
```note
$ 在尾部时有特殊意义,否则与其自身匹配
例:123$ 匹配文件中行尾的123,不在行尾的123字符不匹配
例:$123与字符串$123匹配
例:.$ 匹配行尾的任意字符

%_________________________________________________
^ 在首部时有特殊意义,否则与其自身匹配

例:^printf匹配行首的printf字符串,不在行首的printf串不匹配

例:Hel^lo与字符串Hel^lo匹配

例:在vi中使用 :10,50s/^//g
删除10-50行的每行行首的4个空格
```



# 正则表达式扩展
```note
% ERE:扩展的正则表达式(ERE)
% PCRE: Perl-compatible regular expression
% 对基本正则表达式( BRE )进行了改进:

% 表示分组:圆括号()
% 表示逻辑运算:表示逻辑“或” 的符号 |
  (xy)* 可匹配空字符串,xy,xyxy,xyxyxy
  (pink|green) 与pink或green匹配
  
% 重复次数定义:与星号地位类似的+和?,限定重复次数 \{m,n\}
*号表示它左边的单字符正则表达式的0次或多次重复
+号表示1次或多次: [0-9]+ 匹配长度至少为1数字串
?表示0次或一次: a?,匹配零个或一个a

% 限定重复次数 \{m,n\},例如:[1-9][0-9]\{6,8\} 7-9位数字,首位非0

% 命名的预定义集合
[[:xdigit:]]十六进制数字
\d数字
\D非数字
比^和$更灵活的锚点定义
例如:寻找一个数字串,但是要求这个数字串不许出现在“合计”两个字之后
```



# grep
```note
% grep在文件中查找字符串, grep(Global regular expression print)
% 语法: grep 模式 文件名列表
举例
grep O_RDWR *.h
ps -ef | grep liang
ls -l / | grep '^d' | wc –l
grep '[0-9]*' shudu.c
grep '[0-9][0-9]*' shudu.c


% egrep 使用扩展正则表达式ERE描述模式,在指定模式方面比grep更灵活, 
% fgrep 快速搜索指定字符串,按字符串搜索而不是按模式搜索。
% grep选项, 查PCRE语法:man pcresyntax
-F, --fixed-strings  Fixed strings (instead of regular expressions)
-G, --basic-regexp   Basic regular expression (BRE)
-E, --extended-r     egexp Extended regular expression (ERE)
-P, --perl-regexp    Perl-compatible regular expression (PCRE)

% grep/fgrep/egrep选项
-n 显示时每行前面显示行号
-v 显示所有不包含模式的行
-i 字母比较时忽略字母的大小写
例:grep -n main *.c
查找含有正则表达式main的行,并打印行号
当文件数超过一个时,除了输出行号,还输出文件名

例: grep -v '[Dd]isable' dev.stat>dev.active
取消文件中所有含有指定模式的行,生成新文件

例:grep -i richard telnos
在文件中检索字符串richard,不顾字母的大小写
```




# sed, 流编辑
```note
sed '命令' 文件名列表
sed –e '命令1' –e '命令2' –e '命令3' 文件名列表
sed -f 命令文件 文件名列表


tail -f pppd.log | sed 's/145\.37\.23\.26/桥西/g'
tail -f pppd.log | sed -f sed.cmd

% 其中 sed.cmd 文件
s/145\.37\.23\.26/桥西/g
s/102\.157\.23\.109/柳荫街/g
s/145\.37\.123\.57/大山子/g
cat pm.txt | sed ‘s/\[[^][]*]//g’


sed:正则表达式替换
模式描述中增加\(和\)
在正则表达式中圆括号,仍然代表它自身,在正则表达式中出现的\(和\)不影响匹配操作
[a-zA-Z_][a-zA-Z0-9_]*->number
\([a-zA-Z_][a-zA-Z0-9_]*\)->number

% 替换字符串中的 \0 \1 \2 ......
举例
s/\([a-zA-Z_][a-zA-Z0-9_]*\)->number/\1->num/g

将日期格式“月-日-年”改为“年.月.日”,
比如:将 04-26-1997替换为1997.04.26使用命令:
s/\([0-9][0-9]\)-\([0-9][0-9]\)-\([0-9][0-9]*\)/\3.\1.\2/g

生成文件改名的命令
[快视频www.kuai-vdo.com]-电视剧《三国演义》中文字幕_1080p高清_央视1994版-69.rmvb
sed 's/.*-\([0-9][0-9]\).rmvb/mv \0 第\1集.rmvb/‘
```






