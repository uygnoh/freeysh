### 1 
gentoo@livecd ~ $ sudo su -
livecd ~ # parted -a optimal /dev/dsa
% (parted) print
% (parted) mklabel gpt
% (parted) unit MB
% (parted) mkpart primary 1 20
% (parted) name 1 grub
% (parted) set 1 bios_grub on
% (parted)
% (parted) mkpart primary 21 500
% (parted) name 2 boot
% (parted) mkpart primary 501 8501
% (parted) name 3 swap
% (parted) mkpart primary 8501 -1
% (parted) name 4 root
% (parted)
% (parted) quit

livecd ~ # mkfs.ext2 /dev/sda2 
livecd ~ # mkfs.ext4 /dev/sda4
livecd ~ # mkswap /dev/sda3
livecd ~ # swapon /dev/sda3
livecd ~ # 
livecd ~ # mount /dev/sda4 /mnt/gentoo/
livecd ~ # mkdir /mnt/gentoo/boot
livecd ~ # mount /dev/sda2 /mnt/gentoo/boot
livecd ~ # 



### 2 
livecd ~      # cd /mnt/gentoo/
livecd gentoo # links https://www.gentoo.org/downloads/
livecd gentoo # tar xvjpf stage3-amd64-xxx.tar.bz2



### 3
可选：选择境像站点
为了能更快的下载源代码，这里推荐选择一个快的镜像。
Portage将会在make.conf文件中查找GENTOO_MIRRORS变量，并使用其中所列的镜像。
可以通过浏览Gentoo镜像列表搜索一个（或一组）最接近系统物理位置（往往那是最快的）的镜像。
另外，我们提供一个叫作mirrorselect的好工具，它为用户选择所需镜像提供了一个很好的交换。
只需要移动光标选择镜像并按Spacebar选择一个或多个镜像。
root #mirrorselect -i -o >> /mnt/gentoo/etc/portage/make.conf

Gentoo ebuild 软件仓库
选择镜像的第二个重要步骤是通过/etc/portage/repos.conf/gentoo.conf文件来配置Gentoo的 ebuild 软件仓库。
这个文件包含了更新Portage数据库（包含Portage需要下载和安装软件包所需要的信息的一个ebuild和相关文件的集合）所需要的同步信息。
通过几个简单的步骤就可以完成软件仓库的配置。首先，如果它不存在，则创建repos.conf目录：
% root #mkdir --parents /mnt/gentoo/etc/portage/repos.conf

接下来，复制Portage提供的Gentoo仓库配置文件到这个（新创建的）目录：
% root #cp /mnt/gentoo/usr/share/portage/config/repos.conf /mnt/gentoo/etc/portage/repos.conf/gentoo.conf
使用一个文件编辑器或通过使用cat命令来看一眼。文件里的内容应该是.ini格式并且看起来像是这样： 




### 4 
**复制DNS信息**
livecd gentoo # cp --dereference /etc/resolv.conf /mnt/gentoo/etc/


**挂载必要的文件系统**
root #mount --types proc /proc /mnt/gentoo/proc
root #mount --rbind /sys /mnt/gentoo/sys
root #mount --rbind /dev /mnt/gentoo/dev
[root #mount --make-rslave /mnt/gentoo/dev ]
[root #mount --make-rslave /mnt/gentoo/sys ]

**进入新环境**
root #chroot /mnt/gentoo /bin/bash
env-update
root #source /etc/profile
root #export PS1="(chroot) ${PS1}"



(chroot) livecd / # ls /usr/share/zoneinfo
(chroot) livecd / # cp /usr/share/zoneinfo/Asia/Shanghai /etc/localtime
(chroot) livecd / # eselect profile list

(chroot) livecd / # eselect profile set 3
(chroot) livecd / # cd /etc

(chroot) livecd etc # echo "127.o.0.1 localhost gentoo" >hosts
(chroot) livecd etc # sed -i -e 's/hostname.*/hostname="ysh"/' conf.d/hostname
(chroot) livecd etc #
(chroot) livecd etc #



(chroot) livecd etc # emerge gentoo-sources
(chroot) livecd etc # emerge genkernel
(chroot) livecd etc # emerge genkernel all

(chroot) livecd etc # nano -w /fstab


(chroot) livecd etc # cd init.d

(chroot) livecd init.d # ln -s net.lo net.enp0s3
cd ../conf.d

(chroot) livecd conf.d # echo 'configenp0s3="192.168.1.10 netmask 255.255.255.0\
brd 192.168.1.255"' >>net

(chroot) livecd conf.d # echo 'routes_enp0s3="default via 192.168.1.1" >>net
(chroot) livecd conf.d # ehco 'hostname="ysh"' >hostname
(chroot) livecd conf.d # rc-update add net.enp0s3 default
passwd

emerge dhcpcd
rc-update add dhcpcd default















### 5
(chroot) livecd / # mkdir /usr/portage
(chroot) livecd / # emerge-webrsync
(chroot) livecd / # eselect profile list
(chroot) livecd / # eselect profile set 8



### 6
**更新@world集合**
在这一点上，明智的做法是更新系统的 @world set ，以便可以构建系统。
当系统应用了任何升级，或从 任何profile 构建了stage3 后，应用了变化的 use 标记时，下一步是“必要”的。
root #emerge --ask --verbose --update --deep --newuse @world


### 7
**配置USE变量**
默认的USE设置全放在了系统所使用的Gentoo配置文件的make.defaults文件中。
Gentoo对它的配置文件们使用了一个（复杂的）继承系统，在这个阶段我们不去深入。
最简单的检查当前活动的USE标记的办法是运行emerge --info并选择以USE开头的那一行：
root #emerge --info | grep ^USE
USE="X acl alsa amd64 berkdb bindist bzip2 cli cracklib crypt cxx dri ..."
可以在系统的 /var/db/repos/gentoo/profiles/use.desc 中找到可用的USE标记的完整描述。
root #less /var/db/repos/gentoo/profiles/use.desc
作为示例，我们展示一个支持DVD、ALSA,以及CD录制的基于KDE系统的USE设置：
root #nano -w /etc/portage/make.conf

### /etc/portage/make.conf为支持DVD、ALSA和CD录制的基于KDE系统启用USE
USE="-gtk -gnome qt5 kde dvd alsa cdr"
当USE在/etc/portage/make.conf中定义，会从那个默认列表中添加（或者移除，如果USE标记以-号开头的话）。

用户想忽略所有默认的USE设置并完全由自己管理的话，应该在make.conf中定义USE以-*开头：
### /etc/portage/make.conf忽略默认USE标记
USE="-* X acl alsa "



### 8
**系统选择时区**
chroot -] livecd / # cd /usr/share/zoneinfo/
chroot -] livecd zoneinfo # ls
chroot -] livecd zoneinfo # cd Asia
chroot -] livecd zoneinfo # echo "Asia/Shanghai" > /etc/timezone

**配置地区**
大多数用户只想在他们的系统上使用一或两个地区。
Locales 不只是指定用户应该使用与系统进行交互的语言,
同时也指定了字符串排序，日期和时间的显示等规则。
系统应该支持的地区应该在/etc/locale.gen中提到
root #nano -w /etc/locale.gen
下一步是运行locale-gen。它将生成/etc/locale.gen文件中指定的所有地区
要验证所选择的地区当前可用，运行locale -a。
等完成后，我们就来设定系统级别的区域设置。我们又一次使用eselect来做这件事，现在使用locale模块。
通过eselect locale list可显示可用的目标： 
通过eselect locale set VALUE可以设定正确的地区：
root #eselect locale set 8

**现在重新加载环境**
root #env-update && source /etc/profile && export PS1="(chroot) $PS1"



 
### 9
emerge gentoo-sources
emerge genkernel
time genkernel all





### 10 

nano -w /etc/fstab
/dev/sda2 /boot ext2 defaults,noatime 0 2
/dev/sda4 /     ext4 noatime          0 1
/dev/sda3 none  swap sw               0 0


nano -w /etc/conf.d/hostname
hostname="gentoo"

nano -w /etc/hosts
127.o.0.1 localhost gentoo










### 11 
emerge dhcpcd
rc-update add dhcpcd default

emerge syslog-ng
rc-update add syslog-ng default
emerge cronie
rc-update add cronie default

passwd
useradd -m -G users, wheel,audio,lp,cdrom,portage,cron -s /bin/bash ysh
passwd ysh

emerge sys-boot/grub
grub-install /dev/sda
grub-mkconfig -o /boot/grub/grub.cfg



### 12 
### 13 
### 14 
### 15
### 16 
