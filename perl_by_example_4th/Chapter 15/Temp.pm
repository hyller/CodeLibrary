package Temp;
sub TIEARRAY {
	my $class = shift;  # Shifting the @_ array
	my $obj = [ ];
	bless ($obj, $class);
}

# Access methods
sub FETCH {
	my $self=shift;
	my $indx = shift;
	return $self->[$indx];
}

sub STORE {
	my $self = shift;
	my $indx= shift;
	my $F = shift;    # The Fahrenheit temperature 
	$self->[$indx]=($F - 32) / 1.8;   # Magic works here!

}
1;