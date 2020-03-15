/**
  此前接触过AVR单片机，发现无论是书店里面的教材，还是网上一大堆的中文资料，
  无一例外都是说windows下使用WinAVR、ICCAVR之类的，Linux方面的简直只字不提，
  难道这就是传说中的中国国情？外国情况可很不一样，玩单片机的Geek一般都很哈Linux，
  做单片机开发的软件一应俱全，当然还是开源的。
  昨天从淘宝重新买了条USB的下载线，回来一看是USBasp的设计，附送的光盘当然也是win下的驱动和说明了，忽略。
  插上下载器，lsusb，认倒是认出来了，叫做VOIT，那怎么用呢？上网一搜，
  原来USBasp是德国人的设计http://www.fischl.de/usbasp/，GPL的，
  其中提到AVRDUDE支持USBasp，当然也有源码下载。
  不过我用的是Ubuntu，发挥超级牛力的时候到了：sudo apt-get install avrdude，恩，几秒钟搞定，让他们去编译吧！
  Linux下做单片机开发当然首选GCC，就如这些英文教程说的，下载源码？No，No，APT has Super Cow Powers，继续
%  sudo apt-get install gcc-avr binutils-avr avr-libc

  几分钟装完，很好，估计那些下载源码回来编译的同学要去喝两个小时茶才能用了。
  万事俱全，先写个单片机的HelloWorld，借用micahcarrick的源码：
*/
    #define F_CPU 1000000UL /* 1 MHz CPU clock */

    #include <util/delay.h>
    #include <avr/io.h>

    int
    main (void)
    {
    DDRC = _BV (PC0); /* PC0 is digital output */

    while (1) /* loop forever */
    {
    /* set PC0 on PORTC (digital high) and delay for 500mS */
    PORTC &= ~_BV(PC0);
    _delay_ms(500);

    /* PC0 on PORTC (digital 0) and delay for 500mS */
    PORTC |= _BV(PC0);
    _delay_ms(500);
    }

    return (0);
    }
/**
    ....保存为toggle_led.c
    命令时间：
    avr-gcc -mmcu=atmega48 -Wall -Os -o toggle_led.o toggle_led.c
    是不是似曾相识？平时用gcc就这么用的，这里除了把gcc改成avr-gcc，没多大区别。
    -mmcu定义了目标CPU的类型，我用的是atmega48；-Os是优化选项，减少程序的大小。这就是传说中的交叉编译。
    接着把目标代码翻译成可以烧录到芯片上的hex文件：
    avr-objcopy -j .text -j .data -O ihex toggle_led.o toggle_led.hex
    
    avr-objcopy的-j参数限定转换的程序段，-O设定hex的输出格式，ihex即Intel Hex file
    [Update: 本例子中，-j .data这个选项没作用，因为.data区根本没有数据；
    .data是存放初始化数组、字符串等数据的段，如果程序用到了，记得加上]
    
    
    搞定，开烧：
    sudo avrdude -p m48 -c usbasp -e -U flash:w:toggle_led.hex
    
    因为直接读写USB接口，所以不给权限的话会提示找不到编程器，当然配置USB权限最好，
    这里暂时用sudo。avrdude的-p指定目标CPU，-c指定下载器，如果不知道所用的下载器是什么型号，
    敲avrdude -c会列出所有支持的下载器型号及其描述。-e即烧录前清空，-U参数指定刷写类型以及刷写文件。
    [Update：可参考virtualbox使用usb的配置，把当前用户加入usbfs组，就可以直接使用avrdude了]
    回车后下载器的指示灯闪了下，跟着单片机上的小灯开始闪烁，Hi, Hello World.
    当然问题不是完全没有，我用avrdude下载完后默认的校验老是无法通过，说读取错误，只好加个-V来跳过校验。可能跟个别机器有关。
    当然实际开发很少这样敲一大堆命令来编译程序，一般都用Make搞定。
    对比起Win下满是GUI的程序，我第一次接触WinAVR都搞了半天，如何如何配置一个Project，
    哇那个属性窗口真让人眼花缭乱，使用gcc来开发，则可以循序渐进，未了解到的参数就不用，简洁，明了，但不失其功能强大。 

于是就试了一下lsusb，倒是认出来了
    Bus 004 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub
    Bus 001 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
    Bus 005 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub
    Bus 003 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub
    Bus 002 Device 003: ID 16c0:05dc VOTI
    Bus 002 Device 002: ID 062a:0000 Creative Labs Optical mouse
    Bus 002 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub 
不过是VOTI，猜测可能是作者写错了，不管他，按照作者的方法，装上avrdude(sudo apt-get install avrdude)，
我没来的及编译程序，直接用以前编译好的，准备烧录

作者的烧录命令
sudo avrdude -p m48 -c usbasp -e -U flash:w:toggle_led.hex

我那是老单片机，m8515，也不知还支持不，就改成下面这个样子
sudo avrdude -p m8515 -c usbasp -e -U flash:w:todo.hex

todo.hex是开发板自带的程序，输入密码，然后板子上的小灯闪了起来，很快烧录完毕，程序正常运行
没想到这么简单就把程序烧进了单片机，这下能彻底脱离windows了，虽然我已经不再搞单片机，但还是很高兴
关于程序的编译，引文说的很清楚，并且坛子里还有很多这样的帖子，我就不说了。
最后来看一下这个VOTI是怎么回事，个人认为这是一个软件，基于ATMEGA8L 8AU单片机实现，
如果你的下载器或者单片机开发版上的下载电路里含有这个单片机
（呵呵，有点绕口，注意这个不是你用来写程序的单片机，是专门负责下载的单片机，用单片机烧录单片机，其实很多方案都是这么办的）
那很可能这篇文章就适合你
*/

