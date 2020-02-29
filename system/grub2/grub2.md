### grub2对硬盘编码的定义
```note
    (hd0,1)         #默认语法, 由grub2自动判断分区格式
    (hd0,msdos1)    #此硬盘的分区为传统的MBR模式
    (hd0,gpt1)      #此硬盘的分区为GPT模式
    
硬盘以”hd“表示，后面会接一组数字; 以搜索顺序作为硬盘的编号(这个概念很重要!)
第1个搜索到的硬盘编号为”0“号，第2个搜索到的硬盘编号为”1“号，以此类推
每颗硬盘的第1个分区编号为”1“， 依序类推
```


### grub2的配置文件
```note
#grub2自动写入命令1->update-grub
#grub2自动写入命令2->grub-mkconfig -o /boot/grub/grub.cfg
#使用grub2自动写入命令它会依次读取/etc/default/grub文件, /etc/grub.d目录下的文件
#最后grub2自动写入命令会把这些文件全部整合到->/boot/grub/grub.cfg文件中
#grub2的默认配置文件为/boot/grub/grub.cfg,它由grub2自动写入命令生成，不要修改它！
/boot/grub/grub.cfg 


#该文件定义的是grub2的全局宏，修改内置的宏可以快速生成grub2的配置文件
#在/et/default/grub中，使用”key=value“的格式
#key全部为大写字母，value如果包含有空格或特殊字符，则需要使用引号包围
ysh@localhost:~$ vim /etc/default/grub


#/etc/grub.d/该目录包含以下脚本文件
#00_header,     05_debian_theme,        10_linux,       20_linux_xen
#30_os-prober,  30_uefi-firmware,       40_custom,      41_custom
ysh@localhost:~$ cd /etc/grub.d
```






