# File is Square.pm
# It will square a number, initially set to 5
package Square;  
sub TIESCALAR{
	my $class = shift;
	my $data = shift;
	bless(\$data,$class);   # Blessing a scalar
}
sub FETCH{
	my $self = shift;
	$$self **= 2;
}
sub STORE{
	my $self = shift;
	$$self = shift;
}
1;
