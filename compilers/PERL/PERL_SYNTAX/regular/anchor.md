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




# 捕获变量
1. \s表示匹配空白开头的行
2. \w表示[a-zA-Z0-9_]
3.  +表示匹配多个单词
4.  ,表示包含这个符号
5. (/\s(\w+),/所以它匹配hterc,
6. (\w+)表示它把捕获的变量放到$1中
7. (\w+)这个括号民，表示它启动了正则表达式的捕获功能
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


分组匹配并捕获其中的字符
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


使用特殊变量来作捕获 $1 $2 $3 #n
使用”?:“只作分组，不作捕获
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


+ 重命明捕获
+ 把第1个捕获到的命为name1
+ 把第2个捕获到的命为name2
+ 重命明后它存储在一个特殊的hash中，$+{re_name}格式取出
my $name = "Fred and Barney";
if ($name =~ m/(?<name1>\w+) (?:or|and) (?<name2>\w+)/) {
    print "$+{name1} $+{name2}";
}


+ 重命明用在反向引用的使用
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


# 正则表达式替换文件中的内容 
```perel
$_ = "He's out bowlig with Barney tonight.";
s/Barney/Fred/;
print "$_";

+ $1's team 相当于 (\w+)'s team
+ 后面加入了其它字符串
s/with (\w+)/against $1's team/;
print "$_\n";
```


+ one, two互换位置
+ s/^/huge,/;相当于在字符串前插入huge,
```perl
$_ = "one two three";
s/(\w+) (\w+) /$2 $1/;
print "$_\n";

s/^/huge,/;
print "$_\n";

```

s/home/cave/; 默认只替换1次 
s/home/cave/g;全局替换
```perl
$_ = "home sweet home";
s/home/cave/;
print "$_\n";

s/home/cave/g;
print "$_\n";

```


+ 把多个空格替换成1个
+ 删除字符串前面多余的空格
+ 删除字符串结尾的多余的空格 
+ 删除字符串前后的多余的空格 
```perl
$_ = "Input     data\t   may have       extra whitespace.";
s/\s+/ /g;

$_ = "        one two";
s/^\s+//;
print "$_\n";


$_ = "        one two         ";
s/^\s+$//;
print "$_\n";

$_ = "        one two         ";
s/^\s+|\s+$//g;
print "$_\n";
```


# 正则表达式替换定界符的使用
1. s#^https://#http://#;
2. s{fred}{barney};
3. s[fred][barney};
4. s<fred><barney>;
5. s#wilma#Wilma#gi;
$_ = "fred fintstone";
if (s/fred/wilma/) {
    print "Succeaafully replaced fred with wilma!\n";
}


+ 不使用特殊变量的情况下 $_
+ 使用绑定操作符
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


+ 正则表达式捕获功能替换字符串 
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
```


# split 操作符
+ split用于拆分字符串， 被拆分的字符串它存储在一个数组中
+ 如果字符串数据有空白的，它的前面的部分会保留，中间的也保留，它的后面的部分去掉
+ /\s+/用任意的空白作为分隔符，它得到的是一个 一个单词
+ $_用上了特殊变量 
+  /\s+/ 为split默认的正则表达式 
```perl
@fields = split /:/, "abc:def:g:H";
foreach (@fields) {
    print "$_\n";
}


@fields = split /:/, ":::::abc:::def:g:H:::::::";
foreach (@fields) {
    print "$_\n";
}


my $some_input = "This is a \t      test.  \n";
my @args = split /\s+/, $some_input;
foreach(@args) {
    print "$_\n";
}


$_ = "This is a \t      test.  \n";
my @args = split /\s+/;
foreach(@args) {
    print "$_\n";
}

$_ = "This is a \t      test.  \n";
my @args = split;
foreach(@args) {
    print "$_\n";
}

```


# join 函数

+ 把数组中的数连接起来变成一个字符串，在连接的时候用“：”放在字符串与字符串中间 

@x = (1,2,3,4);
$y = join ":", @y;
print "$y\n";









