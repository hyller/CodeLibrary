#!/usr/bin/perl
package House;

sub new{          # Class/Static method
	my $class = shift;
	my $ref={};   # Anonymous and empty hash
	bless($ref);
	return $ref;
}
sub set_owner{     # Instance/Virtual method
	my $self = shift;
	print "\$self is a class ", ref($self)," reference.\n";
	$self->{"Owner"} = shift;
}
sub display_owner { 
	my $self = shift; 
               # The object reference is the first argument
	print $self->{"Owner"},"\n";
}
1;