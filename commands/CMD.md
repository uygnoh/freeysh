##### 系统可用的shell
+ cat /etc/shells

##### 登陆的shell
+ login shell; 登陆shell使用 ysh@localhost:~$ su - alice
+ {/etc/profile, /etc/bashrc, ~/.profile, ~/.bashrc} ;登陆的shell,这4个文件都执行

##### 非登陆的shell
+ nologin shell; 非登陆shell使用 ysh@localhost:~$ su alice
+ {/etc/bashrc, ~/.bashrc} ;非登陆的shell,它只执行这2个文件

##### bash shell下的配置文件位置
+ /etc/profile    系统级配置文件*
+ /etc/bashrc     系统级配置文件*
+ ~/.profile      用户级配置文件
+ ~/.bashrc       用户级配置文件
+ ~/.bash_logout  离开shell写入~
+ ~/.bash_history 离开shell写入~

##### linux文件备份 
+ cp /var/log/messages{, .bak}

##### base64
+ Base64是网络上最常见的用于传输8Bit字节码的编码方式之一
+ Base64就是一种基于64个可打印字符来表示二进制数据的方法

##### 输入输出重定向 <ls -l  /dev/std*>
+ <, <<;输入重定向(覆盖,append) or >, >>;输出重定向(覆盖,append)
+ cat </etc/passwd >a.password ;把/ect/passwd文件重定向到a.password
+ 1>file_name_ok  ;重定向正确输出到文件file_name_ok中
+ 2>file_name_err ;重定向错误输出到文件file_name_ok中
+ &>file_name     ;正确输出和错误输出重定向到file_name中
+ &>/dev/null     ;正确输出和错误输出重定向到/dev/null中
+ 2>&1            ;将标准错误输出重定向到标准输出
+ nohup java -jar app.jar >log 2>&1 &
`每次都写”>log 2>&1”太麻烦，能简写吗？ 简写方式:   &>log`

##### bash逻辑判断
+ command1 && command2
`只有在 && 左边的命令返回真（命令返回值 $? == 0），&& 右边的命令才会被执行`
+ command1 || command2
`只有在 || 左边的命令返回假（命令返回值 $? == 1），|| 右边的命令才会被执行`
+ ping -c3 www.baidu.com &>/dev/null && echo "is up" || echo "is down"

##### 命令行参数的风格
+ dd if=sysdisk.img of=/dev/sdb
+ find src -name ’*.c’ -type f -exec dos2unix --keepdate {} \;
+ gcc -O0 -Wall -g -masm=intel -Wa,-ahl -c shudu.c
+ ls --classify --all --size --human-readable --width=80 /home/jiang 
+ ls -Fashw80 /home/jiang
+ ls -F -a -s -h -w 80 /home/jiang
+ ls -F -w80 /home/jiang -has




  

  
  






