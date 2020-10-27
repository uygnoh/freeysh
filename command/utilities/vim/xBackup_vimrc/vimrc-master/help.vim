"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" General常规设置

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

set nocompatible
"译注:nocompatible是为了和VI保持最大兼容,除非你经常用于远程终端,或者
"调试陌生的机器,否则就禁用掉好了,单机用户直接禁用好了.

set history=400
"译注:保留历史命令个数,Amir给的命令个数是400,太夸张了,我改到50了,实话
"说,200个命令以前,我用过什么命令,已经完全记不清了

filetype plugin on
"译注:为特定的文件类型允许插件文件的载入.在文件编辑时，相应的插件文件
"也会载入 (如果文件类型能检测到)。比如说,我载入了一个C源代码,而且我的
"VIM安装了C的辅助插件,那么载入C源码文件的时候,对应的插件也会自动载
"入,比如代码识别,函数自动补全等等

filetype indent on
"译注:文件缩进的支持,这个的意思是打开不同类型的文件,可能会自动匹配不同
"的格式,如果已经做了设置的话.

set autoread
"译注:如果文件在外部被其它程序修改了,那么VIM里会自动读入这种修改,而
"不必关闭后再打开,很实用的功能    

set mouse=a
"译注:允许使用鼠标。只可用于特定终端 (xterm、MS-DOS、Win32 |win32-
"mouse|、"QNX pterm、带 sysmouse 的 *BSD 控制台 和带 gpm 的 
"Linux 控制台)。如果你"在桌面状态下使用,就不用管了,鼠标会一直处于可用
"状态,如果你在以上列出的终端状态下使用,请务必打开


let mapleader = ","
let g:mapleader = ","
"译注:映射快捷键开始命令为","号,g:表示全局设置.其使用方法见下

nmap <leader>w :w!<cr>
nmap <leader>f :find<cr>
"译注:nmap表示在普通状态下,上面已经写过,mapleader被映射为","号,
"那么这里可以用,w命令来代替:w!命令,亲自试一下,是不是方便多了,手不
"用再挪大半个键盘打几个键了.mapleader可以自由设定

map <leader>s :source ~/vim_local/vimrc<cr>
"译注:VIM的配置文件名字就是vimrc,位于你的磁盘的某个位置,一般
"来说,Windows位于安装位置或者你的个人配置文件夹,比如我的配置
"文件所在的绝对路径就是
"C:/Documents "and Settings/hongqr/,这段路径,可以直接用~来
"表示,我的这句配置就可以写为
"map <leader>s :source ~/vimrc<cr>
"本句的意思是快速重读配置文件,这样,就不需要关闭文件重开一下来读入
"配置文档了,注意本命令和autoread没有关系,autoread是重读入外部被
"程序修改的文档,source是重新执行指定的文件,不要弄混了    

map <leader>e :e! ~/vim_local/vimrc<cr>
"译注:上面的那一句看懂了,这句就很简单了,这是快速打开配置文件    



autocmd! bufwritepost vimrc source ~/vim_local/vimrc
"译注:autocmd是自动执行命令,这句的意思是当配置文件被更改后重新
"读入,不需要你用,w,s重复操作了    





"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Colors and Fonts
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

syntax enable
"译注:语法高亮,不同的源码文件,会在语法关键字等位置显示不同的颜
"色,代码编辑的时候,不是一般的方便啊



if MySys()== "mac"
    set gfn=Bitstream/ Vera/ Sans/ Mono:h14
    set nomacatsui
    set termencoding=macroman
elseif MySys()=="linux"
    set gfn=Monospace/ 11
endif
"译注:这段是个小脚本,针对不同的系统,使用不同的字体,如果你使用了
"不同的操作系统,这段脚本很有用,或者需要经常带着配置文件,调试不同
"的机器,也有用,否则,就不需要了,GUI版本可以直接在菜单里设置



if has("gui_running")
    set guioptions-=T
    let psc_style='cool'
    colorscheme ps_color
else
    set background=dark
    colorscheme zellner
endif
“在GUI界面下,set guioptions-=T表示不显示工具栏,工具栏
"确实没有什么大用处.psc_style没有查到是什么东东,看名字也应该是
"个自定义的参数.colorscheme是配色方案,配色方案名称是ps_color
"如果你想更多配色方案选择,可以至官网下载
"最后两句是默认设置的配色方案和背景.配色的选择,自己喜欢就好了,
"不需要用作者的



map <leader>1 :set syntax=cheetah<cr>
map <leader>2 :set syntax=xhtml<cr>
map <leader>3 :set syntax=python<cr>
map <leader>4 :set ft=javascript<cr>
map <leader>$ :syntax sync fromstart<cr>
"根据不同的文件类型,配置不同的语法文件.还记得吗?<leader>前面
"设置为","号的.syntax表示语法.syncbind这个比较有趣,它表示强
"制所有 'scrollbind' 窗口具有相同的相对偏移。即：当一个窗口滚
"屏到了它缓冲区的顶部时，所有的 'scrollbind'窗口都会滚屏到它们
"缓冲区的顶部。这段设置,请根据你使用的程序做设置
"fromstart我没有查到这个功能,根据意思,我估计为作者留下的给用户
"算定配置的地方


autocmdBufEnter * :syntax syncbind fromstart
"译注:自动匹配用户读入的程序文件





"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"Fileformats
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

set ffs=unix,dos,mac
“译注:设置文件类型,是UNIX文件,DOS文件还是Mac文件



nmap <leader>fd :se ff=dos<cr>
nmap <leader>fu :se ff=unix<cr>
“译注: 设置文件支持DOS文件格式或者UNIX文件格式,
"和上面的放在一起说,如果只是用Windows系统,那就可以无视这一小节
"了.如果你需要经常调试不同的系统,那么就需要这个了




"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"VIM
userinterface
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

set scroloff=7
“译注: scrolloff光标上下两侧最少保留的屏幕行数,简单来说,就是把光标始终
"固定在屏幕大概约中间的位置,上下至少留七行,这样翻页的时候不会混乱,很实用的功能




""""""""""""""""""""""""""""""
"Statuslinee
""""""""""""""""""""""""""""""

set laststatus=2
“译注:默认情况下,只有两个以上的窗口才显示状态栏.其值定义为
“本选项的值影响最后一个窗口何时有状态行: 
“0: 永不
“1: 只有在有至少两个窗口时
“2: 总是
“注意:本选项与前面的set ruler功能上有重叠,如果设置了本项, 
”set ruler值将被遮住.可以选择使用. 
“状态栏上显示的功能可以更复杂,更多,且中定制(当然可以包含行列数) 
“所以我推荐使用该项而放弃set ruler,不过如果你喜欢更简单的显示, 
“那就放弃本项



function! CurDir()
    let curdir = substitute(getcwd(), '/Users/amir/', "~/", "g")
    return curdir
endfunction
“译注:简单说一下其功能,设置了一个函数CurDir(),该函数调用了getcwd()
“函数,getcwd()的作用是返回当前路径这个值. 
“这里注意一下,其实可以直接使用getcwd(),不用那么麻烦
“getcwd(), '/Users/amir/', "~/", "g"
“这一长串的意思是把/Users/amir/替换为~,是不是有点晕,呵呵,Amir就是作
“者的名字,就是把他的用户目录替换为~显示
“所以这一段可以完全舍弃
set statusline=/%F%m%r%h/ %w/ / CWD:/ %r%{CurDir()}%h/ / / Line:/ %l/%L:%c
“译注:状态栏的格式化.这一段有点乱,一点一点的看吧
“F    缓冲区的文件完整路径。
“m    修改标志位，若开始修改文本显示为 "[+]"；若 'modifiable' 关闭则是 "[-]"。
’modifialbe’也是一个选项.表示如果关闭，缓冲区的内容不能修改。
“r    只读标志位，文本是 "[RO]" 
“h    帮助缓冲区标志位，文本是 "[help]" 
“w    预览窗口标志位，文本是 "[Preview]"。
“%{CurDir()}调用前面的getcwd(),用于显示前面的完整路径,如果上一段舍弃了,这里
“直接用%{getcwd()}来代替.PS:我就是这样用的. 
“l    行号
“c    列号。
“L    缓冲区里的行数
“数量繁多的”/ “是转义符,转义空格的




"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Mappings
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
map
<leader>bd :Bclose<cr>
"译注: ,bd命令快速关闭当前缓冲区文件

map <down> <leader>bd
"译注:向下的方向键映射,bd也就是把上一个命令进一步简化

map <right> :bn<cr>
"译注:右方向键切换到下一个缓冲区文件

map <left> :bp<cr>
"译注:左方向键切换到上一个缓冲区文件

"这里我添加一个我写的语句,原文没有的,大家酌情使用
map <up>   :ls!<cr>
"译注:向上方向键显示所有的缓冲区文件

map <leader>tn :tabnew%<cr>
"译注:将当前内容在新标签中打开

map <leader>te :tabedit<cr>
"译注:打开空白新标签

map <leader>tc :tabclose<cr>
"译注:关闭当前标签

map <leader>tm :tabmove
"译注:移动当前标签,使用方法为
":tabmove [N]把当前标签页移到第N个标签页之后.
"用0使用当前标签页成为首个标签页.如果没有N,
"当前标签页成为最后一个.


try
set switchbuf=usetab
set showtabline=2
catch
endtry
"译注:try和endtry是成对出现的,可以简单理解为循环命令,
"主要功能是用来做错误处理的.
"set switchbuf=usetab
"这里表示不断尝试在编译时跳到打开的包含指定缓冲区
"的窗口(如果有的话)。
"具体的使用方法,请参照quickfix.
"set showtabline=2
"这里表示永远显示带有标签页标签的行
"        本选项的值指定何时显示带有标签页标签的行:
"                0: 永远不会
"                1: 至少有两个标签页时才会
"                2: 永远会




imap <m-$> <esc>$a
"译注:编辑模式下,使用Alt+$,可以立刻跳到编辑行的尾部继续编辑



imap <m-0><esc>0i
"译注:编辑模式下,使用ALT+0,可以立刻跳到编辑行的首部继续编辑
"imap <D-$> <esc>$a和imap <D-0> <esc>0i是Mac下的,意义相同






"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" General Autocommands
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
引用:

map <leader>cd :cd %:p:h<cr>
"译注:切换到当前目录




"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Parenthesis/bracket expanding
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

vnoremap $1<esc>`>a)<esc>`<i(<esc>
"译注:vnoremap可视模式,为选中的内容添加成对出现的符号.下同.使用$1来输入()

vnoremap $2<esc>`>a]<esc>`<i[<esc>
"译注:使用$1来输入[]

vnoremap $3<esc>`>a}<esc>`<i{<esc>
"译注:使用$1来输入{}

vnoremap $$<esc>`>a"<esc>`<i"<esc>
"译注:使用$1来输入""

vnoremap $q<esc>`>a'<esc>`<i'<esc>
"译注:使用$1来输入''


vnoremap $w<esc>`>a"<esc>`<i"<esc>
"译注:PS:这里出现了错误,这一行和往上数的第三行重复了,估计是
"作者打错了,我猜测可能是<>,成对出现的符号也不多.所以,这一行应该为
"vnoremap $w<esc>`>a><esc>`<i<<esc>,或者,如果你编辑中文
"文本比较多,还以为改为 
"vnoremap $w<esc>'>a”<esc>`<i“<esc>
"用于编辑中文的前后双引号,自己编辑常用的成对符号时,一定要注意,
"前面的符号放在<i后,后面的符号放在>a后,不要反了

inoremap $1 ()<esc>:let leavechar=")"<cr>i
"译注:inoremap,在插入模式下,下同.在输入(后,使用$1自动补全),并返回插入模式

inoremap $2 []<esc>:let leavechar="]"<cr>i
"译注:在输入[后,使用$2自动补全],并返回插入模式

inoremap $4 {<esc>o}<esc>:let leavechar="}"<cr>O
"译注:在输入{后,使用$4自动补全},并返回插入模式

inoremap $3 {}<esc>:let leavechar="}"<cr>i
"译注:在输入{后,使用$3自动补全},并返回插入模式

inoremap $q ''<esc>:let leavechar="'"<cr>i
"译注:在输入'后,使用$q自动补全',并返回插入模式


inoremap $w ""<esc>:let leavechar='"'<cr>i
"译注:在输入"后,使用$q自动补全",并返回插入模式


au BufNewFile,BufRead *./(vim/)/@! inoremap """<esc>:let leavechar='"'<cr>i
au BufNewFile,BufRead *./(txt/)/@! inoremap '''<esc>:let leavechar="'"<cr>i
"译注:非常遗憾,实在没有弄明白这两行是什么意思,估计应该是在vim和txt格式文档
"被新建和读入时,输入"和'号后,自动进入编辑模式,并置于符号之间
"我给作者发了一封信,但是没有回应,估计是被当成垃圾邮件处理了.T_T怨念中...





"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" General Abbrevs
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
引用:

iab mdate <c-r>=strftime("%d/%m/%y %H:%M:%S")<cr>
iab mname hongqr
"译注:上面两行是由自己定制的个人信息
"iabc为插入模式删除所有的缩写
"mdate 为插入当前日期和时间
"mdate为插入自己的用户名




"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Editing mappings etc.
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

map 0 ^
"译注:用0来替换^号,使跳到行首使用0命令



nmap <M-j> mz:m+<cr>`z
nmap <M-k> mz:m-2<cr>`z
"译注:普通模式下,<M-j>调整当前行往下一行,<M-k>调整当前行往上一行


vmap <M-j> :m'>+<cr>`<my`>mzgv`yo`z
vmap <M-k> :m'<-2<cr>`>my`<mzgv`yo`z
"译注:可视模式下,<M-j>调整当前行往下一行,<M-k>调整当前行往上一行
"这两组四个命令,非常实用

if MySys() == "mac"
nmap <D-j> <M-j>
nmap <D-k> <M-k>
vmap <D-j> <M-j>
vmap <D-k> <M-k>
endif
"译注:以上脚本是为了Mac机与PC机兼容的,可以忽略


func! DeleteTrailingWS()
exe "normal mz"
%s//s/+$//ge
exe "normal `z"
endfunc
autocmd BufWrite *.py :call DeleteTrailingWS()
"译注:为Python格式最后一个单词尾清理空白字符,ge,向后直到单词尾


set completeopt=menu
"译注:使用弹出菜单来显示可能的补全,命令行下<C-i>弹出





au BufEnter *.sablecc,*.scc set ft=sablecc
"译注:文件类型*.sablecc和*.scc
"进入缓冲区后。设置文件类型为sablecc



function! FoldText()
return substitute(getline(v:foldstart), '{.*', '{...}', '')
endfunction
setl foldtext=FoldText()
endfunction
au FileType java call JavaFold()
"译注:文件类型为java时,调用上面写的javaFold()函数






set backspace=eol,start,indent
“译注:默认情况下,backspace键,也就是我们常说的退格键,只能在本行进行移
"动,现在可以扩展到影响以下参数了
“indent 允许在自动缩进上退格
"eol 允许在换行符上退格 (连接行)
“start 允许在插入开始的位置上退格；CTRL-W 和 CTRL-U 到达插入开始的位
“置时停留一次。


set whichwrap+=<,>,h,l
“译注:和退格键一样,左右方向键默认也只能在本行移动,用起来会很别扭,这条设置过之后,
“就没有限制了, 使指定的左右移动光标的键在行首或行尾可以移到前一行或者后一行
“<和>是用来调整缩进的.


set ignorecase
“译注:搜索时忽略大小写


set incsearch
“译注:搜索时高亮关键词


set magic
“译注:魔法配置. 改变搜索模式使用的特殊字符.默认就是打开的,加上只是预
“防误关闭.具体的使用,请参阅正则表达式.


set noerrorbells
“译注: 关闭错误信息响铃 (鸣叫或屏幕闪烁).除了让你头疼之外,作用实在不大


set novisualbell
“译注:关闭使用可视响铃代替鸣叫.


set t_vb=
“译注:上面两条里的错误铃声,其终端代码就是t_vb.置空之后,世界就清净了.


set showmatch
“译注: 插入括号时，短暂地跳转到匹配的对应括号.超级实用的功能,可以防止少输入半个
“括号.编程时更可以查看是否匹配错误的括号


set matchtime=2
“译注:接上一条,短暂跳转到匹配括号的时间


set hlsearch
“译注: 搜索出之后,高亮关键词.必设项

    
    
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Misc
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" 单键<F7>控制syntax on/off; 原因是有时候颜色太多会妨碍阅读
map <F7> :if exists("syntax_on") <BAR>
\       syntax off <BAR><CR>
\ else <BAR>
\       syntax enable <BAR>
\  endif




" 其中set backspace这一命令有两种写法：后面接数字或其他属性，
" set backspace=0     等同于 set backspace= (Vi 兼容)
" set backspace=1     等同于 set backspace=indent,eol
" set backspace=2     等同于 set backspace=indent,eol,start



" return OS type, eg: windows, or linux, mac, et.st..
function! MySys()
    if has("win16") || has("win32") || has("win64") || has("win95")
        return "windows"
    elseif has("unix")
        return "linux"
    endif
endfunction
" 用户目录变量$VIMFILES
if MySys() == "windows"
    let $VIMFILES = $VIM.'/vimfiles'
elseif MySys() == "linux"
    let $VIMFILES = $HOME.'/.vim'
endif

            
