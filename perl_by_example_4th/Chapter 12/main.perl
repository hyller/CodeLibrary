#!/usr/bin/perl
# Program name: main.perl
use lib ("/home/ellie/Modules");   # A pragma to update @INC.
use Me  qw(hello goodbye);        # Import package
&hello ("Daniel");
&goodbye ("Steve");
&do_nothing;       # This was not on the Export list 
                   # in Me.pm so cannot be imported unless
                   # explicitly with &Me::do_nothing