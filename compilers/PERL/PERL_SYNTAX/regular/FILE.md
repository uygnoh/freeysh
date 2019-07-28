# 一次更新多个文件
+ <>钻椒操作符
+ $^I = "*.bak";有了这个特殊变量后， <>它会先把原来的文件改名"*.bak";
+ 然后用原来的文件名创建一个新的文件，它是空的文件
+ 然后在做循环的时候读的是备份中的一行 一行的内容，
+ 然后用正则表达式替换， 替换了以后，
+ 这时候的print;并不是显示在屏幕上， 而在把它输出到新创建的文件中。
+ 此时新创建的文件和原来的文件是同样的名字，看起来好像是文件被修改了。
```perl
my $date = localtime;
$^I = "*.bak";
while (<>) {
    s/^Author:.*/Author: Randal L. Schwrtz/;
    s/^phone:.*\n//;
    s/^Date:.*/Date: $date/;
    print;
}

% perl demo1.pl demo2.dat
```





# 匹配模式修饰符
+ 从键盘标准输入作为参数传递程序
+ 匹配点需要加上 “\”转义字符
+ i,不区分大小写;  
+ s,让点也可以匹配所有字符
```perl
print "Would you like play a game? \n";
chomp($_ = <STDIN>) 
#if(m{yes}i){
if (/yes/i) {
    print "In that case, I recommend that you go bowling. \n";
}

$_ = "fred hello 3.1415926"
if(/3\.1415926){print "match\n";}else{print "NO-match\n";}
```

$_ = "i sae\napt Barney\nat ay\n fredls\nsot";
if(/barney.*fred/is){print "match\n";}else{print "NO-match\n";}
```


# 检查输入的是否为数字输入
```perl
print "请主输入一个数";
chomp($_ = <STDIN>);
if(/-?\d+\.?\d+/){print "你输入的是一个数： $_\n";}
```


+ 加上“x”它通知perl的正则，它里面加的空格不是正则表达式里的字符
+ 检查输入的是否为数字
  ```perl
  print "请主输入一个数";
  chomp($_ = <STDIN>);
  if(/-? \d+ \.? \d+/x){print "你输入的是一个数： $_\n";}
  ```


+ 加上“x修饰符”它通知perl的正则，它里面加的空格不是正则表达式里的字符
+ 多个修饰符可以放到一起，它们没有顺序 
+ 检查输入的是否为数字, 这样书写方式是为了更好理解代码 
  ```perl
  print "请主输入一个数";
  chomp($_ = <STDIN>);
  if (/-?           #0个或1个“-”号
     \d+            #1个或多个数字
     \.?            #0个或1个“.”小数点 
     \d+            #1个或多个数字
    /x){print "你输入的是一个数： $_\n";}
  ```
  
