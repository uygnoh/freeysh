#!/bin/bash

git add .
git commit -m "$(date)"
git push origin master


# standard peripheral library  ->spl












###########################################################
### git常见错误解决
###########################################################
### git 无法添加文件夹下文件,最近做项目时，发现无法提交某个子文件夹下的文件。
### google后发现可能是该子文件夹下有.git文件夹导致无法上传。删除子文件夹下.git后，依然无法提交子文件夹下的文件。
### 继续google，
### 
### 尝试以下方法
###  git rm --cached directory
###  git add directory
### 注：directory为子文件夹的路径。
### 
### 但是执行git rm --cached directory时，提示
### fatal: Unable to create 'xx/.git/index.lock': File exists.
### 执行rm -f xx/.git/index.lock后解决



###########################################################
### .bashrc
###########################################################
# cat $wb
#export wb=/home/ysh/Documents/FREEYSH/word/wubi_code

# cd $ysh
#export ysh=/home/ysh/Documents/FREEYSH



###########################################################
### .vimrc
###########################################################
# cp /home/ysh/Documents/FREEYSH/profiles/vim/vimrc /home/ysh/.vimrc



###########################################################
### .tmux.conf
###########################################################
# cp /home/ysh/Documents/FREEYSH/profiles/tmux/tmux_cfg /home/ysh/.tmux.conf









