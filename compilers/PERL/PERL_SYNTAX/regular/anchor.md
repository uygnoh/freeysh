# 锚位( ^ $)
$_ = "fred and barney";这个匹配不上
```perl
#匹配以fred开头和结尾的字符
#$_ = "fred and barney";这个匹配不上
$_ = "fred";
if(/^fred$/){print "match\n";}else{print "NO-match\n";}
```

"\b \b"; 这个定义单词边界, 它匹配以这个单词的开头和结尾
```perl
#匹配以fred开头和结尾的字符
#$_ = "fred and barney";这个匹配上了
if(/\band\b/){print "match\n";}else{print "NO-match\n";}
```

"\b \B"; 这个定义单词边界, 它匹配以这个单词开头不以这个单词结尾
```perl
$_ = "searching";
if(/\bsearch\B/){print "match\n";}else{print "NO-match\n";}
```

"\b"; 这个定义单词边界, 它匹配以这个单词开头的字符 
```perl
$_ = "I dream of betty rubble.";
if(/\brub/){print "match\n";}else{print "NO-match\n";}
```


# 绑定操作符“=~”
使用“$_”这个特殊变量，可以省略绑定表达式“=~”
如果没有用 “$_”这个特殊变量， 用普通变量的话需要用绑定表达式“=~”
```perl
$some_other = "I dream of betty rubble.";
if($some_other =~ /\brub/){print "match\n";}else{print "NO-match\n";}
```



# 模式串中的内插(/^($wat)/)
+ while(<>)表示等待从键盘的输入, 把输入的信息存储到 ”$_“ 这个特殊变量中,
+ 然后再与(/^($wat)/)相匹配，再判断是否匹配上 
```perl
my $what = "larry";
while (<>) {
    if (/^($wat)/) {
        print "We saw $what in beginning of $_";
    }
}
```






正则表达式中的特殊变量 
```perl
$_ = "one two three, four five six";
if(/\s(\w+),/) {
    print "$1\n"; #(\w+)小括号匹配到的
    print "$&\n"; #(\w+),整个正则表达式匹配到的
    print "$'\n";
    print "$`\n";
    print "$`$&$'\n";
    print "$`<$&>$'\n";
}
```


# 正则表达式的优先级
不清楚的情况下建议加上小括号
```perl
$_ = "fred";
if (/^(fred|barney)$/) {
    print "match\n";
}
``` 



# 正则表达式模式测试程序

```perl
while (<>) {
    chomp;
    if(/RE/) {
        print "MATCH is: |$`<$&>$'|\n";
    } else {
        print "NO-MATCH Failed!\n";
    }
    
}
```



