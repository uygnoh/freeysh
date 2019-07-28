#!/usr/bin/perl
use strict;
use warnings;           ###开启内建警告信息
use diagnostics;        ###查看更详细问题描述
use feature 'say';
use feature 'switch';
use v5.28;



# FILE


my $emp_file = 'employees.txt';
open my $fh, '<', $emp_file
    or die "Can't Open File: $_";

ehile (my $info = <$fh>) {
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




    





