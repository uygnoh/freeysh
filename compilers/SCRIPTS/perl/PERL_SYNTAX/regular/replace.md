# 正则表达式替换定界符
1. s#^https://#http://#;
2. s{fred}{barney};
3. s[fred][barney};
4. s<fred><barney>;
5. s#wilma#Wilma#gi;
$_ = "fred fintstone";
if (s/fred/wilma/) {
    print "Succeaafully replaced fred with wilma!\n";
}






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





# 特殊变量($_)
+ 不使用特殊变量($_)的情况下 
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
```



















