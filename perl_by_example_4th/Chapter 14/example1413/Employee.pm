package Employee;
sub new{
      my $class = shift;
      $ref={};
      bless($ref, $class);
      return $ref;
}

sub DESTROY{
      my $self = shift;
      print "Employee $self->{Name} is being destroyed.\n";
            }

1;                                                    
