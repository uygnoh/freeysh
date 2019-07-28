
use strict;
use warnings;
use diagnostics;
use feature 'say';
use feature 'switch';
use v5.28;


print "Hello World\n";
my $name = 'FreeLinux';
my ($age, $fvwm) = (18, 'FreeBSD');
my $my_info = "\[$name\] lives on \"$fvwm\"\n";
#my $my_info = qq{"$name lives on \"$fvwm\"\n"};
print $my_info;

my $info = <<"EOF";
123000000000000
456000000000000
789000000000000
EOF
say $info;

my $first = 1;
my $second = 2;
($first, $second) = ($second, $first);
say "$first $second";



my $age1 = 79;
my $is_not_intoxicated = 1;
my $age_last_exam = 16;
if (($age1 >= 1) && ($age1 < 16)) {
    say "You can't drive";
} elsif (!$is_not_intoxicated) {
    say "You can't drive";
} elsif ($age1 >= 80) {
    say "You can't drive";
} else {
    say "You can drive";
}


