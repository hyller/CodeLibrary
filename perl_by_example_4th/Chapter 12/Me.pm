package Me;
use strict;  use warnings;
#require 5.6;      # Make sure we're a version of Perl no 
                  # older than 5.6
require Exporter; # Exporter.pm allows symbols to be imported 
                  # by others
our @ISA=qw(Exporter); # ISA is a list of base packages needed
                       # by this module
our @EXPORT_OK=qw(hello goodbye );  # List of your subroutines 
                                    # to export

sub hello { my($name)=shift;
	print "Hi there, $name.\n" };
sub goodbye { my($name)=shift;
	print "Good-bye $name.\n";}

sub do_nothing { print "Didn't print anything. 
                        Not in EXPORT list\n";}
1;