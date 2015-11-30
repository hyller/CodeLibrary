#!/bin/perl
# dbmopen is an older method of opening a dbm file but simpler 
# than using tie and the SDBM_File module provided
# in the standard Perl library Program name: remstates.pl
use AnyDBM_File;
dbmopen(%states, "statedb", 0666) || die;
TRY: {
	print "Enter the abbreviation for the state to remove. ";
	chomp($abbrev=<STDIN>);
	$abbrev = uc $abbrev;  # Make sure abbreviation is uppercase
	delete $states{"$abbrev"};
	print "$abbrev removed.\n";
	print "Another entry? ";
	$answer = <STDIN>;
	redo TRY  if $answer =~ /Y|y/;  }
dbmclose(%states);

