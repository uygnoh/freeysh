##### alias
+ 列出文件大小
    `alias lt='ls --human-readable --size -1 -S --classify'`
+ 增加一个复制进度条
    `alias cpv='rsync -ah --info=progress2'`

+ 手动去除这些行尾的空格是一件头大的事情，但对于sed来说不过是举手之劳
 `sed 's/[ \t]*$//g' your_code.c`


##### bash命令行提示符修改
+ 如果将以下内容放入 root 的家目录中的 .bashrc 文件中，你将看到一个黑色背景上的红色的 root 提示符
+ 清楚地表明你（或其他任何人）应该谨慎行事。实际上，你应该尽可能避免以 root 用户身份登录
+ 而是通过 sudo 运行大多数系统管理命令，但这是另一回事。
`export PS1="\[$(tput bold)$(tput setab 0)$(tput setaf 1)\]\u@\h:\w # \[$(tput sgr0)\]"`




