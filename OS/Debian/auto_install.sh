#!/bin/bash
###############################################################################
echo -e "\033[41;37m--->>>BEGING INSTALL UTILITIES\033[37;0m"
### #00FF00,绿色-光标
### cp /home/ysh/Documents/FREEYSH/profile/molokai.vim /usr/share/vim/vim80/colors

### 适用于Debian 命令#: dpkg-reconfigure tzdata ;用于修改系统时区

### =======================================================
sudo apt-get -y install gcc
sudo apt-get -y install gdb
sudo apt-get -y install make
sudo apt-get -y install cmake
sudo apt-get -y install openocd

sudo apt-get -y install automake
sudo apt-get -y install autoconf
sudo apt-get -y install libtool

sudo apt-get -y install git
sudo apt-get -y install vim 
sudo apt-get -y install tmux
sudo apt-get -y install ranger 
sudo apt-get -y install xchm

sudo apt-get -y install kicad
sudo apt-get -y install dia

sudo apt-get -y install cmus 
sudo apt-get -y install smplayer
sudo apt-get -y install curl


sudo apt-get -y install cryptsetup

### =======================================================
A=/home/ysh/Documents/FREEYSH/profile/
B=/home/ysh/
cp $A.tmux.conf $A.vimrc $B
curl -fLo ~/.vim/autoload/plug.vim --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim









echo -e "\033[41;37mINSTALLATION IS COMPLETE--->>>\033[37;0m"
echo "return $?"
###############################################################################

