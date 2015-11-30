#!/bin/perl
# Program to demonstrate passing arguments to an instance method.
# When method is called, user can select what he wants returned.
package House;

sub new{     # Constructor, class method
	my $class = shift;
	my ($owner, $salary, $style) = @_;

	my $ref={ "Owner"=>$name,
	          "Price"=>$salary,
	          "Style"=>$style,
	        };   
 	return bless($ref, $class);
}
sub display {           # Instance method
	my $self = shift;   # Object reference is the first argument
	foreach $key ( @_){
		print "$key: $self->{$key}\n";
	}
}
1;