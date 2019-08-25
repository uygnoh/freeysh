put "Hello word";

my $name = prompt "What's your name ?";
put $name;

put 1 .. 10;
say 1 .. 10;
print "No newline";

my $y = 6;
$y = "Dog";
my $z := $y;
put $z;

my Bool $can_vote = True;
put $can_vote;


put "10 :     ", 10.^name;
put "10.5 :   ", (10.5).^name;
put "\"10\" : ", "10".^name;
say "Type :   ", (10.Str).^name;
say "Type :   ", (+"123).^name;
say "1 = @2 = ", "1" + 2;
say '65'.chr;

say (5 + 4).fmt("5 + 4 = %d");
say (5 - 4).fmt("5 - 4 = %d");
say (5 * 4).fmt("5 * 4 = %d");
say (5 / 4).fmt("5 / 4 = %.2f");
say (5 % 4).fmt("5 % 4 = %d");
say (5 **4).fmt("5 **4 = %d");


say "Random : ", 20.rand.Int;
say "Random Range : ", (5..20).rand.Int;


say "(-1).abs = ", (-1).abs;
say "1.exp    = ", (1).exp;
say "sqrt(9)  = ", sqrt(9);


# Conditional Operators > < >= <= == !=
# Logical Operators     && and, || or, ! not
my $age = 12;
if $age >= 5 && $age <= 6 {
    put "Go to Kindergarten";
} elsif 7 <= $age <= 13 {
    put "Go to Middle School";
} elsif $age >= 14 && $age <=18 {
    put "Go to Hiht School";
} else {
    put "Stay Home";
}
put 'old enought for school' if $age >= 5;

my $k = 0;
unless $k == 5 {
    put $k;
}

put 'Can vote : ', $age >= 18 ?? 'True' !! 'False';

my $str1 = "Hello";
say "$str1";
say "I like \"quotes\"";
say "Num : ", $str1.chars;
say "Has Value : ", ?$str1;

say Q/$str1 is ok here/;
say '$str1 is ok here';

say "one" ~ "string";
my $str2 = join " ", "a", "long", "string";
say $str2;

my $str3 = q :heredoc/END/;
i go 
for 
END
say $str3











