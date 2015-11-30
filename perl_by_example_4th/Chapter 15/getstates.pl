#!/bin/perl
# Program name: getstates.pl
# This program fetches the data from the database 
# and generates a report

use AnyDBM_File;
dbmopen(%states, "statedb", 0666);   # Open the database
@sortedkeys=sort keys %states;    # Sort the database by keys
	foreach $key ( @sortedkeys ){
	$value=$states{$key};
	$total++;
	write;
}
dbmclose(%states);    # Close the database
format STDOUT_TOP=
Abbreviation     State
==============================
.


format STDOUT=
@<<<<<<<<<<<<<<@<<<<<<<<<<<<<<<
$key,          $value
.
format SUMMARY=
==============================
Number of states:@###
                $total
.
$~=SUMMARY;
write;