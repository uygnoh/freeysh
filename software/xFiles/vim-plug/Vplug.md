##### Vim-plug 极简的 vim 插件管理器
+ https://linux.cn/article-9751-1.html

##### Vim-plug 安装
+ $ curl -fLo ~/.vim/autoload/plug.vim --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim

+ 例如，我们安装 “lightline.vim” 插件。为此，请在 ~/.vimrc 的顶部添加以下行
```note
call plug#begin('~/.vim/plugged')
Plug 'itchyny/lightline.vim'
call plug#end()
```

+ 在 vim 配置文件中添加上面的行后，通过输入以下命令重新加载：
`:source ~/.vimrc`

##### Vim-plug 操作
+ 现在，打开 vim 编辑器 `$ vim`
+ :PlugStatus       `检查插件状态`
+ :PlugInstall      `安装插件`
+ :PlugUpdate       `更新插件`
+ :PlugDiff         `审查插件`
+ :PlugClean        `删除插件`
+ :PlugUpgrade      `升级 vim-plug`

=

