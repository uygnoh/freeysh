#!/bin/bash


git config --global user.name "hongyu"
git config --global user.email "961832097@qq.com"
git config --global core.editor vim         ##文本编辑器设定
git config --list                           ##查看配置信息
git init                        # 初始化仓库
git add .	                    # 你可通过 git add 命令来实现对指定文件的跟踪
git commit -m "First comment"   # 然后执行 git commit 提交


### 创建 SSH Key
ssh-keygen -t rsa

### 在GitHub上,打开"Account Settings" --->"SSH Keys"
### 导入公钥至"Key"文本框中
### 验证是否成功	          ssh -T git@github.com


### ================================================================= 关联远程库

### git remote add origin git@github.com:uygnoh/free_doc.git  
	
### 关联后,第一次推送master分支的所有内容命令。
### git push -u origin master

### 此后，每次本地提交后，就可以使用下面的命令推送最新修改。
### git push origin master



### ============================================================== 其它注意事项!!! 	
### git remote -v                 # 查看远程关联GitHub仓库	
### git remote rm origin          # 移出旧的GitHub仓库

