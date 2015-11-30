# The Dog class
package Dog;   # The Dog's Constructor
sub new{
	my $class = shift;
	my $ref = {};
	return bless ($ref, $class);
}
sub set_attributes{    # Giving the Dog some attributes
	my $self = shift;
	$self->{"Name"} = "Lassie";
	$self->{"Talk"}= "Bow Wow, woof woof.... ";
}

sub speak {            # Retrieving the Dog's attributes
	my $self = shift;
	print "$self->{'Talk'} I'm the dog called $self->{'Name'}.\n";
}
1;