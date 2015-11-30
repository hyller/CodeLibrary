#!/usr/bin/perl
# Open a file with a filehandle
open(FILE, "datebook") || die "Can't open datebook: $!\n";
while(<FILE>) {
	print  if /Sir Lancelot/;
}
close(FILE);
