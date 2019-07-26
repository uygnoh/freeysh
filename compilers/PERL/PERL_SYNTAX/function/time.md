# perl 时间函数
+ 时间起点: 1970-01-01 00:00:00 ;它以标准时间为基准
+ 标准时间: gmtime()            ;这个函数的值: 表示比时间起点过去了多少秒
+ 北京时间: locatime()          ;这个函数的值: 表示比时间起点过去了多少秒

`北京时间 = 标准时间 + 8小时`

```note
print localtime;
print "\n";
print gmtime;
print "\n";

my $now = localtime;
print $now;
print "\n";
my $now = gmtime;
print $now;
print "\n";
print scalar localtime;

```

```perl
my($sec, $min, $hour, $day, $mon, $year, $wday, $yday, $isdst) = localtime;
print (($year+1900), "年", ($mon+1), "月$day日$hour:$min:$sec\n");
```
