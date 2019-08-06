### Inxi是一个可以获取完整的系统和硬件详情信息的命令行工具
% sudo apt-get install inxi
% sudo apt install hardinfo
% sudo apt install lshw lshw-gtk
1. 硬件
2. CPU
3. 磁盘驱动器
4. Xorg
5. 桌面环境
6. 内核
7. GCC版本
8. 进程
9. 内存占用
0. 和其他有用的信息


### Linux查看硬件信息命令大全
1. 查看服务器型号、序列号
root@localhost:~# dmidecode|grep "System Information" -A9|egrep  "Manufacturer|Product|Serial"

2. 查看主板型号
root@localhost:~# dmidecode |grep -A16 "System Information$"

3. 查看BIOS信息
root@localhost:~# dmidecode -t bios


4. 查看内存槽及内存条
root@localhost:~# dmidecode -t memory | head -45 | tail -23

5. 查看网卡信息
root@localhost:~# dmesg | grep -i Ethernet

6. 查看pci信息，即主板所有硬件槽信息
root@localhost:~# lspci | head -10


### 查看CPU信息
1. 查看cpu型号
root@localhost:~# cat /proc/cpuinfo | grep name | cut -f2 -d: | uniq -c

2. 查看系统中实际物理CPU的数量（物理）
root@localhost:~# grep 'physical id' /proc/cpuinfo | sort | uniq | wc -l

3. 系统中实际物理CPU的数量（核数）
root@localhost:~# cat /proc/cpuinfo |grep 'processor'|wc -l

4. 查看每个物理CPU中core的个数(即核数)
root@localhost:~# cat /proc/cpuinfo |grep "cores"|uniq 

5. 查看CPU的主频
root@localhost:~# cat /proc/cpuinfo |grep MHz|uniq

6. 查看CPU的详细信息
root@localhost:~# cat /proc/cpuinfo | head -20

7. 查看CPU的相关信息
root@localhost:~# lscpu

8. 查看cpu运行模式
root@localhost:~# getconf LONG_BIT

9. 查看cpu是否支持64bit
(结果大于0, 说明支持64bit计算. lm指long mode, 支持lm则是64bit)
root@localhost:~# cat /proc/cpuinfo | grep flags | grep ' lm ' | wc -l




### 查看内存信息

1. 查看内存硬件信息
root@localhost:~# dmidecode -t memory | head -45 | tail -24

2. 最大支持多少内存
root@localhost:~# dmidecode|grep -P 'Maximum\s+Capacity'

3. Linux 查看内存的插槽数,已经使用多少插槽.每条内存多大
root@localhost:~# dmidecode | grep -A5 "Memory Device" | grep Size | grep -v Range

4. Linux 查看内存的频率
root@localhost:~# dmidecode|grep -A16 "Memory Device"|grep 'Speed'

5. Linux 查看内存的详细信息：
root@localhost:~# cat /proc/meminfo |head -20

6. Linux 查看内存的使用情况
free -m    // -b,-k,-m,-g show output in bytes, KB, MB, or GB


### 查看硬盘信息
1. 查看挂接的分区状态
root@localhost:~# fdisk -l |grep Disk

2. 查看硬盘和分区分布
root@localhost:~# lsblk

3. 查看硬盘和分区的详细信息
root@localhost:~# fdisk -l

4. 查看挂接的分区状态
root@localhost:~# mount | column -t

5. 查看挂接的分区状态
root@localhost:~# swapon -s

6. 查看硬盘使用情况
root@localhost:~# df -hT

7. 硬盘检测命令smartctl



### 查看网卡信息
1. 查看网卡硬件信息
root@localhost:~# lspci | grep -i 'eth'

2. 查看系统的所有网络接口
root@localhost:~# ip link show

3. 列出所有PCI设备信息
root@localhost:~# lspci -tv | more

4. 查看网卡的驱动
lspci |grep -i eth


















