### stm32f10x_conf.h 头文件, 在 stm32f10x.h中的定义          
8296    #ifdef USE_STDPERIPH_DRIVER
        #include "stm32f10x_conf.h"
        #endif


### eclipse新建一个空的工程                          
File->New->C Project->Emptry Project Cross ARM GCC
mkdir user startup cmsis libraies ldscripts bsp
添加相应的文件到工程中，并刷新工程




## GNU ARM Embedded Toolchain 
sudo gedit ~/.bashrc



### GNU Arm Embedded Toolchain
export GCC_HOME=/opt/gcc-arm-none-eabi-7-2018-q2-update-linux/gcc-arm-none-eabi-7-2018-q2-update/
export PATH=$PATH:$GCC_HOME/bin


### JAVA-JDK
export JAVA_HOME=/opt/jdk-8u181-linux-x64/jdk1.8.0_181/
export PATH=$PATH:$JAVA_HOME/bin


### eclipse
export PATH=$PATH:/opt/eclipse-cpp-2018-09-linux-gtk-x86_64/eclipse/


