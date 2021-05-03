### ======================================================= https
% http://www.netsurf-browser.org/
% http://zensites.net/fvwm/guide/index.html
% http://blog.sina.com.cn/s/blog_8ea8e9d50102v1zn.html
### ======================================================= Xorg
+ xorg是X11的一个实现，而X Window System是一个C/S结构的程序，
+ Xorg只是提供了一个X Server，负责底层的操作当你运行一个程序的时候，
+ 这个程序会连接到X server上，由X server接收键盘鼠标输入和负责屏幕输出窗口的移动，
+ 窗口标题的样式等等。

### ======================================================= fvwm
+ fvwm是一个X11的窗口管理器，设计理念为减少内存消耗，提供3D外观和虚拟桌面。
+ FVWM是ICCCM兼容的，它的开发很活跃，支持也很优秀。
+ FVWM是一种非常优秀的窗口管理器，一旦配置完成便可以长久使用。
+ Fvwm是完全支持EWMH特性的一个WM，可以让你取得软件窗口特性的全部控制权。
+ 比如，如果你想让任意软件窗口达到quake-console
+ [著名的quake控制台模式，使用`热键唤出或隐藏窗口]的操作方式，
+ 在Fvwm的配置里面，写上2、3句话就可以了。

### ======================================================= xterm
xterm， 轻量级字符终端
w3m, w3m是个开放源代码的文字式网页浏览器

### ======================================================= rox-filer
rox-filer，轻量级的文件管理器
ranger，   字符终端下的文件管理器
gvim，     图形界面的vim
nano,

===============================================================================
###  redshift
+ http://jonls.dk/redshift/
+ sudo apt-get install redshift
+ 设置屏幕亮度
`redshift -b 0.5 -O 5500`


+ redshift开机自启 `vim /etc/systtemd/user/redshift.service`
+ 切换到 /etc/systemd/user 目录下，新建文件 redshift.service，配置内容如下
```note
[Unit]
Description=Redshift display colour temperature adjustment
Documentation=http://jonls.dk/redshift/
After=display-manager.service

[Service]
Environment=DISPLAY=:0
ExecStart=/usr/bin/redshift
Restart=always
RestartSec=20

[Install]
WantedBy=default.target
```


+ 对于新创建的 unit 文件或修改了的 unit 文件，要通知 systemd 重载此配置文件
systemctl daemon-reload

+ 然后以用户级别启动开机自启服务
systemctl --user enable redshift.service

+ 开启/停止/重启; 像其他用户服务一样使用
systemctl --user start redshift.service     开启
systemctl --user stop redshift.service      停止
systemctl --user restart redshift.service   重启
===============================================================================















