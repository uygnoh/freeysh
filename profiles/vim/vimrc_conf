

if 7 < 9
    if empty(glob('~/.vim/autoload/plug.vim'))
        silent !curl -fLo ~/.vim/autoload/plug.vim --create-dirs
		\ https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
        autocmd VimEnter * PlugInstall --sync | source $MYVIMRC
    endif
    source ~/Documents/FREEYSH/profiles/vim/VIMRC/vimrc
else
    source ~/Documents/FREEYSH/profiles/vim/VIMRC/basic.vim
endif



""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"                                                                        "
" 窗口切换 vim <===>Buffer              tmux<===>Shift+arrow             "
" 窗格切换 vim <===>Ctrl+arrow          tmux<===>Alt+arrow               "
" 分屏操作 vim <===>:split, :vsplit     tmux<===> PREFIX+h, PREFIX+v     "
" 高亮切换 F7                                                            " 
" 全屏切换 F11                                                           "
" 打开终端 Ctrl+7                                                        "
"                                                                        "
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" 
" 参考文件位置: /home/ysh/Documents/FREEYSH/readme.md
" Vim 中的 Buffer 是文件在内存中的缓存数据，一个 Buffer 总是也只能是对应一个文件
" :ls   :buffer number  :buffer next    :buffer previous   <buffer == b> 
"
" tmux Ctrl+b激活控制台；此时以下按键生效, PREFIX = Ctrl+a自定义方式
" tmux 使用C/S模型构建, 包括的单元模块有 server, session, window, panel
" tmux new-session -s <session_name> 创建一个新的会话
" 
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

