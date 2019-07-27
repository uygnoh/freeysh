#  grep
```perl
# 打印1到100中所有的奇数
my @odd_numbers;
foreach(1..100) {
    push @odd_numbers, $_ if $_ % 2;
}
print "@odd_numbers\n";
```

```perl
print "\n\n";
my @odd = grep $_ % 2, 1..100;
print "@odd\n";

print "\n\n";
my @odd = grep {$_ % 2} 1..100;
print "@odd\n";
```


# map
```perl
# 搜索带有 fred(不区分大小写)的行显示出来 
my @matching_lines = grep /\bfred\b/i, <>;
print "@matching_lines

my @files = glob "*.*";
print "@files\n";

my @txt_files = map {/(.*)\.txt$/} @files;
print "@txt_files\n";

my @sizes = map {-s} @txt_files;
print "@sizes\n";
```



# 对数字时行变换
```perl
sub big_money {
    my $number = sprintf "%.2f, shift @_;
    1 while $number =~ s/^(-?\d)(\d\d\d)/$1,$2/;
    $number =~ s/^(-?)/$1\$/;
    $number;
}

print (big_money 123456.1234);



my @data = (4.75, 1,5, 2, 1234, 6.9876, 12345678.9, 29.95);
foreach(@data){
    push @formatted_data, &big_money($_);
}
print "@formatted_data\n";



my @formatted = map {&big_money($_)} @data;
print "The money number are:\n", map {sprintf("%25s\n", $_} @formatted;
print "@formatted\n";
or
print "The money number are:\n", map {sprintf("%25s\n", &big_money($_))} @data;
```


