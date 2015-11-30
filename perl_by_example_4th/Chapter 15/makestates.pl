#!/usr/bin/perl
# Program name: makestates.pl
# This program creates the database using the dbm functions

use AnyDBM_File;  # Let Perl pick the right dbm for your system
dbmopen(%states, "statedb", 0666 ) || die;   
                  # Create or open the database
TRY: {
	print "Enter the abbreviation for your state. ";
	chomp($abbrev=<STDIN>);
	$abbrev = uc $abbrev;  # Make sure abbreviation is uppercase
	print "Enter the name of the state. ";
	chomp($state=<STDIN>);
	lc $state;
	$states{$abbrev}="\u$state";  # Assign values to the database
	print "Another entry? ";
	$answer = <STDIN>;
	redo TRY  if $answer =~ /Y|y/;
}
dbmclose(%states);       # Close the database