package House;
sub TIEHASH {
	my $class = shift;
	print "I'm the constructor in package $class\n";
	my $houseref = {};
	bless $houseref, $class; 
}
sub FETCH {
	my $self=shift;
	my $key=shift; 
	return $self->{$key};
}
sub STORE {
	my $self = shift;
	my $key = shift;
	my $value = shift;
	$self->{$key}=$value;
}

sub FIRSTKEY {
	my $self = shift;
	my $tmp = scalar keys %{$self}; 
	return each  %{$self};
}
sub NEXTKEY {
	$self=shift;
	each %{$self};
}
1;
