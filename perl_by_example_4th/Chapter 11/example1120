#!/bin/perl
open(READMEFILE, "f1") || die;
&readit(*READMEFILE);     # Passing a filehandle to a subroutine
sub readit{
	local(*myfile)=@_;    # myfile is an alias for READMEFILE
	while(<myfile>){
		print;
	}
}
