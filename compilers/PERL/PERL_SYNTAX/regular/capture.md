# 捕获变量
1. \s表示匹配空白开头的行
2. \w表示[a-zA-Z0-9_]
3.  +表示匹配多个单词
4.  ,表示包含这个符号
5. (/\s(\w+),/所以它匹配hterc,
6. (\w+)表示它把捕获的变量放到$1中
7. (\w+)这个括号，表示它启动了正则表达式的捕获功能
8. $1表示它把捕获到的变量放入它里面
```perl
$_ = "hello hterc, neighbor";
if(/\s(/w+),/){
    print $1;
}
```

+ "Hello there, neighbor"它正好匹配它
+ \S表示不包含空白
```perl
$_ = "Hello there, neighbor";
if(/(\S+) (\S+), (\S+)/) {
    print "$1 $2 $3";
}
```


+ "I fear that I'll be extinct after 1000 years.";
+ 匹配上面的字符串中的数字并打印出来 
```perl
my $dino = "I fear that I'll be extinct after 1000 years.";
if($dino =~ /(\d*) years/) {
    print "$1 \n";
}
```


# 分组匹配并捕获其中的字符
```perl
$_ = "one two three four five six";
if(/(\S+) (\S+) (\S+) (\S+)/) {
    print "$1 $2 $3 $4 \n";
}


?:它表示只用来分组，不用来作捕获
$_ = "one two three four five six";
if(/(?:\S+) (\S+) (\S+) (\S+)/) {
    print "$1 $2 $3 $4 \n";
}
```


# 使用特殊变量来作捕获 $1 $2 $3 #n
+ 使用”?:“只作分组，不作捕获
```perl
my $name = "Fred and Barney";
if ($name =~ m/(\w+) and (\w+)/) {
    print "$1 $2 \n";
}



my $name = "Fred and Barney";
if ($name =~ m/(\w+) (?:or|and) (\w+)/) {
    print "$1 $2 \n";
}


my $name = "Fred and Barney";
if ($name =~ m/(\w+) (or|and) (\w+)/) {
    print "$1 $3 \n";
}
```


# 重命明捕获
+ 把第1个捕获到的命为name1
+ 把第2个捕获到的命为name2
+ 重命明后它存储在一个特殊的hash中，$+{re_name}格式取出
my $name = "Fred and Barney";
if ($name =~ m/(?<name1>\w+) (?:or|and) (?<name2>\w+)/) {
    print "$+{name1} $+{name2}";
}





# 重命明用在反向引用的使用
```perl
my $names = "Fred Flinstone and Wilma Flinstone";

if ($name =~ /(?<last_name>\w+) and \w+ \g{last_name}/) {
    print "$+{last_name}\n";
}
```

```perl
my $names = "Fred Gates and Wilma Gates";

if ($name =~ /(?<last_name>\w+) and \w+ \k<last_name>/) {
    print "$+{last_name}\n";
}
```









# 特殊变量 $_
+ 不使用特殊变量($_)的情况下, 使用绑定操作符(=~)
$content = "one another one";
$content =~ s/one/two/g;


+ (fred|barney)转换成大写字母
+ (fred|barney)转换成小写字母
```perl
$_ = "I saw Barney with Fred";
s/(fred|barney)/\U$1/ig;
print "$_\n";


$_ = "I saw Barney with Fred";
s/(fred|barney)/\L$1/ig;
print "$_\n";
```


# 正则表达式捕获功能替换字符串 
+ 正则表达式捕获功能替换字符串，并改为大写
+ 正则表达式捕获功能替换字符串，用E来结束大写 
```perl
$-_ = "this is one and two";
s/(\w+) and (\w+)/$2 and $1/;

$-_ = "this is one and two";
s/(\w+) and (\w+)/\U$2 and $1/;

$-_ = "this is one and two";
s/(\w+) and (\w+)/\U$2\E and $1/;
```

+ \U全部字母大写 
+ \u第1个字母大写，其它不变
+ \l第1个字母小写，其它不变
+ \L全部字母小写
+ \u\L第1个字母大写，其它字母小写 
+ \E表示来结束大小写字母
```perl
$_ = "one and two";
s/(one|two)/\U$1/gi;
print "$_\n";

$_ = "one and two";
s/(one|two)/\u$1/gi;
print "$_\n";

$_ = "one and two";
s/(one|two)/\u$1/gi;
print "$_\n";

$_ = "one and two";
s/(one|two)/\u\L$1/gi;
print "$_\n";

$name = "bill";
print "Hello, \L\u$name\E, would you like to play a game?\n";












