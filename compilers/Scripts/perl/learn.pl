#!/usr/bin/perl
use strict;
use warnings;          
use diagnostics;        
use feature 'say';
use feature 'switch';
use v5.28;


### perl数学运算
### ++ -- += -= *= /= %=
say "5 + 4 = ", 5 + 4;
say "5 - 4 = ", 5 - 4;
say "5 * 4 = ", 5 * 4;
say "5 / 4 = ", 5 / 4;
say "5 % 4 = ", 5 % 4;
say "5 **4 = ", 5 **4;
say "exp 1 = ", exp 1;
say "hex 9 = ", hex 9;
say "oct 8 = ", oct 8;
say "int 1.23=", int(1.23);
say "log 1234=", log 1234;
say "sqrt 9 = ", sqrt 9;
say "Random between 0-10 = ", int(Rand 11);



### perl常量 $
print "Hello World\n";
my $name = "FreeBSD"
my ($FVWM, $XTerm) = (123, 'terminal');

my $my_info = "$name lives on \"$XTerm\"\n";
my $my_info = qq{$name lives on "$XTerm"\n}


### perl EOF
my $bunch_on_info = <<"END";
This ia a
bunch of information
on multiple lines
END

sy $bunch_on_info;



### %c  : Character
### %s  : String
### %d  : Decimal
### %u  : Unsigned integer
### %f  : Floating Point (Decimal Notation)
### %e  : Floating Point (Scientific Notaiton)
my $big_int = 18446744073709551615;
printf("%u \n", $big_int + 1);

my $big_float = .1000000000000001;
printf("%.16f \n", $big_float + .1000000000000001);



### perl两个数互换值
my $first = 1;
my $second = 2;
($first, $second) = ($second, $first);
say "$first, $sceond"



### if else
my $age = 80;
my $is_not_intoxicated = 1;
my $age_last_exam = 16;
if ($age < 16) {
    say "You can't drvie";
} elsif (!$is_not_intoxicated) {
    "You can't driver";
} else {
    "You can driver";
}


if (($age >= 1) && ($age < 16) {
    say "You can't driver";
} elsif (!$is_not_intoxicated) {
    say "You can't driver";
} elsif (($age >= 80) && (($age > 100) || (($age - $age_last_exm) > 5))) {
    say "You can't driver";
} else {
    say "You can driver";
}


if ('a' eq 'b') {
    say "a equals b";
} else {
    say "a doesn't equals b";
}

unless (!$is_not_intocicated) {
    say "Get Sober";
}

say (($age > 18) ? "Can Vote" : "Can't Vote");


### for while given
for (my $i = 0; $i < 10; $i++) {
    say $i;
}


my $i = 1;
while ($i < 10) {
    if ($i % 2 == 0) {
        $i++;
        next;
    }
    if ($i == 7) {last;}
    say $i;
    $i++;
}

# 如何从用户那里获得输入？
my $lucky_num  7;
my $guess;
do {
    say "Guess a Number Between 1 an 10";
    $guess = <STDIN>;
} while $guess != $lucky_num;
say "You Guessed 7";

# 相当于C语言中的SWITCH-CASE
my $age_old = 18;
given ($age_old) {
    when ($_ > 16) {
        say "You can driver";
        continue;
    }
    when ($_ > 17) {
        say "Go Vote";
    }
    default {
        say "Notthing Special";
    }
}



## perl字符串
my $long_string = "Random Long Strint";
say "Length of String ", length $long_string;
printf("Long is at %d \n", index $long_string, "Long");
printf("Long g is at %d \n", rindex $long_string, "g");
say "Index 7 through 10", substr $long_string, 7, 4;

printf("UpperCase : %s \n", uc $long_string);
printf("LowerCase : %s \n", lc $long_string);
printf("1st UpperCase : %s \n", ucfirst $long_string);


my $animal = 'amimals';
printf("Last Character is %s\n", chop $animal);

### 字符串替换
$long_string =~ s/ /, /g;

my $two_times = "what I said is " x 2;
say $two_times;


### perl数组
my @abcs = ('a' .. 'z');
print join(", ", @abcs), "\n";
my $letter = 'c';
say "Next Letter ", ++$letter;




my @my_info = ("Derek", "123 Main St", 40, 6.25);
$my_info[4] = "Banas";
for my $info (@my_info) {
    say $info;
}

my @primes = (2,3,5,7,11,13,17);
foreach my $num (@primes) {
    say $num;
}

for (@my_info) {
    say $_;
}

my @my_name = @my_info[0, 4];
say @my_name;
my items = scalar @my_info;
say $items;

my ($f_name, $address, $how_old, $height, $l_name) = @my_info;
say "$f_name $l_name";


say "Popped Value ", pop @primes;
say "Pushed Value ", push @primes, 17;
say "First Item   ", shift @primes;
say "Unshifted Item ", unshift @primes, 2;
print join(", ", @primes), "\n";


say "Remove Index 0--2 ", splice @primes, 0, 3;
print join(", ", @primes), "\n";


print join " ", ('list', 'of', 'words', "\n");
my $customers = "Sue Sally Paul";
my @cust_array = split / /, $customers;
print join(", ", @cust_array), "\n";


@cust_array = reverse @cust_array;
@cust_array = reverse sort @cust_array;


my @number_array = (1,2,3,4,5,6,6,8,);
my @odds_array = grep {$_ % 2} @number_array;
print join(", ", @cust_array), "\n";


my @dbl_array = map {$_ * 2} @number_array;
print join(", ", @dbl_array), "\n";



### perl 哈希
my %employees = (
    "Sue" => 35,
    "Pau" => 43;,
    "Sam" => 12;
);
printf("Sue is %d \n", $employees{Sue});


$employees{Frank} = 44;
while )my ($k, $v)=each %employyes {
    print "$k $v\n";
}


my @ages = @employees{"Sue", "Sam"};
say @ages;


my @hash_array = %employees;
delete $employees{'Frank'};
while (my ($k, $v)=each %employees {
    print "$k $v\n";
}
say ((exists $employees{'Sam'}) ? "Sam is here" : "No Sam");


for my $key (keys %employees) {
    if ($employees{$key} == 35) {
        say "Hi Sue";
    }
}


### perl子程序 
sub get_random {
    return int(rand 11);
}
say "Random Number ", get_random();
###
sub get_random_max {
    my ($max_num) = @_;
    $max_num ||= 11;
    return int(rand $max_num);
}
say "Random Number ", get_random_max(100);  

sub get_sum {
    my ($num_1, $num_2) = @_;
    $num_1 ||= 1;
    $num_2 ||= 1;
    return $num_1 + $num_2;
}
sub sum_many {
    my $sum = 0;
    foreach my $val (@_) {
        $sum += $val;
    }
    return $sum;
}
say "Sum : ", sum_many(1,2,3,4,5);
sub increment {
    state $execute_total = 0;
    $execute_total++;
    say "Executed $execute_total times";
}
increment();
increment();



sub double_array {
    my @num_array = @_;
    $_ *= 2 for @num_array;
    return @num_array;
}
my @rand_array = (1,2,3,4,5);
print join(", ", double_array(@rand_array)), "\n";


sub get_mults {
    my ($rand_num) = @_;
    $rand_num ||= 1;
    return $rnad_num *2, $rand_num * 3;
}
my ($dbl_num, $trip_num) = get_mults(3);
say "$dbl_num $trip_num";


# 1st: num = 4 * factorial(3) = 4 * 6 = 24
# 2nt: num = 3 * factorial(2) = 3 * 2 = 6
# 3rd: num = 2 * factorial(1) = 2 * 1 = 2
sub factorial {
    my ($num) = @_;
    return 0 if $num <= 0;
    return 1 if $num == 1;
    return $num * factorial($num - 1);
}
say "Factorial 4 = ", factorial(4);



### perl文件读写
# vim employees.txt
Sally:Secretary:121
Sam:Janitor:122
Sue:Manager:123
Mark:Salesman:124



my $emp_file = 'empoyees.txt';
open my $fh, '<', $emp_file
    or die "Can't Open File : $_";
while (my $info = <$fh>) {
    chomp($info);
    my ($emp_name, $job, $id) = split /:/, $info;
    print "$emp_name is a $job and has the id $id \n";
}
close $fh or die "Couldn't Close File : $_";


open $fh, '>>', $emp_file
    or die "Can't Open File : $_";
print $fh "Mark:Salesman:124\n";
close $fh or die "Couldn't Close File : $_";


open $fh, '+<', $emp_file
    or die "Can't Open File : $_";
seek $fh, 0, 0;
print $fh "Phil:Salesman:125\n";
close $fh or die "Couldn't Close File : $_";


### perl面向对象







### 打印1到100中所有的奇数
my @odd_numbers;
foreach(1..100) {
    push @odd_numbers, $_ if $_ % 2;
}
print "@odd_numbers\n";



### 打印奇数
print "\n\n";
my @odd = grep $_ % 2, 1..100;
print "@odd\n";

print "\n\n";
my @odd = grep {$_ % 2} 1..100;
print "@odd\n";


### 从标准输入读入数据
### 搜索带有 fred(不区分大小写)的行显示出来
my @matching_lines = grep /\bfred\b/i, <>;
print "@matching_lines"




# maps

my @files = glob "*.*";
print "@files\n";

my @txt_files = map {/(.*)\.txt$/} @files;
print "@txt_files\n";

my @sizes = map {-s} @txt_files;
print "@sizes\n";




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



