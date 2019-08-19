### 操作系统安装相关知识
+ 打开电源 
+ 不停按系统热键<F2>
+ 进入BIOS进行设定

### Legacy BIOS
+ Basic Input Output System             <基本输入输出系统>
+ Legacy Support    [Disable]           <legacy是传统BIOS>

### EFI BIOS
+ EFI <Extensible Firmware Interface>         <可扩展固件接口>
+ EFI BIOS是用模块化，C语言风格的参数堆栈传递方式，动态链接的形式构建的系统
+ EFI在概念上非常类似于一个低阶的操作系统，并且具有操控所有硬件资源的能力

### UEFI
+ UEFI<Unified Extensible Firmware Interface> <统一的可扩展固件接口> 
+ 是一种详细描述全新类型接口的标准。这种接口用于操作系统自动从预启动的操作环境，
+ 加载到一种操作系统上，从而使开机程序化繁为简，节省时间

### UEFI Boot Order
+ 进入UEFIbios系统后， 选择需要引导的设备， 把它设置为第1个位置

### 开启U盘启动->“USB Boot”
+ 进Boot/Startup这项目中的“USB Boot”要更改为 “Enabled”,(一般的主板默认开启)

### Secure Boot
+ Secure Boot       [Disabled]
+ Secure Boot只是UEFI的一个部分。两者的关系是局部与整体的关系
+ Secure Boot的目的，是防止恶意软件侵入
```
+ 微软强行部署Secure Boot
它的做法就是采用密钥。UEFI规定，主板出厂的时候，可以内置一些可靠的公钥。
然后，任何想要在这块主板上加载的 操作系统或者硬件驱动程序，都必须通过这些公钥的认证。
也就是说，这些软件必须用对应的私钥签署过，否则主板拒绝加载。
由于恶意软件不可能通过认证，因此 就没有办法感染Boot。
这个设想是好的。但是，UEFI没规定哪些公钥是可靠的，也没规定谁负责颁发这些公钥，
都留给硬件厂商自己决定。现在，微软就是要求，主板厂商内置Windows 8的公钥。
```


### MBR GPT esp分区 FAT分区
+ MBR分区列表支持最大2TB硬盘
```
MBR（Master Boot Record）：即硬盘的主引导记录分区列表，
在主引导扇区，位于硬盘的cylinder 0， head 0， sector 1 （Sector是从1开始的）
```
+ GPT分区列表支持最大128PB(1PB=1024TB)
```
GUID磁盘分区表（GUID Partition Table，缩写：GPT）其含义为“全局唯一标识磁盘分区表”
它是可扩展固件接口（EFI）标准（被Intel用于替代个人计算机的BIOS）的一部分，
被用于替代BIOS系统中的一64bits来存储逻辑块地址和大小信息的主开机纪录（MBR）分区表
```

+ esp分区, EFI系统分区，即 EFI system partition，简写为 ESP。
```
ESP虽然 是一个 FAT16 或 FAT32 格式的物理分区，但是其分区标识是 EF (十六进制) 而非常规的 0E 或 0C。
因此，该分区在 Windows 操作系统下一般是不可见的。分区内存放引导管理程序、驱动程序、系统维护工具等。
支持 EFI 模式的电脑需要从 ESP 启动系统，EFI 固件可从 ESP 加载 EFI 启动程序和应用程序。

ESP是一个独立于操作系统之外的分区，操作系统被引导之后，就不再依赖它。
这使得 ESP 非常适合用来存储那些系统级的维护性的工具和数据，
比如：引导管理程序、驱动程序、系统维护工具、系统备份等，
甚至可以在 ESP 里安装一个特殊的操作系统（SlaTaz Linux? PuppyLinux? Win PE?）
```

+ FAT分区与通用性
```
EFI 规范规定 ESP 使用 FAT 格式。尽管这种老旧的格式有很多局限性，但也不算一无是处。
尤其开发者来说，系统中有个 FAT32 分区是很好的，因为经常使用多个系统，包括 Windows、Linux、FreeBSD，
而这些系统都能安全地访问 FAT 分区，因此，可以把各个系统的启动相关的文件包括启动管理程序等放到 ESP 里，
而且，这也方便在一个系统中去修改另一个系统的启动文件，至少可以把 ESP 当作各个系统的公共交换空间.
```


