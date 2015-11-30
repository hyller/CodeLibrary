# The Cat class
package Cat;   
sub new{       # The Cat's constructor
	my $class = shift;
	my $ref = {};
	return bless ($ref, $class);
}
sub set_attributes{   # Giving the Cat some attributes, 
                      # a name and a voice
	my $self = shift;
	$self->{"Name"} = "Sylvester";
	$self->{"Talk"}= "Meow purrrrrr.... ";
}
sub speak {          # Retrieving the Cat's attributes
	my $self = shift;
	print "$self->{Talk} I'm the cat called $self->{Name}.\n";
}
1;
