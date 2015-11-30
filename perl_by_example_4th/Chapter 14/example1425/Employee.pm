package Employee;  # Base class
use strict;
use warnings;
sub new {          # Employee’s constructor is defined
	my $class = shift;
	my %params = @_;
	my $self = { Name=>$params{"Name"},
	             Salary=>$params{"Salary"},
	           };
	bless ($self, $class);
	}
sub display {       # Instance method
	my $self = shift;
	foreach my $key ( @_){
		print "$key: $self->{$key}\n";
	}
	print "The class using this display method is ", 
		  ref($self),"\n";
}
1;