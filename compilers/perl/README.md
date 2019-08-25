### 在perl中引号不一定要写成符号
```note
    q()     #表示单引号
    qq()    #表示双引号
    qx()    #表示反引号
其中这里的括号也可以替换成其它成对的符号
    q{}     q//     q%%
    qq{}    qq//    qq%%
    qx{}    qx//    qx%%
```



## 在perl中, <STDIN>
```note
1. 读取标准输入，只能读取一行
vim test.pl
#!/usr/bin/perl
$data=<STDIN>;
print "$data";

> echo "abcdef" | perl test.pl


1. 读取标准输入，读取多行
foreach $line (<STDIN>) {
    print "$line";
}

> echo "abcd\njkfm" | perl test.pl

#和上面语法等效
    foreach $_ (<STDIN>) {
        print "$_";
    }
```

## 在perl中, <>
```note
读取文件中的数据 
我们可以将文件作为perl命令行参数，perl会使用”<>“去读取文件中的内容

foreach $_ (<>) {
    print "$_";
}

> perl test.pl /etc/passwd

#去掉默认的换行符
    foreach $_ (<>) {
        chomp $_;
        print "$_";
    }

```



### 在perl中, 匹配字符串 =~
```note
$name="aAbBcC";
if ($name =~ m/ab/i) {
    print "pre match:  $`\n";
    print "match:      $&\n";
    print "post match: $'\n";
}
```




### perl命令行加上“-e”选项，就能在perl命令行中直接写perl表达式
> echo "hello" | /usr/bin/perl -e '$name=<STDIN>;print $name;'







