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
#$_ = "fred and barney";这个匹配上了 ->and
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










