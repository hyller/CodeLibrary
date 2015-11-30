# Module Employee.pm
# The Base Class
package Employee;
use strict;
use warnings;
# Constructor method
sub new {
	my $class = shift;
	my $self = {_Name=>undef,
	            _Address=>undef,
	            _BasePay=>undef,
	           };
	return bless($self, $class);
}

# Instance/access methods
sub set_data{  
	my $self=shift;
		print "Enter the name of the employee. ";
		chomp($self->{_Name}=<STDIN>);
		print "Enter the address of $self->{_Name}. ";
		chomp($self->{_Address}=<STDIN>);
		print "Enter the monthly base pay for $self->{_Name}. ";
		chomp($self->{_BasePay}=<STDIN>);
	}
sub get_data{
	my $self=shift;
	my ($key,$value);
	print "Name = $self->{_Name}.\n";
	while(($key,$value)=each(%$self)){
		$key =~ s/_//;
		print "$key = $value.\n" unless $key eq "Name";
	}
	print "\n";
}
1;
