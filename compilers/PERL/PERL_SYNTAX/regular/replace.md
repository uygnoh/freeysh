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
+ 它可以用各种各样的字符，不一定是“：”
```perl

@x = (1,2,3,4);
$y = join ":", @y;
print "$y\n";
```




# 列表上下文件的 m//
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
+ HASH


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


# 跨行的模式匹配
+ m匹配每一行的开头， g匹配所有的
```perl
$_ = "thie is the firse line\nthis is the second line\nthis is the third line";
s/^this/that/;
print;

$_ = "thie is the firse line\nthis is the second line\nthis is the third line";
s/^this/that/mg;
print;
```



1. 把要打开的文件名存储起来 $filenames
2. 用文件句柄[FILE]来打开文件, or die 如果打开这个文件失败，输出错误信息
3. 用行输入操作符[FILE], 把这个文件每一行都读出来，再用join把它连接成一个大大的字符串
4. 用绑定操作符来进行替换， 在每一行的开头， 把文件名加上去 
5. m跨行的模式匹配
```perl
$filenames = "stm32.c";
open FILE, $filenames or die "can't open '$filenames': $!";
my $lines = join '', <FILE>;
$lines =~ s/^/$filename: /gm;
print “$lines\n";
```








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


