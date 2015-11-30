#!/bin/perl
# Example using tie with a hash

package House;
sub TIEHASH {             # Constructor method
	my $class = shift;    # Shifting the @_ array
	my $price = shift;
	my $color = shift;
	my $rooms = shift;
	print "I'm the constructor in class $class.\n";
	my $house =  {  Color=>$color,    # Data for the tied hash
	                Price=>$price,
		                Rooms=>$rooms,
		                		        };
	bless $house, $class; 
}
sub FETCH {                # Access methods
	my $self=shift;
	my $key=shift; 
	print "Fetching a value.\n";
	return $self->{$key};
}
sub STORE {
	my $self = shift;
	my $key = shift;
	my $value = shift;
	print "Storing a value.\n";
	$self->{$key}=$value;
}
1;