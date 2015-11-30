#Student.pm:

package Student;
sub new {  # Constructor
     my $class = shift;
     my $data={};
     our $students;

      my $ref = sub { # Closure
          my ($access_type, $key, $value) = @_;

          if ($access_type eq "set"){
            $data->{$key} = $value;  # $data still available here
           }
           elsif ($access_type eq "get"){
                return $data->{$key};
           }
           elsif ($access_type eq "keys"){
                return (keys %{$data});
           }
           elsif ($access_type eq "destroy"){       
                 $students--;
                 return $students;
           }            
           else{
                die "Access type should be set or get";
          }
          
      };
          
          
      print "New student created, we have ", ++$students," students.\n";
      return bless ($ref, $class);  # bless anonymous subroutine
  
}  # End constructor

sub set{
    my ($self,$key,$value) = @_; # $self references anonymous sub
    $self->("set",$key,$value);
}
sub get{
my ($self,$key) = @_;           
 return $self->("get", $key);
}
sub display{
   my $self = shift;
   my @keys = $self->("keys");
   @keys=reverse(@keys);
   foreach my $key (@keys){
      my $value = $self->("get",$key);
      printf "%-25s%-5s:%-20s\n",$self, $key,$value ;
   }
   print "\n";
}
sub DESTROY{
    my $self = shift;
    print "Object going out of scope:\n";
    print "Students remain: ", $self->("destroy"), "\n";
}
1;