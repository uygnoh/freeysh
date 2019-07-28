# if 语句 可以判断语句的返回值

```perl
if(open(DATA, $file)){
   ...
}else{
   die "Error: 无法打开文件 - $!";
}

程序中变量 $! 返回了错误信息。 我们也可以将以上代码简化为如下代码：
open(DATA, $file) || die "Error: 无法打开文件 - $!";
```

# exit

语法： exit
说明： 退出执行的程序。
示例： print"i love cgi\n"; exit; 
      显示完"i love cgi"以后，将退出这个程序。
