package Salesman;  # Derived class
use strict;
use warnings;
use Employee;
our @ISA=qw (Exporter Employee);
sub new {          # Constructor in derived Salesman class
	my $class = shift;
	my (%params) = @_;
	my $self = new Employee(%params);  # Call constructor 
	                                   # in base class
	$self->{Commission} = $params{Commission};
	bless ( $self, $class );     # Rebless the object into 
	                             # the derived class
}
sub set_Salary {
	my $self = shift;
	$self->{Salary}=$self->{Salary} + $self->{Commission};
}
sub display{        # Override method in Employee class
	my $self = shift;
	my @args = @_;
		print "Stats for the Salesman\n";
	print "-" x 25, "\n"; 
	$self->Employee::display(@args);  # Access to the 
	                                  # overridden method
}
1;