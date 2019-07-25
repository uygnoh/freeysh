### ======================================================= https
% http://www.netsurf-browser.org/
% http://zensites.net/fvwm/guide/index.html
% http://blog.sina.com.cn/s/blog_8ea8e9d50102v1zn.html
ranger
Xorg
Fvwm
gvim ->vim-gnome
xterm




### ======================================================= redshift
% http://jonls.dk/redshift/
% sudo apt-get install redshift


redshift -b 0.5 -O 5500




%Example (location is Copenhagen, Denmark):
$ redshift -l 55.7:12.6 -t 5700:3600 -g 0.8 -m randr -v

Configuration file
A configuration file can be created, but the documentation is a bit sparse. 
You’ll have to create it manually and put it in ~/.config/redshift.conf. 
The following is an example of a configuration file:

; Global settings for redshift
[redshift]
; Set the day and night screen temperatures
temp-day=5700
temp-night=3500

; Enable/Disable a smooth transition between day and night
; 0 will cause a direct change from day to night screen temperature.
; 1 will gradually increase or decrease the screen temperature.
transition=1

; Set the screen brightness. Default is 1.0.
;brightness=0.9
; It is also possible to use different settings for day and night
; since version 1.8.
;brightness-day=0.7
;brightness-night=0.4
; Set the screen gamma (for all colors, or each color channel
; individually)
gamma=0.8
;gamma=0.8:0.7:0.8
; This can also be set individually for day and night since
; version 1.10.
;gamma-day=0.8:0.7:0.8
;gamma-night=0.6

; Set the location-provider: 'geoclue', 'geoclue2', 'manual'
; type 'redshift -l list' to see possible values.
; The location provider settings are in a different section.
location-provider=manual

; Set the adjustment-method: 'randr', 'vidmode'
; type 'redshift -m list' to see all possible values.
; 'randr' is the preferred method, 'vidmode' is an older API.
; but works in some cases when 'randr' does not.
; The adjustment method settings are in a different section.
adjustment-method=randr

; Configuration of the location-provider:
; type 'redshift -l PROVIDER:help' to see the settings.
; ex: 'redshift -l manual:help'
; Keep in mind that longitudes west of Greenwich (e.g. the Americas)
; are negative numbers.
[manual]
lat=48.1
lon=11.6

; Configuration of the adjustment-method
; type 'redshift -m METHOD:help' to see the settings.
; ex: 'redshift -m randr:help'
; In this example, randr is configured to adjust screen 1.
; Note that the numbering starts from 0, so this is actually the
; second screen. If this option is not specified, Redshift will try
; to adjust _all_ screens.
[randr]
screen=1




### ======================================================= redshift配置
% 切换到 ~/.config 目录下，并新建文件 redshift.conf，配置内容如下：

[redshift]
; 白天屏幕温度
temp-day=5800
; 夜晚屏幕温度
temp-night=4600
; 昼夜是否平滑过度(1/0)
transition=1
; 全局屏幕亮度
;brightness=0.9
; 昼夜屏幕亮度(version >= 1.8)
brightness-day=0.9
brightness-night=0.7
; 屏幕gamma
gamma=0.9
; 位置提供方式(redshift -l list)
location-provider=manual
; 调整工具(redshift -m list)
adjustment-method=randr

; 屏幕调整工具设置
[randr]
; 第1 块屏幕(0)
screen=0

[manual]
; 位置提供方式设置
; 经纬度(北京)
lat=39.90
lon=116.41
### ======================================================= redshift 开机自启
% 切换到 /etc/systemd/user 目录下，新建文件 redshift.service，配置内容如下：

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



% 对于新创建的 unit 文件或修改了的 unit 文件，要通知 systemd 重载此配置文件：
systemctl daemon-reload


% 然后以用户级别启动开机自启服务：
systemctl --user enable redshift.service


% 开启/停止/重启
% 像其他用户服务一样使用：
systemctl --user start redshift.service     开启
systemctl --user stop redshift.service      停止
systemctl --user restart redshift.service   重启




### =======================================================rox-filer，文件管理器











