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
##### export PS1="\[$(tput bold)$(tput setab 0)$(tput setaf 1)\]\u@\h:\w # \[$(tput sgr0)\]"
