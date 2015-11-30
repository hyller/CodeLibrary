package Cat;
sub new{      # Constructor
  	my $class=shift;
  	my $dptr={};
  	bless($dptr, $class);
}
sub set_attributes{            # Access Methods
	my $self= shift;
	$self->{"Name"}="Sylvester";
	$self->{"Owner"}="Mrs. Black";
	$self->{"Type"}="Siamese";
	$self->{"Sex"}="Male";
}
sub get_attributes{
	my $self = shift;
	print "-" x 20, "\n";
	print "Stats for the Cat\n";
	print "-" x 20, "\n";
	while(($key,$value)=each( %$self)){
		print "$key is $value. \n";
	}
}
print "-" x 20, "\n";
1;
