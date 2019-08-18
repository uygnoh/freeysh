
# perl Regular Expression
```perl
    /pattern/ 	结果
    .	        除了换行字符\n外,找寻只有一个字符的字符串
    x? 	        找寻0个或是1个x字符
    x* 	        找寻0个或是0个以上的x字符
    .* 	        找寻0个或是0个以上的任何字符
    x+ 	        找寻0个或是1个以上的x字符
    .+ 	        找寻1个或是1个以上的任何字符
    {m} 	    找寻刚好是m个个数指定的字符
    {m,n} 	    找寻在m个数个数以上,n个个数以下指定的字符
    {m,} 	    找寻m个个数以上指定的字符
    [] 	        找寻符合[]内的字符
    [^] 	    找寻不符合[]内的字符
    [0-9] 	    找寻符合0到9的任何一个字符
    [a-z] 	    找寻符合a到z的任何一个字符
    [^0-9] 	    找寻不符合0到9的任何一个字符
    [^a-z] 	    找寻不符合a到z的任何一个字符
    ^ 	        找寻字符开头的字符
    $ 	        找寻字符结尾的字符
    \d 	        找寻一个digit(数字)的字符,和[0-9]语法一样
    \d+ 	    找寻一个digit(数字)以上的字符串,和[0-9]+语法一样
    \D 	        找寻一个non-digit(非数字)的字符,和[^0-9]语法一样
    \D+ 	    找寻一个non-digit(非数字)以上的字符,和[^0-9]+语法一样
    \w 	        找寻一个英文字母或是数值的字符,和[a-zA-Z0-9]语法一样
    \w+ 	    找寻一个以上英文字母或是数值的字符,和[a-zA-Z0-9]+语法一样
    \W 	        找寻一个非英文字母,数值的字符,和[^a-zA-Z0-9]语法一样
    \W+ 	    找寻一个以上非英文字母,数值的字符,和[^a-zA-Z0-9]+语法一样
    \s 	        找寻一个空白的字符,和[\n\t\r\f]一样
    \s+ 	    找寻一个以上空白的字符,和[\n\t\r\f]+一样
    \S 	        找寻一个非空白的字符,和[^\n\t\r\f]一样
    \S+ 	    找寻一个以上非空白的字符,和[^\n\t\r\f]+一样
    \b 	        找寻一个不以英文字母,数值为边界的字符串
    \B 	        找寻一个以英文字母,数值为边界的字符串
    a|b|c 	    找到符合a字符或是b字符或是c字符的字符串
    abc 	    找到一个含有abc的字符串

    (pattern) 	()这个符号是会记忆所找寻到的字符,是一个很实用的语法
                第一个()内所找到的字符串变成$1这个变量或是\1变量
                第二个()内所找到的字符串变成$2这个变量或是\2变量
                以此类推,笔者会在下一小节中详细介绍它的用法
                
    /pattern/i 	i这个参数是代表忽略英文大小写的意思,
                也就是在找寻字符 串的时候,不会去考虑英文的大小写
                
    \ 	        如果要在pattern模式中找寻一个有特殊的意义的字符,
                要在 这个字符前加上\这个符号,这样才会让这个特殊字符失效
```

           
            
            
# 文字处理模式的简单范例  
```perl             
    范例 	    说明
    /perl/ 	    找到含有perl的字符串
    /^perl/ 	找到开头是perl的字符串
    /perl$/ 	找到结尾是perl的字符串
    /c|g|i/ 	找到含有c或g或i的字符串
    /cg{2,4}i/ 	找到c后面跟着2个到4个g,再跟着i的字符串
    /cg{2,}i/ 	找到c后面跟着2个以上g,再跟着i的字符串
    /cg{2}i/ 	找到c后面跟着2个g,再跟着i的字符串
    /cg*i/ 	    找到c后面跟着0个或多个g,再跟着i的字符串,如同/cg{0,1}i/
    /cg+i/ 	    找到c后面跟着一个以上g,再跟着c的字符串,如同/cg{1,}i/
    /cg?i/ 	    找到c后面跟着0个或是一个g,再跟着c的字符串,如同/cg{0,1}i/
    /c.i/ 	    找到c后面跟着一个任意字符,再跟着i的字符串
    /c..i/ 	    找到c后面跟着二个任意字符,再跟着i的字符串
    /[cgi]/ 	找到符合有这三个字符任意一个的字符串
    /[^cgi]/ 	找到没有这三个字符中任意一个的字符串
    /\d/ 	    找寻符合数值的字符串
                可以使用/\d+/来表示一个或是多个数值的字符串
    /\D/ 	    找寻符合不是数值的字符串
                可以使用/\D+/来表示一个或是更多个非数值的字符串
    /\w/ 	    找寻符合英文字母,数值的字符串
                可以使用/\w+/来表示一个或是更多个英文字母,数值的字符串
    /\W/ 	    找寻符合非英文字母,数值字符的字符串
                可以使用/\W+/来表示一个或是更多个非英文字母,数值的字符串
    /\s/ 	    找寻符合空白的字符串
                可以使用/\s+/来表示一个或是更多个空白字符的字符串
    /\S/ 	    找寻符合不是空白的字符串
                可以使用/\S+/来表示一个或是更多不是空白的字符的字符串
    /\*/ 	    找寻符合*这个符号的字符串,因为*在文字处理模式中有它的特殊意思,
                所以要在这个特殊符号前加上\这个符号,这样才会让这个特殊字符失效
    /abc/i 	    找寻符合abc的字符串而且不考虑这些符合字符串的大小写           
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


