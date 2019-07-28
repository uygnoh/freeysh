# perl 正则表达式
+ 正则表达式模式匹配->量词         . * + ?
+ 正则表达式模式匹配->分组         (.)(..)\1\2
+ 正则表达式模式匹配->捕获
+ 正则表达式模式匹配->匹配         =~
+ 正则表达式模式匹配->智能匹配      ~~
+ 正则表达式模式匹配->            m//
+ 正则表达式模式匹配->修饰符       isgxm
+ 正则表达式模式替换->            s///
+ 正则表达式模式替换->修饰符       gi


# 正则表达式模式分组匹配
```perl
    #习学习学
    if(/(.)(.)\1\2/){print "match\n";}else{print "NO-match\n";}   

    #我正在我正在          
    if(/(.)(..)\1\2/){print "match\n";}else{print "NO-match\n";}     

    #我正在我正在我       
    if(/(.)(..)\1\2\1/){print "match\n";}else{print "NO-match\n";}   

    #正在我正在我我
    if(/(.)(..)\g{1}\g{2}\g{1}/){print "match\n";}else{print "NO-match\n";}

    #我学习学习(相对引用)
    if(/(.)(..)\g{-1}/){print "match\n";}else{print "NO-match\n";} 
```



# 正则表达式, 修饰符(isgx)
```perl
    $_ = "banny and fred";
    if(/fred/) {print "match\n";}else{print "NO-match\n";}
    if(m/fred/){print "match\n";}else{print "NO-match\n";}
    if(m{fred}){print "match\n";}else{print "NO-match\n";}
    if(m<fred>){print "match\n";}else{print "NO-match\n";}
    if(m(fred)){print "match\n";}else{print "NO-match\n";}

    $_ = "Welcome to our website http://www.baidu.com";
    if(m%http://%){print "match\n";}else{print "NO-match\n";}
    if(m{http://}){print "match\n";}else{print "NO-match\n";}
```


  

  
# 跨行的模式匹配
m匹配每一行的开头， g匹配所有的
```perl
    $_ = "thie is the firse line\nthis is the second line\nthis is the third line";
    s/^this/that/;
    print;

    $_ = "thie is the firse line\nthis is the second line\nthis is the third line";
    s/^this/that/mg;
    print;


    1. 把要打开的文件名存储起来 $filenames
    2. 用文件句柄[FILE]来打开文件, or die 如果打开这个文件失败，输出错误信息
    3. 用行输入操作符[FILE], 把这个文件每一行都读出来，再用join把它连接成一个大大的字符串
    4. 用绑定操作符来进行替换， 在每一行的开头， 把文件名加上去 
    5. m跨行的模式匹配

    $filenames = "stm32.c";
    open FILE, $filenames or die "can't open '$filenames': $!";
    my $lines = join '', <FILE>;
    $lines =~ s/^/$filename: /gm;
    print “$lines\n";
```

  
  
# 列表上下文件的
+ my ($first, $second, $third) = /(\S+) (\S+), (\S+)/;
+ 第1小括号它捕获到的变量放到$first,
+ 第2小括号它捕获到的变量放到$second,
+ 第3小括号它捕获到的变量放到$third
+ my @words = ($text =~ /([a-z]+/ig);
+ 使用列表上下文 
+ 第1次捕获的内容放到列表中 
+ 第1次捕获的内容放到列表中
+ 第N次捕获的内容放到列表中
+ 相当于Loop捕获
+ my %last_name = ($data =~ /(\w+)\s+(\w+)/g);


```perl
    $_ = "Hello there, neighbor!";
    my ($first, $second, $third) = /(\S+) (\S+), (\S+)/;
    print "$first $secdond, $third";


    my $text = "Fred dropped a 5 ton grainte block on MR.Slate";
    my @words = ($text =~ /([a-z]+/ig);
    print "@words\n";


    my $data = "Barney Rubble Fred Flintstone Wilma Flintstone Bill Gates";
    my %last_name = ($data =~ /(\w+)\s+(\w+)/g);
    while (($key, $value) = each %last_name) {
        print "$key => $value\n";
    }
```



# 非贪婪模式
+ 贪婪模式
+ 非贪婪模式加上“?”
+ 贪婪模式
+ 非贪婪模式加上“?”
```perl
    $_ = "I thought you said Fred and <BOLD>Velma</BOLD>, not <BOLD>Wilma</BOLD>.";
    s#<BOLD>(.*)</BOLD>#$1#g;

    $_ = "I thought you said Fred and <BOLD>Velma</BOLD>, not <BOLD>Wilma</BOLD>.";
    s#<BOLD>(.*?)</BOLD>#$1#g;

    $_ = "helloooooooooooooo";
    if(/(hello+) {
        print "$1\n";
    }

    $_ = "helloooooooooooooo";
    if(/(hello+?) {
        print "$1\n";
    }
```
