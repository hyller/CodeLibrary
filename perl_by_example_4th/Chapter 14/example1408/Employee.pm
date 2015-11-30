# Module Employee.pm--See Example 13.8 to use this module.
package Employee;
use Carp;
sub new {
	my $class = shift;
	my(%params)=@_;   # Receiving the hash that was passed
	my $objptr={
		"Name"=>$params{"Name"} || croak("No name assigned"),
		"Extension"=>$params{"Extension"},
		"Address"=>$params{"Address"},
		"PayCheck"=>$params{"PayCheck"} || 
                  croak("No pay assigned"),
		((defined $params{"IdNum"})?("IdNum"=>$params{"IdNum"}):
		    ("IdNum"=>"Employee's id was not provided!"
		)),
	};

	return bless($objptr,$class);
}
sub get_stats{
	my $self=shift;
	while( ($key, $value)=each %$self){
 		print $key, " = ", $value, "\n";
	}
	print "\n";
}
1;

