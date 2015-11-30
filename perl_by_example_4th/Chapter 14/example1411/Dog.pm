package Dog;
sub new{               # Constructor
  	my $class=shift;
  	my $dptr={};
  	bless($dptr, $class);
}
sub set_attributes{
	my $self= shift;
	my($name, $owner, $breed)=@_;
	$self->{"Name"}="$name";
	$self->{"Owner"}="$owner";
	$self->{"Breed"}="$breed";
}
sub get_attributes{
	my $self = shift;
	print "x" x 20, "\n";
	print "All about $self->{Name}\n";
	while(($key,$value)= each( %$self)){
		print "$key is $value.\n";
	}
	print "x" x 20, "\n";
}
1;
