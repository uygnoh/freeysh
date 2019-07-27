# 基本正则表达式模式匹配

```perl
. * + ?     ;它们表示量词，它们代表要匹配字符的个数.
(.)(..)\1\2 ;模式分组
```

```perl
use encoding 'utf-8';
$_ = "我正在我正在我学习学习数据结构和算法算法";

if(/数据结构.算法/){print "match\n";}else{print "NO-match\n";}
if(/数据结构.*算法/){print "match\n";}else{print "NO-match\n";}
if(/数据结构.+算法/){print "match\n";}else{print "NO-match\n";}
if(/学习.*算法/){print "match\n";}else{print "NO-match\n";}
if(/数据结构和*算法/){print "match\n";}else{print "NO-match\n";}
if(/数据结构和+算法/){print "match\n";}else{print "NO-match\n";}
if(/数据结构和?算法/){print "match\n";}else{print "NO-match\n";}
if(/(数据结构)+和算法/){print "match\n";}else{print "NO-match\n";}


#"数据结构和算法" 或 "数据结构算法"
if(/数据结构(和|与)算法/){print "match\n";}else{print "NO-match\n";}

$_ = "我a你";
if(/我[abcwxyz]你/){print "match\n";}else{print "NO-match\n";}

$_ = "我8888你";
if(/我[01389]+你/){print "match\n";}else{print "NO-match\n";}
if(/我[A-Za-z0-9_]*你/){print "match\n";}else{print "NO-match\n";} 
if(/我\w*你/){print "match\n";}else{print "NO-match\n";}
if(/我[0-9]你/){print "match\n";}else{print "NO-match\n";}
if(/我\d你/){print "match\n";}else{print "NO-match\n";}
if(/我[^0-9]你/){print "match\n";}else{print "NO-match\n";}
if(/我\D你/){print "match\n";}else{print "NO-match\n";}
if(/我[^\d]你/){print "match\n";}else{print "NO-match\n";}

$_ = "you me";
if(/you[\t\n\r\f]me/){print "match\n";}else{print "NO-match\n";}
if(/you\sme/){print "match\n";}else{print "NO-match\n";}
if(/you[^\t\n\r\f]me/){print "match\n";}else{print "NO-match\n";}
if(/you[^\s]me/){print "match\n";}else{print "NO-match\n";}
if(/you\Sme/){print "match\n";}else{print "NO-match\n";}

#可以匹配任何字符
if(/you[\d\D]me/){print "match\n";}else{print "NO-match\n";}


#不匹配任何字符
if(/you[^\d\D]me/){print "match\n";}else{print "NO-match\n";}
```



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


if(/(.)(..)\g{-1}/){print "match\n";}else{print "NO-match\n";} ;我学习学习(相对引用)
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

##### i, 修饰符，不区分大小写
##### 从键盘标准输入作为参数传递程序
```perl
print "Would you like play a game? \n";
chomp($_ = <STDIN>) 
#if(m{yes}i){
if (/yes/i) {
    print "In that case, I recommend that you go bowling. \n";
}

```  

##### 匹配点需要加上 “\”转义字符

```perl
$_ = "fred hello 3.1415926"
if(/3\.1415926){print "match\n";}else{print "NO-match\n";}
```

##### i,不区分大小写;  s,让点也可以匹配所有字符
```perl
$_ = "i sae\napt Barney\nat ay\n fredls\nsot";
if(/barney.*fred/is){print "match\n";}else{print "NO-match\n";}
```


##### 检查输入的是否为数字输入
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
  
  

  
  
  
  
  
  
  
