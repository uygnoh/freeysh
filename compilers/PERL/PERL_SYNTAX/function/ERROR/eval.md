# 使用eval捕获错误
```perl
eval语法格式：

eval {
    ...
};
if ($@) {...}
```




```perl
sub do_something {
    #....
}

foreach my $person (qw/ Fred wilma betty barney dino pebbles /) {
    eval {
        open FILE, "<$person" or die "Cant't open file '$person': $!";
        
        my($total, $count);
        
        while (<FILE>) {
            $tatal += $_;
            $count++;
        }
        
        my $average = $total / $count;
        print "Average for file $person was $average\n";
        
        &do_something($person, $average);
    };
    if ($@) {
        print "An Error occured ($@), continuing\n";
    }
}
```



# eval die配合使用， 捕获错误
```perl
sub do_work {
    my $task = shift;
    if ($task < 0) {
        die("Task [$task] should be greate than zero");
    }
    $task;
}


eval {
    my $value = do_work(-9);
    
};
if ($@) {
    print "error: $@";
}

```







