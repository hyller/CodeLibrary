$ cat average.pl   # File where subroutine is defined
package average; # Declare a package
# Average a list of grades
sub ave { 
	my(@grades)=@_;
	my($num_of_grades)=$#grades + 1;
	foreach $grade ( @grades ){
	     $total += $grade;
	}
	$total/$num_of_grades;   # What gets returned
}
1; # Make sure the file returns true or require will not succeed!
