### bash命令行提示符修改
```note
如果将以下内容放入 root 的家目录中的 .bashrc 文件中，
你将看到一个黑色背景上的红色的 root 提示符，
清楚地表明你（或其他任何人）应该谨慎行事。
实际上，你应该尽可能避免以 root 用户身份登录，
而是通过 sudo 运行大多数系统管理命令，但这是另一回事。
```
### export PS1="\[$(tput bold)$(tput setab 0)$(tput setaf 1)\]\u@\h:\w # \[$(tput sgr0)\]"
