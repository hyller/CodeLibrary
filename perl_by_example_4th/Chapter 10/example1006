#!/usr/bin/perl
# Open a file with a filehandle
open(FILE, "<datebook") || die "Can't open datebook: $!\n";
@lines = <FILE>;
print @lines;       # Contents of the entire file are printed
print "\nThe datebook file contains ", $#lines + 1, 
      " lines of text.\n";
close(FILE);
