package House;          # Class

sub new {                  # Class method called a constructor
	my $class = shift;
	my $ref={"Owner"=>undef,     # Attributes of the object
		     "Price" =>undef,   # Values will be assigned later
	        };
	bless($ref, $class); 
	                # $ref now references an object in this class
	return $ref;    # A reference to the object is returned 
}
1;
