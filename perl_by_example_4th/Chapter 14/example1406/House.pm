package House; 
sub new{         # Constructor  method
	my $class = shift;
	my ($owner, $salary) = @_;      # Instance variables
	my $ref={"Owner"=>$owner,       # Instance variables to 
	         "Price"=>$price,       # initialize the object
	};
	bless($ref, $class);
	return $ref;
}

sub display_object {       # An instance method
	my $self = shift;      # The name of the object is passed
	while( ($key, $value)=each %$self){
		print "$key: $value \n";
	}
} 
1;

